//
// avcodec.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * VDA HW acceleration
 *
 * copyright (c) 2011 Sebastien Zwickert
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

// #ifndef AVCODEC_VDA_H
// #define AVCODEC_VDA_H

(**
 * @file
 * @ingroup lavc_codec_hwaccel_vda
 * Public libavcodec VDA header.
 *)

// #include "libavcodec/avcodec.h"

// #include <stdint.h>

// emmintrin.h is unable to compile with -std=c99 -Werror=missing-prototypes
// http://openradar.appspot.com/8026390
//TODO #undef __GNUC_STDC_INLINE__

//TODO  Picture = QuickdrawPicture;
//TODO #include <VideoDecodeAcceleration/VDADecoder.h>
//TODO #undef Picture

// #include "libavcodec/version.h"

// extra flags not defined in VDADecoder.h
const
  kVDADecodeInfo_Asynchronous = (1 shl 0);
  kVDADecodeInfo_FrameDropped = (1 shl 1);

(**
 * @defgroup lavc_codec_hwaccel_vda VDA
 * @ingroup lavc_codec_hwaccel
 *
 * @{
 *)

(**
 * This structure is used to provide the necessary configurations and data
 * to the VDA FFmpeg HWAccel implementation.
 *
 * The application must make it available as AVCodecContext.hwaccel_context.
 *)
type
  Pvda_context = ^vda_context;
  vda_context = record
    (**
     * VDA decoder object.
     *
     * - encoding: unused
     * - decoding: Set/Unset by libavcodec.
     *)
    decoder: VDADecoder;

    (**
     * The Core Video pixel buffer that contains the current image data.
     *
     * encoding: unused
     * decoding: Set by libavcodec. Unset by user.
     *)
    cv_buffer: CVPixelBufferRef;

    (**
     * Use the hardware decoder in synchronous mode.
     *
     * encoding: unused
     * decoding: Set by user.
     *)
    use_sync_decoding: cint;

    (**
     * The frame width.
     *
     * - encoding: unused
     * - decoding: Set/Unset by user.
     *)
    width: cint;

    (**
     * The frame height.
     *
     * - encoding: unused
     * - decoding: Set/Unset by user.
     *)
    height: cint;

    (**
     * The frame format.
     *
     * - encoding: unused
     * - decoding: Set/Unset by user.
     *)
    format: cint;

    (**
     * The pixel format for output image buffers.
     *
     * - encoding: unused
     * - decoding: Set/Unset by user.
     *)
    cv_pix_fmt_type: OSType;

    (**
     * unused
     *)
    priv_bitstream: pcuint8;

    (**
     * unused
     *)
    priv_bitstream_size: cint;

    (**
     * unused
     *)
    priv_allocated_size: cint;

    (**
     * Use av_buffer to manage buffer.
     * When the flag is set, the CVPixelBuffers returned by the decoder will
     * be released automatically, so you have to retain them if necessary.
     * Not setting this flag may cause memory leak.
     *
     * encoding: unused
     * decoding: Set by user.
     *)
    use_ref_buffer: cint;
  end;

(** Create the video decoder. *)
function ff_vda_create_decoder(vda_ctx: Pvda_context; extradata: pcuint8; extradata_size: cint): cint; cdecl; external LIB_AVCODEC;

(** Destroy the video decoder. *)
function ff_vda_destroy_decoder(vda_ctx: Pvda_context): cint; cdecl; external LIB_AVCODEC;

(**
 * This struct holds all the information that needs to be passed
 * between the caller and libavcodec for initializing VDA decoding.
 * Its size is not a part of the public ABI, it must be allocated with
 * av_vda_alloc_context() and freed with av_free().
 *)
type
  PAVVDAContext = ^AVVDAContext;
  AVVDAContext = record
    (**
     * VDA decoder object. Created and freed by the caller.
     *)
    decoder: VDADecoder;

    (**
     * The output callback that must be passed to VDADecoderCreate.
     * Set by av_vda_alloc_context().
     *)
    output_callback: VDADecoderOutputCallback;

    (**
     * CVPixelBuffer Format Type that VDA will use for decoded frames; set by
     * the caller.
     *)
    cv_pix_fmt_type: OSType;
  end;

(**
 * Allocate and initialize a VDA context.
 *
 * This function should be called from the get_format() callback when the caller
 * selects the AV_PIX_FMT_VDA format. The caller must then create the decoder
 * object (using the output callback provided by libavcodec) that will be used
 * for VDA-accelerated decoding.
 *
 * When decoding with VDA is finished, the caller must destroy the decoder
 * object and free the VDA context using av_free().
 *
 * @return the newly allocated context or NULL on failure
 *)
function av_vda_alloc_context(): PAVVDAContext; cdecl; external LIB_AVCODEC;

(**
 * This is a convenience function that creates and sets up the VDA context using
 * an internal implementation.
 *
 * @param avctx the corresponding codec context
 *
 * @return >= 0 on success, a negative AVERROR code on failure
 *)
function av_vda_default_init(avctx: PAVCodecContext): cint; cdecl; external LIB_AVCODEC;

(**
 * This is a convenience function that creates and sets up the VDA context using
 * an internal implementation.
 *
 * @param avctx the corresponding codec context
 * @param vdactx the VDA context to use
 *
 * @return >= 0 on success, a negative AVERROR code on failure
 *)
function av_vda_default_init2(avctx: PAVCodecContext; vdactx: PAVVDAContext): cint; cdecl; external LIB_AVCODEC;

(**
 * This function must be called to free the VDA context initialized with
 * av_vda_default_init().
 *
 * @param avctx the corresponding codec context
 *)
procedure av_vda_default_free(avctx: PAVCodecContext); cdecl; external LIB_AVCODEC;

(**
 * @}
 *)

// #endif (* AVCODEC_VDA_H *)
