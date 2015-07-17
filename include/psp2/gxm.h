/**
 * \file gxm.h
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PSP2_GXM_H_
#define _PSP2_GXM_H_

/** 
 * @file
 * Helper include file that includes all public headers.
 */

#include <psp2/gxm/blending.h>
#include <psp2/gxm/constants.h>
#include <psp2/gxm/context.h>
#include <psp2/gxm/defs.h>
#include <psp2/gxm/display_queue.h>
#include <psp2/gxm/error.h>
#include <psp2/gxm/fragment_program.h>
#include <psp2/gxm/init.h>
#include <psp2/gxm/memory.h>
#include <psp2/gxm/precomputation.h>
#include <psp2/gxm/program.h>
#include <psp2/gxm/render_target.h>
#include <psp2/gxm/shader_patcher.h>
#include <psp2/gxm/structs.h>
#include <psp2/gxm/surface.h>
#include <psp2/gxm/sync_object.h>
#include <psp2/gxm/texture.h>
#include <psp2/gxm/transfer.h>
#include <psp2/gxm/types.h>
#include <psp2/gxm/uniforms.h>
#include <psp2/gxm/vertex_program.h>

/** 
 * @defgroup render Rendering API
 * Structures and functions for creating and rendering GPU data structures.
 */

/** 
 * @defgroup shader Shader API
 * Structures and functions that relate to the shader compiler output.
 */

/** 
 * @defgroup shaderpatcher Shader Patcher API
 * Structures and functions to provide a more traditional API for shaders, where vertex
 * formats, blend state and MRT setup are defined at runtime.  There will some unavoidable
 * CPU cost for using this API, and developers are advised to define all of these areas
 * offline in their shader code to avoid these overheads.
 */

#endif /* _PSP2_GXM_H_ */
