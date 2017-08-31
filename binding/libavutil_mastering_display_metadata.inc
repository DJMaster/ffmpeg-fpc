//
// avutil.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(**
 * Copyright (c) 2016 Neil Birkbeck <neil.birkbeck@gmail.com>
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

// #ifndef AVUTIL_MASTERING_DISPLAY_METADATA_H
// #define AVUTIL_MASTERING_DISPLAY_METADATA_H

// #include "frame.h"
// #include "rational.h"

(**
 * Mastering display metadata capable of representing the color volume of
 * the display used to master the content (SMPTE 2086:2014).
 *
 * To be used as payload of a AVFrameSideData or AVPacketSideData with the
 * appropriate type.
 *
 * @note The struct should be allocated with av_mastering_display_metadata_alloc()
 *       and its size is not a part of the public ABI.
 *)
type
  PAVMasteringDisplayMetadata = ^AVMasteringDisplayMetadata;
  AVMasteringDisplayMetadata = record
    (**
     * CIE 1931 xy chromaticity coords of color primaries (r, g, b order).
     *)
    display_primaries: array[0..2][0..1] of AVRational;

    (**
     * CIE 1931 xy chromaticity coords of white point.
     *)
    white_point: array[0..1] of AVRational;

    (**
     * Min luminance of mastering display (cd/m^2).
     *)
    min_luminance: AVRational;

    (**
     * Max luminance of mastering display (cd/m^2).
     *)
    max_luminance: AVRational;

    (**
     * Flag indicating whether the display primaries (and white point) are set.
     *)
    has_primaries: cint;

    (**
     * Flag indicating whether the luminance (min_ and max_) have been set.
     *)
    has_luminance: cint;
  end;

(**
 * Allocate an AVMasteringDisplayMetadata structure and set its fields to
 * default values. The resulting struct can be freed using av_freep().
 *
 * @return An AVMasteringDisplayMetadata filled with default values or NULL
 *         on failure.
 *)
function av_mastering_display_metadata_alloc(): PAVMasteringDisplayMetadata; cdecl; external LIB_AVUTIL;

(**
 * Allocate a complete AVMasteringDisplayMetadata and add it to the frame.
 *
 * @param frame The frame which side data is added to.
 *
 * @return The AVMasteringDisplayMetadata structure to be filled by caller.
 *)
function av_mastering_display_metadata_create_side_data(frame: PAVFrame): PAVMasteringDisplayMetadata; cdecl; external LIB_AVUTIL;

// #endif (* AVUTIL_MASTERING_DISPLAY_METADATA_H *)
