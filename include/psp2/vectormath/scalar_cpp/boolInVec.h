/**
 * \file boolInVec.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_VECTORMATH_SCALAR_BOOLINVEC_H_
#define _PSP2_VECTORMATH_SCALAR_BOOLINVEC_H_

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

class floatInVec;

//--------------------------------------------------------------------------------------------------
// boolInVec class
//

/// @short
/// A class representing a scalar bool value.
///
/// A class representing a scalar bool value.
/// This class does not support fastmath.
class boolInVec
{
	uint32_t mData;

public:
	/// @short
	/// Default constructor; does no initialization.
	///
	/// Default constructor; does no initialization.
	///
	SCE_VECTORMATH_ALWAYS_INLINE boolInVec();

	/// @short
	/// Construct from a value converted from float.
	///
	/// Construct from a value that is generated from float by standard type conversion.
	/// @param vec   Scalar float value
	///
	SCE_VECTORMATH_ALWAYS_INLINE boolInVec(floatInVec_arg vec);

	/// @short
	/// Explicit cast from bool.
	///
	/// Explicit cast from bool.
	/// @param scalar   Scalar bool value
	///
	explicit SCE_VECTORMATH_ALWAYS_INLINE boolInVec(bool scalar);

	/// @short
	/// Explicit cast to bool.
	///
	/// Explicit cast to bool.
	/// @return
	/// Bool value
	///
	SCE_VECTORMATH_ALWAYS_INLINE bool getAsBool() const;

#ifndef _SCE_VECTORMATH_NO_SCALAR_CAST
	/// @short
	/// Implicit cast to bool.
	///
	/// Implicit cast to bool.
	/// @note
	/// This function is disabled if <code>_SCE_VECTORMATH_NO_SCALAR_CAST</code> is defined.
	///
	SCE_VECTORMATH_ALWAYS_INLINE operator bool() const;
#endif

	/// @short
	/// Boolean negation operator.
	///
	/// Boolean negation operator.
	/// @return
	/// Boolean negated value
	///
	SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator !() const;

	/// @short
	/// Assignment operator.
	///
	/// Assignment operator.
	/// @param vec  Scalar value
	/// @return
	/// A reference to the resulting boolean value
	///
	SCE_VECTORMATH_ALWAYS_INLINE boolInVec& operator =(boolInVec_arg vec);

	/// @short
	/// Boolean and assignment operator.
	///
	/// Boolean and assignment operator.
	/// @param vec  Scalar value
	/// @return
	/// A reference to the resulting boolean value
	///
	SCE_VECTORMATH_ALWAYS_INLINE boolInVec& operator &=(boolInVec_arg vec);

	/// @short
	/// Boolean exclusive or assignment operator.
	///
	/// Boolean exclusive or assignment operator.
	/// @param vec  Scalar value
	/// @return
	/// A reference to the resulting boolean value
	///
	SCE_VECTORMATH_ALWAYS_INLINE boolInVec& operator ^=(boolInVec_arg vec);

	/// @short
	/// Boolean or assignment operator.
	///
	/// Boolean or assignment operator.
	/// @param vec  Scalar value
	/// @return
	/// A reference to the resulting boolean value
	///
	SCE_VECTORMATH_ALWAYS_INLINE boolInVec& operator |=(boolInVec_arg vec);
};

/// @name boolInVec Functions
/// @{

/// @short
/// Equal operator.
///
/// Equal operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// True if <code><i>vec0</i></code> is equal to <code><i>vec1</i></code>; otherwise false
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator ==(boolInVec_arg vec0, boolInVec_arg vec1);

/// @short
/// Not equal operator.
///
/// Not equal operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// True if <code><i>vec0</i></code> is not equal to <code><i>vec1</i></code>; otherwise false
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator !=(boolInVec_arg vec0, boolInVec_arg vec1);

/// @short
/// And operator.
///
/// And operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// True if <code><i>vec0</i></code> is true and <code><i>vec1</i></code> is also true; otherwise false
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator &(boolInVec_arg vec0, boolInVec_arg vec1);

/// @short
/// Logical And operator.
///
/// Logical And operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// True if <code><i>vec0</i></code> is true and <code><i>vec1</i></code> is also true; otherwise false
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator &&(boolInVec_arg vec0, boolInVec_arg vec1);

/// @short
/// Exclusive or operator.
///
/// Exclusive or operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// True if <code><i>vec0</i></code> is not equal to <code><i>vec1</i></code>; otherwise false
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator ^(boolInVec_arg vec0, boolInVec_arg vec1);

/// @short
/// Or operator.
///
/// Or operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// True if <code><i>vec0</i></code> is true or <code><i>vec1</i></code> is true; otherwise false
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator |(boolInVec_arg vec0, boolInVec_arg vec1);

/// @short
/// Logical Or operator.
///
/// Logical Or operator.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @return
/// True if <code><i>vec0</i></code> is true or <code><i>vec1</i></code> is true; otherwise false
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator ||(boolInVec_arg vec0, boolInVec_arg vec1);

/// @short
/// Conditionally select between two values.
///
/// Conditionally select between two values.
/// @param vec0   Scalar value
/// @param vec1   Scalar value
/// @param select_vec1   False selects <code><i>vec0</i></code>; true selects <code><i>vec1</i></code>
/// @return
/// Equal to <code><i>vec1</i></code> if <code><i>select_vec1</i></code> is true; otherwise equal to <code><i>vec0</i></code>
/// @note
/// This function uses a conditional select instruction to avoid a branch.
///
SCE_VECTORMATH_ALWAYS_INLINE const boolInVec select(boolInVec_arg vec0, boolInVec_arg vec1, boolInVec_arg select_vec1);

/// @}

} // namespace Scalar
} // namespace Vectormath
} // namespace sce

//--------------------------------------------------------------------------------------------------
// boolInVec implementation
//

#include <psp2/vectormath/scalar_cpp/floatInVec.h>

namespace sce {

namespace Vectormath {

namespace Scalar {

SCE_VECTORMATH_ALWAYS_INLINE boolInVec::boolInVec()
{
}

SCE_VECTORMATH_ALWAYS_INLINE boolInVec::boolInVec(floatInVec_arg vec)
{
	*this = (vec != floatInVec(0.0f));
}

SCE_VECTORMATH_ALWAYS_INLINE boolInVec::boolInVec(bool scalar)
{
	int32_t mask = static_cast<int32_t>(scalar);
	mData = static_cast<uint32_t>(-mask);
}

SCE_VECTORMATH_ALWAYS_INLINE bool boolInVec::getAsBool() const
{
	return (mData != 0);
}

#ifndef _SCE_VECTORMATH_NO_SCALAR_CAST
SCE_VECTORMATH_ALWAYS_INLINE boolInVec::operator bool() const
{
	return getAsBool();
}
#endif

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec boolInVec::operator ! () const
{
	return boolInVec(!mData);
}

SCE_VECTORMATH_ALWAYS_INLINE boolInVec& boolInVec::operator =(boolInVec_arg vec)
{
	mData = vec.mData;
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE boolInVec& boolInVec::operator &=(boolInVec_arg vec)
{
	*this = *this & vec;
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE boolInVec& boolInVec::operator ^=(boolInVec_arg vec)
{
	*this = *this ^ vec;
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE boolInVec& boolInVec::operator |=(boolInVec_arg vec)
{
	*this = *this | vec;
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator ==(boolInVec_arg vec0, boolInVec_arg vec1)
{
	return boolInVec(vec0.getAsBool() == vec1.getAsBool());
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator !=(boolInVec_arg vec0, boolInVec_arg vec1)
{
	return !(vec0 == vec1);
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator &(boolInVec_arg vec0, boolInVec_arg vec1)
{
	return boolInVec(vec0.getAsBool() & vec1.getAsBool());
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator &&(boolInVec_arg vec0, boolInVec_arg vec1)
{
	return boolInVec(vec0.getAsBool() && vec1.getAsBool());
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator |(boolInVec_arg vec0, boolInVec_arg vec1)
{
	return boolInVec(vec0.getAsBool() | vec1.getAsBool());
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator ||(boolInVec_arg vec0, boolInVec_arg vec1)
{
	return boolInVec(vec0.getAsBool() || vec1.getAsBool());
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec operator ^(boolInVec_arg vec0, boolInVec_arg vec1)
{
	return boolInVec(vec0.getAsBool() ^ vec1.getAsBool());
}

SCE_VECTORMATH_ALWAYS_INLINE const boolInVec select(boolInVec_arg vec0, boolInVec_arg vec1, boolInVec_arg select_vec1)
{
	return (select_vec1.getAsBool() == 0) ? vec0 : vec1;
}

} // namespace Scalar
} // namespace Vectormath
} // namespace sce

#endif /* _PSP2_VECTORMATH_SCALAR_BOOLINVEC_H_ */
