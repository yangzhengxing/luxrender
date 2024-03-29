/***************************************************************************
 * Copyright 1998-2015 by authors (see AUTHORS.txt)                        *
 *                                                                         *
 *   This file is part of LuxRender.                                       *
 *                                                                         *
 * Licensed under the Apache License, Version 2.0 (the "License");         *
 * you may not use this file except in compliance with the License.        *
 * You may obtain a copy of the License at                                 *
 *                                                                         *
 *     http://www.apache.org/licenses/LICENSE-2.0                          *
 *                                                                         *
 * Unless required by applicable law or agreed to in writing, software     *
 * distributed under the License is distributed on an "AS IS" BASIS,       *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
 * See the License for the specific language governing permissions and     *
 * limitations under the License.                                          *
 ***************************************************************************/

#if !defined(LUXRAYS_DISABLE_OPENCL)

#include <iosfwd>
#include <limits>

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#include "slg/engines/pathoclbase/compiledscene.h"
#include "slg/kernels/kernels.h"

#include "slg/textures/abs.h"
#include "slg/textures/add.h"
#include "slg/textures/band.h"
#include "slg/textures/bilerp.h"
#include "slg/textures/blackbody.h"
#include "slg/textures/blender_texture.h"
#include "slg/textures/brick.h"
#include "slg/textures/checkerboard.h"
#include "slg/textures/clamp.h"
#include "slg/textures/colordepth.h"
#include "slg/textures/constfloat.h"
#include "slg/textures/constfloat3.h"
#include "slg/textures/cloud.h"
#include "slg/textures/dots.h"
#include "slg/textures/fbm.h"
#include "slg/textures/fresnelapprox.h"
#include "slg/textures/fresnel/fresnelcolor.h"
#include "slg/textures/fresnel/fresnelconst.h"
#include "slg/textures/fresnel/fresnelluxpop.h"
#include "slg/textures/fresnel/fresnelpreset.h"
#include "slg/textures/fresnel/fresnelsopra.h"
#include "slg/textures/fresnel/fresneltexture.h"
#include "slg/textures/hitpoint.h"
#include "slg/textures/hsv.h"
#include "slg/textures/imagemaptex.h"
#include "slg/textures/irregulardata.h"
#include "slg/textures/lampspectrum.h"
#include "slg/textures/marble.h"
#include "slg/textures/mix.h"
#include "slg/textures/normalmap.h"
#include "slg/textures/scale.h"
#include "slg/textures/subtract.h"
#include "slg/textures/windy.h"
#include "slg/textures/wrinkled.h"
#include "slg/textures/uv.h"

using namespace std;
using namespace luxrays;
using namespace slg;
using namespace slg::blender;

void CompiledScene::CompileTextureMapping2D(slg::ocl::TextureMapping2D *mapping, const TextureMapping2D *m) {
	switch (m->GetType()) {
		case UVMAPPING2D: {
			mapping->type = slg::ocl::UVMAPPING2D;
			const UVMapping2D *uvm = static_cast<const UVMapping2D *>(m);
			mapping->uvMapping2D.uScale = uvm->uScale;
			mapping->uvMapping2D.vScale = uvm->vScale;
			mapping->uvMapping2D.uDelta = uvm->uDelta;
			mapping->uvMapping2D.vDelta = uvm->vDelta;
			break;
		}
		default:
			throw runtime_error("Unknown 2D texture mapping in CompiledScene::CompileTextureMapping2D: " + boost::lexical_cast<string>(m->GetType()));
	}
}

void CompiledScene::CompileTextureMapping3D(slg::ocl::TextureMapping3D *mapping, const TextureMapping3D *m) {
	switch (m->GetType()) {
		case UVMAPPING3D: {
			mapping->type = slg::ocl::UVMAPPING3D;
			const UVMapping3D *uvm = static_cast<const UVMapping3D *>(m);
			memcpy(&mapping->worldToLocal.m, &uvm->worldToLocal.m, sizeof(float[4][4]));
			memcpy(&mapping->worldToLocal.mInv, &uvm->worldToLocal.mInv, sizeof(float[4][4]));
			break;
		}
		case GLOBALMAPPING3D: {
			mapping->type = slg::ocl::GLOBALMAPPING3D;
			const GlobalMapping3D *gm = static_cast<const GlobalMapping3D *>(m);
			memcpy(&mapping->worldToLocal.m, &gm->worldToLocal.m, sizeof(float[4][4]));
			memcpy(&mapping->worldToLocal.mInv, &gm->worldToLocal.mInv, sizeof(float[4][4]));
			break;
		}
		case LOCALMAPPING3D: {
			mapping->type = slg::ocl::LOCALMAPPING3D;
			const LocalMapping3D *gm = static_cast<const LocalMapping3D *>(m);
			memcpy(&mapping->worldToLocal.m, &gm->worldToLocal.m, sizeof(float[4][4]));
			memcpy(&mapping->worldToLocal.mInv, &gm->worldToLocal.mInv, sizeof(float[4][4]));
			break;
		}
		default:
			throw runtime_error("Unknown 3D texture mapping in CompiledScene::CompileTextureMapping3D: " + boost::lexical_cast<string>(m->GetType()));
	}
}

float *CompiledScene::CompileDistribution1D(const Distribution1D *dist, u_int *size) {
	const u_int count = dist->GetCount();
	*size = sizeof(u_int) + count * sizeof(float) + (count + 1) * sizeof(float);
	float *compDist = new float[*size];

	*((u_int *)&compDist[0]) = count;
	copy(dist->GetFuncs(), dist->GetFuncs() + count,
			compDist + 1);
	copy(dist->GetCDFs(), dist->GetCDFs() + count + 1,
			compDist + 1 + count);

	return compDist;
}

float *CompiledScene::CompileDistribution2D(const Distribution2D *dist, u_int *size) {
	u_int marginalSize;
	float *marginalDist = CompileDistribution1D(dist->GetMarginalDistribution(),
			&marginalSize);

	u_int condSize;
	vector<float *> condDists;
	for (u_int i = 0; i < dist->GetHeight(); ++i) {
		condDists.push_back(CompileDistribution1D(dist->GetConditionalDistribution(i),
			&condSize));
	}

	*size = 2 * sizeof(u_int) + marginalSize + condDists.size() * condSize;
	float *compDist = new float[*size];

	*((u_int *)&compDist[0]) = dist->GetWidth();
	*((u_int *)&compDist[1]) = dist->GetHeight();

	float *ptr = &compDist[2];
	copy(marginalDist, marginalDist + marginalSize, ptr);
	ptr += marginalSize / 4;
	delete[] marginalDist;

	const u_int condSize4 = condSize / sizeof(float);
	for (u_int i = 0; i < dist->GetHeight(); ++i) {
		copy(condDists[i], condDists[i] + condSize4, ptr);
		ptr += condSize4;
		delete[] condDists[i];
	}

	return compDist;
}

