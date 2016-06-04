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

#define CAMERAHELPER_CLASSID Class_ID(4128,0)
#define MAX2016_PHYSICAL_CAMERA Class_ID(1181315608,686293133)

#define OMNI_CLASSID Class_ID(4113, 0)
#define SPOTLIGHT_CLASSID Class_ID(4114,0)

#define SKYLIGHT_CLASSID Class_ID(2079724664, 1378764549)
#define DIRLIGHT_CLASSID Class_ID(4115, 0) // free directional light and sun light classid

#include "LuxMaxpch.h"
#include "resource.h"
#include "LuxMax.h"

#include "LuxMaxCamera.h"
#include "LuxMaxUtils.h"
#include "LuxMaxMaterials.h"
#include "LuxMaxLights.h"
#include "LuxMaxMesh.h"

#include <maxscript\maxscript.h>
#include <render.h>
#include <point3.h>
#include <MeshNormalSpec.h>
#include <Path.h>
#include <bitmap.h>
#include <GraphicsWindow.h>
#include <IColorCorrectionMgr.h>
#include <IGame\IGame.h>
#include <VertexNormal.h>
#include <string>
#include <string.h>
#include <iostream>
#include <IMaterialBrowserEntryInfo.h>
#include <units.h>
namespace luxcore
{
#include <luxcore/luxcore.h>
}
#include <boost/filesystem/operations.hpp>
#include <boost/foreach.hpp>
#include <boost/assign.hpp>
#include <boost/format.hpp>
#include <mesh.h>
#include <locale>
#include <sstream>

LuxMaxCamera lxmCamera;
LuxMaxLights lxmLights;
LuxMaxMaterials lxmMaterials;
LuxMaxUtils lxmUtils;
LuxMaxMesh lxmMesh;

#pragma warning (push)
#pragma warning( disable:4002)
#pragma warning (pop)

using namespace std;
using namespace luxcore;
using namespace luxrays;

extern BOOL FileExists(const TCHAR *filename);
float* pixels;

bool defaultlightset = true;
int rendertype = 4;
int renderWidth = 0;
int renderHeight = 0;
bool renderingMaterialPreview = false;
Scene *materialPreviewScene;// = new Scene();

class LuxMaxClassDesc :public ClassDesc2 {
public:
	virtual int 			IsPublic() { return 1; }
	virtual void *			Create(BOOL loading) { UNREFERENCED_PARAMETER(loading); return new LuxMax; }
	virtual const TCHAR *	ClassName() { return GetString(IDS_VRENDTITLE); }
	virtual SClass_ID		SuperClassID() { return RENDERER_CLASS_ID; }
	virtual Class_ID 		ClassID() { return REND_CLASS_ID; }
	virtual const TCHAR* 	Category() { return _T(""); }
	virtual void			ResetClassParams(BOOL fileReset) { UNREFERENCED_PARAMETER(fileReset); }
};

ClassDesc2* GetRendDesc() {
	static LuxMaxClassDesc srendCD;
	return &srendCD;
}

/*enum { lens_params };
enum { lensradius_spin };

/*const int MIN_SPIN = 0.0f;
const int MAX_SPIN = 100.0f;*/
/*

static ParamBlockDesc2 DepthOfFieldblk(lens_params, _T("Simple Parameters"), 0, GetRendDesc(), P_AUTO_CONSTRUCT + P_AUTO_UI, 1,
//rollout
IDD_DEPTH, IDS_DEPTH, 0, 0, NULL,
// params
lensradius_spin,		_T("spin"),			TYPE_FLOAT,		P_ANIMATABLE,	IDS_SPIN,
p_default,			0.1f,
p_range,			0.0f, 1000.0f,
p_ui,				TYPE_SPINNER,		EDITTYPE_FLOAT, IDC_LENSRADIUS, IDC_LENSRADIUS_SPIN, 0.01f,
p_end,
p_end
);*/

