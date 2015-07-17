/**
 * \file vec_aos.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_VECTORMATH_SCALAR_VEC_AOS_CPP_H_
#define _PSP2_VECTORMATH_SCALAR_VEC_AOS_CPP_H_


//-----------------------------------------------------------------------------
// Definitions

namespace sce {
namespace Vectormath {
namespace Scalar {
namespace Aos {

SCE_VECTORMATH_ALWAYS_INLINE Vector2::Vector2()
{
}

SCE_VECTORMATH_INLINE Vector2::Vector2( float _x, float _y )
{
	mX = _x;
	mY = _y;
}

SCE_VECTORMATH_INLINE Vector2::Vector2( floatInVec_arg _x, floatInVec_arg _y )
{
	mX = _x.getAsFloat();
	mY = _y.getAsFloat();
}

SCE_VECTORMATH_INLINE Vector2::Vector2( float scalar )
{
	mX = scalar;
	mY = scalar;
}

SCE_VECTORMATH_INLINE Vector2::Vector2( floatInVec_arg scalar )
{
	mX = scalar.getAsFloat();
	mY = scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE Vector2 & Vector2::operator =( Vector2_arg vec )
{
	mX = vec.mX;
	mY = vec.mY;
	return *this;
}

SCE_VECTORMATH_INLINE Vector2 & Vector2::setX( float _x )
{
	mX = _x;
	return *this;
}

SCE_VECTORMATH_INLINE Vector2 & Vector2::setX( floatInVec_arg _x )
{
	mX = _x.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Vector2::getX( ) const
{
	return floatInVec(mX);
}

SCE_VECTORMATH_INLINE Vector2 & Vector2::setY( float _y )
{
	mY = _y;
	return *this;
}

SCE_VECTORMATH_INLINE Vector2 & Vector2::setY( floatInVec_arg _y )
{
	mY = _y.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Vector2::getY( ) const
{
	return floatInVec(mY);
}

SCE_VECTORMATH_INLINE Vector2 & Vector2::setElem( int idx, float value )
{
	SCE_VECTORMATH_ASSERT_MSG( ( 0 == idx ) || ( 1 == idx ), "Element Index Out of Range" );
	*(&mX + idx) = value;
	return *this;
}

SCE_VECTORMATH_INLINE Vector2 & Vector2::setElem( int idx, floatInVec_arg value )
{
	SCE_VECTORMATH_ASSERT_MSG( ( 0 == idx ) || ( 1 == idx ), "Element Index Out of Range" );
	*(&mX + idx) = value.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Vector2::getElem( int idx ) const
{
	SCE_VECTORMATH_ASSERT_MSG( ( 0 == idx ) || ( 1 == idx ), "Element Index Out of Range" );
	return floatInVec(*(&mX + idx));
}

SCE_VECTORMATH_INLINE const floatInVec Vector2::operator []( const int idx ) const
{
	SCE_VECTORMATH_ASSERT_MSG( ( 0 == idx ) || ( 1 == idx ), "Element Index Out of Range" );
	return floatInVec(*(&mX + idx));
}

SCE_VECTORMATH_INLINE const Vector2 Vector2::operator +( Vector2_arg vec ) const
{
	return Vector2(
		( mX + vec.mX ),
		( mY + vec.mY )
		);
}

SCE_VECTORMATH_INLINE const Vector2 Vector2::operator -( Vector2_arg vec ) const
{
	return Vector2(
		( mX - vec.mX ),
		( mY - vec.mY )
		);
}

SCE_VECTORMATH_INLINE const Vector2 Vector2::operator *( floatInVec_arg scalar ) const
{
	return Vector2(
		( mX * scalar.getAsFloat() ),
		( mY * scalar.getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Vector2 Vector2::operator *( float scalar ) const
{
	return Vector2(
		( mX * scalar ),
		( mY * scalar )
		);
}

SCE_VECTORMATH_INLINE const Vector2 Vector2::operator /( floatInVec_arg scalar ) const
{
	return Vector2(
		( mX / scalar.getAsFloat() ),
		( mY / scalar.getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Vector2 Vector2::operator /( float scalar ) const
{
	return Vector2(
		( mX / scalar ),
		( mY / scalar )
		);
}

SCE_VECTORMATH_INLINE Vector2 & Vector2::operator +=( Vector2_arg vec )
{
	*this = *this + vec;
	return *this;
}

SCE_VECTORMATH_INLINE Vector2 & Vector2::operator -=( Vector2_arg vec )
{
	*this = *this - vec;
	return *this;
}

SCE_VECTORMATH_INLINE Vector2 & Vector2::operator *=( float scalar )
{
	*this = *this * scalar;
	return *this;
}

SCE_VECTORMATH_INLINE Vector2 & Vector2::operator *=( floatInVec_arg scalar )
{
	*this = *this * scalar.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Vector2 & Vector2::operator /=( float scalar )
{
	*this = *this / scalar;
	return *this;
}

SCE_VECTORMATH_INLINE Vector2 & Vector2::operator /=( floatInVec_arg scalar )
{
	*this = *this / scalar.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE const Vector2 Vector2::operator -( ) const
{
	return Vector2(
		-mX,
		-mY
		);
}

SCE_VECTORMATH_INLINE const Vector2 Vector2::xAxis()
{
	return Vector2( 1.0f, 0.0f );
}

SCE_VECTORMATH_INLINE const Vector2 Vector2::yAxis()
{
	return Vector2( 0.0f, 1.0f );
}

SCE_VECTORMATH_INLINE const Vector2 Vector2::zero()
{
	return Vector2( 0.0f, 0.0f );
}

SCE_VECTORMATH_INLINE const Vector2 operator *( float scalar, Vector2_arg vec )
{
	return vec * scalar;
}

SCE_VECTORMATH_INLINE const Vector2 operator *( floatInVec_arg scalar, Vector2_arg vec )
{
	return vec * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Vector2 mulPerElem( Vector2_arg vec0, Vector2_arg vec1 )
{
	return Vector2(
		( vec0.getX().getAsFloat() * vec1.getX().getAsFloat() ),
		( vec0.getY().getAsFloat() * vec1.getY().getAsFloat() )
	);
}

SCE_VECTORMATH_INLINE const Vector2 divPerElem( Vector2_arg vec0, Vector2_arg vec1 )
{
	return Vector2(
		( vec0.getX().getAsFloat() / vec1.getX().getAsFloat() ),
		( vec0.getY().getAsFloat() / vec1.getY().getAsFloat() )
	);
}

SCE_VECTORMATH_INLINE const Vector2 recipPerElem( Vector2_arg vec )
{
	return Vector2(
		( 1.0f / vec.getX().getAsFloat() ),
		( 1.0f / vec.getY().getAsFloat() )
	);
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Vector2 sqrtPerElem( Vector2_arg vec )
{
	return Vector2(
		::sqrtf( vec.getX().getAsFloat() ),
		::sqrtf( vec.getY().getAsFloat() )
	);
}

SCE_VECTORMATH_INLINE const Vector2 rsqrtPerElem( Vector2_arg vec )
{
	return Vector2(
		( 1.0f / ::sqrtf( vec.getX().getAsFloat() ) ),
		( 1.0f / ::sqrtf( vec.getY().getAsFloat() ) )
	);
}

SCE_VECTORMATH_INLINE const Vector2 absPerElem( Vector2_arg vec )
{
	return Vector2(
		::fabsf( vec.getX().getAsFloat() ),
		::fabsf( vec.getY().getAsFloat() )
	);
}

SCE_VECTORMATH_INLINE const Vector2 clampPerElem(Vector2_arg vec, Vector2_arg clampMin, Vector2_arg clampMax)
{
	return minPerElem( maxPerElem( clampMin , vec ), clampMax );
}

SCE_VECTORMATH_INLINE const Vector2 copySignPerElem( Vector2_arg vec0, Vector2_arg vec1 )
{
	float x0abs = ::fabsf( vec0.getX().getAsFloat() ); float x1 = vec1.getX().getAsFloat();
	float y0abs = ::fabsf( vec0.getY().getAsFloat() ); float y1 = vec1.getY().getAsFloat();
	return Vector2(
		( x1 < 0.0f ) ? -x0abs : x0abs,
		( y1 < 0.0f ) ? -y0abs : y0abs
		);
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Vector2 maxPerElem( Vector2_arg vec0, Vector2_arg vec1 )
{
	float x0 = vec0.getX().getAsFloat();
	float y0 = vec0.getY().getAsFloat();
	float x1 = vec1.getX().getAsFloat();
	float y1 = vec1.getY().getAsFloat();
	return Vector2(
		( x0 > x1 ) ? x0 : x1,
		( y0 > y1 ) ? y0 : y1
	);
}

SCE_VECTORMATH_INLINE const floatInVec maxElem( Vector2_arg vec )
{
	float x0 = vec.getX().getAsFloat();
	float y0 = vec.getY().getAsFloat();
	float result = ( x0 > y0 ) ? x0 : y0;
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const Vector2 minPerElem( Vector2_arg vec0, Vector2_arg vec1 )
{
	float x0 = vec0.getX().getAsFloat(); float x1 = vec1.getX().getAsFloat();
	float y0 = vec0.getY().getAsFloat(); float y1 = vec1.getY().getAsFloat();
	return Vector2(
		( x0 < x1 ) ? x0 : x1,
		( y0 < y1 ) ? y0 : y1
	);
}

SCE_VECTORMATH_INLINE const floatInVec minElem( Vector2_arg vec )
{
	float x0 = vec.getX().getAsFloat();
	float y0 = vec.getY().getAsFloat();
	float result = ( x0 < y0 ) ? x0 : y0;
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemLessThan(Vector2_arg vec0, Vector2_arg vec1)
{
	bool result      = ( vec0.getX().getAsFloat() < vec1.getX().getAsFloat() );
	result = result && ( vec0.getY().getAsFloat() < vec1.getY().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemLessThanOrEqual(Vector2_arg vec0, Vector2_arg vec1)
{
	bool result      = ( vec0.getX().getAsFloat() <= vec1.getX().getAsFloat() );
	result = result && ( vec0.getY().getAsFloat() <= vec1.getY().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThan(Vector2_arg vec0, Vector2_arg vec1)
{
	bool result      = ( vec0.getX().getAsFloat() > vec1.getX().getAsFloat() );
	result = result && ( vec0.getY().getAsFloat() > vec1.getY().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThanOrEqual(Vector2_arg vec0, Vector2_arg vec1)
{
	bool result      = ( vec0.getX().getAsFloat() >= vec1.getX().getAsFloat() );
	result = result && ( vec0.getY().getAsFloat() >= vec1.getY().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec sum( Vector2_arg vec )
{
	float result;
	result = ( vec.getX().getAsFloat() + vec.getY().getAsFloat() );
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec dot( Vector2_arg vec0, Vector2_arg vec1 )
{
	float result;
	result  = ( vec0.getX().getAsFloat() * vec1.getX().getAsFloat() );
	result += ( vec0.getY().getAsFloat() * vec1.getY().getAsFloat() );
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec lengthSqr( Vector2_arg vec )
{
	float result;
	result  = ( vec.getX().getAsFloat() * vec.getX().getAsFloat() );
	result += ( vec.getY().getAsFloat() * vec.getY().getAsFloat() );
	return floatInVec( result );
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const floatInVec length( Vector2_arg vec )
{
	return floatInVec( ::sqrtf( lengthSqr( vec ).getAsFloat() ) );
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const floatInVec determinant( Vector2_arg vec0, Vector2_arg vec1 )
{
	return floatInVec( ( vec0.getX().getAsFloat() * vec1.getY().getAsFloat() ) - ( vec1.getX().getAsFloat() * vec0.getY().getAsFloat() ) );
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const floatInVec angle( Vector2_arg vec )
{
	return floatInVec( ::atan2f( vec.getY().getAsFloat(), vec.getX().getAsFloat() ) );
}

SCE_VECTORMATH_INLINE const floatInVec angleBetween( Vector2_arg vec0, Vector2_arg vec1 )
{
	float dotProduct = dot( vec0, vec1 ).getAsFloat();
	float len0 = lengthSqr( vec0 ).getAsFloat();
	float len1 = lengthSqr( vec1 ).getAsFloat();
	return floatInVec( ::acosf( dotProduct / ::sqrtf( ( len0 * len1 ) ) ) );
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Vector2 perp( Vector2_arg vec )
{
	return Vector2( -vec.getY().getAsFloat(), vec.getX().getAsFloat() );
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Vector2 rotate(floatInVec_arg rot, Vector2_arg vec)
{
	float s = ::sinf( rot.getAsFloat() );
	float c = ::cosf( rot.getAsFloat() );
	float x = c * vec.getX().getAsFloat() - s * vec.getY().getAsFloat();
	float y = s * vec.getX().getAsFloat() + c * vec.getY().getAsFloat();
	return Vector2( x, y );
}

SCE_VECTORMATH_INLINE const Vector2 normalize( Vector2_arg vec )
{
	float len = length( vec ).getAsFloat();
	return ( vec / len );
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Vector2 lerp( floatInVec_arg t, Vector2_arg vec0, Vector2_arg vec1 )
{
	return lerp( t.getAsFloat(), vec0, vec1 );
}

SCE_VECTORMATH_INLINE const Vector2 lerp( float t, Vector2_arg vec0, Vector2_arg vec1 )
{
	return ( vec0 + ( vec1 - vec0 ) * t );
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Vector2 slerp( floatInVec_arg t, Vector2_arg unitVec0, Vector2_arg unitVec1, floatInVec_arg tol )
{
	return slerp( t.getAsFloat(), unitVec0, unitVec1, tol.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Vector2 slerp( float t, Vector2_arg unitVec0, Vector2_arg unitVec1, float tol )
{
	float recipSinAngle, scale0, scale1, cosAngle, angle;
	cosAngle = dot( unitVec0, unitVec1 ).getAsFloat();
	if ( ::fabsf( cosAngle ) < tol ) {
		angle = ::acosf( cosAngle );
		recipSinAngle = ( 1.0f / ::sinf( angle ) );
		scale0 = ( ::sinf( ( ( 1.0f - t ) * angle ) ) * recipSinAngle );
		scale1 = ( ::sinf( ( t * angle ) ) * recipSinAngle );
	} else {
		scale0 = ( 1.0f - t );
		scale1 = t;
	}
	return ( ( unitVec0 * scale0 ) + ( unitVec1 * scale1 ) );
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Vector2 select( Vector2_arg vec0, Vector2_arg vec1, bool select1 )
{
	return ( select1 ? vec1 : vec0 );
}

SCE_VECTORMATH_INLINE const Vector2 select( Vector2_arg vec0, Vector2_arg vec1, boolInVec_arg select1 )
{
	return select( vec0, vec1, select1.getAsBool() );
}

SCE_VECTORMATH_INLINE void loadXY( Vector2& vec, const float* fptr )
{
	vec = Vector2( fptr[0], fptr[1] );
}

SCE_VECTORMATH_INLINE void storeXY( Vector2_arg vec, float * fptr )
{
	fptr[0] = vec.getX().getAsFloat();
	fptr[1] = vec.getY().getAsFloat();
}

SCE_VECTORMATH_INLINE void loadXYArray( Vector2& vec0, Vector2& vec1, Vector2& vec2, Vector2& vec3, const float * fptr )
{
	vec0 = Vector2( fptr[0], fptr[1] );
	vec1 = Vector2( fptr[2], fptr[3] );
	vec2 = Vector2( fptr[4], fptr[5] );
	vec3 = Vector2( fptr[6], fptr[7] );
}

SCE_VECTORMATH_INLINE void storeXYArray( Vector2_arg vec0, Vector2_arg vec1, Vector2_arg vec2, Vector2_arg vec3, float * fptr )
{
	fptr[0] = vec0.getX().getAsFloat();
	fptr[1] = vec0.getY().getAsFloat();
	fptr[2] = vec1.getX().getAsFloat();
	fptr[3] = vec1.getY().getAsFloat();
	fptr[4] = vec2.getX().getAsFloat();
	fptr[5] = vec2.getY().getAsFloat();
	fptr[6] = vec3.getX().getAsFloat();
	fptr[7] = vec3.getY().getAsFloat();
}

SCE_VECTORMATH_INLINE void loadHalfFloats( Vector2& vec0, Vector2& vec1, Vector2& vec2, Vector2 & vec3, Vector2 & vec4, Vector2 & vec5, Vector2 & vec6, Vector2 & vec7, const uint16_t * hfptr )
{
	loadHalfFloats( vec0, &hfptr[0] );
	loadHalfFloats( vec1, &hfptr[2] );
	loadHalfFloats( vec2, &hfptr[4] );
	loadHalfFloats( vec3, &hfptr[6] );
	loadHalfFloats( vec4, &hfptr[8] );
	loadHalfFloats( vec5, &hfptr[10] );
	loadHalfFloats( vec6, &hfptr[12] );
	loadHalfFloats( vec7, &hfptr[14] );
}

SCE_VECTORMATH_INLINE void loadHalfFloats( Vector2& vec, const uint16_t * hfptr )
{
	union Data32 {
		uint32_t u32;
		float f32;
	} data[2];

	for( int i = 0; i < 2; i++ ) {
		uint32_t fp16 = static_cast<uint32_t>(hfptr[i]);
		uint32_t sign = (fp16 >> 15);
		uint32_t exponent = (fp16 >> 10) & ((1 << 5) - 1);
		uint32_t mantissa = fp16 & ((1 << 10) - 1);

		if (exponent == 0) {
			// zero
			mantissa = 0;
		} else if (exponent == 31 && mantissa != 0) {
			// nan
			exponent = 255;
			mantissa = (1 << 22);
			sign = 0;
		} else if (exponent == 31 && mantissa == 0) {
			// infinity
			exponent = 255;
			mantissa = 0;
		} else {
			exponent += 127 - 15;
			mantissa <<= 13;
		}

		data[i].u32 = (sign << 31) | (exponent << 23) | mantissa;
	}

	vec = Vector2( data[0].f32, data[1].f32 );
}

SCE_VECTORMATH_INLINE void storeHalfFloats( Vector2_arg vec0, Vector2_arg vec1, Vector2_arg vec2, Vector2_arg vec3, Vector2_arg vec4, Vector2_arg vec5, Vector2_arg vec6, Vector2_arg vec7, uint16_t *hfptr )
{
	storeHalfFloats( vec0, &hfptr[0] );
	storeHalfFloats( vec1, &hfptr[2] );
	storeHalfFloats( vec2, &hfptr[4] );
	storeHalfFloats( vec3, &hfptr[6] );
	storeHalfFloats( vec4, &hfptr[8] );
	storeHalfFloats( vec5, &hfptr[10] );
	storeHalfFloats( vec6, &hfptr[12] );
	storeHalfFloats( vec7, &hfptr[14] );
}

SCE_VECTORMATH_INLINE void storeHalfFloats( Vector2_arg vec, uint16_t * hfptr )
{
	union Data32 {
		uint32_t u32;
		float f32;
	};

	for (int i = 0; i < 2; i++) {
		Data32 d;
		d.f32 = vec[i].getAsFloat();

		uint32_t sign = d.u32 >> 31;
		uint32_t exponent = (d.u32 >> 23) & ((1 << 8) - 1);
		uint32_t mantissa = d.u32 & ((1 << 23) - 1);

		if (exponent == 0) {
			// zero or denorm -> zero
			mantissa = 0;
		} else if (exponent == 255 && mantissa != 0) {
			// nan
			exponent = 31;
			mantissa = (1 << 9);
			sign = 0;
		} else if (exponent >= 127 - 15 + 31) {
			// overflow or infinity -> infinity
			exponent = 31;
			mantissa = 0;
		} else if (exponent <= 127 - 15) {
			// underflow -> zero
			exponent = 0;
			mantissa = 0;
		} else {
			exponent -= 127 - 15;
			mantissa >>= 13;
		}

		hfptr[i] = static_cast<uint16_t>((sign << 15) | (exponent << 10) | mantissa);
	}
}

#ifdef SCE_VECTORMATH_DEBUG

SCE_VECTORMATH_INLINE void print( Vector2_arg vec )
{
	sce_vectormath_printf( "( %f %f )\n", vec.getX().getAsFloat(), vec.getY().getAsFloat() );
}

SCE_VECTORMATH_INLINE void print( Vector2_arg vec, const char * name )
{
	sce_vectormath_printf( "%s: ( %f %f )\n", name, vec.getX().getAsFloat(), vec.getY().getAsFloat() );
}

#endif

SCE_VECTORMATH_ALWAYS_INLINE Vector3::Vector3()
{
}

SCE_VECTORMATH_INLINE Vector3::Vector3(float x, float y, float z)
{
	mX = x;
	mY = y;
	mZ = z;
}

SCE_VECTORMATH_INLINE Vector3::Vector3(floatInVec_arg x, floatInVec_arg y, floatInVec_arg z)
{
	mX = x.getAsFloat();
	mY = y.getAsFloat();
	mZ = z.getAsFloat();
}

SCE_VECTORMATH_INLINE Vector3::Vector3(Vector2_arg xy, float z)
{
	mX = xy.getX().getAsFloat();
	mY = xy.getY().getAsFloat();
	mZ = z;
}

SCE_VECTORMATH_INLINE Vector3::Vector3(Vector2_arg xy, floatInVec_arg z)
{
	mX = xy.getX().getAsFloat();
	mY = xy.getY().getAsFloat();
	mZ = z.getAsFloat();
}

SCE_VECTORMATH_INLINE Vector3::Vector3(Point3_arg pnt)
{
	mX = pnt.getX().getAsFloat();
	mY = pnt.getY().getAsFloat();
	mZ = pnt.getZ().getAsFloat();
}

SCE_VECTORMATH_INLINE Vector3::Vector3(float scalar)
{
	mX = scalar;
	mY = scalar;
	mZ = scalar;
}

SCE_VECTORMATH_INLINE Vector3::Vector3(floatInVec_arg scalar)
{
	mX = scalar.getAsFloat();
	mY = scalar.getAsFloat();
	mZ = scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE Vector3& Vector3::operator =(Vector3_arg vec)
{
	mX = vec.mX;
	mY = vec.mY;
	mZ = vec.mZ;
	return *this;
}

SCE_VECTORMATH_INLINE Vector3& Vector3::setXY(Vector2_arg vec)
{
	mX = vec.getX().getAsFloat();
	mY = vec.getY().getAsFloat();
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector2 Vector3::getXY() const
{
	return Vector2( mX, mY );
}

SCE_VECTORMATH_INLINE Vector3& Vector3::setX(float x)
{
	mX = x;
	return *this;
}

SCE_VECTORMATH_INLINE Vector3& Vector3::setY(float y)
{
	mY = y;
	return *this;
}

SCE_VECTORMATH_INLINE Vector3& Vector3::setZ(float z)
{
	mZ = z;
	return *this;
}

SCE_VECTORMATH_INLINE Vector3& Vector3::setX(floatInVec_arg x)
{
	mX = x.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Vector3& Vector3::setY(floatInVec_arg y)
{
	mY = y.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Vector3& Vector3::setZ(floatInVec_arg z)
{
	mZ = z.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Vector3::getX() const
{
	return floatInVec(mX);
}

SCE_VECTORMATH_INLINE const floatInVec Vector3::getY() const
{
	return floatInVec(mY);
}

SCE_VECTORMATH_INLINE const floatInVec Vector3::getZ() const
{
	return floatInVec(mZ);
}

SCE_VECTORMATH_INLINE Vector3& Vector3::setElem(int idx, float value)
{
	*(&mX + idx) = value;
	return *this;
}

SCE_VECTORMATH_INLINE Vector3& Vector3::setElem(int idx, floatInVec_arg value)
{
	*(&mX + idx) = value.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Vector3::getElem(int idx) const
{
	return floatInVec(*(&mX + idx));
}

SCE_VECTORMATH_INLINE float& Vector3::operator [](int idx)
{
	return *(&mX + idx);
}

SCE_VECTORMATH_INLINE const floatInVec Vector3::operator [](int idx) const
{
	return floatInVec( *(&mX + idx) );
}

SCE_VECTORMATH_INLINE const Vector3 Vector3::operator +(Vector3_arg vec) const
{
	return Vector3(
		( mX + vec.mX ),
		( mY + vec.mY ),
		( mZ + vec.mZ )
		);
}

SCE_VECTORMATH_INLINE const Vector3 Vector3::operator -(Vector3_arg vec) const
{
	return Vector3(
		( mX - vec.mX ),
		( mY - vec.mY ),
		( mZ - vec.mZ )
		);
}

SCE_VECTORMATH_INLINE const Point3 Vector3::operator +(Point3_arg pnt) const
{
	return Point3(
		( mX + pnt.getX().getAsFloat() ),
		( mY + pnt.getY().getAsFloat() ),
		( mZ + pnt.getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Vector3 Vector3::operator *(float scalar) const
{
	return Vector3(
		( mX * scalar ),
		( mY * scalar ),
		( mZ * scalar )
		);
}

SCE_VECTORMATH_INLINE const Vector3 Vector3::operator /(float scalar) const
{
	return Vector3(
		( mX / scalar ),
		( mY / scalar ),
		( mZ / scalar )
		);
}

SCE_VECTORMATH_INLINE const Vector3 Vector3::operator *(floatInVec_arg scalar) const
{
	return *this * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Vector3 Vector3::operator /(floatInVec_arg scalar) const
{
	return *this / scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE Vector3& Vector3::operator +=(Vector3_arg vec)
{
	return *this = *this + vec;
}

SCE_VECTORMATH_INLINE Vector3& Vector3::operator -=(Vector3_arg vec)
{
	return *this = *this - vec;
}

SCE_VECTORMATH_INLINE Vector3& Vector3::operator *=(float scalar)
{
	return *this = *this * scalar;
}

SCE_VECTORMATH_INLINE Vector3& Vector3::operator /=(float scalar)
{
	return *this = *this / scalar;
}

SCE_VECTORMATH_INLINE Vector3& Vector3::operator *=(floatInVec_arg scalar)
{
	return *this = *this * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE Vector3& Vector3::operator /=(floatInVec_arg scalar)
{
	return *this = *this / scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Vector3 Vector3::operator -() const
{
	return Vector3(
		-mX,
		-mY,
		-mZ
		);
}

SCE_VECTORMATH_INLINE const Vector3 Vector3::xAxis()
{
	return Vector3( 1.0f, 0.0f, 0.0f );
}

SCE_VECTORMATH_INLINE const Vector3 Vector3::yAxis()
{
	return Vector3( 0.0f, 1.0f, 0.0f );
}

SCE_VECTORMATH_INLINE const Vector3 Vector3::zAxis()
{
	return Vector3( 0.0f, 0.0f, 1.0f );
}

SCE_VECTORMATH_INLINE const Vector3 Vector3::zero()
{
	return Vector3( 0.0f, 0.0f, 0.0f );
}

SCE_VECTORMATH_INLINE const Vector3 operator *(float scalar, Vector3_arg vec)
{
	return vec * scalar;
}

SCE_VECTORMATH_INLINE const Vector3 operator *(floatInVec_arg scalar, Vector3_arg vec)
{
	return vec * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Vector3 mulPerElem(Vector3_arg vec0, Vector3_arg vec1)
{
	return Vector3(
		( vec0.getX().getAsFloat() * vec1.getX().getAsFloat() ),
		( vec0.getY().getAsFloat() * vec1.getY().getAsFloat() ),
		( vec0.getZ().getAsFloat() * vec1.getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Vector3 divPerElem(Vector3_arg vec0, Vector3_arg vec1)
{
	return Vector3(
		( vec0.getX().getAsFloat() / vec1.getX().getAsFloat() ),
		( vec0.getY().getAsFloat() / vec1.getY().getAsFloat() ),
		( vec0.getZ().getAsFloat() / vec1.getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Vector3 recipPerElem(Vector3_arg vec)
{
	return Vector3(
		( 1.0f / vec.getX().getAsFloat() ),
		( 1.0f / vec.getY().getAsFloat() ),
		( 1.0f / vec.getZ().getAsFloat() )
		);
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Vector3 sqrtPerElem(Vector3_arg vec)
{
	return Vector3(
		::sqrtf( vec.getX().getAsFloat() ),
		::sqrtf( vec.getY().getAsFloat() ),
		::sqrtf( vec.getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Vector3 rsqrtPerElem(Vector3_arg vec)
{
	return Vector3(
		( 1.0f / ::sqrtf( vec.getX().getAsFloat() ) ),
		( 1.0f / ::sqrtf( vec.getY().getAsFloat() ) ),
		( 1.0f / ::sqrtf( vec.getZ().getAsFloat() ) )
		);
}

SCE_VECTORMATH_INLINE const Vector3 absPerElem(Vector3_arg vec)
{
	return Vector3(
		::fabsf( vec.getX().getAsFloat() ),
		::fabsf( vec.getY().getAsFloat() ),
		::fabsf( vec.getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Vector3 clampPerElem(Vector3_arg vec, Vector3_arg clampMin, Vector3_arg clampMax)
{
	return minPerElem( maxPerElem( clampMin , vec ), clampMax );
}

SCE_VECTORMATH_INLINE const Vector3 copySignPerElem(Vector3_arg vec0, Vector3_arg vec1)
{
	float x0abs = ::fabsf( vec0.getX().getAsFloat() ); float x1 = vec1.getX().getAsFloat();
	float y0abs = ::fabsf( vec0.getY().getAsFloat() ); float y1 = vec1.getY().getAsFloat();
	float z0abs = ::fabsf( vec0.getZ().getAsFloat() ); float z1 = vec1.getZ().getAsFloat();
	return Vector3(
		( x1 < 0.0f ) ? -x0abs : x0abs,
		( y1 < 0.0f ) ? -y0abs : y0abs,
		( z1 < 0.0f ) ? -z0abs : z0abs
		);
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Vector3 maxPerElem(Vector3_arg vec0, Vector3_arg vec1)
{
	float x0 = vec0.getX().getAsFloat(); float x1 = vec1.getX().getAsFloat();
	float y0 = vec0.getY().getAsFloat(); float y1 = vec1.getY().getAsFloat();
	float z0 = vec0.getZ().getAsFloat(); float z1 = vec1.getZ().getAsFloat();
	return Vector3(
		( x0 > x1 ) ? x0 : x1,
		( y0 > y1 ) ? y0 : y1,
		( z0 > z1 ) ? z0 : z1
		);
}

SCE_VECTORMATH_INLINE const Vector3 minPerElem(Vector3_arg vec0, Vector3_arg vec1)
{
	float x0 = vec0.getX().getAsFloat(); float x1 = vec1.getX().getAsFloat();
	float y0 = vec0.getY().getAsFloat(); float y1 = vec1.getY().getAsFloat();
	float z0 = vec0.getZ().getAsFloat(); float z1 = vec1.getZ().getAsFloat();
	return Vector3(
		( x0 < x1 ) ? x0 : x1,
		( y0 < y1 ) ? y0 : y1,
		( z0 < z1 ) ? z0 : z1
		);
}

SCE_VECTORMATH_INLINE const floatInVec maxElem(Vector3_arg vec)
{
	float x0 = vec.getX().getAsFloat();
	float y0 = vec.getY().getAsFloat();
	float z0 = vec.getZ().getAsFloat();
	float result;
	result = ( x0 > y0 ) ? x0 : y0;
	result = ( z0 > result ) ? z0 : result;
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec minElem(Vector3_arg vec)
{
	float x0 = vec.getX().getAsFloat();
	float y0 = vec.getY().getAsFloat();
	float z0 = vec.getZ().getAsFloat();
	float result;
	result = ( x0 < y0 ) ? x0 : y0;
	result = ( z0 < result ) ? z0 : result;
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemLessThan(Vector3_arg vec0, Vector3_arg vec1)
{
	bool result      = ( vec0.getX().getAsFloat() < vec1.getX().getAsFloat() );
	result = result && ( vec0.getY().getAsFloat() < vec1.getY().getAsFloat() );
	result = result && ( vec0.getZ().getAsFloat() < vec1.getZ().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemLessThanOrEqual(Vector3_arg vec0, Vector3_arg vec1)
{
	bool result      = ( vec0.getX().getAsFloat() <= vec1.getX().getAsFloat() );
	result = result && ( vec0.getY().getAsFloat() <= vec1.getY().getAsFloat() );
	result = result && ( vec0.getZ().getAsFloat() <= vec1.getZ().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThan(Vector3_arg vec0, Vector3_arg vec1)
{
	bool result      = ( vec0.getX().getAsFloat() > vec1.getX().getAsFloat() );
	result = result && ( vec0.getY().getAsFloat() > vec1.getY().getAsFloat() );
	result = result && ( vec0.getZ().getAsFloat() > vec1.getZ().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThanOrEqual(Vector3_arg vec0, Vector3_arg vec1)
{
	bool result      = ( vec0.getX().getAsFloat() >= vec1.getX().getAsFloat() );
	result = result && ( vec0.getY().getAsFloat() >= vec1.getY().getAsFloat() );
	result = result && ( vec0.getZ().getAsFloat() >= vec1.getZ().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec sum(Vector3_arg vec)
{
	float result;
	result  = vec.getX().getAsFloat();
	result += vec.getY().getAsFloat();
	result += vec.getZ().getAsFloat();
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec dot(Vector3_arg vec0, Vector3_arg vec1)
{
	float result;
	result  = ( vec0.getX().getAsFloat() * vec1.getX().getAsFloat() );
	result += ( vec0.getY().getAsFloat() * vec1.getY().getAsFloat() );
	result += ( vec0.getZ().getAsFloat() * vec1.getZ().getAsFloat() );
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec lengthSqr(Vector3_arg vec)
{
	float result;
	result  = ( vec.getX().getAsFloat() * vec.getX().getAsFloat() );
	result += ( vec.getY().getAsFloat() * vec.getY().getAsFloat() );
	result += ( vec.getZ().getAsFloat() * vec.getZ().getAsFloat() );
	return floatInVec( result );
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const floatInVec length(Vector3_arg vec)
{
	return floatInVec( ::sqrtf( lengthSqr( vec ).getAsFloat() ) );
}

SCE_VECTORMATH_INLINE const Vector3 normalize(Vector3_arg vec)
{
	float lenSqr, lenInv;
	lenSqr = lengthSqr( vec ).getAsFloat();
	lenInv = 1.0f / ::sqrtf( lenSqr );
	return Vector3(
		( vec.getX().getAsFloat() * lenInv ),
		( vec.getY().getAsFloat() * lenInv ),
		( vec.getZ().getAsFloat() * lenInv )
		);
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Vector3 cross(Vector3_arg vec0, Vector3_arg vec1)
{
	return Vector3(
		( ( vec0.getY().getAsFloat() * vec1.getZ().getAsFloat() ) - ( vec0.getZ().getAsFloat() * vec1.getY().getAsFloat() ) ),
		( ( vec0.getZ().getAsFloat() * vec1.getX().getAsFloat() ) - ( vec0.getX().getAsFloat() * vec1.getZ().getAsFloat() ) ),
		( ( vec0.getX().getAsFloat() * vec1.getY().getAsFloat() ) - ( vec0.getY().getAsFloat() * vec1.getX().getAsFloat() ) )
		);
}

SCE_VECTORMATH_INLINE const Matrix3 outer(Vector3_arg vec0, Vector3_arg vec1)
{
	return Matrix3(
		(vec0 * vec1.getX().getAsFloat()),
		(vec0 * vec1.getY().getAsFloat()),
		(vec0 * vec1.getZ().getAsFloat())
		);
}

SCE_VECTORMATH_INLINE const Vector3 rowMul(Vector3_arg vec, Matrix3_arg mat)
{
	return Vector3(
		( ( ( vec.getX().getAsFloat() * mat.getCol0().getX().getAsFloat() ) + ( vec.getY().getAsFloat() * mat.getCol0().getY().getAsFloat() ) ) + ( vec.getZ().getAsFloat() * mat.getCol0().getZ().getAsFloat() ) ),
		( ( ( vec.getX().getAsFloat() * mat.getCol1().getX().getAsFloat() ) + ( vec.getY().getAsFloat() * mat.getCol1().getY().getAsFloat() ) ) + ( vec.getZ().getAsFloat() * mat.getCol1().getZ().getAsFloat() ) ),
		( ( ( vec.getX().getAsFloat() * mat.getCol2().getX().getAsFloat() ) + ( vec.getY().getAsFloat() * mat.getCol2().getY().getAsFloat() ) ) + ( vec.getZ().getAsFloat() * mat.getCol2().getZ().getAsFloat() ) )
		);
}

SCE_VECTORMATH_INLINE const Matrix3 crossMatrix(Vector3_arg vec)
{
	return Matrix3(
		Vector3( 0.0f, vec.getZ().getAsFloat(), -vec.getY().getAsFloat() ),
		Vector3( -vec.getZ().getAsFloat(), 0.0f, vec.getX().getAsFloat() ),
		Vector3( vec.getY().getAsFloat(), -vec.getX().getAsFloat(), 0.0f )
		);
}

SCE_VECTORMATH_INLINE const Matrix3 crossMatrixMul(Vector3_arg vec, Matrix3_arg mat)
{
	return Matrix3(
		cross(vec, mat.getCol0()),
		cross(vec, mat.getCol1()),
		cross(vec, mat.getCol2())
		);
}

SCE_VECTORMATH_INLINE const Vector3 lerp(floatInVec_arg t, Vector3_arg vec0, Vector3_arg vec1)
{
	return lerp( t.getAsFloat(), vec0, vec1 );
}

SCE_VECTORMATH_INLINE const Vector3 lerp(float t, Vector3_arg vec0, Vector3_arg vec1)
{
	return ( vec0 + ( ( vec1 - vec0 ) * t ) );
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Vector3 slerp(floatInVec_arg t, Vector3_arg unitVec0, Vector3_arg unitVec1, floatInVec_arg tol)
{
	return slerp( t.getAsFloat(), unitVec0, unitVec1, tol.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Vector3 slerp(float t, Vector3_arg unitVec0, Vector3_arg unitVec1, float tol)
{
	float recipSinAngle, scale0, scale1, cosAngle, angle;
	cosAngle = dot( unitVec0, unitVec1 ).getAsFloat();
	if ( ::fabsf( cosAngle ) < tol ) {
		angle = ::acosf( cosAngle );
		recipSinAngle = ( 1.0f / ::sinf( angle ) );
		scale0 = ( ::sinf( ( ( 1.0f - t ) * angle ) ) * recipSinAngle );
		scale1 = ( ::sinf( ( t * angle ) ) * recipSinAngle );
	} else {
		scale0 = ( 1.0f - t );
		scale1 = t;
	}
	return ( ( unitVec0 * scale0 ) + ( unitVec1 * scale1 ) );
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Vector3 select(Vector3_arg vec0, Vector3_arg vec1, boolInVec_arg select1)
{
	return ( select1.getAsBool() ? vec1 : vec0 );
}

SCE_VECTORMATH_INLINE const Vector3 select(Vector3_arg vec0, Vector3_arg vec1, bool select1)
{
	return ( select1 ? vec1 : vec0 );
}

SCE_VECTORMATH_INLINE void loadXYZ(Vector3& vec, const float* fptr)
{
	vec = Vector3( fptr[0], fptr[1], fptr[2] );
}

SCE_VECTORMATH_INLINE void storeXYZ( Vector3_arg vec, float * fptr )
{
	fptr[0] = vec.getX().getAsFloat();
	fptr[1] = vec.getY().getAsFloat();
	fptr[2] = vec.getZ().getAsFloat();
}

SCE_VECTORMATH_INLINE void loadXYZArray(Vector3& vec0, Vector3& vec1, Vector3& vec2, Vector3& vec3, const float* fptr)
{
	loadXYZ( vec0, fptr+0 );
	loadXYZ( vec1, fptr+3 );
	loadXYZ( vec2, fptr+6 );
	loadXYZ( vec3, fptr+9 );
}

SCE_VECTORMATH_INLINE void storeXYZArray(Vector3_arg vec0, Vector3_arg vec1, Vector3_arg vec2, Vector3_arg vec3, float* fptr)
{
	storeXYZ( vec0, fptr+0 );
	storeXYZ( vec1, fptr+3 );
	storeXYZ( vec2, fptr+6 );
	storeXYZ( vec3, fptr+9 );
}

SCE_VECTORMATH_INLINE void loadHalfFloats(Vector3& vec0, Vector3& vec1, Vector3& vec2, Vector3& vec3, Vector3& vec4, Vector3& vec5, Vector3& vec6, Vector3& vec7, const uint16_t* hfptr)
{
	loadHalfFloats( vec0, hfptr+0 );
	loadHalfFloats( vec1, hfptr+3 );
	loadHalfFloats( vec2, hfptr+6 );
	loadHalfFloats( vec3, hfptr+9 );
	loadHalfFloats( vec4, hfptr+12 );
	loadHalfFloats( vec5, hfptr+15 );
	loadHalfFloats( vec6, hfptr+18 );
	loadHalfFloats( vec7, hfptr+21 );
}

SCE_VECTORMATH_INLINE void loadHalfFloats(Vector3& vec, const uint16_t* hfptr)
{
	union Data32 {
		uint32_t u32;
		float f32;
	};

	for (int i = 0; i < 3; i++) {
		uint32_t fp16 = static_cast<uint32_t>(hfptr[i]);
		uint32_t sign = (fp16 >> 15);
		uint32_t exponent = (fp16 >> 10) & ((1 << 5) - 1);
		uint32_t mantissa = fp16 & ((1 << 10) - 1);

		if (exponent == 0) {
			// zero
			mantissa = 0;
		} else if (exponent == 31 && mantissa != 0) {
			// nan
			exponent = 255;
			mantissa = (1 << 22);
			sign = 0;
		} else if (exponent == 31 && mantissa == 0) {
			// infinity
			exponent = 255;
			mantissa = 0;
		} else {
			exponent += 127 - 15;
			mantissa <<= 13;
		}

		Data32 d;
		d.u32 = (sign << 31) | (exponent << 23) | mantissa;
		vec[i] = d.f32;
	}
}

SCE_VECTORMATH_INLINE void storeHalfFloats(Vector3_arg vec0, Vector3_arg vec1, Vector3_arg vec2, Vector3_arg vec3, Vector3_arg vec4, Vector3_arg vec5, Vector3_arg vec6, Vector3_arg vec7, uint16_t* hfptr)
{
	storeHalfFloats( vec0, hfptr+0 );
	storeHalfFloats( vec1, hfptr+3 );
	storeHalfFloats( vec2, hfptr+6 );
	storeHalfFloats( vec3, hfptr+9 );
	storeHalfFloats( vec4, hfptr+12 );
	storeHalfFloats( vec5, hfptr+15 );
	storeHalfFloats( vec6, hfptr+18 );
	storeHalfFloats( vec7, hfptr+21 );
}

SCE_VECTORMATH_INLINE void storeHalfFloats(Vector3_arg vec, uint16_t* hfptr)
{
	union Data32 {
		uint32_t u32;
		float f32;
	};

	for (int i = 0; i < 3; i++) {
		Data32 d;
		d.f32 = vec[i].getAsFloat();

		uint32_t sign = d.u32 >> 31;
		uint32_t exponent = (d.u32 >> 23) & ((1 << 8) - 1);
		uint32_t mantissa = d.u32 & ((1 << 23) - 1);

		if (exponent == 0) {
			// zero or denorm -> zero
			mantissa = 0;
		} else if (exponent == 255 && mantissa != 0) {
			// nan
			exponent = 31;
			mantissa = (1 << 9);
			sign = 0;
		} else if (exponent >= 127 - 15 + 31) {
			// overflow or infinity -> infinity
			exponent = 31;
			mantissa = 0;
		} else if (exponent <= 127 - 15) {
			// underflow -> zero
			exponent = 0;
			mantissa = 0;
		} else {
			exponent -= 127 - 15;
			mantissa >>= 13;
		}

		hfptr[i] = static_cast<uint16_t>((sign << 15) | (exponent << 10) | mantissa);
	}
}

#ifdef SCE_VECTORMATH_DEBUG

SCE_VECTORMATH_INLINE void print(Vector3_arg vec)
{
	sce_vectormath_printf( "( %f %f %f )\n", vec.getX().getAsFloat(), vec.getY().getAsFloat(), vec.getZ().getAsFloat() );
}

SCE_VECTORMATH_INLINE void print(Vector3_arg vec, const char* name)
{
	sce_vectormath_printf( "%s: ( %f %f %f )\n", name, vec.getX().getAsFloat(), vec.getY().getAsFloat(), vec.getZ().getAsFloat() );
}

#endif

SCE_VECTORMATH_ALWAYS_INLINE Vector4::Vector4()
{

}

SCE_VECTORMATH_INLINE Vector4::Vector4(float x, float y, float z, float w)
{
	mX = x;
	mY = y;
	mZ = z;
	mW = w;
}

SCE_VECTORMATH_INLINE Vector4::Vector4(floatInVec_arg x, floatInVec_arg y, floatInVec_arg z, floatInVec_arg w)
{
	mX = x.getAsFloat();
	mY = y.getAsFloat();
	mZ = z.getAsFloat();
	mW = w.getAsFloat();
}

SCE_VECTORMATH_INLINE Vector4::Vector4(Vector2_arg xy, float z, float w)
{
	this->setX( xy.getX().getAsFloat() );
	this->setY( xy.getY().getAsFloat() );
	this->setZ( z );
	this->setW( w );
}

SCE_VECTORMATH_INLINE Vector4::Vector4(Vector2_arg xy, floatInVec_arg z, floatInVec_arg w)
{
	this->setX( xy.getX().getAsFloat() );
	this->setY( xy.getY().getAsFloat() );
	this->setZ( z );
	this->setW( w );
}

SCE_VECTORMATH_INLINE Vector4::Vector4(Vector2_arg xy, Vector2_arg zw)
{
	this->setX( xy.getX().getAsFloat() );
	this->setY( xy.getY().getAsFloat() );
	this->setZ( zw.getX().getAsFloat() );
	this->setW( zw.getY().getAsFloat() );
}

SCE_VECTORMATH_INLINE Vector4::Vector4(Vector3_arg xyz, float w)
{
	this->setXYZ( xyz );
	this->setW( w );
}

SCE_VECTORMATH_INLINE Vector4::Vector4(Vector3_arg xyz, floatInVec_arg w)
{
	this->setXYZ( xyz );
	this->setW( w );
}

SCE_VECTORMATH_INLINE Vector4::Vector4(Vector3_arg vec)
{
	mX = vec.getX().getAsFloat();
	mY = vec.getY().getAsFloat();
	mZ = vec.getZ().getAsFloat();
	mW = 0.0f;
}

SCE_VECTORMATH_INLINE Vector4::Vector4(Point3_arg pnt)
{
	mX = pnt.getX().getAsFloat();
	mY = pnt.getY().getAsFloat();
	mZ = pnt.getZ().getAsFloat();
	mW = 1.0f;
}

SCE_VECTORMATH_INLINE Vector4::Vector4(Quat_arg quat)
{
	mX = quat.getX().getAsFloat();
	mY = quat.getY().getAsFloat();
	mZ = quat.getZ().getAsFloat();
	mW = quat.getW().getAsFloat();
}

SCE_VECTORMATH_INLINE Vector4::Vector4(float scalar)
{
	mX = scalar;
	mY = scalar;
	mZ = scalar;
	mW = scalar;
}

SCE_VECTORMATH_INLINE Vector4::Vector4(floatInVec_arg scalar)
{
	mX = scalar.getAsFloat();
	mY = scalar.getAsFloat();
	mZ = scalar.getAsFloat();
	mW = scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE Vector4& Vector4::operator =(Vector4_arg vec)
{
	mX = vec.mX;
	mY = vec.mY;
	mZ = vec.mZ;
	mW = vec.mW;
	return *this;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::setXY(Vector2_arg vec)
{
	mX = vec.getX().getAsFloat();
	mY = vec.getY().getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::setXYZ(Vector3_arg vec)
{
	mX = vec.getX().getAsFloat();
	mY = vec.getY().getAsFloat();
	mZ = vec.getZ().getAsFloat();
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector2 Vector4::getXY() const
{
	return Vector2( mX, mY );
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector3 Vector4::getXYZ() const
{
	return Vector3( mX, mY, mZ );
}

SCE_VECTORMATH_INLINE Vector4& Vector4::setX(float x)
{
	mX = x;
	return *this;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::setY(float y)
{
	mY = y;
	return *this;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::setZ(float z)
{
	mZ = z;
	return *this;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::setW(float w)
{
	mW = w;
	return *this;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::setX(floatInVec_arg x)
{
	mX = x.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::setY(floatInVec_arg y)
{
	mY = y.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::setZ(floatInVec_arg z)
{
	mZ = z.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::setW(floatInVec_arg w)
{
	mW = w.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Vector4::getX() const
{
	return floatInVec(mX);
}

SCE_VECTORMATH_INLINE const floatInVec Vector4::getY() const
{
	return floatInVec(mY);
}

SCE_VECTORMATH_INLINE const floatInVec Vector4::getZ() const
{
	return floatInVec(mZ);
}

SCE_VECTORMATH_INLINE const floatInVec Vector4::getW() const
{
	return floatInVec(mW);
}

SCE_VECTORMATH_INLINE Vector4& Vector4::setElem(int idx, float value)
{
	*(&mX + idx) = value;
	return *this;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::setElem(int idx, floatInVec_arg value)
{
	*(&mX + idx) = value.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Vector4::getElem(int idx) const
{
	return floatInVec(*(&mX + idx));
}

SCE_VECTORMATH_INLINE float& Vector4::operator [](int idx)
{
	return *(&mX + idx);
}

SCE_VECTORMATH_INLINE const floatInVec Vector4::operator [](int idx) const
{
	return floatInVec( *(&mX + idx) );
}

SCE_VECTORMATH_INLINE const Vector4 Vector4::operator +(Vector4_arg vec) const
{
	return Vector4(
		( mX + vec.mX ),
		( mY + vec.mY ),
		( mZ + vec.mZ ),
		( mW + vec.mW )
		);
}

SCE_VECTORMATH_INLINE const Vector4 Vector4::operator -(Vector4_arg vec) const
{
	return Vector4(
		( mX - vec.mX ),
		( mY - vec.mY ),
		( mZ - vec.mZ ),
		( mW - vec.mW )
		);
}

SCE_VECTORMATH_INLINE const Vector4 Vector4::operator /(floatInVec_arg scalar) const
{
	return *this / scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Vector4 Vector4::operator /(float scalar) const
{
	return Vector4(
		( mX / scalar ),
		( mY / scalar ),
		( mZ / scalar ),
		( mW / scalar )
		);
}

SCE_VECTORMATH_INLINE const Vector4 Vector4::operator *(floatInVec_arg scalar) const
{
	return *this * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Vector4 Vector4::operator *(float scalar) const
{
	return Vector4(
		( mX * scalar ),
		( mY * scalar ),
		( mZ * scalar ),
		( mW * scalar )
		);
}

SCE_VECTORMATH_INLINE Vector4& Vector4::operator +=(Vector4_arg vec)
{
	return *this = *this + vec;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::operator -=(Vector4_arg vec)
{
	return *this = *this - vec;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::operator *=(float scalar)
{
	return *this = *this * scalar;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::operator /=(float scalar)
{
	return *this = *this / scalar;
}

SCE_VECTORMATH_INLINE Vector4& Vector4::operator *=(floatInVec_arg scalar)
{
	return *this = *this * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE Vector4& Vector4::operator /=(floatInVec_arg scalar)
{
	return *this = *this / scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Vector4 Vector4::operator -() const
{
	return Vector4(
		-mX,
		-mY,
		-mZ,
		-mW
		);
}

SCE_VECTORMATH_INLINE const Vector4 Vector4::xAxis()
{
	return Vector4( 1.0f, 0.0f, 0.0f, 0.0f );
}

SCE_VECTORMATH_INLINE const Vector4 Vector4::yAxis()
{
	return Vector4( 0.0f, 1.0f, 0.0f, 0.0f );
}

SCE_VECTORMATH_INLINE const Vector4 Vector4::zAxis()
{
	return Vector4( 0.0f, 0.0f, 1.0f, 0.0f );
}

SCE_VECTORMATH_INLINE const Vector4 Vector4::wAxis()
{
	return Vector4( 0.0f, 0.0f, 0.0f, 1.0f );
}

SCE_VECTORMATH_INLINE const Vector4 Vector4::zero()
{
	return Vector4( 0.0f, 0.0f, 0.0f, 0.0f );
}

SCE_VECTORMATH_INLINE const Vector4 operator *(float scalar, Vector4_arg vec)
{
	return vec * scalar;
}

SCE_VECTORMATH_INLINE const Vector4 operator *(floatInVec_arg scalar, Vector4_arg vec)
{
	return vec * scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE const Vector4 mulPerElem(Vector4_arg vec0, Vector4_arg vec1)
{
	return Vector4(
		( vec0.getX().getAsFloat() * vec1.getX().getAsFloat() ),
		( vec0.getY().getAsFloat() * vec1.getY().getAsFloat() ),
		( vec0.getZ().getAsFloat() * vec1.getZ().getAsFloat() ),
		( vec0.getW().getAsFloat() * vec1.getW().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Vector4 divPerElem(Vector4_arg vec0, Vector4_arg vec1)
{
	return Vector4(
		( vec0.getX().getAsFloat() / vec1.getX().getAsFloat() ),
		( vec0.getY().getAsFloat() / vec1.getY().getAsFloat() ),
		( vec0.getZ().getAsFloat() / vec1.getZ().getAsFloat() ),
		( vec0.getW().getAsFloat() / vec1.getW().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Vector4 recipPerElem(Vector4_arg vec)
{
	return Vector4(
		( 1.0f / vec.getX().getAsFloat() ),
		( 1.0f / vec.getY().getAsFloat() ),
		( 1.0f / vec.getZ().getAsFloat() ),
		( 1.0f / vec.getW().getAsFloat() )
		);
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Vector4 sqrtPerElem(Vector4_arg vec)
{
	return Vector4(
		::sqrtf( vec.getX().getAsFloat() ),
		::sqrtf( vec.getY().getAsFloat() ),
		::sqrtf( vec.getZ().getAsFloat() ),
		::sqrtf( vec.getW().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Vector4 rsqrtPerElem(Vector4_arg vec)
{
	return Vector4(
		( 1.0f / ::sqrtf( vec.getX().getAsFloat() ) ),
		( 1.0f / ::sqrtf( vec.getY().getAsFloat() ) ),
		( 1.0f / ::sqrtf( vec.getZ().getAsFloat() ) ),
		( 1.0f / ::sqrtf( vec.getW().getAsFloat() ) )
		);
}

SCE_VECTORMATH_INLINE const Vector4 absPerElem(Vector4_arg vec)
{
	return Vector4(
		::fabsf( vec.getX().getAsFloat() ),
		::fabsf( vec.getY().getAsFloat() ),
		::fabsf( vec.getZ().getAsFloat() ),
		::fabsf( vec.getW().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Vector4 clampPerElem(Vector4_arg vec, Vector4_arg clampMin, Vector4_arg clampMax)
{
	return minPerElem( maxPerElem( clampMin , vec ), clampMax );
}

SCE_VECTORMATH_INLINE const Vector4 copySignPerElem(Vector4_arg vec0, Vector4_arg vec1)
{
	float x0abs = ::fabsf( vec0.getX().getAsFloat() ); float x1 = vec1.getX().getAsFloat();
	float y0abs = ::fabsf( vec0.getY().getAsFloat() ); float y1 = vec1.getY().getAsFloat();
	float z0abs = ::fabsf( vec0.getZ().getAsFloat() ); float z1 = vec1.getZ().getAsFloat();
	float w0abs = ::fabsf( vec0.getW().getAsFloat() ); float w1 = vec1.getW().getAsFloat();
	return Vector4(
		( x1 < 0.0f ) ? -x0abs : x0abs,
		( y1 < 0.0f ) ? -y0abs : y0abs,
		( z1 < 0.0f ) ? -z0abs : z0abs,
		( w1 < 0.0f ) ? -w0abs : w0abs
		);
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Vector4 maxPerElem(Vector4_arg vec0, Vector4_arg vec1)
{
	float x0 = vec0.getX().getAsFloat(); float x1 = vec1.getX().getAsFloat();
	float y0 = vec0.getY().getAsFloat(); float y1 = vec1.getY().getAsFloat();
	float z0 = vec0.getZ().getAsFloat(); float z1 = vec1.getZ().getAsFloat();
	float w0 = vec0.getW().getAsFloat(); float w1 = vec1.getW().getAsFloat();
	return Vector4(
		( x0 > x1 ) ? x0 : x1,
		( y0 > y1 ) ? y0 : y1,
		( z0 > z1 ) ? z0 : z1,
		( w0 > w1 ) ? w0 : w1
		);
}

SCE_VECTORMATH_INLINE const Vector4 minPerElem(Vector4_arg vec0, Vector4_arg vec1)
{
	float x0 = vec0.getX().getAsFloat(); float x1 = vec1.getX().getAsFloat();
	float y0 = vec0.getY().getAsFloat(); float y1 = vec1.getY().getAsFloat();
	float z0 = vec0.getZ().getAsFloat(); float z1 = vec1.getZ().getAsFloat();
	float w0 = vec0.getW().getAsFloat(); float w1 = vec1.getW().getAsFloat();
	return Vector4(
		( x0 < x1 ) ? x0 : x1,
		( y0 < y1 ) ? y0 : y1,
		( z0 < z1 ) ? z0 : z1,
		( w0 < w1 ) ? w0 : w1
		);
}

SCE_VECTORMATH_INLINE const floatInVec maxElem(Vector4_arg vec)
{
	float resultXY = ( vec.getX().getAsFloat() > vec.getY().getAsFloat() ) ? vec.getX().getAsFloat() : vec.getY().getAsFloat();
	float resultZW = ( vec.getZ().getAsFloat() > vec.getW().getAsFloat() ) ? vec.getZ().getAsFloat() : vec.getW().getAsFloat();
	float result = ( resultXY > resultZW ) ? resultXY : resultZW;
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec minElem(Vector4_arg vec)
{
	float resultXY = ( vec.getX().getAsFloat() < vec.getY().getAsFloat() ) ? vec.getX().getAsFloat() : vec.getY().getAsFloat();
	float resultZW = ( vec.getZ().getAsFloat() < vec.getW().getAsFloat() ) ? vec.getZ().getAsFloat() : vec.getW().getAsFloat();
	float result = ( resultXY < resultZW ) ? resultXY : resultZW;
	return floatInVec( result );

}

SCE_VECTORMATH_INLINE const boolInVec allElemLessThan(Vector4_arg vec0, Vector4_arg vec1)
{
	bool result      = ( vec0.getX().getAsFloat() < vec1.getX().getAsFloat() );
	result = result && ( vec0.getY().getAsFloat() < vec1.getY().getAsFloat() );
	result = result && ( vec0.getZ().getAsFloat() < vec1.getZ().getAsFloat() );
	result = result && ( vec0.getW().getAsFloat() < vec1.getW().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemLessThanOrEqual(Vector4_arg vec0, Vector4_arg vec1)
{
	bool result      = ( vec0.getX().getAsFloat() <= vec1.getX().getAsFloat() );
	result = result && ( vec0.getY().getAsFloat() <= vec1.getY().getAsFloat() );
	result = result && ( vec0.getZ().getAsFloat() <= vec1.getZ().getAsFloat() );
	result = result && ( vec0.getW().getAsFloat() <= vec1.getW().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThan(Vector4_arg vec0, Vector4_arg vec1)
{
	bool result      = ( vec0.getX().getAsFloat() > vec1.getX().getAsFloat() );
	result = result && ( vec0.getY().getAsFloat() > vec1.getY().getAsFloat() );
	result = result && ( vec0.getZ().getAsFloat() > vec1.getZ().getAsFloat() );
	result = result && ( vec0.getW().getAsFloat() > vec1.getW().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThanOrEqual(Vector4_arg vec0, Vector4_arg vec1)
{
	bool result      = ( vec0.getX().getAsFloat() >= vec1.getX().getAsFloat() );
	result = result && ( vec0.getY().getAsFloat() >= vec1.getY().getAsFloat() );
	result = result && ( vec0.getZ().getAsFloat() >= vec1.getZ().getAsFloat() );
	result = result && ( vec0.getW().getAsFloat() >= vec1.getW().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec sum(Vector4_arg vec)
{
	float result;
	result  = ( vec.getX().getAsFloat() + vec.getY().getAsFloat() );
	result += ( vec.getZ().getAsFloat() + vec.getW().getAsFloat() );
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec dot(Vector4_arg vec0, Vector4_arg vec1)
{
	float result;
	result  = ( vec0.getX().getAsFloat() * vec1.getX().getAsFloat() );
	result += ( vec0.getY().getAsFloat() * vec1.getY().getAsFloat() );
	result += ( vec0.getZ().getAsFloat() * vec1.getZ().getAsFloat() );
	result += ( vec0.getW().getAsFloat() * vec1.getW().getAsFloat() );
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec lengthSqr(Vector4_arg vec)
{
	float result;
	result  = ( vec.getX().getAsFloat() * vec.getX().getAsFloat() );
	result += ( vec.getY().getAsFloat() * vec.getY().getAsFloat() );
	result += ( vec.getZ().getAsFloat() * vec.getZ().getAsFloat() );
	result += ( vec.getW().getAsFloat() * vec.getW().getAsFloat() );
	return floatInVec( result );
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const floatInVec length(Vector4_arg vec)
{
	return floatInVec( ::sqrtf( lengthSqr( vec ).getAsFloat() ) );
}

SCE_VECTORMATH_INLINE const Vector4 normalize(Vector4_arg vec)
{
	float lenSqr, lenInv;
	lenSqr = lengthSqr( vec ).getAsFloat();
	lenInv = 1.0f / ::sqrtf( lenSqr );
	return Vector4(
		( vec.getX().getAsFloat() * lenInv ),
		( vec.getY().getAsFloat() * lenInv ),
		( vec.getZ().getAsFloat() * lenInv ),
		( vec.getW().getAsFloat() * lenInv )
		);
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Matrix4 outer(Vector4_arg vec0, Vector4_arg vec1)
{
	return Matrix4(
		vec0 * vec1.getX().getAsFloat(),
		vec0 * vec1.getY().getAsFloat(),
		vec0 * vec1.getZ().getAsFloat(),
		vec0 * vec1.getW().getAsFloat()
		);
}

SCE_VECTORMATH_INLINE const Vector4 lerp(floatInVec_arg t, Vector4_arg vec0, Vector4_arg vec1)
{
	return lerp( t.getAsFloat(), vec0, vec1 );
}

SCE_VECTORMATH_INLINE const Vector4 lerp(float t, Vector4_arg vec0, Vector4_arg vec1)
{
	return ( vec0 + ( ( vec1 - vec0 ) * t ) );
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Vector4 slerp(floatInVec_arg t, Vector4_arg unitVec0, Vector4_arg unitVec1, floatInVec_arg tol)
{
	return slerp( t.getAsFloat(), unitVec0, unitVec1, tol.getAsFloat() );
}

SCE_VECTORMATH_INLINE const Vector4 slerp(float t, Vector4_arg unitVec0, Vector4_arg unitVec1, float tol)
{
	float recipSinAngle, scale0, scale1, cosAngle, angle;
	cosAngle = dot( unitVec0, unitVec1 ).getAsFloat();
	if ( ::fabsf( cosAngle ) < tol ) {
		angle = ::acosf( cosAngle );
		recipSinAngle = ( 1.0f / ::sinf( angle ) );
		scale0 = ( ::sinf( ( ( 1.0f - t ) * angle ) ) * recipSinAngle );
		scale1 = ( ::sinf( ( t * angle ) ) * recipSinAngle );
	} else {
		scale0 = ( 1.0f - t );
		scale1 = t;
	}
	return ( ( unitVec0 * scale0 ) + ( unitVec1 * scale1 ) );
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Vector4 select(Vector4_arg vec0, Vector4_arg vec1, boolInVec_arg select1)
{
	return ( select1.getAsBool() ? vec1 : vec0 );
}

SCE_VECTORMATH_INLINE const Vector4 select(Vector4_arg vec0, Vector4_arg vec1, bool select1)
{
	return ( select1 ? vec1 : vec0 );
}

SCE_VECTORMATH_INLINE void loadXYZW(Vector4& vec, const float* fptr)
{
	vec = Vector4( fptr[0], fptr[1], fptr[2], fptr[3] );
}

SCE_VECTORMATH_INLINE void storeXYZW(Vector4_arg vec, float* fptr)
{
	fptr[0] = vec.getX().getAsFloat();
	fptr[1] = vec.getY().getAsFloat();
	fptr[2] = vec.getZ().getAsFloat();
	fptr[3] = vec.getW().getAsFloat();
}

SCE_VECTORMATH_INLINE void loadHalfFloats(Vector4& vec0, Vector4& vec1, Vector4& vec2, Vector4& vec3, const uint16_t* hfptr)
{
	loadHalfFloats( vec0, hfptr+0  );
	loadHalfFloats( vec1, hfptr+4  );
	loadHalfFloats( vec2, hfptr+8  );
	loadHalfFloats( vec3, hfptr+12 );
}

SCE_VECTORMATH_INLINE void loadHalfFloats(Vector4& vec, const uint16_t* hfptr)
{
	union Data32 {
		uint32_t u32;
		float f32;
	};

	for (int i = 0; i < 4; i++) {
		uint32_t fp16 = static_cast<uint32_t>(hfptr[i]);
		uint32_t sign = (fp16 >> 15);
		uint32_t exponent = (fp16 >> 10) & ((1 << 5) - 1);
		uint32_t mantissa = fp16 & ((1 << 10) - 1);

		if (exponent == 0) {
			// zero
			mantissa = 0;
		} else if (exponent == 31 && mantissa != 0) {
			// nan
			exponent = 255;
			mantissa = (1 << 22);
			sign = 0;
		} else if (exponent == 31 && mantissa == 0) {
			// infinity
			exponent = 255;
			mantissa = 0;
		} else {
			exponent += 127 - 15;
			mantissa <<= 13;
		}

		Data32 d;
		d.u32 = (sign << 31) | (exponent << 23) | mantissa;
		vec[i] = d.f32;
	}
}

SCE_VECTORMATH_INLINE void storeHalfFloats(Vector4_arg vec0, Vector4_arg vec1, Vector4_arg vec2, Vector4_arg vec3, uint16_t* hfptr)
{
	storeHalfFloats( vec0, hfptr+0  );
	storeHalfFloats( vec1, hfptr+4  );
	storeHalfFloats( vec2, hfptr+8  );
	storeHalfFloats( vec3, hfptr+12 );
}

SCE_VECTORMATH_INLINE void storeHalfFloats(Vector4_arg vec, uint16_t* hfptr)
{
	union Data32 {
		uint32_t u32;
		float f32;
	};

	for (int i = 0; i < 4; i++) {
		Data32 d;
		d.f32 = vec[i].getAsFloat();

		uint32_t sign = d.u32 >> 31;
		uint32_t exponent = (d.u32 >> 23) & ((1 << 8) - 1);
		uint32_t mantissa = d.u32 & ((1 << 23) - 1);

		if (exponent == 0) {
			// zero or denorm -> zero
			mantissa = 0;
		} else if (exponent == 255 && mantissa != 0) {
			// nan
			exponent = 31;
			mantissa = (1 << 9);
			sign = 0;
		} else if (exponent >= 127 - 15 + 31) {
			// overflow or infinity -> infinity
			exponent = 31;
			mantissa = 0;
		} else if (exponent <= 127 - 15) {
			// underflow -> zero
			exponent = 0;
			mantissa = 0;
		} else {
			exponent -= 127 - 15;
			mantissa >>= 13;
		}

		hfptr[i] = static_cast<uint16_t>((sign << 15) | (exponent << 10) | mantissa);
	}
}

#ifdef SCE_VECTORMATH_DEBUG

SCE_VECTORMATH_INLINE void print(Vector4_arg vec)
{
	sce_vectormath_printf( "( %f %f %f %f )\n", vec.getX().getAsFloat(), vec.getY().getAsFloat(), vec.getZ().getAsFloat(), vec.getW().getAsFloat() );
}

SCE_VECTORMATH_INLINE void print(Vector4_arg vec, const char* name)
{
	sce_vectormath_printf( "%s: ( %f %f %f %f )\n", name, vec.getX().getAsFloat(), vec.getY().getAsFloat(), vec.getZ().getAsFloat(), vec.getW().getAsFloat() );
}

#endif

SCE_VECTORMATH_ALWAYS_INLINE Point3::Point3()
{
}

SCE_VECTORMATH_INLINE Point3::Point3(float x, float y, float z)
{
	mX = x;
	mY = y;
	mZ = z;
}

SCE_VECTORMATH_INLINE Point3::Point3(floatInVec_arg x, floatInVec_arg y, floatInVec_arg z)
{
	mX = x.getAsFloat();
	mY = y.getAsFloat();
	mZ = z.getAsFloat();
}

SCE_VECTORMATH_INLINE Point3::Point3(Vector2_arg xy, float z)
{
	mX = xy.getX().getAsFloat();
	mY = xy.getY().getAsFloat();
	mZ = z;
}

SCE_VECTORMATH_INLINE Point3::Point3(Vector2_arg xy, floatInVec_arg z)
{
	mX = xy.getX().getAsFloat();
	mY = xy.getY().getAsFloat();
	mZ = z.getAsFloat();
}

SCE_VECTORMATH_INLINE Point3::Point3(Vector3_arg vec)
{
	mX = vec.getX().getAsFloat();
	mY = vec.getY().getAsFloat();
	mZ = vec.getZ().getAsFloat();
}

SCE_VECTORMATH_INLINE Point3::Point3(float scalar)
{
	mX = scalar;
	mY = scalar;
	mZ = scalar;
}

SCE_VECTORMATH_INLINE Point3::Point3(floatInVec_arg scalar)
{
	mX = scalar.getAsFloat();
	mY = scalar.getAsFloat();
	mZ = scalar.getAsFloat();
}

SCE_VECTORMATH_INLINE Point3& Point3::operator =(Point3_arg pnt)
{
	mX = pnt.mX;
	mY = pnt.mY;
	mZ = pnt.mZ;
	return *this;
}

SCE_VECTORMATH_INLINE Point3& Point3::setXY(Vector2_arg vec)
{
	mX = vec.getX().getAsFloat();
	mY = vec.getY().getAsFloat();
	return *this;
}

SCE_VECTORMATH_ALWAYS_INLINE const Vector2 Point3::getXY() const
{
	return Vector2( mX, mY );
}

SCE_VECTORMATH_INLINE Point3& Point3::setX(float x)
{
	mX = x;
	return *this;
}

SCE_VECTORMATH_INLINE Point3& Point3::setY(float y)
{
	mY = y;
	return *this;
}

SCE_VECTORMATH_INLINE Point3& Point3::setZ(float z)
{
	mZ = z;
	return *this;
}

SCE_VECTORMATH_INLINE Point3& Point3::setX(floatInVec_arg x)
{
	mX = x.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Point3& Point3::setY(floatInVec_arg y)
{
	mY = y.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE Point3& Point3::setZ(floatInVec_arg z)
{
	mZ = z.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Point3::getX() const
{
	return floatInVec(mX);
}

SCE_VECTORMATH_INLINE const floatInVec Point3::getY() const
{
	return floatInVec(mY);
}

SCE_VECTORMATH_INLINE const floatInVec Point3::getZ() const
{
	return floatInVec(mZ);
}

SCE_VECTORMATH_INLINE Point3& Point3::setElem(int idx, float value)
{
	*(&mX + idx) = value;
	return *this;
}

SCE_VECTORMATH_INLINE Point3& Point3::setElem(int idx, floatInVec_arg value)
{
	*(&mX + idx) = value.getAsFloat();
	return *this;
}

SCE_VECTORMATH_INLINE const floatInVec Point3::getElem(int idx) const
{
	return floatInVec(*(&mX + idx));
}

SCE_VECTORMATH_INLINE float& Point3::operator [](int idx)
{
	return *(&mX + idx);
}

SCE_VECTORMATH_INLINE const floatInVec Point3::operator [](int idx) const
{
	return floatInVec( *(&mX + idx) );
}

SCE_VECTORMATH_INLINE const Vector3 Point3::operator -(Point3_arg pnt) const
{
	return Vector3(
		( mX - pnt.mX ),
		( mY - pnt.mY ),
		( mZ - pnt.mZ )
		);
}

SCE_VECTORMATH_INLINE const Point3 Point3::operator +(Vector3_arg vec) const
{
	return Point3(
		( mX + vec.getX().getAsFloat() ),
		( mY + vec.getY().getAsFloat() ),
		( mZ + vec.getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Point3 Point3::operator -(Vector3_arg vec) const
{
	return Point3(
		( mX - vec.getX().getAsFloat() ),
		( mY - vec.getY().getAsFloat() ),
		( mZ - vec.getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE Point3& Point3::operator +=(Vector3_arg vec)
{
	*this = *this + vec;
	return *this;
}

SCE_VECTORMATH_INLINE Point3& Point3::operator -=(Vector3_arg vec)
{
	*this = *this - vec;
	return *this;
}

SCE_VECTORMATH_INLINE const Point3 Point3::origin()
{
	return Point3( 0.0f, 0.0f, 0.0f );
}

SCE_VECTORMATH_INLINE const Point3 mulPerElem(Point3_arg pnt0, Point3_arg pnt1)
{
	return Point3(
		( pnt0.getX().getAsFloat() * pnt1.getX().getAsFloat() ),
		( pnt0.getY().getAsFloat() * pnt1.getY().getAsFloat() ),
		( pnt0.getZ().getAsFloat() * pnt1.getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Point3 divPerElem(Point3_arg pnt0, Point3_arg pnt1)
{
	return Point3(
		( pnt0.getX().getAsFloat() / pnt1.getX().getAsFloat() ),
		( pnt0.getY().getAsFloat() / pnt1.getY().getAsFloat() ),
		( pnt0.getZ().getAsFloat() / pnt1.getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Point3 recipPerElem(Point3_arg pnt)
{
	return Point3(
		( 1.0f / pnt.getX().getAsFloat() ),
		( 1.0f / pnt.getY().getAsFloat() ),
		( 1.0f / pnt.getZ().getAsFloat() )
		);
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const Point3 sqrtPerElem(Point3_arg pnt)
{
	return Point3(
		::sqrtf( pnt.getX().getAsFloat() ),
		::sqrtf( pnt.getY().getAsFloat() ),
		::sqrtf( pnt.getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Point3 rsqrtPerElem(Point3_arg pnt)
{
	return Point3(
		( 1.0f / ::sqrtf( pnt.getX().getAsFloat() ) ),
		( 1.0f / ::sqrtf( pnt.getY().getAsFloat() ) ),
		( 1.0f / ::sqrtf( pnt.getZ().getAsFloat() ) )
		);
}

SCE_VECTORMATH_INLINE const Point3 absPerElem(Point3_arg pnt)
{
	return Point3(
		::fabsf( pnt.getX().getAsFloat() ),
		::fabsf( pnt.getY().getAsFloat() ),
		::fabsf( pnt.getZ().getAsFloat() )
		);
}

SCE_VECTORMATH_INLINE const Point3 clampPerElem(Point3_arg pnt, Point3_arg clampMin, Point3_arg clampMax)
{
	return minPerElem( maxPerElem( clampMin , pnt ), clampMax );
}

SCE_VECTORMATH_INLINE const Point3 copySignPerElem(Point3_arg pnt0, Point3_arg pnt1)
{
	float x0abs = ::fabsf( pnt0.getX().getAsFloat() ); float x1 = pnt1.getX().getAsFloat();
	float y0abs = ::fabsf( pnt0.getY().getAsFloat() ); float y1 = pnt1.getY().getAsFloat();
	float z0abs = ::fabsf( pnt0.getZ().getAsFloat() ); float z1 = pnt1.getZ().getAsFloat();
	return Point3(
		( x1 < 0.0f ) ? -x0abs : x0abs,
		( y1 < 0.0f ) ? -y0abs : y0abs,
		( z1 < 0.0f ) ? -z0abs : z0abs
		);
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Point3 maxPerElem(Point3_arg pnt0, Point3_arg pnt1)
{
	float x0 = pnt0.getX().getAsFloat(); float x1 = pnt1.getX().getAsFloat();
	float y0 = pnt0.getY().getAsFloat(); float y1 = pnt1.getY().getAsFloat();
	float z0 = pnt0.getZ().getAsFloat(); float z1 = pnt1.getZ().getAsFloat();
	return Point3(
		( x0 > x1 ) ? x0 : x1,
		( y0 > y1 ) ? y0 : y1,
		( z0 > z1 ) ? z0 : z1
		);
}

SCE_VECTORMATH_INLINE const Point3 minPerElem(Point3_arg pnt0, Point3_arg pnt1)
{
	float x0 = pnt0.getX().getAsFloat(); float x1 = pnt1.getX().getAsFloat();
	float y0 = pnt0.getY().getAsFloat(); float y1 = pnt1.getY().getAsFloat();
	float z0 = pnt0.getZ().getAsFloat(); float z1 = pnt1.getZ().getAsFloat();
	return Point3(
		( x0 < x1 ) ? x0 : x1,
		( y0 < y1 ) ? y0 : y1,
		( z0 < z1 ) ? z0 : z1
		);
}

SCE_VECTORMATH_INLINE const floatInVec maxElem(Point3_arg pnt)
{
	float x0 = pnt.getX().getAsFloat();
	float y0 = pnt.getY().getAsFloat();
	float z0 = pnt.getZ().getAsFloat();
	float result;
	result = ( x0 > y0 ) ? x0 : y0;
	result = ( z0 > result ) ? z0 : result;
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec minElem(Point3_arg pnt)
{
	float x0 = pnt.getX().getAsFloat();
	float y0 = pnt.getY().getAsFloat();
	float z0 = pnt.getZ().getAsFloat();
	float result;
	result = ( x0 < y0 ) ? x0 : y0;
	result = ( z0 < result ) ? z0 : result;
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemLessThan(Point3_arg pnt0, Point3_arg pnt1)
{
	bool result      = ( pnt0.getX().getAsFloat() < pnt1.getX().getAsFloat() );
	result = result && ( pnt0.getY().getAsFloat() < pnt1.getY().getAsFloat() );
	result = result && ( pnt0.getZ().getAsFloat() < pnt1.getZ().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemLessThanOrEqual(Point3_arg pnt0, Point3_arg pnt1)
{
	bool result      = ( pnt0.getX().getAsFloat() <= pnt1.getX().getAsFloat() );
	result = result && ( pnt0.getY().getAsFloat() <= pnt1.getY().getAsFloat() );
	result = result && ( pnt0.getZ().getAsFloat() <= pnt1.getZ().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThan(Point3_arg pnt0, Point3_arg pnt1)
{
	bool result      = ( pnt0.getX().getAsFloat() > pnt1.getX().getAsFloat() );
	result = result && ( pnt0.getY().getAsFloat() > pnt1.getY().getAsFloat() );
	result = result && ( pnt0.getZ().getAsFloat() > pnt1.getZ().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const boolInVec allElemGreaterThanOrEqual(Point3_arg pnt0, Point3_arg pnt1)
{
	bool result      = ( pnt0.getX().getAsFloat() >= pnt1.getX().getAsFloat() );
	result = result && ( pnt0.getY().getAsFloat() >= pnt1.getY().getAsFloat() );
	result = result && ( pnt0.getZ().getAsFloat() >= pnt1.getZ().getAsFloat() );
	return boolInVec( result );
}

SCE_VECTORMATH_INLINE const floatInVec sum(Point3_arg pnt)
{
	float result;
	result  = pnt.getX().getAsFloat();
	result += pnt.getY().getAsFloat();
	result += pnt.getZ().getAsFloat();
	return floatInVec( result );
}

SCE_VECTORMATH_INLINE const Point3 scale(Point3_arg pnt, float scaleVal)
{
	return mulPerElem(pnt, Point3(scaleVal));
}

SCE_VECTORMATH_INLINE const Point3 scale(Point3_arg pnt, floatInVec_arg scaleVal)
{
	return mulPerElem(pnt, Point3(scaleVal));
}

SCE_VECTORMATH_INLINE const Point3 scale(Point3_arg pnt, Vector3_arg scaleVec)
{
	return mulPerElem(pnt, Point3(scaleVec));
}

SCE_VECTORMATH_INLINE const floatInVec projection(Point3_arg pnt, Vector3_arg unitVec)
{
	return dot(Vector3(pnt), unitVec);
}

SCE_VECTORMATH_INLINE const floatInVec distSqrFromOrigin(Point3_arg pnt)
{
	return lengthSqr(Vector3(pnt));
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const floatInVec distFromOrigin(Point3_arg pnt)
{
	return length(Vector3(pnt));
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const floatInVec distSqr(Point3_arg pnt0, Point3_arg pnt1)
{
	return lengthSqr(pnt1 - pnt0);
}

#if !defined(SCE_VECTORMATH_NO_MATH_DEFS)

SCE_VECTORMATH_INLINE const floatInVec dist(Point3_arg pnt0, Point3_arg pnt1)
{
	return length(pnt1 - pnt0);
}

#endif	/* !defined(SCE_VECTORMATH_NO_MATH_DEFS) */

