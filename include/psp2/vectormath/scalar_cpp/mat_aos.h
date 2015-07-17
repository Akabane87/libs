/**
 * \file mat_aos.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_VECTORMATH_SCALAR_MAT_AOS_CPP_H_
#define _PSP2_VECTORMATH_SCALAR_MAT_AOS_CPP_H_

namespace sce {
namespace Vectormath {
namespace Scalar {
namespace Aos {

//-----------------------------------------------------------------------------
// Constants

#define _SCE_VECTORMATH_PI_OVER_2 1.570796327f

//-----------------------------------------------------------------------------
// Definitions

SCE_VECTORMATH_ALWAYS_INLINE Matrix2::Matrix2()
{
}

SCE_VECTORMATH_INLINE Matrix2::Matrix2(Vector2_arg col0, Vector2_arg col1)
{
	mMat = Vector4( col0, col1 );
}

SCE_VECTORMATH_INLINE Matrix2::Matrix2(float scalar)
{
	mMat = Vector4(scalar);
}

SCE_VECTORMATH_INLINE Matrix2::Matrix2(floatInVec_arg scalar)
{
	mMat = Vector4(scalar.getAsFloat());
}

SCE_VECTORMATH_INLINE Matrix2::Matrix2(Vector4_arg mat)
{
	mMat = mat;
}

SCE_VECTORMATH_INLINE Matrix2& Matrix2::operator =(Matrix2_arg mat)
{
	mMat = mat.mMat;
	return *this;
}

SCE_VECTORMATH_INLINE Matrix2& Matrix2::setCol0(Vector2_arg col0)
{
	mMat.setX( col0.getX().getAsFloat() );
	mMat.setY( col0.getY().getAsFloat() );
	return *this;
}

SCE_VECTORMATH_INLINE Matrix2& Matrix2::setCol1(Vector2_arg col1)
{
	mMat.setZ( col1.getX().getAsFloat() );
	mMat.setW( col1.getY().getAsFloat() );
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector2 Matrix2::getCol0() const
{
	return Vector2( mMat.getX().getAsFloat(), mMat.getY().getAsFloat() );
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector2 Matrix2::getCol1() const
{
	return Vector2( mMat.getZ().getAsFloat(), mMat.getW().getAsFloat() );
}

SCE_VECTORMATH_INLINE Matrix2& Matrix2::setCol(int col, Vector2_arg vec)
{
	SCE_VECTORMATH_ASSERT_MSG( ( 0 == col ) || ( 1 == col ), "Column Index Out of Range" );
	if( col ) {
		setCol1( vec );
	} else {
		setCol0( vec );
	}
	return *this;
}

SCE_VECTORMATH_INLINE Matrix2& Matrix2::setRow(int row, Vector2_arg vec)
{
	SCE_VECTORMATH_ASSERT_MSG( ( 0 == row ) || ( 1 == row ), "Row Index Out of Range" );
	if( row ) {
		mMat.setY( vec.getX().getAsFloat() );
		mMat.setW( vec.getY().getAsFloat() );
	} else {
		mMat.setX( vec.getX().getAsFloat() );
		mMat.setZ( vec.getY().getAsFloat() );
	}
	return *this;
}

SCE_VECTORMATH_INLINE const Vector2 Matrix2::getCol(int col) const
{
	SCE_VECTORMATH_ASSERT_MSG( ( 0 == col ) || ( 1 == col ), "Column Index Out of Range" );
	return ( col ? getCol1() : getCol0() );
}

SCE_VECTORMATH_INLINE const Vector2 Matrix2::getRow(int row) const
{
	SCE_VECTORMATH_ASSERT_MSG( ( 0 == row ) || ( 1 == row ), "Row Index Out of Range" );
	if( row ) {
		return Vector2( mMat.getY().getAsFloat(), mMat.getW().getAsFloat() );
	} else {
		return Vector2( mMat.getX().getAsFloat(), mMat.getZ().getAsFloat() );
	}
}

SCE_VECTORMATH_INLINE const Vector2 Matrix2::operator [](int col) const
{
	return getCol(col);
}

SCE_VECTORMATH_INLINE Matrix2& Matrix2::setElem(int col, int row, float val)
{
	SCE_VECTORMATH_ASSERT_MSG( ( 0 == col ) || ( 1 == col ), "Column Index Out of Range" );
	SCE_VECTORMATH_ASSERT_MSG( ( 0 == row ) || ( 1 == row ), "Row Index Out of Range" );
	mMat.setElem( 2*col + row, val );
	return *this;
}

SCE_VECTORMATH_INLINE Matrix2& Matrix2::setElem(int col, int row, floatInVec_arg val)
{
	SCE_VECTORMATH_ASSERT_MSG( ( 0 == col ) || ( 1 == col ), "Column Index Out of Range" );
	SCE_VECTORMATH_ASSERT_MSG( ( 0 == row ) || ( 1 == row ), "Row Index Out of Range" );
	mMat.setElem( 2*col + row, val.getAsFloat() );
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Matrix2::getElem(int col, int row) const
{
	return mMat.getElem( 2*col + row );
}

SCE_VECTORMATH_INLINE const Matrix2 Matrix2::operator +(Matrix2_arg mat) const
{
	return Matrix2( mMat + mat.mMat );
}

SCE_VECTORMATH_INLINE const Matrix2 Matrix2::operator -(Matrix2_arg mat) const
{
	return Matrix2( mMat - mat.mMat );
}

SCE_VECTORMATH_INLINE const Matrix2 Matrix2::operator -() const
{
	return Matrix2( -mMat );
}

SCE_VECTORMATH_INLINE const Matrix2 Matrix2::operator *(float scalar) const
{
	return Matrix2( mMat * scalar );
}

SCE_VECTORMATH_INLINE const Matrix2 Matrix2::operator *(floatInVec_arg scalar) const
{
	return Matrix2( mMat * scalar.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Vector2 Matrix2::operator *(Vector2_arg vec) const
{
	float xv = vec.getX().getAsFloat();
	float yv = vec.getY().getAsFloat();
	return Vector2(
		( ( ( getCol0().getX().getAsFloat() * xv ) + ( getCol1().getX().getAsFloat() * yv ) ) ),
		( ( ( getCol0().getY().getAsFloat() * xv ) + ( getCol1().getY().getAsFloat() * yv ) ) )
	);
}

SCE_VECTORMATH_INLINE const Matrix2 Matrix2::operator *(Matrix2_arg mat) const
{
	return Matrix2(
		( *this * mat.getCol0() ),
		( *this * mat.getCol1() )
		);
}

SCE_VECTORMATH_INLINE Matrix2& Matrix2::operator +=(Matrix2_arg mat)
{
	return *this = *this + mat;
}

SCE_VECTORMATH_INLINE Matrix2& Matrix2::operator -=(Matrix2_arg mat)
{
	return *this = *this - mat;
}

SCE_VECTORMATH_INLINE Matrix2& Matrix2::operator *=(float scalar)
{
	return *this = *this * scalar;
}

SCE_VECTORMATH_INLINE Matrix2& Matrix2::operator *=(floatInVec_arg scalar)
{
	return *this = *this * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE Matrix2& Matrix2::operator *=(Matrix2_arg mat)
{
	return *this = *this * mat;
}

SCE_VECTORMATH_INLINE const Matrix2 Matrix2::identity()
{
	return Matrix2(
		Vector2::xAxis(),
		Vector2::yAxis()
	);
}

SCE_VECTORMATH_INLINE const Matrix2 Matrix2::zero()
{
	return Matrix2( Vector4::zero() );
}

#if	!defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Matrix2 Matrix2::rotation(float radians)
{
	float s = ::sinf( radians );
	float c = ::cosf( radians );
	return Matrix2(
		Vector2(  c, s ),
		Vector2( -s, c )
		);
}

SCE_VECTORMATH_INLINE const Matrix2 Matrix2::rotation(floatInVec_arg radians)
{
	return rotation( radians.getAsFloat() );
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Matrix2 Matrix2::scale(Vector2_arg scaleVec)
{
	return Matrix2(
		Vector2( scaleVec.getX().getAsFloat(), 0.0f ),
		Vector2( 0.0f, scaleVec.getY().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Matrix2 operator *(float scalar, Matrix2_arg mat)
{
	return mat * scalar;
}

SCE_VECTORMATH_INLINE const Matrix2 operator *(floatInVec_arg scalar, Matrix2_arg mat)
{
	return mat * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Matrix2 appendScale(Matrix2_arg mat, Vector2_arg scaleVec)
{
	return Matrix2(
		mat.getCol0() * scaleVec.getX().getAsFloat(),
		mat.getCol1() * scaleVec.getY().getAsFloat()
		);
}

SCE_VECTORMATH_INLINE const Matrix2 prependScale(Vector2_arg scaleVec, Matrix2_arg mat)
{
	return Matrix2(
		mulPerElem( mat.getCol0(), scaleVec ),
		mulPerElem( mat.getCol1(), scaleVec )
		);
}

SCE_VECTORMATH_INLINE const Matrix2 mulPerElem(Matrix2_arg mat0, Matrix2_arg mat1)
{
	return Matrix2( mulPerElem( mat0.getCol0(), mat1.getCol0() ), mulPerElem( mat0.getCol1(), mat1.getCol1() ) );
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Matrix2 absPerElem(Matrix2_arg mat)
{
	return Matrix2( absPerElem( mat.getCol0() ), absPerElem( mat.getCol1() ) );
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Matrix2 transpose(Matrix2_arg mat)
{
	return Matrix2(
		Vector2( mat.getCol0().getX().getAsFloat(), mat.getCol1().getX().getAsFloat() ),
		Vector2( mat.getCol0().getY().getAsFloat(), mat.getCol1().getY().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Matrix2 inverse(Matrix2_arg mat)
{
	float detinv = 1.0f / determinant( mat ).getAsFloat();
	return Matrix2(
		Vector2(  mat.getCol1().getY().getAsFloat(), -mat.getCol0().getY().getAsFloat() ) * detinv,
		Vector2( -mat.getCol1().getX().getAsFloat(),  mat.getCol0().getX().getAsFloat() ) * detinv
		);
}

SCE_VECTORMATH_INLINE const floatInVec determinant(Matrix2_arg mat)
{
	return floatInVec( mat.getCol1().getY().getAsFloat() * mat.getCol0().getX().getAsFloat() - mat.getCol1().getX().getAsFloat() * mat.getCol0().getY().getAsFloat() );
}

SCE_VECTORMATH_INLINE const Matrix2 select(Matrix2_arg mat0, Matrix2_arg mat1, bool select1)
{
	return (select1 ? mat1 : mat0);
}

SCE_VECTORMATH_INLINE const Matrix2 select(Matrix2_arg mat0, Matrix2_arg mat1, boolInVec_arg select1)
{
	return (select1.getAsBool() ? mat1 : mat0);
}

#ifdef SCE_VECTORMATH_DEBUG

SCE_VECTORMATH_INLINE void print(Matrix2_arg mat)
{
	print(mat.getRow(0));
	print(mat.getRow(1));
}

SCE_VECTORMATH_INLINE void print(Matrix2_arg mat, const char* name)
{
	sce_vectormath_printf("%s:\n", name);
	print(mat);
}

#endif	/* SCE_VECTORMATH_DEBUG */

