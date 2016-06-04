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

#include <max.h>
#include "LuxMaxUtils.h"
#include <string>
#include <locale>
#include <sstream>
#include <algorithm>
#include <matrix3.h>
#include <inode.h>

#include <boost/filesystem/operations.hpp>
#include <boost/foreach.hpp>
#include <boost/assign.hpp>
#include <boost/format.hpp>

#include <luxcore/luxcore.h>
#include <luxrays\luxrays.h>



LuxMaxUtils::LuxMaxUtils()
{
}


LuxMaxUtils::~LuxMaxUtils()
{
}

float LuxMaxUtils::GetMeterMult()
{
	int type;
	float scale;
	GetMasterUnitInfo(&type, &scale);
	switch (type)
	{
	case UNITS_INCHES:      return scale*0.0254f;
	case UNITS_FEET:     return scale*0.3048f;
	case UNITS_MILES:    return scale*1609.3f;
	case UNITS_MILLIMETERS: return scale*0.001f;
	case UNITS_CENTIMETERS: return scale*0.01f;
	case UNITS_METERS:      return scale;
	case UNITS_KILOMETERS:  return scale*1000.0f;
	default:          return 0;
	}
}

std::string LuxMaxUtils::ToNarrow(const wchar_t *s, char dfault,
	const std::locale& loc)
{
	std::ostringstream stm;

	while (*s != L'\0') {
		stm << std::use_facet< std::ctype<wchar_t> >(loc).narrow(*s++, dfault);
	}
	return stm.str();
}

bool LuxMaxUtils::replace(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

std::string LuxMaxUtils::floatToString(float number){
	std::ostringstream buff;
	buff << number;
	return buff.str();
}

std::string LuxMaxUtils::ReplaceAll(std::string str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
	return str;
}

::std::string LuxMaxUtils::getstring(const wchar_t* wstr)
{
	std::wstring ws(wstr);
	std::string str(ws.begin(), ws.end());
	return str;
}

std::string LuxMaxUtils::removeUnwatedChars(std::string& str)
{
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	replace(str, "#", "_");
	replace(str, ".", "_");
	replace(str, ",", "_");
	replace(str, """", "_");
	replace(str, "�", "_");
	replace(str, "%25", "_");
	replace(str, "&", "_");
	replace(str, "/", "_");
	replace(str, "(", "_");
	replace(str, ")", "_");
	replace(str, "=", "_");
	replace(str, "?", "_");
	replace(str, "+", "_");
	replace(str, "\\", "_");
	replace(str, "`", "_");
	replace(str, "^", "_");
	replace(str, "�", "_");
	replace(str, "|", "_");
	replace(str, "*", "_");
	replace(str, "'", "_");
	replace(str, ";", "_");
	replace(str, ":", "_");

	return str;
}

std::string LuxMaxUtils::getMaxNodeTransform(INode* node)
{
	LuxMaxUtils *lmutil;
	std::string tmpTrans = "";
	Matrix3 nodeTransformPos = node->GetObjTMAfterWSM(GetCOREInterface()->GetTime());
	Matrix3 nodeTransformRot = nodeTransformPos;
	Matrix3 nodeTransformScale = nodeTransformPos;

	nodeTransformRot.NoTrans();
	nodeTransformScale.NoTrans();
	nodeTransformScale.NoRot();

	nodeTransformRot = nodeTransformRot * nodeTransformScale;

	tmpTrans.append(floatToString(nodeTransformRot.GetColumn(0).x));
	tmpTrans.append(" ");
	tmpTrans.append(floatToString(nodeTransformRot.GetColumn(1).x));
	tmpTrans.append(" ");
	tmpTrans.append(floatToString(nodeTransformRot.GetColumn(2).x));
	tmpTrans.append(" ");
	tmpTrans.append("0 ");

	tmpTrans.append(floatToString(nodeTransformRot.GetColumn(0).y));
	tmpTrans.append(" ");
	tmpTrans.append(floatToString(nodeTransformRot.GetColumn(1).y));
	tmpTrans.append(" ");
	tmpTrans.append(floatToString(nodeTransformRot.GetColumn(2).y));
	tmpTrans.append(" ");
	tmpTrans.append("0 ");

	tmpTrans.append(floatToString(nodeTransformRot.GetColumn(0).z));
	tmpTrans.append(" ");
	tmpTrans.append(floatToString(nodeTransformRot.GetColumn(1).z));
	tmpTrans.append(" ");
	tmpTrans.append(floatToString(nodeTransformRot.GetColumn(2).z));
	tmpTrans.append(" ");
	tmpTrans.append("0 ");

	tmpTrans.append(floatToString(nodeTransformPos.GetTrans().x));
	tmpTrans.append(" ");
	tmpTrans.append(floatToString(nodeTransformPos.GetTrans().y));
	tmpTrans.append(" ");
	tmpTrans.append(floatToString(nodeTransformPos.GetTrans().z));
	tmpTrans.append(" 1.0");

	return tmpTrans;
}

//luxrays::Properties LuxMaxUtils::getNodeTransform(INode* node)
//{
//	/*
//	r = row.x - y - z
//	r00 = row0.x
//	Transformation looks like this:
//	r00 r10 r20 0
//	r01 r11 r21 0
//	r02 r12 r22 0
//	*/
//	std::string objString;
//	luxrays::Properties props;
//
//	//objString = "";
//	objString.append("scene.objects.");
//	objString.append(ToNarrow(node->GetName()));
//	objString.append(".transformation = ");
//
//	std::string tmpTrans = "";
//	Matrix3 nodeTransformPos = node->GetNodeTM(GetCOREInterface()->GetTime());
//	Matrix3 nodeTransformRot = nodeTransformPos;
//	Matrix3 nodeTransformScale = nodeTransformPos;
//
//	nodeTransformRot.NoTrans();
//	nodeTransformScale.NoTrans();
//	nodeTransformScale.NoRot();
//
//	nodeTransformRot = nodeTransformRot * nodeTransformScale;
//
//	objString.append(std::to_string(nodeTransformRot.GetColumn(0).x));
//	objString.append(" ");
//	objString.append(std::to_string(nodeTransformRot.GetColumn(1).x));
//	objString.append(" ");
//	objString.append(std::to_string(nodeTransformRot.GetColumn(2).x));
//	objString.append(" ");
//	objString.append("0 ");
//
//	objString.append(std::to_string(nodeTransformRot.GetColumn(0).y));
//	objString.append(" ");
//	objString.append(std::to_string(nodeTransformRot.GetColumn(1).y));
//	objString.append(" ");
//	objString.append(std::to_string(nodeTransformRot.GetColumn(2).y));
//	objString.append(" ");
//	objString.append("0 ");
//
//	objString.append(std::to_string(nodeTransformRot.GetColumn(0).z));
//	objString.append(" ");
//	objString.append(std::to_string(nodeTransformRot.GetColumn(1).z));
//	objString.append(" ");
//	objString.append(std::to_string(nodeTransformRot.GetColumn(2).z));
//	objString.append(" ");
//	objString.append("0 ");
//
//	objString.append(std::to_string(nodeTransformPos.GetTrans().x));
//	objString.append(" ");
//	objString.append(std::to_string(nodeTransformPos.GetTrans().y));
//	objString.append(" ");
//	objString.append(std::to_string(nodeTransformPos.GetTrans().z));
//	objString.append(" ");
//
//	objString.append(std::to_string(1.0));
//	objString.append("\n");
//
//	props.SetFromString(objString);
//	//scene->Parse(props);
//	objString = "";
//	return props;
//}

