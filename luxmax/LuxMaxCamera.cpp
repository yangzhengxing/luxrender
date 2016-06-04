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
#include "LuxMaxCamera.h"
#include <algorithm>
#include "max.h"
#include "LuxMaxUtils.h"
#include <stdio.h>
#include <string>
#include <maxapi.h>
#include <iparamb2.h>
#include <iparamb.h>
#include <boost/filesystem/operations.hpp>
#include <boost/foreach.hpp>
#include <boost/assign.hpp>
#include <boost/format.hpp>
#include <maxscript\maxscript.h>
#include <Scene/IPhysicalCamera.h>
#include <luxcore/luxcore.h>
#include <luxrays\luxrays.h>

#define CAMERAHELPER_CLASSID Class_ID(4128,0)
#define MAX2016_PHYSICAL_CAMERA Class_ID(1181315608,686293133)

using namespace std;
using namespace MaxSDK;
using namespace luxcore;
using namespace luxrays;

LuxMaxCamera::LuxMaxCamera()
{
}

LuxMaxCamera::~LuxMaxCamera()
{
}

bool LuxMaxCamera::exportCamera(float lensRadius, luxcore::Scene &scene)
{
	INode* camNode = GetCOREInterface9()->GetActiveViewExp().GetViewCamera();

	if (camNode == NULL)
	{
		MessageBox(0, L"Set active view to a target camera and render again.", L"Error!", MB_OK);
		return false;
	}
	else
	{
		CameraObject*   cameraPtr = (CameraObject *)camNode->EvalWorldState(GetCOREInterface()->GetTime()).obj;

		float v = 0.0f;
		float FOV = 0;
		float focaldistance = 0;
		Interval      ivalid = FOREVER;
		IParamBlock2 *pBlock = camNode->GetParamBlock(0);
		IParamBlock2* pblock2;

		if (v > 0.0f)
		{
			MessageBox(0, L"LuxCam modifier selected.", L"Error!", MB_OK);
			return false;
		}

		if (cameraPtr->ClassID() == MAX2016_PHYSICAL_CAMERA)
		{
			IPhysicalCamera* physicalCamera = dynamic_cast<IPhysicalCamera*>(camNode->EvalWorldState(GetCOREInterface()->GetTime()).obj);

			FOV = physicalCamera->GetFOV(GetCOREInterface()->GetTime(), FOREVER) * 180 / PI;
			focaldistance = physicalCamera->GetTDist(GetCOREInterface()->GetTime(), FOREVER);
		}
		else
		{
			FOV = cameraPtr->GetFOV(GetCOREInterface()->GetTime(), FOREVER) * 180 / PI;
			focaldistance = cameraPtr->GetTDist(GetCOREInterface()->GetTime(), FOREVER);
		}

		::Point3 camTrans = camNode->GetNodeTM(GetCOREInterface()->GetTime()).GetTrans();
		INode* NewCam = camNode;
		::Matrix3 targetPos;
		NewCam->GetTargetTM(GetCOREInterface()->GetTime(), targetPos);

		float aspectratio = GetCOREInterface11()->GetImageAspRatio();
		if (aspectratio < 1)
			FOV = 2.0f * ((180 / PI) *(atan(tan((PI / 180)*(FOV / 2.0f)) / aspectratio)));

		mprintf(L"Rendering with camera: : %s\n", camNode->GetName());
		scene.Parse(
			Property("scene.camera.lookat.orig")(camTrans.x, camTrans.y, camTrans.z) <<
			Property("scene.camera.lookat.target")(targetPos.GetTrans().x, targetPos.GetTrans().y, targetPos.GetTrans().z) <<
			Property("scene.camera.fieldofview")(FOV) <<
			Property("scene.camera.lensradius")(lensRadius) <<
			//Property("scene.camera.focaldistance")(cameraPtr->GetTDist(GetCOREInterface()->GetTime(), FOREVER)) <<
			Property("scene.camera.focaldistance")(focaldistance) <<
			Property("scene.camera.shutteropen")(0.0f) <<
			Property("scene.camera.shutterclose")(1.615f)
			);
		return true;
	}

	
}