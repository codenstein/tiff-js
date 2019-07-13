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
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_SUBFILETYPE);             /* subfile data descriptor */
  NODE_DEFINE_CONSTANT(constants, FILETYPE_REDUCEDIMAGE);           /* reduced resolution version */
  NODE_DEFINE_CONSTANT(constants, FILETYPE_PAGE);                   /* one page of many */
  NODE_DEFINE_CONSTANT(constants, FILETYPE_MASK);                   /* transparency mask */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_OSUBFILETYPE);            /* +kind of data in subfile */
  NODE_DEFINE_CONSTANT(constants, OFILETYPE_IMAGE);                   /* full resolution image data */
  NODE_DEFINE_CONSTANT(constants, OFILETYPE_REDUCEDIMAGE);            /* reduced size image data */
  NODE_DEFINE_CONSTANT(constants, OFILETYPE_PAGE);                    /* one page of many */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IMAGEWIDTH);              /* image width in pixels */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IMAGELENGTH);             /* image height in pixels */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_BITSPERSAMPLE);           /* bits per channel (sample) */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_COMPRESSION);             /* data compression technique */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_NONE);                  /* dump mode */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_CCITTRLE);              /* CCITT modified Huffman RLE */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_CCITTFAX3);             /* CCITT Group 3 fax encoding */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_CCITT_T4);              /* CCITT T.4 (TIFF 6 name) */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_CCITTFAX4);             /* CCITT Group 4 fax encoding */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_CCITT_T6);              /* CCITT T.6 (TIFF 6 name) */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_LZW);                   /* Lempel-Ziv  & Welch */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_OJPEG);                 /* !6.0 JPEG */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_JPEG);                  /* %JPEG DCT compression */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_T85);                   /* !TIFF/FX T.85 JBIG compression */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_T43);                  /* !TIFF/FX T.43 colour by layered JBIG compression */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_NEXT);              /* NeXT 2-bit RLE */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_CCITTRLEW);         /* #1 w/ word alignment */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_PACKBITS);          /* Macintosh RLE */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_THUNDERSCAN);       /* ThunderScan RLE */
                                                                         /* codes 32895-32898 are reserved for ANSI IT8 TIFF/IT <dkelly@apago.com) */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_IT8CTPAD);          /* IT8 CT w/padding */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_IT8LW);             /* IT8 Linework RLE */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_IT8MP);             /* IT8 Monochrome picture */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_IT8BL);             /* IT8 Binary line art */
                                                                         /* compression codes 32908-32911 are reserved for Pixar */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_PIXARFILM);         /* Pixar companded 10bit LZW */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_PIXARLOG);          /* Pixar companded 11bit ZIP */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_DEFLATE);           /* Deflate compression */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_ADOBE_DEFLATE);         /* Deflate compression, \
			   as recognized by Adobe */
                                                                         /* compression code 32947 is reserved for Oceana Matrix <dev@oceana.com> */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_DCS);               /* Kodak DCS encoding */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_JBIG);              /* ISO JBIG */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_SGILOG);            /* SGI Log Luminance RLE */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_SGILOG24);          /* SGI Log 24-bit packed */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_JP2000);            /* Leadtools JPEG2000 */
  NODE_DEFINE_CONSTANT(constants, COMPRESSION_LZMA);              /* LZMA2 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PHOTOMETRIC);             /* photometric interpretation */
  NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_MINISWHITE);            /* min value is white */
  NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_MINISBLACK);            /* min value is black */
  NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_RGB);                   /* RGB color model */
  NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_PALETTE);               /* color map indexed */
  NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_MASK);                  /* $holdout mask */
  NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_SEPARATED);             /* !color separations */
  NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_YCBCR);                 /* !CCIR 601 */
  NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_CIELAB);                /* !1976 CIE L*a*b* */
  NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_ICCLAB);                /* ICC L*a*b* [Adobe TIFF Technote 4] */
  NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_ITULAB);               /* ITU L*a*b* */
  NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_CFA);               /* color filter array */
  NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_LOGL);              /* CIE Log2(L) */
  NODE_DEFINE_CONSTANT(constants, PHOTOMETRIC_LOGLUV);            /* CIE Log2(L) (u',v') */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_THRESHHOLDING);           /* +thresholding used on data */
  NODE_DEFINE_CONSTANT(constants, THRESHHOLD_BILEVEL);                /* b&w art scan */
  NODE_DEFINE_CONSTANT(constants, THRESHHOLD_HALFTONE);               /* or dithered scan */
  NODE_DEFINE_CONSTANT(constants, THRESHHOLD_ERRORDIFFUSE);           /* usually floyd-steinberg */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CELLWIDTH);               /* +dithering matrix width */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CELLLENGTH);              /* +dithering matrix height */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_FILLORDER);               /* data order within a byte */
  NODE_DEFINE_CONSTANT(constants, FILLORDER_MSB2LSB);                 /* most significant -> least */
  NODE_DEFINE_CONSTANT(constants, FILLORDER_LSB2MSB);                 /* least significant -> most */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DOCUMENTNAME);            /* name of doc. image is from */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IMAGEDESCRIPTION);        /* info about image */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_MAKE);                    /* scanner manufacturer name */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_MODEL);                   /* scanner model name/number */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_STRIPOFFSETS);            /* offsets to data strips */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ORIENTATION);             /* +image orientation */
  NODE_DEFINE_CONSTANT(constants, ORIENTATION_TOPLEFT);               /* row 0 top, col 0 lhs */
  NODE_DEFINE_CONSTANT(constants, ORIENTATION_TOPRIGHT);              /* row 0 top, col 0 rhs */
  NODE_DEFINE_CONSTANT(constants, ORIENTATION_BOTRIGHT);              /* row 0 bottom, col 0 rhs */
  NODE_DEFINE_CONSTANT(constants, ORIENTATION_BOTLEFT);               /* row 0 bottom, col 0 lhs */
  NODE_DEFINE_CONSTANT(constants, ORIENTATION_LEFTTOP);               /* row 0 lhs, col 0 top */
  NODE_DEFINE_CONSTANT(constants, ORIENTATION_RIGHTTOP);              /* row 0 rhs, col 0 top */
  NODE_DEFINE_CONSTANT(constants, ORIENTATION_RIGHTBOT);              /* row 0 rhs, col 0 bottom */
  NODE_DEFINE_CONSTANT(constants, ORIENTATION_LEFTBOT);               /* row 0 lhs, col 0 bottom */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_SAMPLESPERPIXEL);         /* samples per pixel */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ROWSPERSTRIP);            /* rows per strip of data */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_STRIPBYTECOUNTS);         /* bytes counts for strips */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_MINSAMPLEVALUE);          /* +minimum sample value */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_MAXSAMPLEVALUE);          /* +maximum sample value */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_XRESOLUTION);             /* pixels/resolution in x */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_YRESOLUTION);             /* pixels/resolution in y */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PLANARCONFIG);            /* storage organization */
  NODE_DEFINE_CONSTANT(constants, PLANARCONFIG_CONTIG);               /* single image plane */
  NODE_DEFINE_CONSTANT(constants, PLANARCONFIG_SEPARATE);             /* separate planes of data */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PAGENAME);                /* page name image is from */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_XPOSITION);               /* x page offset of image lhs */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_YPOSITION);               /* y page offset of image lhs */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_FREEOFFSETS);             /* +byte offset to free block */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_FREEBYTECOUNTS);          /* +sizes of free blocks */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_GRAYRESPONSEUNIT);        /* $gray scale curve accuracy */
  NODE_DEFINE_CONSTANT(constants, GRAYRESPONSEUNIT_10S);              /* tenths of a unit */
  NODE_DEFINE_CONSTANT(constants, GRAYRESPONSEUNIT_100S);             /* hundredths of a unit */
  NODE_DEFINE_CONSTANT(constants, GRAYRESPONSEUNIT_1000S);            /* thousandths of a unit */
  NODE_DEFINE_CONSTANT(constants, GRAYRESPONSEUNIT_10000S);           /* ten-thousandths of a unit */
  NODE_DEFINE_CONSTANT(constants, GRAYRESPONSEUNIT_100000S);          /* hundred-thousandths */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_GRAYRESPONSECURVE);       /* $gray scale response curve */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_GROUP3OPTIONS);           /* 32 flag bits */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_T4OPTIONS);               /* TIFF 6.0 proper name alias */
  NODE_DEFINE_CONSTANT(constants, GROUP3OPT_2DENCODING);            /* 2-dimensional coding */
  NODE_DEFINE_CONSTANT(constants, GROUP3OPT_UNCOMPRESSED);          /* data not compressed */
  NODE_DEFINE_CONSTANT(constants, GROUP3OPT_FILLBITS);              /* fill to byte boundary */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_GROUP4OPTIONS);           /* 32 flag bits */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_T6OPTIONS);               /* TIFF 6.0 proper name */
  NODE_DEFINE_CONSTANT(constants, GROUP4OPT_UNCOMPRESSED);          /* data not compressed */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_RESOLUTIONUNIT);          /* units of resolutions */
  NODE_DEFINE_CONSTANT(constants, RESUNIT_NONE);                      /* no meaningful units */
  NODE_DEFINE_CONSTANT(constants, RESUNIT_INCH);                      /* english */
  NODE_DEFINE_CONSTANT(constants, RESUNIT_CENTIMETER);                /* metric */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PAGENUMBER);              /* page numbers of multi-page */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_COLORRESPONSEUNIT);       /* $color curve accuracy */
  NODE_DEFINE_CONSTANT(constants, COLORRESPONSEUNIT_10S);             /* tenths of a unit */
  NODE_DEFINE_CONSTANT(constants, COLORRESPONSEUNIT_100S);            /* hundredths of a unit */
  NODE_DEFINE_CONSTANT(constants, COLORRESPONSEUNIT_1000S);           /* thousandths of a unit */
  NODE_DEFINE_CONSTANT(constants, COLORRESPONSEUNIT_10000S);          /* ten-thousandths of a unit */
  NODE_DEFINE_CONSTANT(constants, COLORRESPONSEUNIT_100000S);         /* hundred-thousandths */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_TRANSFERFUNCTION);        /* !colorimetry info */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_SOFTWARE);                /* name & release */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DATETIME);                /* creation date and time */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ARTIST);                  /* creator of image */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_HOSTCOMPUTER);            /* machine where created */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PREDICTOR);               /* prediction scheme w/ LZW */
  NODE_DEFINE_CONSTANT(constants, PREDICTOR_NONE);                    /* no prediction scheme used */
  NODE_DEFINE_CONSTANT(constants, PREDICTOR_HORIZONTAL);              /* horizontal differencing */
  NODE_DEFINE_CONSTANT(constants, PREDICTOR_FLOATINGPOINT);           /* floating point predictor */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_WHITEPOINT);              /* image white point */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PRIMARYCHROMATICITIES);   /* !primary chromaticities */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_COLORMAP);                /* RGB map for palette image */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_HALFTONEHINTS);           /* !highlight+shadow info */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_TILEWIDTH);               /* !tile width in pixels */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_TILELENGTH);              /* !tile height in pixels */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_TILEOFFSETS);             /* !offsets to data tiles */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_TILEBYTECOUNTS);          /* !byte counts for tiles */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_BADFAXLINES);             /* lines w/ wrong pixel count */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CLEANFAXDATA);            /* regenerated line info */
  NODE_DEFINE_CONSTANT(constants, CLEANFAXDATA_CLEAN);                /* no errors detected */
  NODE_DEFINE_CONSTANT(constants, CLEANFAXDATA_REGENERATED);          /* receiver regenerated lines */
  NODE_DEFINE_CONSTANT(constants, CLEANFAXDATA_UNCLEAN);              /* uncorrected errors exist */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CONSECUTIVEBADFAXLINES);  /* max consecutive bad lines */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_SUBIFD);                  /* subimage descriptors */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_INKSET);                  /* !inks in separated image */
  NODE_DEFINE_CONSTANT(constants, INKSET_CMYK);                       /* !cyan-magenta-yellow-black color */
  NODE_DEFINE_CONSTANT(constants, INKSET_MULTIINK);                   /* !multi-ink or hi-fi color */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_INKNAMES);                /* !ascii names of inks */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_NUMBEROFINKS);            /* !number of inks */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DOTRANGE);                /* !0% and 100% dot codes */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_TARGETPRINTER);           /* !separation target */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_EXTRASAMPLES);            /* !info about extra samples */
  NODE_DEFINE_CONSTANT(constants, EXTRASAMPLE_UNSPECIFIED);           /* !unspecified data */
  NODE_DEFINE_CONSTANT(constants, EXTRASAMPLE_ASSOCALPHA);            /* !associated alpha data */
  NODE_DEFINE_CONSTANT(constants, EXTRASAMPLE_UNASSALPHA);            /* !unassociated alpha data */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_SAMPLEFORMAT);            /* !data sample format */
  NODE_DEFINE_CONSTANT(constants, SAMPLEFORMAT_UINT);                 /* !unsigned integer data */
  NODE_DEFINE_CONSTANT(constants, SAMPLEFORMAT_INT);                  /* !signed integer data */
  NODE_DEFINE_CONSTANT(constants, SAMPLEFORMAT_IEEEFP);               /* !IEEE floating point data */
  NODE_DEFINE_CONSTANT(constants, SAMPLEFORMAT_VOID);                 /* !untyped data */
  NODE_DEFINE_CONSTANT(constants, SAMPLEFORMAT_COMPLEXINT);           /* !complex signed int */
  NODE_DEFINE_CONSTANT(constants, SAMPLEFORMAT_COMPLEXIEEEFP);        /* !complex ieee floating */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_SMINSAMPLEVALUE);         /* !variable MinSampleValue */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_SMAXSAMPLEVALUE);         /* !variable MaxSampleValue */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CLIPPATH);                /* %ClipPath \
								  [Adobe TIFF technote 2] */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_XCLIPPATHUNITS);          /* %XClipPathUnits \
							  [Adobe TIFF technote 2] */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_YCLIPPATHUNITS);          /* %YClipPathUnits \
							  [Adobe TIFF technote 2] */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_INDEXED);                 /* %Indexed \
								  [Adobe TIFF Technote 3] */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGTABLES);              /* %JPEG table stream */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_OPIPROXY);                /* %OPI Proxy [Adobe TIFF technote] */
                                                                         /* Tags 400-435 are from the TIFF/FX spec */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_GLOBALPARAMETERSIFD);     /* ! */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PROFILETYPE);             /* ! */
  NODE_DEFINE_CONSTANT(constants, PROFILETYPE_UNSPECIFIED);           /* ! */
  NODE_DEFINE_CONSTANT(constants, PROFILETYPE_G3_FAX);                /* ! */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXPROFILE);              /* ! */
  NODE_DEFINE_CONSTANT(constants, FAXPROFILE_S);                      /* !TIFF/FX FAX profile S */
  NODE_DEFINE_CONSTANT(constants, FAXPROFILE_F);                      /* !TIFF/FX FAX profile F */
  NODE_DEFINE_CONSTANT(constants, FAXPROFILE_J);                      /* !TIFF/FX FAX profile J */
  NODE_DEFINE_CONSTANT(constants, FAXPROFILE_C);                      /* !TIFF/FX FAX profile C */
  NODE_DEFINE_CONSTANT(constants, FAXPROFILE_L);                      /* !TIFF/FX FAX profile L */
  NODE_DEFINE_CONSTANT(constants, FAXPROFILE_M);                      /* !TIFF/FX FAX profile LM */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CODINGMETHODS);           /* !TIFF/FX coding methods */
  NODE_DEFINE_CONSTANT(constants, CODINGMETHODS_T4_1D);        /* !T.4 1D */
  NODE_DEFINE_CONSTANT(constants, CODINGMETHODS_T4_2D);        /* !T.4 2D */
  NODE_DEFINE_CONSTANT(constants, CODINGMETHODS_T6);           /* !T.6 */
  NODE_DEFINE_CONSTANT(constants, CODINGMETHODS_T85);          /* !T.85 JBIG */
  NODE_DEFINE_CONSTANT(constants, CODINGMETHODS_T42);          /* !T.42 JPEG */
  NODE_DEFINE_CONSTANT(constants, CODINGMETHODS_T43);          /* !T.43 colour by layered JBIG */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_VERSIONYEAR);             /* !TIFF/FX version year */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_MODENUMBER);              /* !TIFF/FX mode number */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DECODE);                  /* !TIFF/FX decode */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IMAGEBASECOLOR);          /* !TIFF/FX image base colour */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_T82OPTIONS);              /* !TIFF/FX T.82 options */
                                                                         /*
 * Tags 512-521 are obsoleted by Technical Note #2 which specifies a
 * revised JPEG-in-TIFF scheme.
 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGPROC);                /* !JPEG processing algorithm */
  NODE_DEFINE_CONSTANT(constants, JPEGPROC_BASELINE);                 /* !baseline sequential */
  NODE_DEFINE_CONSTANT(constants, JPEGPROC_LOSSLESS);                /* !Huffman coded lossless */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGIFOFFSET);            /* !pointer to SOI marker */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGIFBYTECOUNT);         /* !JFIF stream length */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGRESTARTINTERVAL);     /* !restart interval length */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGLOSSLESSPREDICTORS);  /* !lossless proc predictor */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGPOINTTRANSFORM);      /* !lossless point transform */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGQTABLES);             /* !Q matrix offsets */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGDCTABLES);            /* !DCT table offsets */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGACTABLES);            /* !AC coefficient offsets */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_YCBCRCOEFFICIENTS);       /* !RGB -> YCbCr transform */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_YCBCRSUBSAMPLING);        /* !YCbCr subsampling factors */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_YCBCRPOSITIONING);        /* !subsample positioning */
  NODE_DEFINE_CONSTANT(constants, YCBCRPOSITION_CENTERED);            /* !as in PostScript Level 2 */
  NODE_DEFINE_CONSTANT(constants, YCBCRPOSITION_COSITED);             /* !as in CCIR 601-1 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_REFERENCEBLACKWHITE);     /* !colorimetry info */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_STRIPROWCOUNTS);          /* !TIFF/FX strip row counts */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_XMLPACKET);               /* %XML packet   \
								  [Adobe XMP Specification, \
								  January 2004 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_OPIIMAGEID);            /* %OPI ImageID \
							  [Adobe TIFF technote] */
                                                                         /* tags 32952-32956 are private tags registered to Island Graphics */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_REFPTS);                /* image reference points */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_REGIONTACKPOINT);       /* region-xform tack point */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_REGIONWARPCORNERS);     /* warp quadrilateral */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_REGIONAFFINE);          /* affine transformation mat */
                                                                         /* tags 32995-32999 are private tags registered to SGI */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_MATTEING);              /* $use ExtraSamples */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DATATYPE);              /* $use SampleFormat */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IMAGEDEPTH);            /* z depth of image */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_TILEDEPTH);             /* z depth/data tile */
                                                                         /* tags 33300-33309 are private tags registered to Pixar */
                                                                         /*
 * TIFFTAG_PIXAR_IMAGEFULLWIDTH and TIFFTAG_PIXAR_IMAGEFULLLENGTH
 * are set when an image has been cropped out of a larger image.  
 * They reflect the size of the original uncropped image.
 * The TIFFTAG_XPOSITION and TIFFTAG_YPOSITION can be used
 * to determine the position of the smaller image in the larger one.
 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_IMAGEFULLWIDTH);  /* full image size in x */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_IMAGEFULLLENGTH); /* full image size in y */
                                                                         /* Tags 33302-33306 are used to identify special image modes and data
  * used by Pixar's texture formats.
  */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_TEXTUREFORMAT);   /* texture map format */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_WRAPMODES);       /* s & t wrap modes */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_FOVCOT);          /* cotan(fov) for env. maps */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_MATRIX_WORLDTOSCREEN);
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXAR_MATRIX_WORLDTOCAMERA);
  /* tag 33405 is a private tag registered to Eastman Kodak */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_WRITERSERIALNUMBER);  /* device serial number */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CFAREPEATPATTERNDIM); /* dimensions of CFA pattern */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CFAPATTERN);          /* color filter array pattern */
                                                                       /* tag 33432 is listed in the 6.0 spec w/ unknown ownership */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_COPYRIGHT);           /* copyright string */
                                                                       /* IPTC TAG from RichTIFF specifications */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_RICHTIFFIPTC);
  /* 34016-34029 are reserved for ANSI IT8 TIFF/IT <dkelly@apago.com) */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8SITE);                     /* site name */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8COLORSEQUENCE);            /* color seq. [RGB,CMYK,etc] */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8HEADER);                   /* DDES Header */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8RASTERPADDING);            /* raster scanline padding */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8BITSPERRUNLENGTH);         /* # of bits in short run */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8BITSPEREXTENDEDRUNLENGTH); /* # of bits in long run */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8COLORTABLE);               /* LW colortable */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8IMAGECOLORINDICATOR);      /* BP/BL image color switch */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8BKGCOLORINDICATOR);        /* BP/BL bg color switch */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8IMAGECOLORVALUE);          /* BP/BL image color value */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8BKGCOLORVALUE);            /* BP/BL bg color value */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8PIXELINTENSITYRANGE);      /* MP pixel intensity value */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8TRANSPARENCYINDICATOR);    /* HC transparency switch */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8COLORCHARACTERIZATION);    /* color character. table */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8HCUSAGE);                  /* HC usage indicator */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8TRAPINDICATOR);            /* Trapping indicator \
								 (untrapped=0, trapped=1) */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IT8CMYKEQUIVALENT);           /* CMYK color equivalents */
                                                                               /* tags 34232-34236 are private tags registered to Texas Instruments */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_FRAMECOUNT);                  /* Sequence Frame Count */
                                                                               /* tag 34377 is private tag registered to Adobe for PhotoShop */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PHOTOSHOP);
  /* tags 34665, 34853 and 40965 are documented in EXIF specification */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_EXIFIFD);                 /* Pointer to EXIF private directory */
                                                                           /* tag 34750 is a private tag registered to Adobe? */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ICCPROFILE);              /* ICC profile data */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_IMAGELAYER);              /* !TIFF/FX image layer information */
                                                                           /* tag 34750 is a private tag registered to Pixel Magic */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JBIGOPTIONS);             /* JBIG options */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_GPSIFD);                  /* Pointer to GPS private directory */
                                                                           /* tags 34908-34914 are private tags registered to SGI */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXRECVPARAMS);           /* encoded Class 2 ses. parms */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXSUBADDRESS);           /* received SubAddr string */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXRECVTIME);             /* receive time (secs) */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXDCS);                  /* encoded fax ses. params, Table 2/T.30 */
                                                                           /* tags 37439-37443 are registered to SGI <gregl@sgi.com> */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_STONITS);                 /* Sample value to Nits */
                                                                           /* tag 34929 is a private tag registered to FedEx */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_FEDEX_EDR);               /* unknown use */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_INTEROPERABILITYIFD);     /* Pointer to Interoperability private directory */
                                                                           /* Adobe Digital Negative (DNG) format tags */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DNGVERSION);              /* &DNG version number */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DNGBACKWARDVERSION);      /* &DNG compatibility version */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_UNIQUECAMERAMODEL);       /* &name for the camera model */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_LOCALIZEDCAMERAMODEL);    /* &localized camera model \
						 name */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CFAPLANECOLOR);           /* &CFAPattern->LinearRaw space \
							 mapping */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CFALAYOUT);               /* &spatial layout of the CFA */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_LINEARIZATIONTABLE);      /* &lookup table description */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_BLACKLEVELREPEATDIM);     /* &repeat pattern size for \
							 the BlackLevel tag */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_BLACKLEVEL);              /* &zero light encoding level */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_BLACKLEVELDELTAH);        /* &zero light encoding level \
							 differences (columns) */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_BLACKLEVELDELTAV);        /* &zero light encoding level \
							 differences (rows) */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_WHITELEVEL);              /* &fully saturated encoding \
								 level */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DEFAULTSCALE);            /* &default scale factors */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DEFAULTCROPORIGIN);       /* &origin of the final image \
							 area */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DEFAULTCROPSIZE);         /* &size of the final image \
							 area */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_COLORMATRIX1);            /* &XYZ->reference color space \
							 transformation matrix 1 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_COLORMATRIX2);            /* &XYZ->reference color space \
							 transformation matrix 2 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CAMERACALIBRATION1);      /* &calibration matrix 1 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CAMERACALIBRATION2);      /* &calibration matrix 2 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_REDUCTIONMATRIX1);        /* &dimensionality reduction \
							 matrix 1 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_REDUCTIONMATRIX2);        /* &dimensionality reduction \
							 matrix 2 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ANALOGBALANCE);           /* &gain applied the stored raw \
							 values*/
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ASSHOTNEUTRAL);           /* &selected white balance in \
							 linear reference space */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ASSHOTWHITEXY);           /* &selected white balance in \
							 x-y chromaticity                               \
							 coordinates */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_BASELINEEXPOSURE);        /* &how much to move the zero \
							 point */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_BASELINENOISE);           /* &relative noise level */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_BASELINESHARPNESS);       /* &relative amount of \
							 sharpening */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_BAYERGREENSPLIT);         /* &how closely the values of \
							 the green pixels in the                        \
							 blue/green rows track the                      \
							 values of the green pixels                     \
							 in the red/green rows */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_LINEARRESPONSELIMIT);     /* &non-linear encoding range */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CAMERASERIALNUMBER);      /* &camera's serial number */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_LENSINFO);                /* info about the lens */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CHROMABLURRADIUS);        /* &chroma blur radius */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ANTIALIASSTRENGTH);       /* &relative strength of the \
							 camera's anti-alias filter */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_SHADOWSCALE);             /* &used by Adobe Camera Raw */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DNGPRIVATEDATA);          /* &manufacturer's private data */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_MAKERNOTESAFETY);         /* &whether the EXIF MakerNote \
							 tag is safe to preserve                         \
							 along with the rest of the                      \
							 EXIF data */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CALIBRATIONILLUMINANT1);  /* &illuminant 1 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CALIBRATIONILLUMINANT2);  /* &illuminant 2 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_BESTQUALITYSCALE);        /* &best quality multiplier */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_RAWDATAUNIQUEID);         /* &unique identifier for \
							 the raw image data */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ORIGINALRAWFILENAME);     /* &file name of the original \
							 raw file */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ORIGINALRAWFILEDATA);     /* &contents of the original \
							 raw file */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ACTIVEAREA);              /* &active (non-masked) pixels \
								 of the sensor */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_MASKEDAREAS);             /* &list of coordinates \
								 of fully masked pixels */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ASSHOTICCPROFILE);        /* &these two tags used to */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ASSHOTPREPROFILEMATRIX);  /* map cameras's color space \
						 into ICC profile space */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CURRENTICCPROFILE);       /* & */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_CURRENTPREPROFILEMATRIX); /* & */
                                                                           /* tag 65535 is an undefined tag used by Eastman Kodak */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSHUESHIFTVALUES);       /* hue shift correction data */

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
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXMODE);           /* Group 3/4 format control */
  NODE_DEFINE_CONSTANT(constants, FAXMODE_CLASSIC);          /* default, include RTC */
  NODE_DEFINE_CONSTANT(constants, FAXMODE_NORTC);            /* no RTC at end of data */
  NODE_DEFINE_CONSTANT(constants, FAXMODE_NOEOL);            /* no EOL code at end of row */
  NODE_DEFINE_CONSTANT(constants, FAXMODE_BYTEALIGN);        /* byte align row */
  NODE_DEFINE_CONSTANT(constants, FAXMODE_WORDALIGN);        /* word align row */
  NODE_DEFINE_CONSTANT(constants, FAXMODE_CLASSF);    /* TIFF Class F */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGQUALITY);       /* Compression quality level */
                                                                     /* Note: quality level is on the IJG 0-100 scale.  Default value is 75 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGCOLORMODE);     /* Auto RGB<=>YCbCr convert? */
  NODE_DEFINE_CONSTANT(constants, JPEGCOLORMODE_RAW);        /* no conversion (default) */
  NODE_DEFINE_CONSTANT(constants, JPEGCOLORMODE_RGB);        /* do auto conversion */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_JPEGTABLESMODE);    /* What to put in JPEGTables */
  NODE_DEFINE_CONSTANT(constants, JPEGTABLESMODE_QUANT);     /* include quantization tbls */
  NODE_DEFINE_CONSTANT(constants, JPEGTABLESMODE_HUFF);      /* include Huffman tbls */
                                                                     /* Note: default is JPEGTABLESMODE_QUANT | JPEGTABLESMODE_HUFF */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_FAXFILLFUNC);       /* G3/G4 fill function */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXARLOGDATAFMT);   /* PixarLogCodec I/O data sz */
  NODE_DEFINE_CONSTANT(constants, PIXARLOGDATAFMT_8BIT);          /* regular u_char samples */
  NODE_DEFINE_CONSTANT(constants, PIXARLOGDATAFMT_8BITABGR);      /* ABGR-order u_chars */
  NODE_DEFINE_CONSTANT(constants, PIXARLOGDATAFMT_11BITLOG);      /* 11-bit log-encoded (raw) */
  NODE_DEFINE_CONSTANT(constants, PIXARLOGDATAFMT_12BITPICIO);    /* as per PICIO (1.0==2048) */
  NODE_DEFINE_CONSTANT(constants, PIXARLOGDATAFMT_16BIT);         /* signed short samples */
  NODE_DEFINE_CONSTANT(constants, PIXARLOGDATAFMT_FLOAT);         /* IEEE float samples */
                                                                     /* 65550-65556 are allocated to Oceana Matrix <dev@oceana.com> */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSIMAGERTYPE);     /* imager model & filter */
  NODE_DEFINE_CONSTANT(constants, DCSIMAGERMODEL_M3);             /* M3 chip (1280 x 1024) */
  NODE_DEFINE_CONSTANT(constants, DCSIMAGERMODEL_M5);             /* M5 chip (1536 x 1024) */
  NODE_DEFINE_CONSTANT(constants, DCSIMAGERMODEL_M6);             /* M6 chip (3072 x 2048) */
  NODE_DEFINE_CONSTANT(constants, DCSIMAGERFILTER_IR);            /* infrared filter */
  NODE_DEFINE_CONSTANT(constants, DCSIMAGERFILTER_MONO);          /* monochrome filter */
  NODE_DEFINE_CONSTANT(constants, DCSIMAGERFILTER_CFA);           /* color filter array */
  NODE_DEFINE_CONSTANT(constants, DCSIMAGERFILTER_OTHER);         /* other filter */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSINTERPMODE);     /* interpolation mode */
  NODE_DEFINE_CONSTANT(constants, DCSINTERPMODE_NORMAL);        /* whole image, default */
  NODE_DEFINE_CONSTANT(constants, DCSINTERPMODE_PREVIEW);       /* preview of image (384x256) */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSBALANCEARRAY);   /* color balance values */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSCORRECTMATRIX);  /* color correction values */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSGAMMA);          /* gamma value */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSTOESHOULDERPTS); /* toe & shoulder points */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSCALIBRATIONFD);  /* calibration file desc */
                                                                     /* Note: quality level is on the ZLIB 1-9 scale. Default value is -1 */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_ZIPQUALITY);        /* compression quality level */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PIXARLOGQUALITY);   /* PixarLog uses same scale */
                                                                     /* 65559 is allocated to Oceana Matrix <dev@oceana.com> */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_DCSCLIPRECTANGLE);  /* area of image to acquire */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_SGILOGDATAFMT);     /* SGILog user data format */
  NODE_DEFINE_CONSTANT(constants, SGILOGDATAFMT_FLOAT);           /* IEEE float samples */
  NODE_DEFINE_CONSTANT(constants, SGILOGDATAFMT_16BIT);           /* 16-bit samples */
  NODE_DEFINE_CONSTANT(constants, SGILOGDATAFMT_RAW);             /* uninterpreted data */
  NODE_DEFINE_CONSTANT(constants, SGILOGDATAFMT_8BIT);            /* 8-bit RGB monitor values */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_SGILOGENCODE);      /* SGILog data encoding control*/
  NODE_DEFINE_CONSTANT(constants, SGILOGENCODE_NODITHER);         /* do not dither encoded values*/
  NODE_DEFINE_CONSTANT(constants, SGILOGENCODE_RANDITHER);        /* randomly dither encd values */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_LZMAPRESET);        /* LZMA2 preset (compression level) */
  NODE_DEFINE_CONSTANT(constants, TIFFTAG_PERSAMPLE);         /* interface for per sample tags */
  NODE_DEFINE_CONSTANT(constants, PERSAMPLE_MERGED);              /* present as a single value */
  NODE_DEFINE_CONSTANT(constants, PERSAMPLE_MULTI);               /* present as multiple values */

  /*
 * EXIF tags
 */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_EXPOSURETIME);             /* Exposure time */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_FNUMBER);                  /* F number */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_EXPOSUREPROGRAM);          /* Exposure program */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SPECTRALSENSITIVITY);      /* Spectral sensitivity */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_ISOSPEEDRATINGS);          /* ISO speed rating */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_OECF);                     /* Optoelectric conversion \
								  factor */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_EXIFVERSION);              /* Exif version */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_DATETIMEORIGINAL);         /* Date and time of original \
							  data generation */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_DATETIMEDIGITIZED);        /* Date and time of digital \
							  data generation */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_COMPONENTSCONFIGURATION);  /* Meaning of each component */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_COMPRESSEDBITSPERPIXEL);   /* Image compression mode */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SHUTTERSPEEDVALUE);        /* Shutter speed */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_APERTUREVALUE);            /* Aperture */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_BRIGHTNESSVALUE);          /* Brightness */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_EXPOSUREBIASVALUE);        /* Exposure bias */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_MAXAPERTUREVALUE);         /* Maximum lens aperture */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBJECTDISTANCE);          /* Subject distance */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_METERINGMODE);             /* Metering mode */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_LIGHTSOURCE);              /* Light source */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_FLASH);                    /* Flash */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_FOCALLENGTH);              /* Lens focal length */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBJECTAREA);              /* Subject area */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_MAKERNOTE);                /* Manufacturer notes */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_USERCOMMENT);              /* User comments */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBSECTIME);               /* DateTime subseconds */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBSECTIMEORIGINAL);       /* DateTimeOriginal subseconds */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBSECTIMEDIGITIZED);      /* DateTimeDigitized subseconds */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_FLASHPIXVERSION);          /* Supported Flashpix version */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_COLORSPACE);               /* Color space information */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_PIXELXDIMENSION);          /* Valid image width */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_PIXELYDIMENSION);          /* Valid image height */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_RELATEDSOUNDFILE);         /* Related audio file */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_FLASHENERGY);              /* Flash energy */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SPATIALFREQUENCYRESPONSE); /* Spatial frequency response */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_FOCALPLANEXRESOLUTION);    /* Focal plane X resolution */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_FOCALPLANEYRESOLUTION);    /* Focal plane Y resolution */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_FOCALPLANERESOLUTIONUNIT); /* Focal plane resolution unit */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBJECTLOCATION);          /* Subject location */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_EXPOSUREINDEX);            /* Exposure index */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SENSINGMETHOD);            /* Sensing method */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_FILESOURCE);               /* File source */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SCENETYPE);                /* Scene type */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_CFAPATTERN);               /* CFA pattern */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_CUSTOMRENDERED);           /* Custom image processing */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_EXPOSUREMODE);             /* Exposure mode */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_WHITEBALANCE);             /* White balance */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_DIGITALZOOMRATIO);         /* Digital zoom ratio */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_FOCALLENGTHIN35MMFILM);    /* Focal length in 35 mm film */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SCENECAPTURETYPE);         /* Scene capture type */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_GAINCONTROL);              /* Gain control */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_CONTRAST);                 /* Contrast */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SATURATION);               /* Saturation */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SHARPNESS);                /* Sharpness */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_DEVICESETTINGDESCRIPTION); /* Device settings description */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_SUBJECTDISTANCERANGE);     /* Subject distance range */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_GAINCONTROL);              /* Gain control */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_GAINCONTROL);              /* Gain control */
  NODE_DEFINE_CONSTANT(constants, EXIFTAG_IMAGEUNIQUEID);            /* Unique image ID */

  exports->Set(Nan::New("constants").ToLocalChecked(), constants);
}

NAN_MODULE_INIT(Init)
{
  InitConstants(target);
}

NODE_MODULE(tiffh, Init);