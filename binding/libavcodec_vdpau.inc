//
// avcodec.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * The Video Decode and Presentation API for UNIX (VDPAU) is used for
 * hardware-accelerated decoding of MPEG-1/2, H.264 and VC-1.
 *
 * Copyright (C) 2008 NVIDIA
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

// #ifndef AVCODEC_VDPAU_H
// #define AVCODEC_VDPAU_H

(**
 * @file
 * @ingroup lavc_codec_hwaccel_vdpau
 * Public libavcodec VDPAU header.
 *)

(**
 * @defgroup lavc_codec_hwaccel_vdpau VDPAU Decoder and Renderer
 * @ingroup lavc_codec_hwaccel
 *
 * VDPAU hardware acceleration has two modules
 * - VDPAU decoding
 * - VDPAU presentation
 *
 * The VDPAU decoding module parses all headers using FFmpeg
 * parsing mechanisms and uses VDPAU for the actual decoding.
 *
 * As per the current implementation, the actual decoding
 * and rendering (API calls) are done as part of the VDPAU
 * presentation (vo_vdpau.c) module.
 *
 * @{
 *)

// #include <vdpau/vdpau.h>
// #include "libavutil/avconfig.h"
// #include "libavutil/attributes.h"

// #include "avcodec.h"
// #include "version.h"

{$ifdef FF_API_BUFS_VDPAU}
type
  AVVDPAUPictureInfo = record
    h264: VdpPictureInfoH264;
    mpeg: VdpPictureInfoMPEG1Or2;
    vc1: VdpPictureInfoVC1;
    mpeg4: VdpPictureInfoMPEG4Part2;
  end;
{$endif}

type
  PAVCodecContext = ^AVCodecContext;
  AVCodecContext = record
  end;

  PAVFrame = ^AVFrame;
  AVFrame = record
  end;

  AVVDPAU_Render2 = function (ctx: PAVCodecContext; frame: PAVFrame; const pi: PVdpPictureInfo; arg: cuint32; const bb: PVdpBitstreamBuffer): cint; cdecl;

(**
 * This structure is used to share data between the libavcodec library and
 * the client video application.
 * The user shall allocate the structure via the av_alloc_vdpau_hwaccel
 * function and make it available as
 * AVCodecContext.hwaccel_context. Members can be set by the user once
 * during initialization or through each AVCodecContext.get_buffer()
 * function call. In any case, they must be valid prior to calling
 * decoding functions.
 *
 * The size of this structure is not a part of the public ABI and must not
 * be used outside of libavcodec. Use av_vdpau_alloc_context() to allocate an
 * AVVDPAUContext.
 *)
  PAVVDPAUContext = ^AVVDPAUContext;
  AVVDPAUContext = record
    (**
     * VDPAU decoder handle
     *
     * Set by user.
     *)
    decoder: VdpDecoder;

    (**
     * VDPAU decoder render callback
     *
     * Set by the user.
     *)
    render: PVdpDecoderRender;

{$ifdef FF_API_BUFS_VDPAU}
    (**
     * VDPAU picture information
     *
     * Set by libavcodec.
     *)
    //TODO attribute_deprecated
    info: AVVDPAUPictureInfo;

    (**
     * Allocated size of the bitstream_buffers table.
     *
     * Set by libavcodec.
     *)
    //TODO attribute_deprecated
    bitstream_buffers_allocated: cint;

    (**
     * Useful bitstream buffers in the bitstream buffers table.
     *
     * Set by libavcodec.
     *)
    //TODO attribute_deprecated
    bitstream_buffers_used: cint;

   (**
     * Table of bitstream buffers.
     * The user is responsible for freeing this buffer using av_freep().
     *
     * Set by libavcodec.
     *)
    //TODO attribute_deprecated
    bitstream_buffers: PVdpBitstreamBuffer;
{$endif}
    render2: AVVDPAU_Render2;
  end;

(**
 * @brief allocation function for AVVDPAUContext
 *
 * Allows extending the struct without breaking API/ABI
 *)
function av_alloc_vdpaucontext(): PAVVDPAUContext; cdecl; external LIB_AVCODEC;

function av_vdpau_hwaccel_get_render2(const ctx: PAVVDPAUContext): AVVDPAU_Render2; cdecl; external LIB_AVCODEC;
procedure av_vdpau_hwaccel_set_render2(ctx: PAVVDPAUContext; render2: AVVDPAU_Render2): AVVDPAU_Render2; cdecl; external LIB_AVCODEC;

(**
 * Associate a VDPAU device with a codec context for hardware acceleration.
 * This function is meant to be called from the get_format() codec callback,
 * or earlier. It can also be called after avcodec_flush_buffers() to change
 * the underlying VDPAU device mid-stream (e.g. to recover from non-transparent
 * display preemption).
 *
 * @note get_format() must return AV_PIX_FMT_VDPAU if this function completes
 * successfully.
 *
 * @param avctx decoding context whose get_format() callback is invoked
 * @param device VDPAU device handle to use for hardware acceleration
 * @param get_proc_address VDPAU device driver
 * @param flags zero of more OR'd AV_HWACCEL_FLAG_* flags
 *
 * @return 0 on success, an AVERROR code on failure.
 *)
function av_vdpau_bind_context(avctx: PAVCodecContext; device: VdpDevice; get_proc_address: PVdpGetProcAddress; flags: cunsigned): cint; cdecl; external LIB_AVCODEC;

(**
 * Gets the parameters to create an adequate VDPAU video surface for the codec
 * context using VDPAU hardware decoding acceleration.
 *
 * @note Behavior is undefined if the context was not successfully bound to a
 * VDPAU device using av_vdpau_bind_context().
 *
 * @param avctx the codec context being used for decoding the stream
 * @param type storage space for the VDPAU video surface chroma type
 *              (or NULL to ignore)
 * @param width storage space for the VDPAU video surface pixel width
 *              (or NULL to ignore)
 * @param height storage space for the VDPAU video surface pixel height
 *              (or NULL to ignore)
 *
 * @return 0 on success, a negative AVERROR code on failure.
 *)
function av_vdpau_get_surface_parameters(avctx: PAVCodecContext; type_: PVdpChromaType; width: pcuint32; height: pcuint32): cint; cdecl; external LIB_AVCODEC;

(**
 * Allocate an AVVDPAUContext.
 *
 * @return Newly-allocated AVVDPAUContext or NULL on failure.
 *)
function av_vdpau_alloc_context(): PAVVDPAUContext; cdecl; external LIB_AVCODEC;

{$ifdef FF_API_VDPAU_PROFILE}
(**
 * Get a decoder profile that should be used for initializing a VDPAU decoder.
 * Should be called from the AVCodecContext.get_format() callback.
 *
 * @deprecated Use av_vdpau_bind_context() instead.
 *
 * @param avctx the codec context being used for decoding the stream
 * @param profile a pointer into which the result will be written on success.
 *                The contents of profile are undefined if this function returns
 *                an error.
 *
 * @return 0 on success (non-negative), a negative AVERROR on failure.
 *)
//TODO attribute_deprecated
function av_vdpau_get_profile(avctx: PAVCodecContext; profile: PVdpDecoderProfile): cint; cdecl; external LIB_AVCODEC;
{$endif}

{$ifdef FF_API_CAP_VDPAU}
const
(** @brief The videoSurface is used for rendering. *)
  FF_VDPAU_STATE_USED_FOR_RENDER = 1;

(**
 * @brief The videoSurface is needed for reference/prediction.
 * The codec manipulates this.
 *)
  FF_VDPAU_STATE_USED_FOR_REFERENCE = 2;

(**
 * @brief This structure is used as a callback between the FFmpeg
 * decoder (vd_) and presentation (vo_) module.
 * This is used for defining a video frame containing surface,
 * picture parameter, bitstream information etc which are passed
 * between the FFmpeg decoder and its clients.
 *)
type
  Pvdpau_render_state = ^vdpau_render_state;
  vdpau_render_state = record
    surface: VdpVideoSurface; ///< Used as rendered surface, never changed.

    state: cint; ///< Holds FF_VDPAU_STATE_* values.

    (** picture parameter information for all supported codecs *)
    info: AVVDPAUPictureInfo;

    (** Describe size/location of the compressed video data.
        Set to 0 when freeing bitstream_buffers. *)
    bitstream_buffers_allocated: cint;
    bitstream_buffers_used: cint;
    (** The user is responsible for freeing this buffer using av_freep(). *)
    bitstream_buffers: PVdpBitstreamBuffer;
  end;
{$endif}

(* @}*)

// #endif (* AVCODEC_VDPAU_H *)
