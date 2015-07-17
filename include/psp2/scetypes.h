/**
 * \file scetypes.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_SCETYPES_SCETYPES_H_
#define _PSP2_SCETYPES_SCETYPES_H_

/* SCE prefix types */
/**
 * @brief 8bit signed char 
 */
typedef signed char		SceChar8;

/**
 * @brief 8bit unsigned char
 */
typedef unsigned char	SceUChar8;

/**
 * @brief 8bit integer 
 */
typedef signed char			SceInt8;

/**
 * @brief 8bit unsigned integer 
 */
typedef unsigned char	SceUInt8;

/**
 * @brief 16bit signed short 
 */
typedef signed short	SceShort16;

/**
 * @brief 16bit unsigned short 
 */
typedef unsigned short	SceUShort16;

/**
 * @brief 16bit unsigned integer 
 */
typedef short			SceInt16;

/**
 * @brief 16bit unsigned integer 
 */
typedef unsigned short	SceUInt16;

/**
 * @brief 32bit signed integer 
 */
typedef signed int		SceInt32;

/**
 * @brief 32bit unsigned integer 
 */
typedef unsigned int	SceUInt32;

/**
 * SCE integer 
 */
typedef int		SceInt;

/**
 * SCE unsigned int 
 */
typedef unsigned int	SceUInt;

#if defined(__GNUC__) || defined(__SNC__) || defined(__MWERKS__)
typedef signed int		SceInt64    __attribute__((mode(DI)));
typedef unsigned int	SceUInt64   __attribute__((mode(DI)));
typedef long			SceLong;
typedef unsigned long	SceULong;
typedef signed int		SceLong64   __attribute__((mode(DI)));
typedef unsigned int	SceULong64  __attribute__((mode(DI)));

#else	/* defined(__GNUC__) || defined(__SNC__) || defined(__MWERKS__)  */

#if defined(_MSC_VER)
typedef __int64			 SceInt64;
typedef unsigned __int64 SceUInt64;
typedef __int64			 SceLong64;
typedef unsigned __int64 SceULong64;
#else	/* defined(_MSC_VER) */
typedef long long          SceInt64;
typedef unsigned long long SceUInt64;
typedef long long          SceLong64;
typedef unsigned long long SceULong64;
#endif	/* defined(_MSC_VER) */
#endif	/* defined(__GNUC__) || defined(__SNC__) || defined(__MWERKS__) */



/**
 * SCE prefixed float type 
 */
typedef float			SceFloat;

/**
 * @brief 32bit float type 
 */
typedef float			SceFloat32;

/**
 * SCE prefixed double type 
 */
typedef double			SceDouble;

/**
 * @brief 64bit double type 
 */
typedef double			SceDouble64;

/**
 * @brief signed byte 
 */
typedef signed char		SceSByte;

/**
 * @brief signed 8b byte type 
 */
typedef signed char		SceSByte8;

/**
 * @brief unsigned byte type 
 */
typedef unsigned char	SceByte;

/**
 * @brief unsigned 8 bit byte type 
 */
typedef unsigned char	SceByte8;

/**
 * @brief 16 bit unsigned wide character 
 */
typedef unsigned short	SceWChar16;

/**
 * @brief 32 bit unsigned wide character 
 */
typedef unsigned int	SceWChar32;

/**
 * @def SCE_NULL
 */
#if defined(__cplusplus)
#define SCE_NULL		(0)
#else	/* defined(__cplusplus) */
#define SCE_NULL		((void *)0)
#endif	/* defined(__cplusplus) */

/**
 * @brief boolean type 
 */
typedef int				SceBool;

#define SCE_FALSE		(0)		//!< boolean false 
#define SCE_TRUE		(1)		//!< boolean true 

/**
 * @brief integer type for pointer 
 */
typedef int				SceIntPtr;

/**
 * @brief unsigned integer type for pointer 
 */
typedef unsigned int	SceUIntPtr;

/**
 * @brief void type 
 */
typedef void			SceVoid;

/**
 * @brief pointer to void type 
 */
typedef void*			ScePVoid;


/**
 * @brief 32 bits integer 2D vector type 
 */
typedef struct SceIVector2 {
	int x, y;
} SceIVector2;

/**
 * @brief 32 bits integer 2D vector type 
 */
typedef struct SceFVector2 {
	float x, y;
} SceFVector2;

/**
 * @brief 32 bits 2D vector conversion type 
 */
typedef union SceUVector2 {
	SceIVector2 iv;
	SceFVector2 fv;
#if defined(__ARM_NEON__)
#if defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H))
	int32x2_t      i32x2;
	float32x2_t    f32x2;
	uint32x2_t     ui32x2;
#endif	/* defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H)) */
#endif	/* defined(__ARM_NEON__) */
} SceUVector2;

/**
 * @brief 32 bits integer 3D vector type 
 */
typedef struct SceIVector3 {
	int x, y, z;
} SceIVector3;

/**
 * @brief 32 bits integer 2D vector type 
 */
