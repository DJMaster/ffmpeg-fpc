//
// avutil.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * rational numbers
 * Copyright (c) 2003 Michael Niedermayer <michaelni@gmx.at>
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
 * @ingroup lavu_math_rational
 * Utilties for rational number calculation.
 * @author Michael Niedermayer <michaelni@gmx.at>
 *)

// #ifndef AVUTIL_RATIONAL_H
// #define AVUTIL_RATIONAL_H

// #include <stdint.h>
// #include <limits.h>
// #include "attributes.h"

(**
 * @defgroup lavu_math_rational AVRational
 * @ingroup lavu_math
 * Rational number calculation.
 *
 * While rational numbers can be expressed as floating-point numbers, the
 * conversion process is a lossy one, so are floating-point operations. On the
 * other hand, the nature of FFmpeg demands highly accurate calculation of
 * timestamps. This set of rational number utilities serves as a generic
 * interface for manipulating rational numbers as pairs of numerators and
 * denominators.
 *
 * Many of the functions that operate on AVRational's have the suffix `_q`, in
 * reference to the mathematical symbol "ℚ" (Q) which denotes the set of all
 * rational numbers.
 *
 * @{
 *)

(**
 * Rational number (pair of numerator and denominator).
 *)
type
  PAVRational = ^AVRational;
  AVRational = record
    num: cint; ///< Numerator
    den: cint; ///< Denominator
  end;

(**
 * Create an AVRational.
 *
 * Useful for compilers that do not support compound literals.
 *
 * @note The return value is not reduced.
 * @see av_reduce()
 *)
//TODO function av_make_q(num: cint; den: cint): AVRational; inline;
//TODO {
//TODO     AVRational r = { num, den };
//TODO     return r;
//TODO }

(**
 * Compare two rationals.
 *
 * @param a First rational
 * @param b Second rational
 *
 * @return One of the following values:
 *         - 0 if `a == b`
 *         - 1 if `a > b`
 *         - -1 if `a < b`
 *         - `INT_MIN` if one of the values is of the form `0 / 0`
 *)
function av_cmp_q(a: AVRational; b: AVRational): cint; inline;
{
    const int64_t tmp= a.num * (int64_t)b.den - b.num * (int64_t)a.den;

    if(tmp) return (int)((tmp ^ a.den ^ b.den)>>63)|1;
    else if(b.den && a.den) return 0;
    else if(a.num && b.num) return (a.num>>31) - (b.num>>31);
    else                    return INT_MIN;
}

(**
 * Convert an AVRational to a `double`.
 * @param a AVRational to convert
 * @return `a` in floating-point form
 * @see av_d2q()
 *)
function av_q2d(a: AVRational): cdouble; inline;
{
    return a.num / (double) a.den;
}

(**
 * Reduce a fraction.
 *
 * This is useful for framerate calculations.
 *
 * @param[out] dst_num Destination numerator
 * @param[out] dst_den Destination denominator
 * @param[in]      num Source numerator
 * @param[in]      den Source denominator
 * @param[in]      max Maximum allowed values for `dst_num` & `dst_den`
 * @return 1 if the operation is exact, 0 otherwise
 *)
function av_reduce(dst_num: pcint; dst_den: pcint; num: cint64; den: cint64; max: cint64): cint; cdecl; external LIB_AVUTIL;

(**
 * Multiply two rationals.
 * @param b First rational
 * @param c Second rational
 * @return b*c
 *)
//TODO av_const
function av_mul_q(b: AVRational; c: AVRational): AVRational; cdecl; external LIB_AVUTIL;

(**
 * Divide one rational by another.
 * @param b First rational
 * @param c Second rational
 * @return b/c
 *)
//TODO av_const
function av_div_q(b: AVRational; c: AVRational): AVRational; cdecl; external LIB_AVUTIL;

(**
 * Add two rationals.
 * @param b First rational
 * @param c Second rational
 * @return b+c
 *)
//TODO av_const
function av_add_q(b: AVRational; c: AVRational): AVRational; cdecl; external LIB_AVUTIL;

(**
 * Subtract one rational from another.
 * @param b First rational
 * @param c Second rational
 * @return b-c
 *)
//TODO av_const
function av_sub_q(b: AVRational; c: AVRational): AVRational; cdecl; external LIB_AVUTIL;

(**
 * Invert a rational.
 * @param q value
 * @return 1 / q
 *)
//TODO av_always_inline
//TODO function av_inv_q(q: AVRational): AVRational; inline;
//TODO {
//TODO     AVRational r = { q.den, q.num };
//TODO     return r;
//TODO }

(**
 * Convert a double precision floating point number to a rational.
 *
 * In case of infinity, the returned value is expressed as `{1, 0}` or
 * `{-1, 0}` depending on the sign.
 *
 * @param d   `double` to convert
 * @param max Maximum allowed numerator and denominator
 * @return `d` in AVRational form
 * @see av_q2d()
 *)
//TODO av_const
function av_d2q(d: cdouble; max: cint): AVRational; cdecl; external LIB_AVUTIL;

(**
 * Find which of the two rationals is closer to another rational.
 *
 * @param q     Rational to be compared against
 * @param q1,q2 Rationals to be tested
 * @return One of the following values:
 *         - 1 if `q1` is nearer to `q` than `q2`
 *         - -1 if `q2` is nearer to `q` than `q1`
 *         - 0 if they have the same distance
 *)
function av_nearer_q(q: AVRational; q1: AVRational; q2: AVRational): cint; cdecl; external LIB_AVUTIL;

(**
 * Find the value in a list of rationals nearest a given reference rational.
 *
 * @param q      Reference rational
 * @param q_list Array of rationals terminated by `{0, 0}`
 * @return Index of the nearest value found in the array
 *)
function av_find_nearest_q_idx(q: AVRational; const q_list: PAVRational): cint; cdecl; external LIB_AVUTIL;

(**
 * Convert an AVRational to a IEEE 32-bit `float` expressed in fixed-point
 * format.
 *
 * @param q Rational to be converted
 * @return Equivalent floating-point value, expressed as an unsigned 32-bit
 *         integer.
 * @note The returned value is platform-indepedant.
 *)
function av_q2intfloat(q: AVRational): cuint32; cdecl; external LIB_AVUTIL;

(**
 * @}
 *)

// #endif (* AVUTIL_RATIONAL_H *)
