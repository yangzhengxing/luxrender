#include <string> 
namespace slg { namespace ocl { 
std::string KernelSource_texture_abs_funcs = 
"#line 2 \"texture_abs_funcs.cl\"\n" 
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
"//------------------------------------------------------------------------------\n" 
"// Abs texture\n" 
"//------------------------------------------------------------------------------\n" 
"#if defined(PARAM_ENABLE_TEX_ABS)\n" 
"float AbsTexture_ConstEvaluateFloat(__global HitPoint *hitPoint,\n" 
"const float v) {\n" 
"return fabs(v);\n" 
"}\n" 
"float3 AbsTexture_ConstEvaluateSpectrum(__global HitPoint *hitPoint,\n" 
"const float3 v) {\n" 
"return fabs(v);\n" 
"}\n" 
"#endif\n" 
; } } 