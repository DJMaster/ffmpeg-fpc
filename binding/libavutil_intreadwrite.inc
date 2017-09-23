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

// #ifndef AVUTIL_INTREADWRITE_H
// #define AVUTIL_INTREADWRITE_H

// #include <stdint.h>
// #include "libavutil/avconfig.h"
// #include "attributes.h"
// #include "bswap.h"

type
  av_alias64 = record
    case cint of
      0: (u64: cuint64);
      1: (u32: array[0..1] of cuint32);
      2: (u16: array[0..3] of cuint16);
      3: (u8: array[0..7] of cuint8);
      4: (f64: cdouble);
      5: (f32: array[0..1] of cfloat);
  end;

  av_alias32 = record
    case cint of
      0: (u32: cuint32);
      1: (u16: array[0..1] of cuint16);
      2: (u8: array[0..3] of cuint8);
      3: (f32: cfloat);
  end;

  av_alias16 = record
    case cint of
      0: (u16: cuint16);
      1: (u8: array[0..1] of cuint8);
  end;

(*
 * Arch-specific headers can provide any combination of
 * AV_[RW][BLN](16|24|32|48|64) and AV_(COPY|SWAP|ZERO)(64|128) macros.
 * Preprocessor symbols must be defined, even if these are implemented
 * as inline functions.
 *
 * R/W means read/write, B/L/N means big/little/native endianness.
 * The following macros require aligned access, compared to their
 * unaligned variants: AV_(COPY|SWAP|ZERO)(64|128), AV_[RW]N[8-64]A.
 * Incorrect usage may range from abysmal performance to crash
 * depending on the platform.
 *
 * The unaligned variants are AV_[RW][BLN][8-64] and AV_COPY*U.
 *)

{$ifdef HAVE_AV_CONFIG_H}

#include "config.h"

#if ARCH_ARM
#   include "arm/intreadwrite.h"
#elif ARCH_AVR32
#   include "avr32/intreadwrite.h"
#elif ARCH_MIPS
#   include "mips/intreadwrite.h"
#elif ARCH_PPC
#   include "ppc/intreadwrite.h"
#elif ARCH_TOMI
#   include "tomi/intreadwrite.h"
#elif ARCH_X86
#   include "x86/intreadwrite.h"
#endif

{$endif} (* HAVE_AV_CONFIG_H *)

(*
 * Map AV_RNXX <-> AV_R[BL]XX for all variants provided by per-arch headers.
 *)

{$if AV_HAVE_BIGENDIAN}

#   if    defined(AV_RN16) && !defined(AV_RB16)
#       define AV_RB16(p) AV_RN16(p)
#   elif !defined(AV_RN16) &&  defined(AV_RB16)
#       define AV_RN16(p) AV_RB16(p)
#   endif

#   if    defined(AV_WN16) && !defined(AV_WB16)
#       define AV_WB16(p, v) AV_WN16(p, v)
#   elif !defined(AV_WN16) &&  defined(AV_WB16)
#       define AV_WN16(p, v) AV_WB16(p, v)
#   endif

#   if    defined(AV_RN24) && !defined(AV_RB24)
#       define AV_RB24(p) AV_RN24(p)
#   elif !defined(AV_RN24) &&  defined(AV_RB24)
#       define AV_RN24(p) AV_RB24(p)
#   endif

#   if    defined(AV_WN24) && !defined(AV_WB24)
#       define AV_WB24(p, v) AV_WN24(p, v)
#   elif !defined(AV_WN24) &&  defined(AV_WB24)
#       define AV_WN24(p, v) AV_WB24(p, v)
#   endif

#   if    defined(AV_RN32) && !defined(AV_RB32)
#       define AV_RB32(p) AV_RN32(p)
#   elif !defined(AV_RN32) &&  defined(AV_RB32)
#       define AV_RN32(p) AV_RB32(p)
#   endif

