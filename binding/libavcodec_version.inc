//
// avcodec.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
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

// #ifndef AVCODEC_VERSION_H
// #define AVCODEC_VERSION_H

(**
 * @file
 * @ingroup libavc
 * Libavcodec version macros.
 *)

#include "libavutil/version.h"

const
  LIBAVCODEC_VERSION_MAJOR = 57;
  LIBAVCODEC_VERSION_MINOR = 89;
  LIBAVCODEC_VERSION_MICRO = 100;

  LIBAVCODEC_VERSION_INT = AV_VERSION_INT(LIBAVCODEC_VERSION_MAJOR, \
                                               LIBAVCODEC_VERSION_MINOR, \
                                               LIBAVCODEC_VERSION_MICRO);
  LIBAVCODEC_VERSION = AV_VERSION(LIBAVCODEC_VERSION_MAJOR,    \
                                           LIBAVCODEC_VERSION_MINOR,    \
                                           LIBAVCODEC_VERSION_MICRO);
  LIBAVCODEC_BUILD = LIBAVCODEC_VERSION_INT;

  LIBAVCODEC_IDENT = 'Lavc' + AV_STRINGIFY(LIBAVCODEC_VERSION);

(**
 * FF_API_* defines may be placed below to indicate public API that will be
 * dropped at a future version bump. The defines themselves are not part of
 * the public API and may change, break or disappear at any time.
 *
 * @note, when bumping the major version it is recommended to manually
 * disable each FF_API_* in its own commit instead of disabling them all
 * at once through the bump. This improves the git bisect-ability of the change.
 *)

{$ifndef FF_API_VIMA_DECODER}
const
  FF_API_VIMA_DECODER = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_AUDIO_CONVERT}
const
  FF_API_AUDIO_CONVERT = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_AVCODEC_RESAMPLE}
const
  FF_API_AVCODEC_RESAMPLE = FF_API_AUDIO_CONVERT;
{$endif}
{$ifndef FF_API_GETCHROMA}
const
  FF_API_GETCHROMA = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_MISSING_SAMPLE}
const
  FF_API_MISSING_SAMPLE = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_LOWRES}
const
  FF_API_LOWRES = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_CAP_VDPAU}
const
  FF_API_CAP_VDPAU = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_BUFS_VDPAU}
const
  FF_API_BUFS_VDPAU = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_VOXWARE}
const
  FF_API_VOXWARE = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_SET_DIMENSIONS}
const
  FF_API_SET_DIMENSIONS = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_DEBUG_MV}
const
  FF_API_DEBUG_MV = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_AC_VLC}
const
  FF_API_AC_VLC = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_OLD_MSMPEG4}
const
  FF_API_OLD_MSMPEG4 = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_ASPECT_EXTENDED}
const
  FF_API_ASPECT_EXTENDED = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_ARCH_ALPHA}
const
  FF_API_ARCH_ALPHA = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_XVMC}
const
  FF_API_XVMC = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_ERROR_RATE}
const
  FF_API_ERROR_RATE = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_QSCALE_TYPE}
const
  FF_API_QSCALE_TYPE = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_MB_TYPE}
const
  FF_API_MB_TYPE = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_MAX_BFRAMES}
const
  FF_API_MAX_BFRAMES = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_NEG_LINESIZES}
const
  FF_API_NEG_LINESIZES = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_EMU_EDGE}
const
  FF_API_EMU_EDGE = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_ARCH_SH4}
const
  FF_API_ARCH_SH4 = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_ARCH_SPARC}
const
  FF_API_ARCH_SPARC = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_UNUSED_MEMBERS}
const
  FF_API_UNUSED_MEMBERS = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_IDCT_XVIDMMX}
const
  FF_API_IDCT_XVIDMMX = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_INPUT_PRESERVED}
const
  FF_API_INPUT_PRESERVED = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_NORMALIZE_AQP}
const
  FF_API_NORMALIZE_AQP = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_GMC}
const
  FF_API_GMC = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_MV0}
const
  FF_API_MV0 = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_CODEC_NAME}
const
  FF_API_CODEC_NAME = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_AFD}
const
  FF_API_AFD = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_VISMV}
(* XXX: don't forget to drop the -vismv documentation *)
const
  FF_API_VISMV = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_AUDIOENC_DELAY}
const
  FF_API_AUDIOENC_DELAY = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_VAAPI_CONTEXT}
const
  FF_API_VAAPI_CONTEXT = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_MERGE_SD}
const
  FF_API_MERGE_SD = (LIBAVCODEC_VERSION_MAJOR < 58);
{$endif}
{$ifndef FF_API_AVCTX_TIMEBASE}
const
  FF_API_AVCTX_TIMEBASE = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_MPV_OPT}
const
  FF_API_MPV_OPT = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_STREAM_CODEC_TAG}
const
  FF_API_STREAM_CODEC_TAG = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_QUANT_BIAS}
const
  FF_API_QUANT_BIAS = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_RC_STRATEGY}
const
  FF_API_RC_STRATEGY = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_CODED_FRAME}
const
  FF_API_CODED_FRAME = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_MOTION_EST}
const
  FF_API_MOTION_EST = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_WITHOUT_PREFIX}
const
  FF_API_WITHOUT_PREFIX = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_SIDEDATA_ONLY_PKT}
const
  FF_API_SIDEDATA_ONLY_PKT = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_VDPAU_PROFILE}
const
  FF_API_VDPAU_PROFILE = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_CONVERGENCE_DURATION}
const
  FF_API_CONVERGENCE_DURATION = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_AVPICTURE}
const
  FF_API_AVPICTURE = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_AVPACKET_OLD_API}
const
  FF_API_AVPACKET_OLD_API = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_RTP_CALLBACK}
const
  FF_API_RTP_CALLBACK = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_VBV_DELAY}
const
  FF_API_VBV_DELAY = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_CODER_TYPE}
const
  FF_API_CODER_TYPE = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_STAT_BITS}
const
  FF_API_STAT_BITS = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_PRIVATE_OPT}
const
  FF_API_PRIVATE_OPT = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_ASS_TIMING}
const
  FF_API_ASS_TIMING = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_OLD_BSF}
const
  FF_API_OLD_BSF = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_COPY_CONTEXT}
const
  FF_API_COPY_CONTEXT = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_GET_CONTEXT_DEFAULTS}
const
  FF_API_GET_CONTEXT_DEFAULTS = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_NVENC_OLD_NAME}
const
  FF_API_NVENC_OLD_NAME = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_STRUCT_VAAPI_CONTEXT}
const
  FF_API_STRUCT_VAAPI_CONTEXT = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_MERGE_SD_API}
const
  FF_API_MERGE_SD_API = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}
{$ifndef FF_API_TAG_STRING}
const
  FF_API_TAG_STRING = (LIBAVCODEC_VERSION_MAJOR < 59);
{$endif}

// #endif (* AVCODEC_VERSION_H *)
