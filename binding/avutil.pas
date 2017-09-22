//
// avutil.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
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

unit avutil;

{$mode objfpc}{$H+}
{$macro on}

interface

uses
  ctypes;

type
  pppcuint8 = ^ppcuint8;
  ppcuint8 = ^pcuint8;

const
  LIB_AVUTIL = 'avutil-55.dll';

// #ifndef AVUTIL_AVUTIL_H
// #define AVUTIL_AVUTIL_H

{$include libavutil_rational.inc}

(**
 * @file
 * @ingroup lavu
 * Convenience header that includes @ref lavu "libavutil"'s core.
 *)

(**
 * @mainpage
 *
 * @section ffmpeg_intro Introduction
 *
 * This document describes the usage of the different libraries
 * provided by FFmpeg.
 *
 * @li @ref libavc "libavcodec" encoding/decoding library
 * @li @ref lavfi "libavfilter" graph-based frame editing library
 * @li @ref libavf "libavformat" I/O and muxing/demuxing library
 * @li @ref lavd "libavdevice" special devices muxing/demuxing library
 * @li @ref lavu "libavutil" common utility library
 * @li @ref lswr "libswresample" audio resampling, format conversion and mixing
 * @li @ref lpp  "libpostproc" post processing library
 * @li @ref libsws "libswscale" color conversion and scaling library
 *
 * @section ffmpeg_versioning Versioning and compatibility
 *
 * Each of the FFmpeg libraries contains a version.h header, which defines a
 * major, minor and micro version number with the
 * <em>LIBRARYNAME_VERSION_{MAJOR,MINOR,MICRO}</em> macros. The major version
 * number is incremented with backward incompatible changes - e.g. removing
 * parts of the public API, reordering public struct members, etc. The minor
 * version number is incremented for backward compatible API changes or major
 * new features - e.g. adding a new public function or a new decoder. The micro
 * version number is incremented for smaller changes that a calling program
 * might still want to check for - e.g. changing behavior in a previously
 * unspecified situation.
 *
 * FFmpeg guarantees backward API and ABI compatibility for each library as long
 * as its major version number is unchanged. This means that no public symbols
 * will be removed or renamed. Types and names of the public struct members and
 * values of public macros and enums will remain the same (unless they were
 * explicitly declared as not part of the public API). Documented behavior will
 * not change.
 *
 * In other words, any correct program that works with a given FFmpeg snapshot
 * should work just as well without any changes with any later snapshot with the
 * same major versions. This applies to both rebuilding the program against new
 * FFmpeg versions or to replacing the dynamic FFmpeg libraries that a program
 * links against.
 *
 * However, new public symbols may be added and new members may be appended to
 * public structs whose size is not part of public ABI (most public structs in
 * FFmpeg). New macros and enum values may be added. Behavior in undocumented
 * situations may change slightly (and be documented). All those are accompanied
 * by an entry in doc/APIchanges and incrementing either the minor or micro
 * version number.
 *)