RefResult LuxMax::NotifyRefChanged(const Interval &changeInt, RefTargetHandle hTarget, PartID &partID,
	RefMessage message, BOOL propagate)
{
	UNREFERENCED_PARAMETER(propagate);
	UNREFERENCED_PARAMETER(message);
	UNREFERENCED_PARAMETER(partID);
	UNREFERENCED_PARAMETER(hTarget);
	UNREFERENCED_PARAMETER(changeInt);
	/*switch (message)
	{
	case REFMSG_CHANGE:
	{
	if (hTarget == pblock)
	{
	ParamID changing_param = pblock->LastNotifyParamID();
	DepthOfFieldblk.InvalidateUI(changing_param);
	}
	}
	break;
	}*/
	return REF_SUCCEED;
}

static void CreateBox(Scene *scene, const string &objName, const string &meshName,
	const string &matName, const bool enableUV, const BBox &bbox) {
	Point *p = Scene::AllocVerticesBuffer(24);
	// Bottom face
	p[0] = Point(bbox.pMin.x, bbox.pMin.y, bbox.pMin.z);
	p[1] = Point(bbox.pMin.x, bbox.pMax.y, bbox.pMin.z);
	p[2] = Point(bbox.pMax.x, bbox.pMax.y, bbox.pMin.z);
	p[3] = Point(bbox.pMax.x, bbox.pMin.y, bbox.pMin.z);
	// Top face
	p[4] = Point(bbox.pMin.x, bbox.pMin.y, bbox.pMax.z);
	p[5] = Point(bbox.pMax.x, bbox.pMin.y, bbox.pMax.z);
	p[6] = Point(bbox.pMax.x, bbox.pMax.y, bbox.pMax.z);
	p[7] = Point(bbox.pMin.x, bbox.pMax.y, bbox.pMax.z);
	// Side left
	p[8] = Point(bbox.pMin.x, bbox.pMin.y, bbox.pMin.z);
	p[9] = Point(bbox.pMin.x, bbox.pMin.y, bbox.pMax.z);
	p[10] = Point(bbox.pMin.x, bbox.pMax.y, bbox.pMax.z);
	p[11] = Point(bbox.pMin.x, bbox.pMax.y, bbox.pMin.z);
	// Side right
	p[12] = Point(bbox.pMax.x, bbox.pMin.y, bbox.pMin.z);
	p[13] = Point(bbox.pMax.x, bbox.pMax.y, bbox.pMin.z);
	p[14] = Point(bbox.pMax.x, bbox.pMax.y, bbox.pMax.z);
	p[15] = Point(bbox.pMax.x, bbox.pMin.y, bbox.pMax.z);
	// Side back
	p[16] = Point(bbox.pMin.x, bbox.pMin.y, bbox.pMin.z);
	p[17] = Point(bbox.pMax.x, bbox.pMin.y, bbox.pMin.z);
	p[18] = Point(bbox.pMax.x, bbox.pMin.y, bbox.pMax.z);
	p[19] = Point(bbox.pMin.x, bbox.pMin.y, bbox.pMax.z);
	// Side front
	p[20] = Point(bbox.pMin.x, bbox.pMax.y, bbox.pMin.z);
	p[21] = Point(bbox.pMin.x, bbox.pMax.y, bbox.pMax.z);
	p[22] = Point(bbox.pMax.x, bbox.pMax.y, bbox.pMax.z);
	p[23] = Point(bbox.pMax.x, bbox.pMax.y, bbox.pMin.z);

	Triangle *vi = Scene::AllocTrianglesBuffer(12);
	// Bottom face
	vi[0] = Triangle(0, 1, 2);
	vi[1] = Triangle(2, 3, 0);
	// Top face
	vi[2] = Triangle(4, 5, 6);
	vi[3] = Triangle(6, 7, 4);
	// Side left
	vi[4] = Triangle(8, 9, 10);
	vi[5] = Triangle(10, 11, 8);
	// Side right
	vi[6] = Triangle(12, 13, 14);
	vi[7] = Triangle(14, 15, 12);
	// Side back
	vi[8] = Triangle(16, 17, 18);
	vi[9] = Triangle(18, 19, 16);
	// Side back
	vi[10] = Triangle(20, 21, 22);
	vi[11] = Triangle(22, 23, 20);

	// Define the Mesh
	if (!enableUV) {
		// Define the object
		scene->DefineMesh(meshName, 24, 12, p, vi, NULL, NULL, NULL, NULL);
	}
	else {
		UV *uv = new UV[24];
		// Bottom face
		uv[0] = UV(0.f, 0.f);
		uv[1] = UV(1.f, 0.f);
		uv[2] = UV(1.f, 1.f);
		uv[3] = UV(0.f, 1.f);
		// Top face
		uv[4] = UV(0.f, 0.f);
		uv[5] = UV(1.f, 0.f);
		uv[6] = UV(1.f, 1.f);
		uv[7] = UV(0.f, 1.f);
		// Side left
		uv[8] = UV(0.f, 0.f);
		uv[9] = UV(1.f, 0.f);
		uv[10] = UV(1.f, 1.f);
		uv[11] = UV(0.f, 1.f);
		// Side right
		uv[12] = UV(0.f, 0.f);
		uv[13] = UV(1.f, 0.f);
		uv[14] = UV(1.f, 1.f);
		uv[15] = UV(0.f, 1.f);
		// Side back
		uv[16] = UV(0.f, 0.f);
		uv[17] = UV(1.f, 0.f);
		uv[18] = UV(1.f, 1.f);
		uv[19] = UV(0.f, 1.f);
		// Side front
		uv[20] = UV(0.f, 0.f);
		uv[21] = UV(1.f, 0.f);
		uv[22] = UV(1.f, 1.f);
		uv[23] = UV(0.f, 1.f);

		// Define the object
		scene->DefineMesh(meshName, 24, 12, p, vi, NULL, uv, NULL, NULL);
	}

	// Add the object to the scene
	Properties props;
	props.SetFromString(
		"scene.objects." + objName + ".shape = " + meshName + "\n"
		"scene.objects." + objName + ".material = " + matName + "\n"
		);
	scene->Parse(props);
}

