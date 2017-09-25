//
// swresample.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * Version macros.
 *
 * This file is part of libswresample
 *
 * libswresample is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * libswresample is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with libswresample; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *)

// #ifndef SWRESAMPLE_VERSION_H
// #define SWRESAMPLE_VERSION_H

(**
 * @file
 * Libswresample version macros
 *)

// #include "libavutil/avutil.h"

const
  LIBSWRESAMPLE_VERSION_MAJOR = 2;
  LIBSWRESAMPLE_VERSION_MINOR = 7;
  LIBSWRESAMPLE_VERSION_MICRO = 100;

var
  LIBSWRESAMPLE_VERSION_INT: cint;
  LIBSWRESAMPLE_VERSION: string;
  LIBSWRESAMPLE_BUILD: string;

  LIBSWRESAMPLE_IDENT: string;

// #endif (* SWRESAMPLE_VERSION_H *)
