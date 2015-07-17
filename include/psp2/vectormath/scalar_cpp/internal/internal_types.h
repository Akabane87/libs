/**
 * \file internal_types.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_VECTORMATH_SCALAR_INTERNAL_TYPES_H_
#define _PSP2_VECTORMATH_SCALAR_INTERNAL_TYPES_H_

// Standard Types
#if !defined(SCE_VECTORMATH_NO_STDINT_DEFS)
  #if defined(_MSC_VER) && (_MSC_VER < 1600)
    typedef signed __int8  int8_t;
    typedef signed __int16 int16_t;
    typedef signed __int32 int32_t;
    typedef signed __int64 int64_t;
    typedef unsigned __int8  uint8_t;
    typedef unsigned __int16 uint16_t;
    typedef unsigned __int32 uint32_t;
    typedef unsigned __int64 uint64_t;
  #else
    #include <stdint.h>
  #endif
#endif

#endif	//	#ifndef _PSP2_VECTORMATH_SCALAR_INTERNAL_TYPES_H_