Mtl * matPrevNodesEnum(INode * inode)
{
	for (int c = 0; c < inode->NumberOfChildren(); c++)
	{
		Mtl * mat = matPrevNodesEnum(inode->GetChildNode(c));
		if (mat)
		{
			//mprintf(_T("\nMaterial Name: %s\n", mat->GetName()));
			lxmMaterials.exportMaterial(mat, *materialPreviewScene);
			return mat;
		}
	}

	ObjectState ostate = inode->EvalWorldState(0);
	if (ostate.obj->SuperClassID() == GEOMOBJECT_CLASS_ID)
		if (ostate.obj->CanConvertToType(triObjectClassID))
		{
			Object * obj = ostate.obj;
			if (!obj)
				return NULL;
			TriObject * tobj = (TriObject *)obj->ConvertToType(0, triObjectClassID);
			if (!tobj)
				return NULL;
			::Mesh * cmesh = &(tobj->mesh);

			lxmMaterials.exportMaterial(inode->GetMtl(), *materialPreviewScene);
			if (!cmesh)
				return NULL;

			return inode->GetMtl();
		}

	return NULL;
}

::Matrix3 camPos;

int LuxMax::Open(
	INode *scene,     	// root node of scene to render
	INode *vnode,     	// view node (camera or light), or NULL
	ViewParams *viewPar,// view params for rendering ortho or user viewport
	RendParams &rp,  	// common renderer parameters
	HWND hwnd, 				// owner window, for messages
	DefaultLight* defaultLights, // Array of default lights if none in scene
	int numDefLights,	// number of lights in defaultLights array
	RendProgressCallback* prog
	)
{
	UNREFERENCED_PARAMETER(prog);
	UNREFERENCED_PARAMETER(numDefLights);
	UNREFERENCED_PARAMETER(defaultLights);
	UNREFERENCED_PARAMETER(hwnd);

	viewNode = vnode;
	camPos = viewPar->affineTM;

	if (rp.inMtlEdit)
	{
		renderingMaterialPreview = true;
		materialPreviewScene = new Scene();

		lxmMesh.createMesh(scene, *materialPreviewScene);
	}
	else
	{
		renderingMaterialPreview = false;
	}

	return 1;
}

