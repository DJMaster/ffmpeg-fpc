//
// avutil.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * RC4 encryption/decryption/pseudo-random number generator
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

// #ifndef AVUTIL_RC4_H
// #define AVUTIL_RC4_H

// #include <stdint.h>

(**
 * @defgroup lavu_rc4 RC4
 * @ingroup lavu_crypto
 * @{
 *)

type
  PAVRC4 = ^AVRC4;
  AVRC4 = record
    state: array[0..255] of cuint8;
    x, y: cint;
  end;

(**
 * Allocate an AVRC4 context.
 *)
function av_rc4_alloc(): PAVRC4; cdecl; external LIB_AVUTIL;

(**
 * @brief Initializes an AVRC4 context.
 *
 * @param key_bits must be a multiple of 8
 * @param decrypt 0 for encryption, 1 for decryption, currently has no effect
 * @return zero on success, negative value otherwise
 *)
function av_rc4_init(d: PAVRC4; const key: pcuint8; key_bits: cint; decrypt: cint): cint; cdecl; external LIB_AVUTIL;

(**
 * @brief Encrypts / decrypts using the RC4 algorithm.
 *
 * @param count number of bytes
 * @param dst destination array, can be equal to src
 * @param src source array, can be equal to dst, may be NULL
 * @param iv not (yet) used for RC4, should be NULL
 * @param decrypt 0 for encryption, 1 for decryption, not (yet) used
 *)
procedure av_rc4_crypt(d: PAVRC4; dst: pcuint8; const src: pcuint8; count: cint; iv: pcuint8; decrypt: cint); cdecl; external LIB_AVUTIL;

(**
 * @}
 *)

// #endif (* AVUTIL_RC4_H *)
