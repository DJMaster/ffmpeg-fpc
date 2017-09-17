//
// avutil.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(*
 * Copyright (c) 2007 Mans Rullgard
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

// #ifndef AVUTIL_AVSTRING_H
// #define AVUTIL_AVSTRING_H

// #include <stddef.h>
// #include <stdint.h>
// #include "attributes.h"

(**
 * @addtogroup lavu_string
 * @{
 *)

(**
 * Return non-zero if pfx is a prefix of str. If it is, *ptr is set to
 * the address of the first character in str after the prefix.
 *
 * @param str input string
 * @param pfx prefix to test
 * @param ptr updated if the prefix is matched inside str
 * @return non-zero if the prefix matches, zero otherwise
 *)
function av_strstart(const str: pchar; const pfx: pchar; const ptr: ppchar): cint; cdecl; external LIB_AVUTIL;

(**
 * Return non-zero if pfx is a prefix of str independent of case. If
 * it is, *ptr is set to the address of the first character in str
 * after the prefix.
 *
 * @param str input string
 * @param pfx prefix to test
 * @param ptr updated if the prefix is matched inside str
 * @return non-zero if the prefix matches, zero otherwise
 *)
function av_stristart(const str: pchar; const pfx: pchar; const ptr: ppchar): cint; cdecl; external LIB_AVUTIL;

(**
 * Locate the first case-independent occurrence in the string haystack
 * of the string needle.  A zero-length string needle is considered to
 * match at the start of haystack.
 *
 * This function is a case-insensitive version of the standard strstr().
 *
 * @param haystack string to search in
 * @param needle   string to search for
 * @return         pointer to the located match within haystack
 *                 or a null pointer if no match
 *)
function av_stristr(const haystack: pchar; const needle: pchar): pchar; cdecl; external LIB_AVUTIL;

(**
 * Locate the first occurrence of the string needle in the string haystack
 * where not more than hay_length characters are searched. A zero-length
 * string needle is considered to match at the start of haystack.
 *
 * This function is a length-limited version of the standard strstr().
 *
 * @param haystack   string to search in
 * @param needle     string to search for
 * @param hay_length length of string to search in
 * @return           pointer to the located match within haystack
 *                   or a null pointer if no match
 *)
function av_strnstr(const haystack: pchar; const needle: pchar; hay_length: csize_t): pchar; cdecl; external LIB_AVUTIL;

(**
 * Copy the string src to dst, but no more than size - 1 bytes, and
 * null-terminate dst.
 *
 * This function is the same as BSD strlcpy().
 *
 * @param dst destination buffer
 * @param src source string
 * @param size size of destination buffer
 * @return the length of src
 *
 * @warning since the return value is the length of src, src absolutely
 * _must_ be a properly 0-terminated string, otherwise this will read beyond
 * the end of the buffer and possibly crash.
 *)
function av_strlcpy(dst: pchar; const src: pchar; size: csize_t): csize_t; cdecl; external LIB_AVUTIL;

(**
 * Append the string src to the string dst, but to a total length of
 * no more than size - 1 bytes, and null-terminate dst.
 *
 * This function is similar to BSD strlcat(), but differs when
 * size <= strlen(dst).
 *
 * @param dst destination buffer
 * @param src source string
 * @param size size of destination buffer
 * @return the total length of src and dst
 *
 * @warning since the return value use the length of src and dst, these
 * absolutely _must_ be a properly 0-terminated strings, otherwise this
 * will read beyond the end of the buffer and possibly crash.
 *)
function av_strlcat(dst: pchar; const src: pchar; size: csize_t): csize_t; cdecl; external LIB_AVUTIL;

(**
 * Append output to a string, according to a format. Never write out of
 * the destination buffer, and always put a terminating 0 within
 * the buffer.
 * @param dst destination buffer (string to which the output is
 *  appended)
 * @param size total size of the destination buffer
 * @param fmt printf-compatible format string, specifying how the
 *  following parameters are used
 * @return the length of the string that would have been generated
 *  if enough space had been available
 *)
//TODO av_printf_format(3, 4)
function av_strlcatf(dst: pchar; size: csize_t; const fmt: pchar; args: array of const): csize_t; cdecl; external LIB_AVUTIL;

(**
 * Get the count of continuous non zero chars starting from the beginning.
 *
 * @param len maximum number of characters to check in the string, that
 *            is the maximum value which is returned by the function
 *)
function av_strnlen(const s: pchar; len: csize_t): csize_t; inline;
{
    size_t i;
    for (i = 0; i < len && s[i]; i++)
        ;
    return i;
}

(**
 * Print arguments following specified format into a large enough auto
 * allocated buffer. It is similar to GNU asprintf().
 * @param fmt printf-compatible format string, specifying how the
 *            following parameters are used.
 * @return the allocated string
 * @note You have to free the string yourself with av_free().
 *)
//TODO av_printf_format(1, 2)
function av_asprintf(const fmt: pchar; args: array of const): pchar; cdecl; external LIB_AVUTIL;

(**
 * Convert a number to an av_malloced string.
 *)
function av_d2str(d: cdouble): pchar; cdecl; external LIB_AVUTIL;

(**
 * Unescape the given string until a non escaped terminating char,
 * and return the token corresponding to the unescaped string.
 *
 * The normal \ and ' escaping is supported. Leading and trailing
 * whitespaces are removed, unless they are escaped with '\' or are
 * enclosed between ''.
 *
 * @param buf the buffer to parse, buf will be updated to point to the
 * terminating char
 * @param term a 0-terminated list of terminating chars
 * @return the malloced unescaped string, which must be av_freed by
 * the user, NULL in case of allocation failure
 *)
function av_get_token(const buf: ppchar; const term: pchar): pchar; cdecl; external LIB_AVUTIL;

(**
 * Split the string into several tokens which can be accessed by
 * successive calls to av_strtok().
 *
 * A token is defined as a sequence of characters not belonging to the
 * set specified in delim.
 *
 * On the first call to av_strtok(), s should point to the string to
 * parse, and the value of saveptr is ignored. In subsequent calls, s
 * should be NULL, and saveptr should be unchanged since the previous
 * call.
 *
 * This function is similar to strtok_r() defined in POSIX.1.
 *
 * @param s the string to parse, may be NULL
 * @param delim 0-terminated list of token delimiters, must be non-NULL
 * @param saveptr user-provided pointer which points to stored
 * information necessary for av_strtok() to continue scanning the same
 * string. saveptr is updated to point to the next character after the
 * first delimiter found, or to NULL if the string was terminated
 * @return the found token, or NULL when no token is found
 *)
function av_strtok(s: pchar; const delim: pchar; saveptr: ppchar): pchar; cdecl; external LIB_AVUTIL;

(**
 * Locale-independent conversion of ASCII isdigit.
 *)
function av_isdigit(c: cint): cint; inline;
{
    return c >= '0' && c <= '9';
}

(**
 * Locale-independent conversion of ASCII isgraph.
 *)
function av_isgraph(c: cint): cint; inline;
{
    return c > 32 && c < 127;
}

(**
 * Locale-independent conversion of ASCII isspace.
 *)
function av_isspace(c: cint): cint; inline;
{
    return c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' ||
           c == '\v';
}

(**
 * Locale-independent conversion of ASCII characters to uppercase.
 *)
function av_toupper(c: cint): cint; inline;
{
    if (c >= 'a' && c <= 'z')
        c ^= $20;
    return c;
}

(**
 * Locale-independent conversion of ASCII characters to lowercase.
 *)
function av_tolower(c: cint): cint; inline;
{
    if (c >= 'A' && c <= 'Z')
        c ^= $20;
    return c;
}

(**
 * Locale-independent conversion of ASCII isxdigit.
 *)
function av_isxdigit(c: cint): cint; inline;
{
    c = av_tolower(c);
    return av_isdigit(c) || (c >= 'a' && c <= 'f');
}

(**
 * Locale-independent case-insensitive compare.
 * @note This means only ASCII-range characters are case-insensitive
 *)
function av_strcasecmp(const a: pchar; const b: pchar): cint; cdecl; external LIB_AVUTIL;

(**
 * Locale-independent case-insensitive compare.
 * @note This means only ASCII-range characters are case-insensitive
 *)
function av_strncasecmp(const a: pchar; const b: pchar; n: csize_t): cint; cdecl; external LIB_AVUTIL;

(**
 * Thread safe basename.
 * @param path the path, on DOS both \ and / are considered separators.
 * @return pointer to the basename substring.
 *)
function av_basename(const path: pchar): pchar; cdecl; external LIB_AVUTIL;

(**
 * Thread safe dirname.
 * @param path the path, on DOS both \ and / are considered separators.
 * @return the path with the separator replaced by the string terminator or ".".
 * @note the function may change the input string.
 *)
function av_dirname(path: pchar): pchar; cdecl; external LIB_AVUTIL;

(**
 * Match instances of a name in a comma-separated list of names.
 * List entries are checked from the start to the end of the names list,
 * the first match ends further processing. If an entry prefixed with '-'
 * matches, then 0 is returned. The "ALL" list entry is considered to
 * match all names.
 *
 * @param name  Name to look for.
 * @param names List of names.
 * @return 1 on match, 0 otherwise.
 *)
function av_match_name(const name: pchar; const names: pchar): cint; cdecl; external LIB_AVUTIL;

(**
 * Append path component to the existing path.
 * Path separator '/' is placed between when needed.
 * Resulting string have to be freed with av_free().
 * @param path      base path
 * @param component component to be appended
 * @return new path or NULL on error.
 *)
function av_append_path_component(const path: pchar; const component: pchar): pchar; cdecl; external LIB_AVUTIL;

type
  AVEscapeMode = (
    AV_ESCAPE_MODE_AUTO, ///< Use auto-selected escaping mode.
    AV_ESCAPE_MODE_BACKSLASH, ///< Use backslash escaping.
    AV_ESCAPE_MODE_QUOTE ///< Use single-quote escaping.
  );

(**
 * Consider spaces special and escape them even in the middle of the
 * string.
 *
 * This is equivalent to adding the whitespace characters to the special
 * characters lists, except it is guaranteed to use the exact same list
 * of whitespace characters as the rest of libavutil.
 *)
const
  AV_ESCAPE_FLAG_WHITESPACE = (1 shl 0);

(**
 * Escape only specified special characters.
 * Without this flag, escape also any characters that may be considered
 * special by av_get_token(), such as the single quote.
 *)
  AV_ESCAPE_FLAG_STRICT = (1 shl 1);

(**
 * Escape string in src, and put the escaped string in an allocated
 * string in *dst, which must be freed with av_free().
 *
 * @param dst           pointer where an allocated string is put
 * @param src           string to escape, must be non-NULL
 * @param special_chars string containing the special characters which
 *                      need to be escaped, can be NULL
 * @param mode          escape mode to employ, see AV_ESCAPE_MODE_* macros.
 *                      Any unknown value for mode will be considered equivalent to
 *                      AV_ESCAPE_MODE_BACKSLASH, but this behaviour can change without
 *                      notice.
 * @param flags         flags which control how to escape, see AV_ESCAPE_FLAG_ macros
 * @return the length of the allocated string, or a negative error code in case of error
 * @see av_bprint_escape()
 *)
//TODO av_warn_unused_result
function av_escape(dst: ppchar; const src: pchar; const special_chars: pchar; mode: AVEscapeMode; flags: cint): cint; cdecl; external LIB_AVUTIL;

const
  AV_UTF8_FLAG_ACCEPT_INVALID_BIG_CODES = 1; ///< accept codepoints over 0x10FFFF
  AV_UTF8_FLAG_ACCEPT_NON_CHARACTERS = 2; ///< accept non-characters - 0xFFFE and 0xFFFF
  AV_UTF8_FLAG_ACCEPT_SURROGATES = 4; ///< accept UTF-16 surrogates codes
  AV_UTF8_FLAG_EXCLUDE_XML_INVALID_CONTROL_CODES = 8; ///< exclude control codes not accepted by XML

  AV_UTF8_FLAG_ACCEPT_ALL = AV_UTF8_FLAG_ACCEPT_INVALID_BIG_CODES or AV_UTF8_FLAG_ACCEPT_NON_CHARACTERS or AV_UTF8_FLAG_ACCEPT_SURROGATES;

(**
 * Read and decode a single UTF-8 code point (character) from the
 * buffer in *buf, and update *buf to point to the next byte to
 * decode.
 *
 * In case of an invalid byte sequence, the pointer will be updated to
 * the next byte after the invalid sequence and the function will
 * return an error code.
 *
 * Depending on the specified flags, the function will also fail in
 * case the decoded code point does not belong to a valid range.
 *
 * @note For speed-relevant code a carefully implemented use of
 * GET_UTF8() may be preferred.
 *
 * @param codep   pointer used to return the parsed code in case of success.
 *                The value in *codep is set even in case the range check fails.
 * @param bufp    pointer to the address the first byte of the sequence
 *                to decode, updated by the function to point to the
 *                byte next after the decoded sequence
 * @param buf_end pointer to the end of the buffer, points to the next
 *                byte past the last in the buffer. This is used to
 *                avoid buffer overreads (in case of an unfinished
 *                UTF-8 sequence towards the end of the buffer).
 * @param flags   a collection of AV_UTF8_FLAG_* flags
 * @return >= 0 in case a sequence was successfully read, a negative
 * value in case of invalid sequence
 *)
//TODO av_warn_unused_result
function av_utf8_decode(codep: pcint32; const bufp: ppcuint8; const buf_end: pcuint8; flags: cuint): cint; cdecl; external LIB_AVUTIL;

(**
 * Check if a name is in a list.
 * @returns 0 if not found, or the 1 based index where it has been found in the
 *            list.
 *)
function av_match_list(const name: pchar; const list: pchar; separator: char): cint; cdecl; external LIB_AVUTIL;

(**
 * @}
 *)

// #endif (* AVUTIL_AVSTRING_H *)
