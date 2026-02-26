/***********************************************************************
*
* Copyright (c) 2012-2024 Barbara Geller
* Copyright (c) 2012-2024 Ansel Sermersheim
*
* Copyright (c) 2015 The Qt Company Ltd.
* Copyright (c) 2012-2016 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
*
* This file is part of CopperSpice.
*
* CopperSpice is free software. You can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://www.gnu.org/licenses/
*
***********************************************************************/

#ifndef QRasterDefs_P_H
#define QRasterDefs_P_H


typedef struct LSCS_FT_Vector_
{
    int  x;
    int  y;

} LSCS_FT_Vector;

typedef struct  LSCS_FT_BBox_
{
    int  xMin, yMin;
    int  xMax, yMax;

} LSCS_FT_BBox;

typedef enum  LSCS_FT_Pixel_Mode_
{
    LSCS_FT_PIXEL_MODE_NONE = 0,
    LSCS_FT_PIXEL_MODE_MONO,
    LSCS_FT_PIXEL_MODE_GRAY,
    LSCS_FT_PIXEL_MODE_GRAY2,
    LSCS_FT_PIXEL_MODE_GRAY4,
    LSCS_FT_PIXEL_MODE_LCD,
    LSCS_FT_PIXEL_MODE_LCD_V,

    LSCS_FT_PIXEL_MODE_MAX      /* do not remove */

} LSCS_FT_Pixel_Mode;

#define lscs_ft_pixel_mode_none   LSCS_FT_PIXEL_MODE_NONE
#define lscs_ft_pixel_mode_mono   LSCS_FT_PIXEL_MODE_MONO
#define lscs_ft_pixel_mode_grays  LSCS_FT_PIXEL_MODE_GRAY
#define lscs_ft_pixel_mode_pal2   LSCS_FT_PIXEL_MODE_GRAY2
#define lscs_ft_pixel_mode_pal4   LSCS_FT_PIXEL_MODE_GRAY4


typedef struct  LSCS_FT_Bitmap_
{
    int             rows;
    int             width;
    int             pitch;
    unsigned char  *buffer;
    short           num_grays;
    char            pixel_mode;
    char            palette_mode;
    void           *palette;

} LSCS_FT_Bitmap;

typedef struct  LSCS_FT_Outline_
{
    int      n_contours;       /* number of contours in glyph        */
    int      n_points;         /* number of points in the glyph      */

    LSCS_FT_Vector  *points;     /* the outline's points               */
    char     *tags;            /* the points flags                   */
    int      *contours;        /* the contour end points             */

    int         flags;         /* outline masks                      */

} LSCS_FT_Outline;


#define LSCS_FT_OUTLINE_NONE             0x0
#define LSCS_FT_OUTLINE_OWNER            0x1
#define LSCS_FT_OUTLINE_EVEN_ODD_FILL    0x2
#define LSCS_FT_OUTLINE_REVERSE_FILL     0x4
#define LSCS_FT_OUTLINE_IGNORE_DROPOUTS  0x8

#define LSCS_FT_OUTLINE_HIGH_PRECISION   0x100
#define LSCS_FT_OUTLINE_SINGLE_PASS      0x200

#define lscs_ft_outline_none             LSCS_FT_OUTLINE_NONE
#define lscs_ft_outline_owner            LSCS_FT_OUTLINE_OWNER
#define lscs_ft_outline_even_odd_fill    LSCS_FT_OUTLINE_EVEN_ODD_FILL
#define lscs_ft_outline_reverse_fill     LSCS_FT_OUTLINE_REVERSE_FILL
#define lscs_ft_outline_ignore_dropouts  LSCS_FT_OUTLINE_IGNORE_DROPOUTS
#define lscs_ft_outline_high_precision   LSCS_FT_OUTLINE_HIGH_PRECISION
#define lscs_ft_outline_single_pass      LSCS_FT_OUTLINE_SINGLE_PASS

#define LSCS_FT_CURVE_TAG( flag )  ( flag & 3 )

