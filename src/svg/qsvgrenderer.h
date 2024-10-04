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

#ifndef QSVGRENDERER_H
#define QSVGRENDERER_H

#include <qmatrix.h>

#ifndef QT_NO_SVGRENDERER

#include <qobject.h>
#include <qrect.h>
#include <qscopedpointer.h>
#include <qsize.h>
#include <qxmlstream.h>

class QByteArray;
class QPainter;
class QSvgRendererPrivate;

class Q_SVG_EXPORT QSvgRenderer : public QObject
{
    SVG_LSCS_OBJECT( QSvgRenderer )

    SVG_LSCS_PROPERTY_READ( viewBox, viewBoxF )
    SVG_LSCS_PROPERTY_WRITE( viewBox, cs_setViewBox )

    SVG_LSCS_PROPERTY_READ( framesPerSecond, framesPerSecond )
    SVG_LSCS_PROPERTY_WRITE( framesPerSecond, setFramesPerSecond )

    SVG_LSCS_PROPERTY_READ( currentFrame, currentFrame )
    SVG_LSCS_PROPERTY_WRITE( currentFrame, setCurrentFrame )

public:
    QSvgRenderer( QObject *parent = nullptr );
    QSvgRenderer( const QString &filename, QObject *parent = nullptr );
    QSvgRenderer( const QByteArray &contents, QObject *parent = nullptr );
    QSvgRenderer( QXmlStreamReader *contents, QObject *parent = nullptr );
    ~QSvgRenderer();

    bool isValid() const;

    QSize defaultSize() const;

    QRect viewBox() const;
    QRectF viewBoxF() const;
    void setViewBox( const QRect &viewBox );
    void setViewBox( const QRectF &viewBox );

    // wrapper for overloaded method
    inline void cs_setViewBox( const QRectF &viewBox );

    bool animated() const;
    int framesPerSecond() const;
    void setFramesPerSecond( int num );
    int currentFrame() const;
    void setCurrentFrame( int );
    int animationDuration() const;   //in seconds

    QRectF boundsOnElement( const QString &id ) const;
    bool elementExists( const QString &id ) const;
    QMatrix matrixForElement( const QString &id ) const;

    SVG_LSCS_SLOT_1( Public, bool load( const QString &filename ) )
    SVG_LSCS_SLOT_OVERLOAD_BOOL( load, ( const QString & ) )

    SVG_LSCS_SLOT_1( Public, bool load( const QByteArray &contents ) )
    SVG_LSCS_SLOT_OVERLOAD_BOOL( load, ( const QByteArray & ) )

    SVG_LSCS_SLOT_1( Public, bool load( QXmlStreamReader *contents ) )
    SVG_LSCS_SLOT_OVERLOAD_BOOL( load, ( QXmlStreamReader * ) )

    SVG_LSCS_SLOT_1( Public, void render( QPainter *painter ) )
    SVG_LSCS_SLOT_OVERLOAD( render, ( QPainter * ) )

    SVG_LSCS_SLOT_1( Public, void render( QPainter *painter, const QRectF &bounds ) )
    SVG_LSCS_SLOT_OVERLOAD( render, ( QPainter *, const QRectF & ) )

    SVG_LSCS_SLOT_1( Public, void render( QPainter *painter, const QString &elementId, const QRectF &bounds = QRectF() ) )
    SVG_LSCS_SLOT_OVERLOAD( render, ( QPainter *, const QString &, const QRectF & ) )

    SVG_LSCS_SIGNAL_1( Public, void repaintNeeded() )
    SVG_LSCS_SIGNAL_2( repaintNeeded )

protected:
    QScopedPointer<QSvgRendererPrivate> d_ptr;

private:
    Q_DECLARE_PRIVATE( QSvgRenderer )

};

void QSvgRenderer::cs_setViewBox( const QRectF &viewbox )
{
    setViewBox( viewbox );
}

#endif // QT_NO_SVGRENDERER
#endif // QSVGRENDERER_H