static void DoRendering(RenderSession *session, RendProgressCallback *prog, Bitmap *tobm) {
	const u_int haltTime = session->GetRenderConfig().GetProperties().Get(Property("batch.halttime")(0)).Get<u_int>();
	const u_int haltSpp = session->GetRenderConfig().GetProperties().Get(Property("batch.haltspp")(0)).Get<u_int>();
	const float haltThreshold = session->GetRenderConfig().GetProperties().Get(Property("batch.haltthreshold")(-1.f)).Get<float>();
	const wchar_t *state = NULL;

	char buf[512];
	const Properties &stats = session->GetStats();
	for (;;) {
		boost::this_thread::sleep(boost::posix_time::millisec(1000));

		session->UpdateStats();
		const double elapsedTime = stats.Get("stats.renderengine.time").Get<double>();
		if ((haltTime > 0) && (elapsedTime >= haltTime))
			break;

		const u_int pass = stats.Get("stats.renderengine.pass").Get<u_int>();
		if ((haltSpp > 0) && (pass >= haltSpp))
			break;

		// Convergence test is update inside UpdateFilm()
		const float convergence = stats.Get("stats.renderengine.convergence").Get<u_int>();
		if ((haltThreshold >= 0.f) && (1.f - convergence <= haltThreshold))
			break;

		// Print some information about the rendering progress
		//sprintf(buf, "[Elapsed time: %3d/%dsec][Samples %4d/%d][Convergence %f%%][Avg. samples/sec % 3.2fM on %.1fK tris]",
		//			int(elapsedTime), int(haltTime), pass, haltSpp, 100.f * convergence,
		//		stats.Get("stats.renderengine.total.samplesec").Get<double>() / 1000000.0,
		//	stats.Get("stats.dataset.trianglecount").Get<double>() / 1000.0);
		//mprintf(_T("Elapsed time %i\n"), int(elapsedTime));

		state = (L"Rendering ....");
		prog->SetTitle(state);
		bool renderabort = prog->Progress(elapsedTime + 1, haltTime);
		if (renderabort == false)
			break;
		renderWidth = tobm->Width();
		renderHeight = tobm->Height();
		int pixelArraySize = renderWidth * renderHeight * 3;

		pixels = new float[pixelArraySize]();

		session->GetFilm().GetOutput(session->GetFilm().OUTPUT_RGB_TONEMAPPED, pixels, 0);

		int i = 0;

		BMM_Color_64 col64;
		col64.r = 0;
		col64.g = 0;
		col64.b = 0;
		//fill in the pixels
		for (int w = renderHeight; w > 0; w--)
		{
			for (int h = 0; h < renderWidth; h++)
			{
				col64.r = (WORD)floorf(pixels[i] * 65535.f + .5f);
				col64.g = (WORD)floorf(pixels[i + 1] * 65535.f + .5f);
				col64.b = (WORD)floorf(pixels[i + 2] * 65535.f + .5f);

				tobm->PutPixels(h, w, 1, &col64);

				i += 3;
			}
		}
		tobm->RefreshWindow(NULL);

		SLG_LOG(buf);
	}

	int pixelArraySize = renderWidth * renderHeight * 3;

	pixels = new float[pixelArraySize]();

	session->GetFilm().GetOutput(session->GetFilm().OUTPUT_RGB_TONEMAPPED, pixels, 0);
}

