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

#include <qcolormap.h>

#include <qcolor.h>
#include <qguiapplication.h>
#include <qpaintdevice.h>
#include <qscreen.h>

class QColormapPrivate
{
public:
    inline QColormapPrivate()
        : ref( 1 ), mode( QColormap::Direct ), depth( 0 ), numcolors( 0 )
    { }

    QAtomicInt ref;

    QColormap::Mode mode;
    int depth;
    int numcolors;
};

static QColormapPrivate *screenMap = nullptr;

void QColormap::initialize()
{
    screenMap = new QColormapPrivate;

    if ( ! QGuiApplication::primaryScreen() )
    {
        qWarning( "QColormap::initialize() No screens are available, assuming 24-bit color" );

        screenMap->depth = 24;
        screenMap->mode = QColormap::Direct;
        return;
    }

    screenMap->depth = QGuiApplication::primaryScreen()->depth();

    if ( screenMap->depth < 8 )
    {
        screenMap->mode = QColormap::Indexed;
        screenMap->numcolors = 256;
    }
    else
    {
        screenMap->mode = QColormap::Direct;
        screenMap->numcolors = -1;
    }
}

void QColormap::cleanup()
{
    delete screenMap;
    screenMap = nullptr;
}

QColormap QColormap::instance( int )
{
    return QColormap();
}

QColormap::QColormap()
    : d( screenMap )
{
    d->ref.ref();
}

QColormap::QColormap( const QColormap &colormap )
    : d ( colormap.d )
{
    d->ref.ref();
}

QColormap::~QColormap()
{
    if ( !d->ref.deref() )
    {
        delete d;
    }
}

QColormap::Mode QColormap::mode() const
{
    return d->mode;
}

int QColormap::depth() const
{
    return d->depth;
}

int QColormap::size() const
{
    return d->numcolors;
}

#ifndef LSCS_QWS_DEPTH16_RGB
#define LSCS_QWS_DEPTH16_RGB 565
#endif

static constexpr const int lscs_rbits = ( LSCS_QWS_DEPTH16_RGB / 100 );
static constexpr const int lscs_gbits = ( LSCS_QWS_DEPTH16_RGB / 10 % 10 );
static constexpr const int lscs_bbits = ( LSCS_QWS_DEPTH16_RGB % 10 );

static constexpr const int lscs_red_shift      = lscs_bbits + lscs_gbits - ( 8 - lscs_rbits );
static constexpr const int lscs_green_shift    = lscs_bbits - ( 8 - lscs_gbits );
static constexpr const int lscs_neg_blue_shift = 8 - lscs_bbits;
static constexpr const int lscs_blue_mask      = ( 1 << lscs_bbits ) - 1;
static constexpr const int lscs_green_mask     = ( 1 << ( lscs_gbits + lscs_bbits ) ) - ( 1 << lscs_bbits );
static constexpr const int lscs_red_mask       = ( 1 << ( lscs_rbits + lscs_gbits + lscs_bbits ) ) - ( 1 <<
        ( lscs_gbits + lscs_bbits ) );

static constexpr const int lscs_red_rounding_shift   = lscs_red_shift + lscs_rbits;
static constexpr const int lscs_green_rounding_shift = lscs_green_shift + lscs_gbits;
static constexpr const int lscs_blue_rounding_shift  = lscs_bbits - lscs_neg_blue_shift;

inline ushort lscs_convRgbTo16( QRgb c )
{
    const int tr = qRed( c ) << lscs_red_shift;
    const int tg = qGreen( c ) << lscs_green_shift;
    const int tb = qBlue( c ) >> lscs_neg_blue_shift;

    return ( tb & lscs_blue_mask ) | ( tg & lscs_green_mask ) | ( tr & lscs_red_mask );
}

inline QRgb lscs_conv16ToRgb( ushort c )
{
    const int r = ( c & lscs_red_mask );
    const int g = ( c & lscs_green_mask );
    const int b = ( c & lscs_blue_mask );
    const int tr = r >> lscs_red_shift | r >> lscs_red_rounding_shift;
    const int tg = g >> lscs_green_shift | g >> lscs_green_rounding_shift;
    const int tb = b << lscs_neg_blue_shift | b >> lscs_blue_rounding_shift;

    return qRgb( tr, tg, tb );
}

uint QColormap::pixel( const QColor &color ) const
{
    QRgb rgb = color.rgba();

    if ( d->mode == QColormap::Direct )
    {
        switch ( d->depth )
        {
            case 16:
                return lscs_convRgbTo16( rgb );

            case 24:
            case 32:
            {
                const int r = qRed( rgb );
                const int g = qGreen( rgb );
                const int b = qBlue( rgb );
                const int red_shift = 16;
                const int green_shift = 8;
                const int red_mask   = 0xff0000;
                const int green_mask = 0x00ff00;
                const int blue_mask  = 0x0000ff;
                const int tg = g << green_shift;

#ifdef LSCS_QWS_DEPTH_32_BGR

                if ( lscs_screen->pixelType() == QScreen::BGRPixel )
                {
                    const int tb = b << red_shift;
                    return 0xff000000 | ( r & blue_mask ) | ( tg & green_mask ) | ( tb & red_mask );
                }

#endif
                const int tr = r << red_shift;
                return 0xff000000 | ( b & blue_mask ) | ( tg & green_mask ) | ( tr & red_mask );
            }
        }
    }

    return 0;
}

const QColor QColormap::colorAt( uint pixel ) const
{
    if ( d->mode == Direct )
    {
        if ( d->depth == 16 )
        {
            pixel = lscs_conv16ToRgb( pixel );
        }

        const int red_shift = 16;
        const int green_shift = 8;
        const int red_mask   = 0xff0000;
        const int green_mask = 0x00ff00;
        const int blue_mask  = 0x0000ff;

#ifdef LSCS_QWS_DEPTH_32_BGR

        if ( lscs_screen->pixelType() == QScreen::BGRPixel )
        {
            return QColor( ( pixel & blue_mask ),
                           ( pixel & green_mask ) >> green_shift,
                           ( pixel & red_mask ) >> red_shift );
        }

#endif

        return QColor( ( pixel & red_mask ) >> red_shift,
                       ( pixel & green_mask ) >> green_shift,
                       ( pixel & blue_mask ) );
    }

    return QColor();
}

const QVector<QColor> QColormap::colormap() const
{
    return QVector<QColor>();
}

QColormap &QColormap::operator=( const QColormap &colormap )
{
    qAtomicAssign( d, colormap.d );
    return *this;
}

