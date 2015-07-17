/**
 * \file
 * \brief Header file which defines unique variable types
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PSP2_TYPES_H_
#define _PSP2_TYPES_H_

#include <stddef.h>
#include <stdint.h>

#include <psp2/scetypes.h>


enum {
	PSP2_FALSE,
	PSP2_TRUE
};

#define PSP2_KERNEL_PROCESS_ID_SELF 0 //!< Current running process ID is always 0

#define PSP2_UID_NAMELEN 31 //!< Maximum length for kernel object names

#endif