#   if    defined(AV_WN32) && !defined(AV_WB32)
#       define AV_WB32(p, v) AV_WN32(p, v)
#   elif !defined(AV_WN32) &&  defined(AV_WB32)
#       define AV_WN32(p, v) AV_WB32(p, v)
#   endif

#   if    defined(AV_RN48) && !defined(AV_RB48)
#       define AV_RB48(p) AV_RN48(p)
#   elif !defined(AV_RN48) &&  defined(AV_RB48)
#       define AV_RN48(p) AV_RB48(p)
#   endif

#   if    defined(AV_WN48) && !defined(AV_WB48)
#       define AV_WB48(p, v) AV_WN48(p, v)
#   elif !defined(AV_WN48) &&  defined(AV_WB48)
#       define AV_WN48(p, v) AV_WB48(p, v)
#   endif

#   if    defined(AV_RN64) && !defined(AV_RB64)
#       define AV_RB64(p) AV_RN64(p)
#   elif !defined(AV_RN64) &&  defined(AV_RB64)
#       define AV_RN64(p) AV_RB64(p)
#   endif

#   if    defined(AV_WN64) && !defined(AV_WB64)
#       define AV_WB64(p, v) AV_WN64(p, v)
#   elif !defined(AV_WN64) &&  defined(AV_WB64)
#       define AV_WN64(p, v) AV_WB64(p, v)
#   endif

#else (* AV_HAVE_BIGENDIAN *)

#   if    defined(AV_RN16) && !defined(AV_RL16)
#       define AV_RL16(p) AV_RN16(p)
#   elif !defined(AV_RN16) &&  defined(AV_RL16)
#       define AV_RN16(p) AV_RL16(p)
#   endif

#   if    defined(AV_WN16) && !defined(AV_WL16)
#       define AV_WL16(p, v) AV_WN16(p, v)
#   elif !defined(AV_WN16) &&  defined(AV_WL16)
#       define AV_WN16(p, v) AV_WL16(p, v)
#   endif

#   if    defined(AV_RN24) && !defined(AV_RL24)
#       define AV_RL24(p) AV_RN24(p)
#   elif !defined(AV_RN24) &&  defined(AV_RL24)
#       define AV_RN24(p) AV_RL24(p)
#   endif

#   if    defined(AV_WN24) && !defined(AV_WL24)
#       define AV_WL24(p, v) AV_WN24(p, v)
#   elif !defined(AV_WN24) &&  defined(AV_WL24)
#       define AV_WN24(p, v) AV_WL24(p, v)
#   endif

#   if    defined(AV_RN32) && !defined(AV_RL32)
#       define AV_RL32(p) AV_RN32(p)
#   elif !defined(AV_RN32) &&  defined(AV_RL32)
#       define AV_RN32(p) AV_RL32(p)
#   endif

#   if    defined(AV_WN32) && !defined(AV_WL32)
#       define AV_WL32(p, v) AV_WN32(p, v)
#   elif !defined(AV_WN32) &&  defined(AV_WL32)
#       define AV_WN32(p, v) AV_WL32(p, v)
#   endif

#   if    defined(AV_RN48) && !defined(AV_RL48)
#       define AV_RL48(p) AV_RN48(p)
#   elif !defined(AV_RN48) &&  defined(AV_RL48)
#       define AV_RN48(p) AV_RL48(p)
#   endif

#   if    defined(AV_WN48) && !defined(AV_WL48)
#       define AV_WL48(p, v) AV_WN48(p, v)
#   elif !defined(AV_WN48) &&  defined(AV_WL48)
#       define AV_WN48(p, v) AV_WL48(p, v)
#   endif

#   if    defined(AV_RN64) && !defined(AV_RL64)
#       define AV_RL64(p) AV_RN64(p)
#   elif !defined(AV_RN64) &&  defined(AV_RL64)
#       define AV_RN64(p) AV_RL64(p)
#   endif

#   if    defined(AV_WN64) && !defined(AV_WL64)
#       define AV_WL64(p, v) AV_WN64(p, v)
#   elif !defined(AV_WN64) &&  defined(AV_WL64)
#       define AV_WN64(p, v) AV_WL64(p, v)
#   endif

