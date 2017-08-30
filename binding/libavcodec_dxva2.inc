//
// avcodec.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * DXVA2 HW acceleration
 *
 * copyright (c) 2009 Laurent Aimar
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

// #ifndef AVCODEC_DXVA2_H
// #define AVCODEC_DXVA2_H

(**
 * @file
 * @ingroup lavc_codec_hwaccel_dxva2
 * Public libavcodec DXVA2 header.
 *)

#if !defined(_WIN32_WINNT) || _WIN32_WINNT < $0602
#undef _WIN32_WINNT
  _WIN32_WINNT = $0602;
{$endif}

#include <stdint.h>
#include <d3d9.h>
#include <dxva2api.h>

(**
 * @defgroup lavc_codec_hwaccel_dxva2 DXVA2
 * @ingroup lavc_codec_hwaccel
 *
 * @{
 *)
const
  FF_DXVA2_WORKAROUND_SCALING_LIST_ZIGZAG = 1; ///< Work around for DXVA2 and old UVD/UVD+ ATI video cards
  FF_DXVA2_WORKAROUND_INTEL_CLEARVIDEO = 2; ///< Work around for DXVA2 and old Intel GPUs with ClearVideo interface

(**
 * This structure is used to provides the necessary configurations and data
 * to the DXVA2 FFmpeg HWAccel implementation.
 *
 * The application must make it available as AVCodecContext.hwaccel_context.
 *)
type
  Pdxva_context = ^dxva_context;
  dxva_context = record
    (**
     * DXVA2 decoder object
     *)
    decoder: PIDirectXVideoDecoder;

    (**
     * DXVA2 configuration used to create the decoder
     *)
    cfg: PDXVA2_ConfigPictureDecode;

    (**
     * The number of surface in the surface array
     *)
    surface_count: cunsigned;

    (**
     * The array of Direct3D surfaces used to create the decoder
     *)
    surface: PLPDIRECT3DSURFACE9;

    (**
     * A bit field configuring the workarounds needed for using the decoder
     *)
    workaround: cuint64_t;

    (**
     * Private to the FFmpeg AVHWAccel implementation
     *)
    report_id: cunsigned;
  end;

(**
 * @}
 *)

// #endif (* AVCODEC_DXVA2_H *)
