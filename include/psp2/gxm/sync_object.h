/**
 * \file sync_object.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_GXM_SYNC_OBJECT_H_
#define _PSP2_GXM_SYNC_OBJECT_H_

/** 
 * @file
 */
#include <psp2/gxm/types.h>
#include <psp2/gxm/error.h>
#include <psp2/gxm/structs.h>

#ifdef	__cplusplus
extern "C" {
#endif	// def __cplusplus

/** 
 * Creates a sync object.  Currently sync objects are used purely to
 * synchronize rendering with display operations in the display queue.
 * 
 * @param[out]	syncObject		A pointer to storage for a sync object pointer.
 * 
 * @retval
 * SCE_OK		The operation was completed successfully.
 * @retval
 * SCE_GXM_ERROR_UNINITIALIZED The operation failed as libgxm is not initialized.
 * @retval
 * SCE_GXM_ERROR_INVALID_POINTER The operation failed as the sync object pointer was <c>NULL</c>.
 * @retval
 * SCE_GXM_ERROR_DRIVER The operation failed due to a driver error.
 * 
 * @ingroup render
 */
SceGxmErrorCode sceGxmSyncObjectCreate(SceGxmSyncObject **syncObject);

/** 
 * Destroys a sync object.	
 * 
 * @param[in,out]	syncObject		A sync object pointer.
 * 
 * @retval
 * SCE_OK		The operation was completed successfully.
 * @retval
 * SCE_GXM_ERROR_UNINITIALIZED The operation failed as libgxm is not initialized.
 * @retval
 * SCE_GXM_ERROR_INVALID_POINTER The operation failed as the sync object pointer was <c>NULL</c>.
 * @retval
 * SCE_GXM_ERROR_DRIVER The operation failed due to a driver error.
 * 
 * @ingroup render
 */
SceGxmErrorCode sceGxmSyncObjectDestroy(SceGxmSyncObject *syncObject);

#ifdef	__cplusplus
}
#endif	// def __cplusplus

#endif /* _PSP2_GXM_SYNC_OBJECT_H_ */
