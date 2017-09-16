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

(**
 * @file
 * common internal and external API header
 *)

// #ifndef AVUTIL_COMMON_H
// #define AVUTIL_COMMON_H

// #if defined(__cplusplus) && !defined(__STDC_CONSTANT_MACROS) && !defined(UINT64_C)
// #error missing -D__STDC_CONSTANT_MACROS / #define __STDC_CONSTANT_MACROS
// #endif

// #include <errno.h>
// #include <inttypes.h>
// #include <limits.h>
// #include <math.h>
// #include <stdint.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #include "attributes.h"
// #include "macros.h"
// #include "version.h"
// #include "libavutil/avconfig.h"

//TODO #if AV_HAVE_BIGENDIAN
//TODO #   define AV_NE(be, le) (be)
//TODO #else
//TODO #   define AV_NE(be, le) (le)
//TODO #endif

//rounded division & shift
//TODO #define RSHIFT(a,b) ((a) > 0 ? ((a) + ((1<<(b))>>1))>>(b) : ((a) + ((1<<(b))>>1)-1)>>(b))
(* assume b>0 *)
//TODO #define ROUNDED_DIV(a,b) (((a)>0 ? (a) + ((b)>>1) : (a) - ((b)>>1))/(b))
(* Fast a/(1<<b) rounded toward +inf. Assume a>=0 and b>=0 *)
//TODO #define AV_CEIL_RSHIFT(a,b) (!av_builtin_constant_p(b) ? -((-(a)) >> (b)) \
//TODO                                                        : ((a) + (1<<(b)) - 1) >> (b))
(* Backwards compat. *)
//TODO #define FF_CEIL_RSHIFT AV_CEIL_RSHIFT

//TODO #define FFUDIV(a,b) (((a)>0 ?(a):(a)-(b)+1) / (b))
//TODO #define FFUMOD(a,b) ((a)-(b)*FFUDIV(a,b))

(**
 * Absolute value, Note, INT_MIN / INT64_MIN result in undefined behavior as they
 * are not representable as absolute values of their type. This is the same
 * as with *abs()
 * @see FFNABS()
 *)
//TODO #define FFABS(a) ((a) >= 0 ? (a) : (-(a)))
//TODO #define FFSIGN(a) ((a) > 0 ? 1 : -1)

(**
 * Negative Absolute value.
 * this works for all integers of all types.
 * As with many macros, this evaluates its argument twice, it thus must not have
 * a sideeffect, that is FFNABS(x++) has undefined behavior.
 *)
//TODO #define FFNABS(a) ((a) <= 0 ? (a) : (-(a)))

(**
 * Comparator.
 * For two numerical expressions x and y, gives 1 if x > y, -1 if x < y, and 0
 * if x == y. This is useful for instance in a qsort comparator callback.
 * Furthermore, compilers are able to optimize this to branchless code, and
 * there is no risk of overflow with signed types.
 * As with many macros, this evaluates its argument multiple times, it thus
 * must not have a side-effect.
 *)
//TODO #define FFDIFFSIGN(x,y) (((x)>(y)) - ((x)<(y)))

//TODO #define FFMAX(a,b) ((a) > (b) ? (a) : (b))
//TODO #define FFMAX3(a,b,c) FFMAX(FFMAX(a,b),c)
//TODO #define FFMIN(a,b) ((a) > (b) ? (b) : (a))
//TODO #define FFMIN3(a,b,c) FFMIN(FFMIN(a,b),c)

//TODO #define FFSWAP(type,a,b) do{type SWAP_tmp= b; b= a; a= SWAP_tmp;}while(0)
//TODO #define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))

(* misc math functions *)

//TODO #ifdef HAVE_AV_CONFIG_H
//TODO #   include "config.h"
//TODO #   include "intmath.h"
//TODO #endif

(* Pull in unguarded fallback defines at the end of this file. *)
// #include "common.h"

{$ifndef av_log2}
function av_log2(v: cunsigned): cint; cdecl; external LIB_AVUTIL;
{$endif}

