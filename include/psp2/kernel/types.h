/**
 * \file types.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_KERNEL_TYPES_H_
#define _PSP2_KERNEL_TYPES_H_

#include <psp2/types.h>

#ifdef	__cplusplus
extern "C" {
#endif	// def __cplusplus

#if !defined(_LANGUAGE_ASSEMBLY)


/*----- sysmem/block -----*/
/**
 * memory block type 
 * 
 * @internal
 */
typedef SceUInt32		SceKernelMemBlockType;


/*****************************************************/

typedef int			SceIoMode;
typedef int			SceMode; /* for compat */

/**
 * @typedef SceIores
 */
#ifndef _SCE_KERNEL_IORES_T
#define _SCE_KERNEL_IORES_T

typedef SceInt64 SceIores;

#endif	/* _SCE_KERNEL_IORES_T */

/*****************************************************/

typedef union _SceKernelSysClock {
	struct	{
		SceUInt32	low;	
		SceUInt32	hi;		
	} u;					
	SceUInt64		quad;	
} SceKernelSysClock;

#endif	/* !defined(_LANGUAGE_ASSEMBLY) */

#ifdef	__cplusplus
}
#endif	// def __cplusplus

#endif	/* _PSP2_KERNEL_TYPES_H_ */