SCE_VECTORMATH_INLINE const Point3 lerp(floatInVec_arg t, Point3_arg pnt0, Point3_arg pnt1)
{
	return lerp( t.getAsFloat(), pnt0, pnt1 );
}

SCE_VECTORMATH_INLINE const Point3 lerp(float t, Point3_arg pnt0, Point3_arg pnt1)
{
	return ( pnt0 + ( ( pnt1 - pnt0 ) * t ) );
}

SCE_VECTORMATH_INLINE const Point3 select(Point3_arg pnt0, Point3_arg pnt1, boolInVec_arg select1)
{
	return ( select1.getAsBool() ? pnt1 : pnt0 );
}

SCE_VECTORMATH_INLINE const Point3 select(Point3_arg pnt0, Point3_arg pnt1, bool select1)
{
	return ( select1 ? pnt1 : pnt0 );
}

SCE_VECTORMATH_INLINE void loadXYZ(Point3& pnt, const float* fptr)
{
	pnt = Point3( fptr[0], fptr[1], fptr[2] );
}

SCE_VECTORMATH_INLINE void storeXYZ(Point3_arg pnt, float* fptr)
{
	fptr[0] = pnt.getX().getAsFloat();
	fptr[1] = pnt.getY().getAsFloat();
	fptr[2] = pnt.getZ().getAsFloat();
}