void CompiledScene::CompileTextures() {
	const u_int texturesCount = scene->texDefs.GetSize();
	SLG_LOG("Compile " << texturesCount << " Textures");
	//SLG_LOG("  Texture size: " << sizeof(slg::ocl::Texture));

	//--------------------------------------------------------------------------
	// Translate textures
	//--------------------------------------------------------------------------

	const double tStart = WallClockTime();

	usedTextureTypes.clear();

	// The following textures source code are statically defined and always included
	usedTextureTypes.insert(CONST_FLOAT);
	usedTextureTypes.insert(CONST_FLOAT3);
	usedTextureTypes.insert(IMAGEMAP);
	usedTextureTypes.insert(FRESNELCONST_TEX);
	usedTextureTypes.insert(FRESNELCOLOR_TEX);
	usedTextureTypes.insert(NORMALMAP_TEX);

	texs.resize(texturesCount);

	for (u_int i = 0; i < texturesCount; ++i) {
		Texture *t = scene->texDefs.GetTexture(i);
		slg::ocl::Texture *tex = &texs[i];

		usedTextureTypes.insert(t->GetType());
		switch (t->GetType()) {
			case CONST_FLOAT: {
				ConstFloatTexture *cft = static_cast<ConstFloatTexture *>(t);

				tex->type = slg::ocl::CONST_FLOAT;
				tex->constFloat.value = cft->GetValue();
				break;
			}
			case CONST_FLOAT3: {
				ConstFloat3Texture *cft = static_cast<ConstFloat3Texture *>(t);

				tex->type = slg::ocl::CONST_FLOAT3;
				ASSIGN_SPECTRUM(tex->constFloat3.color, cft->GetColor());
				break;
			}
			case IMAGEMAP: {
				ImageMapTexture *imt = static_cast<ImageMapTexture *>(t);

				tex->type = slg::ocl::IMAGEMAP;
				const ImageMap *im = imt->GetImageMap();
				tex->imageMapTex.gain = imt->GetGain();
				CompileTextureMapping2D(&tex->imageMapTex.mapping, imt->GetTextureMapping());
				tex->imageMapTex.imageMapIndex = scene->imgMapCache.GetImageMapIndex(im);
				break;
			}
			case SCALE_TEX: {
				ScaleTexture *st = static_cast<ScaleTexture *>(t);

				tex->type = slg::ocl::SCALE_TEX;
				const Texture *tex1 = st->GetTexture1();
				tex->scaleTex.tex1Index = scene->texDefs.GetTextureIndex(tex1);

				const Texture *tex2 = st->GetTexture2();
				tex->scaleTex.tex2Index = scene->texDefs.GetTextureIndex(tex2);
				break;
			}
			case FRESNEL_APPROX_N: {
				FresnelApproxNTexture *ft = static_cast<FresnelApproxNTexture *>(t);

				tex->type = slg::ocl::FRESNEL_APPROX_N;
				const Texture *tx = ft->GetTexture();
				tex->fresnelApproxN.texIndex = scene->texDefs.GetTextureIndex(tx);
				break;
			}
			case FRESNEL_APPROX_K: {
				FresnelApproxKTexture *ft = static_cast<FresnelApproxKTexture *>(t);

				tex->type = slg::ocl::FRESNEL_APPROX_K;
				const Texture *tx = ft->GetTexture();
				tex->fresnelApproxK.texIndex = scene->texDefs.GetTextureIndex(tx);
				break;
			}
			case CHECKERBOARD2D: {
				CheckerBoard2DTexture *cb = static_cast<CheckerBoard2DTexture *>(t);

				tex->type = slg::ocl::CHECKERBOARD2D;
				CompileTextureMapping2D(&tex->checkerBoard2D.mapping, cb->GetTextureMapping());
				const Texture *tex1 = cb->GetTexture1();
				tex->checkerBoard2D.tex1Index = scene->texDefs.GetTextureIndex(tex1);

				const Texture *tex2 = cb->GetTexture2();
				tex->checkerBoard2D.tex2Index = scene->texDefs.GetTextureIndex(tex2);
				break;
			}
			case CHECKERBOARD3D: {
				CheckerBoard3DTexture *cb = static_cast<CheckerBoard3DTexture *>(t);

				tex->type = slg::ocl::CHECKERBOARD3D;
				CompileTextureMapping3D(&tex->checkerBoard3D.mapping, cb->GetTextureMapping());
				const Texture *tex1 = cb->GetTexture1();
				tex->checkerBoard3D.tex1Index = scene->texDefs.GetTextureIndex(tex1);

				const Texture *tex2 = cb->GetTexture2();
				tex->checkerBoard3D.tex2Index = scene->texDefs.GetTextureIndex(tex2);
				break;
			}
			case MIX_TEX: {
				MixTexture *mt = static_cast<MixTexture *>(t);

				tex->type = slg::ocl::MIX_TEX;
				const Texture *amount = mt->GetAmountTexture();
				tex->mixTex.amountTexIndex = scene->texDefs.GetTextureIndex(amount);

				const Texture *tex1 = mt->GetTexture1();
				tex->mixTex.tex1Index = scene->texDefs.GetTextureIndex(tex1);
				const Texture *tex2 = mt->GetTexture2();
				tex->mixTex.tex2Index = scene->texDefs.GetTextureIndex(tex2);
				break;
			}
			case CLOUD_TEX: {
				CloudTexture *ft = static_cast<CloudTexture *>(t);
							
				tex->type = slg::ocl::CLOUD_TEX;
				CompileTextureMapping3D(&tex->cloud.mapping, ft->GetTextureMapping());

				tex->cloud.radius = ft->GetRadius();
				tex->cloud.numspheres = ft->GetNumSpheres();
				tex->cloud.spheresize = ft->GetSphereSize();
				tex->cloud.sharpness = ft->GetSharpness();
				tex->cloud.basefadedistance = ft->GetBaseFadeDistance();
				tex->cloud.baseflatness = ft->GetBaseFlatness();
				tex->cloud.variability = ft->GetVariability();
				tex->cloud.omega = ft->GetOmega();
				tex->cloud.noisescale = ft->GetNoiseScale();
				tex->cloud.noiseoffset = ft->GetNoiseOffset();
				tex->cloud.turbulence = ft->GetTurbulenceAmount();
				tex->cloud.octaves = ft->GetNumOctaves();
				break;
			}
			case FBM_TEX: {
				FBMTexture *ft = static_cast<FBMTexture *>(t);

				tex->type = slg::ocl::FBM_TEX;
				CompileTextureMapping3D(&tex->fbm.mapping, ft->GetTextureMapping());
				tex->fbm.octaves = ft->GetOctaves();
				tex->fbm.omega = ft->GetOmega();
				break;
			}
			case MARBLE: {
				MarbleTexture *mt = static_cast<MarbleTexture *>(t);

				tex->type = slg::ocl::MARBLE;
				CompileTextureMapping3D(&tex->marble.mapping, mt->GetTextureMapping());
				tex->marble.octaves = mt->GetOctaves();
				tex->marble.omega = mt->GetOmega();
				tex->marble.scale = mt->GetScale();
				tex->marble.variation = mt->GetVariation();
				break;
			}
			case DOTS: {
				DotsTexture *dt = static_cast<DotsTexture *>(t);

				tex->type = slg::ocl::DOTS;
				CompileTextureMapping2D(&tex->dots.mapping, dt->GetTextureMapping());
				const Texture *insideTex = dt->GetInsideTex();
				tex->dots.insideIndex = scene->texDefs.GetTextureIndex(insideTex);

				const Texture *outsideTex = dt->GetOutsideTex();
				tex->dots.outsideIndex = scene->texDefs.GetTextureIndex(outsideTex);
				break;
			}
			case BRICK: {
				BrickTexture *bt = static_cast<BrickTexture *>(t);

				tex->type = slg::ocl::BRICK;
				CompileTextureMapping3D(&tex->brick.mapping, bt->GetTextureMapping());
				const Texture *tex1 = bt->GetTexture1();
				tex->brick.tex1Index = scene->texDefs.GetTextureIndex(tex1);
				const Texture *tex2 = bt->GetTexture2();
				tex->brick.tex2Index = scene->texDefs.GetTextureIndex(tex2);
				const Texture *tex3 = bt->GetTexture3();
				tex->brick.tex3Index = scene->texDefs.GetTextureIndex(tex3);

				switch (bt->GetBond()) {
					case FLEMISH:
						tex->brick.bond = slg::ocl::FLEMISH;
						break;
					default:
					case RUNNING:
						tex->brick.bond = slg::ocl::RUNNING;
						break;
					case ENGLISH:
						tex->brick.bond = slg::ocl::ENGLISH;
						break;
					case HERRINGBONE:
						tex->brick.bond = slg::ocl::HERRINGBONE;
						break;
					case BASKET:
						tex->brick.bond = slg::ocl::BASKET;
						break;
					case KETTING:
						tex->brick.bond = slg::ocl::KETTING;
						break;
				}

				tex->brick.offsetx = bt->GetOffset().x;
				tex->brick.offsety = bt->GetOffset().y;
				tex->brick.offsetz = bt->GetOffset().z;
				tex->brick.brickwidth = bt->GetBrickWidth();
				tex->brick.brickheight = bt->GetBrickHeight();
				tex->brick.brickdepth = bt->GetBrickDepth();
				tex->brick.mortarsize = bt->GetMortarSize();
				tex->brick.proportion = bt->GetProportion();
				tex->brick.invproportion = bt->GetInvProportion();
				tex->brick.run = bt->GetRun();
				tex->brick.mortarwidth = bt->GetMortarWidth();
				tex->brick.mortarheight = bt->GetMortarHeight();
				tex->brick.mortardepth = bt->GetMortarDepth();
				tex->brick.bevelwidth = bt->GetBevelWidth();
				tex->brick.bevelheight = bt->GetBevelHeight();
				tex->brick.beveldepth = bt->GetBevelDepth();
				tex->brick.usebevel = bt->GetUseBevel();
				break;
			}
			case ADD_TEX: {
				AddTexture *st = static_cast<AddTexture *>(t);

				tex->type = slg::ocl::ADD_TEX;
				const Texture *tex1 = st->GetTexture1();
				tex->addTex.tex1Index = scene->texDefs.GetTextureIndex(tex1);

				const Texture *tex2 = st->GetTexture2();
				tex->addTex.tex2Index = scene->texDefs.GetTextureIndex(tex2);
				break;
			}
			case SUBTRACT_TEX: {
				SubtractTexture *st = static_cast<SubtractTexture *>(t);
				
				tex->type = slg::ocl::SUBTRACT_TEX;
				const Texture *tex1 = st->GetTexture1();
				tex->subtractTex.tex1Index = scene->texDefs.GetTextureIndex(tex1);
				
				const Texture *tex2 = st->GetTexture2();
				tex->subtractTex.tex2Index = scene->texDefs.GetTextureIndex(tex2);
				break;
			}
			case WINDY: {
				WindyTexture *wt = static_cast<WindyTexture *>(t);

				tex->type = slg::ocl::WINDY;
				CompileTextureMapping3D(&tex->windy.mapping, wt->GetTextureMapping());
				break;
			}
			case WRINKLED: {
				WrinkledTexture *wt = static_cast<WrinkledTexture *>(t);

				tex->type = slg::ocl::WRINKLED;
				CompileTextureMapping3D(&tex->wrinkled.mapping, wt->GetTextureMapping());
				tex->wrinkled.octaves = wt->GetOctaves();
				tex->wrinkled.omega = wt->GetOmega();
				break;
			}
			case BLENDER_BLEND: {
				BlenderBlendTexture *wt = static_cast<BlenderBlendTexture *>(t);
				tex->type = slg::ocl::BLENDER_BLEND;
				CompileTextureMapping3D(&tex->blenderBlend.mapping, wt->GetTextureMapping());
				tex->blenderBlend.direction = wt->GetDirection();
				tex->blenderBlend.bright = wt->GetBright();
				tex->blenderBlend.contrast = wt->GetContrast();

				switch (wt->GetProgressionType()) {
					default:
					case TEX_LIN:
						tex->blenderBlend.type = slg::ocl::TEX_LIN;
						break;
					case TEX_QUAD:
						tex->blenderBlend.type = slg::ocl::TEX_QUAD;
						break;
					case TEX_EASE:
						tex->blenderBlend.type = slg::ocl::TEX_EASE;
						break;
					case TEX_DIAG:
						tex->blenderBlend.type = slg::ocl::TEX_DIAG;
						break;
					case TEX_SPHERE:
						tex->blenderBlend.type = slg::ocl::TEX_SPHERE;
						break;
					case TEX_HALO:
						tex->blenderBlend.type = slg::ocl::TEX_HALO;
						break;
					case TEX_RAD:
						tex->blenderBlend.type = slg::ocl::TEX_RAD;
						break;
				}
				break;
			}
			case BLENDER_CLOUDS: {
				BlenderCloudsTexture *wt = static_cast<BlenderCloudsTexture *>(t);
				tex->type = slg::ocl::BLENDER_CLOUDS;
				CompileTextureMapping3D(&tex->blenderClouds.mapping, wt->GetTextureMapping());
				tex->blenderClouds.noisesize = wt->GetNoiseSize();
				tex->blenderClouds.noisedepth = wt->GetNoiseDepth();
				tex->blenderClouds.bright = wt->GetBright();
				tex->blenderClouds.contrast = wt->GetContrast();
				tex->blenderClouds.hard = wt->GetNoiseType();
				switch (wt->GetNoiseBasis()) {
					default:
					case BLENDER_ORIGINAL:
						tex->blenderClouds.noisebasis = slg::ocl::BLENDER_ORIGINAL;
						break;
					case ORIGINAL_PERLIN:
						tex->blenderClouds.noisebasis = slg::ocl::ORIGINAL_PERLIN;
						break;
					case IMPROVED_PERLIN:
						tex->blenderClouds.noisebasis = slg::ocl::IMPROVED_PERLIN;
						break;
					case VORONOI_F1:
						tex->blenderClouds.noisebasis = slg::ocl::VORONOI_F1;
						break;
					case VORONOI_F2:
						tex->blenderClouds.noisebasis = slg::ocl::VORONOI_F2;
						break;
					case VORONOI_F3:
						tex->blenderClouds.noisebasis = slg::ocl::VORONOI_F3;
						break;
					case VORONOI_F4:
						tex->blenderClouds.noisebasis = slg::ocl::VORONOI_F4;
						break;
					case VORONOI_F2_F1:
						tex->blenderClouds.noisebasis = slg::ocl::VORONOI_F2_F1;
						break;
					case VORONOI_CRACKLE:
						tex->blenderClouds.noisebasis = slg::ocl::VORONOI_CRACKLE;
						break;
					case CELL_NOISE:
						tex->blenderClouds.noisebasis = slg::ocl::CELL_NOISE;
						break;
				}
				break;
			}
			case BLENDER_DISTORTED_NOISE: {
				BlenderDistortedNoiseTexture *wt = static_cast<BlenderDistortedNoiseTexture *>(t);
				tex->type = slg::ocl::BLENDER_DISTORTED_NOISE;
				CompileTextureMapping3D(&tex->blenderDistortedNoise.mapping, wt->GetTextureMapping());
				tex->blenderDistortedNoise.distortion = wt->GetDistortion();
				tex->blenderDistortedNoise.noisesize = wt->GetNoiseSize();
				tex->blenderDistortedNoise.bright = wt->GetBright();
				tex->blenderDistortedNoise.contrast = wt->GetContrast();

				switch (wt->GetNoiseDistortion()) {
					default:
					case BLENDER_ORIGINAL:
						tex->blenderDistortedNoise.noisedistortion = slg::ocl::BLENDER_ORIGINAL;
						break;
					case ORIGINAL_PERLIN:
						tex->blenderDistortedNoise.noisedistortion = slg::ocl::ORIGINAL_PERLIN;
						break;
					case IMPROVED_PERLIN:
						tex->blenderDistortedNoise.noisedistortion = slg::ocl::IMPROVED_PERLIN;
						break;
					case VORONOI_F1:
						tex->blenderDistortedNoise.noisedistortion = slg::ocl::VORONOI_F1;
						break;
					case VORONOI_F2:
						tex->blenderDistortedNoise.noisedistortion = slg::ocl::VORONOI_F2;
						break;
					case VORONOI_F3:
						tex->blenderDistortedNoise.noisedistortion = slg::ocl::VORONOI_F3;
						break;
					case VORONOI_F4:
						tex->blenderDistortedNoise.noisedistortion = slg::ocl::VORONOI_F4;
						break;
					case VORONOI_F2_F1:
						tex->blenderDistortedNoise.noisedistortion = slg::ocl::VORONOI_F2_F1;
						break;
					case VORONOI_CRACKLE:
						tex->blenderDistortedNoise.noisedistortion = slg::ocl::VORONOI_CRACKLE;
						break;
					case CELL_NOISE:
						tex->blenderDistortedNoise.noisedistortion = slg::ocl::CELL_NOISE;
						break;
				}

				switch (wt->GetNoiseBasis()) {
					default:
					case BLENDER_ORIGINAL:
						tex->blenderDistortedNoise.noisebasis = slg::ocl::BLENDER_ORIGINAL;
						break;
					case ORIGINAL_PERLIN:
						tex->blenderDistortedNoise.noisebasis = slg::ocl::ORIGINAL_PERLIN;
						break;
					case IMPROVED_PERLIN:
						tex->blenderDistortedNoise.noisebasis = slg::ocl::IMPROVED_PERLIN;
						break;
					case VORONOI_F1:
						tex->blenderDistortedNoise.noisebasis = slg::ocl::VORONOI_F1;
						break;
					case VORONOI_F2:
						tex->blenderDistortedNoise.noisebasis = slg::ocl::VORONOI_F2;
						break;
					case VORONOI_F3:
						tex->blenderDistortedNoise.noisebasis = slg::ocl::VORONOI_F3;
						break;
					case VORONOI_F4:
						tex->blenderDistortedNoise.noisebasis = slg::ocl::VORONOI_F4;
						break;
					case VORONOI_F2_F1:
						tex->blenderDistortedNoise.noisebasis = slg::ocl::VORONOI_F2_F1;
						break;
					case VORONOI_CRACKLE:
						tex->blenderDistortedNoise.noisebasis = slg::ocl::VORONOI_CRACKLE;
						break;
					case CELL_NOISE:
						tex->blenderDistortedNoise.noisebasis = slg::ocl::CELL_NOISE;
						break;
				}
				break;
			}
			case BLENDER_MAGIC: {
				BlenderMagicTexture *wt = static_cast<BlenderMagicTexture *>(t);
				tex->type = slg::ocl::BLENDER_MAGIC;
				CompileTextureMapping3D(&tex->blenderMagic.mapping, wt->GetTextureMapping());
				tex->blenderMagic.noisedepth = wt->GetNoiseDepth();
				tex->blenderMagic.turbulence = wt->GetTurbulence();
				tex->blenderMagic.bright = wt->GetBright();
				tex->blenderMagic.contrast = wt->GetContrast();
				break;
			}
			case BLENDER_MARBLE: {
				BlenderMarbleTexture *wt = static_cast<BlenderMarbleTexture *>(t);
				tex->type = slg::ocl::BLENDER_MARBLE;
				CompileTextureMapping3D(&tex->blenderMarble.mapping, wt->GetTextureMapping());
				tex->blenderMarble.turbulence = wt->GetTurbulence();
				tex->blenderMarble.noisesize = wt->GetNoiseSize();
				tex->blenderMarble.noisedepth = wt->GetNoiseDepth();
				tex->blenderMarble.bright = wt->GetBright();
				tex->blenderMarble.contrast = wt->GetContrast();
				tex->blenderMarble.hard = wt->GetNoiseType();

				switch (wt->GetNoiseBasis2()) {
					default:
					case TEX_SIN:
						tex->blenderMarble.noisebasis2 = slg::ocl::TEX_SIN;
						break;
					case TEX_SAW:
						tex->blenderMarble.noisebasis2 = slg::ocl::TEX_SAW;
						break;
					case TEX_TRI:
						tex->blenderMarble.noisebasis2 = slg::ocl::TEX_TRI;
						break;
				}

				switch (wt->GetMarbleType()) {
					default:
					case TEX_SOFT:
						tex->blenderMarble.type = slg::ocl::TEX_SOFT;
						break;
					case TEX_SHARP:
						tex->blenderMarble.type = slg::ocl::TEX_SHARP;
						break;
					case TEX_SHARPER:
						tex->blenderMarble.type = slg::ocl::TEX_SHARPER;
						break;
				}

				switch (wt->GetNoiseBasis()) {
					default:
					case BLENDER_ORIGINAL:
						tex->blenderMarble.noisebasis = slg::ocl::BLENDER_ORIGINAL;
						break;
					case ORIGINAL_PERLIN:
						tex->blenderMarble.noisebasis = slg::ocl::ORIGINAL_PERLIN;
						break;
					case IMPROVED_PERLIN:
						tex->blenderMarble.noisebasis = slg::ocl::IMPROVED_PERLIN;
						break;
					case VORONOI_F1:
						tex->blenderMarble.noisebasis = slg::ocl::VORONOI_F1;
						break;
					case VORONOI_F2:
						tex->blenderMarble.noisebasis = slg::ocl::VORONOI_F2;
						break;
					case VORONOI_F3:
						tex->blenderMarble.noisebasis = slg::ocl::VORONOI_F3;
						break;
					case VORONOI_F4:
						tex->blenderMarble.noisebasis = slg::ocl::VORONOI_F4;
						break;
					case VORONOI_F2_F1:
						tex->blenderMarble.noisebasis = slg::ocl::VORONOI_F2_F1;
						break;
					case VORONOI_CRACKLE:
						tex->blenderMarble.noisebasis = slg::ocl::VORONOI_CRACKLE;
						break;
					case CELL_NOISE:
						tex->blenderMarble.noisebasis = slg::ocl::CELL_NOISE;
						break;
				}
				break;
			}
			case BLENDER_MUSGRAVE: {
				BlenderMusgraveTexture *wt = static_cast<BlenderMusgraveTexture *>(t);
				tex->type = slg::ocl::BLENDER_MUSGRAVE;
				CompileTextureMapping3D(&tex->blenderMusgrave.mapping, wt->GetTextureMapping());
				tex->blenderMusgrave.dimension = wt->GetDimension();
				tex->blenderMusgrave.intensity = wt->GetIntensity();
				tex->blenderMusgrave.lacunarity = wt->GetLacunarity();
				tex->blenderMusgrave.offset = wt->GetOffset();
				tex->blenderMusgrave.gain = wt->GetGain();
				tex->blenderMusgrave.octaves = wt->GetOctaves();
				tex->blenderMusgrave.noisesize = wt->GetNoiseSize();
				tex->blenderMusgrave.bright = wt->GetBright();
				tex->blenderMusgrave.contrast = wt->GetContrast();

				switch (wt->GetMusgraveType()) {
					default:
					case TEX_MULTIFRACTAL:
						tex->blenderMusgrave.type = slg::ocl::TEX_MULTIFRACTAL;
						break;
					case TEX_RIDGED_MULTIFRACTAL:
						tex->blenderMusgrave.type = slg::ocl::TEX_RIDGED_MULTIFRACTAL;
						break;
					case TEX_HYBRID_MULTIFRACTAL:
						tex->blenderMusgrave.type = slg::ocl::TEX_HYBRID_MULTIFRACTAL;
						break;
					case TEX_FBM:
						tex->blenderMusgrave.type = slg::ocl::TEX_FBM;
						break;
					case TEX_HETERO_TERRAIN:
						tex->blenderMusgrave.type = slg::ocl::TEX_HETERO_TERRAIN;
						break;
				}

				switch (wt->GetNoiseBasis()) {
					default:
					case BLENDER_ORIGINAL:
						tex->blenderMusgrave.noisebasis = slg::ocl::BLENDER_ORIGINAL;
						break;
					case ORIGINAL_PERLIN:
						tex->blenderMusgrave.noisebasis = slg::ocl::ORIGINAL_PERLIN;
						break;
					case IMPROVED_PERLIN:
						tex->blenderMusgrave.noisebasis = slg::ocl::IMPROVED_PERLIN;
						break;
					case VORONOI_F1:
						tex->blenderMusgrave.noisebasis = slg::ocl::VORONOI_F1;
						break;
					case VORONOI_F2:
						tex->blenderMusgrave.noisebasis = slg::ocl::VORONOI_F2;
						break;
					case VORONOI_F3:
						tex->blenderMusgrave.noisebasis = slg::ocl::VORONOI_F3;
						break;
					case VORONOI_F4:
						tex->blenderMusgrave.noisebasis = slg::ocl::VORONOI_F4;
						break;
					case VORONOI_F2_F1:
						tex->blenderMusgrave.noisebasis = slg::ocl::VORONOI_F2_F1;
						break;
					case VORONOI_CRACKLE:
						tex->blenderMusgrave.noisebasis = slg::ocl::VORONOI_CRACKLE;
						break;
					case CELL_NOISE:
						tex->blenderMusgrave.noisebasis = slg::ocl::CELL_NOISE;
						break;
				}
				break;
			}
			case BLENDER_STUCCI: {
				BlenderStucciTexture *wt = static_cast<BlenderStucciTexture *>(t);
				tex->type = slg::ocl::BLENDER_STUCCI;
				CompileTextureMapping3D(&tex->blenderStucci.mapping, wt->GetTextureMapping());
				tex->blenderStucci.noisesize = wt->GetNoiseSize();
				tex->blenderStucci.turbulence = wt->GetTurbulence();
				tex->blenderStucci.bright = wt->GetBright();
				tex->blenderStucci.contrast = wt->GetContrast();
				tex->blenderStucci.hard = wt->GetNoiseType();

				switch (wt->GetStucciType()) {
					default:
					case TEX_PLASTIC:
						tex->blenderStucci.type = slg::ocl::TEX_PLASTIC;
						break;
					case TEX_WALL_IN:
						tex->blenderStucci.type = slg::ocl::TEX_WALL_IN;
						break;
					case TEX_WALL_OUT:
						tex->blenderStucci.type = slg::ocl::TEX_WALL_OUT;
						break;
				}

				switch (wt->GetNoiseBasis()) {
					default:
					case BLENDER_ORIGINAL:
						tex->blenderStucci.noisebasis = slg::ocl::BLENDER_ORIGINAL;
						break;
					case ORIGINAL_PERLIN:
						tex->blenderStucci.noisebasis = slg::ocl::ORIGINAL_PERLIN;
						break;
					case IMPROVED_PERLIN:
						tex->blenderStucci.noisebasis = slg::ocl::IMPROVED_PERLIN;
						break;
					case VORONOI_F1:
						tex->blenderStucci.noisebasis = slg::ocl::VORONOI_F1;
						break;
					case VORONOI_F2:
						tex->blenderStucci.noisebasis = slg::ocl::VORONOI_F2;
						break;
					case VORONOI_F3:
						tex->blenderStucci.noisebasis = slg::ocl::VORONOI_F3;
						break;
					case VORONOI_F4:
						tex->blenderStucci.noisebasis = slg::ocl::VORONOI_F4;
						break;
					case VORONOI_F2_F1:
						tex->blenderStucci.noisebasis = slg::ocl::VORONOI_F2_F1;
						break;
					case VORONOI_CRACKLE:
						tex->blenderStucci.noisebasis = slg::ocl::VORONOI_CRACKLE;
						break;
					case CELL_NOISE:
						tex->blenderStucci.noisebasis = slg::ocl::CELL_NOISE;
						break;
				}

				break;
			}
			case BLENDER_WOOD: {
				BlenderWoodTexture *wt = static_cast<BlenderWoodTexture *>(t);

				tex->type = slg::ocl::BLENDER_WOOD;
				CompileTextureMapping3D(&tex->blenderWood.mapping, wt->GetTextureMapping());
				tex->blenderWood.turbulence = wt->GetTurbulence();
				tex->blenderWood.bright = wt->GetBright();
				tex->blenderWood.contrast = wt->GetContrast();
				tex->blenderWood.hard = wt->GetNoiseType();
				tex->blenderWood.noisesize = wt->GetNoiseSize();
				switch (wt->GetNoiseBasis2()) {
					default:
					case TEX_SIN:
						tex->blenderWood.noisebasis2 = slg::ocl::TEX_SIN;
						break;
					case TEX_SAW:
						tex->blenderWood.noisebasis2 = slg::ocl::TEX_SAW;
						break;
					case TEX_TRI:
						tex->blenderWood.noisebasis2 = slg::ocl::TEX_TRI;
						break;
				}

				switch (wt->GetWoodType()) {
					default:
					case BANDS:
						tex->blenderWood.type = slg::ocl::BANDS;
						break;
					case RINGS:
						tex->blenderWood.type = slg::ocl::RINGS;
						break;
					case BANDNOISE:
						tex->blenderWood.type = slg::ocl::BANDNOISE;
						break;
					case RINGNOISE:
						tex->blenderWood.type = slg::ocl::RINGNOISE;
						break;
				}
				switch (wt->GetNoiseBasis()) {
					default:
					case BLENDER_ORIGINAL:
						tex->blenderWood.noisebasis = slg::ocl::BLENDER_ORIGINAL;
						break;
					case ORIGINAL_PERLIN:
						tex->blenderWood.noisebasis = slg::ocl::ORIGINAL_PERLIN;
						break;
					case IMPROVED_PERLIN:
						tex->blenderWood.noisebasis = slg::ocl::IMPROVED_PERLIN;
						break;
					case VORONOI_F1:
						tex->blenderWood.noisebasis = slg::ocl::VORONOI_F1;
						break;
					case VORONOI_F2:
						tex->blenderWood.noisebasis = slg::ocl::VORONOI_F2;
						break;
					case VORONOI_F3:
						tex->blenderWood.noisebasis = slg::ocl::VORONOI_F3;
						break;
					case VORONOI_F4:
						tex->blenderWood.noisebasis = slg::ocl::VORONOI_F4;
						break;
					case VORONOI_F2_F1:
						tex->blenderWood.noisebasis = slg::ocl::VORONOI_F2_F1;
						break;
					case VORONOI_CRACKLE:
						tex->blenderWood.noisebasis = slg::ocl::VORONOI_CRACKLE;
						break;
					case CELL_NOISE:
						tex->blenderWood.noisebasis = slg::ocl::CELL_NOISE;
						break;
				}
				break;
			}
			case BLENDER_VORONOI: {
				BlenderVoronoiTexture *wt = static_cast<BlenderVoronoiTexture *>(t);

				tex->type = slg::ocl::BLENDER_VORONOI;
				CompileTextureMapping3D(&tex->blenderVoronoi.mapping, wt->GetTextureMapping());
				tex->blenderVoronoi.feature_weight1 = wt->GetFeatureWeight1();
				tex->blenderVoronoi.feature_weight2 = wt->GetFeatureWeight2();
				tex->blenderVoronoi.feature_weight3 = wt->GetFeatureWeight3();
				tex->blenderVoronoi.feature_weight4 = wt->GetFeatureWeight4();
				tex->blenderVoronoi.noisesize = wt->GetNoiseSize();
				tex->blenderVoronoi.intensity = wt->GetIntensity();
				tex->blenderVoronoi.exponent = wt->GetExponent();
				tex->blenderVoronoi.bright = wt->GetBright();
				tex->blenderVoronoi.contrast = wt->GetContrast();

				switch (wt->GetDistMetric()) {
					default:
					case ACTUAL_DISTANCE:
						tex->blenderVoronoi.distancemetric = slg::ocl::ACTUAL_DISTANCE;
						break;
					case DISTANCE_SQUARED:
						tex->blenderVoronoi.distancemetric = slg::ocl::DISTANCE_SQUARED;
						break;
					case MANHATTAN:
						tex->blenderVoronoi.distancemetric = slg::ocl::MANHATTAN;
						break;
					case CHEBYCHEV:
						tex->blenderVoronoi.distancemetric = slg::ocl::CHEBYCHEV;
						break;
					case MINKOWSKI_HALF:
						tex->blenderVoronoi.distancemetric = slg::ocl::MINKOWSKI_HALF;
						break;
					case MINKOWSKI_FOUR:
						tex->blenderVoronoi.distancemetric = slg::ocl::MINKOWSKI_FOUR;
						break;
					case MINKOWSKI:
						tex->blenderVoronoi.distancemetric = slg::ocl::MANHATTAN;
						break;
				}
				break;
			}
            case UV_TEX: {
				UVTexture *uvt = static_cast<UVTexture *>(t);

				tex->type = slg::ocl::UV_TEX;
				CompileTextureMapping2D(&tex->uvTex.mapping, uvt->GetTextureMapping());
				break;
			}
			case BAND_TEX: {
				BandTexture *bt = static_cast<BandTexture *>(t);

				tex->type = slg::ocl::BAND_TEX;
				
				switch (bt->GetInterpolationType()) {
					case BandTexture::NONE:
						tex->band.interpType = slg::ocl::INTERP_NONE;
						break;
					default:
					case BandTexture::LINEAR:
						tex->band.interpType = slg::ocl::INTERP_LINEAR;
						break;
					case BandTexture::CUBIC:
						tex->band.interpType = slg::ocl::INTERP_CUBIC;
						break;
				}
				
				const Texture *amount = bt->GetAmountTexture();
				tex->band.amountTexIndex = scene->texDefs.GetTextureIndex(amount);

				const vector<float> &offsets = bt->GetOffsets();
				const vector<Spectrum> &values = bt->GetValues();
				if (offsets.size() > BAND_TEX_MAX_SIZE)
					throw runtime_error("BandTexture with more than " + ToString(BAND_TEX_MAX_SIZE) + " are not supported");
				tex->band.size = offsets.size();
				for (u_int i = 0; i < BAND_TEX_MAX_SIZE; ++i) {
					if (i < offsets.size()) {
						tex->band.offsets[i] = offsets[i];
						ASSIGN_SPECTRUM(tex->band.values[i], values[i]);
					} else {
						tex->band.offsets[i] = 1.f;
						tex->band.values[i].c[0] = 0.f;
						tex->band.values[i].c[1] = 0.f;
						tex->band.values[i].c[2] = 0.f;
					}
				}
				break;
			}
			case HITPOINTCOLOR: {
				tex->type = slg::ocl::HITPOINTCOLOR;
				break;
			}
			case HITPOINTALPHA: {
				tex->type = slg::ocl::HITPOINTALPHA;
				break;
			}
			case HITPOINTGREY: {
				HitPointGreyTexture *hpg = static_cast<HitPointGreyTexture *>(t);

				tex->type = slg::ocl::HITPOINTGREY;
				tex->hitPointGrey.channel = hpg->GetChannel();
				break;
			}
            case NORMALMAP_TEX: {
                NormalMapTexture *nmt = static_cast<NormalMapTexture *>(t);

                tex->type = slg::ocl::NORMALMAP_TEX;
                const Texture *normalTex = nmt->GetTexture();
				tex->normalMap.texIndex = scene->texDefs.GetTextureIndex(normalTex);
				break;
            }
			case BLACKBODY_TEX: {
				BlackBodyTexture *bbt = static_cast<BlackBodyTexture *>(t);

				tex->type = slg::ocl::BLACKBODY_TEX;
				ASSIGN_SPECTRUM(tex->blackBody.rgb, bbt->GetRGB());
				break;
			}
			case IRREGULARDATA_TEX: {
				IrregularDataTexture *idt = static_cast<IrregularDataTexture *>(t);

				tex->type = slg::ocl::IRREGULARDATA_TEX;
				ASSIGN_SPECTRUM(tex->irregularData.rgb, idt->GetRGB());
				break;
			}
			case FRESNELCOLOR_TEX: {
				FresnelColorTexture *fct = static_cast<FresnelColorTexture *>(t);

				tex->type = slg::ocl::FRESNELCOLOR_TEX;
				const Texture *krTex = fct->GetKr();
				tex->fresnelColor.krIndex = scene->texDefs.GetTextureIndex(krTex);
				break;
			}
			case FRESNELCONST_TEX: {
				FresnelConstTexture *fct = static_cast<FresnelConstTexture *>(t);

				tex->type = slg::ocl::FRESNELCONST_TEX;
				ASSIGN_SPECTRUM(tex->fresnelConst.n, fct->GetN());
				ASSIGN_SPECTRUM(tex->fresnelConst.k, fct->GetK());
				break;
			}
			case ABS_TEX: {
				AbsTexture *at = static_cast<AbsTexture *>(t);

				tex->type = slg::ocl::ABS_TEX;
				const Texture *refTex = at->GetTexture();
				tex->absTex.texIndex = scene->texDefs.GetTextureIndex(refTex);
				break;
			}
			case CLAMP_TEX: {
				ClampTexture *ct = static_cast<ClampTexture *>(t);

				tex->type = slg::ocl::CLAMP_TEX;
				const Texture *refTex = ct->GetTexture();
				tex->clampTex.texIndex = scene->texDefs.GetTextureIndex(refTex);
				tex->clampTex.minVal = ct->GetMinVal();
				tex->clampTex.maxVal = ct->GetMaxVal();
				break;
			}
			case BILERP_TEX: {
				BilerpTexture *bt = static_cast<BilerpTexture *>(t);
				tex->type = slg::ocl::BILERP_TEX;
				const Texture *t00 = bt->GetTexture00();
				const Texture *t01 = bt->GetTexture01();
				const Texture *t10 = bt->GetTexture10();
				const Texture *t11 = bt->GetTexture11();
				tex->bilerpTex.t00Index = scene->texDefs.GetTextureIndex(t00);
				tex->bilerpTex.t01Index = scene->texDefs.GetTextureIndex(t01);
				tex->bilerpTex.t10Index = scene->texDefs.GetTextureIndex(t10);
				tex->bilerpTex.t11Index = scene->texDefs.GetTextureIndex(t11);
				break;
			}
			case COLORDEPTH_TEX: {
				ColorDepthTexture *ct = static_cast<ColorDepthTexture *>(t);

				tex->type = slg::ocl::COLORDEPTH_TEX;
				const Texture *ktTex = ct->GetKt();
				tex->colorDepthTex.ktIndex = scene->texDefs.GetTextureIndex(ktTex);
				tex->colorDepthTex.dVal = ct->GetD();
				break;
			}
			case HSV_TEX: {
				HsvTexture *ht = static_cast<HsvTexture *>(t);

				tex->type = slg::ocl::HSV_TEX;
				tex->hsvTex.texIndex = scene->texDefs.GetTextureIndex(ht->GetTexture());
				tex->hsvTex.hueTexIndex = scene->texDefs.GetTextureIndex(ht->GetHue());
				tex->hsvTex.satTexIndex = scene->texDefs.GetTextureIndex(ht->GetSaturation());
				tex->hsvTex.valTexIndex = scene->texDefs.GetTextureIndex(ht->GetValue());
				break;
			}
			default:
				throw runtime_error("Unknown texture in CompiledScene::CompileTextures(): " + boost::lexical_cast<string>(t->GetType()));
				break;
		}
	}

	const double tEnd = WallClockTime();
	SLG_LOG("Textures compilation time: " << int((tEnd - tStart) * 1000.0) << "ms");
}

