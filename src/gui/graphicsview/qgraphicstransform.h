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

#ifndef QGRAPHICSTRANSFORM_H
#define QGRAPHICSTRANSFORM_H

#include <qobject.h>
#include <qvector3d.h>
#include <qtransform.h>
#include <qmatrix4x4.h>
#include <qscopedpointer.h>

#ifndef LSCS_NO_GRAPHICSVIEW

class QGraphicsItem;
class QGraphicsTransformPrivate;
class QGraphicsScalePrivate;
class QGraphicsRotationPrivate;

class Q_GUI_EXPORT QGraphicsTransform : public QObject
{
    GUI_LSCS_OBJECT( QGraphicsTransform )

public:
    QGraphicsTransform( QObject *parent = nullptr );
    ~QGraphicsTransform();

    virtual void applyTo( QMatrix4x4 *matrix ) const = 0;

protected :
    GUI_LSCS_SLOT_1( Protected, void update() )
    GUI_LSCS_SLOT_2( update )

    QGraphicsTransform( QGraphicsTransformPrivate &p, QObject *parent );

    QScopedPointer<QGraphicsTransformPrivate> d_ptr;

private:
    friend class QGraphicsItem;
    friend class QGraphicsItemPrivate;
    Q_DECLARE_PRIVATE( QGraphicsTransform )
};

class Q_GUI_EXPORT QGraphicsScale : public QGraphicsTransform
{
    GUI_LSCS_OBJECT( QGraphicsScale )

    GUI_LSCS_PROPERTY_READ( origin, origin )
    GUI_LSCS_PROPERTY_WRITE( origin, setOrigin )
    GUI_LSCS_PROPERTY_NOTIFY( origin, originChanged )
    GUI_LSCS_PROPERTY_READ( xScale, xScale )
    GUI_LSCS_PROPERTY_WRITE( xScale, setXScale )
    GUI_LSCS_PROPERTY_NOTIFY( xScale, xScaleChanged )
    GUI_LSCS_PROPERTY_READ( yScale, yScale )
    GUI_LSCS_PROPERTY_WRITE( yScale, setYScale )
    GUI_LSCS_PROPERTY_NOTIFY( yScale, yScaleChanged )
    GUI_LSCS_PROPERTY_READ( zScale, zScale )
    GUI_LSCS_PROPERTY_WRITE( zScale, setZScale )
    GUI_LSCS_PROPERTY_NOTIFY( zScale, zScaleChanged )

public:
    QGraphicsScale( QObject *parent = nullptr );
    ~QGraphicsScale();

    QVector3D origin() const;
    void setOrigin( const QVector3D &point );

    qreal xScale() const;
    void setXScale( qreal value );

    qreal yScale() const;
    void setYScale( qreal value );

    qreal zScale() const;
    void setZScale( qreal value );

    void applyTo( QMatrix4x4 *matrix ) const override;

    GUI_LSCS_SIGNAL_1( Public, void originChanged() )
    GUI_LSCS_SIGNAL_2( originChanged )
    GUI_LSCS_SIGNAL_1( Public, void xScaleChanged() )
    GUI_LSCS_SIGNAL_2( xScaleChanged )
    GUI_LSCS_SIGNAL_1( Public, void yScaleChanged() )
    GUI_LSCS_SIGNAL_2( yScaleChanged )
    GUI_LSCS_SIGNAL_1( Public, void zScaleChanged() )
    GUI_LSCS_SIGNAL_2( zScaleChanged )
    GUI_LSCS_SIGNAL_1( Public, void scaleChanged() )
    GUI_LSCS_SIGNAL_2( scaleChanged )

private:
    Q_DECLARE_PRIVATE( QGraphicsScale )
};

class Q_GUI_EXPORT QGraphicsRotation : public QGraphicsTransform
{
    GUI_LSCS_OBJECT( QGraphicsRotation )

    GUI_LSCS_PROPERTY_READ( origin, origin )
    GUI_LSCS_PROPERTY_WRITE( origin, setOrigin )
    GUI_LSCS_PROPERTY_NOTIFY( origin, originChanged )

    GUI_LSCS_PROPERTY_READ( angle, angle )
    GUI_LSCS_PROPERTY_WRITE( angle, setAngle )
    GUI_LSCS_PROPERTY_NOTIFY( angle, angleChanged )

    GUI_LSCS_PROPERTY_READ( axis, axis )
    GUI_LSCS_PROPERTY_WRITE( axis, lscs_setAxis )
    GUI_LSCS_PROPERTY_NOTIFY( axis, axisChanged )

public:
    QGraphicsRotation( QObject *parent = nullptr );
    ~QGraphicsRotation();

    QVector3D origin() const;
    void setOrigin( const QVector3D &point );

    qreal angle() const;
    void setAngle( qreal value );

    QVector3D axis() const;
    void setAxis( const QVector3D &axis );
    void setAxis( Qt::Axis axis );

    void applyTo( QMatrix4x4 *matrix ) const override;

    GUI_LSCS_SIGNAL_1( Public, void originChanged() )
    GUI_LSCS_SIGNAL_2( originChanged )

    GUI_LSCS_SIGNAL_1( Public, void angleChanged() )
    GUI_LSCS_SIGNAL_2( angleChanged )

    GUI_LSCS_SIGNAL_1( Public, void axisChanged() )
    GUI_LSCS_SIGNAL_2( axisChanged )

    // wrapper for static method
    inline void lscs_setAxis( const QVector3D &axis );

private:
    Q_DECLARE_PRIVATE( QGraphicsRotation )
};

void QGraphicsRotation::lscs_setAxis( const QVector3D &axis )
{
    setAxis( axis );
}


#endif //LSCS_NO_GRAPHICSVIEW

#endif // QFXTRANSFORM_H
