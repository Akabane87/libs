/**
 * \file gxt.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_GXT_H_
#define _PSP2_GXT_H_

/** 
 * @file
 */
//#include <psp2/libdbg.h>
#include <psp2/gxm/structs.h>
#include <psp2/gxm/texture.h>

typedef int SceGxtErrorCode;

/**	
 * A header for a GXT file.
 * This structure should be located right at the start of the GXT file.
*/
typedef struct SceGxtHeader
{
	uint32_t	tag;				//!< The GXT identifier.
	uint32_t	version;			//!< The version number.
	uint32_t	numTextures;		//!< The number of textures.
	uint32_t	dataOffset;			//!< The offset to the texture data.
	uint32_t	dataSize;			//!< The total size of the texture data.
	uint32_t	numP4Palettes;		//!< The number of 16 entry palettes.
	uint32_t	numP8Palettes;		//!< The number of 256 entry palettes.
	uint32_t	pad;				//!< Padding.
} SceGxtHeader;

/**	
 * Contains information about each texture in the GXT file.
 * An array of these structures should immediately follow the initial SceGxtHeader in the GXT file.
 * Please refer to the <em>libgxm Reference</em> for a description of <c>SceGxmTextureType</c> and <c>SceGxmTextureFormat</c>.
 */
typedef struct SceGxtTextureInfo
{
	uint32_t	dataOffset;			//!< The offset to the texture data.
	uint32_t	dataSize;			//!< The size of the texture data.
	uint32_t	paletteIndex;		//!< The index of the palette.
	uint32_t	flags;				//!< Texture flags (#SceGxtTextureFlags).
	uint32_t	type;				//!< The texture type (<c>SceGxmTextureType</c>).
	uint32_t	format;				//!< The texture format (<c>SceGxmTextureFormat</c>).
	uint16_t	width;				//!< The texture width.
	uint16_t	height;				//!< The texture height.
	uint8_t		mipCount;			//!< The number of mipmaps.
	uint8_t		pad[3];				//!< Padding.
} SceGxtTextureInfo;

/** 
 * A set of flags that describe a texture.
 */
typedef enum SceGxtTextureFlags {
	SCE_GXT_TEXTURE_FLAG_HAS_BORDER_DATA		= 0x00000001U		//!< The texture contains border data.
} SceGxtTextureFlags;

#if (defined(__SCE__) && defined(__psp2__))
#include <sceerror.h>
#else
/** 
 * General pass code
 */
#define	SCE_OK								0
#endif	// (defined(__SCE__) && defined(__psp2__))

/** 
 * The call failed because a parameter has an invalid value.
 */
#define SCE_GXT_ERROR_INVALID_VALUE			-2141388800		/* 0x805D0000 */

/** 
 * The call failed because a pointer has an invalid value.
 */
#define SCE_GXT_ERROR_INVALID_POINTER		-2141388799		/* 0x805D0001 */

/** 
 * The call failed because a parameter is incorrectly aligned.
 */
#define SCE_GXT_ERROR_INVALID_ALIGNMENT		-2141388798		/* 0x805D0002 */


#define SCE_GXT_TAG								0x00545847UL		/* 'GXT\0'	*/
#define SCE_GXT_VERSION							0x10000003UL


#define SCE_GXT_PALETTE_SIZE_P4					64U
#define SCE_GXT_PALETTE_SIZE_P8					1024U

