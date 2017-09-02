//
// swscale.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * Copyright (C) 2001-2011 Michael Niedermayer <michaelni@gmx.at>
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

unit swscale;

{$mode objfpc}{$H+}

interface

uses
  ctypes;

const
  LIB_SWSCALE = 'swscale-4.dll';

// #ifndef SWSCALE_SWSCALE_H
// #define SWSCALE_SWSCALE_H

(**
 * @file
 * @ingroup libsws
 * external API header
 *)

#include <stdint.h>

#include "libavutil/avutil.h"
#include "libavutil/log.h"
#include "libavutil/pixfmt.h"
#include "version.h"

(**
 * @defgroup libsws libswscale
 * Color conversion and scaling library.
 *
 * @{
 *
 * Return the LIBSWSCALE_VERSION_INT constant.
 *)
function swscale_version(): cunsigned; cdecl; external LIB_SWSCALE;

(**
 * Return the libswscale build-time configuration.
 *)
function swscale_configuration(): pchar; cdecl; external LIB_SWSCALE;

(**
 * Return the libswscale license.
 *)
function swscale_license(): pchar; cdecl; external LIB_SWSCALE;

const
(* values for the flags, the stuff on the command line is different *)
  SWS_FAST_BILINEAR = 1;
  SWS_BILINEAR = 2;
  SWS_BICUBIC = 4;
  SWS_X = 8;
  SWS_POINT = $10;
  SWS_AREA = $20;
  SWS_BICUBLIN = $40;
  SWS_GAUSS = $80;
  SWS_SINC = $100;
  SWS_LANCZOS = $200;
  SWS_SPLINE = $400;

  SWS_SRC_V_CHR_DROP_MASK = $30000;
  SWS_SRC_V_CHR_DROP_SHIFT = 16;

  SWS_PARAM_DEFAULT = 123456;

  SWS_PRINT_INFO = $1000;

//the following 3 flags are not completely implemented
//internal chrominance subsampling info
  SWS_FULL_CHR_H_INT = $2000;
//input subsampling info
  SWS_FULL_CHR_H_INP = $4000;
  SWS_DIRECT_BGR = $8000;
  SWS_ACCURATE_RND = $40000;
  SWS_BITEXACT = $80000;
  SWS_ERROR_DIFFUSION = $800000;

  SWS_MAX_REDUCE_CUTOFF = 0.002;

  SWS_CS_ITU709 = 1;
  SWS_CS_FCC = 4;
  SWS_CS_ITU601 = 5;
  SWS_CS_ITU624 = 5;
  SWS_CS_SMPTE170M = 5;
  SWS_CS_SMPTE240M = 7;
  SWS_CS_DEFAULT = 5;
  SWS_CS_BT2020 = 9;

(**
 * Return a pointer to yuv<->rgb coefficients for the given colorspace
 * suitable for sws_setColorspaceDetails().
 *
 * @param colorspace One of the SWS_CS_* macros. If invalid,
 * SWS_CS_DEFAULT is used.
 *)
function sws_getCoefficients(colorspace: cint): pcint; cdecl; external LIB_SWSCALE;

// when used for filters they must have an odd number of elements
// coeffs cannot be shared between vectors
type
  PSwsVector = ^SwsVector;
  SwsVector = record
    coeff: pcdouble; ///< pointer to the list of coefficients
    length: cint; ///< number of coefficients in the vector
  end;

// vectors can be shared
  PSwsFilter = ^SwsFilter;
  SwsFilter = record
    lumH: PSwsVector;
    lumV: PSwsVector;
    chrH: PSwsVector;
    chrV: PSwsVector;
  end;

  PSwsContext = ^SwsContext;
  SwsContext = record
  end;

(**
 * Return a positive value if pix_fmt is a supported input format, 0
 * otherwise.
 *)
function sws_isSupportedInput(pix_fmt: AVPixelFormat): cint; cdecl; external LIB_SWSCALE;

(**
 * Return a positive value if pix_fmt is a supported output format, 0
 * otherwise.
 *)
function sws_isSupportedOutput(pix_fmt: AVPixelFormat): cint; cdecl; external LIB_SWSCALE;

(**
 * @param[in]  pix_fmt the pixel format
 * @return a positive value if an endianness conversion for pix_fmt is
 * supported, 0 otherwise.
 *)
function sws_isSupportedEndiannessConversion(pix_fmt: AVPixelFormat): cint; cdecl; external LIB_SWSCALE;

(**
 * Allocate an empty SwsContext. This must be filled and passed to
 * sws_init_context(). For filling see AVOptions, options.c and
 * sws_setColorspaceDetails().
 *)
function sws_alloc_context(): PSwsContext; cdecl; external LIB_SWSCALE;

(**
 * Initialize the swscaler context sws_context.
 *
 * @return zero or positive value on success, a negative value on
 * error
 *)
//TODO av_warn_unused_result
function sws_init_context(sws_context: PSwsContext; srcFilter: PSwsFilter; dstFilter: PSwsFilter): cint; cdecl; external LIB_SWSCALE;

(**
 * Free the swscaler context swsContext.
 * If swsContext is NULL, then does nothing.
 *)
procedure sws_freeContext(swsContext: PSwsContext); cdecl; external LIB_SWSCALE;

(**
 * Allocate and return an SwsContext. You need it to perform
 * scaling/conversion operations using sws_scale().
 *
 * @param srcW the width of the source image
 * @param srcH the height of the source image
 * @param srcFormat the source image format
 * @param dstW the width of the destination image
 * @param dstH the height of the destination image
 * @param dstFormat the destination image format
 * @param flags specify which algorithm and options to use for rescaling
 * @param param extra parameters to tune the used scaler
 *              For SWS_BICUBIC param[0] and [1] tune the shape of the basis
 *              function, param[0] tunes f(1) and param[1] f´(1)
 *              For SWS_GAUSS param[0] tunes the exponent and thus cutoff
 *              frequency
 *              For SWS_LANCZOS param[0] tunes the width of the window function
 * @return a pointer to an allocated context, or NULL in case of error
 * @note this function is to be removed after a saner alternative is
 *       written
 *)
function sws_getContext(srcW: cint; srcH: cint; srcFormat: AVPixelFormat; dstW: cint; dstH: cint; dstFormat: AVPixelFormat; flags: cint; srcFilter: PSwsFilter; dstFilter: PSwsFilter; const param: pcdouble): PSwsContext; cdecl; external LIB_SWSCALE;

(**
 * Scale the image slice in srcSlice and put the resulting scaled
 * slice in the image in dst. A slice is a sequence of consecutive
 * rows in an image.
 *
 * Slices have to be provided in sequential order, either in
 * top-bottom or bottom-top order. If slices are provided in
 * non-sequential order the behavior of the function is undefined.
 *
 * @param c         the scaling context previously created with
 *                  sws_getContext()
 * @param srcSlice  the array containing the pointers to the planes of
 *                  the source slice
 * @param srcStride the array containing the strides for each plane of
 *                  the source image
 * @param srcSliceY the position in the source image of the slice to
 *                  process, that is the number (counted starting from
 *                  zero) in the image of the first row of the slice
 * @param srcSliceH the height of the source slice, that is the number
 *                  of rows in the slice
 * @param dst       the array containing the pointers to the planes of
 *                  the destination image
 * @param dstStride the array containing the strides for each plane of
 *                  the destination image
 * @return          the height of the output slice
 *)
function sws_scale(c: PSwsContext; const srcSlice: array of pcuint8; const srcStride: array of cint; srcSliceY: cint; srcSliceH: cint; dst: array of pcuint8; const dstStride: array of cint): cint; cdecl; external LIB_SWSCALE;

(**
 * @param dstRange flag indicating the while-black range of the output (1=jpeg / 0=mpeg)
 * @param srcRange flag indicating the while-black range of the input (1=jpeg / 0=mpeg)
 * @param table the yuv2rgb coefficients describing the output yuv space, normally ff_yuv2rgb_coeffs[x]
 * @param inv_table the yuv2rgb coefficients describing the input yuv space, normally ff_yuv2rgb_coeffs[x]
 * @param brightness 16.16 fixed point brightness correction
 * @param contrast 16.16 fixed point contrast correction
 * @param saturation 16.16 fixed point saturation correction
 * @return -1 if not supported
 *)
function sws_setColorspaceDetails(c: PSwsContext; const inv_table: array[0..3] of cint; srcRange: cint; const table: array[0..3] of cint; dstRange: cint; brightness: cint; contrast: cint; saturation: cint): cint; cdecl; external LIB_SWSCALE;

(**
 * @return -1 if not supported
 *)
function sws_getColorspaceDetails(c: PSwsContext; inv_table: ppcint; srcRange: pcint; table: ppcint; dstRange: pcint; brightness: pcint; contrast: pcint; saturation: pcint): cint; cdecl; external LIB_SWSCALE;

(**
 * Allocate and return an uninitialized vector with length coefficients.
 *)
function sws_allocVec(length: cint): PSwsVector; cdecl; external LIB_SWSCALE;

(**
 * Return a normalized Gaussian curve used to filter stuff
 * quality = 3 is high quality, lower is lower quality.
 *)
function sws_getGaussianVec(variance: cdouble; quality: cdouble): PSwsVector; cdecl; external LIB_SWSCALE;

(**
 * Scale all the coefficients of a by the scalar value.
 *)
procedure sws_scaleVec(a: PSwsVector; scalar: cdouble); cdecl; external LIB_SWSCALE;

(**
 * Scale all the coefficients of a so that their sum equals height.
 *)
procedure sws_normalizeVec(a: PSwsVector; height: cdouble); cdecl; external LIB_SWSCALE;

{$if FF_API_SWS_VECTOR}
//TODO attribute_deprecated
function sws_getConstVec(c: cdouble; length: cint): PSwsVector; cdecl; external LIB_SWSCALE;
//TODO attribute_deprecated
function sws_getIdentityVec(): PSwsVector; cdecl; external LIB_SWSCALE;
//TODO attribute_deprecated
procedure sws_convVec(a: PSwsVector; b: PSwsVector); cdecl; external LIB_SWSCALE;
//TODO attribute_deprecated
procedure sws_addVec(a: PSwsVector; b: PSwsVector); cdecl; external LIB_SWSCALE;
//TODO attribute_deprecated
procedure sws_subVec(a: PSwsVector; b: PSwsVector); cdecl; external LIB_SWSCALE;
//TODO attribute_deprecated
procedure sws_shiftVec(a: PSwsVector; shift: cint); cdecl; external LIB_SWSCALE;
//TODO attribute_deprecated
function sws_cloneVec(a: PSwsVector): PSwsVector; cdecl; external LIB_SWSCALE;
//TODO attribute_deprecated
procedure sws_printVec2(a: PSwsVector; log_ctx: PAVClass; log_level: cint); cdecl; external LIB_SWSCALE;
{$endif}

procedure sws_freeVec(a: PSwsVector); cdecl; external LIB_SWSCALE;

function sws_getDefaultFilter(lumaGBlur: cfloat; chromaGBlur: cfloat; lumaSharpen: cfloat; chromaSharpen: float; chromaHShift: cfloat; chromaVShift: float; verbose: cint): PSwsFilter; cdecl; external LIB_SWSCALE;
procedure sws_freeFilter(filter: PSwsFilter); cdecl; external LIB_SWSCALE;

(**
 * Check if context can be reused, otherwise reallocate a new one.
 *
 * If context is NULL, just calls sws_getContext() to get a new
 * context. Otherwise, checks if the parameters are the ones already
 * saved in context. If that is the case, returns the current
 * context. Otherwise, frees context and gets a new context with
 * the new parameters.
 *
 * Be warned that srcFilter and dstFilter are not checked, they
 * are assumed to remain the same.
 *)
function sws_getCachedContext(context: PSwsContext; srcW: cint; srcH: cint; srcFormat: AVPixelFormat; dstW: cint; dstH: cint; dstFormat: AVPixelFormat; flags: cint; srcFilter: PSwsFilter; dstFilter: PSwsFilter; const param: pcdouble ): PSwsContext; cdecl; external LIB_SWSCALE;

(**
 * Convert an 8-bit paletted frame into a frame with a color depth of 32 bits.
 *
 * The output frame will have the same packed format as the palette.
 *
 * @param src        source frame buffer
 * @param dst        destination frame buffer
 * @param num_pixels number of pixels to convert
 * @param palette    array with [256] entries, which must match color arrangement (RGB or BGR) of src
 *)
procedure sws_convertPalette8ToPacked32(const src: pcuint8; dst: pcuint8; num_pixels: cint; const palette: pcuint8); cdecl; external LIB_SWSCALE;

(**
 * Convert an 8-bit paletted frame into a frame with a color depth of 24 bits.
 *
 * With the palette format "ABCD", the destination frame ends up with the format "ABC".
 *
 * @param src        source frame buffer
 * @param dst        destination frame buffer
 * @param num_pixels number of pixels to convert
 * @param palette    array with [256] entries, which must match color arrangement (RGB or BGR) of src
 *)
procedure sws_convertPalette8ToPacked24(const src: pcuint8; dst: pcuint8; num_pixels: cint; const palette: pcuint8); cdecl; external LIB_SWSCALE;

(**
 * Get the AVClass for swsContext. It can be used in combination with
 * AV_OPT_SEARCH_FAKE_OBJ for examining options.
 *
 * @see av_opt_find().
 *)
function sws_get_class(): PAVClass; cdecl; external LIB_SWSCALE;

(**
 * @}
 *)

// #endif (* SWSCALE_SWSCALE_H *)

implementation

end.