//------------------------------------------------------------------------------
// Dynamic OpenCL code generation for texture evaluation
//------------------------------------------------------------------------------

static string AddTextureSourceCall(const vector<slg::ocl::Texture> &texs,
		const string &type, const u_int i) {
	stringstream ss;

	const slg::ocl::Texture *tex = &texs[i];
	switch (tex->type) {
		case slg::ocl::CONST_FLOAT:
			ss << "ConstFloatTexture_ConstEvaluate" << type << "(&texs[" << i << "])";
			break;
		case slg::ocl::CONST_FLOAT3:
			ss << "ConstFloat3Texture_ConstEvaluate" << type << "(&texs[" << i << "])";
			break;
		case slg::ocl::IMAGEMAP:
			ss << "ImageMapTexture_ConstEvaluate" << type << "(&texs[" << i << "], hitPoint IMAGEMAPS_PARAM)";
			break;
		case slg::ocl::FRESNELCONST_TEX:
			ss << " FresnelConstTexture_ConstEvaluate" << type << "(&texs[" << i << "])";
			break;
		case slg::ocl::FRESNELCOLOR_TEX:
			ss << " FresnelColorTexture_ConstEvaluate" << type << "(&texs[" << i << "])";
			break;
		case slg::ocl::NORMALMAP_TEX:
			ss << "NormalMapTexture_ConstEvaluate" << type << "(&texs[" << i << "])";
			break;
		default:
			ss << "Texture_Index" << i << "_Evaluate" << type << "(&texs[" << i << "], hitPoint TEXTURES_PARAM)";
			break;
	}

	return ss.str();
}

