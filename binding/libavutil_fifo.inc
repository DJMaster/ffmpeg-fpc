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

(**
 * @file
 * a very simple circular buffer FIFO implementation
 *)

// #ifndef AVUTIL_FIFO_H
// #define AVUTIL_FIFO_H

// #include <stdint.h>
// #include "avutil.h"
// #include "attributes.h"

type
  PAVFifoBuffer = ^AVFifoBuffer;
  AVFifoBuffer = record
    buffer: pcuint8;
    rptr, wptr, end_: pcuint8;
    rndx, wndx: cuint32;
  end;

(**
 * Initialize an AVFifoBuffer.
 * @param size of FIFO
 * @return AVFifoBuffer or NULL in case of memory allocation failure
 *)
function av_fifo_alloc(size: cuint): PAVFifoBuffer; cdecl; external LIB_AVUTIL;

(**
 * Initialize an AVFifoBuffer.
 * @param nmemb number of elements
 * @param size  size of the single element
 * @return AVFifoBuffer or NULL in case of memory allocation failure
 *)
function av_fifo_alloc_array(nmemb: csize_t; size: csize_t): PAVFifoBuffer; cdecl; external LIB_AVUTIL;

(**
 * Free an AVFifoBuffer.
 * @param f AVFifoBuffer to free
 *)
procedure av_fifo_free(f: PAVFifoBuffer); cdecl; external LIB_AVUTIL;

(**
 * Free an AVFifoBuffer and reset pointer to NULL.
 * @param f AVFifoBuffer to free
 *)
procedure av_fifo_freep(f: PPAVFifoBuffer); cdecl; external LIB_AVUTIL;

(**
 * Reset the AVFifoBuffer to the state right after av_fifo_alloc, in particular it is emptied.
 * @param f AVFifoBuffer to reset
 *)
procedure av_fifo_reset(f: PAVFifoBuffer); cdecl; external LIB_AVUTIL;

(**
 * Return the amount of data in bytes in the AVFifoBuffer, that is the
 * amount of data you can read from it.
 * @param f AVFifoBuffer to read from
 * @return size
 *)
function av_fifo_size(const f: PAVFifoBuffer): cint; cdecl; external LIB_AVUTIL;

(**
 * Return the amount of space in bytes in the AVFifoBuffer, that is the
 * amount of data you can write into it.
 * @param f AVFifoBuffer to write into
 * @return size
 *)
function av_fifo_space(const f: PAVFifoBuffer): cint; cdecl; external LIB_AVUTIL;

(**
 * Feed data at specific position from an AVFifoBuffer to a user-supplied callback.
 * Similar as av_fifo_gereric_read but without discarding data.
 * @param f AVFifoBuffer to read from
 * @param offset offset from current read position
 * @param buf_size number of bytes to read
 * @param func generic read function
 * @param dest data destination
 *)
type
  func_proc: procedure (arg1: pointer; arg2: pointer; arg3: cint); cdecl;

function av_fifo_generic_peek_at(f: PAVFifoBuffer; dest: pointer; offset: cint; buf_size: cint; func: func_proc): cint; cdecl; external LIB_AVUTIL;

(**
 * Feed data from an AVFifoBuffer to a user-supplied callback.
 * Similar as av_fifo_gereric_read but without discarding data.
 * @param f AVFifoBuffer to read from
 * @param buf_size number of bytes to read
 * @param func generic read function
 * @param dest data destination
 *)
type
  func_proc: procedure (arg1: pointer; arg2: pointer; arg3: cint); cdecl;

function av_fifo_generic_peek(f: PAVFifoBuffer; dest: pointer; buf_size: cint; func: func_proc): cint; cdecl; external LIB_AVUTIL;

(**
 * Feed data from an AVFifoBuffer to a user-supplied callback.
 * @param f AVFifoBuffer to read from
 * @param buf_size number of bytes to read
 * @param func generic read function
 * @param dest data destination
 *)
type
  func_proc: procedure (arg1: pointer; arg2: pointer; arg3: cint); cdecl;

function av_fifo_generic_read(f: PAVFifoBuffer; dest: pointer; buf_size: cint; func: func_proc): cint; cdecl; external LIB_AVUTIL;

(**
 * Feed data from a user-supplied callback to an AVFifoBuffer.
 * @param f AVFifoBuffer to write to
 * @param src data source; non-const since it may be used as a
 * modifiable context by the function defined in func
 * @param size number of bytes to write
 * @param func generic write function; the first parameter is src,
 * the second is dest_buf, the third is dest_buf_size.
 * func must return the number of bytes written to dest_buf, or <= 0 to
 * indicate no more data available to write.
 * If func is NULL, src is interpreted as a simple byte array for source data.
 * @return the number of bytes written to the FIFO
 *)
type
  func_func: function (arg1: pointer; arg2: pointer; arg3: cint): cint; cdecl;

function av_fifo_generic_write(f: PAVFifoBuffer; src: pointer; size: cint; func: func_func): cint; cdecl; external LIB_AVUTIL;

(**
 * Resize an AVFifoBuffer.
 * In case of reallocation failure, the old FIFO is kept unchanged.
 *
 * @param f AVFifoBuffer to resize
 * @param size new AVFifoBuffer size in bytes
 * @return <0 for failure, >=0 otherwise
 *)
function av_fifo_realloc2(f: PAVFifoBuffer; size: cuint): cint; cdecl; external LIB_AVUTIL;

(**
 * Enlarge an AVFifoBuffer.
 * In case of reallocation failure, the old FIFO is kept unchanged.
 * The new fifo size may be larger than the requested size.
 *
 * @param f AVFifoBuffer to resize
 * @param additional_space the amount of space in bytes to allocate in addition to av_fifo_size()
 * @return <0 for failure, >=0 otherwise
 *)
function av_fifo_grow(f: PAVFifoBuffer; additional_space: cuint): cint; cdecl; external LIB_AVUTIL;

(**
 * Read and discard the specified amount of data from an AVFifoBuffer.
 * @param f AVFifoBuffer to read from
 * @param size amount of data to read in bytes
 *)
procedure av_fifo_drain(f: PAVFifoBuffer; size: cint); cdecl; external LIB_AVUTIL;

(**
 * Return a pointer to the data stored in a FIFO buffer at a certain offset.
 * The FIFO buffer is not modified.
 *
 * @param f    AVFifoBuffer to peek at, f must be non-NULL
 * @param offs an offset in bytes, its absolute value must be less
 *             than the used buffer size or the returned pointer will
 *             point outside to the buffer data.
 *             The used buffer size can be checked with av_fifo_size().
 *)
function av_fifo_peek2(const f: PAVFifoBuffer; offs: cint): pcuint8; inline;
{
    uint8_t *ptr = f->rptr + offs;
    if (ptr >= f->end)
        ptr = f->buffer + (ptr - f->end);
    else if (ptr < f->buffer)
        ptr = f->end - (f->buffer - ptr);
    return ptr;
}

// #endif (* AVUTIL_FIFO_H *)
