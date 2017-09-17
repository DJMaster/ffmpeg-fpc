//
// avutil.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * DES encryption/decryption
 * Copyright (c) 2007 Reimar Doeffinger
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

// #ifndef AVUTIL_DES_H
// #define AVUTIL_DES_H

// #include <stdint.h>

(**
 * @defgroup lavu_des DES
 * @ingroup lavu_crypto
 * @{
 *)

type
  PAVDES = ^AVDES;
  AVDES = record
    round_keys: array[0..2, 0..15] of cuint64;
    triple_des: cint;
  end;

(**
 * Allocate an AVDES context.
 *)
function av_des_alloc(): PAVDES; cdecl; external LIB_AVUTIL;

(**
 * @brief Initializes an AVDES context.
 *
 * @param key_bits must be 64 or 192
 * @param decrypt 0 for encryption/CBC-MAC, 1 for decryption
 * @return zero on success, negative value otherwise
 *)
function av_des_init(d: PAVDES; const key: pcuint8; key_bits: cint; decrypt: cint): cint; cdecl; external LIB_AVUTIL;

(**
 * @brief Encrypts / decrypts using the DES algorithm.
 *
 * @param count number of 8 byte blocks
 * @param dst destination array, can be equal to src, must be 8-byte aligned
 * @param src source array, can be equal to dst, must be 8-byte aligned, may be NULL
 * @param iv initialization vector for CBC mode, if NULL then ECB will be used,
 *           must be 8-byte aligned
 * @param decrypt 0 for encryption, 1 for decryption
 *)
procedure av_des_crypt(d: PAVDES; dst: pcuint8; const src: pcuint8; count: cint; iv: pcuint8; decrypt: cint); cdecl; external LIB_AVUTIL;

(**
 * @brief Calculates CBC-MAC using the DES algorithm.
 *
 * @param count number of 8 byte blocks
 * @param dst destination array, can be equal to src, must be 8-byte aligned
 * @param src source array, can be equal to dst, must be 8-byte aligned, may be NULL
 *)
procedure av_des_mac(d: PAVDES; dst: pcuint8; const src: pcuint8; count: cint); cdecl; external LIB_AVUTIL;

(**
 * @}
 *)

// #endif (* AVUTIL_DES_H *)