static string AddTextureBumpSourceCall(const vector<slg::ocl::Texture> &texs, const u_int i) {
	stringstream ss;

	const slg::ocl::Texture *tex = &texs[i];
	switch (tex->type) {
		case slg::ocl::CONST_FLOAT:
			ss << "ConstFloatTexture_Bump(hitPoint)";
			break;
		case slg::ocl::CONST_FLOAT3:
			ss << "ConstFloat3Texture_Bump(hitPoint)";
			break;
		case slg::ocl::IMAGEMAP:
			ss << "ImageMapTexture_Bump(&texs[" << i << "], hitPoint, sampleDistance IMAGEMAPS_PARAM)";
			break;
		case slg::ocl::FRESNELCONST_TEX:
			ss << "FresnelConstTexture_Bump(hitPoint)";
			break;
		case slg::ocl::FRESNELCOLOR_TEX:
			ss << "FresnelColorTexture_Bump(hitPoint)";
			break;
		case slg::ocl::NORMALMAP_TEX:
			ss << "NormalMapTexture_Bump(&texs[" << i << "], hitPoint, sampleDistance TEXTURES_PARAM)";
			break;
		case slg::ocl::ADD_TEX:
		case slg::ocl::SUBTRACT_TEX:
		case slg::ocl::MIX_TEX:
		case slg::ocl::SCALE_TEX:
			ss << "Texture_Index" << i << "_Bump(hitPoint, sampleDistance TEXTURES_PARAM)";
			break;
		default:
			ss << "GenericTexture_Bump(" << i << ", hitPoint, sampleDistance TEXTURES_PARAM)";
			break;
	}

	return ss.str();
}

