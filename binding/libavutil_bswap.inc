//
// avutil.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
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

(**
 * @file
 * byte swapping routines
 *)

// #ifndef AVUTIL_BSWAP_H
// #define AVUTIL_BSWAP_H

// #include <stdint.h>
// #include "libavutil/avconfig.h"
// #include "attributes.h"

#ifdef HAVE_AV_CONFIG_H

// #include "config.h"

//TODO #if ARCH_AARCH64
//TODO #   include "aarch64/bswap.h"
//TODO #elif ARCH_ARM
//TODO #   include "arm/bswap.h"
//TODO #elif ARCH_AVR32
//TODO #   include "avr32/bswap.h"
//TODO #elif ARCH_SH4
//TODO #   include "sh4/bswap.h"
//TODO #elif ARCH_X86
//TODO #   include "x86/bswap.h"
//TODO #endif

{$endif} (* HAVE_AV_CONFIG_H *)

#define AV_BSWAP16C(x) (((x) << 8 & $ff00)  | ((x) >> 8 & $00ff))
#define AV_BSWAP32C(x) (AV_BSWAP16C(x) << 16 | AV_BSWAP16C((x) >> 16))
#define AV_BSWAP64C(x) (AV_BSWAP32C(x) << 32 | AV_BSWAP32C((x) >> 32))

#define AV_BSWAPC(s, x) AV_BSWAP##s##C(x)

{$ifndef av_bswap16}
static av_always_inline av_const uint16_t av_bswap16(uint16_t x)
{
    x= (x>>8) | (x<<8);
    return x;
}
{$endif}

{$ifndef av_bswap32}
//TODO static av_always_inline av_const uint32_t av_bswap32(uint32_t x)
//TODO {
//TODO     return AV_BSWAP32C(x);
//TODO }
{$endif}

{$ifndef av_bswap64}
//TODO static inline uint64_t av_const av_bswap64(uint64_t x)
//TODO {
//TODO     return (uint64_t)av_bswap32(x) << 32 | av_bswap32(x >> 32);
//TODO }
{$endif}

// be2ne ... big-endian to native-endian
// le2ne ... little-endian to native-endian

{$if AV_HAVE_BIGENDIAN}
//TODO #define av_be2ne16(x) (x)
//TODO #define av_be2ne32(x) (x)
//TODO #define av_be2ne64(x) (x)
//TODO #define av_le2ne16(x) av_bswap16(x)
//TODO #define av_le2ne32(x) av_bswap32(x)
//TODO #define av_le2ne64(x) av_bswap64(x)
//TODO #define AV_BE2NEC(s, x) (x)
//TODO #define AV_LE2NEC(s, x) AV_BSWAPC(s, x)
{$else}
//TODO #define av_be2ne16(x) av_bswap16(x)
//TODO #define av_be2ne32(x) av_bswap32(x)
//TODO #define av_be2ne64(x) av_bswap64(x)
//TODO #define av_le2ne16(x) (x)
//TODO #define av_le2ne32(x) (x)
//TODO #define av_le2ne64(x) (x)
//TODO #define AV_BE2NEC(s, x) AV_BSWAPC(s, x)
//TODO #define AV_LE2NEC(s, x) (x)
{$endif}

//TODO #define AV_BE2NE16C(x) AV_BE2NEC(16, x)
//TODO #define AV_BE2NE32C(x) AV_BE2NEC(32, x)
//TODO #define AV_BE2NE64C(x) AV_BE2NEC(64, x)
//TODO #define AV_LE2NE16C(x) AV_LE2NEC(16, x)
//TODO #define AV_LE2NE32C(x) AV_LE2NEC(32, x)
//TODO #define AV_LE2NE64C(x) AV_LE2NEC(64, x)

// #endif (* AVUTIL_BSWAP_H *)
