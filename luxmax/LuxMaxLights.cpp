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

#include <algorithm>
using std::max;
using std::min;

#include "max.h"
#include "LuxMaxLights.h"
#include "LuxMaxUtils.h"
#include <stdio.h>
#include <string>
#include <maxapi.h>
#include "imtl.h"
#include "imaterial.h"
#include <imaterial.h>
#include <iparamb2.h>
#include <iparamb.h>

#include <boost/filesystem/operations.hpp>
#include <boost/foreach.hpp>
#include <boost/assign.hpp>
#include <boost/format.hpp>

#include <maxscript\maxscript.h>
#include "LuxMaxMaterials.h"
#include "LuxMaxUtils.h"
#include <luxcore/luxcore.h>
#include <luxrays\luxrays.h>

LuxMaxUtils lmutil;

LuxMaxLights::LuxMaxLights()
{
}


LuxMaxLights::~LuxMaxLights()
{
}

luxrays::Properties LuxMaxLights::exportOmni(INode* Omni)
{
	::Point3 trans = Omni->GetNodeTM(GetCOREInterface11()->GetTime()).GetTrans();
	::Point3 color;

	luxrays::Properties props;
	std::string objString;

	ObjectState ostate = Omni->EvalWorldState(GetCOREInterface()->GetTime());
	LightObject *light = (LightObject*)ostate.obj;
	color = light->GetRGBColor(GetCOREInterface()->GetTime(), FOREVER);
	float intensityval = light->GetIntensity(GetCOREInterface()->GetTime(), FOREVER);
	
	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(Omni->GetName()));
	objString.append(".type = point");
	objString.append("\n");

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(Omni->GetName()));
	objString.append(".position = ");
	objString.append(std::to_string(trans.x) + " " + std::to_string(trans.y) + " " + std::to_string(trans.z));
	objString.append("\n");

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(Omni->GetName()));
	objString.append(".color = ");
	objString.append(std::to_string(color.x / 255) + " " + std::to_string(color.y / 255) + " " + std::to_string(color.z / 255));
	objString.append("\n");

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(Omni->GetName()));
	objString.append(".power = ");
	objString.append(std::to_string(intensityval));
	objString.append("\n");

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(Omni->GetName()));
	objString.append(".efficency = ");
	objString.append(std::to_string(intensityval));
	objString.append("\n");

	props.SetFromString(objString);
	objString = "";
	return props;
}

luxrays::Properties LuxMaxLights::exportSkyLight(INode* SkyLight)
{
	luxrays::Properties props;
	std::string objString;
	::Point3 trans = SkyLight->GetNodeTM(GetCOREInterface11()->GetTime()).GetTrans();
	::Point3 color;

	ObjectState os = SkyLight->EvalWorldState(GetCOREInterface()->GetTime());
	LightObject *light = (LightObject*)os.obj;

	color = light->GetRGBColor(GetCOREInterface()->GetTime(), FOREVER);
	float ColorIntensValue = 0.0f;
	ColorIntensValue = light->GetIntensity(GetCOREInterface()->GetTime(), FOREVER);

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(SkyLight->GetName()));
	objString.append(".type = sky");
	objString.append("\n");

	// direction of sky light must be static as regular 3dsmax sky light, like an ambient light
	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(SkyLight->GetName()));
	objString.append(".dir = 0.166974 -0.59908 0.783085");
	objString.append("\n");

	/*
	objString.append("scene.lights.");
	objString.append(ToNarrow(SkyLight->GetName()));
	objString.append(".turbidity = ");
	objString.append(::to_string(2.2));
	objString.append("\n");
	*/
	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(SkyLight->GetName()));
	objString.append(".gain = ");
	objString.append(std::to_string(color.x / 255) + " " + std::to_string(color.y / 255) + " " + std::to_string(color.z / 255));
	objString.append("\n");

	props.SetFromString(objString);

	objString = "";
	return props;
}

void LuxMaxLights::exportDefaultSkyLight(luxcore::Scene *scene)
{
	scene->Parse(
		luxrays::Property("scene.lights.skyl.type")("sky") <<
		luxrays::Property("scene.lights.skyl.dir")(0.166974f, 0.59908f, 0.783085f) <<
		luxrays::Property("scene.lights.skyl.turbidity")(2.2f) <<
		luxrays::Property("scene.lights.skyl.gain")(1.0f, 1.0f, 1.0f)
		);
}