SCE_VECTORMATH_INLINE void loadXYZArray(Point3& pnt0, Point3& pnt1, Point3& pnt2, Point3& pnt3, const float* fptr)
{
	loadXYZ( pnt0, fptr+0 );
	loadXYZ( pnt1, fptr+3 );
	loadXYZ( pnt2, fptr+6 );
	loadXYZ( pnt3, fptr+9 );
}

SCE_VECTORMATH_INLINE void storeXYZArray(Point3_arg pnt0, Point3_arg pnt1, Point3_arg pnt2, Point3_arg pnt3, float* fptr)
{
	storeXYZ( pnt0, fptr+0 );
	storeXYZ( pnt1, fptr+3 );
	storeXYZ( pnt2, fptr+6 );
	storeXYZ( pnt3, fptr+9 );
}

SCE_VECTORMATH_INLINE void loadHalfFloats(Point3& pnt0, Point3& pnt1, Point3& pnt2, Point3& pnt3, Point3& pnt4, Point3& pnt5, Point3& pnt6, Point3& pnt7, const uint16_t* hfptr)
{
	loadHalfFloats( pnt0, hfptr+0 );
	loadHalfFloats( pnt1, hfptr+3 );
	loadHalfFloats( pnt2, hfptr+6 );
	loadHalfFloats( pnt3, hfptr+9 );
	loadHalfFloats( pnt4, hfptr+12 );
	loadHalfFloats( pnt5, hfptr+15 );
	loadHalfFloats( pnt6, hfptr+18 );
	loadHalfFloats( pnt7, hfptr+21 );
}

