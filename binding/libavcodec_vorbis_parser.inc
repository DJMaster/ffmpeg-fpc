//
// avcodec.h header binding for the Free Pascal Compiler aka FPC
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

(**
 * @file
 * A public API for Vorbis parsing
 *
 * Determines the duration for each packet.
 *)

// #ifndef AVCODEC_VORBIS_PARSER_H
// #define AVCODEC_VORBIS_PARSER_H

// #include <stdint.h>

type
  PPAVVorbisParseContext = ^PAVVorbisParseContext;
  PAVVorbisParseContext = ^AVVorbisParseContext;
  AVVorbisParseContext = record
  end;

(**
 * Allocate and initialize the Vorbis parser using headers in the extradata.
 *)
function av_vorbis_parse_init(const extradata: pcuint8; extradata_size: cint): PAVVorbisParseContext; cdecl; external LIB_AVCODEC;

(**
 * Free the parser and everything associated with it.
 *)
procedure av_vorbis_parse_free(s: PPAVVorbisParseContext); cdecl; external LIB_AVCODEC;

const
  VORBIS_FLAG_HEADER = $00000001;
  VORBIS_FLAG_COMMENT = $00000002;
  VORBIS_FLAG_SETUP = $00000004;

(**
 * Get the duration for a Vorbis packet.
 *
 * If @p flags is @c NULL,
 * special frames are considered invalid.
 *
 * @param s        Vorbis parser context
 * @param buf      buffer containing a Vorbis frame
 * @param buf_size size of the buffer
 * @param flags    flags for special frames
 *)
function av_vorbis_parse_frame_flags(s: PAVVorbisParseContext; const buf: pcuint8; buf_size: cint; flags: pcint): cint; cdecl; external LIB_AVCODEC;

(**
 * Get the duration for a Vorbis packet.
 *
 * @param s        Vorbis parser context
 * @param buf      buffer containing a Vorbis frame
 * @param buf_size size of the buffer
 *)
function av_vorbis_parse_frame(s: PAVVorbisParseContext; const buf: pcuint8; buf_size: cint): cint; cdecl; external LIB_AVCODEC;

procedure av_vorbis_parse_reset(s: PAVVorbisParseContext); cdecl; external LIB_AVCODEC;

// #endif (* AVCODEC_VORBIS_PARSER_H *)
