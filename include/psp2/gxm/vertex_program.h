/**
 * \file vertex_program.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


#ifndef _PSP2_GXM_VERTEX_PROGRAM_H_
#define _PSP2_GXM_VERTEX_PROGRAM_H_

/** 
 * @file
 */

#include <psp2/gxm/types.h>
#include <psp2/gxm/program.h>

#ifdef	__cplusplus
extern "C" {
#endif	// def __cplusplus

/** 
 * The data structure for vertex programs.
 * 
 * This structure is currently opaque, filled out internally by the
 * shader patcher.
 * 
 * @ingroup render
 */
typedef struct SceGxmVertexProgram SceGxmVertexProgram;

/** 
 * Gets the underlying program for the given vertex program.
 * 
 * @param[in] vertexProgram	A pointer to the vertex program.
 * @return
 * A pointer to the program.
 * 
 * @ingroup render
 */
const SceGxmProgram *sceGxmVertexProgramGetProgram(
	const SceGxmVertexProgram *vertexProgram);

#ifdef	__cplusplus
}
#endif	// def __cplusplus

#endif /* _PSP2_GXM_VERTEX_PROGRAM_H_ */