SCE_VECTORMATH_INLINE void loadHalfFloats(Point3& vec, const uint16_t* hfptr)
{
	union Data32 {
		uint32_t u32;
		float f32;
	};

	for (int i = 0; i < 3; i++) {
		uint32_t fp16 = static_cast<uint32_t>(hfptr[i]);
		uint32_t sign = (fp16 >> 15);
		uint32_t exponent = (fp16 >> 10) & ((1 << 5) - 1);
		uint32_t mantissa = fp16 & ((1 << 10) - 1);

		if (exponent == 0) {
			// zero
			mantissa = 0;
		} else if (exponent == 31 && mantissa != 0) {
			// nan
			exponent = 255;
			mantissa = (1 << 22);
			sign = 0;
		} else if (exponent == 31 && mantissa == 0) {
			// infinity
			exponent = 255;
			mantissa = 0;
		} else {
			exponent += 127 - 15;
			mantissa <<= 13;
		}

		Data32 d;
		d.u32 = (sign << 31) | (exponent << 23) | mantissa;
		vec[i] = d.f32;
	}
}

SCE_VECTORMATH_INLINE void storeHalfFloats(Point3_arg pnt0, Point3_arg pnt1, Point3_arg pnt2, Point3_arg pnt3, Point3_arg pnt4, Point3_arg pnt5, Point3_arg pnt6, Point3_arg pnt7, uint16_t* hfptr)
{
	storeHalfFloats( pnt0, hfptr+0 );
	storeHalfFloats( pnt1, hfptr+3 );
	storeHalfFloats( pnt2, hfptr+6 );
	storeHalfFloats( pnt3, hfptr+9 );
	storeHalfFloats( pnt4, hfptr+12 );
	storeHalfFloats( pnt5, hfptr+15 );
	storeHalfFloats( pnt6, hfptr+18 );
	storeHalfFloats( pnt7, hfptr+21 );
}