{$endif} (* !AV_HAVE_BIGENDIAN *)

(*
 * Define AV_[RW]N helper macros to simplify definitions not provided
 * by per-arch headers.
 *)

//TODO #if defined(__GNUC__) && !defined(__TI_COMPILER_VERSION__)

//TODO union unaligned_64 { uint64_t l; } __attribute__((packed)) av_alias;
//TODO union unaligned_32 { uint32_t l; } __attribute__((packed)) av_alias;
//TODO union unaligned_16 { uint16_t l; } __attribute__((packed)) av_alias;

//TODO #   define AV_RN(s, p) (((const union unaligned_##s *) (p))->l)
//TODO #   define AV_WN(s, p, v) ((((union unaligned_##s *) (p))->l) = (v))

//TODO #elif defined(__DECC)

//TODO #   define AV_RN(s, p) (*((const __unaligned uint##s##_t*)(p)))
//TODO #   define AV_WN(s, p, v) (*((__unaligned uint##s##_t*)(p)) = (v))

//TODO #elif defined(_MSC_VER) && (defined(_M_ARM) || defined(_M_X64)) && AV_HAVE_FAST_UNALIGNED

//TODO #   define AV_RN(s, p) (*((const __unaligned uint##s##_t*)(p)))
//TODO #   define AV_WN(s, p, v) (*((__unaligned uint##s##_t*)(p)) = (v))

//TODO #elif AV_HAVE_FAST_UNALIGNED

//TODO #   define AV_RN(s, p) (((const av_alias##s*)(p))->u##s)
//TODO #   define AV_WN(s, p, v) (((av_alias##s*)(p))->u##s = (v))

//TODO #else

{$ifndef AV_RB16}
//TODO #   define AV_RB16(x)                           \
//TODO     ((((const uint8_t*)(x))[0] << 8) |          \
//TODO       ((const uint8_t*)(x))[1])
{$endif}
{$ifndef AV_WB16}
//TODO #   define AV_WB16(p, val) do {                 \
//TODO         uint16_t d = (val);                     \
//TODO         ((uint8_t*)(p))[1] = (d);               \
//TODO         ((uint8_t*)(p))[0] = (d)>>8;            \
//TODO     } while(0)
{$endif}

{$ifndef AV_RL16}
//TODO #   define AV_RL16(x)                           \
//TODO     ((((const uint8_t*)(x))[1] << 8) |          \
//TODO       ((const uint8_t*)(x))[0])
{$endif}
{$ifndef AV_WL16}
//TODO #   define AV_WL16(p, val) do {                 \
//TODO         uint16_t d = (val);                     \
//TODO         ((uint8_t*)(p))[0] = (d);               \
//TODO         ((uint8_t*)(p))[1] = (d)>>8;            \
//TODO     } while(0)
{$endif}

{$ifndef AV_RB32}
//TODO #   define AV_RB32(x)                                \
//TODO     (((uint32_t)((const uint8_t*)(x))[0] << 24) |    \
//TODO                (((const uint8_t*)(x))[1] << 16) |    \
//TODO                (((const uint8_t*)(x))[2] <<  8) |    \
//TODO                 ((const uint8_t*)(x))[3])
{$endif}
{$ifndef AV_WB32}
//TODO #   define AV_WB32(p, val) do {                 \
//TODO         uint32_t d = (val);                     \
//TODO         ((uint8_t*)(p))[3] = (d);               \
//TODO         ((uint8_t*)(p))[2] = (d)>>8;            \
//TODO         ((uint8_t*)(p))[1] = (d)>>16;           \
//TODO         ((uint8_t*)(p))[0] = (d)>>24;           \
//TODO     } while(0)
{$endif}

