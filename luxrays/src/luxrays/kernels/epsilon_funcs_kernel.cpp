#include <string> 
namespace luxrays { namespace ocl { 
std::string KernelSource_epsilon_funcs = 
"#line 2 \"epsilon_funcs.cl\"\n" 
"/***************************************************************************\n" 
"* Copyright 1998-2015 by authors (see AUTHORS.txt)                        *\n" 
"*                                                                         *\n" 
"*   This file is part of LuxRender.                                       *\n" 
"*                                                                         *\n" 
"* Licensed under the Apache License, Version 2.0 (the \"License\");         *\n" 
"* you may not use this file except in compliance with the License.        *\n" 
"* You may obtain a copy of the License at                                 *\n" 
"*                                                                         *\n" 
"*     http://www.apache.org/licenses/LICENSE-2.0                          *\n" 
"*                                                                         *\n" 
"* Unless required by applicable law or agreed to in writing, software     *\n" 
"* distributed under the License is distributed on an \"AS IS\" BASIS,       *\n" 
"* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*\n" 
"* See the License for the specific language governing permissions and     *\n" 
"* limitations under the License.                                          *\n" 
"***************************************************************************/\n" 
"float MachineEpsilon_FloatAdvance(const float value) {\n" 
"return as_float(as_uint(value) + DEFAULT_EPSILON_DISTANCE_FROM_VALUE);\n" 
"}\n" 
"float MachineEpsilon_E(const float value) {\n" 
"const float epsilon = fabs(MachineEpsilon_FloatAdvance(value) - value);\n" 
"return clamp(epsilon, PARAM_RAY_EPSILON_MIN, PARAM_RAY_EPSILON_MAX);\n" 
"}\n" 
"float MachineEpsilon_E_Float3(const float3 v) {\n" 
"return fmax(MachineEpsilon_E(v.x), fmax(MachineEpsilon_E(v.y), MachineEpsilon_E(v.z)));\n" 
"}\n" 
; } } 