#ifndef SCE_GXT_ERROR_RETURN
#if defined _DEBUG && !defined(SCE_GXT_DISABLE_ERROR_TTY)
#define SCE_GXT_ERROR_RETURN(COND, ERROR_CODE, FMT, ...)		\
do {								\
	if (SCE_UNLIKELY(!(COND))) {				\
		SCE_DBG_LOG_ERROR(FMT, ##__VA_ARGS__);		\
		return (ERROR_CODE);				\
	}							\
} while(false)
#else
#define SCE_GXT_ERROR_RETURN(COND, ERROR_CODE, FMT, ...)		\
do {								\
	if (SCE_UNLIKELY(!(COND))) {				\
		return (ERROR_CODE);				\
	}							\
} while(false)
#endif
#endif	/*	#ifndef SCE_GXT_ERROR_RETURN	*/

#ifndef SCE_DBG_SIMPLE_ASSERT
#define SCE_DBG_SIMPLE_ASSERT(x)
#endif	/*	#ifndef SCE_DBG_SIMPLE_ASSERT	*/

#ifndef SCE_GXT_ASSERT
#define SCE_GXT_ASSERT(x)				SCE_DBG_SIMPLE_ASSERT(x)
#endif	/*	#ifndef SCE_GXT_ASSERT	*/


// Check if a value is aligned to the given power of 2 alignment.
#define SCE_GXT_IS_ALIGNED(VALUE, ALIGNMENT)	(((uint32_t)(VALUE) & ((ALIGNMENT) - 1)) == 0)

#ifdef	__cplusplus
extern "C" {
#endif	// def __cplusplus


/** 
 * Gets the header size of a GXT file.
 * @param gxt				A pointer to the GXT data.
 * @return					The size of the header in bytes.
 */
inline uint32_t sceGxtGetHeaderSize(const void *gxt)
{
	SCE_GXT_ASSERT(NULL != gxt);

	const SceGxtHeader *hdr = (const SceGxtHeader*)gxt;
	return hdr->dataOffset;
}

/** 
 * Gets the start address of the texture data within a GXT file.
 * @param gxt				A pointer to the GXT data.
 * @return					A pointer to the start of the texture data.
 */
inline const void* sceGxtGetDataAddress(const void *gxt)
{
	SCE_GXT_ASSERT(NULL != gxt);

	const SceGxtHeader *hdr = (const SceGxtHeader*)gxt;
	return (const uint8_t*)gxt + hdr->dataOffset;
}

/** 
 * Gets the size of the texture data within a GXT file.
 * @param gxt				A pointer to the GXT data.
 * @return					The size of the texture data in bytes.
 */
inline uint32_t sceGxtGetDataSize(const void *gxt)
{
	SCE_GXT_ASSERT(NULL != gxt);


	const SceGxtHeader *hdr = (const SceGxtHeader*)gxt;
	return hdr->dataSize;
}

/** 
 * Gets the number of textures in a GXT file.
 * @param gxt				A pointer to the GXT data.
 * @return					The number of textures.
 */
inline uint32_t sceGxtGetTextureCount(const void *gxt)
{
	SCE_GXT_ASSERT(NULL != gxt);

	const SceGxtHeader *hdr = (const SceGxtHeader*)gxt;
	return hdr->numTextures;
}

/** 
 * Checks if the specified texture has border data.
 * @param gxt				A pointer to the GXT data.
 * @param textureIndex		The index of the texture.
 * @return					A value of true if the texture has border data. If not, false is returned.
 */
inline bool sceGxtTextureHasBorderData(const void *gxt, uint32_t textureIndex)
{
	const SceGxtHeader *hdr = (const SceGxtHeader*)gxt;

	SCE_GXT_ASSERT(NULL != gxt);
	SCE_GXT_ASSERT(textureIndex < hdr->numTextures);

	const uint8_t* pTextureInfoBase = (const uint8_t*)hdr + sizeof(SceGxtHeader);

	const SceGxtTextureInfo* info = (const SceGxtTextureInfo*)(pTextureInfoBase + (textureIndex * sizeof(SceGxtTextureInfo))) ;

	return info->flags & SCE_GXT_TEXTURE_FLAG_HAS_BORDER_DATA;
}

/** 
 * Set the palette for the given texture.
 * @param texture			A pointer to the texture.
 * @param gxt				A pointer to the GXT data.
 * @param textureData		A pointer to the start of the texture data.
 * @param paletteIndex		The index of the palette.
 * @retval					SCE_OK The operation was successful.
 * @retval					SCE_GXT_ERROR_INVALID_ALIGNMENT The operation failed due to an invalid buffer alignment.
 * @retval					SCE_GXT_ERROR_INVALID_VALUE The operation failed due to an invalid input parameter.
 * @retval					SCE_GXT_ERROR_INVALID_POINTER The operation failed due to an invalid input pointer.
 */
inline SceGxtErrorCode sceGxtSetPalette(SceGxmTexture *texture, const void *gxt, const void *textureData, uint32_t paletteIndex)
{
	// check parameters
	SCE_GXT_ERROR_RETURN(
		texture,
		SCE_GXT_ERROR_INVALID_POINTER,
		"Parameter texture to function sceGxtSetPalette is NULL.");
	SCE_GXT_ERROR_RETURN(
		gxt,
		SCE_GXT_ERROR_INVALID_POINTER,
		"Parameter gxt to function sceGxtSetPalette is NULL.");
	SCE_GXT_ERROR_RETURN(
		textureData,
		SCE_GXT_ERROR_INVALID_POINTER,
		"Parameter textureData to function sceGxtSetPalette is NULL.");
	SCE_GXT_ERROR_RETURN(
		SCE_GXT_IS_ALIGNED(textureData, SCE_GXM_PALETTE_ALIGNMENT),
		SCE_GXT_ERROR_INVALID_ALIGNMENT,
		"Parameter textureData to function sceGxtSetPalette has value %p, which is not aligned to %u.",
		textureData,
		SCE_GXM_PALETTE_ALIGNMENT);

	uint32_t baseFormat = sceGxmTextureGetFormat(texture) & ~SCE_GXM_TEXTURE_SWIZZLE_MASK;

	SCE_GXT_ERROR_RETURN(
		baseFormat == SCE_GXM_TEXTURE_BASE_FORMAT_P4 || baseFormat == SCE_GXM_TEXTURE_BASE_FORMAT_P8,
		SCE_GXT_ERROR_INVALID_VALUE,
		"The function sceGxtSetPalette cannot be called for non-palettised textures.");

	const SceGxtHeader *hdr = (const SceGxtHeader*)gxt;
	void *palette;
	if(baseFormat == SCE_GXM_TEXTURE_BASE_FORMAT_P4)
	{
		SCE_GXT_ERROR_RETURN(
			paletteIndex < hdr->numP4Palettes,
			SCE_GXT_ERROR_INVALID_VALUE,
			"Parameter paletteIndex to function sceGxtSetPalette has value %u, which is not in the range [0, %u].",
			paletteIndex,
			hdr->numP4Palettes);

		palette = (uint8_t*)textureData + hdr->dataSize
				  - hdr->numP8Palettes * SCE_GXT_PALETTE_SIZE_P8
				  - (hdr->numP4Palettes - paletteIndex) * SCE_GXT_PALETTE_SIZE_P4;
	}
	else
	{
		SCE_GXT_ERROR_RETURN(
			paletteIndex < hdr->numP8Palettes,
			SCE_GXT_ERROR_INVALID_VALUE,
			"Parameter paletteIndex to function sceGxtSetPalette has value %u, which is not in the range [0, %u].",
			paletteIndex,
			hdr->numP8Palettes);

		palette = (uint8_t*)textureData + hdr->dataSize
				  - (hdr->numP8Palettes - paletteIndex) * SCE_GXT_PALETTE_SIZE_P8;
	}

	sceGxmTextureSetPalette(texture, palette);

	return SCE_OK;
}

/** 
 * Initializes the texture control words for a given texture within a GXT file.
 * @param texture			A pointer to texture to be initialized.
 * @param gxt				A pointer to the GXT data.
 * @param textureData		A pointer to the start of the texture data.
 * @param textureIndex		The index of the texture.
 * @retval					SCE_OK The operation was successful.
 * @retval					SCE_GXT_ERROR_INVALID_ALIGNMENT The operation failed due to an invalid buffer alignment.
 * @retval					SCE_GXT_ERROR_INVALID_VALUE The operation failed due to an invalid input parameter.
 * @retval					SCE_GXT_ERROR_INVALID_POINTER The operation failed due to an invalid input pointer.
 */
inline SceGxtErrorCode sceGxtInitTexture(SceGxmTexture *texture, const void *gxt, const void *textureData, uint32_t textureIndex)
{
	const SceGxtHeader *hdr = (const SceGxtHeader*)gxt;

	// check parameters
	SCE_GXT_ERROR_RETURN(
		texture,
		SCE_GXT_ERROR_INVALID_POINTER,
		"Parameter texture to function sceGxtInitTexture is NULL.");
	SCE_GXT_ERROR_RETURN(
		gxt,
		SCE_GXT_ERROR_INVALID_POINTER,
		"Parameter gxt to function sceGxtInitTexture is NULL.");
	SCE_GXT_ERROR_RETURN(
		textureData,
		SCE_GXT_ERROR_INVALID_POINTER,
		"Parameter textureData to function sceGxtInitTexture is NULL.");
	SCE_GXT_ERROR_RETURN(
		textureIndex < hdr->numTextures,
		SCE_GXT_ERROR_INVALID_VALUE,
		"Parameter textureIndex to function sceGxtInitTexture has value %u, which is not in the range [0, %u].",
		textureIndex,
		hdr->numTextures-1);

	const uint8_t* pTextureInfoBase = (const uint8_t*)hdr + sizeof(SceGxtHeader);

	const SceGxtTextureInfo* info = (const SceGxtTextureInfo*)(pTextureInfoBase + (textureIndex * sizeof(SceGxtTextureInfo))) ;

	uint32_t minimumDataAlignment = SCE_GXM_TEXTURE_ALIGNMENT;

	if (info->paletteIndex != ~0U) {
		minimumDataAlignment = SCE_GXM_PALETTE_ALIGNMENT;
	}

	SCE_GXT_ERROR_RETURN(
		SCE_GXT_IS_ALIGNED(textureData, minimumDataAlignment),
		SCE_GXT_ERROR_INVALID_ALIGNMENT,
		"Parameter textureData to function sceGxtInitTexture has value %p, which is not aligned to %u.",
		textureData,
		minimumDataAlignment);

	const uint8_t* data = (const uint8_t*)textureData - sceGxtGetHeaderSize(gxt) + info->dataOffset;

	if(hdr->version == SCE_GXT_VERSION) {
		// Current version (>= SDK0.990)
		switch(info->type)
		{
			case SCE_GXM_TEXTURE_LINEAR:
				sceGxmTextureInitLinear(texture, data, (SceGxmTextureFormat)info->format, info->width, info->height, info->mipCount);
				break;
			case SCE_GXM_TEXTURE_SWIZZLED:
				sceGxmTextureInitSwizzled(texture, data, (SceGxmTextureFormat)info->format, info->width, info->height, info->mipCount);
				break;
			case SCE_GXM_TEXTURE_CUBE:
			{
				// handle case where memory layout does not contain mipmaps
				uint32_t mipCount = info->mipCount == 1 ? 0 : info->mipCount;
				sceGxmTextureInitCube(texture, data, (SceGxmTextureFormat)info->format, info->width, info->height, mipCount);
				break;
			}
			case SCE_GXM_TEXTURE_SWIZZLED_ARBITRARY:
				sceGxmTextureInitSwizzledArbitrary(texture, data, (SceGxmTextureFormat)info->format, info->width, info->height, info->mipCount);
				break;
			case SCE_GXM_TEXTURE_CUBE_ARBITRARY:
			{
				// handle case where memory layout does not contain mipmaps
				uint32_t mipCount = info->mipCount == 1 ? 0 : info->mipCount;
				sceGxmTextureInitCubeArbitrary(texture, data, (SceGxmTextureFormat)info->format, info->width, info->height, mipCount);
				break;
			}
			default:
				// Unsupported type
				SCE_GXT_ASSERT(0);
		}
	}
	else {
		SCE_GXT_ERROR_RETURN(
			false,
			SCE_GXT_ERROR_INVALID_VALUE,
			"The GXT header version is incorrect: version 0x%08x was expected, but version 0x%08x was found.",
			SCE_GXT_VERSION,
			hdr->version);
	}

	// Set a border addressing mode if border data is present
	if(info->flags & SCE_GXT_TEXTURE_FLAG_HAS_BORDER_DATA){
		sceGxmTextureSetUAddrMode(texture, SCE_GXM_TEXTURE_ADDR_CLAMP_FULL_BORDER);
		sceGxmTextureSetVAddrMode(texture, SCE_GXM_TEXTURE_ADDR_CLAMP_FULL_BORDER);
	};

	// Set the default palette
	SceGxtErrorCode res = SCE_OK;
	if(info->paletteIndex != ~0U) {
		res = sceGxtSetPalette(texture, gxt, textureData, info->paletteIndex);
	}

	return res;
}

/** 
 * Checks if a pointer looks like a GXT file.
 * @param gxt			A pointer to the GXT data.
 * @retval				SCE_OK The data structure passes GXT header validation.
 * @retval				SCE_GXT_ERROR_INVALID_VALUE The operation failed because the header magic number was invalid
 * or the version numbers are not compatible.
 * @retval				SCE_GXT_ERROR_INVALID_POINTER The operation failed due to an invalid input pointer.
 */
inline SceGxtErrorCode sceGxtCheckData(const void *gxt)
{
	// check parameter
	SCE_GXT_ERROR_RETURN(
		gxt,
		SCE_GXT_ERROR_INVALID_POINTER,
		"Parameter gxt to function sceGxtCheckData is NULL.");

	// check the magic sequence
	SCE_GXT_ERROR_RETURN(
		((const SceGxtHeader*)gxt)->tag == SCE_GXT_TAG,
		SCE_GXT_ERROR_INVALID_VALUE,
		"The check bytes in the GXT header did not match the expect values, the data is corrupt.");


	// check the header version
	SCE_GXT_ERROR_RETURN(
		((const SceGxtHeader*)gxt)->version == SCE_GXT_VERSION,
		SCE_GXT_ERROR_INVALID_VALUE,
		"The GXT header version is incorrect: version 0x%08x was expected, but version 0x%08x was found.",
		SCE_GXT_VERSION,
		((const SceGxtHeader*)gxt)->version);

	// all ok
	return SCE_OK;
}

#ifdef	__cplusplus
}
#endif	// def __cplusplus

#endif /* _PSP2_GXT_H_ */