luxrays::Properties LuxMaxLights::exportDiright(INode* DirLight)
{
	luxrays::Properties props;
	std::string objString;
	::Point3 trans = DirLight->GetNodeTM(GetCOREInterface11()->GetTime()).GetTrans();
	::Matrix3 targetPos;

	ObjectState os = DirLight->EvalWorldState(GetCOREInterface()->GetTime());
	LightObject *light = (LightObject*)os.obj;

	::Point3 color;
	color = light->GetRGBColor(GetCOREInterface()->GetTime(), FOREVER);
	//float gainval = light->GetIntensity(GetCOREInterface()->GetTime(), FOREVER);
	//float intensityval = light->GetIntensity(GetCOREInterface()->GetTime(), FOREVER);

	DirLight->GetTargetTM(GetCOREInterface11()->GetTime(), targetPos);
	trans = DirLight->GetNodeTM(GetCOREInterface11()->GetTime(), 0).GetTrans();

	//color = light->GetRGBColor(GetCOREInterface()->GetTime(), FOREVER);
	//float ColorIntensValue = light->GetIntensity(GetCOREInterface()->GetTime(), FOREVER);

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(DirLight->GetName()));
	objString.append(".type = sun");
	objString.append("\n");

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(DirLight->GetName()));
	objString.append(".dir = 0.166974 -0.59908 0.783085");
	objString.append("\n");

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(DirLight->GetName()));
	objString.append(".turbidity = 2.2");
	objString.append("\n");

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(DirLight->GetName()));
	objString.append(".gain = 0.8 0.8 0.8");
	objString.append("\n");

	props.SetFromString(objString);

	objString = "";
	return props;
}

luxrays::Properties LuxMaxLights::exportSpotLight(INode* SpotLight)
{
	luxrays::Properties props;
	std::string objString;
	::Point3 trans = SpotLight->GetNodeTM(GetCOREInterface11()->GetTime()).GetTrans();
	::Matrix3 targetPos;

	ObjectState os = SpotLight->EvalWorldState(GetCOREInterface()->GetTime());
	LightObject *light = (LightObject*)os.obj;

	::Point3 color;
	color = light->GetRGBColor(GetCOREInterface()->GetTime(), FOREVER);
	//float gainval = light->GetIntensity(GetCOREInterface()->GetTime(), FOREVER);
	//float intensityval = light->GetIntensity(GetCOREInterface()->GetTime(), FOREVER);

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(SpotLight->GetName()));
	objString.append(".type = spot");
	objString.append("\n");

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(SpotLight->GetName()));
	objString.append(".position = ");
	objString.append(std::to_string(trans.x) + " " + std::to_string(trans.y) + " " + std::to_string(trans.z));
	objString.append("\n");

	SpotLight->GetTargetTM(GetCOREInterface11()->GetTime(), targetPos);
	trans = SpotLight->GetNodeTM(GetCOREInterface11()->GetTime(), 0).GetTrans();

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(SpotLight->GetName()));
	objString.append(".target = ");
	objString.append(std::to_string(targetPos.GetTrans().x) + " " + std::to_string(targetPos.GetTrans().y) + " " + std::to_string(targetPos.GetTrans().z));
	objString.append("\n");

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(SpotLight->GetName()));
	objString.append(".gain = ");
	objString.append(std::to_string(color.x) + " " + std::to_string(color.y) + " " + std::to_string(color.z));
	objString.append("\n");

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(SpotLight->GetName()));
	objString.append(".coneangle = ");
	objString.append(std::to_string(light->GetHotspot(GetCOREInterface11()->GetTime(), FOREVER)));
	objString.append("\n");

	objString.append("scene.lights.");
	objString.append(lmutil.ToNarrow(SpotLight->GetName()));
	objString.append(".conedeltaangle = ");
	objString.append(std::to_string(light->GetFallsize(GetCOREInterface11()->GetTime(), FOREVER))); //* 180 / 3.14159265));
	objString.append("\n");

	props.SetFromString(objString);
	return props;
}