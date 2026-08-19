/**
 * @file ucc_version.h
 * @date 2020
 * @copyright (c) 2020, NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 *
 * See file LICENSE for terms.
 */

#define UCC_VERSION(_major, _minor) \
	(((_major) << UCC_VERSION_MAJOR_SHIFT) | \
	 ((_minor) << UCC_VERSION_MINOR_SHIFT))
#define UCC_VERSION_MAJOR_SHIFT    24
#define UCC_VERSION_MINOR_SHIFT    16

#define UCC_API_MAJOR      1
#define UCC_API_MINOR      8
#define UCC_API_VERSION    UCC_VERSION(1, 8)
#define UCC_VERSION_STRING "1.8.0"
#define UCC_GIT_REVISION   "211e2f6"