(**
 * @defgroup lavu libavutil
 * Common code shared across all FFmpeg libraries.
 *
 * @note
 * libavutil is designed to be modular. In most cases, in order to use the
 * functions provided by one component of libavutil you must explicitly include
 * the specific header containing that feature. If you are only using
 * media-related components, you could simply include libavutil/avutil.h, which
 * brings in most of the "core" components.
 *
 * @{
 *
 * @defgroup lavu_crypto Crypto and Hashing
 *
 * @{
 * @}
 *
 * @defgroup lavu_math Mathematics
 * @{
 *
 * @}
 *
 * @defgroup lavu_string String Manipulation
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_mem Memory Management
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_data Data Structures
 * @{
 *
 * @}
 *
 * @defgroup lavu_video Video related
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_audio Audio related
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_error Error Codes
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_log Logging Facility
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_misc Other
 *
 * @{
 *
 * @defgroup preproc_misc Preprocessor String Macros
 *
 * @{
 *
 * @}
 *
 * @defgroup version_utils Library Version Macros
 *
 * @{
 *
 * @}
 *)

(**
 * @addtogroup lavu_ver
 * @{
 *)

(**
 * Return the LIBAVUTIL_VERSION_INT constant.
 *)
function avutil_version(): cunsigned; cdecl; external LIB_AVUTIL;

(**
 * Return an informative version string. This usually is the actual release
 * version number or a git commit description. This string has no fixed format
 * and can change any time. It should never be parsed by code.
 *)
function av_version_info(): pchar; cdecl; external LIB_AVUTIL;

(**
 * Return the libavutil build-time configuration.
 *)
function avutil_configuration(): pchar; cdecl; external LIB_AVUTIL;

(**
 * Return the libavutil license.
 *)
function avutil_license(): pchar; cdecl; external LIB_AVUTIL;

(**
 * @}
 *)

(**
 * @addtogroup lavu_media Media Type
 * @brief Media Type
 *)
type
  AVMediaType = (
    AVMEDIA_TYPE_UNKNOWN = -1, ///< Usually treated as AVMEDIA_TYPE_DATA
    AVMEDIA_TYPE_VIDEO,
    AVMEDIA_TYPE_AUDIO,
    AVMEDIA_TYPE_DATA, ///< Opaque data information usually continuous
    AVMEDIA_TYPE_SUBTITLE,
    AVMEDIA_TYPE_ATTACHMENT, ///< Opaque data information usually sparse
    AVMEDIA_TYPE_NB
  );

(**
 * Return a string describing the media_type enum, NULL if media_type
 * is unknown.
 *)
function av_get_media_type_string(media_type: AVMediaType): pchar; cdecl; external LIB_AVUTIL;

(**
 * @defgroup lavu_const Constants
 * @{
 *
 * @defgroup lavu_enc Encoding specific
 *
 * @note those definition should move to avcodec
 * @{
 *)
const
  FF_LAMBDA_SHIFT = 7;
  FF_LAMBDA_SCALE = (1 shl FF_LAMBDA_SHIFT);
  FF_QP2LAMBDA = 118; ///< factor to convert from H.263 QP to lambda
  FF_LAMBDA_MAX = (256*128-1);

  FF_QUALITY_SCALE = FF_LAMBDA_SCALE; //FIXME maybe remove

(**
 * @}
 * @defgroup lavu_time Timestamp specific
 *
 * FFmpeg internal timebase and timestamp definitions
 *
 * @{
 *)

(**
 * @brief Undefined timestamp value
 *
 * Usually reported by demuxer that work on containers that do not provide
 * either pts or dts.
 *)

  AV_NOPTS_VALUE: cint64 = $8000000000000000;

(**
 * Internal time base represented as integer
 *)

  AV_TIME_BASE = 1000000;

(**
 * Internal time base represented as fractional value
 *)

  AV_TIME_BASE_Q: AVRational = (num: 1; den: AV_TIME_BASE);

(**
 * @}
 * @}
 * @defgroup lavu_picture Image related
 *
 * AVPicture types, pixel formats and basic image planes manipulation.
 *
 * @{
 *)
type
  AVPictureType = (
    AV_PICTURE_TYPE_NONE = 0, ///< Undefined
    AV_PICTURE_TYPE_I, ///< Intra
    AV_PICTURE_TYPE_P, ///< Predicted
    AV_PICTURE_TYPE_B, ///< Bi-dir predicted
    AV_PICTURE_TYPE_S, ///< S(GMC)-VOP MPEG-4
    AV_PICTURE_TYPE_SI, ///< Switching Intra
    AV_PICTURE_TYPE_SP, ///< Switching Predicted
    AV_PICTURE_TYPE_BI ///< BI type
  );

(**
 * Return a single letter to describe the given picture type
 * pict_type.
 *
 * @param[in] pict_type the picture type @return a single character
 * representing the picture type, '?' if pict_type is unknown
 *)
function av_get_picture_type_char(pict_type: AVPictureType): cchar; cdecl; external LIB_AVUTIL;

(**
 * @}
 *)

// #include "common.h"
// #include "error.h"
// #include "rational.h"
// #include "version.h"
// #include "macros.h"
// #include "mathematics.h"
// #include "log.h"
// #include "pixfmt.h"

(**
 * Return x default pointer in case p is NULL.
 *)
//TODO function av_x_if_null(const p: pointer; const x: pointer): pointer; inline;
//TODO {
//TODO     return (void *)(intptr_t)(p ? p : x);
//TODO }

(**
 * Compute the length of an integer list.
 *
 * @param elsize  size in bytes of each list element (only 1, 2, 4 or 8)
 * @param term    list terminator (usually 0 or -1)
 * @param list    pointer to the list
 * @return  length of the list, in elements, not counting the terminator
 *)
//TODO av_pure
function av_int_list_length_for_size(elsize: cunsigned; const list: pointer; term: cuint64): cunsigned; cdecl; external LIB_AVUTIL;

(**
 * Compute the length of an integer list.
 *
 * @param term  list terminator (usually 0 or -1)
 * @param list  pointer to the list
 * @return  length of the list, in elements, not counting the terminator
 *)
//TODO #define av_int_list_length(list, term) \
//TODO     av_int_list_length_for_size(sizeof(*(list)), list, term)

(**
 * Open a file using a UTF-8 filename.
 * The API of this function matches POSIX fopen(), errors are returned through
 * errno.
 *)
function av_fopen_utf8(const path_: pchar; const mode: pchar): pointer; cdecl; external LIB_AVUTIL;

(**
 * Return the fractional representation of the internal time base.
 *)
function av_get_time_base_q(): AVRational; cdecl; external LIB_AVUTIL;

const
  AV_FOURCC_MAX_STRING_SIZE = 32;

//TODO #define av_fourcc2str(fourcc) av_fourcc_make_string((char[AV_FOURCC_MAX_STRING_SIZE]){0}, fourcc)

(**
 * Fill the provided buffer with a string containing a FourCC (four-character
 * code) representation.
 *
 * @param buf    a buffer with size in bytes of at least AV_FOURCC_MAX_STRING_SIZE
 * @param fourcc the fourcc to represent
 * @return the buffer in input
 *)
function av_fourcc_make_string(buf: pchar; fourcc: cuint32): pchar; cdecl; external LIB_AVUTIL;

(**
 * @}
 * @}
 *)

