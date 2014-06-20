/*
 * Author: Brendan Le Foll <brendan.le.foll@intel.com>
 * Copyright © 2014 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#pragma once

/** @file
 *
 * This file defines the basic shared types for libmaa
 * this file is different to common.h in that swig takes this as an input
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * MAA supported platform types
 */
typedef enum {
    MAA_INTEL_GALILEO_GEN1 = 0, /**< The Generation 1 Galileo platform (RevD) */
    MAA_INTEL_GALILEO_GEN2 = 1, /**< The Generation 2 Galileo platform (RevG/H) */

    MAA_UNKNOWN_PLATFORM = 99 /**< An unknown platform type, typically will load INTEL_GALILEO_GEN1 */
} maa_platform_t;

/**
 * MAA return codes
 */
typedef enum {
    MAA_SUCCESS                              =  0, /**< Expected response */
    MAA_ERROR_FEATURE_NOT_IMPLEMENTED        =  1, /**< Feature TODO */
    MAA_ERROR_FEATURE_NOT_SUPPORTED          =  2, /**< Feature not supported by HW */
    MAA_ERROR_INVALID_VERBOSITY_LEVEL        =  3, /**< Verbosity level wrong */
    MAA_ERROR_INVALID_PARAMETER              =  4, /**< Parameter invalid */
    MAA_ERROR_INVALID_HANDLE                 =  5, /**< Handle invalid */
    MAA_ERROR_NO_RESOURCES                   =  6, /**< No resource of that type avail */
    MAA_ERROR_INVALID_RESOURCE               =  7, /**< Resource invalid */
    MAA_ERROR_INVALID_QUEUE_TYPE             =  8, /**< Queue type incorrect */
    MAA_ERROR_NO_DATA_AVAILABLE              =  9, /**< No data available */
    MAA_ERROR_INVALID_PLATFORM               = 10, /**< Platform not recognised */
    MAA_ERROR_PLATFORM_NOT_INITIALISED       = 11, /**< Board information not initialised */
    MAA_ERROR_PLATFORM_ALREADY_INITIALISED   = 12, /**< Board is already initialised */

    MAA_ERROR_UNSPECIFIED                    = 99 /**< Unknown Error */
} maa_result_t;

/**
 * This function attempts to set the maa process to a given priority and the
 * scheduler to SCHED_RR. Highest * priority is typically 99 and minimum is 0.
 * This function * will set to MAX if * priority is > MAX. Function will return
 * -1 on failure.

 * @param priority Value from typically 0 to 99
 * @return The priority value set
 */
int maa_set_priority(const unsigned int priority);

/** Get the version string of maa autogenerated from git tag
 *
 * The version returned may not be what is expected however it is a reliable
 * number associated with the git tag closest to that version at build time
 *
 * @return version string from version.h
 */
const char* maa_get_version();

/**
 * Print a textual representation of the maa_result_t
 *
 * @param result the result to print
 */
void maa_result_print(maa_result_t result);

/**
 * Get platform type, board must be initialised.
 *
 * @return maa_platform_t Platform type enum
 */
maa_platform_t maa_get_platform_type();

#ifdef __cplusplus
}
#endif