SCE_VECTORMATH_ALWAYS_INLINE Matrix3::Matrix3()
{
}

SCE_VECTORMATH_INLINE Matrix3::Matrix3(Vector3_arg col0, Vector3_arg col1, Vector3_arg col2)
{
	mCol0 = col0;
	mCol1 = col1;
	mCol2 = col2;
}

SCE_VECTORMATH_INLINE Matrix3::Matrix3(Quat_arg unitQuat)
{
	float qx, qy, qz, qw, qx2, qy2, qz2, qxqx2, qyqy2, qzqz2, qxqy2, qyqz2, qzqw2, qxqz2, qyqw2, qxqw2;
	qx = unitQuat.getX().getAsFloat();
	qy = unitQuat.getY().getAsFloat();
	qz = unitQuat.getZ().getAsFloat();
	qw = unitQuat.getW().getAsFloat();
	qx2 = ( qx + qx );
	qy2 = ( qy + qy );
	qz2 = ( qz + qz );
	qxqx2 = ( qx * qx2 );
	qxqy2 = ( qx * qy2 );
	qxqz2 = ( qx * qz2 );
	qxqw2 = ( qw * qx2 );
	qyqy2 = ( qy * qy2 );
	qyqz2 = ( qy * qz2 );
	qyqw2 = ( qw * qy2 );
	qzqz2 = ( qz * qz2 );
	qzqw2 = ( qw * qz2 );
	mCol0 = Vector3( ( ( 1.0f - qyqy2 ) - qzqz2 ), ( qxqy2 + qzqw2 ), ( qxqz2 - qyqw2 ) );
	mCol1 = Vector3( ( qxqy2 - qzqw2 ), ( ( 1.0f - qxqx2 ) - qzqz2 ), ( qyqz2 + qxqw2 ) );
	mCol2 = Vector3( ( qxqz2 + qyqw2 ), ( qyqz2 - qxqw2 ), ( ( 1.0f - qxqx2 ) - qyqy2 ) );
}

SCE_VECTORMATH_INLINE Matrix3::Matrix3(float scalar)
{
	mCol0 = Vector3(scalar);
	mCol1 = Vector3(scalar);
	mCol2 = Vector3(scalar);
}

SCE_VECTORMATH_INLINE Matrix3::Matrix3(floatInVec_arg scalar)
{
	mCol0 = Vector3(scalar.getAsFloat());
	mCol1 = Vector3(scalar.getAsFloat());
	mCol2 = Vector3(scalar.getAsFloat());
}

SCE_VECTORMATH_INLINE Matrix3& Matrix3::operator =(Matrix3_arg mat)
{
	mCol0 = mat.mCol0;
	mCol1 = mat.mCol1;
	mCol2 = mat.mCol2;
	return *this;
}

SCE_VECTORMATH_INLINE Matrix3& Matrix3::setCol0(Vector3_arg col0)
{
	mCol0 = col0;
	return *this;
}

SCE_VECTORMATH_INLINE Matrix3& Matrix3::setCol1(Vector3_arg col1)
{
	mCol1 = col1;
	return *this;
}