// #endif (* AVUTIL_AVUTIL_H *)

{$include libavformat_avio.inc}

{$include libavutil_fifo.inc}
{$include libavutil_samplefmt.inc}

{$include libavutil_adler32.inc}
{$include libavutil_aes.inc}
{$include libavutil_aes_ctr.inc}
{$include libavutil_attributes.inc}
{$include libavutil_audio_fifo.inc}
{$include libavutil_avassert.inc}
{$include libavutil_avconfig.inc}
{$include libavutil_avstring.inc}
{$include libavutil_base64.inc}
{$include libavutil_blowfish.inc}
{$include libavutil_bprint.inc}
{$include libavutil_bswap.inc}
{$include libavutil_buffer.inc}
{$include libavutil_camellia.inc}
{$include libavutil_cast5.inc}
{$include libavutil_channel_layout.inc}
{$include libavutil_common.inc}
{$include libavutil_cpu.inc}
{$include libavutil_crc.inc}
{$include libavutil_des.inc}
{$include libavutil_dict.inc}
{$include libavutil_display.inc}
{$include libavutil_downmix_info.inc}
{$include libavutil_error.inc}
{$include libavutil_eval.inc}
{$include libavutil_ffversion.inc}
{$include libavutil_file.inc}
{$include libavutil_frame.inc}
{$include libavutil_hash.inc}
{$include libavutil_hmac.inc}
{$include libavutil_hwcontext.inc}
{$include libavutil_hwcontext_cuda.inc}
{$include libavutil_hwcontext_dxva2.inc}
{$include libavutil_hwcontext_qsv.inc}
{$include libavutil_hwcontext_vaapi.inc}
{$include libavutil_hwcontext_vdpau.inc}
{$include libavutil_imgutils.inc}
{$include libavutil_intfloat.inc}
{$include libavutil_intreadwrite.inc}
{$include libavutil_lfg.inc}
{$include libavutil_log.inc}
{$include libavutil_lzo.inc}
{$include libavutil_macros.inc}
{$include libavutil_mastering_display_metadata.inc}
{$include libavutil_mathematics.inc}
{$include libavutil_md5.inc}
{$include libavutil_mem.inc}
{$include libavutil_motion_vector.inc}
{$include libavutil_murmur3.inc}
{$include libavutil_opt.inc}
{$include libavutil_parseutils.inc}
{$include libavutil_pixdesc.inc}
{$include libavutil_pixelutils.inc}
{$include libavutil_pixfmt.inc}
{$include libavutil_random_seed.inc}
{.$include libavutil_rational.inc}
{$include libavutil_rc4.inc}
{$include libavutil_replaygain.inc}
{$include libavutil_ripemd.inc}
{$include libavutil_sha.inc}
{$include libavutil_sha512.inc}
{$include libavutil_spherical.inc}
{$include libavutil_stereo3d.inc}
{$include libavutil_tea.inc}
{$include libavutil_threadmessage.inc}
{$include libavutil_time.inc}
{$include libavutil_timecode.inc}
{$include libavutil_timestamp.inc}
{$include libavutil_tree.inc}
{$include libavutil_twofish.inc}
{$include libavutil_version.inc}
{$include libavutil_xtea.inc}

implementation

function AV_VERSION_INT(a, b, c: cint): cint;
begin
  Result := (a shl 16) or (b shl 8) or (c);
end;

function AV_VERSION_DOT(a, b, c): string;
begin
  Result := Format('%D.%D.%D', [a, b, c]);
end;

function AV_VERSION(a, b, c): string;
begin
  Result := Format('%D.%D.%D', [a, b, c]);
end;

begin
  LIBAVUTIL_VERSION_INT := AV_VERSION_INT(LIBAVUTIL_VERSION_MAJOR, LIBAVUTIL_VERSION_MINOR, LIBAVUTIL_VERSION_MICRO);
  LIBAVUTIL_VERSION := AV_VERSION(LIBAVUTIL_VERSION_MAJOR, LIBAVUTIL_VERSION_MINOR, LIBAVUTIL_VERSION_MICRO);
  LIBAVUTIL_BUILD := LIBAVUTIL_VERSION;

  LIBAVUTIL_IDENT = 'Lavu' + LIBAVUTIL_VERSION;
end.
