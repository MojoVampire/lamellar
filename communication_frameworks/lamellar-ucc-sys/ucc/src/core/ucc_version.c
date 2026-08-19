/*
* Copyright (c) 2020, NVIDIA CORPORATION & AFFILIATES. All rights reserved.
* See file LICENSE for terms.
*/


void ucc_get_version(unsigned *major_version, unsigned *minor_version,
                     unsigned *release_number)
{
    *major_version  = 1;
    *minor_version  = 8;
    *release_number = 0;
}

const char *ucc_get_version_string()
{
	return "1.8.0";
}
