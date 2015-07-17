/**
 * \file sysmem.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_KERNEL_SYSMEM_H_
#define _PSP2_KERNEL_SYSMEM_H_

#include <psp2/kernel/sysmem/memblock.h>

#ifdef	__cplusplus
extern "C" {
#endif	// def __cplusplus

typedef struct SceKernelFreeMemorySizeInfo {
	SceSize size;
	SceSize sizeMain;
	SceSize sizeCdram;
	SceSize sizePhycont;
} SceKernelFreeMemorySizeInfo;

/**
 * Get free memory size
 */
int sceKernelGetFreeMemorySize(
	SceKernelFreeMemorySizeInfo *pInfo);


// VM stuff
SceUID sceKernelAllocMemBlockForVM(const char *, SceSize);

void sceKernelSyncVMDomain(SceUID, void *, SceSize);
void sceKernelOpenVMDomain();
void sceKernelCloseVMDomain();

#ifdef	__cplusplus
}
#endif	// def __cplusplus

#endif /* _PSP2_KERNEL_SYSMEM_H_ */ 