static void AddTextureSource(stringstream &source,  const string &texName, const string &returnType,
		const string &type, const u_int i, const string &texArgs) {
	source << returnType << " Texture_Index" << i << "_Evaluate" << type << "(__global const Texture *texture,\n"
			"\t\t__global HitPoint *hitPoint\n"
			"\t\tTEXTURES_PARAM_DECL) {\n"
			"\treturn " << texName << "Texture_ConstEvaluate" << type << "(hitPoint" <<
				((texArgs.length() > 0) ? (", " + texArgs) : "") << ");\n"
			"}\n";
}

static void AddTextureSource(stringstream &source,  const string &texName,
		const u_int i, const string &texArgs) {
	AddTextureSource(source, texName, "float", "Float", i, texArgs);
	AddTextureSource(source, texName, "float3", "Spectrum", i, texArgs);
}

static void AddTextureBumpSource(stringstream &source, const vector<slg::ocl::Texture> &texs) {
	const u_int texturesCount = texs.size();

	for (u_int i = 0; i < texturesCount; ++i) {
		const slg::ocl::Texture *tex = &texs[i];

		switch (tex->type) {
			case slg::ocl::CONST_FLOAT:
			case slg::ocl::CONST_FLOAT3:
			case slg::ocl::IMAGEMAP:
			case slg::ocl::FRESNELCONST_TEX:
			case slg::ocl::FRESNELCOLOR_TEX:
			case slg::ocl::NORMALMAP_TEX:
				break;
			case slg::ocl::ADD_TEX: {
				source << "#if defined(PARAM_ENABLE_TEX_ADD)\n";
				source << "float3 Texture_Index" << i << "_Bump(__global HitPoint *hitPoint,\n"
						"\t\tconst float sampleDistance\n"
						"\t\tTEXTURES_PARAM_DECL) {\n"
						"\tconst float3 tex1ShadeN = " << AddTextureBumpSourceCall(texs, tex->addTex.tex1Index) <<";\n"
						"\tconst float3 tex2ShadeN = " << AddTextureBumpSourceCall(texs, tex->addTex.tex2Index) <<";\n"
						"\treturn normalize(tex1ShadeN + tex2ShadeN - VLOAD3F(&hitPoint->shadeN.x));\n"
						"}\n";
				source << "#endif\n";
				break;
			}
			case slg::ocl::SUBTRACT_TEX: {
				source << "#if defined(PARAM_ENABLE_TEX_SUBTRACT)\n";
				source << "float3 Texture_Index" << i << "_Bump(__global HitPoint *hitPoint,\n"
						"\t\tconst float sampleDistance\n"
						"\t\tTEXTURES_PARAM_DECL) {\n"
						"\tconst float3 tex1ShadeN = " << AddTextureBumpSourceCall(texs, tex->subtractTex.tex1Index) << ";\n"
						"\tconst float3 tex2ShadeN = " << AddTextureBumpSourceCall(texs, tex->subtractTex.tex2Index) << ";\n"
						"\treturn normalize(tex1ShadeN - tex2ShadeN + VLOAD3F(&hitPoint->shadeN.x));\n"
						"}\n";
				source << "#endif\n";
				break;
			}
			case slg::ocl::MIX_TEX: {
				source << "#if defined(PARAM_ENABLE_TEX_MIX)\n";
				source << "float3 Texture_Index" << i << "_Bump(__global HitPoint *hitPoint,\n"
						"\t\tconst float sampleDistance\n"
						"\t\tTEXTURES_PARAM_DECL) {\n"
						"\t const float3 shadeN = VLOAD3F(&hitPoint->shadeN.x);\n"
						"\tconst float3 u = normalize(VLOAD3F(&hitPoint->dpdu.x));\n"
						"\tconst float3 v = normalize(cross(shadeN, u));\n"
						"\tfloat3 n = " << AddTextureBumpSourceCall(texs, tex->mixTex.tex1Index) << ";\n"
						"\tfloat nn = dot(n, shadeN);\n"
						"\tconst float du1 = dot(n, u) / nn;\n"
						"\tconst float dv1 = dot(n, v) / nn;\n"
						"\tn = " << AddTextureBumpSourceCall(texs, tex->mixTex.tex2Index) << ";\n"
						"\tnn = dot(n, shadeN);\n"
						"\tconst float du2 = dot(n, u) / nn;\n"
						"\tconst float dv2 = dot(n, v) / nn;\n"
						"\tn = " << AddTextureBumpSourceCall(texs, tex->mixTex.amountTexIndex) << ";\n"
						"\tnn = dot(n, shadeN);\n"
						"\tconst float dua = dot(n, u) / nn;\n"
						"\tconst float dva = dot(n, v) / nn;\n"
						"\tconst float t1 = " << AddTextureSourceCall(texs, "Float", tex->mixTex.tex1Index) << ";\n"
						"\tconst float t2 = " << AddTextureSourceCall(texs, "Float", tex->mixTex.tex2Index) << ";\n"
						"\tconst float amt = clamp(" << AddTextureSourceCall(texs, "Float", tex->mixTex.amountTexIndex) << ", 0.f, 1.f);\n"
						"\tconst float du = mix(du1, du2, amt) + dua * (t2 - t1);\n"
						"\tconst float dv = mix(dv1, dv2, amt) + dva * (t2 - t1);\n"
						"\treturn normalize(shadeN + du * u + dv * v);\n"
						"}\n";
				source << "#endif\n";
				break;
			}
			case slg::ocl::SCALE_TEX: {
				source << "#if defined(PARAM_ENABLE_TEX_SCALE)\n";
				source << "float3 Texture_Index" << i << "_Bump(__global HitPoint *hitPoint,\n"
						"\t\tconst float sampleDistance\n"
						"\t\tTEXTURES_PARAM_DECL) {\n"
						"\t const float3 shadeN = VLOAD3F(&hitPoint->shadeN.x);\n"
						"\tconst float3 u = normalize(VLOAD3F(&hitPoint->dpdu.x));\n"
						"\tconst float3 v = normalize(cross(shadeN, u));\n"
						"\tfloat3 n = " << AddTextureBumpSourceCall(texs, tex->scaleTex.tex1Index) << ";\n"
						"\tfloat nn = dot(n, shadeN);\n"
						"\tconst float du1 = dot(n, u) / nn;\n"
						"\tconst float dv1 = dot(n, v) / nn;\n"
						"\tn = " << AddTextureBumpSourceCall(texs, tex->scaleTex.tex2Index) << ";\n"
						"\tnn = dot(n, shadeN);\n"
						"\tconst float du2 = dot(n, u) / nn;\n"
						"\tconst float dv2 = dot(n, v) / nn;\n"
						"\tconst float t1 = " << AddTextureSourceCall(texs, "Float", tex->scaleTex.tex1Index) << ";\n"
						"\tconst float t2 = " << AddTextureSourceCall(texs, "Float", tex->scaleTex.tex2Index) << ";\n"
						"\tconst float du = du1 * t2 + t1 * du2;\n"
						"\tconst float dv = dv1 * t2 + t1 * dv2;\n"
						"\treturn normalize(shadeN + du * u + dv * v);\n"
						"}\n";
				source << "#endif\n";
				break;
			}
			default:
				// Nothing to do for textures using GenericTexture_Bump()
				break;
		}
	}

	//--------------------------------------------------------------------------
	// Generate the code for evaluating a generic texture bump
	//--------------------------------------------------------------------------

	source << "float3 Texture_Bump(const uint texIndex, "
			"__global HitPoint *hitPoint, const float sampleDistance "
			"TEXTURES_PARAM_DECL) {\n"
			"\t__global const Texture *tex = &texs[texIndex];\n";

	//--------------------------------------------------------------------------
	// For textures source code that it is not dynamically generated
	//--------------------------------------------------------------------------

	source << "\tswitch (tex->type) {\n"
			"#if defined(PARAM_ENABLE_TEX_CONST_FLOAT)\n"
			"\t\tcase CONST_FLOAT: return ConstFloatTexture_Bump(hitPoint);\n"
			"#endif\n"
			"#if defined(PARAM_ENABLE_TEX_CONST_FLOAT3)\n"
			"\t\tcase CONST_FLOAT3: return ConstFloat3Texture_Bump(hitPoint);\n"
			"#endif\n"
			// I can have an IMAGEMAP texture only if PARAM_HAS_IMAGEMAPS is defined
			"#if defined(PARAM_ENABLE_TEX_IMAGEMAP) && defined(PARAM_HAS_IMAGEMAPS)\n"
			"\t\tcase IMAGEMAP: return ImageMapTexture_Bump(tex, hitPoint, sampleDistance IMAGEMAPS_PARAM);\n"
			"#endif\n"
			"#if defined(PARAM_ENABLE_TEX_FRESNELCONST)\n"
			"\t\tcase FRESNELCONST_TEX: return FresnelConstTexture_Bump(hitPoint);\n"
			"#endif\n"
			"#if defined(PARAM_ENABLE_TEX_FRESNELCOLOR)\n"
			"\t\tcase FRESNELCOLOR_TEX: return FresnelColorTexture_Bump(hitPoint);\n"
			"#endif\n"
			"#if defined(PARAM_ENABLE_TEX_NORMALMAP)\n"
			"\t\tcase NORMALMAP_TEX: return NormalMapTexture_Bump(tex, hitPoint, sampleDistance TEXTURES_PARAM);\n"
			"#endif\n"
			"\t\tdefault: break;\n"
			"\t}\n";

	//--------------------------------------------------------------------------
	// For textures source code that it is dynamically generated
	//--------------------------------------------------------------------------

	source <<  "\tswitch (texIndex) {\n";
	for (u_int i = 0; i < texturesCount; ++i) {
		// Generate the case only for dynamically generated code
		const slg::ocl::Texture *tex = &texs[i];

		switch (tex->type) {
			case slg::ocl::CONST_FLOAT:
			case slg::ocl::CONST_FLOAT3:
			case slg::ocl::IMAGEMAP:
			case slg::ocl::FRESNELCONST_TEX:
			case slg::ocl::FRESNELCOLOR_TEX:
			case slg::ocl::NORMALMAP_TEX:
				// For textures source code that it is not dynamically generated
				break;
			case slg::ocl::ADD_TEX:
			case slg::ocl::SUBTRACT_TEX:
			case slg::ocl::MIX_TEX:
			case slg::ocl::SCALE_TEX:
				// For textures source code that it must be dynamically generated
				source << "\t\tcase " << i << ": return Texture_Index" << i << "_Bump(hitPoint, sampleDistance TEXTURES_PARAM);\n";
				break;
			default:
				// For all others using GenericTexture_Bump()
				break;
		}
	}
	source <<
			"\t\tdefault: return GenericTexture_Bump(texIndex, hitPoint, sampleDistance TEXTURES_PARAM);\n"
			"\t}\n"
			"}\n";
}