{$ifndef AV_RL32}
//TODO #   define AV_RL32(x)                                \
//TODO     (((uint32_t)((const uint8_t*)(x))[3] << 24) |    \
//TODO                (((const uint8_t*)(x))[2] << 16) |    \
//TODO                (((const uint8_t*)(x))[1] <<  8) |    \
//TODO                 ((const uint8_t*)(x))[0])
{$endif}
{$ifndef AV_WL32}
//TODO #   define AV_WL32(p, val) do {                 \
//TODO         uint32_t d = (val);                     \
//TODO         ((uint8_t*)(p))[0] = (d);               \
//TODO         ((uint8_t*)(p))[1] = (d)>>8;            \
//TODO         ((uint8_t*)(p))[2] = (d)>>16;           \
//TODO         ((uint8_t*)(p))[3] = (d)>>24;           \
//TODO     } while(0)
{$endif}

{$ifndef AV_RB64}
//TODO #   define AV_RB64(x)                                   \
//TODO     (((uint64_t)((const uint8_t*)(x))[0] << 56) |       \
//TODO      ((uint64_t)((const uint8_t*)(x))[1] << 48) |       \
//TODO      ((uint64_t)((const uint8_t*)(x))[2] << 40) |       \
//TODO      ((uint64_t)((const uint8_t*)(x))[3] << 32) |       \
//TODO      ((uint64_t)((const uint8_t*)(x))[4] << 24) |       \
//TODO      ((uint64_t)((const uint8_t*)(x))[5] << 16) |       \
//TODO      ((uint64_t)((const uint8_t*)(x))[6] <<  8) |       \
//TODO       (uint64_t)((const uint8_t*)(x))[7])
{$endif}
{$ifndef AV_WB64}
//TODO #   define AV_WB64(p, val) do {                 \
//TODO         uint64_t d = (val);                     \
//TODO         ((uint8_t*)(p))[7] = (d);               \
//TODO         ((uint8_t*)(p))[6] = (d)>>8;            \
//TODO         ((uint8_t*)(p))[5] = (d)>>16;           \
//TODO         ((uint8_t*)(p))[4] = (d)>>24;           \
//TODO         ((uint8_t*)(p))[3] = (d)>>32;           \
//TODO         ((uint8_t*)(p))[2] = (d)>>40;           \
//TODO         ((uint8_t*)(p))[1] = (d)>>48;           \
//TODO         ((uint8_t*)(p))[0] = (d)>>56;           \
//TODO     } while(0)
{$endif}

{$ifndef AV_RL64}
//TODO #   define AV_RL64(x)                                   \
//TODO     (((uint64_t)((const uint8_t*)(x))[7] << 56) |       \
//TODO      ((uint64_t)((const uint8_t*)(x))[6] << 48) |       \
//TODO      ((uint64_t)((const uint8_t*)(x))[5] << 40) |       \
//TODO      ((uint64_t)((const uint8_t*)(x))[4] << 32) |       \
//TODO      ((uint64_t)((const uint8_t*)(x))[3] << 24) |       \
//TODO      ((uint64_t)((const uint8_t*)(x))[2] << 16) |       \
//TODO      ((uint64_t)((const uint8_t*)(x))[1] <<  8) |       \
//TODO       (uint64_t)((const uint8_t*)(x))[0])
{$endif}
{$ifndef AV_WL64}
//TODO #   define AV_WL64(p, val) do {                 \
//TODO         uint64_t d = (val);                     \
//TODO         ((uint8_t*)(p))[0] = (d);               \
//TODO         ((uint8_t*)(p))[1] = (d)>>8;            \
//TODO         ((uint8_t*)(p))[2] = (d)>>16;           \
//TODO         ((uint8_t*)(p))[3] = (d)>>24;           \
//TODO         ((uint8_t*)(p))[4] = (d)>>32;           \
//TODO         ((uint8_t*)(p))[5] = (d)>>40;           \
//TODO         ((uint8_t*)(p))[6] = (d)>>48;           \
//TODO         ((uint8_t*)(p))[7] = (d)>>56;           \
//TODO     } while(0)
{$endif}

