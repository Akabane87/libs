/**
 * \file display.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_DISPLAY_DISPLAY_H_
#define _PSP2_DISPLAY_DISPLAY_H_

#include <psp2/types.h>

#if defined(__cplusplus)
extern "C" {
#endif	/* defined(__cplusplus) */


/**
 * Error number definition
 */

/**
 * invalid display head argument 
 */
#define SCE_DISPLAY_ERROR_INVALID_HEAD			-2144796672	/* 0x80290000 */

/**
 * invalid argument 
 */
#define SCE_DISPLAY_ERROR_INVALID_VALUE			-2144796671	/* 0x80290001 */

/**
 * invalid address argument 
 */
#define SCE_DISPLAY_ERROR_INVALID_ADDR			-2144796670	/* 0x80290002 */

/**
 * invalid pixel format argument 
 */
#define SCE_DISPLAY_ERROR_INVALID_PIXELFORMAT	-2144796669	/* 0x80290003 */

/**
 * invalid pitch argument 
 */
#define SCE_DISPLAY_ERROR_INVALID_PITCH			-2144796668	/* 0x80290004 */

/**
 * invalid width,height argument 
 */
#define SCE_DISPLAY_ERROR_INVALID_RESOLUTION	-2144796667	/* 0x80290005 */

/**
 * invalid update timing argument 
 */
#define SCE_DISPLAY_ERROR_INVALID_UPDATETIMING	-2144796666	/* 0x80290006 */

/**
 * this process has no frame buffer 
 */
#define SCE_DISPLAY_ERROR_NO_FRAME_BUFFER		-2144796665	/* 0x80290007 */

/**
 * this process's frame buffer has no pixel data 
 */
#define SCE_DISPLAY_ERROR_NO_PIXEL_DATA			-2144796664	/* 0x80290008 */

/**
 * the head does not output any signal 
 */
#define SCE_DISPLAY_ERROR_NO_OUTPUT_SIGNAL		-2144796663	/* 0x80290009 */


#define SCE_DISPLAY_PIXELFORMAT_A8B8G8R8	0x00000000U		/* A:B:G:R=8:8:8:8    32bit */
#define SCE_DISPLAY_PIXEL_A8B8G8R8			SCE_DISPLAY_PIXELFORMAT_A8B8G8R8



/*Get number of refresh rate */
SceInt32 sceDisplayGetRefreshRate(float *pFps);


typedef struct SceDisplayFrameBuf {
	SceUInt32	size;					/* sizeof(SceDisplayFrameBuf)                      */
	void		*base;					/* frame buffer base address (256bytes aligned)    */
	SceUInt32	pitch;					/* frame buffer pitch pixels                       */
	SceUInt32	pixelformat;			/* pixel format (SCE_DISPLAY_PIXELFORMAT_A8B8G8R8) */
	SceUInt32	width;					/* frame buffer width                              */
	SceUInt32	height;					/* frame buffer height                             */
} SceDisplayFrameBuf;


/*Update frame buffer base address and pixel format */
#define SCE_DISPLAY_UPDATETIMING_NEXTHSYNC	0
#define SCE_DISPLAY_UPDATETIMING_NEXTVSYNC	1
SceInt32 sceDisplaySetFrameBuf(const SceDisplayFrameBuf *pFrameBuf, SceInt32 iUpdateTimingMode);

/*Get frame buffer base address and pixel format */
SceInt32 sceDisplayGetFrameBuf(SceDisplayFrameBuf *pFrameBuf, SceInt32 iUpdateTimingMode);



/*Get number of VSYNCs up to the present */
SceInt32 sceDisplayGetVcount(void);


/*Put thread in WAIT state until start of next VBLANK */
SceInt32 sceDisplayWaitVblankStart(void);
SceInt32 sceDisplayWaitVblankStartCB(void);

/*Wait for start of VBLANK after the specified V period has elapsed since the previous call  */
SceInt32 sceDisplayWaitVblankStartMulti(SceUInt32 vcount);
SceInt32 sceDisplayWaitVblankStartMultiCB(SceUInt32 vcount);

/*Wait for start of VBLANK after the specified V period has elapsed since the previous updating frame buffer */
SceInt32 sceDisplayWaitSetFrameBuf(void);
SceInt32 sceDisplayWaitSetFrameBufCB(void);
SceInt32 sceDisplayWaitSetFrameBufMulti(SceUInt32 vcount);
SceInt32 sceDisplayWaitSetFrameBufMultiCB(SceUInt32 vcount);


/*Registers callback that is notified at the start of VBLANK */
SceInt32 sceDisplayRegisterVblankStartCallback(SceUID uid);
SceInt32 sceDisplayUnregisterVblankStartCallback(SceUID uid);


#if defined(__cplusplus)
}
#endif	/* defined(__cplusplus) */

#endif	/* _PSP2_DISPLAY_DISPLAY_H_ */
