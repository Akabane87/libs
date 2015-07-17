/**
 * \file floatInVec_math.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _SCE_VECTORMATH_SCALAR_FLOATINVEC_MATH_H
#define _SCE_VECTORMATH_SCALAR_FLOATINVEC_MATH_H

#include <psp2/vectormath/scalar_cpp/floatInVec.h>

#if	!defined(SCE_VECTORMATH_NO_MATH_DEFS)

namespace sce {
namespace Vectormath {
namespace Scalar {

/// @short
/// Compute the arc cosine of <code><i>x</i></code>
///
/// Compute the arc cosine of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Arc cosine of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec acosf(floatInVec_arg x)
{
	return floatInVec( ::acosf( x.getAsFloat() ) );
}

/// @short
/// Compute the arc sine of <code><i>x</i></code>
///
/// Compute the arc sine of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Arc sine of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec asinf(floatInVec_arg x)
{
	return floatInVec( ::asinf( x.getAsFloat() ) );
}

/// @short
/// Compute the arc tangent of <code><i>x</i></code>
///
/// Compute the arc tangent of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Arc tangent of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec atanf(floatInVec_arg x)
{
	return floatInVec( ::atanf( x.getAsFloat() ) );
}

/// @short
/// Compute the arc tangent of <code><i>y</i></code>/<code><i>x</i></code>
///
/// Compute the arc tangent of <code><i>y</i></code>/<code><i>x</i></code>.
///
/// @param y   Scalar value
/// @param x   Scalar value
/// @return
/// Arc tangent of <code><i>y</i></code>/<code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec atan2f(floatInVec_arg y, floatInVec_arg x)
{
	return floatInVec( ::atan2f( y.getAsFloat() , x.getAsFloat() ) );
}

/// @short
/// Compute the cube root of <code><i>x</i></code>
///
/// Compute the cube root of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Cube root of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec cbrtf(floatInVec_arg x)
{
#if defined(__SNC__)
	return floatInVec( ::cbrtf( x.getAsFloat() ) );
#else
	return floatInVec( ::powf( x.getAsFloat(), 1.0f / 3.0f ) );
#endif
}

/// @short
/// Compute the smallest integral value greater than or equal to <code><i>x</i></code>
///
/// Compute the smallest integral value greater than or equal to <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Smallest integral value greater than or equal to <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec ceilf(floatInVec_arg x)
{
	return floatInVec( ::ceilf( x.getAsFloat() ) );
}

/// @short
/// Compute the value with the magnitude of <code><i>x</i></code> and the sign of <code><i>y</i></code>
///
/// Compute the value with the magnitude of <code><i>x</i></code> and the sign of <code><i>y</i></code>.
///
/// @param x   Scalar value
/// @param y   Scalar value
/// @return
/// Value with the magnitude of <code><i>x</i></code> and the sign of <code><i>y</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec copysignf(floatInVec_arg x, floatInVec_arg y)
{
	const float ax = ::fabsf( x.getAsFloat() );
	return floatInVec( y.getAsFloat() < 0.0f ? -ax : ax );
}

/// @short
/// Compute the cosine of <code><i>x</i></code>
///
/// Compute the cosine of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Cosine of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec cosf(floatInVec_arg x)
{
	return floatInVec( ::cosf( x.getAsFloat() ) );
}

/// @short
/// Compute the hyperbolic cosine of <code><i>x</i></code>
///
/// Compute the hyperbolic cosine of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Cosine of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec coshf(floatInVec_arg x)
{
	return floatInVec( ::coshf( x.getAsFloat() ) );
}

/// @short
/// Compute the quotient of <code><i>x</i></code>/<code><i>y</i></code>
///
/// Compute the quotient of <code><i>x</i></code>/<code><i>y</i></code>.
///
/// @param x   Scalar value
/// @param y   Scalar value
/// @return
/// Quotient of <code><i>x</i></code>/<code><i>y</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec divf(floatInVec_arg x, floatInVec_arg y)
{
	return floatInVec( x.getAsFloat() / y.getAsFloat() );
}

/// @short
/// Compute the base-2 exponential of <code><i>x</i></code>
///
/// Compute the base-2 exponential of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Base-2 exponential of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec exp2f(floatInVec_arg x)
{
	return floatInVec( ::powf( 2.0f, x.getAsFloat() ) );
}

/// @short
/// Compute the natural exponential of <code><i>x</i></code>
///
/// Compute the natural exponential of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Natural exponential of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec expf(floatInVec_arg x)
{
	return floatInVec( ::expf( x.getAsFloat() ) );
}

/// @short
/// Compute <code>expf(<code><i>x</i></code>)-1</code>
///
/// Compute <code>expf(<code><i>x</i></code>)-1</code> accurately even for small values of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// <code>expf(<code><i>x</i></code>)-1</code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec expm1f(floatInVec_arg x)
{
	return floatInVec( ::expf( x.getAsFloat() ) - 1.0f );
}

/// @short
/// Compute the absolute value of <code><i>x</i></code>
///
/// Compute the absolute value of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Absolute value of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec fabsf(floatInVec_arg x)
{
	return floatInVec( ::fabsf( x.getAsFloat() ) );
}

/// @short
/// Compute the difference if positive, 0 otherwise
///
/// Compute the difference if positive, 0 otherwise.
///
/// @param x   Scalar value
/// @param y   Scalar value
/// @return
/// Difference if positive, 0 otherwise
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec fdimf(floatInVec_arg x, floatInVec_arg y)
{
	return floatInVec( ( x.getAsFloat() > y.getAsFloat() ? ( x.getAsFloat() - y.getAsFloat() ) : 0.0f ) );
}

/// @short
/// Compute the largest integral value less than or equal to <code><i>x</i></code>
///
/// Compute the largest integral value less than or equal to <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Largest integral value less than or equal to <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec floorf(floatInVec_arg x)
{
	return floatInVec( ::floorf( x.getAsFloat() ) );
}

/// @short
/// Compute (<code><i>x</i></code>*<code><i>y</i></code>)+<code><i>z</i></code>, rounded as one ternary operation
///
/// Compute (<code><i>x</i></code>*<code><i>y</i></code>)+<code><i>z</i></code>, rounded as one ternary operation.
///
/// @param x   Scalar value
/// @param y   Scalar value
/// @param z   Scalar value
/// @return
/// (<code><i>x</i></code>*<code><i>y</i></code>)+<code><i>z</i></code>, rounded as one ternary operation
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec fmaf(floatInVec_arg x, floatInVec_arg y, floatInVec_arg z)
{
#if defined(__SNC__)
	return floatInVec( ::fmaf( x.getAsFloat(), y.getAsFloat(), z.getAsFloat() ) );
#else
	return floatInVec( ( x.getAsFloat() * y.getAsFloat() ) + z.getAsFloat() );
#endif
}

/// @short
/// Compute the maximum value of two values
///
/// Compute the maximum value of two values.
///
/// @param x   Scalar value
/// @param y   Scalar value
/// @return
/// Maximum value of two values
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec fmaxf(floatInVec_arg x, floatInVec_arg y)
{
	return floatInVec( x.getAsFloat() < y.getAsFloat() ? y.getAsFloat() : x.getAsFloat() );
}

/// @short
/// Compute the minimum value of two values
///
/// Compute the minimum value of two values.
///
/// @param x   Scalar value
/// @param y   Scalar value
/// @return
/// Minimum value of two values
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec fminf(floatInVec_arg x, floatInVec_arg y)
{
	return floatInVec( x.getAsFloat() > y.getAsFloat() ? y.getAsFloat() : x.getAsFloat() );
}

/// @short
/// Compute the remainder of <code><i>x</i></code>/<code><i>y</i></code>
///
/// Compute the remainder of <code><i>x</i></code>/<code><i>y</i></code>;
/// the result has the same sign as <code><i>x</i></code> and magnitude less than the magnitude of <code><i>y</i></code>.
///
/// @param x   Scalar value
/// @param y   Scalar value
/// @return
/// Remainder of <code><i>x</i></code>/<code><i>y</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec fmodf(floatInVec_arg x, floatInVec_arg y)
{
	return floatInVec( ::fmodf( x.getAsFloat(), y.getAsFloat() ) );
}

/// @short
/// Compute the Euclidean distance
///
/// Compute the Euclidean distance,
/// which is the same as sqrtf(<code><i>x</i></code>*<code><i>x</i></code>+<code><i>y</i></code>*<code><i>y</i></code>).
///
/// @param x   Scalar value
/// @param y   Scalar value
/// @return
/// Euclidean distance
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec hypotf(floatInVec_arg x, floatInVec_arg y)
{
#if defined(__SNC__)
	return floatInVec( ::hypotf( x.getAsFloat(), y.getAsFloat() ) );
#else
	return floatInVec( ::sqrtf( ( x.getAsFloat() * x.getAsFloat() ) + ( y.getAsFloat() * y.getAsFloat() ) ) );
#endif
}

/// @short
/// Compute the base-10 logarithm of <code><i>x</i></code>
///
/// Compute the base-10 logarithm of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Base-10 logarithm of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec log10f(floatInVec_arg x)
{
	return floatInVec( ::log10f( x.getAsFloat() ) );
}

/// @short
/// Compute logf(<code><i>x</i></code>+1)
///
/// Compute logf(<code><i>x</i></code>+1) accurately even for small values of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// logf(<code><i>x</i></code>+1)
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec log1pf(floatInVec_arg x)
{
	return floatInVec( ::logf( x.getAsFloat() + 1.0f ) );
}

/// @short
/// Compute the base-2 logarithm of <code><i>x</i></code>
///
/// Compute the base-2 logarithm of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Base-2 logarithm of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec logtwof(floatInVec_arg x)
{
#if defined(__SNC__)
	return floatInVec( log2f( x.getAsFloat() ) );
#else
	return floatInVec( ::logf( x.getAsFloat() ) / ::logf( 2.0f ) );
#endif
}

/// @short
/// Compute the exponent of <code><i>x</i></code>
///
/// Compute the exponent of <code><i>x</i></code>,
/// which is the same as floorf(log2f(<code><i>x</i></code>)) if FLT_RADIX is equal to 2.
///
/// @param x   Scalar value
/// @return
/// Exponent of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec logbf(floatInVec_arg x)
{
#if defined(__SNC__)
	return floatInVec( ::logbf( x.getAsFloat() ) );
#else
	return floatInVec( ::floorf( ::logf( x.getAsFloat() ) / ::logf( 2.0f ) ) );
#endif
}

/// @short
/// Compute the natural logarithm of <code><i>x</i></code>
///
/// Compute the natural logarithm of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Natural logarithm of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec logf(floatInVec_arg x)
{
	return floatInVec( ::logf( x.getAsFloat() ) );
}

/// @short
/// Compute the integral and fractional parts of <code><i>x</i></code>
///
/// Compute the integral and fractional parts of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @param i   Pointer to a float scalar class (containing one float)
/// @return
/// Integral and fractional parts of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec modff(floatInVec_arg x, floatInVec* i)
{
	float iff;
	float result = ::modff( x.getAsFloat(), &iff );
	*i = floatInVec( iff );
	return floatInVec( result );
}

/// @short
/// Compute the negation of <code><i>x</i></code>
///
/// Compute the negation of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Negation of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec negatef(floatInVec_arg x)
{
	return floatInVec( - x.getAsFloat() );
}

/// @short
/// Compute <code><i>x</i></code> raised to the power of <code><i>y</i></code>
///
/// Compute <code><i>x</i></code> raised to the power of <code><i>y</i></code>.
///
/// @param x   Scalar value
/// @param y   Scalar value
/// @return
/// <code><i>x</i></code> raised to the power of <code><i>y</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec powf(floatInVec_arg x, floatInVec_arg y)
{
	return floatInVec( ::powf( x.getAsFloat(), y.getAsFloat() ) );
}

/// @short
/// Compute the reciprocal of <code><i>x</i></code>
///
/// Compute the reciprocal of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Reciprocal of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec recipf(floatInVec_arg x)
{
	return floatInVec( 1.0f / x.getAsFloat() );
}

/// @short
/// Compute the reciprocal of the square root of <code><i>x</i></code>
///
/// Compute the reciprocal of the square root of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Reciprocal of the square root of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec rsqrtf(floatInVec_arg x)
{
	return floatInVec( 1.0f / ::sqrtf( x.getAsFloat() ) );
}

/// @short
/// Compute the remainder of <code><i>x</i></code>/<code><i>y</i></code>
///
/// Compute the remainder of <code><i>x</i></code>/<code><i>y</i></code>,
/// where the quotient is the integral value nearest the exact value of <code><i>x</i></code>/<code><i>y</i></code>.
///
/// @param x   Scalar value
/// @param y   Scalar value
/// @return
/// Remainder of <code><i>x</i></code>/<code><i>y</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec remainderf(floatInVec_arg x, floatInVec_arg y)
{
#if defined(__SNC__)
	return floatInVec( ::remainderf( x.getAsFloat(), y.getAsFloat() ) );
#else
	float q  = x.getAsFloat() / y.getAsFloat();
	float q_hi = ::ceilf( q );
	float q_lo = ::floorf( q );
	float r = ( ::fabsf( q_hi - q ) < ::fabsf( q - q_lo ) ? q_hi : q_lo );
	return floatInVec( x.getAsFloat() - ( y.getAsFloat() * r ) );
#endif
}

/// @short
/// Compute the sine and cosine of <code><i>x</i></code>
///
/// Compute the sine and cosine of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @param s   Pointer to a float scalar class (containing one float)
/// @param c   Pointer to a float scalar class (containing one float)
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE void sincosf(floatInVec_arg x, floatInVec* s, floatInVec* c)
{
	*s = floatInVec( ::sinf( x.getAsFloat() ) );
	*c = floatInVec( ::cosf( x.getAsFloat() ) );
}

/// @short
/// Compute the sine of <code><i>x</i></code>
///
/// Compute the sine of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Sine of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec sinf(floatInVec_arg x)
{
	return floatInVec( ::sinf( x.getAsFloat() ) );
}

/// @short
/// Compute the hyperbolic sine of <code><i>x</i></code>
///
/// Compute the hyperbolic sine of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Sine of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec sinhf(floatInVec_arg x)
{
	return floatInVec( ::sinhf( x.getAsFloat() ) );
}

/// @short
/// Compute the square root of <code><i>x</i></code>
///
/// Compute the square root of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Square root of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec sqrtf(floatInVec_arg x)
{
	return floatInVec( ::sqrtf( x.getAsFloat() ) );
}

/// @short
/// Compute the tangent of <code><i>x</i></code>
///
/// Compute the tangent of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Tangent of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec tanf(floatInVec_arg x)
{
	 return floatInVec( ::tanf( x.getAsFloat() ) );
}

/// @short
/// Compute the hyperbolic tangent of <code><i>x</i></code>
///
/// Compute the hyperbolic tangent of <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Tangent of <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec tanhf(floatInVec_arg x)
{
	return floatInVec( ::tanhf( x.getAsFloat() ) );
}

/// @short
/// Compute the integral value nearest to but no larger in magnitude than <code><i>x</i></code>
///
/// Compute the integral value nearest to but no larger in magnitude than <code><i>x</i></code>.
///
/// @param x   Scalar value
/// @return
/// Integral value nearest to but no larger in magnitude than <code><i>x</i></code>
/// @note
/// To use this API, <code>floatInVec_math.h</code> must be included.
///
SCE_VECTORMATH_ALWAYS_INLINE floatInVec truncf(floatInVec_arg x)
{
#if defined(__SNC__)
	return floatInVec( ::truncf( x.getAsFloat() ) );
#else
	float iresult;
	::modff( x.getAsFloat(), &iresult );
	return floatInVec( iresult );
#endif
}

} // namespace Scalar
} // namespace Vectormath
} // namespace sce

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

#endif /* _SCE_VECTORMATH_SCALAR_FLOATINVEC_MATH_H */
