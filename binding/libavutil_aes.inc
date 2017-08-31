//
// avutil.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * copyright (c) 2007 Michael Niedermayer <michaelni@gmx.at>
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

// #ifndef AVUTIL_AES_H
// #define AVUTIL_AES_H

// #include <stdint.h>

// #include "attributes.h"
// #include "version.h"

(**
 * @defgroup lavu_aes AES
 * @ingroup lavu_crypto
 * @{
 *)

extern const int av_aes_size;

type
  PAVAES = ^AVAES;
  AVAES = record
  end;

(**
 * Allocate an AVAES context.
 *)
function av_aes_alloc(): PAVAES; cdecl; external LIB_AVUTIL;

(**
 * Initialize an AVAES context.
 * @param key_bits 128, 192 or 256
 * @param decrypt 0 for encryption, 1 for decryption
 *)
function av_aes_init(a: PAVAES; const key: pcuint8; key_bits: cint; decrypt: cint): cint; cdecl; external LIB_AVUTIL;

(**
 * Encrypt or decrypt a buffer using a previously initialized context.
 * @param count number of 16 byte blocks
 * @param dst destination array, can be equal to src
 * @param src source array, can be equal to dst
 * @param iv initialization vector for CBC mode, if NULL then ECB will be used
 * @param decrypt 0 for encryption, 1 for decryption
 *)
procedure av_aes_crypt(a: PAVAES; dst: pcuint8; const src: pcuint8; count: cint; iv: pcuint8; decrypt: cint); cdecl; external LIB_AVUTIL;

(**
 * @}
 *)

// #endif (* AVUTIL_AES_H *)