typedef struct SceFVector3 {
	float x, y, z;
} SceFVector3;

/**
 * @brief 32 bits 3D vector conversion type 
 */
typedef union SceUVector3 {
	SceIVector3 iv;
	SceFVector3 fv;
} SceUVector3;

/**
 * @brief 32 bits integer 4D vector type 
 */
typedef struct SceIVector4 {
	int x, y, z, w;
} SceIVector4;

/**
 * @brief 32 bits integer 2D vector type 
 */
typedef struct SceFVector4 {
	float x, y, z, w;
} SceFVector4;

/**
 * @brief 32 bits 4D vector conversion type 
 */
typedef union SceUVector4 {
	SceIVector4 iv;
	SceFVector4 fv;
#if defined(__ARM_NEON__)
#if defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H))
	int32x4_t      i32x4;
	float32x4_t    f32x4;
	uint32x4_t     ui32x4;
#endif	/* defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H)) */
#endif	/* defined(__ARM_NEON__) */
} SceUVector4;

/**
 * @brief 32 bits integer 2D matrix type 
 */
typedef struct SceIMatrix2{
	SceIVector2 x, y;
} SceIMatrix2;

/**
 * @brief 32 bits float 2D matrix type 
 */
typedef struct SceFMatrix2{
	SceFVector2 x, y;
} SceFMatrix2;

typedef union SceUMatrix2 {
	SceFMatrix2 fm;
	SceIMatrix2 im;
	SceFVector2 fv[2];
	SceIVector2 iv[2];
	SceUVector2 uv[2];
	float f[2][2];
	int   i[2][2];
#if defined(__ARM_NEON__)
#if defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H))
	int32x2x2_t   i32x2x2;
	float32x2x2_t f32x2x2;
	uint32x2x2_t  ui32x2x2;
#endif	/* defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H)) */
#endif	/* defined(__ARM_NEON__) */
#if defined(SCE_TYPES_USE_UNNAMED_UNION)
	struct {
		float f00, f10;
		float f01, f11;
	};
	struct {
		int i00, i10;
		int i01, i11;
	};
#endif	/* defined(SCE_TYPES_USE_UNNAMED_UNION) */
} SceUMatrix2;


/**
 * @brief 32 bits integer 3D matrix type 
 */
typedef struct SceIMatrix3 {
	SceIVector3 x, y, z;
} SceIMatrix3;

/**
 * @brief 32 bits float 3D matrix type 
 */
typedef struct SceFMatrix3 {
	SceFVector3 x, y, z;
} SceFMatrix3;

/**
 * @brief 32 bits 2D matrxi conversion type 
 */
typedef union SceUMatrix3 {
	SceFMatrix3 fm;
	SceIMatrix3 im;
	SceFVector3 fv[3];
	SceIVector3 iv[3];
	SceUVector3 uv[3];
	float f[3][3];
	int   i[3][3];
#if defined(SCE_TYPES_USE_UNNAMED_UNION)
	struct {
		float f00, f10, f20;
		float f01, f11, f21;
		float f02, f12, f22;
	};
	struct {
		int i00, i10, i20;
		int i01, i11, i21;
		int i02, i12, i22;
	};
#endif	/* defined(SCE_TYPES_USE_UNNAMED_UNION) */
} SceUMatrix3;

/**
 * @brief 32 bits integer 4D matrix type 
 */
typedef struct SceIMatrix4 {
	SceIVector4 x, y, z, w;
} SceIMatrix4;

/**
 * @brief 32 bits float 4D matrix type 
 */
typedef struct SceFMatrix4 {
	SceFVector4 x, y, z, w;
} SceFMatrix4;

/**
 * @brief 32 bits 2D matrxi conversion type 
 */
typedef union SceUMatrix4 {
	SceFMatrix4 fm;
	SceIMatrix4 im;
	SceFVector4 fv[4];
	SceIVector4 iv[4];
	SceUVector4 uv[4];
	float f[4][4];
	int   i[4][4];
#if defined(__ARM_NEON__)
#if defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H))
	int32x4x4_t   i32x4x4;
	float32x4x4_t f32x4x4;
	uint32x4x4_t  ui32x4x4;
#endif	/* defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H)) */
#endif	/* defined(__ARM_NEON__) */
#if defined(SCE_TYPES_USE_UNNAMED_UNION)
	struct {
		float f00, f10, f20, f30;
		float f01, f11, f21, f31;
		float f02, f12, f22, f32;
		float f03, f13, f23, f33;
	};
	struct {
		int i00, i10, i20, i30;
		int i01, i11, i21, i31;
		int i02, i12, i22, i32;
		int i03, i13, i23, i33;
	};
#endif	/* defined(SCE_TYPES_USE_UNNAMED_UNION) */
} SceUMatrix4;


/**
 * @brief 32 bits float quaternion type 
 */
typedef struct SceFQuaternion {
	float x, y, z, w;
} SceFQuaternion;

/**
 * @brief 32 bits float color type 
 */
typedef struct SceFColor {
	float r, g, b, a;
} SceFColor;

