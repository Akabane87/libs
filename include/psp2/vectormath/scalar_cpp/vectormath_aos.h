/**
 * \file vectormath_aos.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_VECTORMATH_SCALAR_AOS_CPP_H_
#define _PSP2_VECTORMATH_SCALAR_AOS_CPP_H_

#include <psp2/vectormath/scalar_cpp/internal/internal.h>

namespace sce {
namespace Vectormath {
namespace Scalar {

	// Forward Declarations
	class boolInVec;
	class floatInVec;

	/// @short
	/// Type used when passing <code>floatInVec</code> as a function argument.
	///
	/// Type used when passing <code>floatInVec</code> as a function argument.
	typedef const floatInVec SCE_VECTORMATH_SCALAR_AOS_FLOATINVEC_ARG	floatInVec_arg;

	/// @short
	/// Type used when passing <code>boolInVec</code> as a function argument.
	///
	/// Type used when passing <code>boolInVec</code> as a function argument.
	typedef const boolInVec SCE_VECTORMATH_SCALAR_AOS_BOOLINVEC_ARG		boolInVec_arg;

	/// @short
	/// Enum of valid Euler rotation orders.
	///
	/// Enum of valid Euler rotation orders.
	enum RotationOrder
	{
		kXYZ = 0,	//!< Indicates a rotation around the x axis first, followed by a rotation around the y axis, followed by a rotation around the z axis.
		kYZX = 1,	//!< Indicates a rotation around the y axis first, followed by a rotation around the z axis, followed by a rotation around the x axis.
		kZXY = 2,	//!< Indicates a rotation around the z axis first, followed by a rotation around the x axis, followed by a rotation around the y axis.
		kXZY = 3,	//!< Indicates a rotation around the x axis first, followed by a rotation around the z axis, followed by a rotation around the y axis.
		kYXZ = 4,	//!< Indicates a rotation around the y axis first, followed by a rotation around the x axis, followed by a rotation around the z axis.
		kZYX = 5	//!< Indicates a rotation around the z axis first, followed by a rotation around the y axis, followed by a rotation around the x axis.
	};

	namespace Aos {

		// Forward Declarations
		class Vector2;
		class Vector3;
		class Vector4;
		class Point3;
		class Quat;
		class Matrix2;
		class Matrix3;
		class Matrix4;
		class Transform3;

		/// @short
		/// Type used when passing <code>Vector2</code> as a function argument.
		///
		/// Type used when passing <code>Vector2</code> as a function argument.
		typedef const Vector2 SCE_VECTORMATH_SCALAR_AOS_VECTOR_ARG		Vector2_arg;

		/// @short
		/// Type used when passing <code>Vector3</code> as a function argument.
		///
		/// Type used when passing <code>Vector3</code> as a function argument.
		typedef const Vector3 SCE_VECTORMATH_SCALAR_AOS_VECTOR_ARG		Vector3_arg;

		/// @short
		/// Type used when passing <code>Vector4</code> as a function argument.
		///
		/// Type used when passing <code>Vector4</code> as a function argument.
		typedef const Vector4 SCE_VECTORMATH_SCALAR_AOS_VECTOR_ARG		Vector4_arg;

		/// @short
		/// Type used when passing <code>Point3</code> as a function argument.
		///
		/// Type used when passing <code>Point3</code> as a function argument.
		typedef const Point3 SCE_VECTORMATH_SCALAR_AOS_VECTOR_ARG		Point3_arg;

		/// @short
		/// Type used when passing <code>Quat</code> as a function argument.
		///
		/// Type used when passing <code>Quat</code> as a function argument.
		typedef const Quat SCE_VECTORMATH_SCALAR_AOS_VECTOR_ARG			Quat_arg;

		/// @short
		/// Type used when passing <code>Matrix2</code> as a function argument.
		///
		/// Type used when passing <code>Matrix2</code> as a function argument.
		typedef const Matrix2 SCE_VECTORMATH_SCALAR_AOS_MATRIX_ARG		Matrix2_arg;

		/// @short
		/// Type used when passing <code>Matrix3</code> as a function argument.
		///
		/// Type used when passing <code>Matrix3</code> as a function argument.
		typedef const Matrix3 SCE_VECTORMATH_SCALAR_AOS_MATRIX_ARG		Matrix3_arg;

		/// @short
		/// Type used when passing <code>Matrix4</code> as a function argument.
		///
		/// Type used when passing <code>Matrix4</code> as a function argument.
		typedef const Matrix4 SCE_VECTORMATH_SCALAR_AOS_MATRIX_ARG		Matrix4_arg;

		/// @short
		/// Type used when passing <code>Transform3</code> as a function argument.
		///
		/// Type used when passing <code>Transform3</code> as a function argument.
		typedef const Transform3 SCE_VECTORMATH_SCALAR_AOS_MATRIX_ARG	Transform3_arg;
	} // namespace Aos
} // namespace Scalar
} // namespace Vectormath
} // namespace sce

#include <psp2/vectormath/scalar_cpp/floatInVec.h>
#include <psp2/vectormath/scalar_cpp/boolInVec.h>

#define SCE_VECTORMATH_DEFAULT_SLERP_TOL_F  0.999f

#define SCE_VECTORMATH_PI_OVER_2_F  1.5707963267948966192313216916398f

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

/// @short
/// The namespace containing array-of-structures (AoS) classes.
///
/// The namespace containing array-of-structures (AoS) classes.
///
namespace Aos {

/// @short
/// A 2D vector in array-of-structures format
///
/// A class representing a 2D vector
/// stored in array-of-structures (AoS) format.
///
class Vector2
{
	float mX;
	float mY;
public:
	/// @short
	/// Default constructor; does no initialization
	///
	/// Default constructor; does no initialization.
	///
	SCE_VECTORMATH_ALWAYS_INLINE Vector2( );

	/// @short
	/// Construct a 2D vector from x and y elements
	///
	/// Construct a 2D vector containing the specified x and y elements.
	/// @param x   Scalar value
	/// @param y   Scalar value
	///
	SCE_VECTORMATH_INLINE Vector2( float x, float y );

	/// @short
	/// Construct a 2D vector from x and y elements
	///
	/// Construct a 2D vector containing the specified x and y elements.
	/// @param x   Scalar value
	/// @param y   Scalar value
	///
	SCE_VECTORMATH_INLINE Vector2( floatInVec_arg x, floatInVec_arg y );

	/// @short
	/// Set all elements of a 2D vector to the same scalar value
	///
	/// Construct a 2D vector with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Vector2( float scalar );

	/// @short
	/// Set all elements of a 2D vector to the same scalar value
	///
	/// Construct a 2D vector with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Vector2( floatInVec_arg scalar );

	/// @short
	/// Assign one 2D vector to another
	///
	/// Assign one 2D vector to another.
	/// @param vec   2D vector
	/// @return
	/// A reference to the resulting 2D vector
	///
	SCE_VECTORMATH_INLINE Vector2 & operator =( Vector2_arg vec );

	/// @short
	/// Set the x element of a 2D vector
	///
	/// Set the x element of a 2D vector to the specified scalar value.
	/// @param x   Scalar value
	/// @return
	/// A reference to the resulting 2D vector
	///
	SCE_VECTORMATH_INLINE Vector2 & setX( float x );

	/// @short
	/// Set the y element of a 2D vector
	///
	/// Set the y element of a 2D vector to the specified scalar value.
	/// @param y   Scalar value
	/// @return
	/// A reference to the resulting 2D vector
	///
	SCE_VECTORMATH_INLINE Vector2 & setY( float y );

	/// @short
	/// Set the x element of a 2D vector
	///
	/// Set the x element of a 2D vector to the specified scalar value.
	/// @param x   Scalar value
	/// @return
	/// A reference to the resulting 2D vector
	///
	SCE_VECTORMATH_INLINE Vector2 & setX( floatInVec_arg x );

	/// @short
	/// Set the y element of a 2D vector
	///
	/// Set the y element of a 2D vector to the specified scalar value.
	/// @param y   Scalar value
	/// @return
	/// A reference to the resulting 2D vector
	///
	SCE_VECTORMATH_INLINE Vector2 & setY( floatInVec_arg y );

	/// @short
	/// Get the x element of a 2D vector
	///
	/// Get the x element of a 2D vector.
	/// @return
	/// x element of a 2D vector
	///
	SCE_VECTORMATH_INLINE const floatInVec getX( ) const;

	/// @short
	/// Get the y element of a 2D vector
	///
	/// Get the y element of a 2D vector.
	/// @return
	/// y element of a 2D vector
	///
	SCE_VECTORMATH_INLINE const floatInVec getY( ) const;

	/// @short
	/// Set an x or y element of a 2D vector by index
	///
	/// Set an x or y element of a 2D vector by specifying an index of 0 or 1, respectively.
	/// @param idx   Index, expected in the range 0-1
	/// @param value   Scalar value
	/// @return
	/// A reference to the resulting 2D vector
	///
	SCE_VECTORMATH_INLINE Vector2 & setElem( int idx, float value );

	/// @short
	/// Set an x or y element of a 2D vector by index
	///
	/// Set an x or y element of a 2D vector by specifying an index of 0 or 1, respectively.
	/// @param idx   Index, expected in the range 0-1
	/// @param value   Scalar value
	/// @return
	/// A reference to the resulting 2D vector
	///
	SCE_VECTORMATH_INLINE Vector2 & setElem( int idx, floatInVec_arg value );

	/// @short
	/// Get an x or y element of a 2D vector by index
	///
	/// Get an x or y element of a 2D vector by specifying an index of 0 or 1, respectively.
	/// @param idx   Index, expected in the range 0-1
	/// @return
	/// Element selected by the specified index
	///
	SCE_VECTORMATH_INLINE const floatInVec getElem( int idx ) const;

	/// @short
	/// Subscripting operator to get an element
	///
	/// Subscripting operator invoked when applied to const Vector2.
	/// @param idx   Index, expected in the range 0-1
	/// @return
	/// Indexed element
	///
	SCE_VECTORMATH_INLINE const floatInVec operator []( int idx ) const;

	/// @short
	/// Add two 2D vectors
	///
	/// Add two 2D vectors.
	/// @param vec   2D vector
	/// @return
	/// Sum of the specified 2D vectors
	///
	SCE_VECTORMATH_INLINE const Vector2 operator +( Vector2_arg vec ) const;

	/// @short
	/// Subtract a 2D vector from another 2D vector
	///
	/// Subtract a 2D vector from another 2D vector.
	/// @param vec   2D vector
	/// @return
	/// Difference of the specified 2D vectors
	///
	SCE_VECTORMATH_INLINE const Vector2 operator -( Vector2_arg vec ) const;

	/// @short
	/// Multiply a 2D vector by a scalar
	///
	/// Multiply a 2D vector by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified 2D vector and scalar
	///
	SCE_VECTORMATH_INLINE const Vector2 operator *( float scalar ) const;

	/// @short
	/// Divide a 3D vector by a scalar
	///
	/// Divide a 3D vector by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Quotient of the specified 3D vector and scalar
	///
	SCE_VECTORMATH_INLINE const Vector2 operator /( float scalar ) const;

	/// @short
	/// Multiply a 2D vector by a scalar
	///
	/// Multiply a 2D vector by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified 2D vector and scalar
	///
	SCE_VECTORMATH_INLINE const Vector2 operator *( floatInVec_arg scalar ) const;

	/// @short
	/// Divide a 2D vector by a scalar
	///
	/// Divide a 2D vector by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Quotient of the specified 2D vector and scalar
	///
	SCE_VECTORMATH_INLINE const Vector2 operator /( floatInVec_arg scalar ) const;

	/// @short
	/// Perform compound assignment and addition with a 2D vector
	///
	/// Perform compound assignment and addition with a 2D vector.
	/// @param vec   2D vector
	/// @return
	/// A reference to the resulting 2D vector
	///
	SCE_VECTORMATH_INLINE Vector2 & operator +=( Vector2_arg vec );

	/// @short
	/// Perform compound assignment and subtraction with a 2D vector
	///
	/// Perform compound assignment and subtraction with a 2D vector.
	/// @param vec   2D vector
	/// @return
	/// A reference to the resulting 2D vector
	///
	SCE_VECTORMATH_INLINE Vector2 & operator -=( Vector2_arg vec );

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 2D vector
	///
	SCE_VECTORMATH_INLINE Vector2 & operator *=( float scalar );

	/// @short
	/// Perform compound assignment and division by a scalar
	///
	/// Perform compound assignment and division by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 2D vector
	///
	SCE_VECTORMATH_INLINE Vector2 & operator /=( float scalar );

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 2D vector
	///
	SCE_VECTORMATH_INLINE Vector2 & operator *=( floatInVec_arg scalar );

	/// @short
	/// Perform compound assignment and division by a scalar
	///
	/// Perform compound assignment and division by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 2D vector
	///
	SCE_VECTORMATH_INLINE Vector2 & operator /=( floatInVec_arg scalar );

	/// @short
	/// Negate all elements of a 2D vector
	///
	/// Negate all elements of a 2D vector.
	/// @return
	/// 2D vector containing negated elements of the specified 2D vector
	///
	SCE_VECTORMATH_INLINE const Vector2 operator -( ) const;

	/// @short
	/// Construct x axis
	///
	/// Construct a 2D vector equal to (1,0).
	/// @return
	/// The constructed 2D vector
	///
	static SCE_VECTORMATH_INLINE const Vector2 xAxis( );

	/// @short
	/// Construct y axis
	///
	/// Construct a 2D vector equal to (0,1).
	/// @return
	/// The constructed 2D vector
	///
	static SCE_VECTORMATH_INLINE const Vector2 yAxis( );

	/// @short
	/// Construct zero
	///
	/// Construct a 2D vector equal to (0,0).
	/// @return
	/// The constructed 2D vector
	///
	static SCE_VECTORMATH_INLINE const Vector2 zero();
};

/// @name 2D Vector Functions
/// @{

/// @short
/// Multiply a 2D vector by a scalar
///
/// Multiply a 2D vector by a scalar.
/// @param scalar   Scalar value
/// @param vec   2D vector
/// @return
/// Scalar product of <code><i>vec</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Vector2 operator *( float scalar, Vector2_arg vec );

/// @short
/// Multiply a 2D vector by a scalar
///
/// Multiply a 2D vector by a scalar.
/// @param scalar   Scalar value
/// @param vec   2D vector
/// @return
/// Scalar product of <code><i>vec</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Vector2 operator *( floatInVec_arg scalar, Vector2_arg vec );

/// @short
/// Multiply two 2D vectors per element
///
/// Multiply two 2D vectors element by element.
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// 2D vector in which each element is the product of the corresponding elements of the specified 2D vectors
///
SCE_VECTORMATH_INLINE const Vector2 mulPerElem( Vector2_arg vec0, Vector2_arg vec1 );

/// @short
/// Divide two 2D vectors per element
///
/// Divide two 2D vectors element by element.
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// 2D vector in which each element is the quotient of the corresponding elements of the specified 2D vectors
///
SCE_VECTORMATH_INLINE const Vector2 divPerElem( Vector2_arg vec0, Vector2_arg vec1 );

/// @short
/// Compute the reciprocal of a 2D vector per element
///
/// Create a 2D vector in which each element is the reciprocal of the corresponding element of the specified 2D vector.
/// @param vec   2D vector
/// @return
/// 2D vector in which each element is the reciprocal of the corresponding element of the specified 2D vector
///
SCE_VECTORMATH_INLINE const Vector2 recipPerElem( Vector2_arg vec );

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Compute the square root of a 2D vector per element
///
/// Create a 2D vector in which each element is the square root of the corresponding element of the specified 2D vector.
/// @param vec   2D vector
/// @return
/// 2D vector in which each element is the square root of the corresponding element of the specified 2D vector
///
SCE_VECTORMATH_INLINE const Vector2 sqrtPerElem( Vector2_arg vec );

/// @short
/// Compute the reciprocal square root of a 2D vector per element
///
/// Create a 2D vector in which each element is the reciprocal square root of the corresponding element of the specified 2D vector.
/// @param vec   2D vector
/// @return
/// 2D vector in which each element is the reciprocal square root of the corresponding element of the specified 2D vector
///
SCE_VECTORMATH_INLINE const Vector2 rsqrtPerElem( Vector2_arg vec );

/// @short
/// Compute the absolute value of a 2D vector per element
///
/// Compute the absolute value of each element of a 2D vector.
/// @param vec   2D vector
/// @return
/// 2D vector in which each element is the absolute value of the corresponding element of vec
///
SCE_VECTORMATH_INLINE const Vector2 absPerElem( Vector2_arg vec );

/// @short
/// Clamp each element of a 2D vector between corresponding elements specifying minimum and maximum values
///
/// For each element, create a value that is clamped between the value of the corresponding elements of <code><i>clampMin</i></code> and <code><i>clampMax</i></code>.
/// @param vec		2D vector to be clamped
/// @param clampMin	2D vector containing the minimum values of the range
/// @param clampMax	2D vector containing the maximum values of the range
/// @return
/// 2D vector in which each element has its value clamped in the range specified by the corresponding element of <code><i>clampMin</i></code> and the corresponding element of <code><i>clampMax</i></code>
/// @note
/// Result is undefined if any minimum element is greater than the corresponding maximum element.
///
SCE_VECTORMATH_INLINE const Vector2 clampPerElem(Vector2_arg vec, Vector2_arg clampMin, Vector2_arg clampMax);

/// @short
/// Copy sign from one 2D vector to another, per element
///
/// For each element, create a value composed of the magnitude of <code><i>vec0</i></code> and the sign of <code><i>vec1</i></code>.
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// 2D vector in which each element has the magnitude of the corresponding element of <code><i>vec0</i></code> and the sign of the corresponding element of <code><i>vec1</i></code>
///
SCE_VECTORMATH_INLINE const Vector2 copySignPerElem( Vector2_arg vec0, Vector2_arg vec1 );

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Maximum of two 2D vectors per element
///
/// Create a 2D vector in which each element is the maximum of the corresponding elements of the specified 2D vectors.
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// 2D vector in which each element is the maximum of the corresponding elements of the specified 2D vectors
///
SCE_VECTORMATH_INLINE const Vector2 maxPerElem( Vector2_arg vec0, Vector2_arg vec1 );

/// @short
/// Minimum of two 2D vectors per element
///
/// Create a 2D vector in which each element is the minimum of the corresponding elements of two specified 2D vectors.
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// 2D vector in which each element is the minimum of the corresponding elements of the specified 2D vectors
///
SCE_VECTORMATH_INLINE const Vector2 minPerElem( Vector2_arg vec0, Vector2_arg vec1 );

/// @short
/// Maximum element of a 2D vector
///
/// Compute the maximum value of all elements of a 2D vector.
/// @param vec   2D vector
/// @return
/// Maximum value of all elements of <code><i>vec</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec maxElem( Vector2_arg vec );

/// @short
/// Minimum element of a 2D vector
///
/// Compute the minimum value of all elements of a 2D vector.
/// @param vec   2D vector
/// @return
/// Minimum value of all elements of <code><i>vec</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec minElem( Vector2_arg vec );

/// @short
/// All of the elements of the first 2D vector are less than the corresponding element in the second
///
/// All of the elements of the first 2D vector are less than the corresponding element in the second
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// True if all elements of <code><i>vec0</i></code> are less than the corresponding element in <code><i>vec1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemLessThan(Vector2_arg vec0, Vector2_arg vec1);

/// @short
/// All of the elements of the first 2D vector are less than or equal to the corresponding element in the second
///
/// All of the elements of the first 2D vector are less than or equal to the corresponding element in the second
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// True if all elements of <code><i>vec0</i></code> are less than or equal to the corresponding element in <code><i>vec1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemLessThanOrEqual(Vector2_arg vec0, Vector2_arg vec1);

/// @short
/// All of the elements of the first 2D vector are greater than the corresponding element in the second
///
/// All of the elements of the first 2D vector are greater than the corresponding element in the second
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// True if all elements of <code><i>vec0</i></code> are greater than the corresponding element in <code><i>vec1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThan(Vector2_arg vec0, Vector2_arg vec1);

/// @short
/// All of the elements of the first 2D vector are greater than or equal to the corresponding element in the second
///
/// All of the elements of the first 2D vector are greater than or equal to the corresponding element in the second
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// True if all elements of <code><i>vec0</i></code> are greater than or equal to the corresponding element in <code><i>vec1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThanOrEqual(Vector2_arg vec0, Vector2_arg vec1);

/// @short
/// Compute the sum of all elements of a 2D vector
///
/// Compute the sum of all elements of a 2D vector.
/// @param vec   2D vector
/// @return
/// Sum of all elements of <code><i>vec</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec sum( Vector2_arg vec );

/// @short
/// Compute the dot product of two 2D vectors
///
/// Compute the dot product of two 2D vectors.
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// Dot product of the specified 2D vectors
///
SCE_VECTORMATH_INLINE const floatInVec dot( Vector2_arg vec0, Vector2_arg vec1 );

/// @short
/// Compute the square of the length of a 2D vector
///
/// Compute the square of the length of a 2D vector.
/// @param vec   2D vector
/// @return
/// Square of the length of the specified 2D vector
///
SCE_VECTORMATH_INLINE const floatInVec lengthSqr( Vector2_arg vec );

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Compute the length of a 2D vector
///
/// Compute the length of a 2D vector.
/// @param vec   2D vector
/// @return
/// Length of the specified 2D vector
///
SCE_VECTORMATH_INLINE const floatInVec length( Vector2_arg vec );

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Compute the determinant of the matrix created from two 2D vectors columns
///
/// Compute the determinant of the matrix created from two 2D vectors columns
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// Determinant between two 2D vectors
///
SCE_VECTORMATH_INLINE const floatInVec determinant( Vector2_arg vec0, Vector2_arg vec1 );

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Compute the angle of a 2D vector against the x-axis
///
/// Compute the angle of a 2D vector against the x-axis.
/// @param vec   2D vector
/// @return
/// Angle of the specified 2D vector against the x-axis
///
SCE_VECTORMATH_INLINE const floatInVec angle( Vector2_arg vec );

/// @short
/// Compute the angle between two 2D vectors
///
/// Compute the angle between two 2D vectors.
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// Angle between two specified 2D vectors
///
SCE_VECTORMATH_INLINE const floatInVec angleBetween( Vector2_arg vec0, Vector2_arg vec1 );

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Compute a 2D vector perpendicular to the 2D vector
///
/// Compute a 2D vector perpendicular to the 2D vector.
/// @param vec   2D vector
/// @return
/// A 2D vector perpendicular to the specified 2D vector
///
SCE_VECTORMATH_INLINE const Vector2 perp( Vector2_arg vec );

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Rotate a 2D vector
///
/// Rotate a 2D vector by a specified angle (radians)
/// @param rot   Angle (radians)
/// @param vec   2D vector
/// @return
/// The rotated 2D vector
///
SCE_VECTORMATH_INLINE const Vector2 rotate(floatInVec_arg rot, Vector2_arg vec);

/// @short
/// Normalize a 2D vector
///
/// Compute a normalized 2D vector.
/// @param vec   2D vector
/// @return
/// The specified 2D vector scaled to unit length
/// @note
/// The result is unpredictable when all elements of vec are at or near zero.
///
SCE_VECTORMATH_INLINE const Vector2 normalize( Vector2_arg vec );

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Linear interpolation between two 2D vectors
///
/// Linearly interpolate between two 2D vectors.
/// @param t   Interpolation parameter
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// Interpolated 2D vector
/// @note
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Vector2 lerp( float t, Vector2_arg vec0, Vector2_arg vec1 );

/// @short
/// Linear interpolation between two 2D vectors
///
/// Linearly interpolate between two 2D vectors.
/// @param t   Interpolation parameter
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @return
/// Interpolated 2D vector
/// @note
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Vector2 lerp( floatInVec_arg t, Vector2_arg vec0, Vector2_arg vec1 );

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Spherical linear interpolation between two 2D vectors
///
/// Perform spherical linear interpolation between two 2D vectors.
/// @param t   Interpolation parameter
/// @param unitVec0   2D vector, expected to be unit-length
/// @param unitVec1   2D vector, expected to be unit-length
/// @param tol        A tolerance value for detection of co-linear vectors
/// @return
/// Interpolated 2D vector
/// @note
/// The result is unpredictable if the vectors point in opposite directions.
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Vector2 slerp( float t, Vector2_arg unitVec0, Vector2_arg unitVec1, float tol = SCE_VECTORMATH_DEFAULT_SLERP_TOL_F );

/// @short
/// Spherical linear interpolation between two 2D vectors
///
/// Perform spherical linear interpolation between two 2D vectors.
/// @param t   Interpolation parameter
/// @param unitVec0   2D vector, expected to be unit-length
/// @param unitVec1   2D vector, expected to be unit-length
/// @param tol        A tolerance value for detection of co-linear vectors
/// @return
/// Interpolated 2D vector
/// @note
/// The result is unpredictable if the vectors point in opposite directions.
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Vector2 slerp( floatInVec_arg t, Vector2_arg unitVec0, Vector2_arg unitVec1, floatInVec_arg tol = floatInVec(SCE_VECTORMATH_DEFAULT_SLERP_TOL_F) );

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Conditionally select between two 2D vectors
///
/// Conditionally select one of the 2D vector arguments.
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @param select1   False selects the <code><i>vec0</i></code> argument; true selects the <code><i>vec1</i></code> argument
/// @return
/// Equal to <code><i>vec0</i></code> if <code><i>select1</i></code> is false, or to <code><i>vec1</i></code> if <code><i>select1</i></code> is true
///
SCE_VECTORMATH_INLINE const Vector2 select( Vector2_arg vec0, Vector2_arg vec1, bool select1 );

/// @short
/// Conditionally select between two 2D vectors
///
/// Conditionally select one of the 2D vector arguments.
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @param select1   False selects the <code><i>vec0</i></code> argument; true selects the <code><i>vec1</i></code> argument
/// @return
/// Equal to <code><i>vec0</i></code> if <code><i>select1</i></code> is false, or to <code><i>vec1</i></code> if <code><i>select1</i></code> is true
/// @note
/// This function uses a conditional select instruction to avoid a branch.
///
SCE_VECTORMATH_INLINE const Vector2 select( Vector2_arg vec0, Vector2_arg vec1, boolInVec_arg select1 );

/// @short
/// Load x and y elements from the first two words of a float array.
///
///
/// Load x and y elements from the first two words of a float array.
///
/// @param vec   An output 2D vector
/// @param fptr  Array of float from which x and y will be loaded
///
SCE_VECTORMATH_INLINE void loadXY( Vector2& vec, const float * fptr );

/// @short
/// Store x and y elements of a 2D vector in the first two words of a float array.
///
///
/// Store x and y elements of a 2D vector in the first two words of a float array.
/// Memory area of previous 16 bytes and next 32 bytes from <code><i>fptr</i></code> might be accessed
///
/// @param vec   2D vector
/// @param fptr  An output array of float in which x and y will be stored
///
SCE_VECTORMATH_INLINE void storeXY( Vector2_arg vec, float * fptr );

/// @short
/// Load four two-float 2D vectors from the first eight floats of a float array.
///
///
/// Load four two-float 2D vectors from the first eight floats of a float array.
///
/// @param vec0		First 2D vector in the float array
/// @param vec1		Second 2D vector in the float array
/// @param vec2		Third 2D vector in the float array
/// @param vec3		Fourth 2D vector in the float array
/// @param fptr     Pointer to a float array from which the four two-float 2D vectors will be loaded
///
SCE_VECTORMATH_INLINE void loadXYArray( Vector2& vec0, Vector2& vec1, Vector2& vec2, Vector2& vec3, const float * fptr );

/// @short
/// Store four two-float 2D vectors in the first eight floats of a float array.
///
///
/// Store four two-float 2D vectors in the first eight floats of a float array.
///
/// @param vec0		First 2D vector in the float array
/// @param vec1		Second 2D vector in the float array
/// @param vec2		Third 2D vector in the float array
/// @param vec3		Fourth 2D vector in the float array
/// @param fptr     Pointer to a float array in which the four two-float 2D vectors will be stored
///
SCE_VECTORMATH_INLINE void storeXYArray( Vector2_arg vec0, Vector2_arg vec1, Vector2_arg vec2, Vector2_arg vec3, float * fptr );

/// @short
/// Load eight two-half-floats as 2D vectors
///
/// Load eight two-half-floats as 2D vectors.
/// The input is {x0,y0,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7}.
/// @param vec0   An output 2D vector
/// @param vec1   An output 2D vector
/// @param vec2   An output 2D vector
/// @param vec3   An output 2D vector
/// @param vec4   An output 2D vector
/// @param vec5   An output 2D vector
/// @param vec6   An output 2D vector
/// @param vec7   An output 2D vector
/// @param hfptr  Array of uint16_t containing 16 half-floats
/// @note
/// This transformation may not support either denormalized numbers or NaNs.
///
SCE_VECTORMATH_INLINE void loadHalfFloats( Vector2 & vec0, Vector2 & vec1, Vector2 & vec2, Vector2 & vec3, Vector2 & vec4, Vector2 & vec5, Vector2 & vec6, Vector2 & vec7, const uint16_t * hfptr );

/// @short
/// Load two half-floats as a 2D vector
///
/// Load two half-floats as a 2D vector.
/// @param vec   An output 2D vector
/// @param hfptr Array of two half-floats
/// @note
/// This transformation may not support either denormalized numbers or NaNs.
///
SCE_VECTORMATH_INLINE void loadHalfFloats( Vector2 & vec, const uint16_t * hfptr );

/// @short
/// Store eight 2D vectors as half-floats
///
/// Store eight 2D vectors as half-floats.
/// The output is {x0,y0,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7}.
/// @param vec0   2D vector
/// @param vec1   2D vector
/// @param vec2   2D vector
/// @param vec3   2D vector
/// @param vec4   2D vector
/// @param vec5   2D vector
/// @param vec6   2D vector
/// @param vec7   2D vector
/// @param hfptr  An output array of uint16_t containing 16 half-floats
/// @note
/// This transformation may not support either denormalized numbers or NaNs.
///
SCE_VECTORMATH_INLINE void storeHalfFloats( Vector2_arg vec0, Vector2_arg vec1, Vector2_arg vec2, Vector2_arg vec3, Vector2_arg vec4, Vector2_arg vec5, Vector2_arg vec6, Vector2_arg vec7, uint16_t * hfptr );

/// @short
/// Store a 2D vector as half-floats. The memory area of the previous 16 bytes and the next 32 bytes from <code><i>hfptr</i></code> might be accessed.
///
/// Store a 2D vector in a uint16_t array of half-float values.
/// @param vec   2D vector
/// @param hfptr   An output array of two half-floats
/// @note
/// This transformation does not support either denormalized numbers or NaNs. The memory area of the previous 16 bytes and the next 32 bytes from <code><i>hfptr</i></code> might be accessed.
///
SCE_VECTORMATH_INLINE void storeHalfFloats( Vector2_arg vec, uint16_t * hfptr );

#ifdef SCE_VECTORMATH_DEBUG

/// @short
/// Print a 2D vector
///
/// Print a 2D vector.
/// @param vec   2D vector
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print( Vector2_arg vec );

/// @short
/// Print a 2D vector and an associated string identifier
///
/// Print a 2D vector and an associated string identifier.
/// @param vec   2D vector
/// @param name   String printed with the 2D vector
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print( Vector2_arg vec, const char * name );

#endif //SCE_VECTORMATH_DEBUG

/// @short
/// A 3D vector in array-of-structures format
///
/// A class representing a 3D vector
/// stored in array-of-structures (AoS) format.
///
class Vector3
{
	float mX;
	float mY;
	float mZ;
#if !defined(__GNUC__)
	float d;
#endif
public:
	/// @short
	/// Default constructor; does no initialization
	///
	/// Default constructor; does no initialization.
	///
	SCE_VECTORMATH_ALWAYS_INLINE Vector3();

	/// @short
	/// Construct a 3D vector from x, y, and z elements
	///
	/// Construct a 3D vector containing the specified x, y, and z elements.
	/// @param x   Scalar value
	/// @param y   Scalar value
	/// @param z   Scalar value
	///
	SCE_VECTORMATH_INLINE Vector3(float x, float y, float z);

	/// @short
	/// Construct a 3D vector from x, y, and z elements
	///
	/// Construct a 3D vector containing the specified x, y, and z elements.
	/// @param x   Scalar value
	/// @param y   Scalar value
	/// @param z   Scalar value
	///
	SCE_VECTORMATH_INLINE Vector3(floatInVec_arg x, floatInVec_arg y, floatInVec_arg z);

	/// @short
	/// Construct a 3D vector from a 2D vector and a scalar
	///
	/// Construct a 3D vector with the x and y elements of the specified 2D vector and with the z element set to the specified scalar.
	/// @param xy   2D vector
	/// @param z   Scalar value
	///
	SCE_VECTORMATH_INLINE Vector3(Vector2_arg xy, float z);

	/// @short
	/// Construct a 3D vector from a 2D vector and a scalar
	///
	/// Construct a 3D vector with the x and y elements of the specified 2D vector and with the z element set to the specified scalar.
	/// @param xy   2D vector
	/// @param z   Scalar value
	///
	SCE_VECTORMATH_INLINE Vector3(Vector2_arg xy, floatInVec_arg z);

	/// @short
	/// Copy elements from a 3D point into a 3D vector
	///
	/// Construct a 3D vector containing the x, y, and z elements of the specified 3D point.
	/// @param pnt   3D point
	///
	explicit SCE_VECTORMATH_INLINE Vector3(Point3_arg pnt);

	/// @short
	/// Set all elements of a 3D vector to the same scalar value
	///
	/// Construct a 3D vector with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Vector3(float scalar);

	/// @short
	/// Set all elements of a 3D vector to the same scalar value
	///
	/// Construct a 3D vector with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Vector3(floatInVec_arg scalar);

	/// @short
	/// Assign one 3D vector to another
	///
	/// Assign one 3D vector to another.
	/// @param vec   3D vector
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& operator =(Vector3_arg vec);

	/// @short
	/// Set the x and y elements of a 3D vector
	///
	/// Set the x and y elements to those of the specified 3D vector.
	/// @param vec   2D vector
	/// @return
	/// A reference to the resulting 3D vector
	/// @note
	/// This function does not change the z element.
	///
	SCE_VECTORMATH_INLINE Vector3& setXY(Vector2_arg vec);

	/// @short
	/// Get the x and y elements of a 3D vector
	///
	/// Extract a 3D vector's x and y elements into a 2D vector.
	/// @return
	/// 2D vector containing x and y elements
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector2 getXY() const;

	/// @short
	/// Set the x element of a 3D vector
	///
	/// Set the x element of a 3D vector to the specified scalar value.
	/// @param x   Scalar value
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& setX(float x);

	/// @short
	/// Set the y element of a 3D vector
	///
	/// Set the y element of a 3D vector to the specified scalar value.
	/// @param y   Scalar value
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& setY(float y);

	/// @short
	/// Set the z element of a 3D vector
	///
	/// Set the z element of a 3D vector to the specified scalar value.
	/// @param z   Scalar value
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& setZ(float z);

	/// @short
	/// Set the x element of a 3D vector
	///
	/// Set the x element of a 3D vector to the specified scalar value.
	/// @param x   Scalar value
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& setX(floatInVec_arg x);

	/// @short
	/// Set the y element of a 3D vector
	///
	/// Set the y element of a 3D vector to the specified scalar value.
	/// @param y   Scalar value
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& setY(floatInVec_arg y);

	/// @short
	/// Set the z element of a 3D vector
	///
	/// Set the z element of a 3D vector to the specified scalar value.
	/// @param z   Scalar value
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& setZ(floatInVec_arg z);

	/// @short
	/// Get the x element of a 3D vector
	///
	/// Get the x element of a 3D vector.
	/// @return
	/// x element of a 3D vector
	///
	SCE_VECTORMATH_INLINE const floatInVec getX() const;

	/// @short
	/// Get the y element of a 3D vector
	///
	/// Get the y element of a 3D vector.
	/// @return
	/// y element of a 3D vector
	///
	SCE_VECTORMATH_INLINE const floatInVec getY() const;

	/// @short
	/// Get the z element of a 3D vector
	///
	/// Get the z element of a 3D vector.
	/// @return
	/// z element of a 3D vector
	///
	SCE_VECTORMATH_INLINE const floatInVec getZ() const;

	/// @short
	/// Set an x, y, or z element of a 3D vector by index
	///
	/// Set an x, y, or z element of a 3D vector by specifying an index of 0, 1, or 2, respectively.
	/// @param idx   Index, expected in the range 0-2
	/// @param value   Scalar value
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& setElem(int idx, float value);

	/// @short
	/// Set an x, y, or z element of a 3D vector by index
	///
	/// Set an x, y, or z element of a 3D vector by specifying an index of 0, 1, or 2, respectively.
	/// @param idx   Index, expected in the range 0-2
	/// @param value   Scalar value
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& setElem(int idx, floatInVec_arg value);

	/// @short
	/// Get an x, y, or z element of a 3D vector by index
	///
	/// Get an x, y, or z element of a 3D vector by specifying an index of 0, 1, or 2, respectively.
	/// @param idx   Index, expected in the range 0-2
	/// @return
	/// Element selected by the specified index
	///
	SCE_VECTORMATH_INLINE const floatInVec getElem(int idx) const;

	/// @short
	/// Subscripting operator to set or get an element
	///
	/// Subscripting operator invoked when applied to non-const Vector3.
	/// @param idx   Index, expected in the range 0-2
	/// @return
	/// A reference to the selected element
	///
	SCE_VECTORMATH_INLINE float & operator []( int idx );

	/// @short
	/// Subscripting operator to get an element
	///
	/// Subscripting operator invoked when applied to const Vector3.
	/// @param idx   Index, expected in the range 0-2
	/// @return
	/// Indexed element
	///
	SCE_VECTORMATH_INLINE const floatInVec operator [](int idx) const;

	/// @short
	/// Add two 3D vectors
	///
	/// Add two 3D vectors.
	/// @param vec   3D vector
	/// @return
	/// Sum of the specified 3D vectors
	///
	SCE_VECTORMATH_INLINE const Vector3 operator +(Vector3_arg vec) const;

	/// @short
	/// Subtract a 3D vector from another 3D vector
	///
	/// Subtract a 3D vector from another 3D vector.
	/// @param vec   3D vector
	/// @return
	/// Difference of the specified 3D vectors
	///
	SCE_VECTORMATH_INLINE const Vector3 operator -(Vector3_arg vec) const;

	/// @short
	/// Add a 3D vector to a 3D point
	///
	/// Add a 3D vector to a 3D point.
	/// @param pnt   3D point
	/// @return
	/// Sum of the specified 3D vector and 3D point
	///
	SCE_VECTORMATH_INLINE const Point3 operator +(Point3_arg pnt) const;

	/// @short
	/// Multiply a 3D vector by a scalar
	///
	/// Multiply a 3D vector by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified 3D vector and scalar
	///
	SCE_VECTORMATH_INLINE const Vector3 operator *(float scalar) const;

	/// @short
	/// Divide a 3D vector by a scalar
	///
	/// Divide a 3D vector by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Quotient of the specified 3D vector and scalar
	///
	SCE_VECTORMATH_INLINE const Vector3 operator /(float scalar) const;

	/// @short
	/// Multiply a 3D vector by a scalar
	///
	/// Multiply a 3D vector by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified 3D vector and scalar
	///
	SCE_VECTORMATH_INLINE const Vector3 operator *(floatInVec_arg scalar) const;

	/// @short
	/// Divide a 3D vector by a scalar
	///
	/// Divide a 3D vector by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Quotient of the specified 3D vector and scalar
	///
	SCE_VECTORMATH_INLINE const Vector3 operator /(floatInVec_arg scalar) const;

	/// @short
	/// Perform compound assignment and addition with a 3D vector
	///
	/// Perform compound assignment and addition with a 3D vector.
	/// @param vec   3D vector
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& operator +=(Vector3_arg vec);

	/// @short
	/// Perform compound assignment and subtraction by a 3D vector
	///
	/// Perform compound assignment and subtraction by a 3D vector.
	/// @param vec   3D vector
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& operator -=(Vector3_arg vec);

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& operator *=(float scalar);

	/// @short
	/// Perform compound assignment and division by a scalar
	///
	/// Perform compound assignment and division by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& operator /=(float scalar);

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& operator *=(floatInVec_arg scalar);

	/// @short
	/// Perform compound assignment and division by a scalar
	///
	/// Perform compound assignment and division by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 3D vector
	///
	SCE_VECTORMATH_INLINE Vector3& operator /=(floatInVec_arg scalar);

	/// @short
	/// Negate all elements of a 3D vector
	///
	/// Negate all elements of a 3D vector.
	/// @return
	/// 3D vector containing negated elements of the specified 3D vector
	///
	SCE_VECTORMATH_INLINE const Vector3 operator -() const;

	/// @short
	/// Construct x axis
	///
	/// Construct a 3D vector equal to (1,0,0).
	/// @return
	/// The constructed 3D vector
	///
	static SCE_VECTORMATH_INLINE const Vector3 xAxis();

	/// @short
	/// Construct y axis
	///
	/// Construct a 3D vector equal to (0,1,0).
	/// @return
	/// The constructed 3D vector
	///
	static SCE_VECTORMATH_INLINE const Vector3 yAxis();

	/// @short
	/// Construct z axis
	///
	/// Construct a 3D vector equal to (0,0,1).
	/// @return
	/// The constructed 3D vector
	///
	static SCE_VECTORMATH_INLINE const Vector3 zAxis();

	/// @short
	/// Construct zero
	///
	/// Construct a 3D vector equal to (0,0,0).
	/// @return
	/// The constructed 3D vector
	///
	static SCE_VECTORMATH_INLINE const Vector3 zero();

}
#if defined(__GNUC__)
__attribute__ ((aligned(16)))
#endif
;

/// @name 3D Vector Functions
/// @{

/// @short
/// Multiply a 3D vector by a scalar
///
/// Multiply a 3D vector by a scalar.
/// @param scalar   Scalar value
/// @param vec   3D vector
/// @return
/// Scalar product of <code><i>vec</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Vector3 operator *(float scalar, Vector3_arg vec);

/// @short
/// Multiply a 3D vector by a scalar
///
/// Multiply a 3D vector by a scalar.
/// @param scalar   Scalar value
/// @param vec   3D vector
/// @return
/// Scalar product of <code><i>vec</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Vector3 operator *(floatInVec_arg scalar, Vector3_arg vec);

/// @short
/// Multiply two 3D vectors per element
///
/// Multiply two 3D vectors element by element.
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// 3D vector in which each element is the product of the corresponding elements of the specified 3D vectors
///
SCE_VECTORMATH_INLINE const Vector3 mulPerElem(Vector3_arg vec0, Vector3_arg vec1);

/// @short
/// Divide two 3D vectors per element
///
/// Divide two 3D vectors element by element.
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// 3D vector in which each element is the quotient of the corresponding elements of the specified 3D vectors
/// @note
/// Floating-point behavior matches standard library function <code>divf4</code>.
///
SCE_VECTORMATH_INLINE const Vector3 divPerElem(Vector3_arg vec0, Vector3_arg vec1);

/// @short
/// Compute the reciprocal of a 3D vector per element
///
/// Create a 3D vector in which each element is the reciprocal of the corresponding element of the specified 3D vector.
/// @param vec   3D vector
/// @return
/// 3D vector in which each element is the reciprocal of the corresponding element of the specified 3D vector
/// @note
/// Floating-point behavior matches standard library function <code>recipf4</code>.
///
SCE_VECTORMATH_INLINE const Vector3 recipPerElem(Vector3_arg vec);

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Compute the square root of a 3D vector per element
///
/// Create a 3D vector in which each element is the square root of the corresponding element of the specified 3D vector.
/// @param vec   3D vector
/// @return
/// 3D vector in which each element is the square root of the corresponding element of the specified 3D vector
/// @note
/// Floating-point behavior matches standard library function <code>sqrtf4</code>.
///
SCE_VECTORMATH_INLINE const Vector3 sqrtPerElem(Vector3_arg vec);

/// @short
/// Compute the reciprocal square root of a 3D vector per element
///
/// Create a 3D vector in which each element is the reciprocal square root of the corresponding element of the specified 3D vector.
/// @param vec   3D vector
/// @return
/// 3D vector in which each element is the reciprocal square root of the corresponding element of the specified 3D vector
/// @note
/// Floating-point behavior matches standard library function <code>rsqrtf4</code>.
///
SCE_VECTORMATH_INLINE const Vector3 rsqrtPerElem(Vector3_arg vec);

/// @short
/// Compute the absolute value of a 3D vector per element
///
/// Compute the absolute value of each element of a 3D vector.
/// @param vec   3D vector
/// @return
/// 3D vector in which each element is the absolute value of the corresponding element of vec
///
SCE_VECTORMATH_INLINE const Vector3 absPerElem(Vector3_arg vec);

/// @short
/// Clamp each element of a 3D vector between corresponding elements specifying minimum and maximum values
///
/// For each element, create a value that is clamped between the value of the corresponding elements of <code><i>clampMin</i></code> and <code><i>clampMax</i></code>.
/// @param vec		3D vector to be clamped
/// @param clampMin	3D vector containing the minimum values of the range
/// @param clampMax	3D vector containing the maximum values of the range
/// @return
/// 3D vector in which each element has its value clamped in the range specified by the corresponding element of <code><i>clampMin</i></code> and the corresponding element of <code><i>clampMax</i></code>
/// @note
/// Result is undefined if any minimum element is greater than the corresponding maximum element.
///
SCE_VECTORMATH_INLINE const Vector3 clampPerElem(Vector3_arg vec, Vector3_arg clampMin, Vector3_arg clampMax);

/// @short
/// Copy sign from one 3D vector to another, per element
///
/// For each element, create a value composed of the magnitude of <code><i>vec0</i></code> and the sign of <code><i>vec1</i></code>.
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// 3D vector in which each element has the magnitude of the corresponding element of <code><i>vec0</i></code> and the sign of the corresponding element of <code><i>vec1</i></code>
///
SCE_VECTORMATH_INLINE const Vector3 copySignPerElem(Vector3_arg vec0, Vector3_arg vec1);

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Maximum of two 3D vectors per element
///
/// Create a 3D vector in which each element is the maximum of the corresponding elements of the specified 3D vectors.
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// 3D vector in which each element is the maximum of the corresponding elements of the specified 3D vectors
///
SCE_VECTORMATH_INLINE const Vector3 maxPerElem(Vector3_arg vec0, Vector3_arg vec1);

/// @short
/// Minimum of two 3D vectors per element
///
/// Create a 3D vector in which each element is the minimum of the corresponding elements of two specified 3D vectors.
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// 3D vector in which each element is the minimum of the corresponding elements of the specified 3D vectors
///
SCE_VECTORMATH_INLINE const Vector3 minPerElem(Vector3_arg vec0, Vector3_arg vec1);

/// @short
/// Maximum element of a 3D vector
///
/// Compute the maximum value of all elements of a 3D vector.
/// @param vec   3D vector
/// @return
/// Maximum value of all elements of <code><i>vec</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec maxElem(Vector3_arg vec);

/// @short
/// Minimum element of a 3D vector
///
/// Compute the minimum value of all elements of a 3D vector.
/// @param vec   3D vector
/// @return
/// Minimum value of all elements of <code><i>vec</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec minElem(Vector3_arg vec);

/// @short
/// All of the elements of the first 3D vector are less than the corresponding element in the second
///
/// All of the elements of the first 3D vector are less than the corresponding element in the second
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// True if all elements of <code><i>vec0</i></code> are less than the corresponding element in <code><i>vec1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemLessThan(Vector3_arg vec0, Vector3_arg vec1);

/// @short
/// All of the elements of the first 3D vector are less than or equal to the corresponding element in the second
///
/// All of the elements of the first 3D vector are less than or equal to the corresponding element in the second
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// True if all elements of <code><i>vec0</i></code> are less than or equal to the corresponding element in <code><i>vec1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemLessThanOrEqual(Vector3_arg vec0, Vector3_arg vec1);

/// @short
/// All of the elements of the first 3D vector are greater than the corresponding element in the second
///
/// All of the elements of the first 3D vector are greater than the corresponding element in the second
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// True if all elements of <code><i>vec0</i></code> are greater than the corresponding element in <code><i>vec1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThan(Vector3_arg vec0, Vector3_arg vec1);

/// @short
/// All of the elements of the first 3D vector are greater than or equal to the corresponding element in the second
///
/// All of the elements of the first 3D vector are greater than or equal to the corresponding element in the second
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// True if all elements of <code><i>vec0</i></code> are greater than or equal to the corresponding element in <code><i>vec1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThanOrEqual(Vector3_arg vec0, Vector3_arg vec1);

/// @short
/// Compute the sum of all elements of a 3D vector
///
/// Compute the sum of all elements of a 3D vector.
/// @param vec   3D vector
/// @return
/// Sum of all elements of <code><i>vec</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec sum(Vector3_arg vec);

/// @short
/// Compute the dot product of two 3D vectors
///
/// Compute the dot product of two 3D vectors.
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// Dot product of the specified 3D vectors
///
SCE_VECTORMATH_INLINE const floatInVec dot(Vector3_arg vec0, Vector3_arg vec1);

/// @short
/// Compute the square of the length of a 3D vector
///
/// Compute the square of the length of a 3D vector.
/// @param vec   3D vector
/// @return
/// Square of the length of the specified 3D vector
///
SCE_VECTORMATH_INLINE const floatInVec lengthSqr(Vector3_arg vec);

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Compute the length of a 3D vector
///
/// Compute the length of a 3D vector.
/// @param vec   3D vector
/// @return
/// Length of the specified 3D vector
///
SCE_VECTORMATH_INLINE const floatInVec length(Vector3_arg vec);

/// @short
/// Normalize a 3D vector
///
/// Compute a normalized 3D vector.
/// @param vec   3D vector
/// @return
/// The specified 3D vector scaled to unit length
/// @note
/// The result is unpredictable when all elements of vec are at or near zero.
///
SCE_VECTORMATH_INLINE const Vector3 normalize(Vector3_arg vec);

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Compute cross product of two 3D vectors
///
/// Compute cross product of two 3D vectors.
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// Cross product of the specified 3D vectors
///
SCE_VECTORMATH_INLINE const Vector3 cross(Vector3_arg vec0, Vector3_arg vec1);

/// @short
/// Outer product of two 3D vectors
///
/// Compute the outer product of two 3D vectors.
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// The 3x3 matrix product of a column-vector, <code><i>vec0</i></code>, and a row-vector, <code><i>vec1</i></code>
/// @note
/// The term "outer product", which is used in documentation for the PlayStation&reg;2
/// computer entertainment console, corresponds to "cross product" in this library.
///
SCE_VECTORMATH_INLINE const Matrix3 outer(Vector3_arg vec0, Vector3_arg vec1);

/// @short
/// Pre-multiply a row vector by a 3x3 matrix
///
/// Transpose a 3D vector into a row vector and pre-multiply by 3x3 matrix.
/// @param vec   3D vector
/// @param mat   3x3 matrix
/// @return
/// Product of a row-vector and a 3x3 matrix
/// @note
/// Slower than column post-multiply.
///
SCE_VECTORMATH_INLINE const Vector3 rowMul(Vector3_arg vec, Matrix3_arg mat);

/// @short
/// Cross-product matrix of a 3D vector
///
/// Compute a matrix that, when multiplied by a 3D vector, produces the same result as a cross product with that 3D vector.
/// @param vec   3D vector
/// @return
/// Cross-product matrix of <code><i>vec</i></code>
///
SCE_VECTORMATH_INLINE const Matrix3 crossMatrix(Vector3_arg vec);

/// @short
/// Create cross-product matrix and multiply
///
/// Multiply a cross-product matrix by another matrix.
/// @param vec   3D vector
/// @param mat   3x3 matrix
/// @return
/// Product of cross-product matrix of <code><i>vec</i></code> and <code><i>mat</i></code>
/// @note
/// Faster than separately creating a cross-product matrix and multiplying.
///
SCE_VECTORMATH_INLINE const Matrix3 crossMatrixMul(Vector3_arg vec, Matrix3_arg mat);

/// @short
/// Linear interpolation between two 3D vectors
///
/// Linearly interpolate between two 3D vectors.
/// @param t   Interpolation parameter
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// Interpolated 3D vector
/// @note
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Vector3 lerp(float t, Vector3_arg vec0, Vector3_arg vec1);

/// @short
/// Linear interpolation between two 3D vectors
///
/// Linearly interpolate between two 3D vectors.
/// @param t   Interpolation parameter
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @return
/// Interpolated 3D vector
/// @note
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Vector3 lerp(floatInVec_arg t, Vector3_arg vec0, Vector3_arg vec1);

/// @short
/// Spherical linear interpolation between two 3D vectors
///
/// Perform spherical linear interpolation between two 3D vectors.
/// @param t   Interpolation parameter
/// @param unitVec0   3D vector, expected to be unit-length
/// @param unitVec1   3D vector, expected to be unit-length
/// @param tol        A tolerance value for detection of co-linear vectors
/// @return
/// Interpolated 3D vector
/// @note
/// The result is unpredictable if the vectors point in opposite directions.
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Vector3 slerp(float t, Vector3_arg unitVec0, Vector3_arg unitVec1, float tol = SCE_VECTORMATH_DEFAULT_SLERP_TOL_F);

/// @short
/// Spherical linear interpolation between two 3D vectors
///
/// Perform spherical linear interpolation between two 3D vectors.
/// @param t   Interpolation parameter
/// @param unitVec0   3D vector, expected to be unit-length
/// @param unitVec1   3D vector, expected to be unit-length
/// @param tol        A tolerance value for detection of co-linear vectors
/// @return
/// Interpolated 3D vector
/// @note
/// The result is unpredictable if the vectors point in opposite directions.
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Vector3 slerp(floatInVec_arg t, Vector3_arg unitVec0, Vector3_arg unitVec1, floatInVec_arg tol = floatInVec(SCE_VECTORMATH_DEFAULT_SLERP_TOL_F));

/// @short
/// Conditionally select between two 3D vectors
///
/// Conditionally select one of the 3D vector arguments.
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @param select1   False selects the <code><i>vec0</i></code> argument; true selects the <code><i>vec1</i></code> argument
/// @return
/// Equal to <code><i>vec0</i></code> if <code><i>select1</i></code> is false, or to <code><i>vec1</i></code> if <code><i>select1</i></code> is true
///
SCE_VECTORMATH_INLINE const Vector3 select(Vector3_arg vec0, Vector3_arg vec1, bool select1);

/// @short
/// Conditionally select between two 3D vectors
///
/// Conditionally select one of the 3D vector arguments.
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @param select1   False selects the <code><i>vec0</i></code> argument; true selects the <code><i>vec1</i></code> argument
/// @return
/// Equal to <code><i>vec0</i></code> if <code><i>select1</i></code> is false, or to <code><i>vec1</i></code> if <code><i>select1</i></code> is true
/// @note
/// This function uses a conditional select instruction to avoid a branch.
///
SCE_VECTORMATH_INLINE const Vector3 select(Vector3_arg vec0, Vector3_arg vec1, boolInVec_arg select1);

/// @short
/// Load x, y, and z elements from the first three words of a float array.
///
///
/// Load x, y, and z elements from the first three words of a float array.
///
/// @param vec   An output 3D vector
/// @param fptr   Array of float from which x, y, and z will be loaded
///
SCE_VECTORMATH_INLINE void loadXYZ(Vector3& vec, const float* fptr);

/// @short
/// Store x, y, and z elements of a 3D vector in the first three words of a float array.
/// Memory area of previous 16 bytes and next 32 bytes from <code><i>fptr</i></code> might be accessed
///
/// Store x, y, and z elements of a 3D vector in the first three words of a float array.
/// Memory area of previous 16 bytes and next 32 bytes from <code><i>fptr</i></code> might be accessed.
/// @param vec   3D vector
/// @param fptr   An output array of float in which x, y, and z will be stored
///
SCE_VECTORMATH_INLINE void storeXYZ(Vector3_arg vec, float* fptr);

/// @short
/// Load four three-float 3D vectors, stored in twelve floats
///
/// Load four three-float 3D vectors, stored in twelve floats as {x0,y0,z0,x1,y1,z1,x2,y2,z2,x3,y3,z3}, into four 3D vectors.
/// @param vec0   An output 3D vector
/// @param vec1   An output 3D vector
/// @param vec2   An output 3D vector
/// @param vec3   An output 3D vector
/// @param fptr   Array of floats containing 12 floats
///
SCE_VECTORMATH_INLINE void loadXYZArray(Vector3& vec0, Vector3& vec1, Vector3& vec2, Vector3& vec3, const float* fptr);

/// @short
/// Store four 3D vectors in three quadwords
///
/// Store four 3D vectors in three quadwords as {x0,y0,z0,x1,y1,z1,x2,y2,z2,x3,y3,z3}.
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @param vec2   3D vector
/// @param vec3   3D vector
/// @param fptr   An output array of floats containing 12 floats
///
SCE_VECTORMATH_INLINE void storeXYZArray(Vector3_arg vec0, Vector3_arg vec1, Vector3_arg vec2, Vector3_arg vec3, float* fptr);

/// @short
/// Load eight three-half-floats as 3D vectors
///
/// Load eight three-half-floats as 3D vectors.
/// The input is {x0,y0,z0,x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,x5,y5,z5,x6,y6,z6,x7,y7,z7}.
/// @param vec0   An output 3D vector
/// @param vec1   An output 3D vector
/// @param vec2   An output 3D vector
/// @param vec3   An output 3D vector
/// @param vec4   An output 3D vector
/// @param vec5   An output 3D vector
/// @param vec6   An output 3D vector
/// @param vec7   An output 3D vector
/// @param hfptr  Array of uint16_t containing 24 half-floats
/// @note
/// This transformation may not support either denormalized numbers or NaNs.
///
SCE_VECTORMATH_INLINE void loadHalfFloats(Vector3& vec0, Vector3& vec1, Vector3& vec2, Vector3& vec3, Vector3& vec4, Vector3& vec5, Vector3& vec6, Vector3& vec7, const uint16_t* hfptr);

/// @short
/// Load three half-floats as a 3D vector
///
/// Load three half-floats as a 3D vector.
/// @param vec   An output 3D vector
/// @param hfptr   Array of three half-floats
/// @note
/// This transformation may not support either denormalized numbers or NaNs.
///
SCE_VECTORMATH_INLINE void loadHalfFloats(Vector3& vec, const uint16_t* hfptr);

/// @short
/// Store eight 3D vectors as half-floats
///
/// Store eight 3D vectors in three quadwords of half-float values.
/// The output is {x0,y0,z0,x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,x5,y5,z5,x6,y6,z6,x7,y7,z7}.
/// @param vec0   3D vector
/// @param vec1   3D vector
/// @param vec2   3D vector
/// @param vec3   3D vector
/// @param vec4   3D vector
/// @param vec5   3D vector
/// @param vec6   3D vector
/// @param vec7   3D vector
/// @param hfptr  An output array of 24 half-floats
/// @note
/// This transformation may not support either denormalized numbers or NaNs.
///
SCE_VECTORMATH_INLINE void storeHalfFloats(Vector3_arg vec0, Vector3_arg vec1, Vector3_arg vec2, Vector3_arg vec3, Vector3_arg vec4, Vector3_arg vec5, Vector3_arg vec6, Vector3_arg vec7, uint16_t* hfptr);

/// @short
/// Store a 3D vector as half-floats. The memory area of the previous 16 bytes and the next 32 bytes from <code><i>hfptr</i></code> might be accessed.
///
/// Store a 3D vector in a uint16_t array of half-float values.
/// @param vec   3D vector
/// @param hfptr An output array of three half-floats
/// @note
/// This transformation does not support either denormalized numbers or NaNs. The memory area of the previous 16 bytes and the next 32 bytes from <code><i>hfptr</i></code> might be accessed.
///
SCE_VECTORMATH_INLINE void storeHalfFloats(Vector3_arg vec, uint16_t* hfptr);

#ifdef SCE_VECTORMATH_DEBUG

/// @short
/// Print a 3D vector
///
/// Print a 3D vector.  Prints the 3D vector transposed, that is, as a row instead of a column.
/// @param vec   3D vector
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Vector3_arg vec);

/// @short
/// Print a 3D vector and an associated string identifier
///
/// Print a 3D vector and an associated string identifier.  Prints the 3D vector transposed, that is, as a row instead of a column.
/// @param vec   3D vector
/// @param name   String printed with the 3D vector
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Vector3_arg vec, const char* name);

#endif

/// @}

/// @short
/// A 4D vector in array-of-structures format
///
/// A class representing a 4D vector
/// stored in array-of-structures (AoS) format.
///
class Vector4
{
	float mX;
	float mY;    float mZ;    float mW;
public:
	/// @short
	/// Default constructor; does no initialization
	///
	/// Default constructor; does no initialization.
	///
	SCE_VECTORMATH_ALWAYS_INLINE Vector4();

	/// @short
	/// Construct a 4D vector from x, y, z, and w elements
	///
	/// Construct a 4D vector containing the specified x, y, z, and w elements.
	/// @param x   Scalar value
	/// @param y   Scalar value
	/// @param z   Scalar value
	/// @param w   Scalar value
	///
	SCE_VECTORMATH_INLINE Vector4(float x, float y, float z, float w);

	/// @short
	/// Construct a 4D vector from x, y, z, and w elements
	///
	/// Construct a 4D vector containing the specified x, y, z, and w elements.
	/// @param x   Scalar value
	/// @param y   Scalar value
	/// @param z   Scalar value
	/// @param w   Scalar value
	///
	SCE_VECTORMATH_INLINE Vector4(floatInVec_arg x, floatInVec_arg y, floatInVec_arg z, floatInVec_arg w);

	/// @short
	/// Construct a 3D vector from a 2D vector and two scalars
	///
	/// Construct a 3D vector with the x and y elements of the specified 2D vector and with the z and w elements set to the specified scalars.
	/// @param xy   2D vector
	/// @param z   Scalar value
	/// @param w   Scalar value
	///
	SCE_VECTORMATH_INLINE Vector4(Vector2_arg xy, float z, float w);

	/// @short
	/// Construct a 4D vector from a 2D vector and two scalars
	///
	/// Construct a 3D vector with the x and y elements of the specified 2D vector and with the z and w elements set to the specified scalars.
	/// @param xy   2D vector
	/// @param z   Scalar value
	/// @param w   Scalar value
	///
	SCE_VECTORMATH_INLINE Vector4(Vector2_arg xy, floatInVec_arg z, floatInVec_arg w);

	/// @short
	/// Construct a 3D vector from two 2D vectors
	///
	/// Construct a 4D vector with the x and y elements of the first specified 2D vector and with the z and w elements from the x and y elements of the second specified 2D vector
	/// @param xy   2D vector
	/// @param zw   2D vector
	///
	SCE_VECTORMATH_INLINE Vector4(Vector2_arg xy, Vector2_arg zw);

	/// @short
	/// Construct a 4D vector from a 3D vector and a scalar
	///
	/// Construct a 4D vector with the x, y, and z elements of the specified 3D vector and with the w element set to the specified scalar.
	/// @param xyz   3D vector
	/// @param w   Scalar value
	///
	SCE_VECTORMATH_INLINE Vector4(Vector3_arg xyz, float w);

	/// @short
	/// Construct a 4D vector from a 3D vector and a scalar
	///
	/// Construct a 4D vector with the x, y, and z elements of the specified 3D vector and with the w element set to the specified scalar.
	/// @param xyz   3D vector
	/// @param w   Scalar value
	///
	SCE_VECTORMATH_INLINE Vector4(Vector3_arg xyz, floatInVec_arg w);

	/// @short
	/// Copy x, y, and z from a 3D vector into a 4D vector, and set w to 0
	///
	/// Construct a 4D vector with the x, y, and z elements of the specified 3D vector and with the w element set to 0.
	/// @param vec   3D vector
	///
	explicit SCE_VECTORMATH_INLINE Vector4(Vector3_arg vec);

	/// @short
	/// Copy x, y, and z from a 3D point into a 4D vector, and set w to 1
	///
	/// Construct a 4D vector with the x, y, and z elements of the specified 3D point and with the w element set to 1.
	/// @param pnt   3D point
	///
	explicit SCE_VECTORMATH_INLINE Vector4(Point3_arg pnt);

	/// @short
	/// Copy elements from a quaternion into a 4D vector
	///
	/// Construct a 4D vector containing the x, y, z, and w elements of the specified quaternion.
	/// @param quat   Quaternion
	///
	explicit SCE_VECTORMATH_INLINE Vector4(Quat_arg quat);

	/// @short
	/// Set all elements of a 4D vector to the same scalar value
	///
	/// Construct a 4D vector with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Vector4(float scalar);

	/// @short
	/// Set all elements of a 4D vector to the same scalar value
	///
	/// Construct a 4D vector with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Vector4(floatInVec_arg scalar);

	/// @short
	/// Assign one 4D vector to another
	///
	/// Assign one 4D vector to another.
	/// @param vec   4D vector
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& operator =(Vector4_arg vec);

	/// @short
	/// Set the x and y elements of a 4D vector
	///
	/// Set the x and y elements to those of the specified 2D vector.
	/// @param vec   3D vector
	/// @return
	/// A reference to the resulting 4D vector
	/// @note
	/// This function does not change the z and w elements.
	///
	SCE_VECTORMATH_INLINE Vector4& setXY(Vector2_arg vec);

	/// @short
	/// Set the x, y, and z elements of a 4D vector
	///
	/// Set the x, y, and z elements to those of the specified 3D vector.
	/// @param vec   3D vector
	/// @return
	/// A reference to the resulting 4D vector
	/// @note
	/// This function does not change the w element.
	///
	SCE_VECTORMATH_INLINE Vector4& setXYZ(Vector3_arg vec);

	/// @short
	/// Get the x and y elements of a 4D vector
	///
	/// Extract a 4D vector's x and y elements into a 2D vector.
	/// @return
	/// 2D vector containing x and y elements
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector2 getXY() const;

	/// @short
	/// Get the x, y, and z elements of a 4D vector
	///
	/// Extract a 4D vector's x, y, and z elements into a 3D vector.
	/// @return
	/// 3D vector containing x, y, and z elements
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector3 getXYZ() const;

	/// @short
	/// Set the x element of a 4D vector
	///
	/// Set the x element of a 4D vector to the specified scalar value.
	/// @param x   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& setX(float x);

	/// @short
	/// Set the y element of a 4D vector
	///
	/// Set the y element of a 4D vector to the specified scalar value.
	/// @param y   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& setY(float y);

	/// @short
	/// Set the z element of a 4D vector
	///
	/// Set the z element of a 4D vector to the specified scalar value.
	/// @param z   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& setZ(float z);

	/// @short
	/// Set the w element of a 4D vector
	///
	/// Set the w element of a 4D vector to the specified scalar value.
	/// @param w   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& setW(float w);

	/// @short
	/// Set the x element of a 4D vector
	///
	/// Set the x element of a 4D vector to the specified scalar value.
	/// @param x   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& setX(floatInVec_arg x);

	/// @short
	/// Set the y element of a 4D vector
	///
	/// Set the y element of a 4D vector to the specified scalar value.
	/// @param y   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& setY(floatInVec_arg y);

	/// @short
	/// Set the z element of a 4D vector
	///
	/// Set the z element of a 4D vector to the specified scalar value.
	/// @param z   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& setZ(floatInVec_arg z);

	/// @short
	/// Set the w element of a 4D vector
	///
	/// Set the w element of a 4D vector to the specified scalar value.
	/// @param w   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& setW(floatInVec_arg w);

	/// @short
	/// Get the x element of a 4D vector
	///
	/// Get the x element of a 4D vector.
	/// @return
	/// x element of a 4D vector
	///
	SCE_VECTORMATH_INLINE const floatInVec getX() const;

	/// @short
	/// Get the y element of a 4D vector
	///
	/// Get the y element of a 4D vector.
	/// @return
	/// y element of a 4D vector
	///
	SCE_VECTORMATH_INLINE const floatInVec getY() const;

	/// @short
	/// Get the z element of a 4D vector
	///
	/// Get the z element of a 4D vector.
	/// @return
	/// z element of a 4D vector
	///
	SCE_VECTORMATH_INLINE const floatInVec getZ() const;

	/// @short
	/// Get the w element of a 4D vector
	///
	/// Get the w element of a 4D vector.
	/// @return
	/// w element of a 4D vector
	///
	SCE_VECTORMATH_INLINE const floatInVec getW() const;

	/// @short
	/// Set an x, y, z, or w element of a 4D vector by index
	///
	/// Set an x, y, z, or w element of a 4D vector by specifying an index of 0, 1, 2, or 3, respectively.
	/// @param idx   Index, expected in the range 0-3
	/// @param value   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& setElem(int idx, float value);

	/// @short
	/// Set an x, y, z, or w element of a 4D vector by index
	///
	/// Set an x, y, z, or w element of a 4D vector by specifying an index of 0, 1, 2, or 3, respectively.
	/// @param idx   Index, expected in the range 0-3
	/// @param value   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& setElem(int idx, floatInVec_arg value);

	/// @short
	/// Get an x, y, z, or w element of a 4D vector by index
	///
	/// Get an x, y, z, or w element of a 4D vector by specifying an index of 0, 1, 2, or 3, respectively.
	/// @param idx   Index, expected in the range 0-3
	/// @return
	/// Element selected by the specified index
	///
	SCE_VECTORMATH_INLINE const floatInVec getElem(int idx) const;

	/// @short
	/// Subscripting operator to set or get an element
	///
	/// Subscripting operator invoked when applied to non-const Vector4.
	/// @param idx   Index, expected in the range 0-3
	/// @return
	/// A reference to the selected element
	///
	SCE_VECTORMATH_INLINE float & operator [](int idx);

	/// @short
	/// Subscripting operator to get an element
	///
	/// Subscripting operator invoked when applied to const Vector4.
	/// @param idx   Index, expected in the range 0-3
	/// @return
	/// Indexed element
	///
	SCE_VECTORMATH_INLINE const floatInVec operator [](int idx) const;

	/// @short
	/// Add two 4D vectors
	///
	/// Add two 4D vectors.
	/// @param vec   4D vector
	/// @return
	/// Sum of the specified 4D vectors
	///
	SCE_VECTORMATH_INLINE const Vector4 operator +(Vector4_arg vec) const;

	/// @short
	/// Subtract a 4D vector from another 4D vector
	///
	/// Subtract a 4D vector from another 4D vector.
	/// @param vec   4D vector
	/// @return
	/// Difference of the specified 4D vectors
	///
	SCE_VECTORMATH_INLINE const Vector4 operator -(Vector4_arg vec) const;

	/// @short
	/// Multiply a 4D vector by a scalar
	///
	/// Multiply a 4D vector by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified 4D vector and scalar
	///
	SCE_VECTORMATH_INLINE const Vector4 operator *(float scalar) const;

	/// @short
	/// Divide a 4D vector by a scalar
	///
	/// Divide a 4D vector by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Quotient of the specified 4D vector and scalar
	///
	SCE_VECTORMATH_INLINE const Vector4 operator /(float scalar) const;

	/// @short
	/// Multiply a 4D vector by a scalar
	///
	/// Multiply a 4D vector by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified 4D vector and scalar
	///
	SCE_VECTORMATH_INLINE const Vector4 operator *(floatInVec_arg scalar) const;

	/// @short
	/// Divide a 4D vector by a scalar
	///
	/// Divide a 4D vector by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Quotient of the specified 4D vector and scalar
	///
	SCE_VECTORMATH_INLINE const Vector4 operator /(floatInVec_arg scalar) const;

	/// @short
	/// Perform compound assignment and addition with a 4D vector
	///
	/// Perform compound assignment and addition with a 4D vector.
	/// @param vec   4D vector
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& operator +=(Vector4_arg vec);

	/// @short
	/// Perform compound assignment and subtraction by a 4D vector
	///
	/// Perform compound assignment and subtraction by a 4D vector.
	/// @param vec   4D vector
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& operator -=(Vector4_arg vec);

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& operator *=(float scalar);

	/// @short
	/// Perform compound assignment and division by a scalar
	///
	/// Perform compound assignment and division by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& operator /=(float scalar);

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& operator *=(floatInVec_arg scalar);

	/// @short
	/// Perform compound assignment and division by a scalar
	///
	/// Perform compound assignment and division by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 4D vector
	///
	SCE_VECTORMATH_INLINE Vector4& operator /=(floatInVec_arg scalar);

	/// @short
	/// Negate all elements of a 4D vector
	///
	/// Negate all elements of a 4D vector.
	/// @return
	/// 4D vector containing negated elements of the specified 4D vector
	///
	SCE_VECTORMATH_INLINE const Vector4 operator -() const;

	/// @short
	/// Construct x axis
	///
	/// Construct a 4D vector equal to (1,0,0,0).
	/// @return
	/// The constructed 4D vector
	///
	static SCE_VECTORMATH_INLINE const Vector4 xAxis();

	/// @short
	/// Construct y axis
	///
	/// Construct a 4D vector equal to (0,1,0,0).
	/// @return
	/// The constructed 4D vector
	///
	static SCE_VECTORMATH_INLINE const Vector4 yAxis();

	/// @short
	/// Construct z axis
	///
	/// Construct a 4D vector equal to (0,0,1,0).
	/// @return
	/// The constructed 4D vector
	///
	static SCE_VECTORMATH_INLINE const Vector4 zAxis();

	/// @short
	/// Construct w axis
	///
	/// Construct a 4D vector equal to (0,0,0,1).
	/// @return
	/// The constructed 4D vector
	///
	static SCE_VECTORMATH_INLINE const Vector4 wAxis();

	/// @short
	/// Construct zero
	///
	/// Construct a 4D vector equal to (0,0,0,0).
	/// @return
	/// The constructed 4D vector
	///
	static SCE_VECTORMATH_INLINE const Vector4 zero();

}
#if defined(__GNUC__)
__attribute__ ((aligned(16)))
#endif
;

/// @name 4D Vector Functions
/// @{

/// @short
/// Multiply a 4D vector by a scalar
///
/// Multiply a 4D vector by a scalar.
/// @param scalar   Scalar value
/// @param vec   4D vector
/// @return
/// Scalar product of <code><i>vec</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Vector4 operator *(float scalar, Vector4_arg vec);

/// @short
/// Multiply a 4D vector by a scalar
///
/// Multiply a 4D vector by a scalar.
/// @param scalar   Scalar value
/// @param vec   4D vector
/// @return
/// Scalar product of <code><i>vec</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Vector4 operator *(floatInVec_arg scalar, Vector4_arg vec);

/// @short
/// Multiply two 4D vectors per element
///
/// Multiply two 4D vectors element by element.
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @return
/// 4D vector in which each element is the product of the corresponding elements of the specified 4D vectors
///
SCE_VECTORMATH_INLINE const Vector4 mulPerElem(Vector4_arg vec0, Vector4_arg vec1);

/// @short
/// Divide two 4D vectors per element
///
/// Divide two 4D vectors element by element.
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @return
/// 4D vector in which each element is the quotient of the corresponding elements of the specified 4D vectors
/// @note
/// Floating-point behavior matches standard library function <code>divf4</code>.
///
SCE_VECTORMATH_INLINE const Vector4 divPerElem(Vector4_arg vec0, Vector4_arg vec1);

/// @short
/// Compute the reciprocal of a 4D vector per element
///
/// Create a 4D vector in which each element is the reciprocal of the corresponding element of the specified 4D vector.
/// @param vec   4D vector
/// @return
/// 4D vector in which each element is the reciprocal of the corresponding element of the specified 4D vector
/// @note
/// Floating-point behavior matches standard library function <code>recipf4</code>.
///
SCE_VECTORMATH_INLINE const Vector4 recipPerElem(Vector4_arg vec);

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Compute the square root of a 4D vector per element
///
/// Create a 4D vector in which each element is the square root of the corresponding element of the specified 4D vector.
/// @param vec   4D vector
/// @return
/// 4D vector in which each element is the square root of the corresponding element of the specified 4D vector
/// @note
/// Floating-point behavior matches standard library function <code>sqrtf4</code>.
///
SCE_VECTORMATH_INLINE const Vector4 sqrtPerElem(Vector4_arg vec);

/// @short
/// Compute the reciprocal square root of a 4D vector per element
///
/// Create a 4D vector in which each element is the reciprocal square root of the corresponding element of the specified 4D vector.
/// @param vec   4D vector
/// @return
/// 4D vector in which each element is the reciprocal square root of the corresponding element of the specified 4D vector
/// @note
/// Floating-point behavior matches standard library function <code>rsqrtf4</code>.
///
SCE_VECTORMATH_INLINE const Vector4 rsqrtPerElem(Vector4_arg vec);

/// @short
/// Compute the absolute value of a 4D vector per element
///
/// Compute the absolute value of each element of a 4D vector.
/// @param vec   4D vector
/// @return
/// 4D vector in which each element is the absolute value of the corresponding element of vec
///
SCE_VECTORMATH_INLINE const Vector4 absPerElem(Vector4_arg vec);

/// @short
/// Clamp each element of a 4D vector between corresponding elements specifying minimum and maximum values
///
/// For each element, create a value that is clamped between the value of the corresponding elements of <code><i>clampMin</i></code> and <code><i>clampMax</i></code>.
/// @param vec		4D vector to be clamped
/// @param clampMin	4D vector containing the minimum values of the range
/// @param clampMax	4D vector containing the maximum values of the range
/// @return
/// 4D vector in which each element has its value clamped in the range specified by the corresponding element of <code><i>clampMin</i></code> and the corresponding element of <code><i>clampMax</i></code>
/// @note
/// Result is undefined if any minimum element is greater than the corresponding maximum element.
///
SCE_VECTORMATH_INLINE const Vector4 clampPerElem(Vector4_arg vec, Vector4_arg clampMin, Vector4_arg clampMax);

/// @short
/// Copy sign from one 4D vector to another, per element
///
/// For each element, create a value composed of the magnitude of <code><i>vec0</i></code> and the sign of <code><i>vec1</i></code>.
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @return
/// 4D vector in which each element has the magnitude of the corresponding element of <code><i>vec0</i></code> and the sign of the corresponding element of <code><i>vec1</i></code>
///
SCE_VECTORMATH_INLINE const Vector4 copySignPerElem(Vector4_arg vec0, Vector4_arg vec1);

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Maximum of two 4D vectors per element
///
/// Create a 4D vector in which each element is the maximum of the corresponding elements of the specified 4D vectors.
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @return
/// 4D vector in which each element is the maximum of the corresponding elements of the specified 4D vectors
///
SCE_VECTORMATH_INLINE const Vector4 maxPerElem(Vector4_arg vec0, Vector4_arg vec1);

/// @short
/// Minimum of two 4D vectors per element
///
/// Create a 4D vector in which each element is the minimum of the corresponding elements of two specified 4D vectors.
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @return
/// 4D vector in which each element is the minimum of the corresponding elements of the specified 4D vectors
///
SCE_VECTORMATH_INLINE const Vector4 minPerElem(Vector4_arg vec0, Vector4_arg vec1);

/// @short
/// Maximum element of a 4D vector
///
/// Compute the maximum value of all elements of a 4D vector.
/// @param vec   4D vector
/// @return
/// Maximum value of all elements of <code><i>vec</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec maxElem(Vector4_arg vec);

/// @short
/// Minimum element of a 4D vector
///
/// Compute the minimum value of all elements of a 4D vector.
/// @param vec   4D vector
/// @return
/// Minimum value of all elements of <code><i>vec</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec minElem(Vector4_arg vec);

/// @short
/// All of the elements of the first 4D vector are less than the corresponding element in the second
///
/// All of the elements of the first 4D vector are less than the corresponding element in the second
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @return
/// True if all elements of <code><i>vec0</i></code> are less than the corresponding element in <code><i>vec1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemLessThan(Vector4_arg vec0, Vector4_arg vec1);

/// @short
/// All of the elements of the first 4D vector are less than or equal to the corresponding element in the second
///
/// All of the elements of the first 4D vector are less than or equal to the corresponding element in the second
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @return
/// True if all all elements of <code><i>vec0</i></code> are less than or equal to the corresponding element in <code><i>vec1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemLessThanOrEqual(Vector4_arg vec0, Vector4_arg vec1);

/// @short
/// All of the elements of the first 4D vector are greater than the corresponding element in the second
///
/// All of the elements of the first 4D vector are greater than the corresponding element in the second
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @return
/// True if all elements of <code><i>vec0</i></code> are greater than the corresponding element in <code><i>vec1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThan(Vector4_arg vec0, Vector4_arg vec1);

/// @short
/// All of the elements of the first 4D vector are greater than or equal to the corresponding element in the second
///
/// All of the elements of the first 4D vector are greater than or equal to the corresponding element in the second
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @return
/// True if all all elements of <code><i>vec0</i></code> are greater than or equal to the corresponding element in <code><i>vec1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThanOrEqual(Vector4_arg vec0, Vector4_arg vec1);

/// @short
/// Compute the sum of all elements of a 4D vector
///
/// Compute the sum of all elements of a 4D vector.
/// @param vec   4D vector
/// @return
/// Sum of all elements of <code><i>vec</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec sum(Vector4_arg vec);

/// @short
/// Compute the dot product of two 4D vectors
///
/// Compute the dot product of two 4D vectors.
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @return
/// Dot product of the specified 4D vectors
///
SCE_VECTORMATH_INLINE const floatInVec dot(Vector4_arg vec0, Vector4_arg vec1);

/// @short
/// Compute the square of the length of a 4D vector
///
/// Compute the square of the length of a 4D vector.
/// @param vec   4D vector
/// @return
/// Square of the length of the specified 4D vector
///
SCE_VECTORMATH_INLINE const floatInVec lengthSqr(Vector4_arg vec);

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Compute the length of a 4D vector
///
/// Compute the length of a 4D vector.
/// @param vec   4D vector
/// @return
/// Length of the specified 4D vector
///
SCE_VECTORMATH_INLINE const floatInVec length(Vector4_arg vec);

/// @short
/// Normalize a 4D vector
///
/// Compute a normalized 4D vector.
/// @param vec   4D vector
/// @return
/// The specified 4D vector scaled to unit length
/// @note
/// The result is unpredictable when all elements of vec are at or near zero.
///
SCE_VECTORMATH_INLINE const Vector4 normalize(Vector4_arg vec);

/// @short
/// Outer product of two 4D vectors
///
/// Compute the outer product of two 4D vectors.
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @return
/// The 4x4 matrix product of a column-vector, <code><i>vec0</i></code>, and a row-vector, <code><i>vec1</i></code>
/// @note
/// The term "outer product", which is used in documentation for the PlayStation&reg;2
/// computer entertainment console, corresponds to "cross product" in this library.
///
SCE_VECTORMATH_INLINE const Matrix4 outer(Vector4_arg vec0, Vector4_arg vec1);

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Linear interpolation between two 4D vectors
///
/// Linearly interpolate between two 4D vectors.
/// @param t   Interpolation parameter
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @return
/// Interpolated 4D vector
/// @note
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Vector4 lerp(float t, Vector4_arg vec0, Vector4_arg vec1);

/// @short
/// Linear interpolation between two 4D vectors
///
/// Linearly interpolate between two 4D vectors.
/// @param t   Interpolation parameter
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @return
/// Interpolated 4D vector
/// @note
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Vector4 lerp(floatInVec_arg t, Vector4_arg vec0, Vector4_arg vec1);

/// @short
/// Spherical linear interpolation between two 4D vectors
///
/// Perform spherical linear interpolation between two 4D vectors.
/// @param t   Interpolation parameter
/// @param unitVec0   4D vector, expected to be unit-length
/// @param unitVec1   4D vector, expected to be unit-length
/// @param tol        A tolerance value for detection of co-linear vectors
/// @return
/// Interpolated 4D vector
/// @note
/// The result is unpredictable if the vectors point in opposite directions.
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Vector4 slerp(float t, Vector4_arg unitVec0, Vector4_arg unitVec1, float tol = SCE_VECTORMATH_DEFAULT_SLERP_TOL_F);

/// @short
/// Spherical linear interpolation between two 4D vectors
///
/// Perform spherical linear interpolation between two 4D vectors.
/// @param t   Interpolation parameter
/// @param unitVec0   4D vector, expected to be unit-length
/// @param unitVec1   4D vector, expected to be unit-length
/// @param tol        A tolerance value for detection of co-linear vectors
/// @return
/// Interpolated 4D vector
/// @note
/// The result is unpredictable if the vectors point in opposite directions.
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Vector4 slerp(floatInVec_arg t, Vector4_arg unitVec0, Vector4_arg unitVec1, floatInVec_arg tol = floatInVec(SCE_VECTORMATH_DEFAULT_SLERP_TOL_F));

/// @short
/// Conditionally select between two 4D vectors
///
/// Conditionally select one of the 4D vector arguments.
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @param select1   False selects the <code><i>vec0</i></code> argument; true selects the <code><i>vec1</i></code> argument
/// @return
/// Equal to <code><i>vec0</i></code> if <code><i>select1</i></code> is false, or to <code><i>vec1</i></code> if <code><i>select1</i></code> is true
///
SCE_VECTORMATH_INLINE const Vector4 select(Vector4_arg vec0, Vector4_arg vec1, bool select1);

/// @short
/// Conditionally select between two 4D vectors
///
/// Conditionally select one of the 4D vector arguments.
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @param select1   False selects the <code><i>vec0</i></code> argument; true selects the <code><i>vec1</i></code> argument
/// @return
/// Equal to <code><i>vec0</i></code> if <code><i>select1</i></code> is false, or to <code><i>vec1</i></code> if <code><i>select1</i></code> is true
/// @note
/// This function uses a conditional select instruction to avoid a branch.
///
SCE_VECTORMATH_INLINE const Vector4 select(Vector4_arg vec0, Vector4_arg vec1, boolInVec_arg select1);

/// @short
/// Load x, y, z, and w elements from the first four words of a float array.
///
///
/// Load x, y, z, and w elements from the first four words of a float array.
///
/// @param vec   An output 4D vector
/// @param fptr   Array of float from which x, y, z, and w will be loaded
///
SCE_VECTORMATH_INLINE void loadXYZW(Vector4& vec, const float* fptr);

/// @short
/// Store x, y, z, and w elements of a 4D vector in the first four words of a float array.
/// Memory area of previous 16 bytes and next 32 bytes from <code><i>fptr</i></code> might be accessed
///
/// Store x, y, z, and w elements of a 4D vector in the first four words of a float array.
/// Memory area of previous 16 bytes and next 32 bytes from <code><i>fptr</i></code> might be accessed.
/// @param vec   4D vector
/// @param fptr   An output array of float in which x, y, z, and w will be stored
///
SCE_VECTORMATH_INLINE void storeXYZW(Vector4_arg vec, float* fptr);

/// @short
/// Load four four-half-floats as 4D vectors
///
/// Load four four-half-floats as 4D vectors.
/// The input is {x0,y0,z0,w0,x1,y1,z1,w1,x2,y2,z2,w2,x3,y3,z3,w3}.
/// @param vec0   An output 4D vector
/// @param vec1   An output 4D vector
/// @param vec2   An output 4D vector
/// @param vec3   An output 4D vector
/// @param hfptr  Array of sixteen half-floats
/// @note
/// This transformation may not support either denormalized numbers or NaNs.
///
SCE_VECTORMATH_INLINE void loadHalfFloats(Vector4& vec0, Vector4& vec1, Vector4& vec2, Vector4& vec3, const uint16_t* hfptr);

/// @short
/// Load four half-floats as a 4D vector
///
/// Load four half-floats as a 4D vector.
/// @param vec   An output 4D vector
/// @param hfptr Array of four half-floats
/// @note
/// This transformation may not support either denormalized numbers or NaNs.
///
SCE_VECTORMATH_INLINE void loadHalfFloats(Vector4& vec, const uint16_t* hfptr);

/// @short
/// Store four 4D vectors as half-floats
///
/// Store four 4D vectors in two quadwords of half-float values.
/// The output is {x0,y0,z0,w0,x1,y1,z1,w1,x2,y2,z2,w2,x3,y3,z3,w3}.
/// @param vec0   4D vector
/// @param vec1   4D vector
/// @param vec2   4D vector
/// @param vec3   4D vector
/// @param hfptr  An output array containing 16 half-floats
/// @note
/// This transformation may not support either denormalized numbers or NaNs.
///
SCE_VECTORMATH_INLINE void storeHalfFloats(Vector4_arg vec0, Vector4_arg vec1, Vector4_arg vec2, Vector4_arg vec3, uint16_t* hfptr);

/// @short
/// Store a 4D vector as half-floats. The memory area of the previous 16 bytes and the next 32 bytes from <code><i>hfptr</i></code> might be accessed.
///
/// Store a 4D vector in a uint16_t array of half-float values.
/// @param vec   4D vector
/// @param hfptr   An output array of four half-floats
/// @note
/// This transformation may not support either denormalized numbers or NaNs. The memory area of the previous 16 bytes and the next 32 bytes from <code><i>hfptr</i></code> might be accessed.
///
SCE_VECTORMATH_INLINE void storeHalfFloats(Vector4_arg vec, uint16_t* hfptr);

#ifdef SCE_VECTORMATH_DEBUG

/// @short
/// Print a 4D vector
///
/// Print a 4D vector.  Prints the 4D vector transposed, that is, as a row instead of a column.
/// @param vec   4D vector
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Vector4_arg vec);

/// @short
/// Print a 4D vector and an associated string identifier
///
/// Print a 4D vector and an associated string identifier.  Prints the 4D vector transposed, that is, as a row instead of a column.
/// @param vec   4D vector
/// @param name   String printed with the 4D vector
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Vector4_arg vec, const char* name);

#endif

/// @}

/// @short
/// A 3D point in array-of-structures format
///
/// A class representing a 3D point
/// stored in array-of-structures (AoS) format.
///
class Point3
{
	float mX;
	float mY;
	float mZ;
#if !defined(__GNUC__)
	float d;
#endif
public:
	/// @short
	/// Default constructor; does no initialization
	///
	/// Default constructor; does no initialization.
	///
	SCE_VECTORMATH_ALWAYS_INLINE Point3();

	/// @short
	/// Construct a 3D point from x, y, and z elements
	///
	/// Construct a 3D point containing the specified x, y, and z elements.
	/// @param x   Scalar value
	/// @param y   Scalar value
	/// @param z   Scalar value
	///
	SCE_VECTORMATH_INLINE Point3(float x, float y, float z);

	/// @short
	/// Construct a 3D point from x, y, and z elements
	///
	/// Construct a 3D point containing the specified x, y, and z elements.
	/// @param x   Scalar value
	/// @param y   Scalar value
	/// @param z   Scalar value
	///
	SCE_VECTORMATH_INLINE Point3(floatInVec_arg x, floatInVec_arg y, floatInVec_arg z);

	/// @short
	/// Construct a 3D point from a 2D vector and a scalar
	///
	/// Construct a 3D point with the x and y elements of the specified 2D vector and with the z element set to the specified scalar.
	/// @param xy   2D vector
	/// @param z   Scalar value
	///
	SCE_VECTORMATH_INLINE Point3(Vector2_arg xy, float z);

	/// @short
	/// Construct a 3D point from a 2D vector and a scalar
	///
	/// Construct a 3D point with the x and y elements of the specified 2D vector and with the z element set to the specified scalar.
	/// @param xy   2D vector
	/// @param z   Scalar value
	///
	SCE_VECTORMATH_INLINE Point3(Vector2_arg xy, floatInVec_arg z);

	/// @short
	/// Copy elements from a 3D vector into a 3D point
	///
	/// Construct a 3D point containing the x, y, and z elements of the specified 3D vector.
	/// @param vec   3D vector
	///
	explicit SCE_VECTORMATH_INLINE Point3(Vector3_arg vec);

	/// @short
	/// Set all elements of a 3D point to the same scalar value
	///
	/// Construct a 3D point with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Point3(float scalar);

	/// @short
	/// Set all elements of a 3D point to the same scalar value
	///
	/// Construct a 3D point with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Point3(floatInVec_arg scalar);

	/// @short
	/// Assign one 3D point to another
	///
	/// Assign one 3D point to another.
	/// @param pnt   3D point
	/// @return
	/// A reference to the resulting 3D point
	///
	SCE_VECTORMATH_INLINE Point3& operator =(Point3_arg pnt);

	/// @short
	/// Set the x and y elements of a 3D point
	///
	/// Set the x and y elements to those of the specified 3D point.
	/// @param vec   2D vector
	/// @return
	/// A reference to the resulting 3D point
	/// @note
	/// This function does not change the z element.
	///
	SCE_VECTORMATH_INLINE Point3& setXY(Vector2_arg vec);

	/// @short
	/// Get the x and y elements of a 3D point
	///
	/// Extract a 3D point's x and y elements into a 2D vector.
	/// @return
	/// 2D vector containing x and y elements
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector2 getXY() const;

	/// @short
	/// Set the x element of a 3D point
	///
	/// Set the x element of a 3D point to the specified scalar value.
	/// @param x   Scalar value
	/// @return
	/// A reference to the resulting 3D point
	///
	SCE_VECTORMATH_INLINE Point3& setX(float x);

	/// @short
	/// Set the y element of a 3D point
	///
	/// Set the y element of a 3D point to the specified scalar value.
	/// @param y   Scalar value
	/// @return
	/// A reference to the resulting 3D point
	///
	SCE_VECTORMATH_INLINE Point3& setY(float y);

	/// @short
	/// Set the z element of a 3D point
	///
	/// Set the z element of a 3D point to the specified scalar value.
	/// @param z   Scalar value
	/// @return
	/// A reference to the resulting 3D point
	///
	SCE_VECTORMATH_INLINE Point3& setZ(float z);

	/// @short
	/// Set the x element of a 3D point
	///
	/// Set the x element of a 3D point to the specified scalar value.
	/// @param x   Scalar value
	/// @return
	/// A reference to the resulting 3D point
	///
	SCE_VECTORMATH_INLINE Point3& setX(floatInVec_arg x);

	/// @short
	/// Set the y element of a 3D point
	///
	/// Set the y element of a 3D point to the specified scalar value.
	/// @param y   Scalar value
	/// @return
	/// A reference to the resulting 3D point
	///
	SCE_VECTORMATH_INLINE Point3& setY(floatInVec_arg y);

	/// @short
	/// Set the z element of a 3D point
	///
	/// Set the z element of a 3D point to the specified scalar value.
	/// @param z   Scalar value
	/// @return
	/// A reference to the resulting 3D point
	///
	SCE_VECTORMATH_INLINE Point3& setZ(floatInVec_arg z);

	/// @short
	/// Get the x element of a 3D point
	///
	/// Get the x element of a 3D point.
	/// @return
	/// x element of a 3D point
	///
	SCE_VECTORMATH_INLINE const floatInVec getX() const;

	/// @short
	/// Get the y element of a 3D point
	///
	/// Get the y element of a 3D point.
	/// @return
	/// y element of a 3D point
	///
	SCE_VECTORMATH_INLINE const floatInVec getY() const;

	/// @short
	/// Get the z element of a 3D point
	///
	/// Get the z element of a 3D point.
	/// @return
	/// z element of a 3D point
	///
	SCE_VECTORMATH_INLINE const floatInVec getZ() const;

	/// @short
	/// Set an x, y, or z element of a 3D point by index
	///
	/// Set an x, y, or z element of a 3D point by specifying an index of 0, 1, or 2, respectively.
	/// @param idx   Index, expected in the range 0-2
	/// @param value   Scalar value
	/// @return
	/// A reference to the resulting 3D point
	///
	SCE_VECTORMATH_INLINE Point3& setElem(int idx, float value);

	/// @short
	/// Set an x, y, or z element of a 3D point by index
	///
	/// Set an x, y, or z element of a 3D point by specifying an index of 0, 1, or 2, respectively.
	/// @param idx   Index, expected in the range 0-2
	/// @param value   Scalar value
	/// @return
	/// A reference to the resulting 3D point
	///
	SCE_VECTORMATH_INLINE Point3& setElem(int idx, floatInVec_arg value);

	/// @short
	/// Get an x, y, or z element of a 3D point by index
	///
	/// Get an x, y, or z element of a 3D point by specifying an index of 0, 1, or 2, respectively.
	/// @param idx   Index, expected in the range 0-2
	/// @return
	/// Element selected by the specified index
	///
	SCE_VECTORMATH_INLINE const floatInVec getElem(int idx) const;

	/// @short
	/// Subscripting operator to set or get an element
	///
	/// Subscripting operator invoked when applied to non-const Point3.
	/// @param idx   Index, expected in the range 0-2
	/// @return
	/// A reference to the selected element
	///
	SCE_VECTORMATH_INLINE float & operator [](int idx);

	/// @short
	/// Subscripting operator to get an element
	///
	/// Subscripting operator invoked when applied to const Point3.
	/// @param idx   Index, expected in the range 0-2
	/// @return
	/// Indexed element
	///
	SCE_VECTORMATH_INLINE const floatInVec operator [](int idx) const;

	/// @short
	/// Subtract a 3D point from another 3D point
	///
	/// Subtract a 3D point from another 3D point.
	/// @param pnt   3D point
	/// @return
	/// Difference of the specified 3D points
	///
	SCE_VECTORMATH_INLINE const Vector3 operator -(Point3_arg pnt) const;

	/// @short
	/// Add a 3D vector to a 3D point
	///
	/// Add a 3D vector to a 3D point.
	/// @param vec   3D vector
	/// @return
	/// Sum of the specified 3D point and 3D vector
	///
	SCE_VECTORMATH_INLINE const Point3 operator +(Vector3_arg vec) const;

	/// @short
	/// Subtract a 3D vector from a 3D point
	///
	/// Subtract a 3D vector from a 3D point.
	/// @param vec   3D vector
	/// @return
	/// Difference of the specified 3D point and 3D vector
	///
	SCE_VECTORMATH_INLINE const Point3 operator -(Vector3_arg vec) const;

	/// @short
	/// Perform compound assignment and addition with a 3D vector
	///
	/// Perform compound assignment and addition with a 3D vector.
	/// @param vec   3D vector
	/// @return
	/// A reference to the resulting 3D point
	///
	SCE_VECTORMATH_INLINE Point3& operator +=(Vector3_arg vec);

	/// @short
	/// Perform compound assignment and subtraction by a 3D vector
	///
	/// Perform compound assignment and subtraction by a 3D vector.
	/// @param vec   3D vector
	/// @return
	/// A reference to the resulting 3D point
	///
	SCE_VECTORMATH_INLINE Point3& operator -=(Vector3_arg vec);

	/// @short
	/// Construct a 3D point representing the origin
	///
	/// Construct a 3D point equal to (0,0,0).
	/// @return
	/// The constructed 3D point
	///
	static SCE_VECTORMATH_INLINE const Point3 origin();

}
#if defined(__GNUC__)
__attribute__ ((aligned(16)))
#endif
;

/// @name 3D Point Functions
/// @{

/// @short
/// Multiply two 3D points per element
///
/// Multiply two 3D points element by element.
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @return
/// 3D point in which each element is the product of the corresponding elements of the specified 3D points
///
SCE_VECTORMATH_INLINE const Point3 mulPerElem(Point3_arg pnt0, Point3_arg pnt1);

/// @short
/// Divide two 3D points per element
///
/// Divide two 3D points element by element.
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @return
/// 3D point in which each element is the quotient of the corresponding elements of the specified 3D points
/// @note
/// Floating-point behavior matches standard library function <code>divf4</code>.
///
SCE_VECTORMATH_INLINE const Point3 divPerElem(Point3_arg pnt0, Point3_arg pnt1);

/// @short
/// Compute the reciprocal of a 3D point per element
///
/// Create a 3D point in which each element is the reciprocal of the corresponding element of the specified 3D point.
/// @param pnt   3D point
/// @return
/// 3D point in which each element is the reciprocal of the corresponding element of the specified 3D point
/// @note
/// Floating-point behavior matches standard library function <code>recipf4</code>.
///
SCE_VECTORMATH_INLINE const Point3 recipPerElem(Point3_arg pnt);

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Compute the square root of a 3D point per element
///
/// Create a 3D point in which each element is the square root of the corresponding element of the specified 3D point.
/// @param pnt   3D point
/// @return
/// 3D point in which each element is the square root of the corresponding element of the specified 3D point
/// @note
/// Floating-point behavior matches standard library function <code>sqrtf4</code>.
///
SCE_VECTORMATH_INLINE const Point3 sqrtPerElem(Point3_arg pnt);

/// @short
/// Compute the reciprocal square root of a 3D point per element
///
/// Create a 3D point in which each element is the reciprocal square root of the corresponding element of the specified 3D point.
/// @param pnt   3D point
/// @return
/// 3D point in which each element is the reciprocal square root of the corresponding element of the specified 3D point
/// @note
/// Floating-point behavior matches standard library function <code>rsqrtf4</code>.
///
SCE_VECTORMATH_INLINE const Point3 rsqrtPerElem(Point3_arg pnt);

/// @short
/// Compute the absolute value of a 3D point per element
///
/// Compute the absolute value of each element of a 3D point.
/// @param pnt   3D point
/// @return
/// 3D point in which each element is the absolute value of the corresponding element of pnt
///
SCE_VECTORMATH_INLINE const Point3 absPerElem(Point3_arg pnt);

/// @short
/// Clamp each element of a 3D point between corresponding elements specifying minimum and maximum values
///
/// For each element, create a value that is clamped between the value of the corresponding elements of <code><i>clampMin</i></code> and <code><i>clampMax</i></code>.
/// @param pnt		3D point to be clamped
/// @param clampMin	3D point containing the minimum values of the range
/// @param clampMax	3D point containing the maximum values of the range
/// @return
/// 3D point in which each element has its value clamped in the range specified by the corresponding element of <code><i>clampMin</i></code> and the corresponding element of <code><i>clampMax</i></code>
/// @note
/// Result is undefined if any minimum element is greater than the corresponding maximum element.
///
SCE_VECTORMATH_INLINE const Point3 clampPerElem(Point3_arg pnt, Point3_arg clampMin, Point3_arg clampMax);

/// @short
/// Copy sign from one 3D point to another, per element
///
/// For each element, create a value composed of the magnitude of <code><i>pnt0</i></code> and the sign of <code><i>pnt1</i></code>.
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @return
/// 3D point in which each element has the magnitude of the corresponding element of <code><i>pnt0</i></code> and the sign of the corresponding element of <code><i>pnt1</i></code>
///
SCE_VECTORMATH_INLINE const Point3 copySignPerElem(Point3_arg pnt0, Point3_arg pnt1);

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Maximum of two 3D points per element
///
/// Create a 3D point in which each element is the maximum of the corresponding elements of the specified 3D points.
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @return
/// 3D point in which each element is the maximum of the corresponding elements of the specified 3D points
///
SCE_VECTORMATH_INLINE const Point3 maxPerElem(Point3_arg pnt0, Point3_arg pnt1);

/// @short
/// Minimum of two 3D points per element
///
/// Create a 3D point in which each element is the minimum of the corresponding elements of two specified 3D points.
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @return
/// 3D point in which each element is the minimum of the corresponding elements of the specified 3D points
///
SCE_VECTORMATH_INLINE const Point3 minPerElem(Point3_arg pnt0, Point3_arg pnt1);

/// @short
/// Maximum element of a 3D point
///
/// Compute the maximum value of all elements of a 3D point.
/// @param pnt   3D point
/// @return
/// Maximum value of all elements of <code><i>pnt</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec maxElem(Point3_arg pnt);

/// @short
/// Minimum element of a 3D point
///
/// Compute the minimum value of all elements of a 3D point.
/// @param pnt   3D point
/// @return
/// Minimum value of all elements of <code><i>pnt</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec minElem(Point3_arg pnt);

/// @short
/// All of the elements of the first 3D point are less than the corresponding element in the second
///
/// All of the elements of the first 3D point are less than the corresponding element in the second
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @return
/// True if all elements of <code><i>pnt0</i></code> are less than the corresponding element in <code><i>pnt1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemLessThan(Point3_arg pnt0, Point3_arg pnt1);

/// @short
/// All of the elements of the first 3D point are less than or equal to the corresponding element in the second
///
/// All of the elements of the first 3D point are less than or equal to the corresponding element in the second
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @return
/// True if all elements of <code><i>pnt0</i></code> are less than or equal to the corresponding element in <code><i>pnt1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemLessThanOrEqual(Point3_arg pnt0, Point3_arg pnt1);

/// @short
/// All of the elements of the first 3D point are greater than the corresponding element in the second
///
/// All of the elements of the first 3D point are greater than the corresponding element in the second
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @return
/// True if all elements of <code><i>pnt0</i></code> are greater than or equal to the corresponding element in <code><i>pnt1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThan(Point3_arg pnt0, Point3_arg pnt1);

/// @short
/// All of the elements of the first 3D point are greater than or equal to the corresponding element in the second
///
/// All of the elements of the first 3D point are greater than or equal to the corresponding element in the second
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @return
/// True if all elements of <code><i>pnt0</i></code> are greater than or equal to the corresponding element in <code><i>pnt1</i></code>;  otherwise false
///
SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThanOrEqual(Point3_arg pnt0, Point3_arg pnt1);

/// @short
/// Compute the sum of all elements of a 3D point
///
/// Compute the sum of all elements of a 3D point.
/// @param pnt   3D point
/// @return
/// Sum of all elements of <code><i>pnt</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec sum(Point3_arg pnt);

/// @short
/// Apply uniform scale to a 3D point
///
/// Apply uniform scale to a 3D point.
/// @param pnt   3D point
/// @param scaleVal   Scalar value
/// @return
/// 3D point in which every element is multiplied by the scalar value
///
SCE_VECTORMATH_INLINE const Point3 scale(Point3_arg pnt, float scaleVal);

/// @short
/// Apply uniform scale to a 3D point
///
/// Apply uniform scale to a 3D point.
/// @param pnt   3D point
/// @param scaleVal   Scalar value
/// @return
/// 3D point in which every element is multiplied by the scalar value
///
SCE_VECTORMATH_INLINE const Point3 scale(Point3_arg pnt, floatInVec_arg scaleVal);

/// @short
/// Apply non-uniform scale to a 3D point
///
/// Apply non-uniform scale to a 3D point.
/// @param pnt   3D point
/// @param scaleVec   3D vector
/// @return
/// 3D point in which each element is the product of the corresponding elements of the specified 3D point and 3D vector
///
SCE_VECTORMATH_INLINE const Point3 scale(Point3_arg pnt, Vector3_arg scaleVec);

/// @short
/// Scalar projection of a 3D point on a unit-length 3D vector
///
/// Scalar projection of a 3D point on a unit-length 3D vector (dot product).
/// @param pnt   3D point
/// @param unitVec   3D vector, expected to be unit-length
/// @return
/// Scalar projection of the 3D point on the unit-length 3D vector
///
SCE_VECTORMATH_INLINE const floatInVec projection(Point3_arg pnt, Vector3_arg unitVec);

/// @short
/// Compute the square of the distance of a 3D point from the coordinate-system origin
///
/// Compute the square of the distance of a 3D point from the coordinate-system origin.
/// @param pnt   3D point
/// @return
/// Square of the distance of a 3D point from the origin
///
SCE_VECTORMATH_INLINE const floatInVec distSqrFromOrigin(Point3_arg pnt);

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Compute the distance of a 3D point from the coordinate-system origin
///
/// Compute the distance of a 3D point from the coordinate-system origin.
/// @param pnt   3D point
/// @return
/// Distance of a 3D point from the origin
///
SCE_VECTORMATH_INLINE const floatInVec distFromOrigin(Point3_arg pnt);

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Compute the square of the distance between two 3D points
///
/// Compute the square of the distance between two 3D points.
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @return
/// Square of the distance between two 3D points
///
SCE_VECTORMATH_INLINE const floatInVec distSqr(Point3_arg pnt0, Point3_arg pnt1);

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Compute the distance between two 3D points
///
/// Compute the distance between two 3D points.
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @return
/// Distance between two 3D points
///
SCE_VECTORMATH_INLINE const floatInVec dist(Point3_arg pnt0, Point3_arg pnt1);

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Linear interpolation between two 3D points
///
/// Linearly interpolate between two 3D points.
/// @param t   Interpolation parameter
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @return
/// Interpolated 3D point
/// @note
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Point3 lerp(float t, Point3_arg pnt0, Point3_arg pnt1);

/// @short
/// Linear interpolation between two 3D points
///
/// Linearly interpolate between two 3D points.
/// @param t   Interpolation parameter
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @return
/// Interpolated 3D point
/// @note
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Point3 lerp(floatInVec_arg t, Point3_arg pnt0, Point3_arg pnt1);

/// @short
/// Conditionally select between two 3D points
///
/// Conditionally select one of the 3D point arguments.
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @param select1   False selects the <code><i>pnt0</i></code> argument; true selects the <code><i>pnt1</i></code> argument
/// @return
/// Equal to <code><i>pnt0</i></code> if <code><i>select1</i></code> is false, or to <code><i>pnt1</i></code> if <code><i>select1</i></code> is true
///
SCE_VECTORMATH_INLINE const Point3 select(Point3_arg pnt0, Point3_arg pnt1, bool select1);

/// @short
/// Conditionally select between two 3D points
///
/// Conditionally select one of the 3D point arguments.
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @param select1   False selects the <code><i>pnt0</i></code> argument; true selects the <code><i>pnt1</i></code> argument
/// @return
/// Equal to <code><i>pnt0</i></code> if <code><i>select1</i></code> is false, or to <code><i>pnt1</i></code> if <code><i>select1</i></code> is true
/// @note
/// This function uses a conditional select instruction to avoid a branch.
///
SCE_VECTORMATH_INLINE const Point3 select(Point3_arg pnt0, Point3_arg pnt1, boolInVec_arg select1);

/// @short
/// Load x, y, and z elements from the first three words of a float array.
///
///
/// Load x, y, and z elements from the first three words of a float array.
///
/// @param pnt   An output 3D point
/// @param fptr   Array of float from which x, y, and z will be loaded
///
SCE_VECTORMATH_INLINE void loadXYZ(Point3& pnt, const float* fptr);

/// @short
/// Store x, y, and z elements of a 3D point in the first three words of a float array.
/// Memory area of previous 16 bytes and next 32 bytes from <code><i>fptr</i></code> might be accessed
///
/// Store x, y, and z elements of a 3D point in the first three words of a float array.
/// Memory area of previous 16 bytes and next 32 bytes from <code><i>fptr</i></code> might be accessed.
/// @param pnt   3D point
/// @param fptr   An output array of float in which x, y, and z will be stored
///
SCE_VECTORMATH_INLINE void storeXYZ(Point3_arg pnt, float* fptr);

/// @short
/// Load four three-float 3D points, stored in three quadwords
///
/// Load four three-float 3D points, stored in three quadwords as {x0,y0,z0,x1,y1,z1,x2,y2,z2,x3,y3,z3}, into four 3D points.
/// @param pnt0   An output 3D point
/// @param pnt1   An output 3D point
/// @param pnt2   An output 3D point
/// @param pnt3   An output 3D point
/// @param fptr   Array of containing 12 floats
///
SCE_VECTORMATH_INLINE void loadXYZArray(Point3& pnt0, Point3& pnt1, Point3& pnt2, Point3& pnt3, const float* fptr);

/// @short
/// Store four 3D points in three quadwords
///
/// Store four 3D points in three quadwords as {x0,y0,z0,x1,y1,z1,x2,y2,z2,x3,y3,z3}.
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @param pnt2   3D point
/// @param pnt3   3D point
/// @param fptr   Output array containing 12 floats
///
SCE_VECTORMATH_INLINE void storeXYZArray(Point3_arg pnt0, Point3_arg pnt1, Point3_arg pnt2, Point3_arg pnt3, float* fptr);

/// @short
/// Load eight three-half-floats as 3D points
///
/// Load eight three-half-floats as 3D points.
/// The input is {x0,y0,z0,x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,x5,y5,z5,x6,y6,z6,x7,y7,z7}.
/// @param pnt0   An output 3D point
/// @param pnt1   An output 3D point
/// @param pnt2   An output 3D point
/// @param pnt3   An output 3D point
/// @param pnt4   An output 3D point
/// @param pnt5   An output 3D point
/// @param pnt6   An output 3D point
/// @param pnt7   An output 3D point
/// @param hfptr  Array containing 24 half-floats
/// @note
/// This transformation may not support either denormalized numbers or NaNs.
///
SCE_VECTORMATH_INLINE void loadHalfFloats(Point3& pnt0, Point3& pnt1, Point3& pnt2, Point3& pnt3, Point3& pnt4, Point3& pnt5, Point3& pnt6, Point3& pnt7, const uint16_t* hfptr);

/// @short
/// Load three half-floats as a 3D point
///
/// Load three half-floats as a 3D point.
/// @param pnt   An output 3D point
/// @param hfptr   Array of three half-floats
/// @note
/// This transformation does not support either denormalized numbers or NaNs.
///
SCE_VECTORMATH_INLINE void loadHalfFloats(Point3& pnt, const uint16_t* hfptr);

/// @short
/// Store eight 3D points as half-floats
///
/// Store eight 3D points in three quadwords of half-float values.
/// The output is {x0,y0,z0,x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,x5,y5,z5,x6,y6,z6,x7,y7,z7}.
/// @param pnt0   3D point
/// @param pnt1   3D point
/// @param pnt2   3D point
/// @param pnt3   3D point
/// @param pnt4   3D point
/// @param pnt5   3D point
/// @param pnt6   3D point
/// @param pnt7   3D point
/// @param hfptr  An output array containing 24 half-floats
/// @note
/// This transformation does not support either denormalized numbers or NaNs.
///
SCE_VECTORMATH_INLINE void storeHalfFloats(Point3_arg pnt0, Point3_arg pnt1, Point3_arg pnt2, Point3_arg pnt3, Point3_arg pnt4, Point3_arg pnt5, Point3_arg pnt6, Point3_arg pnt7, uint16_t* hfptr);

/// @short
/// Store a 3D point as half-floats. The memory area of the previous 16 bytes and the next 32 bytes from <code><i>hfptr</i></code> might be accessed.
///
/// Store a 3D point in a uint16_t array of half-float values.
/// @param pnt   3D point
/// @param hfptr   An output array of three half-floats
/// @note
/// This transformation does not support either denormalized numbers or NaNs. The memory area of the previous 16 bytes and the next 32 bytes from <code><i>hfptr</i></code> might be accessed.
///
SCE_VECTORMATH_INLINE void storeHalfFloats(Point3_arg pnt, uint16_t* hfptr);

#ifdef SCE_VECTORMATH_DEBUG

/// @short
/// Print a 3D point
///
/// Print a 3D point.  Prints the 3D point transposed, that is, as a row instead of a column.
/// @param pnt   3D point
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Point3_arg pnt);

/// @short
/// Print a 3D point and an associated string identifier
///
/// Print a 3D point and an associated string identifier.  Prints the 3D point transposed, that is, as a row instead of a column.
/// @param pnt   3D point
/// @param name   String printed with the 3D point
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Point3_arg pnt, const char* name);

#endif

/// @}

/// @short
/// A quaternion in array-of-structures format
///
/// A class representing a quaternion
/// stored in array-of-structures (AoS) format.
///
class Quat
{
	float mX;
	float mY;
	float mZ;
	float mW;
public:
	/// @short
	/// Default constructor; does no initialization
	///
	/// Default constructor; does no initialization.
	///
	SCE_VECTORMATH_ALWAYS_INLINE Quat();

	/// @short
	/// Construct a quaternion from x, y, z, and w elements
	///
	/// Construct a quaternion containing the specified x, y, z, and w elements.
	/// @param x   Scalar value
	/// @param y   Scalar value
	/// @param z   Scalar value
	/// @param w   Scalar value
	///
	SCE_VECTORMATH_INLINE Quat(float x, float y, float z, float w);

	/// @short
	/// Construct a quaternion from x, y, z, and w elements
	///
	/// Construct a quaternion containing the specified x, y, z, and w elements.
	/// @param x   Scalar value
	/// @param y   Scalar value
	/// @param z   Scalar value
	/// @param w   Scalar value
	///
	SCE_VECTORMATH_INLINE Quat(floatInVec_arg x, floatInVec_arg y, floatInVec_arg z, floatInVec_arg w);

	/// @short
	/// Construct a quaternion from a 3D vector and a scalar
	///
	/// Construct a quaternion with the x, y, and z elements of the specified 3D vector and with the w element set to the specified scalar.
	/// @param xyz   3D vector
	/// @param w   Scalar value
	///
	SCE_VECTORMATH_INLINE Quat(Vector3_arg xyz, float w);

	/// @short
	/// Construct a quaternion from a 3D vector and a scalar
	///
	/// Construct a quaternion with the x, y, and z elements of the specified 3D vector and with the w element set to the specified scalar.
	/// @param xyz   3D vector
	/// @param w   Scalar value
	///
	SCE_VECTORMATH_INLINE Quat(Vector3_arg xyz, floatInVec_arg w);

	/// @short
	/// Copy elements from a 4D vector into a quaternion
	///
	/// Construct a quaternion containing the x, y, z, and w elements of the specified 4D vector.
	/// @param vec   4D vector
	///
	explicit SCE_VECTORMATH_INLINE Quat(Vector4_arg vec);

	/// @short
	/// Convert a rotation matrix to a unit-length quaternion
	///
	/// Construct a unit-length quaternion representing the same transformation as a rotation matrix.
	/// @param rotMat   3x3 matrix, expected to be a rotation matrix
	///
	explicit SCE_VECTORMATH_INLINE Quat(Matrix3_arg rotMat);

	/// @short
	/// Set all elements of a quaternion to the same scalar value
	///
	/// Construct a quaternion with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Quat(float scalar);

	/// @short
	/// Set all elements of a quaternion to the same scalar value
	///
	/// Construct a quaternion with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Quat(floatInVec_arg scalar);

	/// @short
	/// Assign one quaternion to another
	///
	/// Assign one quaternion to another.
	/// @param quat   Quaternion
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& operator =(Quat_arg quat);

	/// @short
	/// Set the x and y elements of a quaternion
	///
	/// Set the x and y elements to those of the specified 2D vector.
	/// @param vec   2D vector
	/// @return
	/// A reference to the resulting quaternion
	/// @note
	/// This function does not change the z and w elements.
	///
	SCE_VECTORMATH_INLINE Quat& setXY(Vector2_arg vec);

	/// @short
	/// Set the x, y, and z elements of a quaternion
	///
	/// Set the x, y, and z elements to those of the specified 3D vector.
	/// @param vec   3D vector
	/// @return
	/// A reference to the resulting quaternion
	/// @note
	/// This function does not change the w element.
	///
	SCE_VECTORMATH_INLINE Quat& setXYZ(Vector3_arg vec);

	/// @short
	/// Get the x and y elements of a quaternion
	///
	/// Extract a quaternion's x and y elements into a 2D vector.
	/// @return
	/// 2D vector containing x and y elements
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector2 getXY() const;

	/// @short
	/// Get the x, y, and z elements of a quaternion
	///
	/// Extract a quaternion's x, y, and z elements into a 3D vector.
	/// @return
	/// 3D vector containing x, y, and z elements
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector3 getXYZ() const;

	/// @short
	/// Set the x element of a quaternion
	///
	/// Set the x element of a quaternion to the specified scalar value.
	/// @param x   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& setX(float x);

	/// @short
	/// Set the y element of a quaternion
	///
	/// Set the y element of a quaternion to the specified scalar value.
	/// @param y   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& setY(float y);

	/// @short
	/// Set the z element of a quaternion
	///
	/// Set the z element of a quaternion to the specified scalar value.
	/// @param z   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& setZ(float z);

	/// @short
	/// Set the w element of a quaternion
	///
	/// Set the w element of a quaternion to the specified scalar value.
	/// @param w   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& setW(float w);

	/// @short
	/// Set the x element of a quaternion
	///
	/// Set the x element of a quaternion to the specified scalar value.
	/// @param x   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& setX(floatInVec_arg x);

	/// @short
	/// Set the y element of a quaternion
	///
	/// Set the y element of a quaternion to the specified scalar value.
	/// @param y   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& setY(floatInVec_arg y);

	/// @short
	/// Set the z element of a quaternion
	///
	/// Set the z element of a quaternion to the specified scalar value.
	/// @param z   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& setZ(floatInVec_arg z);

	/// @short
	/// Set the w element of a quaternion
	///
	/// Set the w element of a quaternion to the specified scalar value.
	/// @param w   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& setW(floatInVec_arg w);

	/// @short
	/// Get the x element of a quaternion
	///
	/// Get the x element of a quaternion.
	/// @return
	/// x element of a quaternion
	///
	SCE_VECTORMATH_INLINE const floatInVec getX() const;

	/// @short
	/// Get the y element of a quaternion
	///
	/// Get the y element of a quaternion.
	/// @return
	/// y element of a quaternion
	///
	SCE_VECTORMATH_INLINE const floatInVec getY() const;

	/// @short
	/// Get the z element of a quaternion
	///
	/// Get the z element of a quaternion.
	/// @return
	/// z element of a quaternion
	///
	SCE_VECTORMATH_INLINE const floatInVec getZ() const;

	/// @short
	/// Get the w element of a quaternion
	///
	/// Get the w element of a quaternion.
	/// @return
	/// w element of a quaternion
	///
	SCE_VECTORMATH_INLINE const floatInVec getW() const;

	/// @short
	/// Set an x, y, z, or w element of a quaternion by index
	///
	/// Set an x, y, z, or w element of a quaternion by specifying an index of 0, 1, 2, or 3, respectively.
	/// @param idx   Index, expected in the range 0-3
	/// @param value   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& setElem(int idx, float value);

	/// @short
	/// Set an x, y, z, or w element of a quaternion by index
	///
	/// Set an x, y, z, or w element of a quaternion by specifying an index of 0, 1, 2, or 3, respectively.
	/// @param idx   Index, expected in the range 0-3
	/// @param value   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& setElem(int idx, floatInVec_arg value);

	/// @short
	/// Get an x, y, z, or w element of a quaternion by index
	///
	/// Get an x, y, z, or w element of a quaternion by specifying an index of 0, 1, 2, or 3, respectively.
	/// @param idx   Index, expected in the range 0-3
	/// @return
	/// Element selected by the specified index
	///
	SCE_VECTORMATH_INLINE const floatInVec getElem(int idx) const;

	/// @short
	/// Subscripting operator to set or get an element
	///
	/// Subscripting operator invoked when applied to non-const Quat.
	/// @param idx   Index, expected in the range 0-3
	/// @return
	/// A reference to the selected element
	///
	SCE_VECTORMATH_INLINE float & operator [](int idx);

	/// @short
	/// Subscripting operator to get an element
	///
	/// Subscripting operator invoked when applied to const Quat.
	/// @param idx   Index, expected in the range 0-3
	/// @return
	/// Indexed element
	///
	SCE_VECTORMATH_INLINE const floatInVec operator [](int idx) const;

	/// @short
	/// Add two quaternions
	///
	/// Add two quaternions.
	/// @param quat   Quaternion
	/// @return
	/// Sum of the specified quaternions
	///
	SCE_VECTORMATH_INLINE const Quat operator +(Quat_arg quat) const;

	/// @short
	/// Subtract a quaternion from another quaternion
	///
	/// Subtract a quaternion from another quaternion.
	/// @param quat   Quaternion
	/// @return
	/// Difference of the specified quaternions
	///
	SCE_VECTORMATH_INLINE const Quat operator -(Quat_arg quat) const;

	/// @short
	/// Multiply two quaternions
	///
	/// Multiply two quaternions.
	/// @param quat   Quaternion
	/// @return
	/// Product of the specified quaternions
	///
	SCE_VECTORMATH_INLINE const Quat operator *(Quat_arg quat) const;

	/// @short
	/// Multiply a quaternion by a scalar
	///
	/// Multiply a quaternion by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified quaternion and scalar
	///
	SCE_VECTORMATH_INLINE const Quat operator *(float scalar) const;

	/// @short
	/// Divide a quaternion by a scalar
	///
	/// Divide a quaternion by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Quotient of the specified quaternion and scalar
	///
	SCE_VECTORMATH_INLINE const Quat operator /(float scalar) const;

	/// @short
	/// Multiply a quaternion by a scalar
	///
	/// Multiply a quaternion by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified quaternion and scalar
	///
	SCE_VECTORMATH_INLINE const Quat operator *(floatInVec_arg scalar) const;

	/// @short
	/// Divide a quaternion by a scalar
	///
	/// Divide a quaternion by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Quotient of the specified quaternion and scalar
	///
	SCE_VECTORMATH_INLINE const Quat operator /(floatInVec_arg scalar) const;

	/// @short
	/// Perform compound assignment and addition with a quaternion
	///
	/// Perform compound assignment and addition with a quaternion.
	/// @param quat   Quaternion
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& operator +=(Quat_arg quat);

	/// @short
	/// Perform compound assignment and subtraction by a quaternion
	///
	/// Perform compound assignment and subtraction by a quaternion.
	/// @param quat   Quaternion
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& operator -=(Quat_arg quat);

	/// @short
	/// Perform compound assignment and multiplication by a quaternion
	///
	/// Perform compound assignment and multiplication by a quaternion.
	/// @param quat   Quaternion
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& operator *=(Quat_arg quat);

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& operator *=(float scalar);

	/// @short
	/// Perform compound assignment and division by a scalar
	///
	/// Perform compound assignment and division by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& operator /=(float scalar);

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& operator *=(floatInVec_arg scalar);

	/// @short
	/// Perform compound assignment and division by a scalar
	///
	/// Perform compound assignment and division by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting quaternion
	///
	SCE_VECTORMATH_INLINE Quat& operator /=(floatInVec_arg scalar);

	/// @short
	/// Negate all elements of a quaternion
	///
	/// Negate all elements of a quaternion.
	/// @return
	/// Quaternion containing negated elements of the specified quaternion
	///
	SCE_VECTORMATH_INLINE const Quat operator -() const;

	/// @short
	/// Construct an identity quaternion
	///
	/// Construct an identity quaternion equal to (0,0,0,1).
	/// @return
	/// The constructed quaternion
	///
	static SCE_VECTORMATH_INLINE const Quat identity();

	/// @short
	/// Construct a zero quaternion
	///
	/// Construct a zero quaternion equal to (0,0,0,0).
	/// @return
	/// The constructed quaternion
	///
	static SCE_VECTORMATH_INLINE const Quat zero();

	/// @short
	/// Construct an Euler rotation from a quaternion
	///
	/// Construct an Euler rotation from a quaternion
	/// @param unitQuat Unit rotation quaternion
	/// @param order	Euler rotation order
	/// @return
	/// A 3D vector containing values representing Euler angle rotations with
	/// an element ordering specified by the value <code><i>order</i></code>
	///
	static SCE_VECTORMATH_INLINE const Vector3 euler(Quat_arg unitQuat, RotationOrder order);

	/// @short
	/// Construct an axis-angle rotation from a quaternion.
	///
	/// Construct an axis-angle rotation from a quaternion.
	/// @param unitQuat Unit rotation quaternion
	/// @return
	/// A 4D vector containing a 3D xyz vector representing the unit-length axis
	/// and a w element storing the rotation angle in radians.
	///
	static SCE_VECTORMATH_INLINE const Vector4 axisAngle(Quat_arg unitQuat);

	/// @short
	/// Construct a quaternion from an Euler rotation
	///
	/// Construct a quaternion from an Euler rotation
	/// @param radians  3D vector of the Euler X, Y and Z rotations in radians
	/// @param order    Euler rotation order
	/// @return
	/// A quaternion that represents the compounded rotation specified by the elements of <code><i>radians</i></code>
	///
	static SCE_VECTORMATH_INLINE const Quat rotation(Vector3_arg radians, RotationOrder order);

	/// @short
	/// Construct a quaternion to rotate between two unit-length 3D vectors
	///
	/// Construct a quaternion to rotate between two unit-length 3D vectors.
	/// @param unitVec0   3D vector, expected to be unit-length
	/// @param unitVec1   3D vector, expected to be unit-length
	/// @return
	/// The constructed quaternion
	/// @note
	/// The result is unpredictable if <code><i>unitVec0</i></code> and <code><i>unitVec1</i></code> point in opposite directions.
	///
	static SCE_VECTORMATH_INLINE const Quat rotation(Vector3_arg unitVec0, Vector3_arg unitVec1);

	/// @short
	/// Construct a quaternion to rotate around a unit-length 3D vector
	///
	/// Construct a quaternion to rotate around a unit-length 3D vector by the specified radians angle.
	/// @param radians   Scalar value
	/// @param unitVec   3D vector, expected to be unit-length
	/// @return
	/// The constructed quaternion
	///
	static SCE_VECTORMATH_INLINE const Quat rotation(float radians, Vector3_arg unitVec);

	/// @short
	/// Construct a quaternion to rotate around a unit-length 3D vector
	///
	/// Construct a quaternion to rotate around a unit-length 3D vector by the specified radians angle.
	/// @param radians   Scalar value
	/// @param unitVec   3D vector, expected to be unit-length
	/// @return
	/// The constructed quaternion
	///
	static SCE_VECTORMATH_INLINE const Quat rotation(floatInVec_arg radians, Vector3_arg unitVec);

	/// @short
	/// Construct a quaternion to rotate around the x axis
	///
	/// Construct a quaternion to rotate around the x axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed quaternion
	///
	static SCE_VECTORMATH_INLINE const Quat rotationX(float radians);

	/// @short
	/// Construct a quaternion to rotate around the y axis
	///
	/// Construct a quaternion to rotate around the y axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed quaternion
	///
	static SCE_VECTORMATH_INLINE const Quat rotationY(float radians);

	/// @short
	/// Construct a quaternion to rotate around the z axis
	///
	/// Construct a quaternion to rotate around the z axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed quaternion
	///
	static SCE_VECTORMATH_INLINE const Quat rotationZ(float radians);

	/// @short
	/// Construct a quaternion to rotate around the x axis
	///
	/// Construct a quaternion to rotate around the x axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed quaternion
	///
	static SCE_VECTORMATH_INLINE const Quat rotationX(floatInVec_arg radians);

	/// @short
	/// Construct a quaternion to rotate around the y axis
	///
	/// Construct a quaternion to rotate around the y axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed quaternion
	///
	static SCE_VECTORMATH_INLINE const Quat rotationY(floatInVec_arg radians);

	/// @short
	/// Construct a quaternion to rotate around the z axis
	///
	/// Construct a quaternion to rotate around the z axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed quaternion
	///
	static SCE_VECTORMATH_INLINE const Quat rotationZ(floatInVec_arg radians);
}
#if defined(__GNUC__)
__attribute__ ((aligned(16)))
#endif
;

/// @name Quaternion Functions
/// @{

/// @short
/// Multiply a quaternion by a scalar
///
/// Multiply a quaternion by a scalar.
/// @param scalar   Scalar value
/// @param quat   Quaternion
/// @return
/// Scalar product of <code><i>quat</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Quat operator *(float scalar, Quat_arg quat);

/// @short
/// Multiply a quaternion by a scalar
///
/// Multiply a quaternion by a scalar.
/// @param scalar   Scalar value
/// @param quat   Quaternion
/// @return
/// Scalar product of <code><i>quat</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Quat operator *(floatInVec_arg scalar, Quat_arg quat);

/// @short
/// Compute the conjugate of a quaternion
///
/// Compute the conjugate of a quaternion.
/// @param quat   Quaternion
/// @return
/// Conjugate of the specified quaternion
///
SCE_VECTORMATH_INLINE const Quat conj(Quat_arg quat);

/// @short
/// Use a unit-length quaternion to rotate a 3D vector
///
/// Rotate a 3D vector by applying a unit-length quaternion.
/// @param unitQuat   Quaternion, expected to be unit-length
/// @param vec   3D vector
/// @return
/// The rotated 3D vector, equivalent to unitQuat*Quat(vec,0)*conj(unitQuat)
///
SCE_VECTORMATH_INLINE const Vector3 rotate(Quat_arg unitQuat, Vector3_arg vec);

/// @short
/// Compute the dot product of two quaternions
///
/// Compute the dot product of two quaternions.
/// @param quat0   Quaternion
/// @param quat1   Quaternion
/// @return
/// Dot product of the specified quaternions
///
SCE_VECTORMATH_INLINE const floatInVec dot(Quat_arg quat0, Quat_arg quat1);

/// @short
/// Compute the norm of a quaternion
///
/// Compute the norm, equal to the square of the length, of a quaternion.
/// @param quat   Quaternion
/// @return
/// The norm of the specified quaternion
///
SCE_VECTORMATH_INLINE const floatInVec norm(Quat_arg quat);

/// @short
/// Compute the square of the length of a quaternion.
///
/// Compute the square of the length of a quaternion.
/// @param quat   Quaternion
/// @return
/// Square of the length of the specified quaternion
///
SCE_VECTORMATH_INLINE const floatInVec lengthSqr(Quat_arg quat);

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Compute the length of a quaternion
///
/// Compute the length of a quaternion.
/// @param quat   Quaternion
/// @return
/// Length of the specified quaternion
///
SCE_VECTORMATH_INLINE const floatInVec length(Quat_arg quat);

/// @short
/// Normalize a quaternion
///
/// Compute a normalized quaternion.
/// @param quat   Quaternion
/// @return
/// The specified quaternion scaled to unit length
/// @note
/// The result is unpredictable when all elements of quat are at or near zero.
///
SCE_VECTORMATH_INLINE const Quat normalize(Quat_arg quat);

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Linear interpolation between two quaternions
///
/// Linearly interpolate between two quaternions.
/// @param t   Interpolation parameter
/// @param quat0   Quaternion
/// @param quat1   Quaternion
/// @return
/// Interpolated quaternion
/// @note
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Quat lerp(float t, Quat_arg quat0, Quat_arg quat1);

/// @short
/// Linear interpolation between two quaternions
///
/// Linearly interpolate between two quaternions.
/// @param t   Interpolation parameter
/// @param quat0   Quaternion
/// @param quat1   Quaternion
/// @return
/// Interpolated quaternion
/// @note
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Quat lerp(floatInVec_arg t, Quat_arg quat0, Quat_arg quat1);

/// @short
/// Spherical linear interpolation between two quaternions
///
/// Perform spherical linear interpolation between two quaternions.
/// @param t   Interpolation parameter
/// @param unitQuat0   Quaternion, expected to be unit-length
/// @param unitQuat1   Quaternion, expected to be unit-length
/// @param tol        A tolerance value for detection of co-linear vectors
/// @return
/// Interpolated quaternion
/// @note
/// Interpolates along the shortest path between orientations.
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Quat slerp(float t, Quat_arg unitQuat0, Quat_arg unitQuat1, float tol = SCE_VECTORMATH_DEFAULT_SLERP_TOL_F);

/// @short
/// Spherical linear interpolation between two quaternions
///
/// Perform spherical linear interpolation between two quaternions.
/// @param t   Interpolation parameter
/// @param unitQuat0   Quaternion, expected to be unit-length
/// @param unitQuat1   Quaternion, expected to be unit-length
/// @param tol        A tolerance value for detection of co-linear vectors
/// @return
/// Interpolated quaternion
/// @note
/// Interpolates along the shortest path between orientations.
/// Does not clamp <code><i>t</i></code> between 0 and 1.
///
SCE_VECTORMATH_INLINE const Quat slerp(floatInVec_arg t, Quat_arg unitQuat0, Quat_arg unitQuat1, floatInVec_arg tol = floatInVec(SCE_VECTORMATH_DEFAULT_SLERP_TOL_F));

/// @short
/// Spherical quadrangle interpolation
///
/// Perform spherical quadrangle interpolation between four quaternions.
/// @param t   Interpolation parameter
/// @param unitQuat0   Quaternion, expected to be unit-length
/// @param unitQuat1   Quaternion, expected to be unit-length
/// @param unitQuat2   Quaternion, expected to be unit-length
/// @param unitQuat3   Quaternion, expected to be unit-length
/// @return
/// Interpolated quaternion
///
SCE_VECTORMATH_INLINE const Quat squad(float t, Quat_arg unitQuat0, Quat_arg unitQuat1, Quat_arg unitQuat2, Quat_arg unitQuat3);

/// @short
/// Spherical quadrangle interpolation
///
/// Perform spherical quadrangle interpolation between four quaternions.
/// @param t   Interpolation parameter
/// @param unitQuat0   Quaternion, expected to be unit-length
/// @param unitQuat1   Quaternion, expected to be unit-length
/// @param unitQuat2   Quaternion, expected to be unit-length
/// @param unitQuat3   Quaternion, expected to be unit-length
/// @return
/// Interpolated quaternion
///
SCE_VECTORMATH_INLINE const Quat squad(floatInVec_arg t, Quat_arg unitQuat0, Quat_arg unitQuat1, Quat_arg unitQuat2, Quat_arg unitQuat3);

/// @short
/// Conditionally select between two quaternions
///
/// Conditionally select one of the quaternion arguments.
/// @param quat0   Quaternion
/// @param quat1   Quaternion
/// @param select1   False selects the <code><i>quat0</i></code> argument; true selects the <code><i>quat1</i></code> argument
/// @return
/// Equal to <code><i>quat0</i></code> if <code><i>select1</i></code> is false, or to <code><i>quat1</i></code> if <code><i>select1</i></code> is true
///
SCE_VECTORMATH_INLINE const Quat select(Quat_arg quat0, Quat_arg quat1, bool select1);

/// @short
/// Conditionally select between two quaternions
///
/// Conditionally select one of the quaternion arguments.
/// @param quat0   Quaternion
/// @param quat1   Quaternion
/// @param select1   False selects the <code><i>quat0</i></code> argument; true selects the <code><i>quat1</i></code> argument
/// @return
/// Equal to <code><i>quat0</i></code> if <code><i>select1</i></code> is false, or to <code><i>quat1</i></code> if <code><i>select1</i></code> is true
/// @note
/// This function uses a conditional select instruction to avoid a branch.
///
SCE_VECTORMATH_INLINE const Quat select(Quat_arg quat0, Quat_arg quat1, boolInVec_arg select1);

/// @short
/// Load x, y, z, and w elements from the first four words of a float array.
///
///
/// Load x, y, z, and w elements from the first four words of a float array.
///
/// @param quat   An output quaternion
/// @param fptr   Array of float from which x, y, z, and w will be loaded
///
SCE_VECTORMATH_INLINE void loadXYZW(Quat& quat, const float* fptr);

/// @short
/// Store x, y, z, and w elements of a quaternion in the first four words of a float array.
/// Memory area of previous 16 bytes and next 32 bytes from <code><i>fptr</i></code> might be accessed
///
/// Store x, y, z, and w elements of a quaternion in the first four words of a float array.
/// Memory area of previous 16 bytes and next 32 bytes from <code><i>fptr</i></code> might be accessed.
/// @param quat   Quaternion
/// @param fptr   An output array of float in which x, y, z, and w will be stored
///
SCE_VECTORMATH_INLINE void storeXYZW(Quat_arg quat, float* fptr);

#ifdef SCE_VECTORMATH_DEBUG

/// @short
/// Print a quaternion
///
/// Print a quaternion.
/// @param quat   Quaternion
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Quat_arg quat);

/// @short
/// Print a quaternion and an associated string identifier
///
/// Print a quaternion and an associated string identifier.
/// @param quat   Quaternion
/// @param name   String printed with the quaternion
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Quat_arg quat, const char* name);

#endif

/// @}

/// @short
/// A 2x2 matrix in array-of-structures format
///
/// A class representing a 2x2 matrix
/// stored in array-of-structures (AoS) format.
///

class Matrix2
{
	Vector4 mMat; // XY = Col0, ZW = Col1

public:
	/// @short
	/// Default constructor; does no initialization
	///
	/// Default constructor; does no initialization.
	///
	SCE_VECTORMATH_ALWAYS_INLINE Matrix2();

	/// @short
	/// Construct a 2x2 matrix containing the specified columns
	///
	/// Construct a 2x2 matrix containing the specified columns.
	/// @param col0   2D vector
	/// @param col1   2D vector
	///
	SCE_VECTORMATH_INLINE Matrix2(Vector2_arg col0, Vector2_arg col1);

	/// @short
	/// Set all elements of a 2x2 matrix to the same scalar value
	///
	/// Construct a 2x2 matrix with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Matrix2(float scalar);

	/// @short
	/// Set all elements of a 2x2 matrix to the same scalar value
	///
	/// Construct a 2x2 matrix with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Matrix2(floatInVec_arg scalar);

	/// @short
	/// Construct a 2x2 matrix containing the specified 4D vector data
	///
	/// Construct a 2x2 matrix containing the specified 4D vector data.
	/// The first column is constructed from elements x and y from the specified 4D vector
	/// The second column is constructed from elements z and w from the specified 4D vector
	/// @param mat   Vector float
	///
	explicit SCE_VECTORMATH_INLINE Matrix2(Vector4_arg mat);

	/// @short
	/// Assign one 2x2 matrix to another
	///
	/// Assign one 2x2 matrix to another.
	/// @param mat   2x2 matrix
	/// @return
	/// A reference to the resulting 2x2 matrix
	///
	SCE_VECTORMATH_INLINE Matrix2& operator =(Matrix2_arg mat);

	/// @short
	/// Set column 0 of a 2x2 matrix
	///
	/// Set column 0 of a 2x2 matrix.
	/// @param col0   2D vector
	/// @return
	/// A reference to the resulting 2x2 matrix
	///
	SCE_VECTORMATH_INLINE Matrix2& setCol0(Vector2_arg col0);

	/// @short
	/// Set column 1 of a 2x2 matrix
	///
	/// Set column 1 of a 2x2 matrix.
	/// @param col1   2D vector
	/// @return
	/// A reference to the resulting 2x2 matrix
	///
	SCE_VECTORMATH_INLINE Matrix2& setCol1(Vector2_arg col1);

	/// @short
	/// Get column 0 of a 2x2 matrix
	///
	/// Get column 0 of a 2x2 matrix.
	/// @return
	/// Column 0
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector2 getCol0() const;

	/// @short
	/// Get column 1 of a 2x2 matrix
	///
	/// Get column 1 of a 2x2 matrix.
	/// @return
	/// Column 1
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector2 getCol1() const;

	/// @short
	/// Set the column of a 2x2 matrix referred to by the specified index
	///
	/// Set the column of a 2x2 matrix referred to by the specified index.
	/// @param col   Index, expected in the range 0-1
	/// @param vec   2D vector
	/// @return
	/// A reference to the resulting 2x2 matrix
	///
	SCE_VECTORMATH_INLINE Matrix2& setCol(int col, Vector2_arg vec);

	/// @short
	/// Set the row of a 2x2 matrix referred to by the specified index
	///
	/// Set the row of a 2x2 matrix referred to by the specified index.
	/// @param row   Index, expected in the range 0-1
	/// @param vec   2D vector
	/// @return
	/// A reference to the resulting 2x2 matrix
	///
	SCE_VECTORMATH_INLINE Matrix2& setRow(int row, Vector2_arg vec);

	/// @short
	/// Get the column of a 2x2 matrix referred to by the specified index
	///
	/// Get the column of a 2x2 matrix referred to by the specified index.
	/// @param col   Index, expected in the range 0-1
	/// @return
	/// The column referred to by the specified index
	///
	SCE_VECTORMATH_INLINE const Vector2 getCol(int col) const;

	/// @short
	/// Get the row of a 2x2 matrix referred to by the specified index
	///
	/// Get the row of a 2x2 matrix referred to by the specified index.
	/// @param row   Index, expected in the range 0-1
	/// @return
	/// The row referred to by the specified index
	///
	SCE_VECTORMATH_INLINE const Vector2 getRow(int row) const;

	/// @short
	/// Subscripting operator to set or get a column
	///
	/// Subscripting operator invoked when applied to non-const Matrix2.
	/// @param col   Index, expected in the range 0-1
	/// @return
	/// The column referred to by the specified index
	///
	SCE_VECTORMATH_INLINE const Vector2 operator [](int col) const;

	/// @short
	/// Set the element of a 2x2 matrix referred to by column and row indices
	///
	/// Set the element of a 2x2 matrix referred to by column and row indices.
	/// @param col   Index, expected in the range 0-1
	/// @param row   Index, expected in the range 0-1
	/// @param val   Scalar value
	/// @return
	/// A reference to the resulting 2x2 matrix
	///
	SCE_VECTORMATH_INLINE Matrix2& setElem(int col, int row, float val);

	/// @short
	/// Set the element of a 2x2 matrix referred to by column and row indices
	///
	/// Set the element of a 2x2 matrix referred to by column and row indices.
	/// @param col   Index, expected in the range 0-1
	/// @param row   Index, expected in the range 0-1
	/// @param val   Scalar value
	/// @return
	/// A reference to the resulting 2x2 matrix
	///
	SCE_VECTORMATH_INLINE Matrix2& setElem(int col, int row, floatInVec_arg val);

	/// @short
	/// Get the element of a 2x2 matrix referred to by column and row indices
	///
	/// Get the element of a 2x2 matrix referred to by column and row indices.
	/// @param col   Index, expected in the range 0-1
	/// @param row   Index, expected in the range 0-1
	/// @return
	/// A reference to the resulting 2x2 matrix
	///
	SCE_VECTORMATH_INLINE const floatInVec getElem(int col, int row) const;

	/// @short
	/// Add two 2x2 matrices
	///
	/// Add two 2x2 matrices.
	/// @param mat   2x2 matrix
	/// @return
	/// Sum of the specified 2x2 matrices
	///
	SCE_VECTORMATH_INLINE const Matrix2 operator +(Matrix2_arg mat) const;

	/// @short
	/// Subtract a 2x2 matrix from another 2x2 matrix
	///
	/// Subtract a 2x2 matrix from another 2x2 matrix.
	/// @param mat   2x2 matrix
	/// @return
	/// Difference of the specified 2x2 matrices
	///
	SCE_VECTORMATH_INLINE const Matrix2 operator -(Matrix2_arg mat) const;

	/// @short
	/// Negate all elements of a 2x2 matrix
	///
	/// Negate all elements of a 2x2 matrix.
	/// @return
	/// 2x2 matrix containing negated elements of the specified 2x2 matrix
	///
	SCE_VECTORMATH_INLINE const Matrix2 operator -() const;

	/// @short
	/// Multiply a 2x2 matrix by a scalar
	///
	/// Multiply a 2x2 matrix by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified 2x2 matrix and scalar
	///
	SCE_VECTORMATH_INLINE const Matrix2 operator *(float scalar) const;

	/// @short
	/// Multiply a 2x2 matrix by a scalar
	///
	/// Multiply a 2x2 matrix by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified 2x2 matrix and scalar
	///
	SCE_VECTORMATH_INLINE const Matrix2 operator *(floatInVec_arg scalar) const;

	/// @short
	/// Multiply a 2x2 matrix by a 2D vector
	///
	/// Multiply a 2x2 matrix by a 2D vector.
	/// @param vec   2D vector
	/// @return
	/// Product of the specified 2x2 matrix and 2D vector
	///
	SCE_VECTORMATH_INLINE const Vector2 operator *(Vector2_arg vec) const;

	/// @short
	/// Multiply two 2x2 matrices
	///
	/// Multiply two 2x2 matrices.
	/// @param mat   2x2 matrix
	/// @return
	/// Product of the specified 2x2 matrices
	///
	SCE_VECTORMATH_INLINE const Matrix2 operator *(Matrix2_arg mat) const;

	/// @short
	/// Perform compound assignment and addition with a 2x2 matrix
	///
	/// Perform compound assignment and addition with a 2x2 matrix.
	/// @param mat   2x2 matrix
	/// @return
	/// A reference to the resulting 2x2 matrix
	///
	SCE_VECTORMATH_INLINE Matrix2& operator +=(Matrix2_arg mat);

	/// @short
	/// Perform compound assignment and subtraction by a 2x2 matrix
	///
	/// Perform compound assignment and subtraction by a 2x2 matrix.
	/// @param mat   2x2 matrix
	/// @return
	/// A reference to the resulting 2x2 matrix
	///
	SCE_VECTORMATH_INLINE Matrix2& operator -=(Matrix2_arg mat);

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 2x2 matrix
	///
	SCE_VECTORMATH_INLINE Matrix2& operator *=(float scalar);

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 2x2 matrix
	///
	SCE_VECTORMATH_INLINE Matrix2& operator *=(floatInVec_arg scalar);

	/// @short
	/// Perform compound assignment and multiplication by a 2x2 matrix
	///
	/// Perform compound assignment and multiplication by a 2x2 matrix.
	/// @param mat   2x2 matrix
	/// @return
	/// A reference to the resulting 2x2 matrix
	///
	SCE_VECTORMATH_INLINE Matrix2& operator *=(Matrix2_arg mat);

	/// @short
	/// Construct an identity 2x2 matrix
	///
	/// Construct an identity 2x2 matrix in which non-diagonal elements are zero and diagonal elements are 1.
	/// @return
	/// The constructed 2x2 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix2 identity();

	/// @short
	/// Construct a zero 2x2 matrix
	///
	/// Construct a zero 2x2 matrix in which all elements are zero.
	/// @return
	/// The constructed 2x2 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix2 zero();

#if	!defined(SCE_VECTORMATH_NO_MATH_DEFS)

	/// @short
	/// Construct a 2x2 matrix to rotate
	///
	/// Construct a 2x2 matrix to rotate by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 2x2 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix2 rotation(float radians);

	/// @short
	/// Construct a 2x2 matrix to rotate
	///
	/// Construct a 2x2 matrix to rotate by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 2x2 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix2 rotation(floatInVec_arg radians);

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

	/// @short
	/// Construct a 2x2 matrix to perform scaling
	///
	/// Construct a 2x2 matrix to perform scaling, in which the non-diagonal elements are zero and the diagonal elements are set to the elements of <code><i>scaleVec</i></code>.
	/// @param scaleVec   2D vector
	/// @return
	/// The constructed 2x2 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix2 scale(Vector2_arg scaleVec);
};

/// @short
/// Multiply a 2x2 matrix by a scalar
///
/// Multiply a 2x2 matrix by a scalar.
/// @param scalar   Scalar value
/// @param mat   2x2 matrix
/// @return
/// Scalar product of <code><i>mat</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Matrix2 operator *(float scalar, Matrix2_arg mat);

/// @short
/// Multiply a 2x2 matrix by a scalar
///
/// Multiply a 2x2 matrix by a scalar.
/// @param scalar   Scalar value
/// @param mat   2x2 matrix
/// @return
/// Scalar product of <code><i>mat</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Matrix2 operator *(floatInVec_arg scalar, Matrix2_arg mat);

/// @short
/// Append (post-multiply) a scale transformation to a 2x2 matrix
///
/// Post-multiply a 2x2 matrix by a scale transformation whose diagonal scale factors are contained in the 2D vector.
/// @param mat   2x2 matrix
/// @param scaleVec   2D vector
/// @return
/// The product of <code><i>mat</i></code> and a scale transformation created from <code><i>scaleVec</i></code>
/// @note
/// Faster than creating and multiplying a scale transformation matrix.
///
SCE_VECTORMATH_INLINE const Matrix2 appendScale(Matrix2_arg mat, Vector2_arg scaleVec);

/// @short
/// Prepend (pre-multiply) a scale transformation to a 2x2 matrix
///
/// Pre-multiply a 2x2 matrix by a scale transformation whose diagonal scale factors are contained in the 2D vector.
/// @param scaleVec   2D vector
/// @param mat   2x2 matrix
/// @return
/// The product of a scale transformation created from <code><i>scaleVec</i></code> and <code><i>mat</i></code>
/// @note
/// Faster than creating and multiplying a scale transformation matrix.
///
SCE_VECTORMATH_INLINE const Matrix2 prependScale(Vector2_arg scaleVec, Matrix2_arg mat);

/// @short
/// Multiply two 2x2 matrices per element
///
/// Multiply two 2x2 matrices element by element.
/// @param mat0   2x2 matrix
/// @param mat1   2x2 matrix
/// @return
/// 2x2 matrix in which each element is the product of the corresponding elements of the specified 2x2 matrices
///
SCE_VECTORMATH_INLINE const Matrix2 mulPerElem(Matrix2_arg mat0, Matrix2_arg mat1);

/// @short
/// Compute the absolute value of a 2x2 matrix per element
///
/// Compute the absolute value of each element of a 2x2 matrix.
/// @param mat   2x2 matrix
/// @return
/// 2x2 matrix in which each element is the absolute value of the corresponding element of the specified 2x2 matrix
///
SCE_VECTORMATH_INLINE const Matrix2 absPerElem(Matrix2_arg mat);

/// @short
/// Transpose of a 2x2 matrix
///
/// Compute the transpose of a 2x2 matrix.
/// @param mat   2x2 matrix
/// @return
/// <code><i>mat</i></code> transposed
///
SCE_VECTORMATH_INLINE const Matrix2 transpose(Matrix2_arg mat);

/// @short
/// Compute the inverse of a 2x2 matrix
///
/// Compute the inverse of a 2x2 matrix.
/// @param mat   2x2 matrix
/// @return
/// Inverse of <code><i>mat</i></code>
/// @note
/// Result is unpredictable when the determinant of <code><i>mat</i></code> is equal to or near 0.
///
SCE_VECTORMATH_INLINE const Matrix2 inverse(Matrix2_arg mat);

/// @short
/// Determinant of a 2x2 matrix
///
/// Compute the determinant of a 2x2 matrix.
/// @param mat   2x2 matrix
/// @return
/// The determinant of <code><i>mat</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec determinant(Matrix2_arg mat);

/// @short
/// Conditionally select between two 2x2 matrices
///
/// Conditionally select one of the 2x2 matrix arguments.
/// @param mat0   2x2 matrix
/// @param mat1   2x2 matrix
/// @param select1   False selects the <code><i>mat0</i></code> argument; true selects the <code><i>mat1</i></code> argument
/// @return
/// Equal to <code><i>mat0</i></code> if <code><i>select1</i></code> is false, or to <code><i>mat1</i></code> if <code><i>select1</i></code> is true
///
SCE_VECTORMATH_INLINE const Matrix2 select(Matrix2_arg mat0, Matrix2_arg mat1, bool select1);

/// @short
/// Conditionally select between two 2x2 matrices
///
/// Conditionally select one of the 2x2 matrix arguments.
/// @param mat0   2x2 matrix
/// @param mat1   2x2 matrix
/// @param select1   False selects the <code><i>mat0</i></code> argument; true selects the <code><i>mat1</i></code> argument
/// @return
/// Equal to <code><i>mat0</i></code> if <code><i>select1</i></code> is false, or to <code><i>mat1</i></code> if <code><i>select1</i></code> is true
/// @note
/// This function uses a conditional select instruction to avoid a branch.
///
SCE_VECTORMATH_INLINE const Matrix2 select(Matrix2_arg mat0, Matrix2_arg mat1, boolInVec_arg select1);

#ifdef SCE_VECTORMATH_DEBUG

/// @short
/// Print a 2x2 matrix
///
/// Print a 2x2 matrix.  Unlike the printing of vectors, the 2x2 matrix is printed with the correct orientation (columns appear vertically).
/// @param mat   2x2 matrix
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Matrix2_arg mat);

/// @short
/// Print a 2x2 matrix and an associated string identifier
///
/// Print a 2x2 matrix and an associated string identifier.  Unlike the printing of vectors, the 2x2 matrix is printed with the correct orientation (columns appear vertically).
/// @param mat   2x2 matrix
/// @param name   String printed with the 2x2 matrix
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Matrix2_arg mat, const char* name);

#endif	//	SCE_VECTORMATH_DEBUG

/// @short
/// A 3x3 matrix in array-of-structures format
///
/// A class representing a 3x3 matrix
/// stored in array-of-structures (AoS) format.
///
class Matrix3
{
	Vector3 mCol0;
	Vector3 mCol1;
	Vector3 mCol2;

public:
	/// @short
	/// Default constructor; does no initialization
	///
	/// Default constructor; does no initialization.
	///
	SCE_VECTORMATH_ALWAYS_INLINE Matrix3();

	/// @short
	/// Construct a 3x3 matrix containing the specified columns
	///
	/// Construct a 3x3 matrix containing the specified columns.
	/// @param col0   3D vector
	/// @param col1   3D vector
	/// @param col2   3D vector
	///
	SCE_VECTORMATH_INLINE Matrix3(Vector3_arg col0, Vector3_arg col1, Vector3_arg col2);

	/// @short
	/// Construct a 3x3 rotation matrix from a unit-length quaternion
	///
	/// Construct a 3x3 matrix that applies the same rotation as the specified unit-length quaternion.
	/// @param unitQuat   Quaternion, expected to be unit-length
	///
	explicit SCE_VECTORMATH_INLINE Matrix3(Quat_arg unitQuat);

	/// @short
	/// Set all elements of a 3x3 matrix to the same scalar value
	///
	/// Construct a 3x3 matrix with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Matrix3(float scalar);

	/// @short
	/// Set all elements of a 3x3 matrix to the same scalar value
	///
	/// Construct a 3x3 matrix with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Matrix3(floatInVec_arg scalar);

	/// @short
	/// Assign one 3x3 matrix to another
	///
	/// Assign one 3x3 matrix to another.
	/// @param mat   3x3 matrix
	/// @return
	/// A reference to the resulting 3x3 matrix
	///
	SCE_VECTORMATH_INLINE Matrix3& operator =(Matrix3_arg mat);

	/// @short
	/// Set column 0 of a 3x3 matrix
	///
	/// Set column 0 of a 3x3 matrix.
	/// @param col0   3D vector
	/// @return
	/// A reference to the resulting 3x3 matrix
	///
	SCE_VECTORMATH_INLINE Matrix3& setCol0(Vector3_arg col0);

	/// @short
	/// Set column 1 of a 3x3 matrix
	///
	/// Set column 1 of a 3x3 matrix.
	/// @param col1   3D vector
	/// @return
	/// A reference to the resulting 3x3 matrix
	///
	SCE_VECTORMATH_INLINE Matrix3& setCol1(Vector3_arg col1);

	/// @short
	/// Set column 2 of a 3x3 matrix
	///
	/// Set column 2 of a 3x3 matrix.
	/// @param col2   3D vector
	/// @return
	/// A reference to the resulting 3x3 matrix
	///
	SCE_VECTORMATH_INLINE Matrix3& setCol2(Vector3_arg col2);

	/// @short
	/// Get column 0 of a 3x3 matrix
	///
	/// Get column 0 of a 3x3 matrix.
	/// @return
	/// Column 0
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector3 getCol0() const;

	/// @short
	/// Get column 1 of a 3x3 matrix
	///
	/// Get column 1 of a 3x3 matrix.
	/// @return
	/// Column 1
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector3 getCol1() const;

	/// @short
	/// Get column 2 of a 3x3 matrix
	///
	/// Get column 2 of a 3x3 matrix.
	/// @return
	/// Column 2
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector3 getCol2() const;

	/// @short
	/// Set the column of a 3x3 matrix referred to by the specified index
	///
	/// Set the column of a 3x3 matrix referred to by the specified index.
	/// @param col   Index, expected in the range 0-2
	/// @param vec   3D vector
	/// @return
	/// A reference to the resulting 3x3 matrix
	///
	SCE_VECTORMATH_INLINE Matrix3& setCol(int col, Vector3_arg vec);

	/// @short
	/// Set the row of a 3x3 matrix referred to by the specified index
	///
	/// Set the row of a 3x3 matrix referred to by the specified index.
	/// @param row   Index, expected in the range 0-2
	/// @param vec   3D vector
	/// @return
	/// A reference to the resulting 3x3 matrix
	///
	SCE_VECTORMATH_INLINE Matrix3& setRow(int row, Vector3_arg vec);

	/// @short
	/// Get the column of a 3x3 matrix referred to by the specified index
	///
	/// Get the column of a 3x3 matrix referred to by the specified index.
	/// @param col   Index, expected in the range 0-2
	/// @return
	/// The column referred to by the specified index
	///
	SCE_VECTORMATH_INLINE const Vector3 getCol(int col) const;

	/// @short
	/// Get the row of a 3x3 matrix referred to by the specified index
	///
	/// Get the row of a 3x3 matrix referred to by the specified index.
	/// @param row   Index, expected in the range 0-2
	/// @return
	/// The row referred to by the specified index
	///
	SCE_VECTORMATH_INLINE const Vector3 getRow(int row) const;

	/// @short
	/// Subscripting operator to set or get a column
	///
	/// Subscripting operator invoked when applied to non-const Matrix3.
	/// @param col   Index, expected in the range 0-2
	/// @return
	/// A reference to the indexed column
	///
	SCE_VECTORMATH_INLINE Vector3& operator [](int col);

	/// @short
	/// Subscripting operator to get a column
	///
	/// Subscripting operator invoked when applied to const Matrix3.
	/// @param col   Index, expected in the range 0-2
	/// @return
	/// Indexed column
	///
	SCE_VECTORMATH_INLINE const Vector3 operator [](int col) const;

	/// @short
	/// Set the element of a 3x3 matrix referred to by column and row indices
	///
	/// Set the element of a 3x3 matrix referred to by column and row indices.
	/// @param col   Index, expected in the range 0-2
	/// @param row   Index, expected in the range 0-2
	/// @param val   Scalar value
	/// @return
	/// A reference to the resulting 3x3 matrix
	///
	SCE_VECTORMATH_INLINE Matrix3& setElem(int col, int row, float val);

	/// @short
	/// Set the element of a 3x3 matrix referred to by column and row indices
	///
	/// Set the element of a 3x3 matrix referred to by column and row indices.
	/// @param col   Index, expected in the range 0-2
	/// @param row   Index, expected in the range 0-2
	/// @param val   Scalar value
	/// @return
	/// A reference to the resulting 3x3 matrix
	///
	SCE_VECTORMATH_INLINE Matrix3& setElem(int col, int row, floatInVec_arg val);

	/// @short
	/// Get the element of a 3x3 matrix referred to by column and row indices
	///
	/// Get the element of a 3x3 matrix referred to by column and row indices.
	/// @param col   Index, expected in the range 0-2
	/// @param row   Index, expected in the range 0-2
	/// @return
	/// Element selected by <code><i>col</i></code> and <code><i>row</i></code>
	///
	SCE_VECTORMATH_INLINE const floatInVec getElem(int col, int row) const;

	/// @short
	/// Add two 3x3 matrices
	///
	/// Add two 3x3 matrices.
	/// @param mat   3x3 matrix
	/// @return
	/// Sum of the specified 3x3 matrices
	///
	SCE_VECTORMATH_INLINE const Matrix3 operator +(Matrix3_arg mat) const;

	/// @short
	/// Subtract a 3x3 matrix from another 3x3 matrix
	///
	/// Subtract a 3x3 matrix from another 3x3 matrix.
	/// @param mat   3x3 matrix
	/// @return
	/// Difference of the specified 3x3 matrices
	///
	SCE_VECTORMATH_INLINE const Matrix3 operator -(Matrix3_arg mat) const;

	/// @short
	/// Negate all elements of a 3x3 matrix
	///
	/// Negate all elements of a 3x3 matrix.
	/// @return
	/// 3x3 matrix containing negated elements of the specified 3x3 matrix
	///
	SCE_VECTORMATH_INLINE const Matrix3 operator -() const;

	/// @short
	/// Multiply a 3x3 matrix by a scalar
	///
	/// Multiply a 3x3 matrix by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified 3x3 matrix and scalar
	///
	SCE_VECTORMATH_INLINE const Matrix3 operator *(float scalar) const;

	/// @short
	/// Multiply a 3x3 matrix by a scalar
	///
	/// Multiply a 3x3 matrix by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified 3x3 matrix and scalar
	///
	SCE_VECTORMATH_INLINE const Matrix3 operator *(floatInVec_arg scalar) const;

	/// @short
	/// Multiply a 3x3 matrix by a 3D vector
	///
	/// Multiply a 3x3 matrix by a 3D vector.
	/// @param vec   3D vector
	/// @return
	/// Product of the specified 3x3 matrix and 3D vector
	///
	SCE_VECTORMATH_INLINE const Vector3 operator *(Vector3_arg vec) const;

	/// @short
	/// Multiply two 3x3 matrices
	///
	/// Multiply two 3x3 matrices.
	/// @param mat   3x3 matrix
	/// @return
	/// Product of the specified 3x3 matrices
	///
	SCE_VECTORMATH_INLINE const Matrix3 operator *(Matrix3_arg mat) const;

	/// @short
	/// Perform compound assignment and addition with a 3x3 matrix
	///
	/// Perform compound assignment and addition with a 3x3 matrix.
	/// @param mat   3x3 matrix
	/// @return
	/// A reference to the resulting 3x3 matrix
	///
	SCE_VECTORMATH_INLINE Matrix3& operator +=(Matrix3_arg mat);

	/// @short
	/// Perform compound assignment and subtraction by a 3x3 matrix
	///
	/// Perform compound assignment and subtraction by a 3x3 matrix.
	/// @param mat   3x3 matrix
	/// @return
	/// A reference to the resulting 3x3 matrix
	///
	SCE_VECTORMATH_INLINE Matrix3& operator -=(Matrix3_arg mat);

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 3x3 matrix
	///
	SCE_VECTORMATH_INLINE Matrix3& operator *=(float scalar);

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 3x3 matrix
	///
	SCE_VECTORMATH_INLINE Matrix3& operator *=(floatInVec_arg scalar);

	/// @short
	/// Perform compound assignment and multiplication by a 3x3 matrix
	///
	/// Perform compound assignment and multiplication by a 3x3 matrix.
	/// @param mat   3x3 matrix
	/// @return
	/// A reference to the resulting 3x3 matrix
	///
	SCE_VECTORMATH_INLINE Matrix3& operator *=(Matrix3_arg mat);

	/// @short
	/// Construct an identity 3x3 matrix
	///
	/// Construct an identity 3x3 matrix in which non-diagonal elements are zero and diagonal elements are 1.
	/// @return
	/// The constructed 3x3 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix3 identity();

	/// @short
	/// Construct a zero 3x3 matrix
	///
	/// Construct a zero 3x3 matrix in which all elements are zero.
	/// @return
	/// The constructed 3x3 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix3 zero();

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

	/// @short
	/// Construct a 3x3 matrix to rotate around the x axis
	///
	/// Construct a 3x3 matrix to rotate around the x axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 3x3 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix3 rotationX(float radians);

	/// @short
	/// Construct a 3x3 matrix to rotate around the y axis
	///
	/// Construct a 3x3 matrix to rotate around the y axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 3x3 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix3 rotationY(float radians);

	/// @short
	/// Construct a 3x3 matrix to rotate around the z axis
	///
	/// Construct a 3x3 matrix to rotate around the z axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 3x3 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix3 rotationZ(float radians);

	/// @short
	/// Construct a 3x3 matrix to rotate around the x axis
	///
	/// Construct a 3x3 matrix to rotate around the x axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 3x3 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix3 rotationX(floatInVec_arg radians);

	/// @short
	/// Construct a 3x3 matrix to rotate around the y axis
	///
	/// Construct a 3x3 matrix to rotate around the y axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 3x3 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix3 rotationY(floatInVec_arg radians);

	/// @short
	/// Construct a 3x3 matrix to rotate around the z axis
	///
	/// Construct a 3x3 matrix to rotate around the z axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 3x3 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix3 rotationZ(floatInVec_arg radians);

	/// @short
	/// Construct a 3x3 matrix to rotate around the x, y, and z axes
	///
	/// Construct a 3x3 matrix to rotate around the x, y, and z axes by the radians
	///         angles contained in a 3D vector.  Equivalent to <code>rotationZ(radiansXYZ.getZ()) * rotationY(radiansXYZ.getY()) * rotationX(radiansXYZ.getX())</code>.
	/// @param radiansXYZ   3D vector
	/// @return
	/// The constructed 3x3 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix3 rotationZYX(Vector3_arg radiansXYZ);

	/// @short
	/// Construct a 3x3 matrix to rotate around a unit-length 3D vector
	///
	/// Construct a 3x3 matrix to rotate around a unit-length 3D vector by the specified radians angle.
	/// @param radians   Scalar value
	/// @param unitVec   3D vector, expected to be unit-length
	/// @return
	/// The constructed 3x3 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix3 rotation(float radians, Vector3_arg unitVec);

	/// @short
	/// Construct a 3x3 matrix to rotate around a unit-length 3D vector
	///
	/// Construct a 3x3 matrix to rotate around a unit-length 3D vector by the specified radians angle.
	/// @param radians   Scalar value
	/// @param unitVec   3D vector, expected to be unit-length
	/// @return
	/// The constructed 3x3 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix3 rotation(floatInVec_arg radians, Vector3_arg unitVec);

	/// @short
	/// Construct a rotation matrix from a unit-length quaternion
	///
	/// Construct a 3x3 matrix that applies the same rotation as the specified unit-length quaternion.
	/// @param unitQuat   Quaternion, expected to be unit-length
	/// @return
	/// The constructed 3x3 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix3 rotation(Quat_arg unitQuat);

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

	/// @short
	/// Construct a 3x3 matrix to perform scaling
	///
	/// Construct a 3x3 matrix to perform scaling, in which the non-diagonal elements are zero and the diagonal elements are set to the elements of <code><i>scaleVec</i></code>.
	/// @param scaleVec   3D vector
	/// @return
	/// The constructed 3x3 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix3 scale(Vector3_arg scaleVec);

};
/// @name 3x3 Matrix Functions
/// @{

/// @short
/// Multiply a 3x3 matrix by a scalar
///
/// Multiply a 3x3 matrix by a scalar.
/// @param scalar   Scalar value
/// @param mat   3x3 matrix
/// @return
/// Scalar product of <code><i>mat</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Matrix3 operator *(float scalar, Matrix3_arg mat);

/// @short
/// Multiply a 3x3 matrix by a scalar
///
/// Multiply a 3x3 matrix by a scalar.
/// @param scalar   Scalar value
/// @param mat   3x3 matrix
/// @return
/// Scalar product of <code><i>mat</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Matrix3 operator *(floatInVec_arg scalar, Matrix3_arg mat);

/// @short
/// Append (post-multiply) a scale transformation to a 3x3 matrix
///
/// Post-multiply a 3x3 matrix by a scale transformation whose diagonal scale factors are contained in the 3D vector.
/// @param mat   3x3 matrix
/// @param scaleVec   3D vector
/// @return
/// The product of <code><i>mat</i></code> and a scale transformation created from <code><i>scaleVec</i></code>
/// @note
/// Faster than creating and multiplying a scale transformation matrix.
///
SCE_VECTORMATH_INLINE const Matrix3 appendScale(Matrix3_arg mat, Vector3_arg scaleVec);

/// @short
/// Prepend (pre-multiply) a scale transformation to a 3x3 matrix
///
/// Pre-multiply a 3x3 matrix by a scale transformation whose diagonal scale factors are contained in the 3D vector.
/// @param scaleVec   3D vector
/// @param mat   3x3 matrix
/// @return
/// The product of a scale transformation created from <code><i>scaleVec</i></code> and <code><i>mat</i></code>
/// @note
/// Faster than creating and multiplying a scale transformation matrix.
///
SCE_VECTORMATH_INLINE const Matrix3 prependScale(Vector3_arg scaleVec, Matrix3_arg mat);

/// @short
/// Multiply two 3x3 matrices per element
///
/// Multiply two 3x3 matrices element by element.
/// @param mat0   3x3 matrix
/// @param mat1   3x3 matrix
/// @return
/// 3x3 matrix in which each element is the product of the corresponding elements of the specified 3x3 matrices
///
SCE_VECTORMATH_INLINE const Matrix3 mulPerElem(Matrix3_arg mat0, Matrix3_arg mat1);

/// @short
/// Compute the absolute value of a 3x3 matrix per element
///
/// Compute the absolute value of each element of a 3x3 matrix.
/// @param mat   3x3 matrix
/// @return
/// 3x3 matrix in which each element is the absolute value of the corresponding element of the specified 3x3 matrix
///
SCE_VECTORMATH_INLINE const Matrix3 absPerElem(Matrix3_arg mat);

/// @short
/// Transpose of a 3x3 matrix
///
/// Compute the transpose of a 3x3 matrix.
/// @param mat   3x3 matrix
/// @return
/// <code><i>mat</i></code> transposed
///
SCE_VECTORMATH_INLINE const Matrix3 transpose(Matrix3_arg mat);

/// @short
/// Compute the inverse of a 3x3 matrix
///
/// Compute the inverse of a 3x3 matrix.
/// @param mat   3x3 matrix
/// @return
/// Inverse of <code><i>mat</i></code>
/// @note
/// Result is unpredictable when the determinant of <code><i>mat</i></code> is equal to or near 0.
///
SCE_VECTORMATH_INLINE const Matrix3 inverse(Matrix3_arg mat);

/// @short
/// Determinant of a 3x3 matrix
///
/// Compute the determinant of a 3x3 matrix.
/// @param mat   3x3 matrix
/// @return
/// The determinant of <code><i>mat</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec determinant(Matrix3_arg mat);

/// @short
/// Conditionally select between two 3x3 matrices
///
/// Conditionally select one of the 3x3 matrix arguments.
/// @param mat0   3x3 matrix
/// @param mat1   3x3 matrix
/// @param select1   False selects the <code><i>mat0</i></code> argument; true selects the <code><i>mat1</i></code> argument
/// @return
/// Equal to <code><i>mat0</i></code> if <code><i>select1</i></code> is false, or to <code><i>mat1</i></code> if <code><i>select1</i></code> is true
///
SCE_VECTORMATH_INLINE const Matrix3 select(Matrix3_arg mat0, Matrix3_arg mat1, bool select1);

/// @short
/// Conditionally select between two 3x3 matrices
///
/// Conditionally select one of the 3x3 matrix arguments.
/// @param mat0   3x3 matrix
/// @param mat1   3x3 matrix
/// @param select1   False selects the <code><i>mat0</i></code> argument; true selects the <code><i>mat1</i></code> argument
/// @return
/// Equal to <code><i>mat0</i></code> if <code><i>select1</i></code> is false, or to <code><i>mat1</i></code> if <code><i>select1</i></code> is true
/// @note
/// This function uses a conditional select instruction to avoid a branch.
///
SCE_VECTORMATH_INLINE const Matrix3 select(Matrix3_arg mat0, Matrix3_arg mat1, boolInVec_arg select1);

#ifdef SCE_VECTORMATH_DEBUG

/// @short
/// Print a 3x3 matrix
///
/// Print a 3x3 matrix.  Unlike the printing of vectors, the 3x3 matrix is printed with the correct orientation (columns appear vertically).
/// @param mat   3x3 matrix
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Matrix3_arg mat);

/// @short
/// Print a 3x3 matrix and an associated string identifier
///
/// Print a 3x3 matrix and an associated string identifier.  Unlike the printing of vectors, the 3x3 matrix is printed with the correct orientation (columns appear vertically).
/// @param mat   3x3 matrix
/// @param name   String printed with the 3x3 matrix
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Matrix3_arg mat, const char* name);

#endif

/// @}

/// @short
/// A 4x4 matrix in array-of-structures format
///
/// A class representing a 4x4 matrix
/// stored in array-of-structures (AoS) format.
///
class Matrix4
{
	Vector4 mCol0;
	Vector4 mCol1;
	Vector4 mCol2;
	Vector4 mCol3;

public:
	/// @short
	/// Default constructor; does no initialization
	///
	/// Default constructor; does no initialization.
	///
	SCE_VECTORMATH_ALWAYS_INLINE Matrix4();

	/// @short
	/// Construct a 4x4 matrix containing the specified columns
	///
	/// Construct a 4x4 matrix containing the specified columns.
	/// @param col0   4D vector
	/// @param col1   4D vector
	/// @param col2   4D vector
	/// @param col3   4D vector
	///
	SCE_VECTORMATH_INLINE Matrix4(Vector4_arg col0, Vector4_arg col1, Vector4_arg col2, Vector4_arg col3);

	/// @short
	/// Construct a 4x4 matrix from a 3x4 transformation matrix
	///
	/// Construct a 4x4 matrix whose upper 3x4 elements are equal to the 3x4 transformation matrix argument and whose bottom row is equal to (0,0,0,1).
	/// @param mat   3x4 transformation matrix
	///
	explicit SCE_VECTORMATH_INLINE Matrix4(Transform3_arg mat);

	/// @short
	/// Construct a 4x4 matrix from a 3x3 matrix and a 3D vector
	///
	/// Construct a 4x4 matrix whose upper 3x3 elements are equal to the 3x3 matrix argument, whose translation component is equal to the 3D vector argument, and whose bottom row is (0,0,0,1).
	/// @param mat   3x3 matrix
	/// @param translateVec   3D vector
	///
	SCE_VECTORMATH_INLINE Matrix4(Matrix3_arg mat, Vector3_arg translateVec);

	/// @short
	/// Construct a 4x4 matrix from a unit-length quaternion and a 3D vector
	///
	/// Construct a 4x4 matrix whose upper-left 3x3 submatrix is a rotation matrix converted from the unit-length quaternion argument, whose translation component is equal to the 3D vector argument, and whose bottom row is (0,0,0,1).
	/// @param unitQuat   Quaternion, expected to be unit-length
	/// @param translateVec   3D vector
	///
	SCE_VECTORMATH_INLINE Matrix4(Quat_arg unitQuat, Vector3_arg translateVec);

	/// @short
	/// Set all elements of a 4x4 matrix to the same scalar value
	///
	/// Construct a 4x4 matrix with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Matrix4(float scalar);

	/// @short
	/// Set all elements of a 4x4 matrix to the same scalar value
	///
	/// Construct a 4x4 matrix with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Matrix4(floatInVec_arg scalar);

	/// @short
	/// Assign one 4x4 matrix to another
	///
	/// Assign one 4x4 matrix to another.
	/// @param mat   4x4 matrix
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& operator =(Matrix4_arg mat);

	/// @short
	/// Set the upper-left 3x3 submatrix
	///
	/// Set the upper-left 3x3 submatrix elements of a 4x4 matrix equal to the specified 3x3 matrix.
	/// @param mat3   3x3 matrix
	/// @return
	/// A reference to the resulting 4x4 matrix
	/// @note
	/// This function does not change the bottom row elements.
	///
	SCE_VECTORMATH_INLINE Matrix4& setUpper3x3(Matrix3_arg mat3);

	/// @short
	/// Get the upper-left 3x3 submatrix of a 4x4 matrix
	///
	/// Get the upper-left 3x3 submatrix of a 4x4 matrix.
	/// @return
	/// Upper-left 3x3 submatrix
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Matrix3 getUpper3x3() const;

	/// @short
	/// Set translation component
	///
	/// Set the translation component of a 4x4 matrix equal to the specified 3D vector.
	/// @param translateVec   3D vector
	/// @return
	/// A reference to the resulting 4x4 matrix
	/// @note
	/// This function does not change the bottom row elements.
	///
	SCE_VECTORMATH_INLINE Matrix4& setTranslation(Vector3_arg translateVec);

	/// @short
	/// Get the translation component of a 4x4 matrix
	///
	/// Get the translation component of a 4x4 matrix.
	/// @return
	/// Translation component
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector3 getTranslation() const;

	/// @short
	/// Set column 0 of a 4x4 matrix
	///
	/// Set column 0 of a 4x4 matrix.
	/// @param col0   4D vector
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& setCol0(Vector4_arg col0);

	/// @short
	/// Set column 1 of a 4x4 matrix
	///
	/// Set column 1 of a 4x4 matrix.
	/// @param col1   4D vector
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& setCol1(Vector4_arg col1);

	/// @short
	/// Set column 2 of a 4x4 matrix
	///
	/// Set column 2 of a 4x4 matrix.
	/// @param col2   4D vector
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& setCol2(Vector4_arg col2);

	/// @short
	/// Set column 3 of a 4x4 matrix
	///
	/// Set column 3 of a 4x4 matrix.
	/// @param col3   4D vector
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& setCol3(Vector4_arg col3);

	/// @short
	/// Get column 0 of a 4x4 matrix
	///
	/// Get column 0 of a 4x4 matrix.
	/// @return
	/// Column 0
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector4 getCol0() const;

	/// @short
	/// Get column 1 of a 4x4 matrix
	///
	/// Get column 1 of a 4x4 matrix.
	/// @return
	/// Column 1
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector4 getCol1() const;

	/// @short
	/// Get column 2 of a 4x4 matrix
	///
	/// Get column 2 of a 4x4 matrix.
	/// @return
	/// Column 2
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector4 getCol2() const;

	/// @short
	/// Get column 3 of a 4x4 matrix
	///
	/// Get column 3 of a 4x4 matrix.
	/// @return
	/// Column 3
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector4 getCol3() const;

	/// @short
	/// Set the column of a 4x4 matrix referred to by the specified index
	///
	/// Set the column of a 4x4 matrix referred to by the specified index.
	/// @param col   Index, expected in the range 0-3
	/// @param vec   4D vector
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& setCol(int col, Vector4_arg vec);

	/// @short
	/// Set the row of a 4x4 matrix referred to by the specified index
	///
	/// Set the row of a 4x4 matrix referred to by the specified index.
	/// @param row   Index, expected in the range 0-3
	/// @param vec   4D vector
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& setRow(int row, Vector4_arg vec);

	/// @short
	/// Get the column of a 4x4 matrix referred to by the specified index
	///
	/// Get the column of a 4x4 matrix referred to by the specified index.
	/// @param col   Index, expected in the range 0-3
	/// @return
	/// The column referred to by the specified index
	///
	SCE_VECTORMATH_INLINE const Vector4 getCol(int col) const;

	/// @short
	/// Get the row of a 4x4 matrix referred to by the specified index
	///
	/// Get the row of a 4x4 matrix referred to by the specified index.
	/// @param row   Index, expected in the range 0-3
	/// @return
	/// The row referred to by the specified index
	///
	SCE_VECTORMATH_INLINE const Vector4 getRow(int row) const;

	/// @short
	/// Subscripting operator to set or get a column
	///
	/// Subscripting operator invoked when applied to non-const Matrix4.
	/// @param col   Index, expected in the range 0-3
	/// @return
	/// A reference to the indexed column
	///
	SCE_VECTORMATH_INLINE Vector4& operator [](int col);

	/// @short
	/// Subscripting operator to get a column
	///
	/// Subscripting operator invoked when applied to const Matrix4.
	/// @param col   Index, expected in the range 0-3
	/// @return
	/// Indexed column
	///
	SCE_VECTORMATH_INLINE const Vector4 operator [](int col) const;

	/// @short
	/// Set the element of a 4x4 matrix referred to by column and row indices
	///
	/// Set the element of a 4x4 matrix referred to by column and row indices.
	/// @param col   Index, expected in the range 0-3
	/// @param row   Index, expected in the range 0-3
	/// @param val   Scalar value
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& setElem(int col, int row, float val);

	/// @short
	/// Set the element of a 4x4 matrix referred to by column and row indices
	///
	/// Set the element of a 4x4 matrix referred to by column and row indices.
	/// @param col   Index, expected in the range 0-3
	/// @param row   Index, expected in the range 0-3
	/// @param val   Scalar value
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& setElem(int col, int row, floatInVec_arg val);

	/// @short
	/// Get the element of a 4x4 matrix referred to by column and row indices
	///
	/// Get the element of a 4x4 matrix referred to by column and row indices.
	/// @param col   Index, expected in the range 0-3
	/// @param row   Index, expected in the range 0-3
	/// @return
	/// Element selected by <code><i>col</i></code> and <code><i>row</i></code>
	///
	SCE_VECTORMATH_INLINE const floatInVec getElem(int col, int row) const;

	/// @short
	/// Add two 4x4 matrices
	///
	/// Add two 4x4 matrices.
	/// @param mat   4x4 matrix
	/// @return
	/// Sum of the specified 4x4 matrices
	///
	SCE_VECTORMATH_INLINE const Matrix4 operator +(Matrix4_arg mat) const;

	/// @short
	/// Subtract a 4x4 matrix from another 4x4 matrix
	///
	/// Subtract a 4x4 matrix from another 4x4 matrix.
	/// @param mat   4x4 matrix
	/// @return
	/// Difference of the specified 4x4 matrices
	///
	SCE_VECTORMATH_INLINE const Matrix4 operator -(Matrix4_arg mat) const;

	/// @short
	/// Negate all elements of a 4x4 matrix
	///
	/// Negate all elements of a 4x4 matrix.
	/// @return
	/// 4x4 matrix containing negated elements of the specified 4x4 matrix
	///
	SCE_VECTORMATH_INLINE const Matrix4 operator -() const;

	/// @short
	/// Multiply a 4x4 matrix by a scalar
	///
	/// Multiply a 4x4 matrix by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified 4x4 matrix and scalar
	///
	SCE_VECTORMATH_INLINE const Matrix4 operator *(float scalar) const;

	/// @short
	/// Multiply a 4x4 matrix by a scalar
	///
	/// Multiply a 4x4 matrix by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// Product of the specified 4x4 matrix and scalar
	///
	SCE_VECTORMATH_INLINE const Matrix4 operator *(floatInVec_arg scalar) const;

	/// @short
	/// Multiply a 4x4 matrix by a 4D vector
	///
	/// Multiply a 4x4 matrix by a 4D vector.
	/// @param vec   4D vector
	/// @return
	/// Product of the specified 4x4 matrix and 4D vector
	///
	SCE_VECTORMATH_INLINE const Vector4 operator *(Vector4_arg vec) const;

	/// @short
	/// Multiply a 4x4 matrix by a 3D vector
	///
	/// Multiply a 4x4 matrix by a 3D vector treated as if it were a 4D vector with the w element equal to 0.
	/// @param vec   3D vector
	/// @return
	/// Product of the specified 4x4 matrix and 3D vector
	///
	SCE_VECTORMATH_INLINE const Vector4 operator *(Vector3_arg vec) const;

	/// @short
	/// Multiply a 4x4 matrix by a 3D point
	///
	/// Multiply a 4x4 matrix by a 3D point treated as if it were a 4D vector with the w element equal to 1.
	/// @param pnt   3D point
	/// @return
	/// Product of the specified 4x4 matrix and 3D point
	///
	SCE_VECTORMATH_INLINE const Vector4 operator *(Point3_arg pnt) const;

	/// @short
	/// Multiply two 4x4 matrices
	///
	/// Multiply two 4x4 matrices.
	/// @param mat   4x4 matrix
	/// @return
	/// Product of the specified 4x4 matrices
	///
	SCE_VECTORMATH_INLINE const Matrix4 operator *(Matrix4_arg mat) const;

	/// @short
	/// Multiply a 4x4 matrix by a 3x4 transformation matrix
	///
	/// Multiply a 4x4 matrix by a 3x4 transformation matrix treated as if it were a 4x4 matrix with the bottom row equal to (0,0,0,1).
	/// @param tfrm   3x4 transformation matrix
	/// @return
	/// Product of the specified 4x4 matrix and 3x4 transformation matrix
	///
	SCE_VECTORMATH_INLINE const Matrix4 operator *(Transform3_arg tfrm) const;

	/// @short
	/// Perform compound assignment and addition with a 4x4 matrix
	///
	/// Perform compound assignment and addition with a 4x4 matrix.
	/// @param mat   4x4 matrix
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& operator +=(Matrix4_arg mat);

	/// @short
	/// Perform compound assignment and subtraction by a 4x4 matrix
	///
	/// Perform compound assignment and subtraction by a 4x4 matrix.
	/// @param mat   4x4 matrix
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& operator -=(Matrix4_arg mat);

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& operator *=(float scalar);

	/// @short
	/// Perform compound assignment and multiplication by a scalar
	///
	/// Perform compound assignment and multiplication by a scalar.
	/// @param scalar   Scalar value
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& operator *=(floatInVec_arg scalar);

	/// @short
	/// Perform compound assignment and multiplication by a 4x4 matrix
	///
	/// Perform compound assignment and multiplication by a 4x4 matrix.
	/// @param mat   4x4 matrix
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& operator *=(Matrix4_arg mat);

	/// @short
	/// Perform compound assignment and multiplication by a 3x4 transformation matrix
	///
	/// Perform compound assignment and multiplication by a 3x4 transformation matrix.
	/// @param tfrm   3x4 transformation matrix
	/// @return
	/// A reference to the resulting 4x4 matrix
	///
	SCE_VECTORMATH_INLINE Matrix4& operator *=(Transform3_arg tfrm);

	/// @short
	/// Construct an identity 4x4 matrix
	///
	/// Construct an identity 4x4 matrix in which non-diagonal elements are zero and diagonal elements are 1.
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 identity();

	/// @short
	/// Construct a zero 4x4 matrix
	///
	/// Construct a zero 4x4 matrix in which all elements are zero.
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 zero();

#if	!defined(SCE_VECTORMATH_NO_MATH_DEFS)

	/// @short
	/// Construct a 4x4 matrix to rotate around the x axis
	///
	/// Construct a 4x4 matrix to rotate around the x axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 rotationX(float radians);

	/// @short
	/// Construct a 4x4 matrix to rotate around the y axis
	///
	/// Construct a 4x4 matrix to rotate around the y axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 rotationY(float radians);

	/// @short
	/// Construct a 4x4 matrix to rotate around the z axis
	///
	/// Construct a 4x4 matrix to rotate around the z axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 rotationZ(float radians);

	/// @short
	/// Construct a 4x4 matrix to rotate around the x axis
	///
	/// Construct a 4x4 matrix to rotate around the x axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 rotationX(floatInVec_arg radians);

	/// @short
	/// Construct a 4x4 matrix to rotate around the y axis
	///
	/// Construct a 4x4 matrix to rotate around the y axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 rotationY(floatInVec_arg radians);

	/// @short
	/// Construct a 4x4 matrix to rotate around the z axis
	///
	/// Construct a 4x4 matrix to rotate around the z axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 rotationZ(floatInVec_arg radians);

	/// @short
	/// Construct a 4x4 matrix to rotate around the x, y, and z axes
	///
	/// Construct a 4x4 matrix to rotate around the x, y, and z axes by the radians
	///         angles contained in a 3D vector.  Equivalent to <code>rotationZ(radiansXYZ.getZ()) * rotationY(radiansXYZ.getY()) * rotationX(radiansXYZ.getX())</code>.
	/// @param radiansXYZ   3D vector
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 rotationZYX(Vector3_arg radiansXYZ);

	/// @short
	/// Construct a 4x4 matrix to rotate around a unit-length 3D vector
	///
	/// Construct a 4x4 matrix to rotate around a unit-length 3D vector by the specified radians angle.
	/// @param radians   Scalar value
	/// @param unitVec   3D vector, expected to be unit-length
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 rotation(float radians, Vector3_arg unitVec);

	/// @short
	/// Construct a 4x4 matrix to rotate around a unit-length 3D vector
	///
	/// Construct a 4x4 matrix to rotate around a unit-length 3D vector by the specified radians angle.
	/// @param radians   Scalar value
	/// @param unitVec   3D vector, expected to be unit-length
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 rotation(floatInVec_arg radians, Vector3_arg unitVec);

	/// @short
	/// Construct a rotation matrix from a unit-length quaternion
	///
	/// Construct a 4x4 matrix that applies the same rotation as the specified unit-length quaternion.
	/// @param unitQuat   Quaternion, expected to be unit-length
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 rotation(Quat_arg unitQuat);

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

	/// @short
	/// Construct a 4x4 matrix to perform scaling
	///
	/// Construct a 4x4 matrix to perform scaling, in which the non-diagonal elements are zero and the diagonal elements are set to the elements of <code><i>scaleVec</i></code>.
	/// @param scaleVec   3D vector
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 scale(Vector3_arg scaleVec);

	/// @short
	/// Construct a 4x4 matrix to perform translation
	///
	/// Construct a 4x4 matrix to perform translation, which is an identity matrix except for the translation component, with coordinates equal to those in <code><i>translateVec</i></code>.
	/// @param translateVec   3D vector
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 translation(Vector3_arg translateVec);

	/// @short
	/// Construct viewing matrix based on eye position, position looked at, and up direction
	///
	/// Construct the inverse of a coordinate frame that is centered at the eye position, with z axis directed away from <code>lookAtPos</code>, and y axis oriented to best match the up direction.
	/// @param eyePos   3D point
	/// @param lookAtPos   3D point
	/// @param upVec   3D vector
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 lookAt(Point3_arg eyePos, Point3_arg lookAtPos, Vector3_arg upVec);

	/// @short
	/// Construct a perspective projection matrix
	///
	/// Construct a perspective projection matrix, equal to:
	///
	/// <pre><code><br />cot(y/2)/a          0               0               0<br />    0            cot(y/2)           0               0<br />    0               0          (f+n)/(n-f)     2*f*n/(n-f)<br />    0               0              -1               0<br /><br /> ; y = fovyRadians<br /> ; a = aspect<br /> ; n = zNear<br /> ; f = zFar</code></pre>
	/// @note
	/// This function will assert if zNear is not less than zFar
	/// @param fovyRadians   Scalar value
	/// @param aspect   Scalar value
	/// @param zNear   Scalar value
	/// @param zFar   Scalar value
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 perspective(float fovyRadians, float aspect, float zNear, float zFar);

	/// @short
	/// Construct a perspective projection matrix
	///
	/// Construct a perspective projection matrix, equal to:
	///
	/// <pre><code><br />cot(y/2)/a          0               0               0<br />    0            cot(y/2)           0               0<br />    0               0          (f+n)/(n-f)     2*f*n/(n-f)<br />    0               0              -1               0<br /><br /> ; y = fovyRadians<br /> ; a = aspect<br /> ; n = zNear<br /> ; f = zFar</code></pre>
	/// @note
	/// This function will assert if zNear is not less than zFar
	/// @param fovyRadians   Scalar value
	/// @param aspect   Scalar value
	/// @param zNear   Scalar value
	/// @param zFar   Scalar value
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 perspective(floatInVec_arg fovyRadians, floatInVec_arg aspect, floatInVec_arg zNear, floatInVec_arg zFar);

	/// @short
	/// Construct a perspective projection matrix based on frustum
	///
	/// Construct a perspective projection matrix based on frustum, equal to:
	///
	/// <pre><code><br /> 2*n/(r-l)          0          (r+l)/(r-l)          0<br />    0            2*n/(t-b)     (t+b)/(t-b)          0<br />    0               0         -(f+n)/(f-n)    -2*f*n/(f-n)<br />    0               0              -1               0<br /><br /> ; l = left<br /> ; r = right<br /> ; b = bottom<br /> ; t = top<br /> ; n = zNear<br /> ; f = zFar</code></pre>
	/// @note
	/// This function will assert if zNear is not less than zFar
	/// @param left   Scalar value
	/// @param right   Scalar value
	/// @param bottom   Scalar value
	/// @param top   Scalar value
	/// @param zNear   Scalar value
	/// @param zFar   Scalar value
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 frustum(float left, float right, float bottom, float top, float zNear, float zFar);

	/// @short
	/// Construct a perspective projection matrix based on frustum
	///
	/// Construct a perspective projection matrix based on frustum, equal to:
	///
	/// <pre><code><br /> 2*n/(r-l)          0          (r+l)/(r-l)          0<br />    0            2*n/(t-b)     (t+b)/(t-b)          0<br />    0               0         -(f+n)/(f-n)    -2*f*n/(f-n)<br />    0               0              -1               0<br /><br /> ; l = left<br /> ; r = right<br /> ; b = bottom<br /> ; t = top<br /> ; n = zNear<br /> ; f = zFar</code></pre>
	/// @note
	/// This function will assert if zNear is not less than zFar
	/// @param left   Scalar value
	/// @param right   Scalar value
	/// @param bottom   Scalar value
	/// @param top   Scalar value
	/// @param zNear   Scalar value
	/// @param zFar   Scalar value
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 frustum(floatInVec_arg left, floatInVec_arg right, floatInVec_arg bottom, floatInVec_arg top, floatInVec_arg zNear, floatInVec_arg zFar);

	/// @short
	/// Construct an orthographic projection matrix
	///
	/// Construct an orthographic projection matrix, equal to:
	///
	/// <pre><code><br /> 2/(r-l)            0               0         -(r+l)/(r-l)<br />    0            2/(t-b)            0         -(t+b)/(t-b)<br />    0               0           -2/(f-n)      -(f+n)/(f-n)<br />    0               0               0               1<br /><br /> ; l = left<br /> ; r = right<br /> ; b = bottom<br /> ; t = top<br /> ; n = zNear<br /> ; f = zFar</code></pre>
	/// @note
	/// This function will assert if zNear is not less than zFar
	/// @param left   Scalar value
	/// @param right   Scalar value
	/// @param bottom   Scalar value
	/// @param top   Scalar value
	/// @param zNear   Scalar value
	/// @param zFar   Scalar value
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 orthographic(float left, float right, float bottom, float top, float zNear, float zFar);

	/// @short
	/// Construct an orthographic projection matrix
	///
	/// Construct an orthographic projection matrix, equal to:
	///
	/// <pre><code><br /> 2/(r-l)            0               0         -(r+l)/(r-l)<br />    0            2/(t-b)            0         -(t+b)/(t-b)<br />    0               0           -2/(f-n)      -(f+n)/(f-n)<br />    0               0               0               1<br /><br /> ; l = left<br /> ; r = right<br /> ; b = bottom<br /> ; t = top<br /> ; n = zNear<br /> ; f = zFar</code></pre>
	/// @note
	/// This function will assert if zNear is not less than zFar
	/// @param left   Scalar value
	/// @param right   Scalar value
	/// @param bottom   Scalar value
	/// @param top   Scalar value
	/// @param zNear   Scalar value
	/// @param zFar   Scalar value
	/// @return
	/// The constructed 4x4 matrix
	///
	static SCE_VECTORMATH_INLINE const Matrix4 orthographic(floatInVec_arg left, floatInVec_arg right, floatInVec_arg bottom, floatInVec_arg top, floatInVec_arg zNear, floatInVec_arg zFar);
};
/// @name 4x4 Matrix Functions
/// @{

/// @short
/// Multiply a 4x4 matrix by a scalar
///
/// Multiply a 4x4 matrix by a scalar.
/// @param scalar   Scalar value
/// @param mat   4x4 matrix
/// @return
/// Scalar product of <code><i>mat</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Matrix4 operator *(float scalar, Matrix4_arg mat);

/// @short
/// Multiply a 4x4 matrix by a scalar
///
/// Multiply a 4x4 matrix by a scalar.
/// @param scalar   Scalar value
/// @param mat   4x4 matrix
/// @return
/// Scalar product of <code><i>mat</i></code> and <code><i>scalar</i></code>
///
SCE_VECTORMATH_INLINE const Matrix4 operator *(floatInVec_arg scalar, Matrix4_arg mat);

/// @short
/// Append (post-multiply) a scale transformation to a 4x4 matrix
///
/// Post-multiply a 4x4 matrix by a scale transformation whose diagonal scale factors are contained in the 3D vector.
/// @param mat   4x4 matrix
/// @param scaleVec   3D vector
/// @return
/// The product of <code><i>mat</i></code> and a scale transformation created from <code><i>scaleVec</i></code>
/// @note
/// Faster than creating and multiplying a scale transformation matrix.
///
SCE_VECTORMATH_INLINE const Matrix4 appendScale(Matrix4_arg mat, Vector3_arg scaleVec);

/// @short
/// Prepend (pre-multiply) a scale transformation to a 4x4 matrix
///
/// Pre-multiply a 4x4 matrix by a scale transformation whose diagonal scale factors are contained in the 3D vector.
/// @param scaleVec   3D vector
/// @param mat   4x4 matrix
/// @return
/// The product of a scale transformation created from <code><i>scaleVec</i></code> and <code><i>mat</i></code>
/// @note
/// Faster than creating and multiplying a scale transformation matrix.
///
SCE_VECTORMATH_INLINE const Matrix4 prependScale(Vector3_arg scaleVec, Matrix4_arg mat);

/// @short
/// Multiply two 4x4 matrices per element
///
/// Multiply two 4x4 matrices element by element.
/// @param mat0   4x4 matrix
/// @param mat1   4x4 matrix
/// @return
/// 4x4 matrix in which each element is the product of the corresponding elements of the specified 4x4 matrices
///
SCE_VECTORMATH_INLINE const Matrix4 mulPerElem(Matrix4_arg mat0, Matrix4_arg mat1);

/// @short
/// Compute the absolute value of a 4x4 matrix per element
///
/// Compute the absolute value of each element of a 4x4 matrix.
/// @param mat   4x4 matrix
/// @return
/// 4x4 matrix in which each element is the absolute value of the corresponding element of the specified 4x4 matrix
///
SCE_VECTORMATH_INLINE const Matrix4 absPerElem(Matrix4_arg mat);

/// @short
/// Transpose of a 4x4 matrix
///
/// Compute the transpose of a 4x4 matrix.
/// @param mat   4x4 matrix
/// @return
/// <code><i>mat</i></code> transposed
///
SCE_VECTORMATH_INLINE const Matrix4 transpose(Matrix4_arg mat);

/// @short
/// Compute the inverse of a 4x4 matrix
///
/// Compute the inverse of a 4x4 matrix.
/// @param mat   4x4 matrix
/// @return
/// Inverse of <code><i>mat</i></code>
/// @note
/// Result is unpredictable when the determinant of <code><i>mat</i></code> is equal to or near 0.
///
SCE_VECTORMATH_INLINE const Matrix4 inverse(Matrix4_arg mat);

/// @short
/// Compute the inverse of a 4x4 matrix, which is expected to be an affine matrix
///
/// Naming the upper-left 3x3 submatrix of the specified 4x4 matrix as <code>M</code>, and its translation component as <code>v</code>, compute a matrix whose upper-left 3x3 submatrix is <code>inverse(M)</code>, whose translation vector is <code>-inverse(M)*v</code>, and whose bottom row is (0,0,0,1).
/// @param mat   4x4 matrix
/// @return
/// Inverse of the specified 4x4 matrix
/// @note
/// This can be used to achieve better performance than a general inverse when the specified 4x4 matrix meets the given restrictions.  The result is unpredictable when the determinant of <code><i>mat</i></code> is equal to or near 0.
///
SCE_VECTORMATH_INLINE const Matrix4 affineInverse(Matrix4_arg mat);

/// @short
/// Compute the inverse of a 4x4 matrix, which is expected to be an affine matrix with an orthogonal upper-left 3x3 submatrix
///
/// Naming the upper-left 3x3 submatrix of the specified 4x4 matrix as <code>M</code>, and its translation component as <code>v</code>, compute a matrix whose upper-left 3x3 submatrix is <code>transpose(M)</code>, whose translation vector is <code>-transpose(M)*v</code>, and whose bottom row is (0,0,0,1).
/// @param mat   4x4 matrix
/// @return
/// Inverse of the specified 4x4 matrix
/// @note
/// This can be used to achieve better performance than a general inverse when the specified 4x4 matrix meets the given restrictions.
///
SCE_VECTORMATH_INLINE const Matrix4 orthoInverse(Matrix4_arg mat);

/// @short
/// Determinant of a 4x4 matrix
///
/// Compute the determinant of a 4x4 matrix.
/// @param mat   4x4 matrix
/// @return
/// The determinant of <code><i>mat</i></code>
///
SCE_VECTORMATH_INLINE const floatInVec determinant(Matrix4_arg mat);

/// @short
/// Conditionally select between two 4x4 matrices
///
/// Conditionally select one of the 4x4 matrix arguments.
/// @param mat0   4x4 matrix
/// @param mat1   4x4 matrix
/// @param select1   False selects the <code><i>mat0</i></code> argument; true selects the <code><i>mat1</i></code> argument
/// @return
/// Equal to <code><i>mat0</i></code> if <code><i>select1</i></code> is false, or to <code><i>mat1</i></code> if <code><i>select1</i></code> is true
///
SCE_VECTORMATH_INLINE const Matrix4 select(Matrix4_arg mat0, Matrix4_arg mat1, bool select1);

/// @short
/// Conditionally select between two 4x4 matrices
///
/// Conditionally select one of the 4x4 matrix arguments.
/// @param mat0   4x4 matrix
/// @param mat1   4x4 matrix
/// @param select1   False selects the <code><i>mat0</i></code> argument; true selects the <code><i>mat1</i></code> argument
/// @return
/// Equal to <code><i>mat0</i></code> if <code><i>select1</i></code> is false, or to <code><i>mat1</i></code> if <code><i>select1</i></code> is true
/// @note
/// This function uses a conditional select instruction to avoid a branch.
///
SCE_VECTORMATH_INLINE const Matrix4 select(Matrix4_arg mat0, Matrix4_arg mat1, boolInVec_arg select1);

#ifdef SCE_VECTORMATH_DEBUG

/// @short
/// Print a 4x4 matrix
///
/// Print a 4x4 matrix.  Unlike the printing of vectors, the 4x4 matrix is printed with the correct orientation (columns appear vertically).
/// @param mat   4x4 matrix
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Matrix4_arg mat);

/// @short
/// Print a 4x4 matrix and an associated string identifier
///
/// Print a 4x4 matrix and an associated string identifier.  Unlike the printing of vectors, the 4x4 matrix is printed with the correct orientation (columns appear vertically).
/// @param mat   4x4 matrix
/// @param name   String printed with the 4x4 matrix
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Matrix4_arg mat, const char* name);

#endif

/// @}

/// @short
/// A 3x4 transformation matrix in array-of-structures format
///
/// A class representing a 3x4 transformation matrix
/// stored in array-of-structures (AoS) format.
///
class Transform3
{
	Vector3 mCol0;
	Vector3 mCol1;
	Vector3 mCol2;
	Vector3 mCol3;

public:
	/// @short
	/// Default constructor; does no initialization
	///
	/// Default constructor; does no initialization.
	///
	SCE_VECTORMATH_ALWAYS_INLINE Transform3();

	/// @short
	/// Construct a 3x4 transformation matrix containing the specified columns
	///
	/// Construct a 3x4 transformation matrix containing the specified columns.
	/// @param col0   3D vector
	/// @param col1   3D vector
	/// @param col2   3D vector
	/// @param col3   3D vector
	///
	SCE_VECTORMATH_INLINE Transform3(Vector3_arg col0, Vector3_arg col1, Vector3_arg col2, Vector3_arg col3);

	/// @short
	/// Construct a 3x4 transformation matrix from a 3x3 matrix and a 3D vector
	///
	/// Construct a 3x4 transformation matrix whose upper 3x3 elements are equal to the 3x3 matrix argument and whose translation component is equal to the 3D vector argument.
	/// @param tfrm   3x3 matrix
	/// @param translateVec   3D vector
	///
	SCE_VECTORMATH_INLINE Transform3(Matrix3_arg tfrm, Vector3_arg translateVec);

	/// @short
	/// Construct a 3x4 transformation matrix from a unit-length quaternion and a 3D vector
	///
	/// Construct a 3x4 transformation matrix whose upper-left 3x3 submatrix is a rotation matrix converted from the unit-length quaternion argument and whose translation component is equal to the 3D vector argument.
	/// @param unitQuat   Quaternion, expected to be unit-length
	/// @param translateVec   3D vector
	///
	SCE_VECTORMATH_INLINE Transform3(Quat_arg unitQuat, Vector3_arg translateVec);

	/// @short
	/// Set all elements of a 3x4 transformation matrix to the same scalar value
	///
	/// Construct a 3x4 transformation matrix with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Transform3(float scalar);

	/// @short
	/// Set all elements of a 3x4 transformation matrix to the same scalar value
	///
	/// Construct a 3x4 transformation matrix with all elements set to the scalar value argument.
	/// @param scalar   Scalar value
	///
	explicit SCE_VECTORMATH_INLINE Transform3(floatInVec_arg scalar);

	/// @short
	/// Assign one 3x4 transformation matrix to another
	///
	/// Assign one 3x4 transformation matrix to another.
	/// @param tfrm   3x4 transformation matrix
	/// @return
	/// A reference to the resulting 3x4 transformation matrix
	///
	SCE_VECTORMATH_INLINE Transform3& operator =(Transform3_arg tfrm);

	/// @short
	/// Set the upper-left 3x3 submatrix
	///
	/// Set the upper-left 3x3 submatrix elements of a 3x4 transformation matrix equal to the specified 3x3 matrix.
	/// @param mat3   3x3 matrix
	/// @return
	/// A reference to the resulting 3x4 transformation matrix
	///
	SCE_VECTORMATH_INLINE Transform3& setUpper3x3(Matrix3_arg mat3);

	/// @short
	/// Get the upper-left 3x3 submatrix of a 3x4 transformation matrix
	///
	/// Get the upper-left 3x3 submatrix of a 3x4 transformation matrix.
	/// @return
	/// Upper-left 3x3 submatrix
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Matrix3 getUpper3x3() const;

	/// @short
	/// Set translation component
	///
	/// Set the translation component of a 3x4 transformation matrix equal to the specified 3D vector.
	/// @param translateVec   3D vector
	/// @return
	/// A reference to the resulting 3x4 transformation matrix
	///
	SCE_VECTORMATH_INLINE Transform3& setTranslation(Vector3_arg translateVec);

	/// @short
	/// Get the translation component of a 3x4 transformation matrix
	///
	/// Get the translation component of a 3x4 transformation matrix.
	/// @return
	/// Translation component
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector3 getTranslation() const;

	/// @short
	/// Set column 0 of a 3x4 transformation matrix
	///
	/// Set column 0 of a 3x4 transformation matrix.
	/// @param col0   3D vector
	/// @return
	/// A reference to the resulting 3x4 transformation matrix
	///
	SCE_VECTORMATH_INLINE Transform3& setCol0(Vector3_arg col0);

	/// @short
	/// Set column 1 of a 3x4 transformation matrix
	///
	/// Set column 1 of a 3x4 transformation matrix.
	/// @param col1   3D vector
	/// @return
	/// A reference to the resulting 3x4 transformation matrix
	///
	SCE_VECTORMATH_INLINE Transform3& setCol1(Vector3_arg col1);

	/// @short
	/// Set column 2 of a 3x4 transformation matrix
	///
	/// Set column 2 of a 3x4 transformation matrix.
	/// @param col2   3D vector
	/// @return
	/// A reference to the resulting 3x4 transformation matrix
	///
	SCE_VECTORMATH_INLINE Transform3& setCol2(Vector3_arg col2);

	/// @short
	/// Set column 3 of a 3x4 transformation matrix
	///
	/// Set column 3 of a 3x4 transformation matrix.
	/// @param col3   3D vector
	/// @return
	/// A reference to the resulting 3x4 transformation matrix
	///
	SCE_VECTORMATH_INLINE Transform3& setCol3(Vector3_arg col3);

	/// @short
	/// Get column 0 of a 3x4 transformation matrix
	///
	/// Get column 0 of a 3x4 transformation matrix.
	/// @return
	/// Column 0
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector3 getCol0() const;

	/// @short
	/// Get column 1 of a 3x4 transformation matrix
	///
	/// Get column 1 of a 3x4 transformation matrix.
	/// @return
	/// Column 1
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector3 getCol1() const;

	/// @short
	/// Get column 2 of a 3x4 transformation matrix
	///
	/// Get column 2 of a 3x4 transformation matrix.
	/// @return
	/// Column 2
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector3 getCol2() const;

	/// @short
	/// Get column 3 of a 3x4 transformation matrix
	///
	/// Get column 3 of a 3x4 transformation matrix.
	/// @return
	/// Column 3
	///
	SCE_VECTORMATH_ALWAYS_INLINE const Vector3 getCol3() const;

	/// @short
	/// Set the column of a 3x4 transformation matrix referred to by the specified index
	///
	/// Set the column of a 3x4 transformation matrix referred to by the specified index.
	/// @param col   Index, expected in the range 0-3
	/// @param vec   3D vector
	/// @return
	/// A reference to the resulting 3x4 transformation matrix
	///
	SCE_VECTORMATH_INLINE Transform3& setCol(int col, Vector3_arg vec);

	/// @short
	/// Set the row of a 3x4 transformation matrix referred to by the specified index
	///
	/// Set the row of a 3x4 transformation matrix referred to by the specified index.
	/// @param row   Index, expected in the range 0-2
	/// @param vec   4D vector
	/// @return
	/// A reference to the resulting 3x4 transformation matrix
	///
	SCE_VECTORMATH_INLINE Transform3& setRow(int row, Vector4_arg vec);

	/// @short
	/// Get the column of a 3x4 transformation matrix referred to by the specified index
	///
	/// Get the column of a 3x4 transformation matrix referred to by the specified index.
	/// @param col   Index, expected in the range 0-3
	/// @return
	/// The column referred to by the specified index
	///
	SCE_VECTORMATH_INLINE const Vector3 getCol(int col) const;

	/// @short
	/// Get the row of a 3x4 transformation matrix referred to by the specified index
	///
	/// Get the row of a 3x4 transformation matrix referred to by the specified index.
	/// @param row   Index, expected in the range 0-2
	/// @return
	/// The row referred to by the specified index
	///
	SCE_VECTORMATH_INLINE const Vector4 getRow(int row) const;

	/// @short
	/// Subscripting operator to set or get a column
	///
	/// Subscripting operator invoked when applied to non-const Transform3.
	/// @param col   Index, expected in the range 0-3
	/// @return
	/// A reference to the indexed column
	///
	SCE_VECTORMATH_INLINE Vector3& operator [](int col);

	/// @short
	/// Subscripting operator to get a column
	///
	/// Subscripting operator invoked when applied to const Transform3.
	/// @param col   Index, expected in the range 0-3
	/// @return
	/// Indexed column
	///
	SCE_VECTORMATH_INLINE const Vector3 operator [](int col) const;

	/// @short
	/// Set the element of a 3x4 transformation matrix referred to by column and row indices
	///
	/// Set the element of a 3x4 transformation matrix referred to by column and row indices.
	/// @param col   Index, expected in the range 0-3
	/// @param row   Index, expected in the range 0-2
	/// @param val   Scalar value
	/// @return
	/// A reference to the resulting 3x4 transformation matrix
	///
	SCE_VECTORMATH_INLINE Transform3& setElem(int col, int row, float val);

	/// @short
	/// Set the element of a 3x4 transformation matrix referred to by column and row indices
	///
	/// Set the element of a 3x4 transformation matrix referred to by column and row indices.
	/// @param col   Index, expected in the range 0-3
	/// @param row   Index, expected in the range 0-2
	/// @param val   Scalar value
	/// @return
	/// A reference to the resulting 3x4 transformation matrix
	///
	SCE_VECTORMATH_INLINE Transform3& setElem(int col, int row, floatInVec_arg val);

	/// @short
	/// Get the element of a 3x4 transformation matrix referred to by column and row indices
	///
	/// Get the element of a 3x4 transformation matrix referred to by column and row indices.
	/// @param col   Index, expected in the range 0-3
	/// @param row   Index, expected in the range 0-2
	/// @return
	/// Element selected by <code><i>col</i></code> and <code><i>row</i></code>
	///
	SCE_VECTORMATH_INLINE const floatInVec getElem(int col, int row) const;

	/// @short
	/// Multiply a 3x4 transformation matrix by a 3D vector
	///
	/// Applies the 3x3 upper-left submatrix (but not the translation component) of a 3x4 transformation matrix to a 3D vector.
	/// @param vec   3D vector
	/// @return
	/// Product of the specified 3x4 transformation matrix and 3D vector
	///
	SCE_VECTORMATH_INLINE const Vector3 operator *(Vector3_arg vec) const;

	/// @short
	/// Multiply a 3x4 transformation matrix by a 3D point
	///
	/// Applies the 3x3 upper-left submatrix and the translation component of a 3x4 transformation matrix to a 3D point.
	/// @param pnt   3D point
	/// @return
	/// Product of the specified 3x4 transformation matrix and 3D point
	///
	SCE_VECTORMATH_INLINE const Point3 operator *(Point3_arg pnt) const;

	/// @short
	/// Multiply two 3x4 transformation matrices
	///
	/// Multiply two 3x4 transformation matrices.
	/// @param tfrm   3x4 transformation matrix
	/// @return
	/// Product of the specified 3x4 transformation matrices
	///
	SCE_VECTORMATH_INLINE const Transform3 operator *(Transform3_arg tfrm) const;

	/// @short
	/// Perform compound assignment and multiplication by a 3x4 transformation matrix
	///
	/// Perform compound assignment and multiplication by a 3x4 transformation matrix.
	/// @param tfrm   3x4 transformation matrix
	/// @return
	/// A reference to the resulting 3x4 transformation matrix
	///
	SCE_VECTORMATH_INLINE Transform3& operator *=(Transform3_arg tfrm);

	/// @short
	/// Construct an identity 3x4 transformation matrix
	///
	/// Construct an identity 3x4 transformation matrix in which non-diagonal elements are zero and diagonal elements are 1.
	/// @return
	/// The constructed 3x4 transformation matrix
	///
	static SCE_VECTORMATH_INLINE const Transform3 identity();

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

	/// @short
	/// Construct a 3x4 transformation matrix to rotate around the x axis
	///
	/// Construct a 3x4 transformation matrix to rotate around the x axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 3x4 transformation matrix
	///
	static SCE_VECTORMATH_INLINE const Transform3 rotationX(float radians);

	/// @short
	/// Construct a 3x4 transformation matrix to rotate around the y axis
	///
	/// Construct a 3x4 transformation matrix to rotate around the y axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 3x4 transformation matrix
	///
	static SCE_VECTORMATH_INLINE const Transform3 rotationY(float radians);

	/// @short
	/// Construct a 3x4 transformation matrix to rotate around the z axis
	///
	/// Construct a 3x4 transformation matrix to rotate around the z axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 3x4 transformation matrix
	///
	static SCE_VECTORMATH_INLINE const Transform3 rotationZ(float radians);

	/// @short
	/// Construct a 3x4 transformation matrix to rotate around the x axis
	///
	/// Construct a 3x4 transformation matrix to rotate around the x axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 3x4 transformation matrix
	///
	static SCE_VECTORMATH_INLINE const Transform3 rotationX(floatInVec_arg radians);

	/// @short
	/// Construct a 3x4 transformation matrix to rotate around the y axis
	///
	/// Construct a 3x4 transformation matrix to rotate around the y axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 3x4 transformation matrix
	///
	static SCE_VECTORMATH_INLINE const Transform3 rotationY(floatInVec_arg radians);

	/// @short
	/// Construct a 3x4 transformation matrix to rotate around the z axis
	///
	/// Construct a 3x4 transformation matrix to rotate around the z axis by the specified radians angle.
	/// @param radians   Scalar value
	/// @return
	/// The constructed 3x4 transformation matrix
	///
	static SCE_VECTORMATH_INLINE const Transform3 rotationZ(floatInVec_arg radians);

	/// @short
	/// Construct a 3x4 transformation matrix to rotate around the x, y, and z axes
	///
	/// Construct a 3x4 transformation matrix to rotate around the x, y, and z axes by the radians
	///         angles contained in a 3D vector.  Equivalent to <code>rotationZ(radiansXYZ.getZ()) * rotationY(radiansXYZ.getY()) * rotationX(radiansXYZ.getX())</code>.
	/// @param radiansXYZ   3D vector
	/// @return
	/// The constructed 3x4 transformation matrix
	///
	static SCE_VECTORMATH_INLINE const Transform3 rotationZYX(Vector3_arg radiansXYZ);

	/// @short
	/// Construct a 3x4 transformation matrix to rotate around a unit-length 3D vector
	///
	/// Construct a 3x4 transformation matrix to rotate around a unit-length 3D vector by the specified radians angle.
	/// @param radians   Scalar value
	/// @param unitVec   3D vector, expected to be unit-length
	/// @return
	/// The constructed 3x4 transformation matrix
	///
	static SCE_VECTORMATH_INLINE const Transform3 rotation(float radians, Vector3_arg unitVec);

	/// @short
	/// Construct a 3x4 transformation matrix to rotate around a unit-length 3D vector
	///
	/// Construct a 3x4 transformation matrix to rotate around a unit-length 3D vector by the specified radians angle.
	/// @param radians   Scalar value
	/// @param unitVec   3D vector, expected to be unit-length
	/// @return
	/// The constructed 3x4 transformation matrix
	///
	static SCE_VECTORMATH_INLINE const Transform3 rotation(floatInVec_arg radians, Vector3_arg unitVec);

	/// @short
	/// Construct a rotation matrix from a unit-length quaternion
	///
	/// Construct a 3x4 transformation matrix that applies the same rotation as the specified unit-length quaternion.
	/// @param unitQuat   Quaternion, expected to be unit-length
	/// @return
	/// The constructed 3x4 transformation matrix
	///
	static SCE_VECTORMATH_INLINE const Transform3 rotation(Quat_arg unitQuat);

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

	/// @short
	/// Construct a 3x4 transformation matrix to perform scaling
	///
	/// Construct a 3x4 transformation matrix to perform scaling, in which the non-diagonal elements are zero and the diagonal elements are set to the elements of <code><i>scaleVec</i></code>.
	/// @param scaleVec   3D vector
	/// @return
	/// The constructed 3x4 transformation matrix
	///
	static SCE_VECTORMATH_INLINE const Transform3 scale(Vector3_arg scaleVec);

	/// @short
	/// Construct a 3x4 transformation matrix to perform translation
	///
	/// Construct a 3x4 transformation matrix to perform translation, which is an identity matrix except for the translation component, with coordinates equal to those in <code><i>translateVec</i></code>.
	/// @param translateVec   3D vector
	/// @return
	/// The constructed 3x4 transformation matrix
	///
	static SCE_VECTORMATH_INLINE const Transform3 translation(Vector3_arg translateVec);

};
/// @name 3x4 Transformation Matrix Functions
/// @{

/// @short
/// Append (post-multiply) a scale transformation to a 3x4 transformation matrix
///
/// Post-multiply a 3x4 transformation matrix by a scale transformation whose diagonal scale factors are contained in the 3D vector.
/// @param tfrm   3x4 transformation matrix
/// @param scaleVec   3D vector
/// @return
/// The product of <code><i>tfrm</i></code> and a scale transformation created from <code><i>scaleVec</i></code>
/// @note
/// Faster than creating and multiplying a scale transformation matrix.
///
SCE_VECTORMATH_INLINE const Transform3 appendScale(Transform3_arg tfrm, Vector3_arg scaleVec);

/// @short
/// Prepend (pre-multiply) a scale transformation to a 3x4 transformation matrix
///
/// Pre-multiply a 3x4 transformation matrix by a scale transformation whose diagonal scale factors are contained in the 3D vector.
/// @param scaleVec   3D vector
/// @param tfrm   3x4 transformation matrix
/// @return
/// The product of a scale transformation created from <code><i>scaleVec</i></code> and <code><i>tfrm</i></code>
/// @note
/// Faster than creating and multiplying a scale transformation matrix.
///
SCE_VECTORMATH_INLINE const Transform3 prependScale(Vector3_arg scaleVec, Transform3_arg tfrm);

/// @short
/// Multiply two 3x4 transformation matrices per element
///
/// Multiply two 3x4 transformation matrices element by element.
/// @param tfrm0   3x4 transformation matrix
/// @param tfrm1   3x4 transformation matrix
/// @return
/// 3x4 transformation matrix in which each element is the product of the corresponding elements of the specified 3x4 transformation matrices
///
SCE_VECTORMATH_INLINE const Transform3 mulPerElem(Transform3_arg tfrm0, Transform3_arg tfrm1);

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

/// @short
/// Compute the absolute value of a 3x4 transformation matrix per element
///
/// Compute the absolute value of each element of a 3x4 transformation matrix.
/// @param tfrm   3x4 transformation matrix
/// @return
/// 3x4 transformation matrix in which each element is the absolute value of the corresponding element of the specified 3x4 transformation matrix
///
SCE_VECTORMATH_INLINE const Transform3 absPerElem(Transform3_arg tfrm);

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

/// @short
/// Inverse of a 3x4 transformation matrix
///
/// Compute the inverse of a 3x4 transformation matrix.
/// @param tfrm   3x4 transformation matrix
/// @return
/// Inverse of <code><i>tfrm</i></code>
/// @note
/// Result is unpredictable when the determinant of the left 3x3 submatrix is equal to or near 0.
///
SCE_VECTORMATH_INLINE const Transform3 inverse(Transform3_arg tfrm);

/// @short
/// Compute the inverse of a 3x4 transformation matrix, expected to have an orthogonal upper-left 3x3 submatrix
///
/// Naming the upper-left 3x3 submatrix of the specified 3x4 transformation matrix as <code>M</code>, and its translation component as <code>v</code>, compute a matrix whose upper-left 3x3 submatrix is <code>transpose(M)</code>, and whose translation vector is <code>-transpose(M)*v</code>.
/// @param tfrm   3x4 transformation matrix
/// @return
/// Inverse of the specified 3x4 transformation matrix
/// @note
/// This can be used to achieve better performance than a general inverse when the specified 3x4 transformation matrix meets the given restrictions.
///
SCE_VECTORMATH_INLINE const Transform3 orthoInverse(Transform3_arg tfrm);

/// @short
/// Conditionally select between two 3x4 transformation matrices
///
/// Conditionally select one of the 3x4 transformation matrix arguments.
/// @param tfrm0   3x4 transformation matrix
/// @param tfrm1   3x4 transformation matrix
/// @param select1   False selects the <code><i>tfrm0</i></code> argument; true selects the <code><i>tfrm1</i></code> argument
/// @return
/// Equal to <code><i>tfrm0</i></code> if <code><i>select1</i></code> is false, or to <code><i>tfrm1</i></code> if <code><i>select1</i></code> is true
///
SCE_VECTORMATH_INLINE const Transform3 select(Transform3_arg tfrm0, Transform3_arg tfrm1, bool select1);


/// @short
/// Conditionally select between two 3x4 transformation matrices
///
/// Conditionally select one of the 3x4 transformation matrix arguments.
/// @param tfrm0   3x4 transformation matrix
/// @param tfrm1   3x4 transformation matrix
/// @param select1   False selects the <code><i>tfrm0</i></code> argument; true selects the <code><i>tfrm1</i></code> argument
/// @return
/// Equal to <code><i>tfrm0</i></code> if <code><i>select1</i></code> is false, or to <code><i>tfrm1</i></code> if <code><i>select1</i></code> is true
/// @note
/// This function uses a conditional select instruction to avoid a branch.
///
SCE_VECTORMATH_INLINE const Transform3 select(Transform3_arg tfrm0, Transform3_arg tfrm1, boolInVec_arg select1);

#ifdef SCE_VECTORMATH_DEBUG

/// @short
/// Print a 3x4 transformation matrix
///
/// Print a 3x4 transformation matrix.  Unlike the printing of vectors, the 3x4 transformation matrix is printed with the correct orientation (columns appear vertically).
/// @param tfrm   3x4 transformation matrix
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Transform3_arg tfrm);

/// @short
/// Print a 3x4 transformation matrix and an associated string identifier
///
/// Print a 3x4 transformation matrix and an associated string identifier.  Unlike the printing of vectors, the 3x4 transformation matrix is printed with the correct orientation (columns appear vertically).
/// @param tfrm   3x4 transformation matrix
/// @param name   String printed with the 3x4 transformation matrix
/// @note
/// Function is only defined when <code>SCE_VECTORMATH_DEBUG</code> is defined.
///
SCE_VECTORMATH_INLINE void print(Transform3_arg tfrm, const char* name);

#endif

/// @}

} // namespace Aos
} // namespace Scalar
} // namespace Vectormath
} // namespace sce

#ifdef SCE_VECTORMATH_DEBUG
  #if defined(__SPU__)
    #include <spu_printf.h>
    #define sce_vectormath_printf spu_printf
  #else
    #include <stdio.h>
    #define sce_vectormath_printf printf
  #endif
#else
  #define sce_vectormath_printf(...)
#endif

#include <psp2/vectormath/scalar_cpp/vec_aos.h>
#include <psp2/vectormath/scalar_cpp/quat_aos.h>
#include <psp2/vectormath/scalar_cpp/mat_aos.h>

#endif /* _PSP2_VECTORMATH_SCALAR_AOS_CPP_H_ */