int LuxMax::Render(
	TimeValue t,   			// frame to render.
	Bitmap *tobm, 			// optional target bitmap
	FrameRendParams &frp,	// Time dependent parameters
	HWND hwnd, 				// owner window
	RendProgressCallback *prog,
	ViewParams *vp
	)
{
	UNREFERENCED_PARAMETER(vp);
	UNREFERENCED_PARAMETER(hwnd);
	UNREFERENCED_PARAMETER(frp);
	UNREFERENCED_PARAMETER(t);
	UNREFERENCED_PARAMETER(prog);

	using namespace std;
	using namespace luxrays;
	using namespace luxcore;
	const wchar_t *renderProgTitle = NULL;
	defaultlightset = true;

	//mprintf(_T("\nRendering with Luxcore version: %s,%s \n"), LUXCORE_VERSION_MAJOR, LUXCORE_VERSION_MINOR);

	if (renderingMaterialPreview)
	{
		//Here we create a dummy mesh and dummy material, if we do not do this the renderer crashes.
		//It's very small and should not be visible in the material previews.
		//We also create and assign a dummy material.
		materialPreviewScene->Parse(
			Property("scene.materials.mat_dummy.type")("matte") <<
			Property("scene.materials.mat_dummy.kd")(1.0f, 1.f, 1.f)
			);
		CreateBox(materialPreviewScene, "dummybox", "dummyboxmesh", "mat_dummy", false, BBox(Point(-.001f, -.001f, .001f), Point(.05f, .05f, 0.07f)));

		defaultlightset = false;
		renderWidth = tobm->Width();
		renderHeight = tobm->Height();

		float previewCameraDistance = 6 / lxmUtils.GetMeterMult();

		materialPreviewScene->Parse(
			Property("scene.camera.lookat.orig")(previewCameraDistance, previewCameraDistance, previewCameraDistance) <<
			Property("scene.camera.lookat.target")(0.f, 0.f, 0.f) <<
			Property("scene.camera.fieldofview")(60.f)
			);

		//Instead of the preview sky light, we should fetch max's internal lights for material previews.
		lxmLights.exportDefaultSkyLight(materialPreviewScene);

		RenderConfig *config = new RenderConfig(
			Property("renderengine.type")("PATHCPU") <<
			Property("sampler.type")("SOBOL") <<
			Property("opencl.platform.index")(-1) <<
			Property("opencl.cpu.use")(true) <<
			Property("opencl.gpu.use")(true) <<
			Property("batch.halttime")(3) <<
			Property("film.outputs.1.type")("RGBA_TONEMAPPED") <<
			Property("film.outputs.1.filename")("tmp.png") <<
			Property("film.imagepipeline.0.type")("TONEMAP_AUTOLINEAR") <<
			Property("film.imagepipeline.1.type")("GAMMA_CORRECTION") <<
			Property("film.height")(renderHeight) <<
			Property("film.width")(renderWidth) <<
			Property("film.imagepipeline.1.value")(1.0f),
			materialPreviewScene);
		RenderSession *session = new RenderSession(config);

		session->Start();

		DoRendering(session, prog, tobm);
		session->Stop();

		int i = 0;

		BMM_Color_64 col64;
		col64.r = 0;
		col64.g = 0;
		col64.b = 0;
		//fill in the pixels
		for (int w = renderHeight; w > 0; w--)
		{
			for (int h = 0; h < renderWidth; h++)
			{
				col64.r = (WORD)floorf(pixels[i] * 65535.f + .5f);
				col64.g = (WORD)floorf(pixels[i + 1] * 65535.f + .5f);
				col64.b = (WORD)floorf(pixels[i + 2] * 65535.f + .5f);

				tobm->PutPixels(h, w, 1, &col64);

				i += 3;
			}
		}
		tobm->RefreshWindow(NULL);

		pixels = NULL;
		delete session;
		delete config;
		delete materialPreviewScene;

		SLG_LOG("Done.");

		return 1;
	}
	else

	{
		Scene *scene = new Scene();
		//In the camera 'export' function we check for supported camera, it returns false if something is not right.
		if (!lxmCamera.exportCamera((float)_wtof(LensRadiusstr), *scene))
		{
			return false;
		}

		//Export all meshes
		INode* maxscene = GetCOREInterface7()->GetRootNode();
		for (int a = 0; maxscene->NumChildren() > a; a++)
		{
			INode* currNode = maxscene->GetChildNode(a);

			//prog->SetCurField(1);
			renderProgTitle = (L"Translating object: %s", currNode->GetName());
			prog->SetTitle(renderProgTitle);
			//	mprintf(_T("\n Total Rendering elements number: %i"), maxscene->NumChildren());
			//		mprintf(_T("   ::   Current elements number: %i \n"), a + 1);
			prog->Progress(a + 1, maxscene->NumChildren());

			Object*	obj;
			ObjectState os = currNode->EvalWorldState(GetCOREInterface()->GetTime());
			obj = os.obj;
			bool doExport = true;

			switch (os.obj->SuperClassID())
			{
			case HELPER_CLASS_ID:
			{
				doExport = false;

				//If the helper is a group header we loop through and export all objects inside the group.
				if (currNode->IsGroupHead())
				{
					lxmMesh.createMeshesInGroup(currNode, *scene);
				}
				break;
			}

			case LIGHT_CLASS_ID:
			{
				//Properties props;
				std::string objString;
				bool lightsupport = false;

				if (defaultlightchk == true)
				{
					if (defaultlightauto == true)
					{
						defaultlightset = false;
					}
				}
				else
				{
					defaultlightset = false;
					mprintf(_T("\n Default Light Deactive Automaticlly %i \n"));
				}

				if (os.obj->ClassID() == OMNI_CLASSID)
				{
					scene->Parse(lxmLights.exportOmni(currNode));
					lightsupport = true;
				}
				if (os.obj->ClassID() == SPOTLIGHT_CLASSID)
				{
					scene->Parse(lxmLights.exportSpotLight(currNode));
					lightsupport = true;
				}
				if (os.obj->ClassID() == SKYLIGHT_CLASSID)
				{
					scene->Parse(lxmLights.exportSkyLight(currNode));
					lightsupport = true;
				}
				if (os.obj->ClassID() == DIRLIGHT_CLASSID)
				{
					scene->Parse(lxmLights.exportDiright(currNode));
					lightsupport = true;
				}
				if (lightsupport == false)
				{
					if (defaultlightchk == true)
					{
						mprintf(_T("\n There is No Suported light in scene %i \n"));
						defaultlightset = true;
					}
				}

				break;
			}

			/*case CAMERA_CLASS_ID:
			{
			break;
			}*/

			case GEOMOBJECT_CLASS_ID:
			{
				if (doExport)
				{
					lxmMesh.createMesh(currNode, *scene);
				}

				break;
			}
			}
		}

		if (defaultlightchk == true)
		{
			if (defaultlightset == true)
			{
				lxmLights.exportDefaultSkyLight(scene);
			}
		}

		std::string tmpFilename = FileName.ToCStr();
		int halttime = (int)_wtof(halttimewstr);

		if (tmpFilename != NULL)
		{
			mprintf(_T("\nRendering to: %s \n"), FileName.ToMSTR());
		}

		renderWidth = GetCOREInterface11()->GetRendWidth();
		renderHeight = GetCOREInterface11()->GetRendHeight();

		string tmprendtype = "PATHCPU";
		rendertype = renderType;

		switch (rendertype)
		{
		case 0:
			tmprendtype = "BIASPATHCPU";
			break;
		case 1:
			tmprendtype = "BIASPATHOCL";
			break;
		case 2:
			tmprendtype = "BIDIRCPU";
			break;
		case 3:
			tmprendtype = "BIDIRVMCPU";
			break;
		case 4:
			tmprendtype = "PATHCPU";
			break;
		case 5:
			tmprendtype = "PATHOCL";
			break;
		case 6:
			tmprendtype = "RTBIASPATHOCL";
			break;
		case 7:
			tmprendtype = "RTPATHOCL";
			break;
		}
		mprintf(_T("\n Renderengine type is %i \n"), rendertype);

		RenderConfig *config = new RenderConfig(
			//filesaver
			//Property("renderengine.type")("FILESAVER") <<
			//Property("filesaver.directory")("C:/tmp/filesaveroutput/") <<
			//Property("filesaver.renderengine.type")("engine") <<
			//Filesaver

			Property("renderengine.type")(tmprendtype) <<
			Property("sampler.type")("SOBOL") <<
			//Property("sampler.type")("METROPOLIS") <<
			Property("opencl.platform.index")(-1) <<
			Property("opencl.cpu.use")(true) <<
			Property("opencl.gpu.use")(true) <<
			Property("batch.halttime")(halttime) <<
			Property("film.outputs.1.type")("RGBA_TONEMAPPED") <<
			Property("film.outputs.1.filename")(tmpFilename) <<
			Property("film.imagepipeline.0.type")("TONEMAP_AUTOLINEAR") <<
			Property("film.imagepipeline.1.type")("GAMMA_CORRECTION") <<
			Property("film.height")(renderHeight) <<
			Property("film.width")(renderWidth) <<
			Property("film.imagepipeline.1.value")(1.0f),
			scene);
		RenderSession *session = new RenderSession(config);

		session->Start();

		//We need to stop the rendering immidiately if debug output is selsected.

		DoRendering(session, prog, tobm);
		session->Stop();

		int i = 0;

		BMM_Color_64 col64;
		col64.r = 0;
		col64.g = 0;
		col64.b = 0;
		//fill in the pixels
		for (int w = renderHeight; w > 0; w--)
		{
			for (int h = 0; h < renderWidth; h++)
			{
				col64.r = (WORD)floorf(pixels[i] * 65535.f + .5f);
				col64.g = (WORD)floorf(pixels[i + 1] * 65535.f + .5f);
				col64.b = (WORD)floorf(pixels[i + 2] * 65535.f + .5f);

				tobm->PutPixels(h, w, 1, &col64);

				i += 3;
			}
		}
		tobm->RefreshWindow(NULL);

		pixels = NULL;
		delete session;
		delete config;
		delete scene;

		SLG_LOG("Done.");

		return 1;
	}
}