{$if AV_HAVE_BIGENDIAN}
//TODO #   define AV_RN(s, p)    AV_RB##s(p)
//TODO #   define AV_WN(s, p, v) AV_WB##s(p, v)
{$else}
//TODO #   define AV_RN(s, p)    AV_RL##s(p)
//TODO #   define AV_WN(s, p, v) AV_WL##s(p, v)
{$endif}

//TODO #endif (* HAVE_FAST_UNALIGNED *)

{$ifndef AV_RN16}
//TODO #   define AV_RN16(p) AV_RN(16, p)
{$endif}

{$ifndef AV_RN32}
//TODO #   define AV_RN32(p) AV_RN(32, p)
{$endif}

{$ifndef AV_RN64}
//TODO #   define AV_RN64(p) AV_RN(64, p)
{$endif}

{$ifndef AV_WN16}
//TODO #   define AV_WN16(p, v) AV_WN(16, p, v)
{$endif}

{$ifndef AV_WN32}
//TODO #   define AV_WN32(p, v) AV_WN(32, p, v)
{$endif}

{$ifndef AV_WN64}
//TODO #   define AV_WN64(p, v) AV_WN(64, p, v)
{$endif}

{$if AV_HAVE_BIGENDIAN}
//TODO #   define AV_RB(s, p)    AV_RN##s(p)
//TODO #   define AV_WB(s, p, v) AV_WN##s(p, v)
//TODO #   define AV_RL(s, p)    av_bswap##s(AV_RN##s(p))
//TODO #   define AV_WL(s, p, v) AV_WN##s(p, av_bswap##s(v))
{$else}
//TODO #   define AV_RB(s, p)    av_bswap##s(AV_RN##s(p))
//TODO #   define AV_WB(s, p, v) AV_WN##s(p, av_bswap##s(v))
//TODO #   define AV_RL(s, p)    AV_RN##s(p)
//TODO #   define AV_WL(s, p, v) AV_WN##s(p, v)
{$endif}

//TODO #define AV_RB8(x)     (((const uint8_t*)(x))[0])
//TODO #define AV_WB8(p, d)  do { ((uint8_t*)(p))[0] = (d); } while(0)

//TODO #define AV_RL8(x)     AV_RB8(x)
//TODO #define AV_WL8(p, d)  AV_WB8(p, d)

{$ifndef AV_RB16}
//TODO #   define AV_RB16(p)    AV_RB(16, p)
{$endif}
{$ifndef AV_WB16}
//TODO #   define AV_WB16(p, v) AV_WB(16, p, v)
{$endif}

{$ifndef AV_RL16}
//TODO #   define AV_RL16(p)    AV_RL(16, p)
{$endif}
{$ifndef AV_WL16}
//TODO #   define AV_WL16(p, v) AV_WL(16, p, v)
{$endif}

{$ifndef AV_RB32}
//TODO #   define AV_RB32(p)    AV_RB(32, p)
{$endif}
{$ifndef AV_WB32}
//TODO #   define AV_WB32(p, v) AV_WB(32, p, v)
{$endif}

{$ifndef AV_RL32}
//TODO #   define AV_RL32(p)    AV_RL(32, p)
{$endif}
{$ifndef AV_WL32}
//TODO #   define AV_WL32(p, v) AV_WL(32, p, v)
{$endif}

{$ifndef AV_RB64}
//TODO #   define AV_RB64(p)    AV_RB(64, p)
{$endif}
{$ifndef AV_WB64}
//TODO #   define AV_WB64(p, v) AV_WB(64, p, v)
{$endif}

{$ifndef AV_RL64}
//TODO #   define AV_RL64(p)    AV_RL(64, p)
{$endif}
{$ifndef AV_WL64}
//TODO #   define AV_WL64(p, v) AV_WL(64, p, v)
{$endif}

