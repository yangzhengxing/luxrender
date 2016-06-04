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
#include <string>
class LuxMaxUtils
{
public:
	LuxMaxUtils();
	~LuxMaxUtils();
	
	std::string ToNarrow(const wchar_t *s, char dfault = '?',
		const std::locale& loc = std::locale());

	std::string removeUnwatedChars(std::string& str);
	bool replace(std::string& str, const std::string& from, const std::string& to);
	::std::string getstring(const wchar_t* wstr);
	std::string ReplaceAll(std::string str, const std::string& from, const std::string& to);
	std::string floatToString(float number);
	std::string getMaxNodeTransform(INode* node);
	float GetMeterMult();
	//luxrays::Properties getNodeTransform(INode* node);
	
};

