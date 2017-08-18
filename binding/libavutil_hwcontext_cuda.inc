//
// avutil.h header binding for the Free Pascal Compiler aka FPC
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


// #ifndef AVUTIL_HWCONTEXT_CUDA_H
// #define AVUTIL_HWCONTEXT_CUDA_H

{$ifndef CUDA_VERSION}
#include <cuda.h>
{$endif}

#include "pixfmt.h"

(**
 * @file
 * An API-specific header for AV_HWDEVICE_TYPE_CUDA.
 *
 * This API supports dynamic frame pools. AVHWFramesContext.pool must return
 * AVBufferRefs whose data pointer is a CUdeviceptr.
 *)

type
  PAVCUDADeviceContextInternal = ^AVCUDADeviceContextInternal;
  AVCUDADeviceContextInternal = record
  end;

(**
 * This struct is allocated as AVHWDeviceContext.hwctx
 *)
  PAVCUDADeviceContext = ^AVCUDADeviceContext;
  AVCUDADeviceContext = record
    cuda_ctx: CUcontext;
    internal: PAVCUDADeviceContextInternal;
  end;

(**
 * AVHWFramesContext.hwctx is currently not used
 *)

// #endif (* AVUTIL_HWCONTEXT_CUDA_H *)