{$ifndef av_log2_16bit}
function av_log2_16bit(v: cunsigned): cint; cdecl; external LIB_AVUTIL;
{$endif}

(**
 * Clip a signed integer value into the amin-amax range.
 * @param a value to clip
 * @param amin minimum value of the clip range
 * @param amax maximum value of the clip range
 * @return clipped value
 *)
//TODO av_always_inline av_const int av_clip_c(int a, int amin, int amax)
//TODO {
//TODO #if defined(HAVE_AV_CONFIG_H) && defined(ASSERT_LEVEL) && ASSERT_LEVEL >= 2
//TODO     if (amin > amax) abort();
//TODO #endif
//TODO     if      (a < amin) return amin;
//TODO     else if (a > amax) return amax;
//TODO     else               return a;
//TODO }

(**
 * Clip a signed 64bit integer value into the amin-amax range.
 * @param a value to clip
 * @param amin minimum value of the clip range
 * @param amax maximum value of the clip range
 * @return clipped value
 *)
//TODO static av_always_inline av_const int64_t av_clip64_c(int64_t a, int64_t amin, int64_t amax)
//TODO {
//TODO #if defined(HAVE_AV_CONFIG_H) && defined(ASSERT_LEVEL) && ASSERT_LEVEL >= 2
//TODO     if (amin > amax) abort();
//TODO #endif
//TODO     if      (a < amin) return amin;
//TODO     else if (a > amax) return amax;
//TODO     else               return a;
//TODO }

(**
 * Clip a signed integer value into the 0-255 range.
 * @param a value to clip
 * @return clipped value
 *)
//TODO static av_always_inline av_const uint8_t av_clip_uint8_c(int a)
//TODO {
//TODO     if (a&(~0xFF)) return (-a)>>31;
//TODO     else           return a;
//TODO }

(**
 * Clip a signed integer value into the -128,127 range.
 * @param a value to clip
 * @return clipped value
 *)
//TODO static av_always_inline av_const int8_t av_clip_int8_c(int a)
//TODO {
//TODO     if ((a+0x80U) & ~0xFF) return (a>>31) ^ $7F;
//TODO     else                  return a;
//TODO }

(**
 * Clip a signed integer value into the 0-65535 range.
 * @param a value to clip
 * @return clipped value
 *)
//TODO static av_always_inline av_const uint16_t av_clip_uint16_c(int a)
//TODO {
//TODO     if (a&(~0xFFFF)) return (-a)>>31;
//TODO     else             return a;
//TODO }

(**
 * Clip a signed integer value into the -32768,32767 range.
 * @param a value to clip
 * @return clipped value
 *)
//TODO static av_always_inline av_const int16_t av_clip_int16_c(int a)
//TODO {
//TODO     if ((a+0x8000U) & ~0xFFFF) return (a>>31) ^ 0x7FFF;
//TODO     else                      return a;
//TODO }

(**
 * Clip a signed 64-bit integer value into the -2147483648,2147483647 range.
 * @param a value to clip
 * @return clipped value
 *)
//TODO static av_always_inline av_const int32_t av_clipl_int32_c(int64_t a)
//TODO {
//TODO     if ((a+0x80000000u) & ~UINT64_C(0xFFFFFFFF)) return (int32_t)((a>>63) ^ 0x7FFFFFFF);
//TODO     else                                         return (int32_t)a;
//TODO }

(**
 * Clip a signed integer into the -(2^p),(2^p-1) range.
 * @param  a value to clip
 * @param  p bit position to clip at
 * @return clipped value
 *)
//TODO static av_always_inline av_const int av_clip_intp2_c(int a, int p)
//TODO {
//TODO     if (((unsigned)a + (1 << p)) & ~((2 << p) - 1))
//TODO         return (a >> 31) ^ ((1 << p) - 1);
//TODO     else
//TODO         return a;
//TODO }

