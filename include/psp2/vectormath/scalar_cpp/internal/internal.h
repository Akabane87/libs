/**
 * \file internal.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_VECTORMATH_SCALAR_INTERNAL_H_
#define _PSP2_VECTORMATH_SCALAR_INTERNAL_H_

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)
#include <math.h>
#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

//-----------------------------------------------------------------------------
// Alignment and Inlining Control
#define SCE_VECTORMATH_PREALIGN_16
#define SCE_VECTORMATH_POSTALIGN_16 __attribute__ ((aligned(16)))
#define SCE_VECTORMATH_ALWAYS_INLINE inline __attribute__((always_inline))
#define SCE_VECTORMATH_INLINE
#define SCE_VECTORMATH_NO_INLINE __attribute__((noinline))
#define SCE_VECTORMATH_UNUSED
#define SCE_VECTORMATH_IS_COMPILE_TIME_CONSTANT( x ) __builtin_constant_p(x)


//-----------------------------------------------------------------------------
// Platform-specific Type Inclusion
#include <psp2/vectormath/scalar_cpp/internal/internal_types.h>

//-----------------------------------------------------------------------------
// Platform-specific Argument Types
//#if defined(_MSC_VER)
  #define SCE_VECTORMATH_SCALAR_AOS_FLOATINVEC_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_BOOLINVEC_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_VECTOR_ARG &
  #define SCE_VECTORMATH_SCALAR_AOS_MATRIX_ARG &
/*#elif defined(__SSE2__)
  #define SCE_VECTORMATH_SCALAR_AOS_FLOATINVEC_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_BOOLINVEC_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_VECTOR_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_MATRIX_ARG &
#elif defined(__ARM_NEON__)
  #define SCE_VECTORMATH_SCALAR_AOS_FLOATINVEC_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_BOOLINVEC_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_VECTOR_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_MATRIX_ARG
#elif defined(__ALTIVEC__) || defined(__PPU__)
  #define SCE_VECTORMATH_SCALAR_AOS_FLOATINVEC_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_BOOLINVEC_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_VECTOR_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_MATRIX_ARG
#elif defined(__SPU__)
  #define SCE_VECTORMATH_SCALAR_AOS_FLOATINVEC_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_BOOLINVEC_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_VECTOR_ARG
  #define SCE_VECTORMATH_SCALAR_AOS_MATRIX_ARG
#else
  #error unsupported environment
#endif*/

//-----------------------------------------------------------------------------
// Default Assert Stub
#if !defined(SCE_VECTORMATH_ASSERT_MSG)
#define SCE_VECTORMATH_ASSERT_MSG(condition,message)	(void)(condition)
#endif	//	#if !(defined SCE_VECTORMATH_ASSERT_MSG)

#endif /* _PSP2_VECTORMATH_SCALAR_INTERNAL_H_ */