#define LSCS_FT_CURVE_TAG_ON           1
#define LSCS_FT_CURVE_TAG_CONIC        0
#define LSCS_FT_CURVE_TAG_CUBIC        2

#define LSCS_FT_CURVE_TAG_TOUCH_X      8  /* reserved for the TrueType hinter */
#define LSCS_FT_CURVE_TAG_TOUCH_Y     16  /* reserved for the TrueType hinter */

#define LSCS_FT_CURVE_TAG_TOUCH_BOTH  ( LSCS_FT_CURVE_TAG_TOUCH_X | \
                                   LSCS_FT_CURVE_TAG_TOUCH_Y )

#define  LSCS_FT_Curve_Tag_On       LSCS_FT_CURVE_TAG_ON
#define  LSCS_FT_Curve_Tag_Conic    LSCS_FT_CURVE_TAG_CONIC
#define  LSCS_FT_Curve_Tag_Cubic    LSCS_FT_CURVE_TAG_CUBIC
#define  LSCS_FT_Curve_Tag_Touch_X  LSCS_FT_CURVE_TAG_TOUCH_X
#define  LSCS_FT_Curve_Tag_Touch_Y  LSCS_FT_CURVE_TAG_TOUCH_Y


typedef int
( *LSCS_FT_Outline_MoveToFunc )( LSCS_FT_Vector  *to, void *user );

#define LSCS_FT_Outline_MoveTo_Func  LSCS_FT_Outline_MoveToFunc


typedef int
( *LSCS_FT_Outline_LineToFunc )( LSCS_FT_Vector  *to, void *user );

#define  LSCS_FT_Outline_LineTo_Func  LSCS_FT_Outline_LineToFunc


typedef int
( *LSCS_FT_Outline_ConicToFunc )( LSCS_FT_Vector *control, LSCS_FT_Vector *to, void *user );

#define  LSCS_FT_Outline_ConicTo_Func  LSCS_FT_Outline_ConicToFunc

typedef int
( *LSCS_FT_Outline_CubicToFunc )( LSCS_FT_Vector  *control1,
                                  LSCS_FT_Vector  *control2,
                                  LSCS_FT_Vector  *to,
                                  void *user );

#define  LSCS_FT_Outline_CubicTo_Func  LSCS_FT_Outline_CubicToFunc


typedef struct  LSCS_FT_Outline_Funcs_
{
    LSCS_FT_Outline_MoveToFunc   move_to;
    LSCS_FT_Outline_LineToFunc   line_to;
    LSCS_FT_Outline_ConicToFunc  conic_to;
    LSCS_FT_Outline_CubicToFunc  cubic_to;

    int  shift;
    int  delta;

} LSCS_FT_Outline_Funcs;


#ifndef LSCS_FT_IMAGE_TAG
#define LSCS_FT_IMAGE_TAG( value, _x1, _x2, _x3, _x4 )  \
          value = ( ( (unsigned long)_x1 << 24 ) | \
                    ( (unsigned long)_x2 << 16 ) | \
                    ( (unsigned long)_x3 << 8  ) | \
                      (unsigned long)_x4         )
#endif


typedef enum  LSCS_FT_Glyph_Format_
{
    LSCS_FT_IMAGE_TAG( LSCS_FT_GLYPH_FORMAT_NONE, 0, 0, 0, 0 ),

    LSCS_FT_IMAGE_TAG( LSCS_FT_GLYPH_FORMAT_COMPOSITE, 'c', 'o', 'm', 'p' ),
    LSCS_FT_IMAGE_TAG( LSCS_FT_GLYPH_FORMAT_BITMAP,    'b', 'i', 't', 's' ),
    LSCS_FT_IMAGE_TAG( LSCS_FT_GLYPH_FORMAT_OUTLINE,   'o', 'u', 't', 'l' ),
    LSCS_FT_IMAGE_TAG( LSCS_FT_GLYPH_FORMAT_PLOTTER,   'p', 'l', 'o', 't' )

} LSCS_FT_Glyph_Format;