SCE_VECTORMATH_INLINE Matrix3& Matrix3::setCol2(Vector3_arg col2)
{
	mCol2 = col2;
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector3 Matrix3::getCol0() const
{
	return mCol0;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector3 Matrix3::getCol1() const
{
	return mCol1;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector3 Matrix3::getCol2() const
{
	return mCol2;
}

SCE_VECTORMATH_INLINE Matrix3& Matrix3::setCol(int col, Vector3_arg vec)
{
	*(&mCol0 + col) = vec;
	return *this;
}

SCE_VECTORMATH_INLINE Matrix3& Matrix3::setRow(int row, Vector3_arg vec)
{
	mCol0.setElem(row, vec.getX().getAsFloat());
	mCol1.setElem(row, vec.getY().getAsFloat());
	mCol2.setElem(row, vec.getZ().getAsFloat());
	return *this;
}

SCE_VECTORMATH_INLINE const Vector3 Matrix3::getCol(int col) const
{
	return *(&mCol0 + col);
}

SCE_VECTORMATH_INLINE const Vector3 Matrix3::getRow(int row) const
{
	return Vector3(
		mCol0.getElem(row),
		mCol1.getElem(row),
		mCol2.getElem(row)
		);
}

SCE_VECTORMATH_INLINE Vector3& Matrix3::operator [](int col)
{
	return *(&mCol0 + col);
}

SCE_VECTORMATH_INLINE const Vector3 Matrix3::operator [](int col) const
{
	return *(&mCol0 + col);
}

SCE_VECTORMATH_INLINE Matrix3& Matrix3::setElem(int col, int row, float val)
{
	(*this)[col].setElem(row, val);
	return *this;
}

SCE_VECTORMATH_INLINE Matrix3& Matrix3::setElem(int col, int row, floatInVec_arg val)
{
	(*this)[col].setElem(row, val);
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Matrix3::getElem(int col, int row) const
{
	return getCol(col).getElem(row);
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::operator +(Matrix3_arg mat) const
{
	return Matrix3(
		mCol0 + mat.mCol0,
		mCol1 + mat.mCol1,
		mCol2 + mat.mCol2
		);
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::operator -(Matrix3_arg mat) const
{
	return Matrix3(
		mCol0 - mat.mCol0,
		mCol1 - mat.mCol1,
		mCol2 - mat.mCol2
		);
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::operator -() const
{
	return Matrix3(
		-mCol0,
		-mCol1,
		-mCol2
		);
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::operator *(float scalar) const
{
	return Matrix3(
		mCol0 * scalar,
		mCol1 * scalar,
		mCol2 * scalar
		);
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::operator *(floatInVec_arg scalar) const
{
	return *this * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Vector3 Matrix3::operator *(Vector3_arg vec) const
{
	return Vector3(
		( ( ( mCol0.getX().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getX().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getX().getAsFloat() * vec.getZ().getAsFloat() ) ),
		( ( ( mCol0.getY().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getY().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getY().getAsFloat() * vec.getZ().getAsFloat() ) ),
		( ( ( mCol0.getZ().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getZ().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getZ().getAsFloat() * vec.getZ().getAsFloat() ) )
		);
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::operator *(Matrix3_arg mat) const
{
	return Matrix3(
		(*this * mat.mCol0),
		(*this * mat.mCol1),
		(*this * mat.mCol2)
		);
}

SCE_VECTORMATH_INLINE Matrix3& Matrix3::operator +=(Matrix3_arg mat)
{
	return *this = *this + mat;
}

SCE_VECTORMATH_INLINE Matrix3& Matrix3::operator -=(Matrix3_arg mat)
{
	return *this = *this - mat;
}

SCE_VECTORMATH_INLINE Matrix3& Matrix3::operator *=(float scalar)
{
	return *this = *this * floatInVec(scalar);
}

SCE_VECTORMATH_INLINE Matrix3& Matrix3::operator *=(floatInVec_arg scalar)
{
	return *this = *this * scalar;
}

SCE_VECTORMATH_INLINE Matrix3& Matrix3::operator *=(Matrix3_arg mat)
{
	return *this = *this * mat;
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::identity()
{
	return Matrix3(
		Vector3::xAxis(),
		Vector3::yAxis(),
		Vector3::zAxis()
		);
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::zero()
{
	return Matrix3(
		Vector3::zero(),
		Vector3::zero(),
		Vector3::zero()
		);
}

#if	!defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::rotationX(float radians)
{
	float s, c;
	s = ::sinf( radians );
	c = ::cosf( radians );
	return Matrix3(
		Vector3::xAxis( ),
		Vector3( 0.0f, c, s ),
		Vector3( 0.0f, -s, c )
		);
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::rotationY(float radians)
{
	float s, c;
	s = ::sinf( radians );
	c = ::cosf( radians );
	return Matrix3(
		Vector3( c, 0.0f, -s ),
		Vector3::yAxis( ),
		Vector3( s, 0.0f, c )
		);
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::rotationZ(float radians)
{
	float s, c;
	s = ::sinf( radians );
	c = ::cosf( radians );
	return Matrix3(
		Vector3( c, s, 0.0f ),
		Vector3( -s, c, 0.0f ),
		Vector3::zAxis( )
		);
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::rotationX(floatInVec_arg radians)
{
	return rotationX( radians.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::rotationY(floatInVec_arg radians)
{
	return rotationY( radians.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::rotationZ(floatInVec_arg radians)
{
	return rotationZ( radians.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::rotationZYX(Vector3_arg radiansXYZ)
{
	float sX, cX, sY, cY, sZ, cZ, tmp0, tmp1;
	sX = ::sinf( radiansXYZ.getX().getAsFloat() );
	cX = ::cosf( radiansXYZ.getX().getAsFloat() );
	sY = ::sinf( radiansXYZ.getY().getAsFloat() );
	cY = ::cosf( radiansXYZ.getY().getAsFloat() );
	sZ = ::sinf( radiansXYZ.getZ().getAsFloat() );
	cZ = ::cosf( radiansXYZ.getZ().getAsFloat() );
	tmp0 = ( cZ * sY );
	tmp1 = ( sZ * sY );
	return Matrix3(
		Vector3( ( cZ * cY ), ( sZ * cY ), -sY ),
		Vector3( ( ( tmp0 * sX ) - ( sZ * cX ) ), ( ( tmp1 * sX ) + ( cZ * cX ) ), ( cY * sX ) ),
		Vector3( ( ( tmp0 * cX ) + ( sZ * sX ) ), ( ( tmp1 * cX ) - ( cZ * sX ) ), ( cY * cX ) )
		);
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::rotation(float radians, Vector3_arg unitVec)
{
	float x, y, z, s, c, oneMinusC, xy, yz, zx;
	s = ::sinf( radians );
	c = ::cosf( radians );
	x = unitVec.getX().getAsFloat();
	y = unitVec.getY().getAsFloat();
	z = unitVec.getZ().getAsFloat();
	xy = ( x * y );
	yz = ( y * z );
	zx = ( z * x );
	oneMinusC = ( 1.0f - c );
	return Matrix3(
		Vector3( ( ( ( x * x ) * oneMinusC ) + c ), ( ( xy * oneMinusC ) + ( z * s ) ), ( ( zx * oneMinusC ) - ( y * s ) ) ),
		Vector3( ( ( xy * oneMinusC ) - ( z * s ) ), ( ( ( y * y ) * oneMinusC ) + c ), ( ( yz * oneMinusC ) + ( x * s ) ) ),
		Vector3( ( ( zx * oneMinusC ) + ( y * s ) ), ( ( yz * oneMinusC ) - ( x * s ) ), ( ( ( z * z ) * oneMinusC ) + c ) )
		);
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::rotation(floatInVec_arg radians, Vector3_arg unitVec)
{
	return rotation(radians.getAsFloat(), unitVec);
}

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::rotation(Quat_arg unitQuat)
{
	return Matrix3(unitQuat);
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Matrix3 Matrix3::scale(Vector3_arg scaleVec)
{
	return Matrix3(
		Vector3( scaleVec.getX().getAsFloat(), 0.0f, 0.0f ),
		Vector3( 0.0f, scaleVec.getY().getAsFloat(), 0.0f ),
		Vector3( 0.0f, 0.0f, scaleVec.getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Matrix3 operator *(float scalar, Matrix3_arg mat)
{
	return mat * scalar;
}

SCE_VECTORMATH_INLINE const Matrix3 operator *(floatInVec_arg scalar, Matrix3_arg mat)
{
	return mat * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Matrix3 appendScale(Matrix3_arg mat, Vector3_arg scaleVec)
{
	return Matrix3(
		(mat.getCol0() * scaleVec.getX().getAsFloat()),
		(mat.getCol1() * scaleVec.getY().getAsFloat()),
		(mat.getCol2() * scaleVec.getZ().getAsFloat())
		);
}

SCE_VECTORMATH_INLINE const Matrix3 prependScale(Vector3_arg scaleVec, Matrix3_arg mat)
{
	return Matrix3(
		mulPerElem(mat.getCol0(), scaleVec),
		mulPerElem(mat.getCol1(), scaleVec),
		mulPerElem(mat.getCol2(), scaleVec)
		);
}

SCE_VECTORMATH_INLINE const Matrix3 mulPerElem(Matrix3_arg mat0, Matrix3_arg mat1)
{
	return Matrix3(
		mulPerElem(mat0.getCol0(), mat1.getCol0()),
		mulPerElem(mat0.getCol1(), mat1.getCol1()),
		mulPerElem(mat0.getCol2(), mat1.getCol2())
		);
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Matrix3 absPerElem(Matrix3_arg mat)
{
	return Matrix3(
		absPerElem(mat.getCol0()),
		absPerElem(mat.getCol1()),
		absPerElem(mat.getCol2())
		);
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Matrix3 transpose(Matrix3_arg mat)
{
	return Matrix3(
		Vector3( mat.getCol0().getX().getAsFloat(), mat.getCol1().getX().getAsFloat(), mat.getCol2().getX().getAsFloat() ),
		Vector3( mat.getCol0().getY().getAsFloat(), mat.getCol1().getY().getAsFloat(), mat.getCol2().getY().getAsFloat() ),
		Vector3( mat.getCol0().getZ().getAsFloat(), mat.getCol1().getZ().getAsFloat(), mat.getCol2().getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Matrix3 inverse(Matrix3_arg mat)
{
	Vector3 tmp0, tmp1, tmp2;
	float detinv;
	tmp0 = cross( mat.getCol1(), mat.getCol2() );
	tmp1 = cross( mat.getCol2(), mat.getCol0() );
	tmp2 = cross( mat.getCol0(), mat.getCol1() );
	detinv = ( 1.0f / dot( mat.getCol2(), tmp2 ).getAsFloat() );
	return Matrix3(
		Vector3( ( tmp0.getX().getAsFloat() * detinv ), ( tmp1.getX().getAsFloat() * detinv ), ( tmp2.getX().getAsFloat() * detinv ) ),
		Vector3( ( tmp0.getY().getAsFloat() * detinv ), ( tmp1.getY().getAsFloat() * detinv ), ( tmp2.getY().getAsFloat() * detinv ) ),
		Vector3( ( tmp0.getZ().getAsFloat() * detinv ), ( tmp1.getZ().getAsFloat() * detinv ), ( tmp2.getZ().getAsFloat() * detinv ) )
		);
}

SCE_VECTORMATH_INLINE const floatInVec determinant(Matrix3_arg mat)
{
	return dot( mat.getCol2(), cross( mat.getCol0(), mat.getCol1() ) );
}

SCE_VECTORMATH_INLINE const Matrix3 select(Matrix3_arg mat0, Matrix3_arg mat1, bool select1)
{
	return ( select1 ? mat1 : mat0 );
}

SCE_VECTORMATH_INLINE const Matrix3 select(Matrix3_arg mat0, Matrix3_arg mat1, boolInVec_arg select1)
{
	return ( select1.getAsBool() ? mat1 : mat0 );
}

#ifdef SCE_VECTORMATH_DEBUG

SCE_VECTORMATH_INLINE void print(Matrix3_arg mat)
{
	print(mat.getRow(0));
	print(mat.getRow(1));
	print(mat.getRow(2));
}

SCE_VECTORMATH_INLINE void print(Matrix3_arg mat, const char* name)
{
	sce_vectormath_printf("%s:\n", name);
	print(mat);
}

#endif	/* #ifdef SCE_VECTORMATH_DEBUG */

SCE_VECTORMATH_ALWAYS_INLINE Matrix4::Matrix4()
{
}

SCE_VECTORMATH_INLINE Matrix4::Matrix4(Vector4_arg col0, Vector4_arg col1, Vector4_arg col2, Vector4_arg col3)
{
	mCol0 = col0;
	mCol1 = col1;
	mCol2 = col2;
	mCol3 = col3;
}

SCE_VECTORMATH_INLINE Matrix4::Matrix4(Transform3_arg mat)
{
	mCol0 = Vector4(mat.getCol0());
	mCol1 = Vector4(mat.getCol1());
	mCol2 = Vector4(mat.getCol2());
	mCol3 = Vector4(Point3(mat.getCol3()));
}

SCE_VECTORMATH_INLINE Matrix4::Matrix4(Matrix3_arg mat, Vector3_arg translateVec)
{
	mCol0 = Vector4(mat.getCol0());
	mCol1 = Vector4(mat.getCol1());
	mCol2 = Vector4(mat.getCol2());
	mCol3 = Vector4(Point3(translateVec));
}

SCE_VECTORMATH_INLINE Matrix4::Matrix4(Quat_arg unitQuat, Vector3_arg translateVec)
{
	Matrix3 mat;
	mat = Matrix3(unitQuat);
	mCol0 = Vector4(mat.getCol0());
	mCol1 = Vector4(mat.getCol1());
	mCol2 = Vector4(mat.getCol2());
	mCol3 = Vector4(Point3(translateVec));
}

SCE_VECTORMATH_INLINE Matrix4::Matrix4(float scalar)
{
	mCol0 = Vector4(scalar);
	mCol1 = Vector4(scalar);
	mCol2 = Vector4(scalar);
	mCol3 = Vector4(scalar);
}

SCE_VECTORMATH_INLINE Matrix4::Matrix4(floatInVec_arg scalar)
{
	mCol0 = Vector4(scalar.getAsFloat());
	mCol1 = Vector4(scalar.getAsFloat());
	mCol2 = Vector4(scalar.getAsFloat());
	mCol3 = Vector4(scalar.getAsFloat());
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::operator =(Matrix4_arg mat)
{
	mCol0 = mat.mCol0;
	mCol1 = mat.mCol1;
	mCol2 = mat.mCol2;
	mCol3 = mat.mCol3;
	return *this;
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::setUpper3x3(Matrix3_arg mat3)
{
	mCol0.setXYZ(mat3.getCol0());
	mCol1.setXYZ(mat3.getCol1());
	mCol2.setXYZ(mat3.getCol2());
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const Matrix3 Matrix4::getUpper3x3() const
{
	return Matrix3(
		mCol0.getXYZ(),
		mCol1.getXYZ(),
		mCol2.getXYZ()
		);
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::setTranslation(Vector3_arg translateVec)
{
	mCol3.setXYZ(translateVec);
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector3 Matrix4::getTranslation() const
{
	return mCol3.getXYZ();
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::setCol0(Vector4_arg col0)
{
	mCol0 = col0;
	return *this;
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::setCol1(Vector4_arg col1)
{
	mCol1 = col1;
	return *this;
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::setCol2(Vector4_arg col2)
{
	mCol2 = col2;
	return *this;
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::setCol3(Vector4_arg col3)
{
	mCol3 = col3;
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector4 Matrix4::getCol0() const
{
	return mCol0;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector4 Matrix4::getCol1() const
{
	return mCol1;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector4 Matrix4::getCol2() const
{
	return mCol2;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector4 Matrix4::getCol3() const
{
	return mCol3;
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::setCol(int col, Vector4_arg vec)
{
	*(&mCol0 + col) = vec;
	return *this;
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::setRow(int row, Vector4_arg vec)
{
	mCol0.setElem(row, vec.getX().getAsFloat());
	mCol1.setElem(row, vec.getY().getAsFloat());
	mCol2.setElem(row, vec.getZ().getAsFloat());
	mCol3.setElem(row, vec.getW().getAsFloat());
	return *this;
}

SCE_VECTORMATH_INLINE const Vector4 Matrix4::getCol(int col) const
{
	return *(&mCol0 + col);
}

SCE_VECTORMATH_INLINE const Vector4 Matrix4::getRow(int row) const
{
	return Vector4(
		mCol0.getElem(row).getAsFloat(),
		mCol1.getElem(row).getAsFloat(),
		mCol2.getElem(row).getAsFloat(),
		mCol3.getElem(row).getAsFloat()
		);
}

SCE_VECTORMATH_INLINE Vector4& Matrix4::operator [](int col)
{
	return *(&mCol0 + col);
}

SCE_VECTORMATH_INLINE const Vector4 Matrix4::operator [](int col) const
{
	return *(&mCol0 + col);
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::setElem(int col, int row, float val)
{
	(*this)[col].setElem(row, val);
	return *this;
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::setElem(int col, int row, floatInVec_arg val)
{
	(*this)[col].setElem(row, val.getAsFloat());
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Matrix4::getElem(int col, int row) const
{
	return getCol(col).getElem(row);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::operator +(Matrix4_arg mat) const
{
	return Matrix4(
		mCol0 + mat.mCol0,
		mCol1 + mat.mCol1,
		mCol2 + mat.mCol2,
		mCol3 + mat.mCol3
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::operator -(Matrix4_arg mat) const
{
	return Matrix4(
		mCol0 - mat.mCol0,
		mCol1 - mat.mCol1,
		mCol2 - mat.mCol2,
		mCol3 - mat.mCol3
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::operator -() const
{
	return Matrix4(
		-mCol0,
		-mCol1,
		-mCol2,
		-mCol3
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::operator *(float scalar) const
{
	return Matrix4(
		mCol0 * scalar,
		mCol1 * scalar,
		mCol2 * scalar,
		mCol3 * scalar
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::operator *(floatInVec_arg scalar) const
{
	return *this * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Vector4 Matrix4::operator *(Vector4_arg vec) const
{
	return Vector4(
		( ( ( ( mCol0.getX().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getX().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getX().getAsFloat() * vec.getZ().getAsFloat() ) ) + ( mCol3.getX().getAsFloat() * vec.getW().getAsFloat() ) ),
		( ( ( ( mCol0.getY().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getY().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getY().getAsFloat() * vec.getZ().getAsFloat() ) ) + ( mCol3.getY().getAsFloat() * vec.getW().getAsFloat() ) ),
		( ( ( ( mCol0.getZ().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getZ().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getZ().getAsFloat() * vec.getZ().getAsFloat() ) ) + ( mCol3.getZ().getAsFloat() * vec.getW().getAsFloat() ) ),
		( ( ( ( mCol0.getW().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getW().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getW().getAsFloat() * vec.getZ().getAsFloat() ) ) + ( mCol3.getW().getAsFloat() * vec.getW().getAsFloat() ) )
		);
}

SCE_VECTORMATH_INLINE const Vector4 Matrix4::operator *(Vector3_arg vec) const
{
	return Vector4(
		( ( ( mCol0.getX().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getX().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getX().getAsFloat() * vec.getZ().getAsFloat() ) ),
		( ( ( mCol0.getY().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getY().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getY().getAsFloat() * vec.getZ().getAsFloat() ) ),
		( ( ( mCol0.getZ().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getZ().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getZ().getAsFloat() * vec.getZ().getAsFloat() ) ),
		( ( ( mCol0.getW().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getW().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getW().getAsFloat() * vec.getZ().getAsFloat() ) )
		);
}

SCE_VECTORMATH_INLINE const Vector4 Matrix4::operator *(Point3_arg pnt) const
{
	return Vector4(
		( ( ( ( mCol0.getX().getAsFloat() * pnt.getX().getAsFloat() ) + ( mCol1.getX().getAsFloat() * pnt.getY().getAsFloat() ) ) + ( mCol2.getX().getAsFloat() * pnt.getZ().getAsFloat() ) ) + mCol3.getX().getAsFloat() ),
		( ( ( ( mCol0.getY().getAsFloat() * pnt.getX().getAsFloat() ) + ( mCol1.getY().getAsFloat() * pnt.getY().getAsFloat() ) ) + ( mCol2.getY().getAsFloat() * pnt.getZ().getAsFloat() ) ) + mCol3.getY().getAsFloat() ),
		( ( ( ( mCol0.getZ().getAsFloat() * pnt.getX().getAsFloat() ) + ( mCol1.getZ().getAsFloat() * pnt.getY().getAsFloat() ) ) + ( mCol2.getZ().getAsFloat() * pnt.getZ().getAsFloat() ) ) + mCol3.getZ().getAsFloat() ),
		( ( ( ( mCol0.getW().getAsFloat() * pnt.getX().getAsFloat() ) + ( mCol1.getW().getAsFloat() * pnt.getY().getAsFloat() ) ) + ( mCol2.getW().getAsFloat() * pnt.getZ().getAsFloat() ) ) + mCol3.getW().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::operator *(Matrix4_arg mat) const
{
	return Matrix4(
		*this * mat.mCol0,
		*this * mat.mCol1,
		*this * mat.mCol2,
		*this * mat.mCol3
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::operator *(Transform3_arg tfrm) const
{
	return Matrix4(
		*this * tfrm.getCol0(),
		*this * tfrm.getCol1(),
		*this * tfrm.getCol2(),
		*this * Point3(tfrm.getCol3())
		);
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::operator +=(Matrix4_arg mat)
{
	*this = *this + mat;
	return *this;
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::operator -=(Matrix4_arg mat)
{
	*this = *this - mat;
	return *this;
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::operator *=(float scalar)
{
	return *this = *this * scalar;
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::operator *=(floatInVec_arg scalar)
{
	return *this = *this * scalar;
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::operator *=(Matrix4_arg mat)
{
	*this = *this * mat;
	return *this;
}

SCE_VECTORMATH_INLINE Matrix4& Matrix4::operator *=(Transform3_arg tfrm)
{
	*this = *this * tfrm;
	return *this;
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::identity()
{
	return Matrix4(
		Vector4::xAxis(),
		Vector4::yAxis(),
		Vector4::zAxis(),
		Vector4::wAxis()
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::zero()
{
	return Matrix4(
		Vector4::zero(),
		Vector4::zero(),
		Vector4::zero(),
		Vector4::zero()
		);
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::rotationX(float radians)
{
	float s, c;
	s = ::sinf( radians );
	c = ::cosf( radians );
	return Matrix4(
		Vector4::xAxis( ),
		Vector4( 0.0f, c, s, 0.0f ),
		Vector4( 0.0f, -s, c, 0.0f ),
		Vector4::wAxis( )
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::rotationY(float radians)
{
	float s, c;
	s = ::sinf( radians );
	c = ::cosf( radians );
	return Matrix4(
		Vector4( c, 0.0f, -s, 0.0f ),
		Vector4::yAxis( ),
		Vector4( s, 0.0f, c, 0.0f ),
		Vector4::wAxis( )
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::rotationZ(float radians)
{
	float s, c;
	s = ::sinf( radians );
	c = ::cosf( radians );
	return Matrix4(
		Vector4( c, s, 0.0f, 0.0f ),
		Vector4( -s, c, 0.0f, 0.0f ),
		Vector4::zAxis( ),
		Vector4::wAxis( )
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::rotationX(floatInVec_arg radians)
{
	return rotationX( radians.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::rotationY(floatInVec_arg radians)
{
	return rotationY( radians.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::rotationZ(floatInVec_arg radians)
{
	return rotationZ( radians.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::rotationZYX(Vector3_arg radiansXYZ)
{
	float sX, cX, sY, cY, sZ, cZ, tmp0, tmp1;
	sX = ::sinf( radiansXYZ.getX().getAsFloat() );
	cX = ::cosf( radiansXYZ.getX().getAsFloat() );
	sY = ::sinf( radiansXYZ.getY().getAsFloat() );
	cY = ::cosf( radiansXYZ.getY().getAsFloat() );
	sZ = ::sinf( radiansXYZ.getZ().getAsFloat() );
	cZ = ::cosf( radiansXYZ.getZ().getAsFloat() );
	tmp0 = ( cZ * sY );
	tmp1 = ( sZ * sY );
	return Matrix4(
		Vector4( ( cZ * cY ), ( sZ * cY ), -sY, 0.0f ),
		Vector4( ( ( tmp0 * sX ) - ( sZ * cX ) ), ( ( tmp1 * sX ) + ( cZ * cX ) ), ( cY * sX ), 0.0f ),
		Vector4( ( ( tmp0 * cX ) + ( sZ * sX ) ), ( ( tmp1 * cX ) - ( cZ * sX ) ), ( cY * cX ), 0.0f ),
		Vector4::wAxis( )
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::rotation(float radians, Vector3_arg unitVec)
{
	float x, y, z, s, c, oneMinusC, xy, yz, zx;
	s = ::sinf( radians );
	c = ::cosf( radians );
	x = unitVec.getX().getAsFloat();
	y = unitVec.getY().getAsFloat();
	z = unitVec.getZ().getAsFloat();
	xy = ( x * y );
	yz = ( y * z );
	zx = ( z * x );
	oneMinusC = ( 1.0f - c );
	return Matrix4(
		Vector4( ( ( ( x * x ) * oneMinusC ) + c ), ( ( xy * oneMinusC ) + ( z * s ) ), ( ( zx * oneMinusC ) - ( y * s ) ), 0.0f ),
		Vector4( ( ( xy * oneMinusC ) - ( z * s ) ), ( ( ( y * y ) * oneMinusC ) + c ), ( ( yz * oneMinusC ) + ( x * s ) ), 0.0f ),
		Vector4( ( ( zx * oneMinusC ) + ( y * s ) ), ( ( yz * oneMinusC ) - ( x * s ) ), ( ( ( z * z ) * oneMinusC ) + c ), 0.0f ),
		Vector4::wAxis( )
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::rotation(floatInVec_arg radians, Vector3_arg unitVec)
{
	return rotation(radians.getAsFloat(), unitVec);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::rotation(Quat_arg unitQuat)
{
	return Matrix4(Transform3::rotation(unitQuat));
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::scale(Vector3_arg scaleVec)
{
	return Matrix4(
		Vector4( scaleVec.getX().getAsFloat(), 0.0f, 0.0f, 0.0f ),
		Vector4( 0.0f, scaleVec.getY().getAsFloat(), 0.0f, 0.0f ),
		Vector4( 0.0f, 0.0f, scaleVec.getZ().getAsFloat(), 0.0f ),
		Vector4::wAxis()
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::translation(Vector3_arg translateVec)
{
	return Matrix4(
		Vector4::xAxis(),
		Vector4::yAxis(),
		Vector4::zAxis(),
		Vector4(Point3(translateVec))
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::lookAt(Point3_arg eyePos, Point3_arg lookAtPos, Vector3_arg upVec)
{
	Matrix4 m4EyeFrame;
	Vector3 v3X, v3Y, v3Z;
	v3Y = normalize(upVec);
	v3Z = normalize((eyePos - lookAtPos));
	v3X = normalize(cross(v3Y, v3Z));
	v3Y = cross(v3Z, v3X);
	m4EyeFrame = Matrix4(Vector4(v3X), Vector4(v3Y), Vector4(v3Z), Vector4(eyePos));
	return orthoInverse(m4EyeFrame);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::perspective(float fovyRadians, float aspect, float zNear, float zFar)
{
	SCE_VECTORMATH_ASSERT_MSG( zNear < zFar, "Far clip plane should be further away than Near clip plane" );

	float f, rangeInv;
	f = ::tanf( ( static_cast<float>( _SCE_VECTORMATH_PI_OVER_2 ) - ( 0.5f * fovyRadians ) ) );
	rangeInv = ( 1.0f / ( zNear - zFar ) );
	return Matrix4(
		Vector4( ( f / aspect ), 0.0f, 0.0f, 0.0f ),
		Vector4( 0.0f, f, 0.0f, 0.0f ),
		Vector4( 0.0f, 0.0f, ( ( zNear + zFar ) * rangeInv ), -1.0f ),
		Vector4( 0.0f, 0.0f, ( ( ( zNear * zFar ) * rangeInv ) * 2.0f ), 0.0f )
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::perspective(floatInVec_arg fovyRadians, floatInVec_arg aspect, floatInVec_arg zNear, floatInVec_arg zFar)
{
	return perspective( fovyRadians.getAsFloat(), aspect.getAsFloat(), zNear.getAsFloat(), zFar.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::frustum(float left, float right, float bottom, float top, float zNear, float zFar)
{
	SCE_VECTORMATH_ASSERT_MSG( zNear < zFar, "Far clip plane should be further away than Near clip plane" );

	float sum_rl, sum_tb, sum_nf, inv_rl, inv_tb, inv_nf, n2;
	sum_rl = ( right + left );
	sum_tb = ( top + bottom );
	sum_nf = ( zNear + zFar );
	inv_rl = ( 1.0f / ( right - left ) );
	inv_tb = ( 1.0f / ( top - bottom ) );
	inv_nf = ( 1.0f / ( zNear - zFar ) );
	n2 = ( zNear + zNear );
	return Matrix4(
		Vector4( ( n2 * inv_rl ), 0.0f, 0.0f, 0.0f ),
		Vector4( 0.0f, ( n2 * inv_tb ), 0.0f, 0.0f ),
		Vector4( ( sum_rl * inv_rl ), ( sum_tb * inv_tb ), ( sum_nf * inv_nf ), -1.0f ),
		Vector4( 0.0f, 0.0f, ( ( n2 * inv_nf ) * zFar ), 0.0f )
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::frustum(floatInVec_arg left, floatInVec_arg right, floatInVec_arg bottom, floatInVec_arg top, floatInVec_arg zNear, floatInVec_arg zFar)
{
	return frustum( left.getAsFloat(), right.getAsFloat(), bottom.getAsFloat(), top.getAsFloat(), zNear.getAsFloat(), zFar.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::orthographic(float left, float right, float bottom, float top, float zNear, float zFar)
{
	SCE_VECTORMATH_ASSERT_MSG( zNear < zFar, "Far clip plane should be further away than Near clip plane" );

	float sum_rl, sum_tb, sum_nf, inv_rl, inv_tb, inv_nf;
	sum_rl = ( right + left );
	sum_tb = ( top + bottom );
	sum_nf = ( zNear + zFar );
	inv_rl = ( 1.0f / ( right - left ) );
	inv_tb = ( 1.0f / ( top - bottom ) );
	inv_nf = ( 1.0f / ( zNear - zFar ) );
	return Matrix4(
		Vector4( ( inv_rl + inv_rl ), 0.0f, 0.0f, 0.0f ),
		Vector4( 0.0f, ( inv_tb + inv_tb ), 0.0f, 0.0f ),
		Vector4( 0.0f, 0.0f, ( inv_nf + inv_nf ), 0.0f ),
		Vector4( ( -sum_rl * inv_rl ), ( -sum_tb * inv_tb ), ( sum_nf * inv_nf ), 1.0f )
		);
}

SCE_VECTORMATH_INLINE const Matrix4 Matrix4::orthographic(floatInVec_arg left, floatInVec_arg right, floatInVec_arg bottom, floatInVec_arg top, floatInVec_arg zNear, floatInVec_arg zFar)
{
	return orthographic( left.getAsFloat(), right.getAsFloat(), bottom.getAsFloat(), top.getAsFloat(), zNear.getAsFloat(), zFar.getAsFloat() );
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Matrix4 operator *(float scalar, Matrix4_arg mat)
{
	return mat * scalar;
}

SCE_VECTORMATH_INLINE const Matrix4 operator *(floatInVec_arg scalar, Matrix4_arg mat)
{
	return mat * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Matrix4 appendScale(Matrix4_arg mat, Vector3_arg scaleVec)
{
	return Matrix4(
		(mat.getCol0() * scaleVec.getX().getAsFloat()),
		(mat.getCol1() * scaleVec.getY().getAsFloat()),
		(mat.getCol2() * scaleVec.getZ().getAsFloat()),
		mat.getCol3()
		);
}

SCE_VECTORMATH_INLINE const Matrix4 prependScale(Vector3_arg scaleVec, Matrix4_arg mat)
{
	Vector4 scale4 = Vector4(Point3(scaleVec));
	return Matrix4(
		mulPerElem(mat.getCol0(), scale4),
		mulPerElem(mat.getCol1(), scale4),
		mulPerElem(mat.getCol2(), scale4),
		mulPerElem(mat.getCol3(), scale4)
		);
}

SCE_VECTORMATH_INLINE const Matrix4 mulPerElem(Matrix4_arg mat0, Matrix4_arg mat1)
{
	return Matrix4(
		mulPerElem(mat0.getCol0(), mat1.getCol0()),
		mulPerElem(mat0.getCol1(), mat1.getCol1()),
		mulPerElem(mat0.getCol2(), mat1.getCol2()),
		mulPerElem(mat0.getCol3(), mat1.getCol3())
		);
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Matrix4 absPerElem(Matrix4_arg mat)
{
	return Matrix4(
		absPerElem(mat.getCol0()),
		absPerElem(mat.getCol1()),
		absPerElem(mat.getCol2()),
		absPerElem(mat.getCol3())
		);
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Matrix4 transpose(Matrix4_arg mat)
{
	return Matrix4(
		Vector4( mat.getCol0().getX().getAsFloat(), mat.getCol1().getX().getAsFloat(), mat.getCol2().getX().getAsFloat(), mat.getCol3().getX().getAsFloat() ),
		Vector4( mat.getCol0().getY().getAsFloat(), mat.getCol1().getY().getAsFloat(), mat.getCol2().getY().getAsFloat(), mat.getCol3().getY().getAsFloat() ),
		Vector4( mat.getCol0().getZ().getAsFloat(), mat.getCol1().getZ().getAsFloat(), mat.getCol2().getZ().getAsFloat(), mat.getCol3().getZ().getAsFloat() ),
		Vector4( mat.getCol0().getW().getAsFloat(), mat.getCol1().getW().getAsFloat(), mat.getCol2().getW().getAsFloat(), mat.getCol3().getW().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Matrix4 inverse(Matrix4_arg mat)
{
	Vector4 res0, res1, res2, res3;
	float mA, mB, mC, mD, mE, mF, mG, mH, mI, mJ, mK, mL, mM, mN, mO, mP, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, detInv;
	mA = mat.getCol0().getX().getAsFloat();
	mB = mat.getCol0().getY().getAsFloat();
	mC = mat.getCol0().getZ().getAsFloat();
	mD = mat.getCol0().getW().getAsFloat();
	mE = mat.getCol1().getX().getAsFloat();
	mF = mat.getCol1().getY().getAsFloat();
	mG = mat.getCol1().getZ().getAsFloat();
	mH = mat.getCol1().getW().getAsFloat();
	mI = mat.getCol2().getX().getAsFloat();
	mJ = mat.getCol2().getY().getAsFloat();
	mK = mat.getCol2().getZ().getAsFloat();
	mL = mat.getCol2().getW().getAsFloat();
	mM = mat.getCol3().getX().getAsFloat();
	mN = mat.getCol3().getY().getAsFloat();
	mO = mat.getCol3().getZ().getAsFloat();
	mP = mat.getCol3().getW().getAsFloat();
	tmp0 = ( ( mK * mD ) - ( mC * mL ) );
	tmp1 = ( ( mO * mH ) - ( mG * mP ) );
	tmp2 = ( ( mB * mK ) - ( mJ * mC ) );
	tmp3 = ( ( mF * mO ) - ( mN * mG ) );
	tmp4 = ( ( mJ * mD ) - ( mB * mL ) );
	tmp5 = ( ( mN * mH ) - ( mF * mP ) );
	res0.setX( ( ( ( mJ * tmp1 ) - ( mL * tmp3 ) ) - ( mK * tmp5 ) ) );
	res0.setY( ( ( ( mN * tmp0 ) - ( mP * tmp2 ) ) - ( mO * tmp4 ) ) );
	res0.setZ( ( ( ( mD * tmp3 ) + ( mC * tmp5 ) ) - ( mB * tmp1 ) ) );
	res0.setW( ( ( ( mH * tmp2 ) + ( mG * tmp4 ) ) - ( mF * tmp0 ) ) );
	detInv = ( 1.0f / ( ( ( ( mA * res0.getX().getAsFloat() ) + ( mE * res0.getY().getAsFloat() ) ) + ( mI * res0.getZ().getAsFloat() ) ) + ( mM * res0.getW().getAsFloat() ) ) );
	res1.setX( ( mI * tmp1 ) );
	res1.setY( ( mM * tmp0 ) );
	res1.setZ( ( mA * tmp1 ) );
	res1.setW( ( mE * tmp0 ) );
	res3.setX( ( mI * tmp3 ) );
	res3.setY( ( mM * tmp2 ) );
	res3.setZ( ( mA * tmp3 ) );
	res3.setW( ( mE * tmp2 ) );
	res2.setX( ( mI * tmp5 ) );
	res2.setY( ( mM * tmp4 ) );
	res2.setZ( ( mA * tmp5 ) );
	res2.setW( ( mE * tmp4 ) );
	tmp0 = ( ( mI * mB ) - ( mA * mJ ) );
	tmp1 = ( ( mM * mF ) - ( mE * mN ) );
	tmp2 = ( ( mI * mD ) - ( mA * mL ) );
	tmp3 = ( ( mM * mH ) - ( mE * mP ) );
	tmp4 = ( ( mI * mC ) - ( mA * mK ) );
	tmp5 = ( ( mM * mG ) - ( mE * mO ) );
	res2.setX( ( ( ( mL * tmp1 ) - ( mJ * tmp3 ) ) + res2.getX().getAsFloat() ) );
	res2.setY( ( ( ( mP * tmp0 ) - ( mN * tmp2 ) ) + res2.getY().getAsFloat() ) );
	res2.setZ( ( ( ( mB * tmp3 ) - ( mD * tmp1 ) ) - res2.getZ().getAsFloat() ) );
	res2.setW( ( ( ( mF * tmp2 ) - ( mH * tmp0 ) ) - res2.getW().getAsFloat() ) );
	res3.setX( ( ( ( mJ * tmp5 ) - ( mK * tmp1 ) ) + res3.getX().getAsFloat() ) );
	res3.setY( ( ( ( mN * tmp4 ) - ( mO * tmp0 ) ) + res3.getY().getAsFloat() ) );
	res3.setZ( ( ( ( mC * tmp1 ) - ( mB * tmp5 ) ) - res3.getZ().getAsFloat() ) );
	res3.setW( ( ( ( mG * tmp0 ) - ( mF * tmp4 ) ) - res3.getW().getAsFloat() ) );
	res1.setX( ( ( ( mK * tmp3 ) - ( mL * tmp5 ) ) - res1.getX().getAsFloat() ) );
	res1.setY( ( ( ( mO * tmp2 ) - ( mP * tmp4 ) ) - res1.getY().getAsFloat() ) );
	res1.setZ( ( ( ( mD * tmp5 ) - ( mC * tmp3 ) ) + res1.getZ().getAsFloat() ) );
	res1.setW( ( ( ( mH * tmp4 ) - ( mG * tmp2 ) ) + res1.getW().getAsFloat() ) );
	return Matrix4(
		( res0 * detInv ),
		( res1 * detInv ),
		( res2 * detInv ),
		( res3 * detInv )
		);
}

SCE_VECTORMATH_INLINE const Matrix4 affineInverse(Matrix4_arg mat)
{
	Transform3 affineMat;
	affineMat.setCol0( mat.getCol0().getXYZ() );
	affineMat.setCol1( mat.getCol1().getXYZ() );
	affineMat.setCol2( mat.getCol2().getXYZ() );
	affineMat.setCol3( mat.getCol3().getXYZ() );
	return Matrix4( inverse( affineMat ) );
}

SCE_VECTORMATH_INLINE const Matrix4 orthoInverse(Matrix4_arg mat)
{
	Transform3 affineMat;
	affineMat.setCol0( mat.getCol0().getXYZ( ) );
	affineMat.setCol1( mat.getCol1().getXYZ( ) );
	affineMat.setCol2( mat.getCol2().getXYZ( ) );
	affineMat.setCol3( mat.getCol3().getXYZ( ) );
	return Matrix4( orthoInverse( affineMat ) );
}

SCE_VECTORMATH_INLINE const floatInVec determinant(Matrix4_arg mat)
{
	float dx, dy, dz, dw, mA, mB, mC, mD, mE, mF, mG, mH, mI, mJ, mK, mL, mM, mN, mO, mP, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5;
	mA = mat.getCol0().getX().getAsFloat();
	mB = mat.getCol0().getY().getAsFloat();
	mC = mat.getCol0().getZ().getAsFloat();
	mD = mat.getCol0().getW().getAsFloat();
	mE = mat.getCol1().getX().getAsFloat();
	mF = mat.getCol1().getY().getAsFloat();
	mG = mat.getCol1().getZ().getAsFloat();
	mH = mat.getCol1().getW().getAsFloat();
	mI = mat.getCol2().getX().getAsFloat();
	mJ = mat.getCol2().getY().getAsFloat();
	mK = mat.getCol2().getZ().getAsFloat();
	mL = mat.getCol2().getW().getAsFloat();
	mM = mat.getCol3().getX().getAsFloat();
	mN = mat.getCol3().getY().getAsFloat();
	mO = mat.getCol3().getZ().getAsFloat();
	mP = mat.getCol3().getW().getAsFloat();
	tmp0 = ( ( mK * mD ) - ( mC * mL ) );
	tmp1 = ( ( mO * mH ) - ( mG * mP ) );
	tmp2 = ( ( mB * mK ) - ( mJ * mC ) );
	tmp3 = ( ( mF * mO ) - ( mN * mG ) );
	tmp4 = ( ( mJ * mD ) - ( mB * mL ) );
	tmp5 = ( ( mN * mH ) - ( mF * mP ) );
	dx = ( ( ( mJ * tmp1 ) - ( mL * tmp3 ) ) - ( mK * tmp5 ) );
	dy = ( ( ( mN * tmp0 ) - ( mP * tmp2 ) ) - ( mO * tmp4 ) );
	dz = ( ( ( mD * tmp3 ) + ( mC * tmp5 ) ) - ( mB * tmp1 ) );
	dw = ( ( ( mH * tmp2 ) + ( mG * tmp4 ) ) - ( mF * tmp0 ) );
	return floatInVec( ( ( ( mA * dx ) + ( mE * dy ) ) + ( mI * dz ) ) + ( mM * dw ) );
}

SCE_VECTORMATH_INLINE const Matrix4 select(Matrix4_arg mat0, Matrix4_arg mat1, bool select1)
{
	return ( select1 ? mat1 : mat0 );
}

SCE_VECTORMATH_INLINE const Matrix4 select(Matrix4_arg mat0, Matrix4_arg mat1, boolInVec_arg select1)
{
	return ( select1.getAsBool() ? mat1 : mat0 );
}

#ifdef SCE_VECTORMATH_DEBUG

SCE_VECTORMATH_INLINE void print(Matrix4_arg mat)
{
	print(mat.getRow(0));
	print(mat.getRow(1));
	print(mat.getRow(2));
	print(mat.getRow(3));
}

SCE_VECTORMATH_INLINE void print(Matrix4_arg mat, const char* name)
{
	sce_vectormath_printf("%s:\n", name);
	print(mat);
}

#endif

SCE_VECTORMATH_ALWAYS_INLINE Transform3::Transform3()
{
}

SCE_VECTORMATH_INLINE Transform3::Transform3(Vector3_arg col0, Vector3_arg col1, Vector3_arg col2, Vector3_arg col3)
{
	mCol0 = col0;
	mCol1 = col1;
	mCol2 = col2;
	mCol3 = col3;
}

SCE_VECTORMATH_INLINE Transform3::Transform3(Matrix3_arg tfrm, Vector3_arg translateVec)
{
	setUpper3x3(tfrm);
	setTranslation(translateVec);
}

SCE_VECTORMATH_INLINE Transform3::Transform3(Quat_arg unitQuat, Vector3_arg translateVec)
{
	setUpper3x3(Matrix3(unitQuat));
	setTranslation(translateVec);
}

SCE_VECTORMATH_INLINE Transform3::Transform3(float scalar)
{
	mCol0 = Vector3(scalar);
	mCol1 = Vector3(scalar);
	mCol2 = Vector3(scalar);
	mCol3 = Vector3(scalar);
}

SCE_VECTORMATH_INLINE Transform3::Transform3(floatInVec_arg scalar)
{
	mCol0 = Vector3(scalar.getAsFloat());
	mCol1 = Vector3(scalar.getAsFloat());
	mCol2 = Vector3(scalar.getAsFloat());
	mCol3 = Vector3(scalar.getAsFloat());
}

SCE_VECTORMATH_INLINE Transform3& Transform3::operator =(Transform3_arg tfrm)
{
	mCol0 = tfrm.mCol0;
	mCol1 = tfrm.mCol1;
	mCol2 = tfrm.mCol2;
	mCol3 = tfrm.mCol3;
	return *this;
}

SCE_VECTORMATH_INLINE Transform3& Transform3::setUpper3x3(Matrix3_arg mat3)
{
	mCol0 = mat3.getCol0();
	mCol1 = mat3.getCol1();
	mCol2 = mat3.getCol2();
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const Matrix3 Transform3::getUpper3x3() const
{
	return Matrix3(mCol0, mCol1, mCol2);
}

SCE_VECTORMATH_INLINE Transform3& Transform3::setTranslation(Vector3_arg translateVec)
{
	mCol3 = translateVec;
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector3 Transform3::getTranslation() const
{
	return mCol3;
}

SCE_VECTORMATH_INLINE Transform3& Transform3::setCol0(Vector3_arg col0)
{
	mCol0 = col0;
	return *this;
}

SCE_VECTORMATH_INLINE Transform3& Transform3::setCol1(Vector3_arg col1)
{
	mCol1 = col1;
	return *this;
}

SCE_VECTORMATH_INLINE Transform3& Transform3::setCol2(Vector3_arg col2)
{
	mCol2 = col2;
	return *this;
}

SCE_VECTORMATH_INLINE Transform3& Transform3::setCol3(Vector3_arg col3)
{
	mCol3 = col3;
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector3 Transform3::getCol0() const
{
	return mCol0;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector3 Transform3::getCol1() const
{
	return mCol1;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector3 Transform3::getCol2() const
{
	return mCol2;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector3 Transform3::getCol3() const
{
	return mCol3;
}

SCE_VECTORMATH_INLINE Transform3& Transform3::setCol(int col, Vector3_arg vec)
{
	*(&mCol0 + col) = vec;
	return *this;
}

SCE_VECTORMATH_INLINE Transform3& Transform3::setRow(int row, Vector4_arg vec)
{
	mCol0.setElem(row, vec.getX().getAsFloat());
	mCol1.setElem(row, vec.getY().getAsFloat());
	mCol2.setElem(row, vec.getZ().getAsFloat());
	mCol3.setElem(row, vec.getW().getAsFloat());
	return *this;
}

SCE_VECTORMATH_INLINE const Vector3 Transform3::getCol(int col) const
{
	return *(&mCol0 + col);
}

SCE_VECTORMATH_INLINE const Vector4 Transform3::getRow(int row) const
{
	return Vector4(
		mCol0.getElem(row),
		mCol1.getElem(row),
		mCol2.getElem(row),
		mCol3.getElem(row)
		);
}

SCE_VECTORMATH_INLINE Vector3& Transform3::operator [](int col)
{
	return *(&mCol0 + col);
}

SCE_VECTORMATH_INLINE const Vector3 Transform3::operator [](int col) const
{
	return *(&mCol0 + col);
}

SCE_VECTORMATH_INLINE Transform3& Transform3::setElem(int col, int row, float val)
{
	(*this)[col].setElem(row, val);
	return *this;
}

SCE_VECTORMATH_INLINE Transform3& Transform3::setElem(int col, int row, floatInVec_arg val)
{
	(*this)[col].setElem(row, val.getAsFloat());
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Transform3::getElem(int col, int row) const
{
	return getCol(col).getElem(row);
}

SCE_VECTORMATH_INLINE const Vector3 Transform3::operator *(Vector3_arg vec) const
{
	return Vector3(
		( ( ( mCol0.getX().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getX().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getX().getAsFloat() * vec.getZ().getAsFloat() ) ),
		( ( ( mCol0.getY().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getY().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getY().getAsFloat() * vec.getZ().getAsFloat() ) ),
		( ( ( mCol0.getZ().getAsFloat() * vec.getX().getAsFloat() ) + ( mCol1.getZ().getAsFloat() * vec.getY().getAsFloat() ) ) + ( mCol2.getZ().getAsFloat() * vec.getZ().getAsFloat() ) )
		);
}

SCE_VECTORMATH_INLINE const Point3 Transform3::operator *(Point3_arg pnt) const
{
	return Point3(
		( ( ( ( mCol0.getX().getAsFloat() * pnt.getX().getAsFloat() ) + ( mCol1.getX().getAsFloat() * pnt.getY().getAsFloat() ) ) + ( mCol2.getX().getAsFloat() * pnt.getZ().getAsFloat() ) ) + mCol3.getX().getAsFloat() ),
		( ( ( ( mCol0.getY().getAsFloat() * pnt.getX().getAsFloat() ) + ( mCol1.getY().getAsFloat() * pnt.getY().getAsFloat() ) ) + ( mCol2.getY().getAsFloat() * pnt.getZ().getAsFloat() ) ) + mCol3.getY().getAsFloat() ),
		( ( ( ( mCol0.getZ().getAsFloat() * pnt.getX().getAsFloat() ) + ( mCol1.getZ().getAsFloat() * pnt.getY().getAsFloat() ) ) + ( mCol2.getZ().getAsFloat() * pnt.getZ().getAsFloat() ) ) + mCol3.getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Transform3 Transform3::operator *(Transform3_arg tfrm) const
{
	return Transform3(
		(*this * tfrm.mCol0),
		(*this * tfrm.mCol1),
		(*this * tfrm.mCol2),
		Vector3(*this * Point3(tfrm.mCol3))
		);
}

SCE_VECTORMATH_INLINE Transform3& Transform3::operator *=(Transform3_arg tfrm)
{
	return *this = *this * tfrm;
}

SCE_VECTORMATH_INLINE const Transform3 Transform3::identity()
{
	return Transform3(
		Vector3::xAxis(),
		Vector3::yAxis(),
		Vector3::zAxis(),
		Vector3::zero()
		);
}

#if	!defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Transform3 Transform3::rotationX(float radians)
{
	return Transform3(Matrix3::rotationX(radians), Vector3::zero());
}

SCE_VECTORMATH_INLINE const Transform3 Transform3::rotationY(float radians)
{
	return Transform3(Matrix3::rotationY(radians), Vector3::zero());
}

SCE_VECTORMATH_INLINE const Transform3 Transform3::rotationZ(float radians)
{
	return Transform3(Matrix3::rotationZ(radians), Vector3::zero());
}

SCE_VECTORMATH_INLINE const Transform3 Transform3::rotationX(floatInVec_arg radians)
{
	return Transform3(Matrix3::rotationX(radians), Vector3::zero());
}

SCE_VECTORMATH_INLINE const Transform3 Transform3::rotationY(floatInVec_arg radians)
{
	return Transform3(Matrix3::rotationY(radians), Vector3::zero());
}

SCE_VECTORMATH_INLINE const Transform3 Transform3::rotationZ(floatInVec_arg radians)
{
	return Transform3(Matrix3::rotationZ(radians), Vector3::zero());
}

SCE_VECTORMATH_INLINE const Transform3 Transform3::rotationZYX(Vector3_arg radiansXYZ)
{
	return Transform3(Matrix3::rotationZYX(radiansXYZ), Vector3::zero());
}

SCE_VECTORMATH_INLINE const Transform3 Transform3::rotation(float radians, Vector3_arg unitVec)
{
	return Transform3( Matrix3::rotation(radians, unitVec), Vector3::zero() );
}

SCE_VECTORMATH_INLINE const Transform3 Transform3::rotation(floatInVec_arg radians, Vector3_arg unitVec)
{
	return Transform3( Matrix3::rotation(radians, unitVec), Vector3::zero() );
}

SCE_VECTORMATH_INLINE const Transform3 Transform3::rotation(Quat_arg unitQuat)
{
	return Transform3(Matrix3(unitQuat), Vector3::zero());
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Transform3 Transform3::scale(Vector3_arg scaleVec)
{
	return Transform3(
		Vector3( scaleVec.getX().getAsFloat(), 0.0f, 0.0f ),
		Vector3( 0.0f, scaleVec.getY().getAsFloat(), 0.0f ),
		Vector3( 0.0f, 0.0f, scaleVec.getZ().getAsFloat() ),
		Vector3( 0.0f )
		);
}

SCE_VECTORMATH_INLINE const Transform3 Transform3::translation(Vector3_arg translateVec)
{
	return Transform3(
		Vector3::xAxis(),
		Vector3::yAxis(),
		Vector3::zAxis(),
		translateVec
		);
}

SCE_VECTORMATH_INLINE const Transform3 appendScale(Transform3_arg tfrm, Vector3_arg scaleVec)
{
	return Transform3(
		tfrm.getCol0() * scaleVec.getX(),
		tfrm.getCol1() * scaleVec.getY(),
		tfrm.getCol2() * scaleVec.getZ(),
		tfrm.getCol3()
		);
}

SCE_VECTORMATH_INLINE const Transform3 prependScale(Vector3_arg scaleVec, Transform3_arg tfrm)
{
	return Transform3(
		mulPerElem(tfrm.getCol0(), scaleVec),
		mulPerElem(tfrm.getCol1(), scaleVec),
		mulPerElem(tfrm.getCol2(), scaleVec),
		mulPerElem(tfrm.getCol3(), scaleVec)
		);
}

SCE_VECTORMATH_INLINE const Transform3 mulPerElem(Transform3_arg tfrm0, Transform3_arg tfrm1)
{
	return Transform3(
		mulPerElem(tfrm0.getCol0(), tfrm1.getCol0()),
		mulPerElem(tfrm0.getCol1(), tfrm1.getCol1()),
		mulPerElem(tfrm0.getCol2(), tfrm1.getCol2()),
		mulPerElem(tfrm0.getCol3(), tfrm1.getCol3())
		);
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Transform3 absPerElem(Transform3_arg tfrm)
{
	return Transform3(
		absPerElem(tfrm.getCol0()),
		absPerElem(tfrm.getCol1()),
		absPerElem(tfrm.getCol2()),
		absPerElem(tfrm.getCol3())
		);
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Transform3 inverse(Transform3_arg tfrm)
{
	Vector3 tmp0, tmp1, tmp2, inv0, inv1, inv2, inv3;
	float detinv;
	tmp0 = cross( tfrm.getCol1(), tfrm.getCol2() );
	tmp1 = cross( tfrm.getCol2(), tfrm.getCol0() );
	tmp2 = cross( tfrm.getCol0(), tfrm.getCol1() );
	detinv = ( 1.0f / dot( tfrm.getCol2(), tmp2 ).getAsFloat() );
	inv0 = Vector3( ( tmp0.getX().getAsFloat() * detinv ), ( tmp1.getX().getAsFloat() * detinv ), ( tmp2.getX().getAsFloat() * detinv ) );
	inv1 = Vector3( ( tmp0.getY().getAsFloat() * detinv ), ( tmp1.getY().getAsFloat() * detinv ), ( tmp2.getY().getAsFloat() * detinv ) );
	inv2 = Vector3( ( tmp0.getZ().getAsFloat() * detinv ), ( tmp1.getZ().getAsFloat() * detinv ), ( tmp2.getZ().getAsFloat() * detinv ) );
	inv3  = ( inv0 * tfrm.getCol3().getX().getAsFloat() );
	inv3 += ( inv1 * tfrm.getCol3().getY().getAsFloat() );
	inv3 += ( inv2 * tfrm.getCol3().getZ().getAsFloat() );
	return Transform3(
		inv0,
		inv1,
		inv2,
		-inv3
		);
}

SCE_VECTORMATH_INLINE const Transform3 orthoInverse(Transform3_arg tfrm)
{
	Vector3 inv0, inv1, inv2, inv3;
	inv0 = Vector3( tfrm.getCol0().getX().getAsFloat(), tfrm.getCol1().getX().getAsFloat(), tfrm.getCol2().getX().getAsFloat() );
	inv1 = Vector3( tfrm.getCol0().getY().getAsFloat(), tfrm.getCol1().getY().getAsFloat(), tfrm.getCol2().getY().getAsFloat() );
	inv2 = Vector3( tfrm.getCol0().getZ().getAsFloat(), tfrm.getCol1().getZ().getAsFloat(), tfrm.getCol2().getZ().getAsFloat() );
	inv3  = ( inv0 * tfrm.getCol3().getX().getAsFloat() );
	inv3 += ( inv1 * tfrm.getCol3().getY().getAsFloat() );
	inv3 += ( inv2 * tfrm.getCol3().getZ().getAsFloat() );
	return Transform3(
		inv0,
		inv1,
		inv2,
		-inv3
		);
}

SCE_VECTORMATH_INLINE const Transform3 select(Transform3_arg tfrm0, Transform3_arg tfrm1, bool select1)
{
	return ( select1 ? tfrm1 : tfrm0 );
}

SCE_VECTORMATH_INLINE const Transform3 select(Transform3_arg tfrm0, Transform3_arg tfrm1, boolInVec_arg select1)
{
	return ( select1.getAsBool() ? tfrm1 : tfrm0 );
}

#ifdef SCE_VECTORMATH_DEBUG

SCE_VECTORMATH_INLINE void print(Transform3_arg tfrm)
{
	print(tfrm.getRow(0));
	print(tfrm.getRow(1));
	print(tfrm.getRow(2));
}

SCE_VECTORMATH_INLINE void print(Transform3_arg tfrm, const char* name)
{
	sce_vectormath_printf("%s:\n", name);
	print(tfrm);
}

#endif

} // namespace Aos
} // namespace Scalar
} // namespace Vectormath
} // namespace sce

#endif /* _PSP2_VECTORMATH_SCALAR_MAT_AOS_CPP_H_ */