(**
 * Clip a signed integer to an unsigned power of two range.
 * @param  a value to clip
 * @param  p bit position to clip at
 * @return clipped value
 *)
//TODO static av_always_inline av_const unsigned av_clip_uintp2_c(int a, int p)
//TODO {
//TODO     if (a & ~((1<<p) - 1)) return -a >> 31 & ((1<<p) - 1);
//TODO     else                   return  a;
//TODO }

(**
 * Clear high bits from an unsigned integer starting with specific bit position
 * @param  a value to clip
 * @param  p bit position to clip at
 * @return clipped value
 *)
//TODO static av_always_inline av_const unsigned av_mod_uintp2_c(unsigned a, unsigned p)
//TODO {
//TODO     return a & ((1 << p) - 1);
//TODO }

(**
 * Add two signed 32-bit values with saturation.
 *
 * @param  a one value
 * @param  b another value
 * @return sum with signed saturation
 *)
//TODO static av_always_inline int av_sat_add32_c(int a, int b)
//TODO {
//TODO     return av_clipl_int32((int64_t)a + b);
//TODO }

(**
 * Add a doubled value to another value with saturation at both stages.
 *
 * @param  a first value
 * @param  b value doubled and added to a
 * @return sum with signed saturation
 *)
//TODO static av_always_inline int av_sat_dadd32_c(int a, int b)
//TODO {
//TODO     return av_sat_add32(a, av_sat_add32(b, b));
//TODO }

(**
 * Clip a float value into the amin-amax range.
 * @param a value to clip
 * @param amin minimum value of the clip range
 * @param amax maximum value of the clip range
 * @return clipped value
 *)
//TODO static av_always_inline av_const float av_clipf_c(float a, float amin, float amax)
//TODO {
//TODO #if defined(HAVE_AV_CONFIG_H) && defined(ASSERT_LEVEL) && ASSERT_LEVEL >= 2
//TODO     if (amin > amax) abort();
//TODO #endif
//TODO     if      (a < amin) return amin;
//TODO     else if (a > amax) return amax;
//TODO     else               return a;
//TODO }

(**
 * Clip a double value into the amin-amax range.
 * @param a value to clip
 * @param amin minimum value of the clip range
 * @param amax maximum value of the clip range
 * @return clipped value
 *)
//TODO static av_always_inline av_const double av_clipd_c(double a, double amin, double amax)
//TODO {
//TODO #if defined(HAVE_AV_CONFIG_H) && defined(ASSERT_LEVEL) && ASSERT_LEVEL >= 2
//TODO     if (amin > amax) abort();
//TODO #endif
//TODO     if      (a < amin) return amin;
//TODO     else if (a > amax) return amax;
//TODO     else               return a;
//TODO }

(** Compute ceil(log2(x)).
 * @param x value used to compute ceil(log2(x))
 * @return computed ceiling of log2(x)
 *)
//TODO static av_always_inline av_const int av_ceil_log2_c(int x)
//TODO {
//TODO     return av_log2((x - 1) << 1);
//TODO }

(**
 * Count number of bits set to one in x
 * @param x value to count bits of
 * @return the number of bits set to one in x
 *)
//TODO static av_always_inline av_const int av_popcount_c(uint32_t x)
//TODO {
//TODO     x -= (x >> 1) & 0x55555555;
//TODO     x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
//TODO     x = (x + (x >> 4)) & 0x0F0F0F0F;
//TODO     x += x >> 8;
//TODO     return (x + (x >> 16)) & 0x3F;
//TODO }

(**
 * Count number of bits set to one in x
 * @param x value to count bits of
 * @return the number of bits set to one in x
 *)
//TODO static av_always_inline av_const int av_popcount64_c(uint64_t x)
//TODO {
//TODO     return av_popcount((uint32_t)x) + av_popcount((uint32_t)(x >> 32));
//TODO }

//TODO static av_always_inline av_const int av_parity_c(uint32_t v)
//TODO {
//TODO     return av_popcount(v) & 1;
//TODO }

