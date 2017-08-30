//
// avutil.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * Blowfish algorithm
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

// #ifndef AVUTIL_BLOWFISH_H
// #define AVUTIL_BLOWFISH_H

#include <stdint.h>

(**
 * @defgroup lavu_blowfish Blowfish
 * @ingroup lavu_crypto
 * @{
 *)
const
  AV_BF_ROUNDS = 16;

type
  PAVBlowfish = ^AVBlowfish;
  AVBlowfish = record
    p: array[0..AV_BF_ROUNDS + 1] of uint32_t;
    s: array[0..3][0..255] of cuint32_t;
  end;

(**
 * Allocate an AVBlowfish context.
 *)
function av_blowfish_alloc(): PAVBlowfish; cdecl; external LIB_AVUTIL;

(**
 * Initialize an AVBlowfish context.
 *
 * @param ctx an AVBlowfish context
 * @param key a key
 * @param key_len length of the key
 *)
procedure av_blowfish_init(ctx: PAVBlowfish; const key: pcuint8_t; key_len: cint); cdecl; external LIB_AVUTIL;

(**
 * Encrypt or decrypt a buffer using a previously initialized context.
 *
 * @param ctx an AVBlowfish context
 * @param xl left four bytes halves of input to be encrypted
 * @param xr right four bytes halves of input to be encrypted
 * @param decrypt 0 for encryption, 1 for decryption
 *)
procedure av_blowfish_crypt_ecb(ctx: PAVBlowfish; xl: pcuint32_t; xr: pcuint32_t; decrypt: cint); cdecl; external LIB_AVUTIL;

(**
 * Encrypt or decrypt a buffer using a previously initialized context.
 *
 * @param ctx an AVBlowfish context
 * @param dst destination array, can be equal to src
 * @param src source array, can be equal to dst
 * @param count number of 8 byte blocks
 * @param iv initialization vector for CBC mode, if NULL ECB will be used
 * @param decrypt 0 for encryption, 1 for decryption
 *)
procedure av_blowfish_crypt(ctx: PAVBlowfish; dst: pcuint8_t; const src: pcuint8_t; count: cint; iv: pcuint8_t; decrypt: cint); cdecl; external LIB_AVUTIL;

(**
 * @}
 *)

// #endif (* AVUTIL_BLOWFISH_H *)
