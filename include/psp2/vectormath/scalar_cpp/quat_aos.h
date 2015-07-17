/**
 * \file quat_aos.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_VECTORMATH_SCALAR_QUAT_AOS_CPP_H_
#define _PSP2_VECTORMATH_SCALAR_QUAT_AOS_CPP_H_

//-----------------------------------------------------------------------------
// Definitions

namespace sce {
namespace Vectormath {
namespace Scalar {
namespace Aos {

SCE_VECTORMATH_ALWAYS_INLINE Quat::Quat()
{
}

SCE_VECTORMATH_INLINE Quat::Quat(float _x, float _y, float _z, float _w)
{
	mX = _x;
	mY = _y;
	mZ = _z;
	mW = _w;
}

SCE_VECTORMATH_INLINE Quat::Quat(floatInVec_arg _x, floatInVec_arg _y, floatInVec_arg _z, floatInVec_arg _w)
{
	mX = _x.getAsFloat();
	mY = _y.getAsFloat();
	mZ = _z.getAsFloat();
	mW = _w.getAsFloat();
}

SCE_VECTORMATH_INLINE Quat::Quat(Vector3_arg xyz, float _w)
{
	this->setXYZ( xyz );
	this->setW( _w );
}

SCE_VECTORMATH_INLINE Quat::Quat(Vector3_arg xyz, floatInVec_arg _w)
{
	this->setXYZ( xyz );
	this->setW( _w.getAsFloat() );
}

SCE_VECTORMATH_INLINE Quat::Quat(Vector4_arg vec)
{
	mX = vec.getX().getAsFloat();
	mY = vec.getY().getAsFloat();
	mZ = vec.getZ().getAsFloat();
	mW = vec.getW().getAsFloat();
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE Quat::Quat(Matrix3_arg rotMat)
{
	float trace, radicand, scale, xx, yx, zx, xy, yy, zy, xz, yz, zz, tmpx, tmpy, tmpz, tmpw, qx, qy, qz, qw;
	bool negTrace, ZgtX, ZgtY, YgtX;
	bool largestXorY, largestYorZ, largestZorX;

	xx = rotMat.getCol0().getX().getAsFloat();
	yx = rotMat.getCol0().getY().getAsFloat();
	zx = rotMat.getCol0().getZ().getAsFloat();
	xy = rotMat.getCol1().getX().getAsFloat();
	yy = rotMat.getCol1().getY().getAsFloat();
	zy = rotMat.getCol1().getZ().getAsFloat();
	xz = rotMat.getCol2().getX().getAsFloat();
	yz = rotMat.getCol2().getY().getAsFloat();
	zz = rotMat.getCol2().getZ().getAsFloat();

	trace = ( ( xx + yy ) + zz );

	negTrace = ( trace < 0.0f );
	ZgtX = zz > xx;
	ZgtY = zz > yy;
	YgtX = yy > xx;
	largestXorY = ( !ZgtX || !ZgtY ) && negTrace;
	largestYorZ = ( YgtX || ZgtX ) && negTrace;
	largestZorX = ( ZgtY || !YgtX ) && negTrace;

	if ( largestXorY )
	{
		zz = -zz;
		xy = -xy;
	}
	if ( largestYorZ )
	{
		xx = -xx;
		yz = -yz;
	}
	if ( largestZorX )
	{
		yy = -yy;
		zx = -zx;
	}

	radicand = ( ( ( xx + yy ) + zz ) + 1.0f );
	scale = ( 0.5f * ( 1.0f / ::sqrtf( radicand ) ) );

	tmpx = ( ( zy - yz ) * scale );
	tmpy = ( ( xz - zx ) * scale );
	tmpz = ( ( yx - xy ) * scale );
	tmpw = ( radicand * scale );
	qx = tmpx;
	qy = tmpy;
	qz = tmpz;
	qw = tmpw;

	if ( largestXorY )
	{
		qx = tmpw;
		qy = tmpz;
		qz = tmpy;
		qw = tmpx;
	}
	if ( largestYorZ )
	{
		tmpx = qx;
		tmpz = qz;
		qx = qy;
		qy = tmpx;
		qz = qw;
		qw = tmpz;
	}

	mX = qx;
	mY = qy;
	mZ = qz;
	mW = qw;
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE Quat::Quat(float scalar)
{
	mX = scalar;
	mY = scalar;
	mZ = scalar;
	mW = scalar;
}

SCE_VECTORMATH_INLINE Quat::Quat(floatInVec_arg scalar)
{
	mX = scalar.getAsFloat();
	mY = scalar.getAsFloat();
	mZ = scalar.getAsFloat();
	mW = scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE Quat& Quat::operator =(Quat_arg quat)
{
	mX = quat.mX;
	mY = quat.mY;
	mZ = quat.mZ;
	mW = quat.mW;
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::setXY(Vector2_arg vec)
{
	mX = vec.getX().getAsFloat();
	mY = vec.getY().getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::setXYZ(Vector3_arg vec)
{
	mX = vec.getX().getAsFloat();
	mY = vec.getY().getAsFloat();
	mZ = vec.getZ().getAsFloat();
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector2 Quat::getXY() const
{
	return Vector2( mX, mY );
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector3 Quat::getXYZ() const
{
	return Vector3( mX, mY, mZ );
}

SCE_VECTORMATH_INLINE Quat& Quat::setX(float _x)
{
	mX = _x;
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::setY(float _y)
{
	mY = _y;
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::setZ(float _z)
{
	mZ = _z;
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::setW(float _w)
{
	mW = _w;
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::setX(floatInVec_arg _x)
{
	mX = _x.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::setY(floatInVec_arg _y)
{
	mY = _y.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::setZ(floatInVec_arg _z)
{
	mZ = _z.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::setW(floatInVec_arg _w)
{
	mW = _w.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Quat::getX() const
{
	return floatInVec(mX);
}

SCE_VECTORMATH_INLINE const floatInVec Quat::getY() const
{
	return floatInVec(mY);
}

SCE_VECTORMATH_INLINE const floatInVec Quat::getZ() const
{
	return floatInVec(mZ);
}

SCE_VECTORMATH_INLINE const floatInVec Quat::getW() const
{
	return floatInVec(mW);
}

SCE_VECTORMATH_INLINE Quat& Quat::setElem(int idx, float value)
{
	*(&mX + idx) = value;
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::setElem(int idx, floatInVec_arg value)
{
	*(&mX + idx) = value.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Quat::getElem(int idx) const
{
	return floatInVec(*(&mX + idx));
}

SCE_VECTORMATH_INLINE float & Quat::operator [](int idx)
{
	return *(&mX + idx);
}

SCE_VECTORMATH_INLINE const floatInVec Quat::operator [](int idx) const
{
	return floatInVec( *(&mX + idx) );
}

SCE_VECTORMATH_INLINE const Quat Quat::operator +(Quat_arg quat) const
{
	return Quat(
		( mX + quat.mX ),
		( mY + quat.mY ),
		( mZ + quat.mZ ),
		( mW + quat.mW )
		);
}

SCE_VECTORMATH_INLINE const Quat Quat::operator -(Quat_arg quat) const
{
	return Quat(
		( mX - quat.mX ),
		( mY - quat.mY ),
		( mZ - quat.mZ ),
		( mW - quat.mW )
		);
}

SCE_VECTORMATH_INLINE const Quat Quat::operator *(Quat_arg quat) const
{
	return Quat(
		( ( ( ( mW * quat.mX ) + ( mX * quat.mW ) ) + ( mY * quat.mZ ) ) - ( mZ * quat.mY ) ),
		( ( ( ( mW * quat.mY ) + ( mY * quat.mW ) ) + ( mZ * quat.mX ) ) - ( mX * quat.mZ ) ),
		( ( ( ( mW * quat.mZ ) + ( mZ * quat.mW ) ) + ( mX * quat.mY ) ) - ( mY * quat.mX ) ),
		( ( ( ( mW * quat.mW ) - ( mX * quat.mX ) ) - ( mY * quat.mY ) ) - ( mZ * quat.mZ ) )
		);
}

SCE_VECTORMATH_INLINE const Quat Quat::operator *(floatInVec_arg scalar) const
{
	return *this * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Quat Quat::operator *(float scalar) const
{
	return Quat(
		( mX * scalar ),
		( mY * scalar ),
		( mZ * scalar ),
		( mW * scalar )
		);
}

SCE_VECTORMATH_INLINE const Quat Quat::operator /(floatInVec_arg scalar) const
{
	return *this / scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Quat Quat::operator /(float scalar) const
{
	return Quat(
		( mX / scalar ),
		( mY / scalar ),
		( mZ / scalar ),
		( mW / scalar )
		);
}

SCE_VECTORMATH_INLINE Quat& Quat::operator +=(Quat_arg quat)
{
	*this = *this + quat;
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::operator -=(Quat_arg quat)
{
	*this = *this - quat;
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::operator *=(Quat_arg quat)
{
	*this = *this * quat;
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::operator *=(float scalar)
{
	*this = *this * scalar;
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::operator /=(float scalar)
{
	*this = *this / scalar;
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::operator *=(floatInVec_arg scalar)
{
	*this = *this * scalar.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Quat& Quat::operator /=(floatInVec_arg scalar)
{
	*this = *this / scalar.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE const Quat Quat::operator -() const
{
	return Quat(
		-mX,
		-mY,
		-mZ,
		-mW
		);
}

SCE_VECTORMATH_INLINE const Quat Quat::identity()
{
	return Quat( 0.0f, 0.0f, 0.0f, 1.0f );
}

SCE_VECTORMATH_INLINE const Quat Quat::zero()
{
	return Quat( 0.0f, 0.0f, 0.0f, 0.0f );
}

#if	!defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Vector4 Quat::axisAngle(Quat_arg unitQuat)
{
	const float kEpsilon = 0.0001f;
	float q_w = unitQuat.getW().getAsFloat();

	bool valid = ( ::fabsf( q_w ) <= 1.0f );

	float angle = ::acosf( q_w );
	angle += angle;

	float scale = 1.0f - ( q_w * q_w );
	valid |= ( scale > kEpsilon );
	Vector3 axis = unitQuat.getXYZ() / ::sqrtf( scale );

	Vector4 result = Vector4( axis, angle );
	result = select( Vector4::xAxis(), result, valid );
	return result;
}

SCE_VECTORMATH_INLINE const Vector3 Quat::euler(Quat_arg quat, RotationOrder order)
{
	// Sign masks
	const Vector4 signMods[ 6 ] = {
		Vector4( +1.f, -1.f, +1.f, +1.f ), // kXYZ
		Vector4( +1.f, +1.f, -1.f, +1.f ), // kYZX
		Vector4( -1.f, +1.f, +1.f, +1.f ), // kZXY
		Vector4( -1.f, -1.f, +1.f, +1.f ), // kXZY
		Vector4( +1.f, -1.f, -1.f, +1.f ), // kYXZ
		Vector4( -1.f, +1.f, -1.f, +1.f ), // kZYX
	};

	// Get various sums of squares
	Vector4 vquat = Vector4( quat );
	Vector4 sq_vquat = mulPerElem( vquat, vquat );
	Vector4 mtx11 = mulPerElem( sq_vquat, Vector4( +1.f, -1.f, -1.f, +1.f ) );
	mtx11 = Vector4( sum( mtx11 ) );
	Vector4 mtx22 = mulPerElem( sq_vquat, Vector4( -1.f, +1.f, -1.f, +1.f ) );
	mtx22 = Vector4( sum( mtx22 ) );
	Vector4 mtx33 = mulPerElem( sq_vquat, Vector4( -1.f, -1.f, +1.f, +1.f ) );
	mtx33 = Vector4( sum( mtx33 ) );

	// Replicate terms from quat
	Vector4 qX( quat.getX() );
	Vector4 qY( quat.getY() );
	Vector4 qZ( quat.getZ() );
	Vector4 qW( quat.getW() );

	Vector4 mtx23or32 = mulPerElem( qW, qX );
	Vector4 mtx31or13 = mulPerElem( qW, qY );
	Vector4 mtx12or21 = mulPerElem( qW, qZ );

	// Fetch sign bits, perform modification, multiply with lhs, then add to core value
	Vector4 signBits = signMods[ order ];
	mtx23or32 = mulPerElem( mulPerElem( qY, Vector4( signBits.getX() ) ), qZ ) + mtx23or32;
	mtx31or13 = mulPerElem( mulPerElem( qZ, Vector4( signBits.getY() ) ), qX ) + mtx31or13;
	mtx12or21 = mulPerElem( mulPerElem( qX, Vector4( signBits.getZ() ) ), qY ) + mtx12or21;

	// Scale by 2.0f (so.. that's an add then..)
	mtx23or32 += mtx23or32;
	mtx31or13 += mtx31or13;
	mtx12or21 += mtx12or21;

	// Reordering select masks, used to put in strict order (for asin/atan calls)
	const bool orderMasks[ 6 ][ 4 ]	=	{
		{ true,  false, false, false  },	// kXYZ
		{ false, false, true,  false  },	// kYZX
		{ false, true,  false, true	  },	// kZXY
		{ false, false, true,  false  },	// kXZY
		{ false, true,  false, true   },	// kYXZ
		{ true,  false, false, false  },	// kZYX
	};

	// At this point all mtx components should be good to do.. we need to re-order for asin/atan2f calls
	boolInVec replOrderX = boolInVec( orderMasks[ order ][ 0 ] );
	boolInVec replOrderY = boolInVec( orderMasks[ order ][ 1 ] );
	boolInVec replOrderZ = boolInVec( orderMasks[ order ][ 2 ] );
	boolInVec replOrderW = boolInVec( orderMasks[ order ][ 3 ] );

	Vector4 a = clampPerElem( select( select( mtx12or21, mtx31or13, replOrderX ), mtx23or32, replOrderY ), Vector4( -1.0f ), Vector4( +1.0f ) );
	Vector4 b = select( mtx23or32, mtx31or13, replOrderW );
	Vector4 c = select( mtx33, mtx22, replOrderZ );
	Vector4 d = select( mtx12or21, mtx31or13, replOrderZ );
	Vector4 e = select( mtx11, mtx22, replOrderW );

	// Do the maths..
	float results[ 3 ];
	results[ 0 ] = ::asinf( a.getX().getAsFloat() );
	results[ 1 ] = ::atan2f( b.getX().getAsFloat(), c.getX().getAsFloat() );
	results[ 2 ] = ::atan2f( d.getX().getAsFloat(), e.getX().getAsFloat() );

	// Now write to X, Y, and Z floats depending on rotation order..
	const int resultLoc[ 6 ][ 3 ] =
	{
		{ 1, 0, 2 }, // kXYZ
		{ 1, 2, 0 }, // kYZX
		{ 0, 1, 2 }, // kZXY
		{ 1, 2, 0 }, // kXZY
		{ 0, 1, 2 }, // kYXZ
		{ 1, 0, 2 }, // kZYX
	};

	Vector3 result( results[ resultLoc[ order ][ 0 ] ],
		results[ resultLoc[ order ][ 1 ] ],
		results[ resultLoc[ order ][ 2 ] ] );
	return result;
}

SCE_VECTORMATH_INLINE const Quat Quat::rotation(Vector3_arg radians, RotationOrder order)
{
	const int rotIndex[ 6 ][ 3 ] =
	{
		{ 0, 1, 2 }, // kXYZ
		{ 2, 0, 1 }, // kYZX
		{ 1, 2, 0 }, // kZXY
		{ 0, 2, 1 }, // kXZY
		{ 1, 0, 2 }, // kYXZ
		{ 2, 1, 0 }, // kZYX
	};

	// Build axial rotations
	Quat rotations[ 3 ];
	rotations[ rotIndex[ order ][ 0 ] ] = Quat::rotationX( radians.getX().getAsFloat() );
	rotations[ rotIndex[ order ][ 1 ] ] = Quat::rotationY( radians.getY().getAsFloat() );
	rotations[ rotIndex[ order ][ 2 ] ] = Quat::rotationZ( radians.getZ().getAsFloat() );

	// Generate our quaternion
	Quat result = ( ( rotations[ 2 ] * rotations[ 1 ] ) * rotations[ 0 ] );
	return result;
}

SCE_VECTORMATH_INLINE const Quat Quat::rotation(Vector3_arg unitVec0, Vector3_arg unitVec1)
{
	float cosHalfAngleX2, recipCosHalfAngleX2;
	cosHalfAngleX2 = ::sqrtf( ( 2.0f * ( 1.0f + dot( unitVec0, unitVec1 ).getAsFloat() ) ) );
	recipCosHalfAngleX2 = ( 1.0f / cosHalfAngleX2 );
	return Quat( ( cross( unitVec0, unitVec1 ) * recipCosHalfAngleX2 ), ( cosHalfAngleX2 * 0.5f ) );
}

SCE_VECTORMATH_INLINE const Quat Quat::rotation(floatInVec_arg radians, Vector3_arg unitVec)
{
	return rotation( radians.getAsFloat(), unitVec );
}

SCE_VECTORMATH_INLINE const Quat Quat::rotation(float radians, Vector3_arg unitVec)
{
	float s, c, angle;
	angle = ( radians * 0.5f );
	s = ::sinf( angle );
	c = ::cosf( angle );
	return Quat( ( unitVec * s ), c );
}

SCE_VECTORMATH_INLINE const Quat Quat::rotationX(floatInVec_arg radians)
{
	return rotationX( radians.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Quat Quat::rotationX(float radians)
{
	float s, c, angle;
	angle = ( radians * 0.5f );
	s = ::sinf( angle );
	c = ::cosf( angle );
	return Quat( s, 0.0f, 0.0f, c );
}

SCE_VECTORMATH_INLINE const Quat Quat::rotationY(floatInVec_arg radians)
{
	return rotationY( radians.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Quat Quat::rotationY(float radians)
{
	float s, c, angle;
	angle = ( radians * 0.5f );
	s = ::sinf( angle );
	c = ::cosf( angle );
	return Quat( 0.0f, s, 0.0f, c );
}

SCE_VECTORMATH_INLINE const Quat Quat::rotationZ(floatInVec_arg radians)
{
	return rotationZ( radians.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Quat Quat::rotationZ(float radians)
{
	float s, c, angle;
	angle = ( radians * 0.5f );
	s = ::sinf( angle );
	c = ::cosf( angle );
	return Quat( 0.0f, 0.0f, s, c );
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Quat operator *(floatInVec_arg scalar, Quat_arg quat)
{
	return quat * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Quat operator *(float scalar, Quat_arg quat)
{
	return quat * scalar;
}

SCE_VECTORMATH_INLINE const Quat conj(Quat_arg quat)
{
	return Quat( -quat.getX().getAsFloat(), -quat.getY().getAsFloat(), -quat.getZ().getAsFloat(), quat.getW().getAsFloat() );
}

SCE_VECTORMATH_INLINE const Vector3 rotate(Quat_arg quat, Vector3_arg vec)
{
	float tmpX, tmpY, tmpZ, tmpW;
	tmpX = ( ( ( quat.getW().getAsFloat() * vec.getX().getAsFloat() ) + ( quat.getY().getAsFloat() * vec.getZ().getAsFloat() ) ) - ( quat.getZ().getAsFloat() * vec.getY().getAsFloat() ) );
	tmpY = ( ( ( quat.getW().getAsFloat() * vec.getY().getAsFloat() ) + ( quat.getZ().getAsFloat() * vec.getX().getAsFloat() ) ) - ( quat.getX().getAsFloat() * vec.getZ().getAsFloat() ) );
	tmpZ = ( ( ( quat.getW().getAsFloat() * vec.getZ().getAsFloat() ) + ( quat.getX().getAsFloat() * vec.getY().getAsFloat() ) ) - ( quat.getY().getAsFloat() * vec.getX().getAsFloat() ) );
	tmpW = ( ( ( quat.getX().getAsFloat() * vec.getX().getAsFloat() ) + ( quat.getY().getAsFloat() * vec.getY().getAsFloat() ) ) + ( quat.getZ().getAsFloat() * vec.getZ().getAsFloat() ) );
	return Vector3(
		( ( ( ( tmpW * quat.getX().getAsFloat() ) + ( tmpX * quat.getW().getAsFloat() ) ) - ( tmpY * quat.getZ().getAsFloat() ) ) + ( tmpZ * quat.getY().getAsFloat() ) ),
		( ( ( ( tmpW * quat.getY().getAsFloat() ) + ( tmpY * quat.getW().getAsFloat() ) ) - ( tmpZ * quat.getX().getAsFloat() ) ) + ( tmpX * quat.getZ().getAsFloat() ) ),
		( ( ( ( tmpW * quat.getZ().getAsFloat() ) + ( tmpZ * quat.getW().getAsFloat() ) ) - ( tmpX * quat.getY().getAsFloat() ) ) + ( tmpY * quat.getX().getAsFloat() ) )
		);
}

SCE_VECTORMATH_INLINE const floatInVec dot(Quat_arg quat0, Quat_arg quat1)
{
	float result;
	result  = ( quat0.getX().getAsFloat() * quat1.getX().getAsFloat() );
	result += ( quat0.getY().getAsFloat() * quat1.getY().getAsFloat() );
	result += ( quat0.getZ().getAsFloat() * quat1.getZ().getAsFloat() );
	result += ( quat0.getW().getAsFloat() * quat1.getW().getAsFloat() );
	return floatInVec( result );
}

#if	!defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const floatInVec norm(Quat_arg quat)
{
	float result;
	result  = ( quat.getX().getAsFloat() * quat.getX().getAsFloat() );
	result += ( quat.getY().getAsFloat() * quat.getY().getAsFloat() );
	result += ( quat.getZ().getAsFloat() * quat.getZ().getAsFloat() );
	result += ( quat.getW().getAsFloat() * quat.getW().getAsFloat() );
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec lengthSqr(Quat_arg quat)
{
	return norm( quat );
}

SCE_VECTORMATH_INLINE const floatInVec length(Quat_arg quat)
{
	return floatInVec( ::sqrtf( lengthSqr( quat ).getAsFloat() ) );
}

SCE_VECTORMATH_INLINE const Quat normalize(Quat_arg quat)
{
	float lenInv = 1.0f / length( quat ).getAsFloat();
	return Quat(
		( quat.getX().getAsFloat() * lenInv ),
		( quat.getY().getAsFloat() * lenInv ),
		( quat.getZ().getAsFloat() * lenInv ),
		( quat.getW().getAsFloat() * lenInv )
		);
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Quat lerp(floatInVec_arg t, Quat_arg quat0, Quat_arg quat1)
{
	return lerp( t.getAsFloat(), quat0, quat1 );
}

SCE_VECTORMATH_INLINE const Quat lerp(float t, Quat_arg quat0, Quat_arg quat1)
{
	return ( quat0 + ( ( quat1 - quat0 ) * t ) );
}

#if	!defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Quat slerp(floatInVec_arg t, Quat_arg unitQuat0, Quat_arg unitQuat1, floatInVec_arg tol)
{
	return slerp( t.getAsFloat(), unitQuat0, unitQuat1, tol.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Quat slerp(float t, Quat_arg unitQuat0, Quat_arg unitQuat1, float tol)
{
	Quat start;
	float recipSinAngle, scale0, scale1, cosAngle, angle;
	cosAngle = dot( unitQuat0, unitQuat1 ).getAsFloat();
	if ( cosAngle < 0.0f ) {
		cosAngle = -cosAngle;
		start = ( -unitQuat0 );
	} else {
		start = unitQuat0;
	}
	if ( cosAngle < tol ) {
		angle = ::acosf( cosAngle );
		recipSinAngle = ( 1.0f / ::sinf( angle ) );
		scale0 = ( ::sinf( ( ( 1.0f - t ) * angle ) ) * recipSinAngle );
		scale1 = ( ::sinf( ( t * angle ) ) * recipSinAngle );
	} else {
		scale0 = ( 1.0f - t );
		scale1 = t;
	}
	return ( ( start * scale0 ) + ( unitQuat1 * scale1 ) );
}

SCE_VECTORMATH_INLINE const Quat squad(floatInVec_arg t, Quat_arg unitQuat0, Quat_arg unitQuat1, Quat_arg unitQuat2, Quat_arg unitQuat3)
{
	return squad( t.getAsFloat(), unitQuat0, unitQuat1, unitQuat2, unitQuat3 );
}

SCE_VECTORMATH_INLINE const Quat squad(float t, Quat_arg unitQuat0, Quat_arg unitQuat1, Quat_arg unitQuat2, Quat_arg unitQuat3)
{
	Quat tmp0, tmp1;
	tmp0 = slerp( t, unitQuat0, unitQuat3 );
	tmp1 = slerp( t, unitQuat1, unitQuat2 );
	return slerp( ( ( 2.0f * t ) * ( 1.0f - t ) ), tmp0, tmp1 );
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Quat select(Quat_arg quat0, Quat_arg quat1, boolInVec_arg select1)
{
	return ( select1.getAsBool() ? quat1 : quat0 );
}

SCE_VECTORMATH_INLINE const Quat select(Quat_arg quat0, Quat_arg quat1, bool select1)
{
	return ( select1 ? quat1 : quat0 );
}

SCE_VECTORMATH_INLINE void loadXYZW(Quat& quat, const float* fptr)
{
	quat = Quat( fptr[0], fptr[1], fptr[2], fptr[3] );
}

SCE_VECTORMATH_INLINE void storeXYZW(Quat_arg quat, float* fptr)
{
	fptr[0] = quat.getX().getAsFloat();
	fptr[1] = quat.getY().getAsFloat();
	fptr[2] = quat.getZ().getAsFloat();
	fptr[3] = quat.getW().getAsFloat();
}

#ifdef SCE_VECTORMATH_DEBUG

SCE_VECTORMATH_INLINE void print(Quat_arg quat)
{
	sce_vectormath_printf( "( %f %f %f %f )\n", quat.getX().getAsFloat(), quat.getY().getAsFloat(), quat.getZ().getAsFloat(), quat.getW().getAsFloat() );
}

SCE_VECTORMATH_INLINE void print(Quat_arg quat, const char* name)
{
	sce_vectormath_printf( "%s: ( %f %f %f %f )\n", name, quat.getX().getAsFloat(), quat.getY().getAsFloat(), quat.getZ().getAsFloat(), quat.getW().getAsFloat() );
}

#endif

} // namespace Aos
} // namespace Scalar
} // namespace Vectormath
} // namespace sce

#endif /* _PSP2_VECTORMATH_SCALAR_QUAT_AOS_CPP_H_ */