//TODO #define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
//TODO #define MKBETAG(a,b,c,d) ((d) | ((c) << 8) | ((b) << 16) | ((unsigned)(a) << 24))

(**
 * Convert a UTF-8 character (up to 4 bytes) to its 32-bit UCS-4 encoded form.
 *
 * @param val      Output value, must be an lvalue of type uint32_t.
 * @param GET_BYTE Expression reading one byte from the input.
 *                 Evaluated up to 7 times (4 for the currently
 *                 assigned Unicode range).  With a memory buffer
 *                 input, this could be *ptr++.
 * @param ERROR    Expression to be evaluated on invalid input,
 *                 typically a goto statement.
 *
 * @warning ERROR should not contain a loop control statement which
 * could interact with the internal while loop, and should force an
 * exit from the macro code (e.g. through a goto or a return) in order
 * to prevent undefined results.
 *)
//TODO #define GET_UTF8(val, GET_BYTE, ERROR)\
//TODO     val= (GET_BYTE);\
//TODO     {\
//TODO         uint32_t top = (val & 128) >> 1;\
//TODO         if ((val & 0xc0) == $80 || val >= $FE)\
//TODO             ERROR\
//TODO         while (val & top) {\
//TODO             int tmp= (GET_BYTE) - 128;\
//TODO             if(tmp>>6)\
//TODO                 ERROR\
//TODO             val= (val<<6) + tmp;\
//TODO             top <<= 5;\
//TODO         }\
//TODO         val &= (top << 1) - 1;\
//TODO     }

(**
 * Convert a UTF-16 character (2 or 4 bytes) to its 32-bit UCS-4 encoded form.
 *
 * @param val       Output value, must be an lvalue of type uint32_t.
 * @param GET_16BIT Expression returning two bytes of UTF-16 data converted
 *                  to native byte order.  Evaluated one or two times.
 * @param ERROR     Expression to be evaluated on invalid input,
 *                  typically a goto statement.
 *)
//TODO #define GET_UTF16(val, GET_16BIT, ERROR)\
//TODO     val = GET_16BIT;\
//TODO     {\
//TODO         unsigned int hi = val - 0xD800;\
//TODO         if (hi < 0x800) {\
//TODO             val = GET_16BIT - 0xDC00;\
//TODO             if (val > 0x3FFU || hi > 0x3FFU)\
//TODO                 ERROR\
//TODO             val += (hi<<10) + 0x10000;\
//TODO         }\
//TODO     }\

(**
 * @def PUT_UTF8(val, tmp, PUT_BYTE)
 * Convert a 32-bit Unicode character to its UTF-8 encoded form (up to 4 bytes long).
 * @param val is an input-only argument and should be of type uint32_t. It holds
 * a UCS-4 encoded Unicode character that is to be converted to UTF-8. If
 * val is given as a function it is executed only once.
 * @param tmp is a temporary variable and should be of type uint8_t. It
 * represents an intermediate value during conversion that is to be
 * output by PUT_BYTE.
 * @param PUT_BYTE writes the converted UTF-8 bytes to any proper destination.
 * It could be a function or a statement, and uses tmp as the input byte.
 * For example, PUT_BYTE could be "*output++ = tmp;" PUT_BYTE will be
 * executed up to 4 times for values in the valid UTF-8 range and up to
 * 7 times in the general case, depending on the length of the converted
 * Unicode character.
 *)
//TODO #define PUT_UTF8(val, tmp, PUT_BYTE)\
//TODO     {\
//TODO         int bytes, shift;\
//TODO         uint32_t in = val;\
//TODO         if (in < 0x80) {\
//TODO             tmp = in;\
//TODO             PUT_BYTE\
//TODO         } else {\
//TODO             bytes = (av_log2(in) + 4) / 5;\
//TODO             shift = (bytes - 1) * 6;\
//TODO             tmp = (256 - (256 >> bytes)) | (in >> shift);\
//TODO             PUT_BYTE\
//TODO             while (shift >= 6) {\
//TODO                 shift -= 6;\
//TODO                 tmp = $80 | ((in >> shift) & 0x3f);\
//TODO                 PUT_BYTE\
//TODO             }\
//TODO         }\
//TODO     }

