//
// avutil.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * A 32-bit implementation of the XTEA algorithm
 * Copyright (c) 2012 Samuel Pitoiset
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

// #ifndef AVUTIL_XTEA_H
// #define AVUTIL_XTEA_H

#include <stdint.h>

(**
 * @file
 * @brief Public header for libavutil XTEA algorithm
 * @defgroup lavu_xtea XTEA
 * @ingroup lavu_crypto
 * @{
 *)

type
  PAVXTEA = ^AVXTEA;
  AVXTEA = record
    key: array[0..15] of cuint32;
  end;

(**
 * Allocate an AVXTEA context.
 *)
function av_xtea_alloc(): PAVXTEA;

(**
 * Initialize an AVXTEA context.
 *
 * @param ctx an AVXTEA context
 * @param key a key of 16 bytes used for encryption/decryption,
 *            interpreted as big endian 32 bit numbers
 *)
procedure av_xtea_init(ctx: PAVXTEA; const key: array[0..15] of cuint8);

(**
 * Initialize an AVXTEA context.
 *
 * @param ctx an AVXTEA context
 * @param key a key of 16 bytes used for encryption/decryption,
 *            interpreted as little endian 32 bit numbers
 *)
procedure av_xtea_le_init(ctx: PAVXTEA; const key: array[0..15] of cuint8);

(**
 * Encrypt or decrypt a buffer using a previously initialized context,
 * in big endian format.
 *
 * @param ctx an AVXTEA context
 * @param dst destination array, can be equal to src
 * @param src source array, can be equal to dst
 * @param count number of 8 byte blocks
 * @param iv initialization vector for CBC mode, if NULL then ECB will be used
 * @param decrypt 0 for encryption, 1 for decryption
 *)
procedure av_xtea_crypt(ctx: PAVXTEA; dst: pcuint8; const src: pcuint8; count: cint; iv: pcuint8; decrypt: cint);

(**
 * Encrypt or decrypt a buffer using a previously initialized context,
 * in little endian format.
 *
 * @param ctx an AVXTEA context
 * @param dst destination array, can be equal to src
 * @param src source array, can be equal to dst
 * @param count number of 8 byte blocks
 * @param iv initialization vector for CBC mode, if NULL then ECB will be used
 * @param decrypt 0 for encryption, 1 for decryption
 *)
procedure av_xtea_le_crypt(ctx: PAVXTEA; dst: pcuint8; const src: pcuint8; count: cint; iv: pcuint8; decrypt: cint);

(**
 * @}
 *)

// #endif (* AVUTIL_XTEA_H *)
