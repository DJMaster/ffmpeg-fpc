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

// #ifndef AVCODEC_AVFFT_H
// #define AVCODEC_AVFFT_H

(**
 * @file
 * @ingroup lavc_fft
 * FFT functions
 *)

(**
 * @defgroup lavc_fft FFT functions
 * @ingroup lavc_misc
 *
 * @{
 *)
type
  FFTSample: cfloat;

  PFFTComplex = ^FFTComplex;
  FFTComplex = record
    re: FFTSample;
    im: FFTSample;
  end;;

  PFFTContext = ^FFTContext;
  FFTContext = record
  end;

(**
 * Set up a complex FFT.
 * @param nbits           log2 of the length of the input array
 * @param inverse         if 0 perform the forward transform, if 1 perform the inverse
 *)
function av_fft_init(nbits: cint; inverse: cint): PFFTContext; cdecl; external LIB_LIBAVCODEC;

(**
 * Do the permutation needed BEFORE calling ff_fft_calc().
 *)
procedure av_fft_permute(s: PFFTContext; z: PFFTComplex); cdecl; external LIB_LIBAVCODEC;

(**
 * Do a complex FFT with the parameters defined in av_fft_init(). The
 * input data must be permuted before. No 1.0/sqrt(n) normalization is done.
 *)
procedure av_fft_calc(s: PFFTContext; z: PFFTComplex); cdecl; external LIB_LIBAVCODEC;

procedure av_fft_end(s: PFFTContext); cdecl; external LIB_LIBAVCODEC;

function av_mdct_init(nbits: cint; inverse: cint ; scale: cdouble): PFFTContext; cdecl; external LIB_LIBAVCODEC;
procedure av_imdct_calc(s: PFFTContext; output: PFFTSample; const input: PFFTSample); cdecl; external LIB_LIBAVCODEC;
procedure av_imdct_half(s: PFFTContext; output: PFFTSample; const input: PFFTSample); cdecl; external LIB_LIBAVCODEC;
procedure av_mdct_calc(s: PFFTContext; output: PFFTSample; const input: PFFTSample); cdecl; external LIB_LIBAVCODEC;
procedure av_mdct_end(s: PFFTContext); cdecl; external LIB_LIBAVCODEC;

(* Real Discrete Fourier Transform *)

type
  RDFTransformType = (
    DFT_R2C,
    IDFT_C2R,
    IDFT_R2C,
    DFT_C2R
  );

  PRDFTContext = ^RDFTContext;
  RDFTContext = record
  end;

(**
 * Set up a real FFT.
 * @param nbits           log2 of the length of the input array
 * @param trans           the type of transform
 *)
function av_rdft_init(nbits: cint; trans: RDFTransformType): PRDFTContext; cdecl; external LIB_LIBAVCODEC;
procedure av_rdft_calc(s: PRDFTContext; data: PFFTSample); cdecl; external LIB_LIBAVCODEC;
procedure av_rdft_end(s: PRDFTContext); cdecl; external LIB_LIBAVCODEC;

(* Discrete Cosine Transform *)

type
  PDCTContext = ^DCTContext;
  DCTContext = record
  end;

  DCTTransformType = (
    DCT_II = 0,
    DCT_III,
    DCT_I,
    DST_I
  };

(**
 * Set up DCT.
 *
 * @param nbits           size of the input array:
 *                        (1 << nbits)     for DCT-II, DCT-III and DST-I
 *                        (1 << nbits) + 1 for DCT-I
 * @param type            the type of transform
 *
 * @note the first element of the input of DST-I is ignored
 *)
function av_dct_init(nbits: cint; type_: DCTTransformType): PDCTContext; cdecl; external LIB_LIBAVCODEC;
procedure av_dct_calc(s: PDCTContext; data: PFFTSample); cdecl; external LIB_LIBAVCODEC;
procedure av_dct_end(s: PDCTContext); cdecl; external LIB_LIBAVCODEC;

(**
 * @}
 *)

// #endif (* AVCODEC_AVFFT_H *)
