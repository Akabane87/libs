/**
 * \file floatInVec.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _SCE_VECTORMATH_SCALAR_FLOATINVEC_H
#define _SCE_VECTORMATH_SCALAR_FLOATINVEC_H

#include <psp2/vectormath/scalar_cpp/internal/internal.h>


/// @short
/// The namespace containing the sce framework.
///
/// The namespace containing the sce framework.
///
namespace sce {

/// @short
/// The namespace containing the Vectormath library.
///
/// The namespace containing the Vectormath library.
///
namespace Vectormath {

/// @short
/// The namespace containing the Vectormath Scalar implementation.
///
/// The namespace containing the Vectormath Scalar implementation.
///
namespace Scalar {

class boolInVec;

/// @short
/// A class representing a scalar float value.
///
/// A class representing a scalar float value.
/// This class does not support fastmath
class floatInVec
{
	float mData;

public:
	/// @short
	/// Default constructor; does no initialization.
	///
	/// Default constructor; does no initialization.
	///
	SCE_VECTORMATH_ALWAYS_INLINE floatInVec();

	/// @short
	/// Construct from a value converted from bool.
	///
	/// Construct from a value that is generated from bool by standard type conversion.
	/// @param vec   Scalar bool value
	///
	SCE_VECTORMATH_ALWAYS_INLINE floatInVec(boolInVec_arg vec);

	/// @short
	/// Explicit cast from float.
	///
	/// Explicit cast from float.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_ALWAYS_INLINE floatInVec(float scalar);

	/// @short
	/// Explicit cast to float.
	///
	/// Explicit cast to float.
	/// @return
	/// Float value
	///
	SCE_VECTORMATH_ALWAYS_INLINE float getAsFloat() const;

#ifndef _SCE_VECTORMATH_NO_SCALAR_CAST
	/// @short
	/// Implicit cast to float.
	///
	/// Implicit cast to float.
	/// @note
	/// This function is only defined when _SCE_VECTORMATH_NO_SCALAR_CAST is undefined. (There is the option for the purpose of finding LHS by implicit cast.)
	///
	SCE_VECTORMATH_ALWAYS_INLINE operator float() const;
#endif

	/// @short
	/// Post increment (add 1.0f).
	///
	/// Post increment (add 1.0f).
	/// @return
	/// Old value
	///
	SCE_VECTORMATH_ALWAYS_INLINE const floatInVec operator ++ (int);

	/// @short
	/// Post decrement (subtract 1.0f).
	///
	/// Post decrement (subtract 1.0f).
	/// @return
	/// Old value
	///
	SCE_VECTORMATH_ALWAYS_INLINE const floatInVec operator -- (int);

	/// @short
	/// Pre increment (add 1.0f).
	///
	/// Pre increment (add 1.0f).
	/// @return
	/// A reference to the updated value
	///
	SCE_VECTORMATH_ALWAYS_INLINE floatInVec& operator ++ ();

	/// @short
	/// Pre decrement (subtract 1.0f).
	///
	/// Pre decrement (subtract 1.0f).
	/// @return
	/// A reference to the updated value
	///
	SCE_VECTORMATH_ALWAYS_INLINE floatInVec& operator -- ();

	/// @short
	/// Negation operator.
	///
	/// Negation operator.
	/// @return
	/// Negated value
	///
	SCE_VECTORMATH_ALWAYS_INLINE const floatInVec operator - () const;

	 /// @short
	/// Assignment operator.
	///
	/// Assignment operator.
	/// @param vec   Scalar value
	/// @return
	/// A reference to the resulting value
	///
	SCE_VECTORMATH_ALWAYS_INLINE floatInVec& operator = (floatInVec_arg vec);

	/// @short
	/// Multiplication assignment operator.
	///
	/// Multiplication assignment operator.
	/// @param vec   Scalar value
	/// @return
	/// A reference to the resulting value
	///
	SCE_VECTORMATH_ALWAYS_INLINE floatInVec& operator *= (floatInVec_arg vec);

	/// @short
	/// Division assignment operator.
	///
	/// Division assignment operator.
	/// @param vec   Scalar value
	/// @return
	/// A reference to the resulting value
	///
	SCE_VECTORMATH_ALWAYS_INLINE floatInVec& operator /= (floatInVec_arg vec);

	/// @short
	/// Addition assignment operator.
	///
	/// Addition assignment operator.
	/// @param vec   Scalar value
	/// @return
	/// A reference to the resulting value
	///
	SCE_VECTORMATH_ALWAYS_INLINE floatInVec& operator += (floatInVec_arg vec);

	/// @short
	/// Subtraction assignment operator.
	///
	/// Subtraction assignment operator.
	/// @param vec   Scalar value
	/// @return
	/// A reference to the resulting value
	///
	SCE_VECTORMATH_ALWAYS_INLINE floatInVec& operator -= (floatInVec_arg vec);
};

/// @name floatInVec Functions
/// @{

/// @short
/// Multiplication operator
///
/// Multiplication operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// Product of the specified values
///
SCE_VECTORMATH_ALWAYS_INLINE const floatInVec operator * (floatInVec_arg vec0, floatInVec_arg vec1);

/// @short
/// Division operator
///
/// Division operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// Quotient of the specified values
///
SCE_VECTORMATH_ALWAYS_INLINE const floatInVec operator / (floatInVec_arg vec0, floatInVec_arg vec1);

/// @short
/// Addition operator.
///
/// Addition operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// Sum of the specified values
///
SCE_VECTORMATH_ALWAYS_INLINE const floatInVec operator + (floatInVec_arg vec0, floatInVec_arg vec1);

/// @short
/// Subtraction operator.
///
/// Subtraction operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// Difference of the specified values
///
SCE_VECTORMATH_ALWAYS_INLINE const floatInVec operator - (floatInVec_arg vec0, floatInVec_arg vec1);

/// @short
/// Less than operator.
///
/// Less than operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// True if <code><i>vec0</i></code> is less than <code><i>vec1</i></code>; otherwise false
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator < (floatInVec_arg vec0, floatInVec_arg vec1);

/// @short
/// Less than or equal operator.
///
/// Less than or equal operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// True if <code><i>vec0</i></code> is less than or equal to <code><i>vec1</i></code>; otherwise false
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator <= (floatInVec_arg vec0, floatInVec_arg vec1);

/// @short
/// Greater than operator.
///
/// Greater than operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// True if <code><i>vec0</i></code> is greater than <code><i>vec1</i></code>; otherwise false
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator > (floatInVec_arg vec0, floatInVec_arg vec1);

/// @short
/// Greater than or equal operator.
///
/// Greater than or equal operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// True if <code><i>vec0</i></code> is greater than or equal to <code><i>vec1</i></code>; otherwise false
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator >= (floatInVec_arg vec0, floatInVec_arg vec1);

/// @short
/// Equal operator.
///
/// Equal operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// True if <code><i>vec0</i></code> is equal to <code><i>vec1</i></code>; otherwise false
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator == (floatInVec_arg vec0, floatInVec_arg vec1);

/// @short
/// Not equal operator.
///
/// Not equal operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// True if <code><i>vec0</i></code> is not equal to <code><i>vec1</i></code>; otherwise false
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator != (floatInVec_arg vec0, floatInVec_arg vec1);

/// @short
/// Clamp the value between the minimum and maximum values.
///
/// Clamp the value between the minimum and maximum values
/// @param vec	  Scalar value
/// @param minVec   Scalar minimum value
/// @param maxVec   Scalar maximum value
/// @return
/// Equal to <code><i>minVec</i></code> if <code><i>vec</i></code> is less than <code><i>minVec</i></code>
/// @par
/// Equal to <code><i>maxVec</i></code> if <code><i>vec</i></code> is greater than <code><i>maxVec</i></code>
/// @par
/// Else the result is equal to <code><i>vec</i></code>
/// @note
/// Result is undefined if the minimum value is greater than the maximum value
///
SCE_VECTORMATH_ALWAYS_INLINE const floatInVec clamp(floatInVec_arg vec, floatInVec_arg minVec, floatInVec_arg maxVec);

/// @short
/// Conditionally select between two values.
///
/// Conditionally select between two values.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @param select_vec1   False selects <code><i>vec0</i></code>; true selects <code><i>vec1</i></code>
/// @return
/// Equal to <code><i>vec1</i></code> if <code><i>select_vec1</i></code> is true; otherwise equal to <code><i>vec0</i></code>
///
SCE_VECTORMATH_ALWAYS_INLINE const floatInVec select(floatInVec_arg vec0, floatInVec_arg vec1, boolInVec_arg select_vec1);

/// @short
/// Conditionally select between two values.
///
/// Conditionally select between two values.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @param select1   False selects <code><i>vec0</i></code>; true selects <code><i>vec1</i></code>
/// @return
/// Equal to <code><i>vec1</i></code> if <code><i>select1</i></code> is true; otherwise equal to <code><i>vec0</i></code>
///
SCE_VECTORMATH_ALWAYS_INLINE const floatInVec select(floatInVec_arg vec0, floatInVec_arg vec1, bool select1);

/// @}

} // namespace Scalar
} // namespace Vectormath
} // namespace sce

//--------------------------------------------------------------------------------------------------
// floatInVec implementation
//

#include <psp2/vectormath/scalar_cpp/boolInVec.h>

namespace sce {
namespace Vectormath {
namespace Scalar {

SCE_VECTORMATH_ALWAYS_INLINE floatInVec::floatInVec()
{
}

SCE_VECTORMATH_ALWAYS_INLINE floatInVec::floatInVec(boolInVec_arg vec)
{
	mData = float(vec.getAsBool());
}

SCE_VECTORMATH_ALWAYS_INLINE floatInVec::floatInVec(float scalar)
{
	mData = scalar;
}

SCE_VECTORMATH_ALWAYS_INLINE float floatInVec::getAsFloat() const
{
	return mData;
}

#ifndef _SCE_VECTORMATH_NO_SCALAR_CAST
SCE_VECTORMATH_ALWAYS_INLINE floatInVec::operator float() const
{
	return getAsFloat();
}
#endif

SCE_VECTORMATH_ALWAYS_INLINE const floatInVec floatInVec::operator ++ (int)
{
	float olddata = mData;
	operator ++();
	return floatInVec(olddata);
}

SCE_VECTORMATH_ALWAYS_INLINE const floatInVec floatInVec::operator --(int)
{
	float olddata = mData;
	operator --();
	return floatInVec(olddata);
}

SCE_VECTORMATH_ALWAYS_INLINE floatInVec& floatInVec::operator ++()
{
	*this += floatInVec(1.0f);
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE floatInVec& floatInVec::operator --()
{
	*this -= floatInVec(1.0f);
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const floatInVec floatInVec::operator -() const
{
	return floatInVec(-mData);
}

SCE_VECTORMATH_ALWAYS_INLINE floatInVec& floatInVec::operator =(floatInVec_arg vec)
{
	mData = vec.mData;
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE floatInVec& floatInVec::operator *=(floatInVec_arg vec)
{
	mData *= vec.mData;
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE floatInVec& floatInVec::operator /=(floatInVec_arg vec)
{
	mData /= vec.mData;
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE floatInVec& floatInVec::operator +=(floatInVec_arg vec)
{
	mData += vec.mData;
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE floatInVec& floatInVec::operator -=(floatInVec_arg vec)
{
	mData -= vec.mData;
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const floatInVec operator *(floatInVec_arg vec0, floatInVec_arg vec1)
{
	return floatInVec(vec0.getAsFloat() * vec1.getAsFloat());
}

SCE_VECTORMATH_ALWAYS_INLINE const floatInVec operator /(floatInVec_arg num, floatInVec_arg den)
{
	return floatInVec(num.getAsFloat() / den.getAsFloat());
}

SCE_VECTORMATH_ALWAYS_INLINE const floatInVec operator +(floatInVec_arg vec0, floatInVec_arg vec1)
{
	return floatInVec(vec0.getAsFloat() + vec1.getAsFloat());
}

SCE_VECTORMATH_ALWAYS_INLINE const floatInVec operator -(floatInVec_arg vec0, floatInVec_arg vec1)
{
	return floatInVec(vec0.getAsFloat() - vec1.getAsFloat());
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator <(floatInVec_arg vec0, floatInVec_arg vec1)
{
	return boolInVec(vec0.getAsFloat() < vec1.getAsFloat());
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator <=(floatInVec_arg vec0, floatInVec_arg vec1)
{
	return boolInVec(!(vec0.getAsFloat() > vec1.getAsFloat()));
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator >(floatInVec_arg vec0, floatInVec_arg vec1)
{
	return boolInVec(vec0.getAsFloat() > vec1.getAsFloat());
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator >=(floatInVec_arg vec0, floatInVec_arg vec1)
{
	return boolInVec(!(vec0.getAsFloat() < vec1.getAsFloat()));
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator ==(floatInVec_arg vec0, floatInVec_arg vec1)
{
#if defined(__clang__)
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wfloat-equal"
#endif
	return boolInVec(vec0.getAsFloat() == vec1.getAsFloat());
#if defined(__clang__)
	#pragma clang diagnostic pop
#endif
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator !=(floatInVec_arg vec0, floatInVec_arg vec1)
{
#if defined(__clang__)
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wfloat-equal"
#endif
	return boolInVec(!(vec0.getAsFloat() == vec1.getAsFloat()));
#if defined(__clang__)
	#pragma clang diagnostic pop
#endif
}

SCE_VECTORMATH_ALWAYS_INLINE const floatInVec clamp(floatInVec_arg vec , floatInVec_arg minVec, floatInVec_arg maxVec )
{
	return select( select( vec, minVec, vec < minVec ), maxVec, vec > maxVec );
}

SCE_VECTORMATH_ALWAYS_INLINE const floatInVec select(floatInVec_arg vec0, floatInVec_arg vec1, boolInVec_arg select_vec1)
{
	return (select_vec1.getAsBool() == 0) ? vec0 : vec1;
}

SCE_VECTORMATH_ALWAYS_INLINE const floatInVec select(floatInVec_arg vec0, floatInVec_arg vec1, bool select1)
{
	return select1 ? vec1 : vec0;
}

} // namespace Scalar
} // namespace Vectormath
} // namespace sce

#endif /* _SCE_VECTORMATH_SCALAR_FLOATINVEC_H */