static void AddTexturesSwitchSourceCode(stringstream &source, 
		const vector<slg::ocl::Texture> &texs, const string &type, const string &returnType) {
	const u_int texturesCount = texs.size();

	// Generate the code for evaluating a generic texture
	source << returnType << " Texture_Get" << type << "Value(const uint texIndex, __global HitPoint *hitPoint TEXTURES_PARAM_DECL) {\n"
			"\t __global const Texture *tex = &texs[texIndex];\n";

	//--------------------------------------------------------------------------
	// For textures source code that it is not dynamically generated
	//--------------------------------------------------------------------------
	source << "\tswitch (tex->type) {\n"
			"#if defined(PARAM_ENABLE_TEX_CONST_FLOAT)\n"
			"\t\tcase CONST_FLOAT: return ConstFloatTexture_ConstEvaluate" << type << "(tex);\n"
			"#endif\n"
			"#if defined(PARAM_ENABLE_TEX_CONST_FLOAT3)\n"
			"\t\tcase CONST_FLOAT3: return ConstFloat3Texture_ConstEvaluate" << type << "(tex);\n"
			"#endif\n"
			// I can have an IMAGEMAP texture only if PARAM_HAS_IMAGEMAPS is defined
			"#if defined(PARAM_ENABLE_TEX_IMAGEMAP) && defined(PARAM_HAS_IMAGEMAPS)\n"
			"\t\tcase IMAGEMAP: return ImageMapTexture_ConstEvaluate" << type << "(tex, hitPoint IMAGEMAPS_PARAM);\n"
			"#endif\n"
			"#if defined(PARAM_ENABLE_TEX_FRESNELCONST)\n"
			"\t\tcase FRESNELCONST_TEX: return FresnelConstTexture_ConstEvaluate" << type << "(tex);\n"
			"#endif\n"
			"#if defined(PARAM_ENABLE_TEX_FRESNELCOLOR)\n"
			"\t\tcase FRESNELCOLOR_TEX: return FresnelColorTexture_ConstEvaluate" << type << "(tex);\n"
			"#endif\n"
			"#if defined(PARAM_ENABLE_TEX_NORMALMAP)\n"
			"\t\tcase NORMALMAP_TEX: return NormalMapTexture_ConstEvaluate" << type << "(tex);\n"
			"#endif\n"
			"\t\tdefault: break;\n" <<
			"\t}\n";

	//--------------------------------------------------------------------------
	// For textures source code that it is dynamically generated
	//--------------------------------------------------------------------------

	source << "\tswitch (texIndex) {\n";
	for (u_int i = 0; i < texturesCount; ++i) {
		// Generate the case only for dynamically generated code
		const slg::ocl::Texture *tex = &texs[i];

		switch (tex->type) {
			case slg::ocl::CONST_FLOAT:
			case slg::ocl::CONST_FLOAT3:
			case slg::ocl::IMAGEMAP:
			case slg::ocl::FRESNELCONST_TEX:
			case slg::ocl::FRESNELCOLOR_TEX:
			case slg::ocl::NORMALMAP_TEX:
				// For textures source code that it is not dynamically generated
				break;
			default:
				source << "\t\tcase " << i << ": return Texture_Index" << i << "_Evaluate" << type << "(tex, hitPoint TEXTURES_PARAM);\n";
				break;
		}
	}
	// This default should be never be reached as all cases should be catch by previous switches
	source << "\t\tdefault: return 0.f;\n"
			"\t}\n"
			"}\n";
}