{$ifndef AV_RB24}
//TODO #   define AV_RB24(x)                           \
//TODO     ((((const uint8_t*)(x))[0] << 16) |         \
//TODO      (((const uint8_t*)(x))[1] <<  8) |         \
//TODO       ((const uint8_t*)(x))[2])
{$endif}
{$ifndef AV_WB24}
//TODO #   define AV_WB24(p, d) do {                   \
//TODO         ((uint8_t*)(p))[2] = (d);               \
//TODO         ((uint8_t*)(p))[1] = (d)>>8;            \
//TODO         ((uint8_t*)(p))[0] = (d)>>16;           \
//TODO     } while(0)
{$endif}

{$ifndef AV_RL24}
//TODO #   define AV_RL24(x)                           \
//TODO     ((((const uint8_t*)(x))[2] << 16) |         \
//TODO      (((const uint8_t*)(x))[1] <<  8) |         \
//TODO       ((const uint8_t*)(x))[0])
{$endif}
{$ifndef AV_WL24}
//TODO #   define AV_WL24(p, d) do {                   \
//TODO         ((uint8_t*)(p))[0] = (d);               \
//TODO         ((uint8_t*)(p))[1] = (d)>>8;            \
//TODO         ((uint8_t*)(p))[2] = (d)>>16;           \
//TODO     } while(0)
{$endif}

{$ifndef AV_RB48}
//TODO #   define AV_RB48(x)                                     \
//TODO     (((uint64_t)((const uint8_t*)(x))[0] << 40) |         \
//TODO      ((uint64_t)((const uint8_t*)(x))[1] << 32) |         \
//TODO      ((uint64_t)((const uint8_t*)(x))[2] << 24) |         \
//TODO      ((uint64_t)((const uint8_t*)(x))[3] << 16) |         \
//TODO      ((uint64_t)((const uint8_t*)(x))[4] <<  8) |         \
//TODO       (uint64_t)((const uint8_t*)(x))[5])
{$endif}
{$ifndef AV_WB48}
//TODO #   define AV_WB48(p, darg) do {                \
//TODO         uint64_t d = (darg);                    \
//TODO         ((uint8_t*)(p))[5] = (d);               \
//TODO         ((uint8_t*)(p))[4] = (d)>>8;            \
//TODO         ((uint8_t*)(p))[3] = (d)>>16;           \
//TODO         ((uint8_t*)(p))[2] = (d)>>24;           \
//TODO         ((uint8_t*)(p))[1] = (d)>>32;           \
//TODO         ((uint8_t*)(p))[0] = (d)>>40;           \
//TODO     } while(0)
{$endif}

{$ifndef AV_RL48}
//TODO #   define AV_RL48(x)                                     \
//TODO     (((uint64_t)((const uint8_t*)(x))[5] << 40) |         \
//TODO      ((uint64_t)((const uint8_t*)(x))[4] << 32) |         \
//TODO      ((uint64_t)((const uint8_t*)(x))[3] << 24) |         \
//TODO      ((uint64_t)((const uint8_t*)(x))[2] << 16) |         \
//TODO      ((uint64_t)((const uint8_t*)(x))[1] <<  8) |         \
//TODO       (uint64_t)((const uint8_t*)(x))[0])
{$endif}
{$ifndef AV_WL48}
//TODO #   define AV_WL48(p, darg) do {                \
//TODO         uint64_t d = (darg);                    \
//TODO         ((uint8_t*)(p))[0] = (d);               \
//TODO         ((uint8_t*)(p))[1] = (d)>>8;            \
//TODO         ((uint8_t*)(p))[2] = (d)>>16;           \
//TODO         ((uint8_t*)(p))[3] = (d)>>24;           \
//TODO         ((uint8_t*)(p))[4] = (d)>>32;           \
//TODO         ((uint8_t*)(p))[5] = (d)>>40;           \
//TODO     } while(0)
{$endif}

(*
 * The AV_[RW]NA macros access naturally aligned data
 * in a type-safe way.
 *)

//TODO #define AV_RNA(s, p)    (((const av_alias##s*)(p))->u##s)
//TODO #define AV_WNA(s, p, v) (((av_alias##s*)(p))->u##s = (v))

