// ======================================================================== //
// Copyright 2009-2015 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#ifndef __RTCORE_BVH_BUILDER_H__
#define __RTCORE_BVH_BUILDER_H__

/*! \brief Defines an opaque memory allocator type */
typedef struct __RTCAllocator {}* RTCAllocator;
/*! \brief Defines an opaque memory thread local allocator type */
typedef struct __RTCThreadLocalAllocator {}* RTCThreadLocalAllocator;

RTCORE_API RTCAllocator rtcNewAllocator();
RTCORE_API void rtcDeleteAllocator(RTCAllocator allocator);
RTCORE_API void rtcResetAllocator(RTCAllocator allocator);
RTCORE_API RTCThreadLocalAllocator rtcNewThreadAllocator(RTCAllocator allocator);
RTCORE_API void *rtcThreadAlloc(RTCThreadLocalAllocator allocator, const size_t size);

struct RTCBVHBuilderConfig
{
	size_t branchingFactor, maxDepth, blockSize, minLeafSize, maxLeafSize;
	float travCost, intCost;
};

RTCORE_API void rtcDefaultBVHBuilderConfig(RTCBVHBuilderConfig *config);

/*! Axis aligned bounding box representation plus geomID and primID */
struct RTCORE_ALIGN(32) RTCPrimRef
{
	float lower_x, lower_y, lower_z;
	int geomID;
	float upper_x, upper_y, upper_z;
	int primID;
};

typedef void *(*rtcBVHBuilderCreateLocalThreadDataFunc)(void *userGlobalData);
typedef void *(*rtcBVHBuilderCreateNodeFunc)(void *userLocalThreadData);
typedef void *(*rtcBVHBuilderCreateLeafFunc)(void *userLocalThreadData, int geomID, int primID, const float lower[3], const float upper[3]);
typedef void *(*rtcBVHBuilderGetNodeChildrenPtrFunc)(void *node, const size_t i);
typedef void (*rtcBVHBuilderGetNodeChildrenBBoxFunc)(void *node, const size_t i,
		const float lower[3], const float upper[3]);

RTCORE_API void *rtcBVHBuilderBinnedSAH(const RTCBVHBuilderConfig *config, const RTCPrimRef *prims, const size_t primRefsSize, void *userData,
		rtcBVHBuilderCreateLocalThreadDataFunc createLocalThreadDataFunc,
		rtcBVHBuilderCreateNodeFunc createNodeFunc,
		rtcBVHBuilderCreateLeafFunc createLeafFunc,
		rtcBVHBuilderGetNodeChildrenPtrFunc getNodeChildrenPtrFunc,
		rtcBVHBuilderGetNodeChildrenBBoxFunc getNodeChildrenBBoxFunc);

RTCORE_API void *rtcBVHBuilderMorton(const RTCBVHBuilderConfig *config, const RTCPrimRef *prims, const size_t primRefsSize, void *userData,
		rtcBVHBuilderCreateLocalThreadDataFunc createLocalThreadDataFunc,
		rtcBVHBuilderCreateNodeFunc createNodeFunc,
		rtcBVHBuilderCreateLeafFunc createLeafFunc,
		rtcBVHBuilderGetNodeChildrenPtrFunc getNodeChildrenPtrFunc,
		rtcBVHBuilderGetNodeChildrenBBoxFunc getNodeChildrenBBoxFunc);

#endif
