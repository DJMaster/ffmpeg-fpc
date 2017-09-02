//
// avutil.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * An implementation of the CAMELLIA algorithm as mentioned in RFC3713
 * Copyright (c) 2014 Supraja Meedinti
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

// #ifndef AVUTIL_CAMELLIA_H
// #define AVUTIL_CAMELLIA_H

// #include <stdint.h>

(**
  * @file
  * @brief Public header for libavutil CAMELLIA algorithm
  * @defgroup lavu_camellia CAMELLIA
  * @ingroup lavu_crypto
  * @{
  *)

extern const int av_camellia_size;

type
  PAVCAMELLIA = ^AVCAMELLIA;
  AVCAMELLIA = record
  end;

(**
  * Allocate an AVCAMELLIA context
  * To free the struct: av_free(ptr)
  *)
function av_camellia_alloc(): PAVCAMELLIA; cdecl; external LIB_AVUTIL;

(**
  * Initialize an AVCAMELLIA context.
  *
  * @param ctx an AVCAMELLIA context
  * @param key a key of 16, 24, 32 bytes used for encryption/decryption
  * @param key_bits number of keybits: possible are 128, 192, 256
 *)
function av_camellia_init(ctx: PAVCAMELLIA; const key: pcuint8; key_bits: cint): cint; cdecl; external LIB_AVUTIL;

(**
  * Encrypt or decrypt a buffer using a previously initialized context
  *
  * @param ctx an AVCAMELLIA context
  * @param dst destination array, can be equal to src
  * @param src source array, can be equal to dst
  * @param count number of 16 byte blocks
  * @paran iv initialization vector for CBC mode, NULL for ECB mode
  * @param decrypt 0 for encryption, 1 for decryption
 *)
procedure av_camellia_crypt(ctx: PAVCAMELLIA; dst: pcuint8; const src: pcuint8; count: cint; iv: pcuint8; decrypt: cint); cdecl; external LIB_AVUTIL;

(**
 * @}
 *)

// #endif (* AVUTIL_CAMELLIA_H *)