void LuxMax::Close(HWND hwnd, RendProgressCallback* prog) {
	UNREFERENCED_PARAMETER(prog);
	UNREFERENCED_PARAMETER(hwnd);
	if (file)
		delete file;
	file = NULL;
}

RefTargetHandle LuxMax::Clone(RemapDir &remap) {
	LuxMax *newRend = new LuxMax;
	newRend->FileName = FileName;
	BaseClone(this, newRend, remap);
	return newRend;
}

void LuxMax::ResetParams(){
	FileName.Resize(0);
}

#define FILENAME_CHUNKID 001
#define HALTTIME_CHUNKID 002
#define LENSRADIUS_CHUNKID 003

IOResult LuxMax::Save(ISave *isave) {
	if (_tcslen(FileName) > 0) {
		isave->BeginChunk(FILENAME_CHUNKID);
		isave->WriteWString(FileName);
		isave->EndChunk();
	}

	isave->BeginChunk(HALTTIME_CHUNKID);
	isave->WriteWString(halttimewstr);
	isave->EndChunk();
	isave->BeginChunk(LENSRADIUS_CHUNKID);
	isave->WriteWString(LensRadiusstr);
	isave->EndChunk();
	return IO_OK;
}

IOResult LuxMax::Load(ILoad *iload) {
	int id;
	TCHAR *buf;
	IOResult res;
	while (IO_OK == (res = iload->OpenChunk())) {
		switch (id = iload->CurChunkID())  {
		case FILENAME_CHUNKID:
			if (IO_OK == iload->ReadWStringChunk(&buf))
				FileName = buf;
			break;
		case HALTTIME_CHUNKID:
			if (IO_OK == iload->ReadWStringChunk(&buf))
				halttimewstr = buf;
			break;
		case LENSRADIUS_CHUNKID:
			if (IO_OK == iload->ReadWStringChunk(&buf))
				halttimewstr = buf;
			break;
		}
		iload->CloseChunk();
		if (res != IO_OK)
			return res;
	}
	return IO_OK;
}

