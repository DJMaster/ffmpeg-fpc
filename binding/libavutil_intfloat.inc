//
// avutil.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * Copyright (c) 2011 Mans Rullgard
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

// #ifndef AVUTIL_INTFLOAT_H
// #define AVUTIL_INTFLOAT_H

// #include <stdint.h>
// #include "attributes.h"

union av_intfloat32 {
    uint32_t i;
    float    f;
};

union av_intfloat64 {
    uint64_t i;
    double   f;
};

(**
 * Reinterpret a 32-bit integer as a float.
 *)
//TODO static av_always_inline float av_int2float(uint32_t i)
//TODO {
//TODO     union av_intfloat32 v;
//TODO     v.i = i;
//TODO     return v.f;
//TODO }

(**
 * Reinterpret a float as a 32-bit integer.
 *)
//TODO static av_always_inline uint32_t av_float2int(float f)
//TODO {
//TODO     union av_intfloat32 v;
//TODO     v.f = f;
//TODO     return v.i;
//TODO }

(**
 * Reinterpret a 64-bit integer as a double.
 *)
//TODO static av_always_inline double av_int2double(uint64_t i)
//TODO {
//TODO     union av_intfloat64 v;
//TODO     v.i = i;
//TODO     return v.f;
//TODO }

(**
 * Reinterpret a double as a 64-bit integer.
 *)
//TODO static av_always_inline uint64_t av_double2int(double f)
//TODO {
//TODO     union av_intfloat64 v;
//TODO     v.f = f;
//TODO     return v.i;
//TODO }

// #endif (* AVUTIL_INTFLOAT_H *)
