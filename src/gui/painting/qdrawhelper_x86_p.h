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

#ifndef QDRAWHELPER_X86_P_H
#define QDRAWHELPER_X86_P_H

#include <qdrawhelper_p.h>

#ifdef __SSE2__
void lscs_memfill32( quint32 *dest, quint32 value, int count );
void lscs_memfill16( quint16 *dest, quint16 value, int count );
void lscs_bitmapblit32_sse2( QRasterBuffer *rasterBuffer, int x, int y,
                           const QRgba64 &color, const uchar *src, int width, int height, int stride );

void lscs_bitmapblit8888_sse2( QRasterBuffer *rasterBuffer, int x, int y,
                             const QRgba64 &color, const uchar *src, int width, int height, int stride );

void lscs_bitmapblit16_sse2( QRasterBuffer *rasterBuffer, int x, int y,
                           const QRgba64 &color, const uchar *src, int width, int height, int stride );

void lscs_blend_argb32_on_argb32_sse2( uchar *destPixels, int dbpl,
                                     const uchar *srcPixels, int sbpl, int w, int h, int const_alpha );

void lscs_blend_rgb32_on_rgb32_sse2( uchar *destPixels, int dbpl,
                                   const uchar *srcPixels, int sbpl, int w, int h, int const_alpha );

extern CompositionFunction lscs_functionForModeSSE2[];
extern CompositionFunctionSolid lscs_functionForModeSolidSSE2[];
#endif

static constexpr const int numCompositionFunctions = 38;

#endif