//***************************************************************************
// Initialize our custom options.
//***************************************************************************

LuxRenderParams::LuxRenderParams()
{
	//SetDefaults();

	/*envMap = NULL;
	atmos = NULL;
	rendType = RENDTYPE_NORMAL;
	nMinx = 0;
	nMiny = 0;
	nMaxx = 0;
	nMaxy = 0;
	nNumDefLights = 0;
	nRegxmin = 0;
	nRegxmax = 0;
	nRegymin = 0;
	nRegymax = 0;
	//scrDUV = Point2(0.0f, 0.0f);
	//pDefaultLights = NULL;
	//pFrp = NULL;
	bVideoColorCheck = 0;
	bForce2Sided = FALSE;
	bRenderHidden = FALSE;
	bSuperBlack = FALSE;
	bRenderFields = FALSE;
	bNetRender = FALSE;

	renderer = NULL;
	projType = PROJ_PERSPECTIVE;
	devWidth = 0;
	devHeight = 0;
	xscale = 0;
	yscale = 0;
	xc = 0;
	yc = 0;
	antialias = FALSE;
	nearRange = 0;
	farRange = 0;
	devAspect = 0;
	frameDur = 0;
	time = 0;
	wireMode = FALSE;
	inMtlEdit = FALSE;
	fieldRender = FALSE;
	first_field = FALSE;
	field_order = FALSE;
	objMotBlur = FALSE;
	nBlurFrames = 0;*/
}

void LuxRenderParams::SetDefaults()
{
	nMaxDepth = 0;
	//nAntiAliasLevel = 0x00;
	//bReflectEnv = FALSE;
}