{$ifndef AV_RN16A}
//TODO #   define AV_RN16A(p) AV_RNA(16, p)
{$endif}

{$ifndef AV_RN32A}
//TODO #   define AV_RN32A(p) AV_RNA(32, p)
{$endif}

{$ifndef AV_RN64A}
//TODO #   define AV_RN64A(p) AV_RNA(64, p)
{$endif}

{$ifndef AV_WN16A}
//TODO #   define AV_WN16A(p, v) AV_WNA(16, p, v)
{$endif}

{$ifndef AV_WN32A}
//TODO #   define AV_WN32A(p, v) AV_WNA(32, p, v)
{$endif}

{$ifndef AV_WN64A}
//TODO #   define AV_WN64A(p, v) AV_WNA(64, p, v)
{$endif}

(*
 * The AV_COPYxxU macros are suitable for copying data to/from unaligned
 * memory locations.
 *)

//TODO #define AV_COPYU(n, d, s) AV_WN##n(d, AV_RN##n(s));

{$ifndef AV_COPY16U}
//TODO #   define AV_COPY16U(d, s) AV_COPYU(16, d, s)
{$endif}

{$ifndef AV_COPY32U}
//TODO #   define AV_COPY32U(d, s) AV_COPYU(32, d, s)
{$endif}

{$ifndef AV_COPY64U}
//TODO #   define AV_COPY64U(d, s) AV_COPYU(64, d, s)
{$endif}

{$ifndef AV_COPY128U}
//TODO #   define AV_COPY128U(d, s)                                    \
//TODO     do {                                                        \
//TODO         AV_COPY64U(d, s);                                       \
//TODO         AV_COPY64U((char *)(d) + 8, (const char *)(s) + 8);     \
//TODO     } while(0)
{$endif}

(* Parameters for AV_COPY*, AV_SWAP*, AV_ZERO* must be
 * naturally aligned. They may be implemented using MMX,
 * so emms_c() must be called before using any float code
 * afterwards.
 *)

//TODO #define AV_COPY(n, d, s) \
//TODO     (((av_alias##n*)(d))->u##n = ((const av_alias##n*)(s))->u##n)

{$ifndef AV_COPY16}
//TODO #   define AV_COPY16(d, s) AV_COPY(16, d, s)
{$endif}

{$ifndef AV_COPY32}
//TODO #   define AV_COPY32(d, s) AV_COPY(32, d, s)
{$endif}

{$ifndef AV_COPY64}
//TODO #   define AV_COPY64(d, s) AV_COPY(64, d, s)
{$endif}

{$ifndef AV_COPY128}
//TODO #   define AV_COPY128(d, s)                    \
//TODO     do {                                       \
//TODO         AV_COPY64(d, s);                       \
//TODO         AV_COPY64((char*)(d)+8, (char*)(s)+8); \
//TODO     } while(0)
{$endif}

//TODO #define AV_SWAP(n, a, b) FFSWAP(av_alias##n, *(av_alias##n*)(a), *(av_alias##n*)(b))

{$ifndef AV_SWAP64}
//TODO #   define AV_SWAP64(a, b) AV_SWAP(64, a, b)
{$endif}

//TODO #define AV_ZERO(n, d) (((av_alias##n*)(d))->u##n = 0)

{$ifndef AV_ZERO16}
//TODO #   define AV_ZERO16(d) AV_ZERO(16, d)
{$endif}

{$ifndef AV_ZERO32}
//TODO #   define AV_ZERO32(d) AV_ZERO(32, d)
{$endif}

{$ifndef AV_ZERO64}
//TODO #   define AV_ZERO64(d) AV_ZERO(64, d)
{$endif}

{$ifndef AV_ZERO128}
//TODO #   define AV_ZERO128(d)         \
//TODO     do {                         \
//TODO         AV_ZERO64(d);            \
//TODO         AV_ZERO64((char*)(d)+8); \
//TODO     } while(0)
{$endif}

// #endif (* AVUTIL_INTREADWRITE_H *)