SCE_VECTORMATH_INLINE void storeHalfFloats(Point3_arg vec, uint16_t* hfptr)
{
	union Data32 {
		uint32_t u32;
		float f32;
	};

	for (int i = 0; i < 3; i++) {
		Data32 d;
		d.f32 = vec[i].getAsFloat();

		uint32_t sign = d.u32 >> 31;
		uint32_t exponent = (d.u32 >> 23) & ((1 << 8) - 1);
		uint32_t mantissa = d.u32 & ((1 << 23) - 1);

		if (exponent == 0) {
			// zero or denorm -> zero
			mantissa = 0;
		} else if (exponent == 255 && mantissa != 0) {
			// nan
			exponent = 31;
			mantissa = (1 << 9);
			sign = 0;
		} else if (exponent >= 127 - 15 + 31) {
			// overflow or infinity -> infinity
			exponent = 31;
			mantissa = 0;
		} else if (exponent <= 127 - 15) {
			// underflow -> zero
			exponent = 0;
			mantissa = 0;
		} else {
			exponent -= 127 - 15;
			mantissa >>= 13;
		}

		hfptr[i] = static_cast<uint16_t>((sign << 15) | (exponent << 10) | mantissa);
	}
}

#ifdef SCE_VECTORMATH_DEBUG

SCE_VECTORMATH_INLINE void print(Point3_arg pnt)
{
	sce_vectormath_printf( "( %f %f %f )\n", pnt.getX().getAsFloat(), pnt.getY().getAsFloat(), pnt.getZ().getAsFloat() );
}

SCE_VECTORMATH_INLINE void print(Point3_arg pnt, const char* name)
{
	sce_vectormath_printf( "%s: ( %f %f %f )\n", name, pnt.getX().getAsFloat(), pnt.getY().getAsFloat(), pnt.getZ().getAsFloat() );
}

#endif

} // namespace Aos
} // namespace Scalar
} // namespace Vectormath
} // namespace sce

#endif /* _PSP2_VECTORMATH_SCALAR_VEC_AOS_CPP_H_ */
