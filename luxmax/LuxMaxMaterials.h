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

#pragma once
#include <algorithm>
using std::max;
using std::min;
#include <maxapi.h>

#include <luxcore/luxcore.h>


class LuxMaxMaterials
{
public:
	LuxMaxMaterials();
	~LuxMaxMaterials();
	void exportMaterial(Mtl* mat, luxcore::Scene &scene);
	//void exportMaterial(Mtl* mat, luxcore::Scene &scene);
	std::string LuxMaxMaterials::getMaterialDiffuseTexturePath(::Mtl* mat);
	std::string LuxMaxMaterials::getMaterialBumpTexturePath(::Mtl* mat);
	std::string getTextureName(int paramID, ::Mtl* mat);
	std::string getBumpTextureName(::Mtl* mat);
	std::string getDiffuseTextureName(::Mtl* mat);

	//void LuxMaxMaterials::defineTexture(BitmapTex* bmTex, luxcore::Scene &scene, std::string textureName);
	Point3 getMaterialDiffuseColor(::Mtl* mat);
	bool isSupportedMaterial(::Mtl* mat);
	std::string getTexturePathFromParamBlockID(int id, ::Mtl* mat);
	
};