/**
 * @brief 32 bits float plane type 
 */
typedef struct SceFPlane {
	float a, b, c, d;
} SceFPlane;


/**
 * @brief 32 bits type conversion 
 */
typedef union SceUnion32 {
	unsigned int   ui;
	int            i;
	unsigned short us[2];
	short          s[2];
	unsigned char  uc[4];
	char           c[4];
	float          f;
	void           *p;
} SceUnion32;


/**
 * @brief 64 bits type conversion 
 */
typedef union SceUnion64 {
	SceULong64     ull;
	SceLong64      ll;
	unsigned int   ui[2];
	int            i[2];
	unsigned short us[4];
	short          s[4];
	unsigned char  uc[8];
	char           c[8];
	float          f[2];

	SceFVector2    fv;
	SceIVector2    iv;

#if defined(__ARM_NEON__)
#if defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H))
	int8x8_t       i8x8;
	int16x4_t      i16x4;
	int32x2_t      i32x2;
	int64x1_t      i64x1;
	float32x2_t    f32x2;
	poly8x8_t      p8x8;
	poly16x4_t     p16x4;
	uint8x8_t      ui8x8;
	uint16x4_t     ui16x4;
	uint32x2_t     ui32x2;
	uint64x1_t     ui64x1;
#endif	/* defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H)) */
#endif	/* defined(__ARM_NEON__) */
} SceUnion64;


/**
 * @brief 128 bits type conversion 
 */
typedef union SceUnion128 {

	SceULong64      ull[2];
	SceLong64       ll[2];
	unsigned int    ui[4];
	int             i[4];
	unsigned short  us[8];
	short           s[8];
	unsigned char   uc[16];
	char            c[16];
	float           f[4];

	SceFVector4     fv;
	SceFQuaternion  fq;
	SceFPlane       fp;
	SceFColor       fc;
	SceIVector4     iv;

#if defined(__ARM_NEON__)
#if defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H))
	int8x16_t       i8x16;
	int16x8_t       i16x8;
	int32x4_t       i32x4;
	int64x2_t       i64x2;
	float32x4_t     f32x4;
	poly8x16_t      p8x16;
	poly16x8_t      p16x8;
	uint8x16_t      ui8x16;
	uint16x8_t      ui16x8;
	uint32x4_t      ui32x4;
	uint64x2_t      ui64x2;
#endif	/* defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H)) */
#endif	/* defined(__ARM_NEON__) */
} SceUnion128;


/**
 * @brief 512 bits type conversion 
 */
typedef union SceUnion512 {
	SceUnion32      un32[16];
	SceUnion64      un64[8];

	SceULong64      ull[8];
	SceLong64       ll[8];
	unsigned int    ui[16];
	int             i[16];
	unsigned short  us[32];
	short           s[32];
	unsigned char   uc[64];
	char            c[64];
	float           f[16];

	SceFMatrix4     fm;
	SceIMatrix4     im;
	SceUMatrix4     um;

#if defined(__ARM_NEON__)
#if defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H))
	int32x4x4_t     i32x4x4;
	float32x4x4_t   f32x4x4;
#endif	/* defined(__SNC__) || (defined(__GNUC__) && defined(_GCC_ARM_NEON_H)) */
#endif	/* defined(__ARM_NEON__) */
} SceUnion512;


/**
 * @brief representation of time using individual members 
 */
typedef struct SceDateTime {
	unsigned short year;
	unsigned short month;
	unsigned short day;
	unsigned short hour;
	unsigned short minute;
	unsigned short second;
	unsigned int   microsecond;
} SceDateTime;


/**
 * @brief type for unsigned size 
 */
typedef unsigned int	SceSize;

/**
 * @brief physical memory size 
 */
typedef SceSize			ScePSize;

/**
 * @brief virtual memory size 
 */
typedef SceSize			SceVSize;

/**
 * @brief type for signed size 
 */
typedef int				SceSSize;

/**
 * @brief signed size for physical address 
 */
typedef SceSSize		ScePSSize;

/**
 * @brief signed size for virtual size 
 */
typedef SceSSize		SceVSSize;

/* Pointer size unsigned integer */
/**
 * @brief unsigned integer type for virtual address 
 */
typedef unsigned int	SceUIntVAddr;


/*----- SceUID -----*/
/**
 * unified ID type
 */
typedef int		SceUID;

/**
 * Invalid UID value
 */
#if defined(__cplusplus)
#define SCE_UID_INVALID_UID			(static_cast<SceUID>(0xFFFFFFFF))
#else	/* defined(__cplusplus) */
#define SCE_UID_INVALID_UID			((SceUID) 0xFFFFFFFF)
#endif	/* defined(__cplusplus) */

/**
 * Object Name 
 */
typedef char*	SceName;

/**
 * offset type 
 * @note
 * - 64 bits
 */
typedef SceInt64	SceOff;

/**
 * Process ID
 */
typedef SceUID	ScePID;

#endif  /* _PSP2_SCETYPES_SCETYPES_H_ */
