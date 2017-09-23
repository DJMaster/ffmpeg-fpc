//
// avutil.h header binding for the Free Pascal Compiler aka FPC
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

// #ifndef AVUTIL_MOTION_VECTOR_H
// #define AVUTIL_MOTION_VECTOR_H

// #include <stdint.h>

type
  PAVMotionVector = ^AVMotionVector;
  AVMotionVector = record
    (**
     * Where the current macroblock comes from; negative value when it comes
     * from the past, positive value when it comes from the future.
     * XXX: set exact relative ref frame reference instead of a +/- 1 "direction".
     *)
    source: cint32;
    (**
     * Width and height of the block.
     *)
    w, h: cuint8;
    (**
     * Absolute source position. Can be outside the frame area.
     *)
    src_x, src_y: cint16;
    (**
     * Absolute destination position. Can be outside the frame area.
     *)
    dst_x, dst_y: cint16;
    (**
     * Extra flag information.
     * Currently unused.
     *)
    flags: cuint64;
    (**
     * Motion vector
     * src_x = dst_x + motion_x / motion_scale
     * src_y = dst_y + motion_y / motion_scale
     *)
    motion_x, motion_y: cint32;
    motion_scale: cuint16;
  end;

// #endif (* AVUTIL_MOTION_VECTOR_H *)
