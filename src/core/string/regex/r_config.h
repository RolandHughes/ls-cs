/***********************************************************************
*
* Copyright (c) 2017-2024 Barbara Geller
* Copyright (c) 2017-2024 Ansel Sermersheim
*
* Copyright (c) 1998-2009 John Maddock
*
* This file is part of CopperSpice.
*
* CopperSpice is free software, released under the BSD 2-Clause license.
* For license details refer to LICENSE provided with this project.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/

/*
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef LSCS_CONFIG_H
#define LSCS_CONFIG_H

#if defined(_UNICODE) && ! defined(UNICODE)
#   define UNICODE
#endif

#ifndef LSCS_REGEX_MAX_STATE_COUNT
#  define LSCS_REGEX_MAX_STATE_COUNT 100000000
#endif

#ifndef LSCS_REGEX_BLOCKSIZE
#   define LSCS_REGEX_BLOCKSIZE 4096
#endif

#if LSCS_REGEX_BLOCKSIZE < 512
#   error "LSCS_REGEX_BLOCKSIZE must be at least 512"
#endif

#ifndef LSCS_REGEX_MAX_BLOCKS
#   define LSCS_REGEX_MAX_BLOCKS 1024
#endif

#ifndef LSCS_REGEX_MAX_CACHE_BLOCKS
#   define LSCS_REGEX_MAX_CACHE_BLOCKS 16
#endif


#ifdef _WIN32

#ifdef BUILDING_LIB_LSCS_STRING
# define LIB_LSCS_STRING_EXPORT     __declspec(dllexport)
#else
# define LIB_LSCS_STRING_EXPORT     __declspec(dllimport)
#endif

#else
# define LIB_LSCS_STRING_EXPORT

#endif

#include <regex/r_error_type.h>
#include <regex/regex_constants.h>

#endif