#define lscs_ft_glyph_format_none       LSCS_FT_GLYPH_FORMAT_NONE
#define lscs_ft_glyph_format_composite  LSCS_FT_GLYPH_FORMAT_COMPOSITE
#define lscs_ft_glyph_format_bitmap     LSCS_FT_GLYPH_FORMAT_BITMAP
#define lscs_ft_glyph_format_outline    LSCS_FT_GLYPH_FORMAT_OUTLINE
#define lscs_ft_glyph_format_plotter    LSCS_FT_GLYPH_FORMAT_PLOTTER

typedef struct TRaster_ *LSCS_FT_Raster;

typedef struct  LSCS_FT_Span_
{
    short x;
    unsigned short len;
    short y;
    unsigned char coverage;
} LSCS_FT_Span;


typedef void ( *LSCS_FT_SpanFunc )( int count, const LSCS_FT_Span *spans, void *worker );

#define LSCS_FT_Raster_Span_Func   LSCS_FT_SpanFunc

typedef int ( *LSCS_FT_Raster_BitTest_Func )( int y, int x, void *user );
typedef void ( *LSCS_FT_Raster_BitSet_Func )( int y, int x, void *user );


#define LSCS_FT_RASTER_FLAG_DEFAULT  0x0
#define LSCS_FT_RASTER_FLAG_AA       0x1
#define LSCS_FT_RASTER_FLAG_DIRECT   0x2
#define LSCS_FT_RASTER_FLAG_CLIP     0x4

/* deprecated */
#define lscs_ft_raster_flag_default  LSCS_FT_RASTER_FLAG_DEFAULT
#define lscs_ft_raster_flag_aa       LSCS_FT_RASTER_FLAG_AA
#define lscs_ft_raster_flag_direct   LSCS_FT_RASTER_FLAG_DIRECT
#define lscs_ft_raster_flag_clip     LSCS_FT_RASTER_FLAG_CLIP


typedef struct  LSCS_FT_Raster_Params_
{
    LSCS_FT_Bitmap  *target;
    void *source;
    int flags;
    LSCS_FT_SpanFunc gray_spans;
    LSCS_FT_SpanFunc black_spans;
    LSCS_FT_Raster_BitTest_Func bit_test;     /* doesn't work! */
    LSCS_FT_Raster_BitSet_Func  bit_set;      /* doesn't work! */
    void *user;
    LSCS_FT_BBox clip_box;
    int skip_spans;

} LSCS_FT_Raster_Params;


typedef int
( *LSCS_FT_Raster_NewFunc )( LSCS_FT_Raster  *raster );

#define  LSCS_FT_Raster_New_Func    LSCS_FT_Raster_NewFunc

typedef void
( *LSCS_FT_Raster_DoneFunc )( LSCS_FT_Raster  raster );

#define  LSCS_FT_Raster_Done_Func   LSCS_FT_Raster_DoneFunc

typedef void
( *LSCS_FT_Raster_ResetFunc )( LSCS_FT_Raster raster, unsigned char *pool_base, unsigned long  pool_size );

#define  LSCS_FT_Raster_Reset_Func   LSCS_FT_Raster_ResetFunc

typedef int
( *LSCS_FT_Raster_SetModeFunc )( LSCS_FT_Raster raster, unsigned long mode, void *args );

#define  LSCS_FT_Raster_Set_Mode_Func  LSCS_FT_Raster_SetModeFunc

typedef int
( *LSCS_FT_Raster_RenderFunc )( LSCS_FT_Raster raster, LSCS_FT_Raster_Params  *params );

#define  LSCS_FT_Raster_Render_Func    LSCS_FT_Raster_RenderFunc


typedef struct  LSCS_FT_Raster_Funcs_
{
    LSCS_FT_Glyph_Format         glyph_format;
    LSCS_FT_Raster_NewFunc       raster_new;
    LSCS_FT_Raster_ResetFunc     raster_reset;
    LSCS_FT_Raster_SetModeFunc   raster_set_mode;
    LSCS_FT_Raster_RenderFunc    raster_render;
    LSCS_FT_Raster_DoneFunc      raster_done;

} LSCS_FT_Raster_Funcs;

#endif