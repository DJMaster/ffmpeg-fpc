//
// swscale.h header binding for the Free Pascal Compiler aka FPC
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

// #ifndef SWSCALE_VERSION_H
// #define SWSCALE_VERSION_H

(**
 * @file
 * swscale version macros
 *)

// #include "libavutil/version.h"

const
  LIBSWSCALE_VERSION_MAJOR = 4;
  LIBSWSCALE_VERSION_MINOR = 6;
  LIBSWSCALE_VERSION_MICRO = 100;

var
  LIBSWSCALE_VERSION_INT: cint;
  LIBSWSCALE_VERSION: string;
  LIBSWSCALE_BUILD: string;

  LIBSWSCALE_IDENT: string;

(**
 * FF_API_* defines may be placed below to indicate public API that will be
 * dropped at a future version bump. The defines themselves are not part of
 * the public API and may change, break or disappear at any time.
 *)

{$ifndef FF_API_SWS_VECTOR}
{$define FF_API_SWS_VECTOR := (LIBSWSCALE_VERSION_MAJOR < 6)}
{$endif}

// #endif (* SWSCALE_VERSION_H *)
