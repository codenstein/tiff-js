/*
 * Copyright (c) 1988-1997 Sam Leffler
 * Copyright (c) 1991-1997 Silicon Graphics, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and
 * its documentation for any purpose is hereby granted without fee, provided
 * that (i) the above copyright notices and this permission notice appear in
 * all copies of the software and related documentation, and (ii) the names of
 * Sam Leffler and Silicon Graphics may not be used in any advertising or
 * publicity relating to the software without the specific, prior written
 * permission of Sam Leffler and Silicon Graphics.
 *
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR
 * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,
 * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF
 * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

const tiffh = require("bindings")("tiffh");

const ffi = require("ffi");
const ref = require("ref");
ref.types.struct = require("ref-struct");

// tiffconf.h
const TIFF_INT8_T = ref.types.char;
const TIFF_UINT8_T = ref.types.uchar;

const TIFF_INT16_T = ref.types.short;
const TIFF_UINT16_T = ref.types.ushort;

const TIFF_INT32_T = ref.types.int32;
const TIFF_UINT32_T = ref.types.uint32;

const TIFF_INT64_T = ref.types.int64;
const TIFF_UINT64_T = ref.types.uint64;

/*
 * Intrinsic data types required by the file format:
 *
 * 8-bit quantities     int8/uint8
 * 16-bit quantities    int16/uint16
 * 32-bit quantities    int32/uint32
 * 64-bit quantities    int64/uint64
 * strings              unsigned char*
 */

const int8 = TIFF_INT8_T;
const uint8 = TIFF_UINT8_T;

const int16 = TIFF_INT16_T;
const uint16 = TIFF_UINT16_T;

const int32 = TIFF_INT32_T;
const uint32 = TIFF_UINT32_T;

const int64 = TIFF_INT64_T;
const uint64 = TIFF_UINT64_T;

/*
 * Some types as promoted in a variable argument list
 * We use uint16_vap rather then directly using int, because this way
 * we document the type we actually want to pass through, conceptually,
 * rather then confusing the issue by merely stating the type it gets
 * promoted to
 */

const uint16_vap = ref.types.int;

/*
 * TIFF header.
 */
const TIFFHeaderCommon = ref.types.struct({
  tiff_magic: uint16 /* magic number (defines byte order) */,
  tiff_version: uint16 /* TIFF version number */
});

const TIFFHeaderClassic = ref.types.struct({
  tiff_magic: uint16 /* magic number (defines byte order) */,
  tiff_version: uint16 /* TIFF version number */,
  tiff_diroff: uint32 /* byte offset to first directory */
});

const TIFFHeaderBig = ref.types.struct({
  tiff_magic: uint16 /* magic number (defines byte order) */,
  tiff_version: uint16 /* TIFF version number */,
  tiff_offsetsize: uint16 /* size of offsets, should be 8 */,
  tiff_unused: uint16 /* unused word, should be 0 */,
  tiff_diroff: uint64 /* byte offset to first directory */
});

/*
 * NB: In the comments below,
 *  - items marked with a + are obsoleted by revision 5.0,
 *  - items marked with a ! are introduced in revision 6.0.
 *  - items marked with a % are introduced post revision 6.0.
 *  - items marked with a $ are obsoleted by revision 6.0.
 *  - items marked with a & are introduced by Adobe DNG specification.
 */

/*
 * Tag data type information.
 *
 * Note: RATIONALs are the ratio of two 32-bit integer values.
 */
const TIFFDataType = {
  TIFF_NOTYPE: 0 /* placeholder */,
  TIFF_BYTE: 1 /* 8-bit unsigned integer */,
  TIFF_ASCII: 2 /* 8-bit bytes w/ last byte null */,
  TIFF_SHORT: 3 /* 16-bit unsigned integer */,
  TIFF_LONG: 4 /* 32-bit unsigned integer */,
  TIFF_RATIONAL: 5 /* 64-bit unsigned fraction */,
  TIFF_SBYTE: 6 /* !8-bit signed integer */,
  TIFF_UNDEFINED: 7 /* !8-bit untyped data */,
  TIFF_SSHORT: 8 /* !16-bit signed integer */,
  TIFF_SLONG: 9 /* !32-bit signed integer */,
  TIFF_SRATIONAL: 10 /* !64-bit signed fraction */,
  TIFF_FLOAT: 11 /* !32-bit IEEE floating point */,
  TIFF_DOUBLE: 12 /* !64-bit IEEE floating point */,
  TIFF_IFD: 13 /* %32-bit unsigned integer (offset) */,
  TIFF_LONG8: 16 /* BigTIFF 64-bit unsigned integer */,
  TIFF_SLONG8: 17 /* BigTIFF 64-bit signed integer */,
  TIFF_IFD8: 18 /* BigTIFF 64-bit unsigned integer (offset) */
};

/*
 * TIFF is defined as an incomplete type to hide the
 * library's internal data structures from clients.
 */
const TIFF = ref.types.struct();
const pTIFF = ref.refType(TIFF);

module.exports = {
  TIFF,
  pTIFF,

  TIFF_INT8_T,
  TIFF_UINT8_T,
  TIFF_INT16_T,
  TIFF_UINT16_T,
  TIFF_INT32_T,
  TIFF_UINT32_T,
  TIFF_INT64_T,
  TIFF_UINT64_T,

  int8,
  uint8,
  int16,
  uint16,
  int32,
  uint32,
  int64,
  uint64,

  uint16_vap,

  TIFFHeaderCommon,
  TIFFHeaderClassic,
  TIFFHeaderBig,

  TIFFDataType,

  // constants
  ...require("bindings")("tiffh").constants
};