string CompiledScene::GetTexturesEvaluationSourceCode() const {
	// Generate the source code for each texture that reference other textures
	// and constant textures
	stringstream source;

	const u_int texturesCount = texs.size();
	for (u_int i = 0; i < texturesCount; ++i) {
		const slg::ocl::Texture *tex = &texs[i];

		switch (tex->type) {
			case slg::ocl::CONST_FLOAT:
			case slg::ocl::CONST_FLOAT3:
			case slg::ocl::IMAGEMAP:
			case slg::ocl::FRESNELCONST_TEX:
			case slg::ocl::FRESNELCOLOR_TEX:
			case slg::ocl::NORMALMAP_TEX:
				// Constant textures source code is not dynamically generated
				break;
			case slg::ocl::SCALE_TEX: {
				AddTextureSource(source, "Scale", "float", "Float", i,
						AddTextureSourceCall(texs, "Float", tex->scaleTex.tex1Index) + ", " +
						AddTextureSourceCall(texs, "Float", tex->scaleTex.tex2Index));
				AddTextureSource(source, "Scale", "float3", "Spectrum", i,
						AddTextureSourceCall(texs, "Spectrum", tex->scaleTex.tex1Index) + ", " +
						AddTextureSourceCall(texs, "Spectrum", tex->scaleTex.tex2Index));
				break;
			}
			case FRESNEL_APPROX_N:
				AddTextureSource(source, "FresnelApproxN", "float", "Float", i,
						AddTextureSourceCall(texs, "Float", tex->fresnelApproxN.texIndex));
				AddTextureSource(source, "FresnelApproxN", "float3", "Spectrum", i,
						AddTextureSourceCall(texs, "Spectrum", tex->fresnelApproxN.texIndex));
				break;
			case FRESNEL_APPROX_K:
				AddTextureSource(source, "FresnelApproxK", "float", "Float", i,
						AddTextureSourceCall(texs, "Float", tex->fresnelApproxK.texIndex));
				AddTextureSource(source, "FresnelApproxK", "float3", "Spectrum", i,
						AddTextureSourceCall(texs, "Spectrum", tex->fresnelApproxK.texIndex));
				break;
			case slg::ocl::MIX_TEX: {
				AddTextureSource(source, "Mix", "float", "Float", i,
						AddTextureSourceCall(texs, "Float", tex->mixTex.amountTexIndex) + ", " +
						AddTextureSourceCall(texs, "Float", tex->mixTex.tex1Index) + ", " +
						AddTextureSourceCall(texs, "Float", tex->mixTex.tex2Index));
				AddTextureSource(source, "Mix", "float3", "Spectrum", i,
						AddTextureSourceCall(texs, "Float", tex->mixTex.amountTexIndex) + ", " +
						AddTextureSourceCall(texs, "Spectrum", tex->mixTex.tex1Index) + ", " +
						AddTextureSourceCall(texs, "Spectrum", tex->mixTex.tex2Index));
				break;
			}
			case slg::ocl::ADD_TEX: {
				AddTextureSource(source, "Add", "float", "Float", i,
						AddTextureSourceCall(texs, "Float", tex->addTex.tex1Index) + ", " +
						AddTextureSourceCall(texs, "Float", tex->addTex.tex2Index));
				AddTextureSource(source, "Add", "float3", "Spectrum", i,
						AddTextureSourceCall(texs, "Spectrum", tex->addTex.tex1Index) + ", " +
						AddTextureSourceCall(texs, "Spectrum", tex->addTex.tex2Index));
				break;
			}
			case slg::ocl::SUBTRACT_TEX: {
				AddTextureSource(source, "Subtract", "float", "Float", i,
								 AddTextureSourceCall(texs, "Float", tex->subtractTex.tex1Index) + ", " +
								 AddTextureSourceCall(texs, "Float", tex->subtractTex.tex2Index));
				AddTextureSource(source, "Subtract", "float3", "Spectrum", i,
								 AddTextureSourceCall(texs, "Spectrum", tex->subtractTex.tex1Index) + ", " +
								 AddTextureSourceCall(texs, "Spectrum", tex->subtractTex.tex2Index));
				break;
			}
			case slg::ocl::HITPOINTCOLOR:
				AddTextureSource(source, "HitPointColor", i, "");
				break;
			case slg::ocl::HITPOINTALPHA:
				AddTextureSource(source, "HitPointAlpha", i, "");
				break;
			case slg::ocl::HITPOINTGREY:
				AddTextureSource(source, "HitPointGrey", i, "texture->hitPointGrey.channel");
				break;
			case slg::ocl::BLENDER_BLEND:
				AddTextureSource(source, "BlenderBlend", i,
						"texture->blenderBlend.type, "
						"texture->blenderBlend.direction, "
						"texture->blenderBlend.contrast, "
						"texture->blenderBlend.bright, "
						"&texture->blenderBlend.mapping");
				break;
			case slg::ocl::BLENDER_CLOUDS:
				AddTextureSource(source, "BlenderClouds", i,
						"texture->blenderClouds.noisebasis, "
						"texture->blenderClouds.noisesize, "
						"texture->blenderClouds.noisedepth, "
						"texture->blenderClouds.contrast, "
						"texture->blenderClouds.bright, "
						"texture->blenderClouds.hard, "
						"&texture->blenderClouds.mapping");
				break;
			case slg::ocl::BLENDER_DISTORTED_NOISE:
				AddTextureSource(source, "BlenderDistortedNoise", i,
						"texture->blenderDistortedNoise.noisedistortion, "
						"texture->blenderDistortedNoise.noisebasis, "
						"texture->blenderDistortedNoise.distortion, "
						"texture->blenderDistortedNoise.noisesize, "
						"texture->blenderDistortedNoise.contrast, "
						"texture->blenderDistortedNoise.bright, "
						"&texture->blenderDistortedNoise.mapping");
				break;
			case slg::ocl::BLENDER_MAGIC:
				AddTextureSource(source, "BlenderMagic", "float", "Float", i,
						"texture->blenderMagic.noisedepth, "
						"texture->blenderMagic.turbulence, "
						"texture->blenderMagic.contrast, "
						"texture->blenderMagic.bright, "
						"&texture->blenderMagic.mapping");
				AddTextureSource(source, "BlenderMagic", "float3", "Spectrum", i,
						"texture->blenderMagic.noisedepth, "
						"texture->blenderMagic.turbulence, "
						"texture->blenderMagic.contrast, "
						"texture->blenderMagic.bright, "
						"&texture->blenderMagic.mapping");
				break;
			case slg::ocl::BLENDER_MARBLE:
				AddTextureSource(source, "BlenderMarble", i,
						"texture->blenderMarble.type, "
						"texture->blenderMarble.noisebasis, "
						"texture->blenderMarble.noisebasis2, "
						"texture->blenderMarble.noisesize, "
						"texture->blenderMarble.turbulence, "
						"texture->blenderMarble.noisedepth, "
						"texture->blenderMarble.contrast, "
						"texture->blenderMarble.bright, "
						"texture->blenderMarble.hard, "
						"&texture->blenderMagic.mapping");
				break;
			case slg::ocl::BLENDER_MUSGRAVE:
				AddTextureSource(source, "BlenderMusgrave", i,
						"texture->blenderMusgrave.type, "
						"texture->blenderMusgrave.noisebasis, "
						"texture->blenderMusgrave.dimension, "
						"texture->blenderMusgrave.intensity, "
						"texture->blenderMusgrave.lacunarity, "
						"texture->blenderMusgrave.offset, "
						"texture->blenderMusgrave.gain, "
						"texture->blenderMusgrave.octaves, "
						"texture->blenderMusgrave.noisesize, "
						"texture->blenderMusgrave.contrast, "
						"texture->blenderMusgrave.bright, "
						"&texture->blenderMusgrave.mapping");
				break;
			case slg::ocl::BLENDER_STUCCI:
				AddTextureSource(source, "BlenderStucci", i,
						"texture->blenderStucci.type, "
						"texture->blenderStucci.noisebasis, "
						"texture->blenderStucci.noisesize, "
						"texture->blenderStucci.turbulence, "
						"texture->blenderStucci.contrast, "
						"texture->blenderStucci.bright, "
						"texture->blenderStucci.hard, "
						"&texture->blenderStucci.mapping");
				break;
            case slg::ocl::BLENDER_WOOD:
				AddTextureSource(source, "BlenderWood", i,
						"texture->blenderWood.type, "
						"texture->blenderWood.noisebasis2, "
						"texture->blenderWood.noisebasis, "
						"texture->blenderWood.noisesize, "
						"texture->blenderWood.turbulence, "
						"texture->blenderWood.contrast, "
						"texture->blenderWood.bright, "
						"texture->blenderWood.hard, "
						"&texture->blenderWood.mapping");
				break;
			case slg::ocl::BLENDER_VORONOI:
				AddTextureSource(source, "BlenderVoronoi", i,
						"texture->blenderVoronoi.distancemetric, "
						"texture->blenderVoronoi.feature_weight1, "
						"texture->blenderVoronoi.feature_weight2, "
						"texture->blenderVoronoi.feature_weight3, "
						"texture->blenderVoronoi.feature_weight4, "
						"texture->blenderVoronoi.noisesize, "
						"texture->blenderVoronoi.intensity, "
						"texture->blenderVoronoi.exponent, "
						"texture->blenderVoronoi.contrast, "
						"texture->blenderVoronoi.bright, "
						"&texture->blenderVoronoi.mapping");
				break;
			case slg::ocl::CHECKERBOARD2D:
				AddTextureSource(source, "CheckerBoard2D", "float", "Float", i,
						AddTextureSourceCall(texs, "Float", tex->checkerBoard2D.tex1Index) + ", " +
						AddTextureSourceCall(texs, "Float", tex->checkerBoard2D.tex2Index) + ", " +
						"&texture->checkerBoard2D.mapping");
				AddTextureSource(source, "CheckerBoard2D", "float3", "Spectrum", i,
						AddTextureSourceCall(texs, "Spectrum", tex->checkerBoard2D.tex1Index) + ", " +
						AddTextureSourceCall(texs, "Spectrum", tex->checkerBoard2D.tex2Index) + ", " +
						"&texture->checkerBoard2D.mapping");
				break;
			case slg::ocl::CHECKERBOARD3D:
				AddTextureSource(source, "CheckerBoard3D", "float", "Float", i,
						AddTextureSourceCall(texs, "Float", tex->checkerBoard3D.tex1Index) + ", " +
						AddTextureSourceCall(texs, "Float", tex->checkerBoard3D.tex2Index) + ", " +
						"&texture->checkerBoard3D.mapping");
				AddTextureSource(source, "CheckerBoard3D", "float3", "Spectrum", i,
						AddTextureSourceCall(texs, "Spectrum", tex->checkerBoard3D.tex1Index) + ", " +
						AddTextureSourceCall(texs, "Spectrum", tex->checkerBoard3D.tex2Index) + ", " +
						"&texture->checkerBoard3D.mapping");
				break;
			case slg::ocl::CLOUD_TEX:
				AddTextureSource(source, "Cloud", i,
					"texture->cloud.radius, "
					"texture->cloud.numspheres, "
					"texture->cloud.spheresize, "
					"texture->cloud.sharpness, "
					"texture->cloud.basefadedistance, "
					"texture->cloud.baseflatness, "
					"texture->cloud.variability, "
					"texture->cloud.omega, "
					"texture->cloud.noisescale, "
					"texture->cloud.noiseoffset, "
					"texture->cloud.turbulence, "
					"texture->cloud.octaves, "
					"&texture->cloud.mapping");
				break;			
			case slg::ocl::FBM_TEX:
				AddTextureSource(source, "FBM", i,
						"texture->fbm.omega, "
						"texture->fbm.octaves, "
						"&texture->fbm.mapping");
				break;
			case slg::ocl::MARBLE:
				AddTextureSource(source, "Marble", i,
						"texture->marble.scale, "
						"texture->marble.omega, "
						"texture->marble.octaves, "
						"texture->marble.variation, "
						"&texture->marble.mapping");
				break;
			case slg::ocl::DOTS:
				AddTextureSource(source, "Dots", "float", "Float", i,
						AddTextureSourceCall(texs, "Float", tex->dots.insideIndex) + ", " +
						AddTextureSourceCall(texs, "Float", tex->dots.outsideIndex) + ", " +
						"&texture->dots.mapping");
				AddTextureSource(source, "Dots", "float3", "Spectrum", i,
						AddTextureSourceCall(texs, "Spectrum", tex->dots.insideIndex) + ", " +
						AddTextureSourceCall(texs, "Spectrum", tex->dots.outsideIndex) + ", " +
						"&texture->dots.mapping");
				break;
			case slg::ocl::BRICK:
				AddTextureSource(source, "Brick", "float", "Float", i,
						AddTextureSourceCall(texs, "Float", tex->brick.tex1Index) + ", " +
						AddTextureSourceCall(texs, "Float", tex->brick.tex2Index) + ", " +
						AddTextureSourceCall(texs, "Float", tex->brick.tex3Index) + ", " +
						"texture->brick.bond, "
						"texture->brick.brickwidth, "
						"texture->brick.brickheight, "
						"texture->brick.brickdepth, "
						"texture->brick.mortarsize, "
						"(float3)(texture->brick.offsetx, texture->brick.offsety, texture->brick.offsetz), "
						"texture->brick.run, "
						"texture->brick.mortarwidth, "
						"texture->brick.mortarheight, "
						"texture->brick.mortardepth, "
						"texture->brick.proportion, "
						"texture->brick.invproportion, "
						"&texture->brick.mapping");
				AddTextureSource(source, "Brick", "float3", "Spectrum", i,
						AddTextureSourceCall(texs, "Spectrum", tex->brick.tex1Index) + ", " +
						AddTextureSourceCall(texs, "Spectrum", tex->brick.tex2Index) + ", " +
						AddTextureSourceCall(texs, "Spectrum", tex->brick.tex3Index) + ", " +
						"texture->brick.bond, "
						"texture->brick.brickwidth, "
						"texture->brick.brickheight, "
						"texture->brick.brickdepth, "
						"texture->brick.mortarsize, "
						"(float3)(texture->brick.offsetx, texture->brick.offsety, texture->brick.offsetz), "
						"texture->brick.run, "
						"texture->brick.mortarwidth, "
						"texture->brick.mortarheight, "
						"texture->brick.mortardepth, "
						"texture->brick.proportion, "
						"texture->brick.invproportion, "
						"&texture->brick.mapping");
				break;
			case slg::ocl::WINDY:
				AddTextureSource(source, "Windy", i,
						"&texture->windy.mapping");
				break;
			case slg::ocl::WRINKLED:
				AddTextureSource(source, "Wrinkled", i,
						"texture->marble.omega, "
						"texture->marble.octaves, "
						"&texture->wrinkled.mapping");
				break;
			case slg::ocl::UV_TEX:
				AddTextureSource(source, "UV", i,
						"&texture->uvTex.mapping");
				break;
			case slg::ocl::BAND_TEX:
				AddTextureSource(source, "Band", "float", "Float", i,
						"texture->band.interpType, "
						"texture->band.size, "
						"texture->band.offsets, "
						"texture->band.values, " +
						AddTextureSourceCall(texs, "Float", tex->band.amountTexIndex));
				AddTextureSource(source, "Band", "float3", "Spectrum", i,
						"texture->band.interpType, "
						"texture->band.size, "
						"texture->band.offsets, "
						"texture->band.values, " +
						AddTextureSourceCall(texs, "Float", tex->band.amountTexIndex));
				break;
			case slg::ocl::BLACKBODY_TEX:
				AddTextureSource(source, "BlackBody", i, ToOCLString(tex->blackBody.rgb));
				break;
			case slg::ocl::IRREGULARDATA_TEX:
				AddTextureSource(source, "IrregularData", i, ToOCLString(tex->irregularData.rgb));
				break;
			case slg::ocl::ABS_TEX: {
				AddTextureSource(source, "Abs", "float", "Float", i,
						AddTextureSourceCall(texs, "Float", tex->absTex.texIndex));
				AddTextureSource(source, "Abs", "float3", "Spectrum", i,
						AddTextureSourceCall(texs, "Spectrum", tex->absTex.texIndex));
				break;
			}
			case slg::ocl::CLAMP_TEX: {
				AddTextureSource(source, "Clamp", "float", "Float", i,
						AddTextureSourceCall(texs, "Float", tex->clampTex.texIndex) + ", " +
						"texture->clampTex.minVal, "
						"texture->clampTex.maxVal");
				AddTextureSource(source, "Clamp", "float3", "Spectrum", i,
						AddTextureSourceCall(texs, "Spectrum", tex->clampTex.texIndex) + ", " +
						"texture->clampTex.minVal, "
						"texture->clampTex.maxVal");
				break;
			}
			case slg::ocl::BILERP_TEX: {
				AddTextureSource(source, "Bilerp", "float", "Float", i, AddTextureSourceCall(texs, "Float", tex->bilerpTex.t00Index) + ", " +
					AddTextureSourceCall(texs, "Float", tex->bilerpTex.t01Index) + ", " +
					AddTextureSourceCall(texs, "Float", tex->bilerpTex.t10Index) + ", " +
					AddTextureSourceCall(texs, "Float", tex->bilerpTex.t11Index));
				AddTextureSource(source, "Bilerp", "float3", "Spectrum", i, AddTextureSourceCall(texs, "Spectrum", tex->bilerpTex.t00Index) + ", " +
					AddTextureSourceCall(texs, "Spectrum", tex->bilerpTex.t01Index) + ", " +
					AddTextureSourceCall(texs, "Spectrum", tex->bilerpTex.t10Index) + ", " +
					AddTextureSourceCall(texs, "Spectrum", tex->bilerpTex.t11Index));
				break;
			}
			case slg::ocl::COLORDEPTH_TEX: {
				AddTextureSource(source, "ColorDepth", "float", "Float", i,
						"texture->colorDepthTex.dVal, " +
						AddTextureSourceCall(texs, "Float", tex->colorDepthTex.ktIndex));
				AddTextureSource(source, "ColorDepth", "float3", "Spectrum", i,
						"texture->colorDepthTex.dVal, " +
						AddTextureSourceCall(texs, "Spectrum", tex->colorDepthTex.ktIndex));
				break;
			}
			case slg::ocl::HSV_TEX: {
				AddTextureSource(source, "Hsv", "float", "Float", i,
						AddTextureSourceCall(texs, "Spectrum", tex->hsvTex.texIndex) + ", " +
						AddTextureSourceCall(texs, "Float", tex->hsvTex.hueTexIndex) + ", " +
						AddTextureSourceCall(texs, "Float", tex->hsvTex.satTexIndex) + ", " +
						AddTextureSourceCall(texs, "Float", tex->hsvTex.valTexIndex));
				AddTextureSource(source, "Hsv", "float3", "Spectrum", i,
						AddTextureSourceCall(texs, "Spectrum", tex->hsvTex.texIndex) + ", " +
						AddTextureSourceCall(texs, "Float", tex->hsvTex.hueTexIndex) + ", " +
						AddTextureSourceCall(texs, "Float", tex->hsvTex.satTexIndex) + ", " +
						AddTextureSourceCall(texs, "Float", tex->hsvTex.valTexIndex));
				break;
			}
			default:
				throw runtime_error("Unknown texture in CompiledScene::GetTexturesEvaluationSourceCode(): " + boost::lexical_cast<string>(tex->type));
				break;
		}
	}

	// Generate the code for evaluating a generic float texture
	AddTexturesSwitchSourceCode(source, texs, "Float", "float");

	// Generate the code for evaluating a generic float texture
	AddTexturesSwitchSourceCode(source, texs, "Spectrum", "float3");

	// Add bump and normal mapping functions
	source << slg::ocl::KernelSource_texture_bump_funcs;

	source << "#if defined(PARAM_HAS_BUMPMAPS)\n";
	AddTextureBumpSource(source, texs);
	source << "#endif\n";

	return source.str();
}

#endif
