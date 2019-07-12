#include <nan.h>
#include "../tiff.h"

using namespace v8;

void InitConstants(v8::Local<v8::Object> exports)
{
    v8::Local<v8::Object> constants = Nan::New<v8::Object>();

    NODE_DEFINE_CONSTANT(constants, TIFF_VERSION_CLASSIC);
    NODE_DEFINE_CONSTANT(constants, TIFF_VERSION_BIG);

    NODE_DEFINE_CONSTANT(constants, TIFF_BIGENDIAN);
    NODE_DEFINE_CONSTANT(constants, TIFF_LITTLEENDIAN);
    NODE_DEFINE_CONSTANT(constants, MDI_LITTLEENDIAN);
    NODE_DEFINE_CONSTANT(constants, MDI_BIGENDIAN);

    /*
 * TIFF Tag Definitions.
 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_SUBFILETYPE, 254);             /* subfile data descriptor */
    NODE_DEFINE_CONSTANT(constants, FILETYPE_REDUCEDIMAGE, 0x1);           /* reduced resolution version */
    NODE_DEFINE_CONSTANT(constants, FILETYPE_PAGE, 0x2);                   /* one page of many */
    NODE_DEFINE_CONSTANT(constants, FILETYPE_MASK, 0x4);                   /* transparency mask */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_OSUBFILETYPE, 255);            /* +kind of data in subfile */
    NODE_DEFINE_CONSTANT(constants, OFILETYPE_IMAGE, 1);                   /* full resolution image data */
    NODE_DEFINE_CONSTANT(constants, OFILETYPE_REDUCEDIMAGE, 2);            /* reduced size image data */
    NODE_DEFINE_CONSTANT(constants, OFILETYPE_PAGE, 3);                    /* one page of many */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IMAGEWIDTH, 256);              /* image width in pixels */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IMAGELENGTH, 257);             /* image height in pixels */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_BITSPERSAMPLE, 258);           /* bits per channel (sample) */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_COMPRESSION, 259);             /* data compression technique */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_NONE, 1);                  /* dump mode */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_CCITTRLE, 2);              /* CCITT modified Huffman RLE */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_CCITTFAX3, 3);             /* CCITT Group 3 fax encoding */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_CCITT_T4, 3);              /* CCITT T.4 (TIFF 6 name) */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_CCITTFAX4, 4);             /* CCITT Group 4 fax encoding */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_CCITT_T6, 4);              /* CCITT T.6 (TIFF 6 name) */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_LZW, 5);                   /* Lempel-Ziv  & Welch */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_OJPEG, 6);                 /* !6.0 JPEG */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_JPEG, 7);                  /* %JPEG DCT compression */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_T85, 9);                   /* !TIFF/FX T.85 JBIG compression */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_T43, 10);                  /* !TIFF/FX T.43 colour by layered JBIG compression */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_NEXT, 32766);              /* NeXT 2-bit RLE */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_CCITTRLEW, 32771);         /* #1 w/ word alignment */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_PACKBITS, 32773);          /* Macintosh RLE */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_THUNDERSCAN, 32809);       /* ThunderScan RLE */
                                                                           /* codes 32895-32898 are reserved for ANSI IT8 TIFF/IT <dkelly@apago.com) */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_IT8CTPAD, 32895);          /* IT8 CT w/padding */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_IT8LW, 32896);             /* IT8 Linework RLE */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_IT8MP, 32897);             /* IT8 Monochrome picture */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_IT8BL, 32898);             /* IT8 Binary line art */
                                                                           /* compression codes 32908-32911 are reserved for Pixar */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_PIXARFILM, 32908);         /* Pixar companded 10bit LZW */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_PIXARLOG, 32909);          /* Pixar companded 11bit ZIP */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_DEFLATE, 32946);           /* Deflate compression */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_ADOBE_DEFLATE, 8);         /* Deflate compression, \
			   as recognized by Adobe */
                                                                           /* compression code 32947 is reserved for Oceana Matrix <dev@oceana.com> */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_DCS, 32947);               /* Kodak DCS encoding */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_JBIG, 34661);              /* ISO JBIG */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_SGILOG, 34676);            /* SGI Log Luminance RLE */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_SGILOG24, 34677);          /* SGI Log 24-bit packed */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_JP2000, 34712);            /* Leadtools JPEG2000 */
    NODE_DEFINE_CONSTANT(constants, COMPRESSION_LZMA, 34925);              /* LZMA2 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PHOTOMETRIC, 262);             /* photometric interpretation */
    NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_MINISWHITE, 0);            /* min value is white */
    NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_MINISBLACK, 1);            /* min value is black */
    NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_RGB, 2);                   /* RGB color model */
    NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_PALETTE, 3);               /* color map indexed */
    NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_MASK, 4);                  /* $holdout mask */
    NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_SEPARATED, 5);             /* !color separations */
    NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_YCBCR, 6);                 /* !CCIR 601 */
    NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_CIELAB, 8);                /* !1976 CIE L*a*b* */
    NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_ICCLAB, 9);                /* ICC L*a*b* [Adobe TIFF Technote 4] */
    NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_ITULAB, 10);               /* ITU L*a*b* */
    NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_CFA, 32803);               /* color filter array */
    NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_LOGL, 32844);              /* CIE Log2(L) */
    NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_LOGLUV, 32845);            /* CIE Log2(L) (u',v') */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_THRESHHOLDING, 263);           /* +thresholding used on data */
    NODE_DEFINE_CONSTANT(constants, THRESHHOLD_BILEVEL, 1);                /* b&w art scan */
    NODE_DEFINE_CONSTANT(constants, THRESHHOLD_HALFTONE, 2);               /* or dithered scan */
    NODE_DEFINE_CONSTANT(constants, THRESHHOLD_ERRORDIFFUSE, 3);           /* usually floyd-steinberg */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CELLWIDTH, 264);               /* +dithering matrix width */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CELLLENGTH, 265);              /* +dithering matrix height */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_FILLORDER, 266);               /* data order within a byte */
    NODE_DEFINE_CONSTANT(constants, FILLORDER_MSB2LSB, 1);                 /* most significant -> least */
    NODE_DEFINE_CONSTANT(constants, FILLORDER_LSB2MSB, 2);                 /* least significant -> most */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DOCUMENTNAME, 269);            /* name of doc. image is from */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IMAGEDESCRIPTION, 270);        /* info about image */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_MAKE, 271);                    /* scanner manufacturer name */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_MODEL, 272);                   /* scanner model name/number */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_STRIPOFFSETS, 273);            /* offsets to data strips */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ORIENTATION, 274);             /* +image orientation */
    NODE_DEFINE_CONSTANT(constants, ORIENTATION_TOPLEFT, 1);               /* row 0 top, col 0 lhs */
    NODE_DEFINE_CONSTANT(constants, ORIENTATION_TOPRIGHT, 2);              /* row 0 top, col 0 rhs */
    NODE_DEFINE_CONSTANT(constants, ORIENTATION_BOTRIGHT, 3);              /* row 0 bottom, col 0 rhs */
    NODE_DEFINE_CONSTANT(constants, ORIENTATION_BOTLEFT, 4);               /* row 0 bottom, col 0 lhs */
    NODE_DEFINE_CONSTANT(constants, ORIENTATION_LEFTTOP, 5);               /* row 0 lhs, col 0 top */
    NODE_DEFINE_CONSTANT(constants, ORIENTATION_RIGHTTOP, 6);              /* row 0 rhs, col 0 top */
    NODE_DEFINE_CONSTANT(constants, ORIENTATION_RIGHTBOT, 7);              /* row 0 rhs, col 0 bottom */
    NODE_DEFINE_CONSTANT(constants, ORIENTATION_LEFTBOT, 8);               /* row 0 lhs, col 0 bottom */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_SAMPLESPERPIXEL, 277);         /* samples per pixel */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ROWSPERSTRIP, 278);            /* rows per strip of data */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_STRIPBYTECOUNTS, 279);         /* bytes counts for strips */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_MINSAMPLEVALUE, 280);          /* +minimum sample value */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_MAXSAMPLEVALUE, 281);          /* +maximum sample value */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_XRESOLUTION, 282);             /* pixels/resolution in x */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_YRESOLUTION, 283);             /* pixels/resolution in y */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PLANARCONFIG, 284);            /* storage organization */
    NODE_DEFINE_CONSTANT(constants, PLANARCONFIG_CONTIG, 1);               /* single image plane */
    NODE_DEFINE_CONSTANT(constants, PLANARCONFIG_SEPARATE, 2);             /* separate planes of data */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PAGENAME, 285);                /* page name image is from */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_XPOSITION, 286);               /* x page offset of image lhs */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_YPOSITION, 287);               /* y page offset of image lhs */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_FREEOFFSETS, 288);             /* +byte offset to free block */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_FREEBYTECOUNTS, 289);          /* +sizes of free blocks */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_GRAYRESPONSEUNIT, 290);        /* $gray scale curve accuracy */
    NODE_DEFINE_CONSTANT(constants, GRAYRESPONSEUNIT_10S, 1);              /* tenths of a unit */
    NODE_DEFINE_CONSTANT(constants, GRAYRESPONSEUNIT_100S, 2);             /* hundredths of a unit */
    NODE_DEFINE_CONSTANT(constants, GRAYRESPONSEUNIT_1000S, 3);            /* thousandths of a unit */
    NODE_DEFINE_CONSTANT(constants, GRAYRESPONSEUNIT_10000S, 4);           /* ten-thousandths of a unit */
    NODE_DEFINE_CONSTANT(constants, GRAYRESPONSEUNIT_100000S, 5);          /* hundred-thousandths */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_GRAYRESPONSECURVE, 291);       /* $gray scale response curve */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_GROUP3OPTIONS, 292);           /* 32 flag bits */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_T4OPTIONS, 292);               /* TIFF 6.0 proper name alias */
    NODE_DEFINE_CONSTANT(constants, GROUP3OPT_2DENCODING, 0x1);            /* 2-dimensional coding */
    NODE_DEFINE_CONSTANT(constants, GROUP3OPT_UNCOMPRESSED, 0x2);          /* data not compressed */
    NODE_DEFINE_CONSTANT(constants, GROUP3OPT_FILLBITS, 0x4);              /* fill to byte boundary */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_GROUP4OPTIONS, 293);           /* 32 flag bits */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_T6OPTIONS, 293);               /* TIFF 6.0 proper name */
    NODE_DEFINE_CONSTANT(constants, GROUP4OPT_UNCOMPRESSED, 0x2);          /* data not compressed */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_RESOLUTIONUNIT, 296);          /* units of resolutions */
    NODE_DEFINE_CONSTANT(constants, RESUNIT_NONE, 1);                      /* no meaningful units */
    NODE_DEFINE_CONSTANT(constants, RESUNIT_INCH, 2);                      /* english */
    NODE_DEFINE_CONSTANT(constants, RESUNIT_CENTIMETER, 3);                /* metric */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PAGENUMBER, 297);              /* page numbers of multi-page */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_COLORRESPONSEUNIT, 300);       /* $color curve accuracy */
    NODE_DEFINE_CONSTANT(constants, COLORRESPONSEUNIT_10S, 1);             /* tenths of a unit */
    NODE_DEFINE_CONSTANT(constants, COLORRESPONSEUNIT_100S, 2);            /* hundredths of a unit */
    NODE_DEFINE_CONSTANT(constants, COLORRESPONSEUNIT_1000S, 3);           /* thousandths of a unit */
    NODE_DEFINE_CONSTANT(constants, COLORRESPONSEUNIT_10000S, 4);          /* ten-thousandths of a unit */
    NODE_DEFINE_CONSTANT(constants, COLORRESPONSEUNIT_100000S, 5);         /* hundred-thousandths */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_TRANSFERFUNCTION, 301);        /* !colorimetry info */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_SOFTWARE, 305);                /* name & release */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DATETIME, 306);                /* creation date and time */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ARTIST, 315);                  /* creator of image */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_HOSTCOMPUTER, 316);            /* machine where created */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PREDICTOR, 317);               /* prediction scheme w/ LZW */
    NODE_DEFINE_CONSTANT(constants, PREDICTOR_NONE, 1);                    /* no prediction scheme used */
    NODE_DEFINE_CONSTANT(constants, PREDICTOR_HORIZONTAL, 2);              /* horizontal differencing */
    NODE_DEFINE_CONSTANT(constants, PREDICTOR_FLOATINGPOINT, 3);           /* floating point predictor */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_WHITEPOINT, 318);              /* image white point */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PRIMARYCHROMATICITIES, 319);   /* !primary chromaticities */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_COLORMAP, 320);                /* RGB map for palette image */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_HALFTONEHINTS, 321);           /* !highlight+shadow info */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_TILEWIDTH, 322);               /* !tile width in pixels */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_TILELENGTH, 323);              /* !tile height in pixels */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_TILEOFFSETS, 324);             /* !offsets to data tiles */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_TILEBYTECOUNTS, 325);          /* !byte counts for tiles */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_BADFAXLINES, 326);             /* lines w/ wrong pixel count */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CLEANFAXDATA, 327);            /* regenerated line info */
    NODE_DEFINE_CONSTANT(constants, CLEANFAXDATA_CLEAN, 0);                /* no errors detected */
    NODE_DEFINE_CONSTANT(constants, CLEANFAXDATA_REGENERATED, 1);          /* receiver regenerated lines */
    NODE_DEFINE_CONSTANT(constants, CLEANFAXDATA_UNCLEAN, 2);              /* uncorrected errors exist */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CONSECUTIVEBADFAXLINES, 328);  /* max consecutive bad lines */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_SUBIFD, 330);                  /* subimage descriptors */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_INKSET, 332);                  /* !inks in separated image */
    NODE_DEFINE_CONSTANT(constants, INKSET_CMYK, 1);                       /* !cyan-magenta-yellow-black color */
    NODE_DEFINE_CONSTANT(constants, INKSET_MULTIINK, 2);                   /* !multi-ink or hi-fi color */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_INKNAMES, 333);                /* !ascii names of inks */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_NUMBEROFINKS, 334);            /* !number of inks */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DOTRANGE, 336);                /* !0% and 100% dot codes */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_TARGETPRINTER, 337);           /* !separation target */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_EXTRASAMPLES, 338);            /* !info about extra samples */
    NODE_DEFINE_CONSTANT(constants, EXTRASAMPLE_UNSPECIFIED, 0);           /* !unspecified data */
    NODE_DEFINE_CONSTANT(constants, EXTRASAMPLE_ASSOCALPHA, 1);            /* !associated alpha data */
    NODE_DEFINE_CONSTANT(constants, EXTRASAMPLE_UNASSALPHA, 2);            /* !unassociated alpha data */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_SAMPLEFORMAT, 339);            /* !data sample format */
    NODE_DEFINE_CONSTANT(constants, SAMPLEFORMAT_UINT, 1);                 /* !unsigned integer data */
    NODE_DEFINE_CONSTANT(constants, SAMPLEFORMAT_INT, 2);                  /* !signed integer data */
    NODE_DEFINE_CONSTANT(constants, SAMPLEFORMAT_IEEEFP, 3);               /* !IEEE floating point data */
    NODE_DEFINE_CONSTANT(constants, SAMPLEFORMAT_VOID, 4);                 /* !untyped data */
    NODE_DEFINE_CONSTANT(constants, SAMPLEFORMAT_COMPLEXINT, 5);           /* !complex signed int */
    NODE_DEFINE_CONSTANT(constants, SAMPLEFORMAT_COMPLEXIEEEFP, 6);        /* !complex ieee floating */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_SMINSAMPLEVALUE, 340);         /* !variable MinSampleValue */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_SMAXSAMPLEVALUE, 341);         /* !variable MaxSampleValue */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CLIPPATH, 343);                /* %ClipPath \
								  [Adobe TIFF technote 2] */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_XCLIPPATHUNITS, 344);          /* %XClipPathUnits \
							  [Adobe TIFF technote 2] */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_YCLIPPATHUNITS, 345);          /* %YClipPathUnits \
							  [Adobe TIFF technote 2] */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_INDEXED, 346);                 /* %Indexed \
								  [Adobe TIFF Technote 3] */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGTABLES, 347);              /* %JPEG table stream */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_OPIPROXY, 351);                /* %OPI Proxy [Adobe TIFF technote] */
                                                                           /* Tags 400-435 are from the TIFF/FX spec */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_GLOBALPARAMETERSIFD, 400);     /* ! */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PROFILETYPE, 401);             /* ! */
    NODE_DEFINE_CONSTANT(constants, PROFILETYPE_UNSPECIFIED, 0);           /* ! */
    NODE_DEFINE_CONSTANT(constants, PROFILETYPE_G3_FAX, 1);                /* ! */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXPROFILE, 402);              /* ! */
    NODE_DEFINE_CONSTANT(constants, FAXPROFILE_S, 1);                      /* !TIFF/FX FAX profile S */
    NODE_DEFINE_CONSTANT(constants, FAXPROFILE_F, 2);                      /* !TIFF/FX FAX profile F */
    NODE_DEFINE_CONSTANT(constants, FAXPROFILE_J, 3);                      /* !TIFF/FX FAX profile J */
    NODE_DEFINE_CONSTANT(constants, FAXPROFILE_C, 4);                      /* !TIFF/FX FAX profile C */
    NODE_DEFINE_CONSTANT(constants, FAXPROFILE_L, 5);                      /* !TIFF/FX FAX profile L */
    NODE_DEFINE_CONSTANT(constants, FAXPROFILE_M, 6);                      /* !TIFF/FX FAX profile LM */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CODINGMETHODS, 403);           /* !TIFF/FX coding methods */
    NODE_DEFINE_CONSTANT(constants, CODINGMETHODS_T4_1D, (1 << 1));        /* !T.4 1D */
    NODE_DEFINE_CONSTANT(constants, CODINGMETHODS_T4_2D, (1 << 2));        /* !T.4 2D */
    NODE_DEFINE_CONSTANT(constants, CODINGMETHODS_T6, (1 << 3));           /* !T.6 */
    NODE_DEFINE_CONSTANT(constants, CODINGMETHODS_T85, (1 << 4));          /* !T.85 JBIG */
    NODE_DEFINE_CONSTANT(constants, CODINGMETHODS_T42, (1 << 5));          /* !T.42 JPEG */
    NODE_DEFINE_CONSTANT(constants, CODINGMETHODS_T43, (1 << 6));          /* !T.43 colour by layered JBIG */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_VERSIONYEAR, 404);             /* !TIFF/FX version year */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_MODENUMBER, 405);              /* !TIFF/FX mode number */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DECODE, 433);                  /* !TIFF/FX decode */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IMAGEBASECOLOR, 434);          /* !TIFF/FX image base colour */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_T82OPTIONS, 435);              /* !TIFF/FX T.82 options */
                                                                           /*
 * Tags 512-521 are obsoleted by Technical Note #2 which specifies a
 * revised JPEG-in-TIFF scheme.
 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGPROC, 512);                /* !JPEG processing algorithm */
    NODE_DEFINE_CONSTANT(constants, JPEGPROC_BASELINE, 1);                 /* !baseline sequential */
    NODE_DEFINE_CONSTANT(constants, JPEGPROC_LOSSLESS, 14);                /* !Huffman coded lossless */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGIFOFFSET, 513);            /* !pointer to SOI marker */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGIFBYTECOUNT, 514);         /* !JFIF stream length */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGRESTARTINTERVAL, 515);     /* !restart interval length */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGLOSSLESSPREDICTORS, 517);  /* !lossless proc predictor */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGPOINTTRANSFORM, 518);      /* !lossless point transform */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGQTABLES, 519);             /* !Q matrix offsets */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGDCTABLES, 520);            /* !DCT table offsets */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGACTABLES, 521);            /* !AC coefficient offsets */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_YCBCRCOEFFICIENTS, 529);       /* !RGB -> YCbCr transform */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_YCBCRSUBSAMPLING, 530);        /* !YCbCr subsampling factors */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_YCBCRPOSITIONING, 531);        /* !subsample positioning */
    NODE_DEFINE_CONSTANT(constants, YCBCRPOSITION_CENTERED, 1);            /* !as in PostScript Level 2 */
    NODE_DEFINE_CONSTANT(constants, YCBCRPOSITION_COSITED, 2);             /* !as in CCIR 601-1 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_REFERENCEBLACKWHITE, 532);     /* !colorimetry info */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_STRIPROWCOUNTS, 559);          /* !TIFF/FX strip row counts */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_XMLPACKET, 700);               /* %XML packet   \
								  [Adobe XMP Specification, \
								  January 2004 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_OPIIMAGEID, 32781);            /* %OPI ImageID \
							  [Adobe TIFF technote] */
                                                                           /* tags 32952-32956 are private tags registered to Island Graphics */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_REFPTS, 32953);                /* image reference points */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_REGIONTACKPOINT, 32954);       /* region-xform tack point */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_REGIONWARPCORNERS, 32955);     /* warp quadrilateral */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_REGIONAFFINE, 32956);          /* affine transformation mat */
                                                                           /* tags 32995-32999 are private tags registered to SGI */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_MATTEING, 32995);              /* $use ExtraSamples */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DATATYPE, 32996);              /* $use SampleFormat */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IMAGEDEPTH, 32997);            /* z depth of image */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_TILEDEPTH, 32998);             /* z depth/data tile */
                                                                           /* tags 33300-33309 are private tags registered to Pixar */
                                                                           /*
 * TIFFTAG_PIXAR_IMAGEFULLWIDTH and TIFFTAG_PIXAR_IMAGEFULLLENGTH
 * are set when an image has been cropped out of a larger image.  
 * They reflect the size of the original uncropped image.
 * The TIFFTAG_XPOSITION and TIFFTAG_YPOSITION can be used
 * to determine the position of the smaller image in the larger one.
 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_IMAGEFULLWIDTH, 33300);  /* full image size in x */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_IMAGEFULLLENGTH, 33301); /* full image size in y */
                                                                           /* Tags 33302-33306 are used to identify special image modes and data
  * used by Pixar's texture formats.
  */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_TEXTUREFORMAT, 33302);   /* texture map format */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_WRAPMODES, 33303);       /* s & t wrap modes */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_FOVCOT, 33304);          /* cotan(fov) for env. maps */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_MATRIX_WORLDTOSCREEN, 33305);
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_MATRIX_WORLDTOCAMERA, 33306);
    /* tag 33405 is a private tag registered to Eastman Kodak */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_WRITERSERIALNUMBER, 33405);  /* device serial number */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CFAREPEATPATTERNDIM, 33421); /* dimensions of CFA pattern */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CFAPATTERN, 33422);          /* color filter array pattern */
                                                                         /* tag 33432 is listed in the 6.0 spec w/ unknown ownership */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_COPYRIGHT, 33432);           /* copyright string */
                                                                         /* IPTC TAG from RichTIFF specifications */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_RICHTIFFIPTC, 33723);
    /* 34016-34029 are reserved for ANSI IT8 TIFF/IT <dkelly@apago.com) */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8SITE, 34016);                     /* site name */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8COLORSEQUENCE, 34017);            /* color seq. [RGB,CMYK,etc] */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8HEADER, 34018);                   /* DDES Header */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8RASTERPADDING, 34019);            /* raster scanline padding */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8BITSPERRUNLENGTH, 34020);         /* # of bits in short run */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8BITSPEREXTENDEDRUNLENGTH, 34021); /* # of bits in long run */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8COLORTABLE, 34022);               /* LW colortable */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8IMAGECOLORINDICATOR, 34023);      /* BP/BL image color switch */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8BKGCOLORINDICATOR, 34024);        /* BP/BL bg color switch */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8IMAGECOLORVALUE, 34025);          /* BP/BL image color value */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8BKGCOLORVALUE, 34026);            /* BP/BL bg color value */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8PIXELINTENSITYRANGE, 34027);      /* MP pixel intensity value */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8TRANSPARENCYINDICATOR, 34028);    /* HC transparency switch */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8COLORCHARACTERIZATION, 34029);    /* color character. table */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8HCUSAGE, 34030);                  /* HC usage indicator */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8TRAPINDICATOR, 34031);            /* Trapping indicator \
								 (untrapped=0, trapped=1) */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8CMYKEQUIVALENT, 34032);           /* CMYK color equivalents */
                                                                                 /* tags 34232-34236 are private tags registered to Texas Instruments */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_FRAMECOUNT, 34232);                  /* Sequence Frame Count */
                                                                                 /* tag 34377 is private tag registered to Adobe for PhotoShop */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PHOTOSHOP, 34377);
    /* tags 34665, 34853 and 40965 are documented in EXIF specification */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_EXIFIFD, 34665);                 /* Pointer to EXIF private directory */
                                                                             /* tag 34750 is a private tag registered to Adobe? */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ICCPROFILE, 34675);              /* ICC profile data */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_IMAGELAYER, 34732);              /* !TIFF/FX image layer information */
                                                                             /* tag 34750 is a private tag registered to Pixel Magic */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JBIGOPTIONS, 34750);             /* JBIG options */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_GPSIFD, 34853);                  /* Pointer to GPS private directory */
                                                                             /* tags 34908-34914 are private tags registered to SGI */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXRECVPARAMS, 34908);           /* encoded Class 2 ses. parms */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXSUBADDRESS, 34909);           /* received SubAddr string */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXRECVTIME, 34910);             /* receive time (secs) */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXDCS, 34911);                  /* encoded fax ses. params, Table 2/T.30 */
                                                                             /* tags 37439-37443 are registered to SGI <gregl@sgi.com> */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_STONITS, 37439);                 /* Sample value to Nits */
                                                                             /* tag 34929 is a private tag registered to FedEx */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_FEDEX_EDR, 34929);               /* unknown use */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_INTEROPERABILITYIFD, 40965);     /* Pointer to Interoperability private directory */
                                                                             /* Adobe Digital Negative (DNG) format tags */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DNGVERSION, 50706);              /* &DNG version number */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DNGBACKWARDVERSION, 50707);      /* &DNG compatibility version */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_UNIQUECAMERAMODEL, 50708);       /* &name for the camera model */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_LOCALIZEDCAMERAMODEL, 50709);    /* &localized camera model \
						 name */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CFAPLANECOLOR, 50710);           /* &CFAPattern->LinearRaw space \
							 mapping */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CFALAYOUT, 50711);               /* &spatial layout of the CFA */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_LINEARIZATIONTABLE, 50712);      /* &lookup table description */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_BLACKLEVELREPEATDIM, 50713);     /* &repeat pattern size for \
							 the BlackLevel tag */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_BLACKLEVEL, 50714);              /* &zero light encoding level */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_BLACKLEVELDELTAH, 50715);        /* &zero light encoding level \
							 differences (columns) */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_BLACKLEVELDELTAV, 50716);        /* &zero light encoding level \
							 differences (rows) */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_WHITELEVEL, 50717);              /* &fully saturated encoding \
								 level */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DEFAULTSCALE, 50718);            /* &default scale factors */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DEFAULTCROPORIGIN, 50719);       /* &origin of the final image \
							 area */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DEFAULTCROPSIZE, 50720);         /* &size of the final image \
							 area */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_COLORMATRIX1, 50721);            /* &XYZ->reference color space \
							 transformation matrix 1 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_COLORMATRIX2, 50722);            /* &XYZ->reference color space \
							 transformation matrix 2 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CAMERACALIBRATION1, 50723);      /* &calibration matrix 1 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CAMERACALIBRATION2, 50724);      /* &calibration matrix 2 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_REDUCTIONMATRIX1, 50725);        /* &dimensionality reduction \
							 matrix 1 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_REDUCTIONMATRIX2, 50726);        /* &dimensionality reduction \
							 matrix 2 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ANALOGBALANCE, 50727);           /* &gain applied the stored raw \
							 values*/
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ASSHOTNEUTRAL, 50728);           /* &selected white balance in \
							 linear reference space */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ASSHOTWHITEXY, 50729);           /* &selected white balance in \
							 x-y chromaticity                               \
							 coordinates */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_BASELINEEXPOSURE, 50730);        /* &how much to move the zero \
							 point */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_BASELINENOISE, 50731);           /* &relative noise level */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_BASELINESHARPNESS, 50732);       /* &relative amount of \
							 sharpening */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_BAYERGREENSPLIT, 50733);         /* &how closely the values of \
							 the green pixels in the                        \
							 blue/green rows track the                      \
							 values of the green pixels                     \
							 in the red/green rows */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_LINEARRESPONSELIMIT, 50734);     /* &non-linear encoding range */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CAMERASERIALNUMBER, 50735);      /* &camera's serial number */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_LENSINFO, 50736);                /* info about the lens */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CHROMABLURRADIUS, 50737);        /* &chroma blur radius */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ANTIALIASSTRENGTH, 50738);       /* &relative strength of the \
							 camera's anti-alias filter */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_SHADOWSCALE, 50739);             /* &used by Adobe Camera Raw */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DNGPRIVATEDATA, 50740);          /* &manufacturer's private data */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_MAKERNOTESAFETY, 50741);         /* &whether the EXIF MakerNote \
							 tag is safe to preserve                         \
							 along with the rest of the                      \
							 EXIF data */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CALIBRATIONILLUMINANT1, 50778);  /* &illuminant 1 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CALIBRATIONILLUMINANT2, 50779);  /* &illuminant 2 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_BESTQUALITYSCALE, 50780);        /* &best quality multiplier */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_RAWDATAUNIQUEID, 50781);         /* &unique identifier for \
							 the raw image data */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ORIGINALRAWFILENAME, 50827);     /* &file name of the original \
							 raw file */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ORIGINALRAWFILEDATA, 50828);     /* &contents of the original \
							 raw file */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ACTIVEAREA, 50829);              /* &active (non-masked) pixels \
								 of the sensor */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_MASKEDAREAS, 50830);             /* &list of coordinates \
								 of fully masked pixels */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ASSHOTICCPROFILE, 50831);        /* &these two tags used to */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ASSHOTPREPROFILEMATRIX, 50832);  /* map cameras's color space \
						 into ICC profile space */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CURRENTICCPROFILE, 50833);       /* & */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_CURRENTPREPROFILEMATRIX, 50834); /* & */
                                                                             /* tag 65535 is an undefined tag used by Eastman Kodak */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSHUESHIFTVALUES, 65535);       /* hue shift correction data */

    /*
 * The following are ``pseudo tags'' that can be used to control
 * codec-specific functionality.  These tags are not written to file.
 * Note that these values start at 0xffff+1 so that they'll never
 * collide with Aldus-assigned tags.
 *
 * If you want your private pseudo tags ``registered'' (i.e. added to
 * this file), please post a bug report via the tracking system at
 * http://www.remotesensing.org/libtiff/bugs.html with the appropriate
 * C definitions to add.
 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXMODE, 65536);           /* Group 3/4 format control */
    NODE_DEFINE_CONSTANT(constants, FAXMODE_CLASSIC, 0x0000);          /* default, include RTC */
    NODE_DEFINE_CONSTANT(constants, FAXMODE_NORTC, 0x0001);            /* no RTC at end of data */
    NODE_DEFINE_CONSTANT(constants, FAXMODE_NOEOL, 0x0002);            /* no EOL code at end of row */
    NODE_DEFINE_CONSTANT(constants, FAXMODE_BYTEALIGN, 0x0004);        /* byte align row */
    NODE_DEFINE_CONSTANT(constants, FAXMODE_WORDALIGN, 0x0008);        /* word align row */
    NODE_DEFINE_CONSTANT(constants, FAXMODE_CLASSF, FAXMODE_NORTC);    /* TIFF Class F */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGQUALITY, 65537);       /* Compression quality level */
                                                                       /* Note: quality level is on the IJG 0-100 scale.  Default value is 75 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGCOLORMODE, 65538);     /* Auto RGB<=>YCbCr convert? */
    NODE_DEFINE_CONSTANT(constants, JPEGCOLORMODE_RAW, 0x0000);        /* no conversion (default) */
    NODE_DEFINE_CONSTANT(constants, JPEGCOLORMODE_RGB, 0x0001);        /* do auto conversion */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGTABLESMODE, 65539);    /* What to put in JPEGTables */
    NODE_DEFINE_CONSTANT(constants, JPEGTABLESMODE_QUANT, 0x0001);     /* include quantization tbls */
    NODE_DEFINE_CONSTANT(constants, JPEGTABLESMODE_HUFF, 0x0002);      /* include Huffman tbls */
                                                                       /* Note: default is JPEGTABLESMODE_QUANT | JPEGTABLESMODE_HUFF */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXFILLFUNC, 65540);       /* G3/G4 fill function */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXARLOGDATAFMT, 65549);   /* PixarLogCodec I/O data sz */
    NODE_DEFINE_CONSTANT(constants, PIXARLOGDATAFMT_8BIT, 0);          /* regular u_char samples */
    NODE_DEFINE_CONSTANT(constants, PIXARLOGDATAFMT_8BITABGR, 1);      /* ABGR-order u_chars */
    NODE_DEFINE_CONSTANT(constants, PIXARLOGDATAFMT_11BITLOG, 2);      /* 11-bit log-encoded (raw) */
    NODE_DEFINE_CONSTANT(constants, PIXARLOGDATAFMT_12BITPICIO, 3);    /* as per PICIO (1.0==2048) */
    NODE_DEFINE_CONSTANT(constants, PIXARLOGDATAFMT_16BIT, 4);         /* signed short samples */
    NODE_DEFINE_CONSTANT(constants, PIXARLOGDATAFMT_FLOAT, 5);         /* IEEE float samples */
                                                                       /* 65550-65556 are allocated to Oceana Matrix <dev@oceana.com> */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSIMAGERTYPE, 65550);     /* imager model & filter */
    NODE_DEFINE_CONSTANT(constants, DCSIMAGERMODEL_M3, 0);             /* M3 chip (1280 x 1024) */
    NODE_DEFINE_CONSTANT(constants, DCSIMAGERMODEL_M5, 1);             /* M5 chip (1536 x 1024) */
    NODE_DEFINE_CONSTANT(constants, DCSIMAGERMODEL_M6, 2);             /* M6 chip (3072 x 2048) */
    NODE_DEFINE_CONSTANT(constants, DCSIMAGERFILTER_IR, 0);            /* infrared filter */
    NODE_DEFINE_CONSTANT(constants, DCSIMAGERFILTER_MONO, 1);          /* monochrome filter */
    NODE_DEFINE_CONSTANT(constants, DCSIMAGERFILTER_CFA, 2);           /* color filter array */
    NODE_DEFINE_CONSTANT(constants, DCSIMAGERFILTER_OTHER, 3);         /* other filter */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSINTERPMODE, 65551);     /* interpolation mode */
    NODE_DEFINE_CONSTANT(constants, DCSINTERPMODE_NORMAL, 0x0);        /* whole image, default */
    NODE_DEFINE_CONSTANT(constants, DCSINTERPMODE_PREVIEW, 0x1);       /* preview of image (384x256) */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSBALANCEARRAY, 65552);   /* color balance values */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSCORRECTMATRIX, 65553);  /* color correction values */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSGAMMA, 65554);          /* gamma value */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSTOESHOULDERPTS, 65555); /* toe & shoulder points */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSCALIBRATIONFD, 65556);  /* calibration file desc */
                                                                       /* Note: quality level is on the ZLIB 1-9 scale. Default value is -1 */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_ZIPQUALITY, 65557);        /* compression quality level */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXARLOGQUALITY, 65558);   /* PixarLog uses same scale */
                                                                       /* 65559 is allocated to Oceana Matrix <dev@oceana.com> */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSCLIPRECTANGLE, 65559);  /* area of image to acquire */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_SGILOGDATAFMT, 65560);     /* SGILog user data format */
    NODE_DEFINE_CONSTANT(constants, SGILOGDATAFMT_FLOAT, 0);           /* IEEE float samples */
    NODE_DEFINE_CONSTANT(constants, SGILOGDATAFMT_16BIT, 1);           /* 16-bit samples */
    NODE_DEFINE_CONSTANT(constants, SGILOGDATAFMT_RAW, 2);             /* uninterpreted data */
    NODE_DEFINE_CONSTANT(constants, SGILOGDATAFMT_8BIT, 3);            /* 8-bit RGB monitor values */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_SGILOGENCODE, 65561);      /* SGILog data encoding control*/
    NODE_DEFINE_CONSTANT(constants, SGILOGENCODE_NODITHER, 0);         /* do not dither encoded values*/
    NODE_DEFINE_CONSTANT(constants, SGILOGENCODE_RANDITHER, 1);        /* randomly dither encd values */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_LZMAPRESET, 65562);        /* LZMA2 preset (compression level) */
    NODE_DEFINE_CONSTANT(constants, TIFFTAG_PERSAMPLE, 65563);         /* interface for per sample tags */
    NODE_DEFINE_CONSTANT(constants, PERSAMPLE_MERGED, 0);              /* present as a single value */
    NODE_DEFINE_CONSTANT(constants, PERSAMPLE_MULTI, 1);               /* present as multiple values */

    /*
 * EXIF tags
 */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_EXPOSURETIME, 33434);             /* Exposure time */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_FNUMBER, 33437);                  /* F number */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_EXPOSUREPROGRAM, 34850);          /* Exposure program */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SPECTRALSENSITIVITY, 34852);      /* Spectral sensitivity */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_ISOSPEEDRATINGS, 34855);          /* ISO speed rating */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_OECF, 34856);                     /* Optoelectric conversion \
								  factor */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_EXIFVERSION, 36864);              /* Exif version */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_DATETIMEORIGINAL, 36867);         /* Date and time of original \
							  data generation */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_DATETIMEDIGITIZED, 36868);        /* Date and time of digital \
							  data generation */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_COMPONENTSCONFIGURATION, 37121);  /* Meaning of each component */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_COMPRESSEDBITSPERPIXEL, 37122);   /* Image compression mode */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SHUTTERSPEEDVALUE, 37377);        /* Shutter speed */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_APERTUREVALUE, 37378);            /* Aperture */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_BRIGHTNESSVALUE, 37379);          /* Brightness */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_EXPOSUREBIASVALUE, 37380);        /* Exposure bias */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_MAXAPERTUREVALUE, 37381);         /* Maximum lens aperture */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBJECTDISTANCE, 37382);          /* Subject distance */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_METERINGMODE, 37383);             /* Metering mode */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_LIGHTSOURCE, 37384);              /* Light source */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_FLASH, 37385);                    /* Flash */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_FOCALLENGTH, 37386);              /* Lens focal length */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBJECTAREA, 37396);              /* Subject area */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_MAKERNOTE, 37500);                /* Manufacturer notes */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_USERCOMMENT, 37510);              /* User comments */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBSECTIME, 37520);               /* DateTime subseconds */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBSECTIMEORIGINAL, 37521);       /* DateTimeOriginal subseconds */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBSECTIMEDIGITIZED, 37522);      /* DateTimeDigitized subseconds */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_FLASHPIXVERSION, 40960);          /* Supported Flashpix version */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_COLORSPACE, 40961);               /* Color space information */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_PIXELXDIMENSION, 40962);          /* Valid image width */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_PIXELYDIMENSION, 40963);          /* Valid image height */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_RELATEDSOUNDFILE, 40964);         /* Related audio file */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_FLASHENERGY, 41483);              /* Flash energy */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SPATIALFREQUENCYRESPONSE, 41484); /* Spatial frequency response */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_FOCALPLANEXRESOLUTION, 41486);    /* Focal plane X resolution */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_FOCALPLANEYRESOLUTION, 41487);    /* Focal plane Y resolution */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_FOCALPLANERESOLUTIONUNIT, 41488); /* Focal plane resolution unit */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBJECTLOCATION, 41492);          /* Subject location */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_EXPOSUREINDEX, 41493);            /* Exposure index */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SENSINGMETHOD, 41495);            /* Sensing method */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_FILESOURCE, 41728);               /* File source */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SCENETYPE, 41729);                /* Scene type */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_CFAPATTERN, 41730);               /* CFA pattern */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_CUSTOMRENDERED, 41985);           /* Custom image processing */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_EXPOSUREMODE, 41986);             /* Exposure mode */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_WHITEBALANCE, 41987);             /* White balance */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_DIGITALZOOMRATIO, 41988);         /* Digital zoom ratio */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_FOCALLENGTHIN35MMFILM, 41989);    /* Focal length in 35 mm film */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SCENECAPTURETYPE, 41990);         /* Scene capture type */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_GAINCONTROL, 41991);              /* Gain control */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_CONTRAST, 41992);                 /* Contrast */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SATURATION, 41993);               /* Saturation */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SHARPNESS, 41994);                /* Sharpness */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_DEVICESETTINGDESCRIPTION, 41995); /* Device settings description */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBJECTDISTANCERANGE, 41996);     /* Subject distance range */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_GAINCONTROL, 41991);              /* Gain control */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_GAINCONTROL, 41991);              /* Gain control */
    NODE_DEFINE_CONSTANT(constants, EXIFTAG_IMAGEUNIQUEID, 42016);            /* Unique image ID */

    exports->Set(Nan::New("constants").ToLocalChecked(), constants);
}

NAN_MODULE_INIT(Init)
{
    InitConstants(target);
}

NODE_MODULE(tiffh, Init);