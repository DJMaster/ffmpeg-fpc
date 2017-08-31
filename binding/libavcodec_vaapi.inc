//
// avcodec.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * Video Acceleration API (shared data between FFmpeg and the video player)
 * HW decode acceleration for MPEG-2, MPEG-4, H.264 and VC-1
 *
 * Copyright (C) 2008-2009 Splitted-Desktop Systems
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *)

// #ifndef AVCODEC_VAAPI_H
// #define AVCODEC_VAAPI_H

(**
 * @file
 * @ingroup lavc_codec_hwaccel_vaapi
 * Public libavcodec VA API header.
 *)

// #include <stdint.h>
// #include "libavutil/attributes.h"
// #include "version.h"

{$if FF_API_STRUCT_VAAPI_CONTEXT}

(**
 * @defgroup lavc_codec_hwaccel_vaapi VA API Decoding
 * @ingroup lavc_codec_hwaccel
 * @{
 *)

(**
 * This structure is used to share data between the FFmpeg library and
 * the client video application.
 * This shall be zero-allocated and available as
 * AVCodecContext.hwaccel_context. All user members can be set once
 * during initialization or through each AVCodecContext.get_buffer()
 * function call. In any case, they must be valid prior to calling
 * decoding functions.
 *
 * Deprecated: use AVCodecContext.hw_frames_ctx instead.
 *)
//TODO attribute_deprecated
type
  Pvaapi_context = ^vaapi_context;
  vaapi_context = record
    (**
     * Window system dependent data
     *
     * - encoding: unused
     * - decoding: Set by user
     *)
    display: pointer;

    (**
     * Configuration ID
     *
     * - encoding: unused
     * - decoding: Set by user
     *)
    config_id: cuint32;

    (**
     * Context ID (video decode pipeline)
     *
     * - encoding: unused
     * - decoding: Set by user
     *)
    context_id: cuint32;

{$if FF_API_VAAPI_CONTEXT}
    (**
     * VAPictureParameterBuffer ID
     *
     * - encoding: unused
     * - decoding: Set by libavcodec
     *)
    //TODO attribute_deprecated
    pic_param_buf_id: cuint32;

    (**
     * VAIQMatrixBuffer ID
     *
     * - encoding: unused
     * - decoding: Set by libavcodec
     *)
    //TODO attribute_deprecated
    iq_matrix_buf_id: cuint32;

    (**
     * VABitPlaneBuffer ID (for VC-1 decoding)
     *
     * - encoding: unused
     * - decoding: Set by libavcodec
     *)
    //TODO attribute_deprecated
    bitplane_buf_id: cuint32;

    (**
     * Slice parameter/data buffer IDs
     *
     * - encoding: unused
     * - decoding: Set by libavcodec
     *)
    //TODO attribute_deprecated
    slice_buf_ids: pcuint32;

    (**
     * Number of effective slice buffer IDs to send to the HW
     *
     * - encoding: unused
     * - decoding: Set by libavcodec
     *)
    //TODO attribute_deprecated
    n_slice_buf_ids: cuint;

    (**
     * Size of pre-allocated slice_buf_ids
     *
     * - encoding: unused
     * - decoding: Set by libavcodec
     *)
    //TODO attribute_deprecated
    slice_buf_ids_alloc: cuint;

    (**
     * Pointer to VASliceParameterBuffers
     *
     * - encoding: unused
     * - decoding: Set by libavcodec
     *)
    //TODO attribute_deprecated
    slice_params: pointer;

    (**
     * Size of a VASliceParameterBuffer element
     *
     * - encoding: unused
     * - decoding: Set by libavcodec
     *)
    //TODO attribute_deprecated
    slice_param_size: cuint;

    (**
     * Size of pre-allocated slice_params
     *
     * - encoding: unused
     * - decoding: Set by libavcodec
     *)
    //TODO attribute_deprecated
    slice_params_alloc: cuint;

    (**
     * Number of slices currently filled in
     *
     * - encoding: unused
     * - decoding: Set by libavcodec
     *)
    //TODO attribute_deprecated
    slice_count: cuint;

    (**
     * Pointer to slice data buffer base
     * - encoding: unused
     * - decoding: Set by libavcodec
     *)
    //TODO attribute_deprecated
    slice_data: pcuint8;

    (**
     * Current size of slice data
     *
     * - encoding: unused
     * - decoding: Set by libavcodec
     *)
    //TODO attribute_deprecated
    slice_data_size: cuint32;
{$endif}
  end;

(* @} *)

{$endif} (* FF_API_STRUCT_VAAPI_CONTEXT *)

// #endif (* AVCODEC_VAAPI_H *)
