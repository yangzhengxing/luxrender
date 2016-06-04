#include <string> 
namespace slg { namespace ocl { 
std::string KernelSource_materialdefs_funcs_roughmatte_translucent = 
"#line 2 \"materialdefs_funcs_roughmatte_translucent.cl\"\n" 
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
"// MatteTranslucent material\n" 
"//------------------------------------------------------------------------------\n" 
"#if defined (PARAM_ENABLE_MAT_ROUGHMATTETRANSLUCENT)\n" 
"BSDFEvent RoughMatteTranslucentMaterial_GetEventTypes() {\n" 
"return DIFFUSE | REFLECT | TRANSMIT;\n" 
"}\n" 
"float3 RoughMatteTranslucentMaterial_Evaluate(\n" 
"__global HitPoint *hitPoint, const float3 lightDir, const float3 eyeDir,\n" 
"BSDFEvent *event, float *directPdfW,\n" 
"const float3 krVal, const float3 ktVal, const float sigma) {\n" 
"const float3 r = Spectrum_Clamp(krVal);\n" 
"const float3 t = Spectrum_Clamp(ktVal) * \n" 
"// Energy conservation\n" 
"(1.f - r);\n" 
"const bool isKtBlack = Spectrum_IsBlack(t);\n" 
"const bool isKrBlack = Spectrum_IsBlack(r);\n" 
"// Decide to transmit or reflect\n" 
"float threshold;\n" 
"if (!isKrBlack) {\n" 
"if (!isKtBlack)\n" 
"threshold = .5f;\n" 
"else\n" 
"threshold = 1.f;\n" 
"} else {\n" 
"if (!isKtBlack)\n" 
"threshold = 0.f;\n" 
"else {\n" 
"if (directPdfW)\n" 
"*directPdfW = 0.f;\n" 
"return BLACK;\n" 
"}\n" 
"}\n" 
"const bool relfected = (CosTheta(lightDir) * CosTheta(eyeDir) > 0.f);\n" 
"const float weight = (lightDir.z * eyeDir.z > 0.f) ? threshold : (1.f - threshold);\n" 
"if (directPdfW)\n" 
"*directPdfW = weight * fabs(lightDir.z * M_1_PI_F);\n" 
"const float sigma2 = sigma * sigma;\n" 
"const float A = 1.f - (sigma2 / (2.f * (sigma2 + 0.33f)));\n" 
"const float B = 0.45f * sigma2 / (sigma2 + 0.09f);\n" 
"const float sinthetai = SinTheta(eyeDir);\n" 
"const float sinthetao = SinTheta(lightDir);\n" 
"float maxcos = 0.f;\n" 
"if (sinthetai > 1e-4f && sinthetao > 1e-4f) {\n" 
"const float dcos = CosPhi(lightDir) * CosPhi(eyeDir) +\n" 
"SinPhi(lightDir) * SinPhi(eyeDir);\n" 
"maxcos = fmax(0.f, dcos);\n" 
"}\n" 
"const float3 result = (M_1_PI_F * fabs(lightDir.z) *\n" 
"(A + B * maxcos * sinthetai * sinthetao / fmax(fabs(CosTheta(lightDir)), fabs(CosTheta(eyeDir)))));\n" 
"if (lightDir.z * eyeDir.z > 0.f) {\n" 
"*event = DIFFUSE | REFLECT;\n" 
"return r * result;\n" 
"} else {\n" 
"*event = DIFFUSE | TRANSMIT;\n" 
"return t * result;\n" 
"}\n" 
"}\n" 
"float3 RoughMatteTranslucentMaterial_Sample(\n" 
"__global HitPoint *hitPoint, const float3 fixedDir, float3 *sampledDir,\n" 
"const float u0, const float u1,\n" 
"#if defined(PARAM_HAS_PASSTHROUGH)\n" 
"const float passThroughEvent,\n" 
"#endif\n" 
"float *pdfW, float *cosSampledDir, BSDFEvent *event,\n" 
"const BSDFEvent requestedEvent,\n" 
"const float3 krVal, const float3 ktVal, const float sigma) {\n" 
"if (!(requestedEvent & (DIFFUSE | REFLECT | TRANSMIT)) ||\n" 
"(fabs(fixedDir.z) < DEFAULT_COS_EPSILON_STATIC))\n" 
"return BLACK;\n" 
"*sampledDir = CosineSampleHemisphereWithPdf(u0, u1, pdfW);\n" 
"*cosSampledDir = fabs((*sampledDir).z);\n" 
"if (*cosSampledDir < DEFAULT_COS_EPSILON_STATIC)\n" 
"return BLACK;\n" 
"const float3 kr = Spectrum_Clamp(krVal);\n" 
"const float3 kt = Spectrum_Clamp(ktVal) * \n" 
"// Energy conservation\n" 
"(1.f - kr);\n" 
"const bool isKtBlack = Spectrum_IsBlack(kt);\n" 
"const bool isKrBlack = Spectrum_IsBlack(kr);\n" 
"if (isKtBlack && isKrBlack)\n" 
"return BLACK;\n" 
"// Decide to transmit or reflect\n" 
"float threshold;\n" 
"if ((requestedEvent & REFLECT) && !isKrBlack) {\n" 
"if ((requestedEvent & TRANSMIT) && !isKtBlack)\n" 
"threshold = .5f;\n" 
"else\n" 
"threshold = 1.f;\n" 
"} else {\n" 
"if ((requestedEvent & TRANSMIT) && !isKtBlack)\n" 
"threshold = 0.f;\n" 
"else\n" 
"return BLACK;\n" 
"}\n" 
"const float sigma2 = sigma * sigma;\n" 
"const float A = 1.f - (sigma2 / (2.f * (sigma2 + 0.33f)));\n" 
"const float B = 0.45f * sigma2 / (sigma2 + 0.09f);\n" 
"const float sinthetai = SinTheta(fixedDir);\n" 
"const float sinthetao = SinTheta(*sampledDir);\n" 
"float maxcos = 0.f;\n" 
"if (sinthetai > 1e-4f && sinthetao > 1e-4f) {\n" 
"const float dcos = CosPhi(*sampledDir) * CosPhi(fixedDir) +\n" 
"SinPhi(*sampledDir) * SinPhi(fixedDir);\n" 
"maxcos = max(0.f, dcos);\n" 
"}\n" 
"const float coef = (A + B * maxcos * sinthetai * sinthetao / max(fabs(CosTheta(*sampledDir)), fabs(CosTheta(fixedDir))));\n" 
"if (passThroughEvent < threshold) {\n" 
"*sampledDir *= (signbit(fixedDir.z) ? -1.f : 1.f);\n" 
"*event = DIFFUSE | REFLECT;\n" 
"*pdfW *= threshold;\n" 
"return kr * (coef / threshold);\n" 
"} else {\n" 
"*sampledDir *= -(signbit(fixedDir.z) ? -1.f : 1.f);\n" 
"*event = DIFFUSE | TRANSMIT;\n" 
"*pdfW *= (1.f - threshold);\n" 
"return kt * (coef / (1.f - threshold));\n" 
"}\n" 
"}\n" 
"#endif\n" 
; } } 