(**
 * @def PUT_UTF16(val, tmp, PUT_16BIT)
 * Convert a 32-bit Unicode character to its UTF-16 encoded form (2 or 4 bytes).
 * @param val is an input-only argument and should be of type uint32_t. It holds
 * a UCS-4 encoded Unicode character that is to be converted to UTF-16. If
 * val is given as a function it is executed only once.
 * @param tmp is a temporary variable and should be of type uint16_t. It
 * represents an intermediate value during conversion that is to be
 * output by PUT_16BIT.
 * @param PUT_16BIT writes the converted UTF-16 data to any proper destination
 * in desired endianness. It could be a function or a statement, and uses tmp
 * as the input byte.  For example, PUT_BYTE could be "*output++ = tmp;"
 * PUT_BYTE will be executed 1 or 2 times depending on input character.
 *)
//TODO #define PUT_UTF16(val, tmp, PUT_16BIT)\
//TODO     {\
//TODO         uint32_t in = val;\
//TODO         if (in < 0x10000) {\
//TODO             tmp = in;\
//TODO             PUT_16BIT\
//TODO         } else {\
//TODO             tmp = $D800 | ((in - 0x10000) >> 10);\
//TODO             PUT_16BIT\
//TODO             tmp = $DC00 | ((in - 0x10000) & 0x3FF);\
//TODO             PUT_16BIT\
//TODO         }\
//TODO     }\

// #include "mem.h"

{$ifdef HAVE_AV_CONFIG_H}
// #    include "internal.h"
{$endif} (* HAVE_AV_CONFIG_H *)

// #endif (* AVUTIL_COMMON_H *)

(*
 * The following definitions are outside the multiple inclusion guard
 * to ensure they are immediately available in intmath.h.
 *)

{$ifndef av_ceil_log2}
{$define av_ceil_log2 := av_ceil_log2_c}
{$endif}
{$ifndef av_clip}
{$define av_clip := av_clip_c}
{$endif}
{$ifndef av_clip64}
{$define av_clip64 := av_clip64_c}
{$endif}
{$ifndef av_clip_uint8}
{$define av_clip_uint8 := av_clip_uint8_c}
{$endif}
{$ifndef av_clip_int8}
{$define av_clip_int8 := av_clip_int8_c}
{$endif}
{$ifndef av_clip_uint16}
{$define av_clip_uint16 := av_clip_uint16_c}
{$endif}
{$ifndef av_clip_int16}
{$define av_clip_int16 := av_clip_int16_c}
{$endif}
{$ifndef av_clipl_int32}
{$define av_clipl_int32 := av_clipl_int32_c}
{$endif}
{$ifndef av_clip_intp2}
{$define av_clip_intp2 := av_clip_intp2_c}
{$endif}
{$ifndef av_clip_uintp2}
{$define av_clip_uintp2 := av_clip_uintp2_c}
{$endif}
{$ifndef av_mod_uintp2}
{$define av_mod_uintp2 := av_mod_uintp2_c}
{$endif}
{$ifndef av_sat_add32}
{$define av_sat_add32 := av_sat_add32_c}
{$endif}
{$ifndef av_sat_dadd32}
{$define av_sat_dadd32 := av_sat_dadd32_c}
{$endif}
{$ifndef av_clipf}
{$define av_clipf := av_clipf_c}
{$endif}
{$ifndef av_clipd}
{$define av_clipd := av_clipd_c}
{$endif}
{$ifndef av_popcount}
{$define av_popcount := av_popcount_c}
{$endif}
{$ifndef av_popcount64}
{$define av_popcount64 := av_popcount64_c}
{$endif}
{$ifndef av_parity}
{$define av_parity := av_parity_c}
{$endif}
