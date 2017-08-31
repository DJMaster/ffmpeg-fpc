//
// avutil.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * AES-CTR cipher
 * Copyright (c) 2015 Eran Kornblau <erankor at gmail dot com>
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

// #ifndef AVUTIL_AES_CTR_H
// #define AVUTIL_AES_CTR_H

// #include <stdint.h>

// #include "attributes.h"
// #include "version.h"

const
  AES_CTR_KEY_SIZE = (16);
  AES_CTR_IV_SIZE = (8);

type
  PAVAESCTR = ^AVAESCTR;
  AVAESCTR = record
  end;

(**
 * Allocate an AVAESCTR context.
 *)
function av_aes_ctr_alloc(): PAVAESCTR; cdecl; external LIB_AVUTIL;

(**
 * Initialize an AVAESCTR context.
 * @param key encryption key, must have a length of AES_CTR_KEY_SIZE
 *)
function av_aes_ctr_init(a: PAVAESCTR; const key: pcuint8): cint; cdecl; external LIB_AVUTIL;

(**
 * Release an AVAESCTR context.
 *)
procedure av_aes_ctr_free(a: PAVAESCTR); cdecl; external LIB_AVUTIL;

(**
 * Process a buffer using a previously initialized context.
 * @param dst destination array, can be equal to src
 * @param src source array, can be equal to dst
 * @param size the size of src and dst
 *)
procedure av_aes_ctr_crypt(a: PAVAESCTR; dst: pcuint8; const src: pcuint8; size: cint); cdecl; external LIB_AVUTIL;

(**
 * Get the current iv
 *)
function av_aes_ctr_get_iv(a: PAVAESCTR): pcuint8; cdecl; external LIB_AVUTIL;

(**
 * Generate a random iv
 *)
procedure av_aes_ctr_set_random_iv(a: PAVAESCTR); cdecl; external LIB_AVUTIL;

(**
 * Forcefully change the iv
 *)
procedure av_aes_ctr_set_iv(a: PAVAESCTR; const iv: pcuint8); cdecl; external LIB_AVUTIL;

(**
 * Increment the top 64 bit of the iv (performed after each frame)
 *)
procedure av_aes_ctr_increment_iv(a: PAVAESCTR); cdecl; external LIB_AVUTIL;

(**
 * @}
 *)

// #endif (* AVUTIL_AES_CTR_H *)
