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

#ifndef QDeclarativeRectangle_P_H
#define QDeclarativeRectangle_P_H

#include <qdeclarativeitem.h>
#include <QtGui/qbrush.h>
#include <qdeclarativeglobal_p.h>

QT_BEGIN_NAMESPACE

class Q_DECLARATIVE_PRIVATE_EXPORT QDeclarativePen : public QObject
{
    DECL_LSCS_OBJECT( QDeclarativePen )

    DECL_LSCS_PROPERTY_READ( width, width )
    DECL_LSCS_PROPERTY_WRITE( width, setWidth )
    DECL_LSCS_PROPERTY_NOTIFY( width, penChanged )
    DECL_LSCS_PROPERTY_READ( color, color )
    DECL_LSCS_PROPERTY_WRITE( color, setColor )
    DECL_LSCS_PROPERTY_NOTIFY( color, penChanged )

public:
    QDeclarativePen( QObject *parent = nullptr )
        : QObject( parent ), _width( 1 ), _color( "#000000" ), _valid( false )
    {
    }

    int width() const
    {
        return _width;
    }
    void setWidth( int w );

    QColor color() const
    {
        return _color;
    }
    void setColor( const QColor &c );

    bool isValid()
    {
        return _valid;
    }

public:
    DECL_LSCS_SIGNAL_1( Public, void penChanged() )
    DECL_LSCS_SIGNAL_2( penChanged )

private:
    int _width;
    QColor _color;
    bool _valid;
};

class QDeclarativeGradientStop : public QObject
{
    DECL_LSCS_OBJECT( QDeclarativeGradientStop )

    DECL_LSCS_PROPERTY_READ( position, position )
    DECL_LSCS_PROPERTY_WRITE( position, setPosition )
    DECL_LSCS_PROPERTY_READ( color, color )
    DECL_LSCS_PROPERTY_WRITE( color, setColor )

public:
    QDeclarativeGradientStop( QObject *parent = nullptr ) : QObject( parent ) {}

    qreal position() const
    {
        return m_position;
    }
    void setPosition( qreal position )
    {
        m_position = position;
        updateGradient();
    }

    QColor color() const
    {
        return m_color;
    }
    void setColor( const QColor &color )
    {
        m_color = color;
        updateGradient();
    }

private:
    void updateGradient();

private:
    qreal m_position;
    QColor m_color;
};

class QDeclarativeGradient : public QObject
{
    DECL_LSCS_OBJECT( QDeclarativeGradient )

    DECL_LSCS_PROPERTY_READ( stops, stops )
    DECL_LSCS_CLASSINFO( "DefaultProperty", "stops" )

public:
    QDeclarativeGradient( QObject *parent = nullptr ) : QObject( parent ), m_gradient( 0 ) {}
    ~QDeclarativeGradient()
    {
        delete m_gradient;
    }

    QDeclarativeListProperty<QDeclarativeGradientStop> stops()
    {
        return QDeclarativeListProperty<QDeclarativeGradientStop>( this, m_stops );
    }

    const QGradient *gradient() const;

public:
    DECL_LSCS_SIGNAL_1( Public, void updated() )
    DECL_LSCS_SIGNAL_2( updated )

private:
    void doUpdate();

private:
    QList<QDeclarativeGradientStop *> m_stops;
    mutable QGradient *m_gradient;
    friend class QDeclarativeGradientStop;
};

class QDeclarativeRectanglePrivate;
class Q_DECLARATIVE_PRIVATE_EXPORT QDeclarativeRectangle : public QDeclarativeItem
{
    DECL_LSCS_OBJECT( QDeclarativeRectangle )

    DECL_LSCS_PROPERTY_READ( color, color )
    DECL_LSCS_PROPERTY_WRITE( color, setColor )
    DECL_LSCS_PROPERTY_NOTIFY( color, colorChanged )
    DECL_LSCS_PROPERTY_READ( *gradient, gradient )
    DECL_LSCS_PROPERTY_WRITE( *gradient, setGradient )
    DECL_LSCS_PROPERTY_READ( *, border )
    DECL_LSCS_PROPERTY_CONSTANT( * )
    DECL_LSCS_PROPERTY_READ( radius, radius )
    DECL_LSCS_PROPERTY_WRITE( radius, setRadius )
    DECL_LSCS_PROPERTY_NOTIFY( radius, radiusChanged )
public:
    QDeclarativeRectangle( QDeclarativeItem *parent = 0 );

    QColor color() const;
    void setColor( const QColor & );

    QDeclarativePen *border();

    QDeclarativeGradient *gradient() const;
    void setGradient( QDeclarativeGradient *gradient );

    qreal radius() const;
    void setRadius( qreal radius );

    QRectF boundingRect() const;

    void paint( QPainter *, const QStyleOptionGraphicsItem *, QWidget * );

public:
    DECL_LSCS_SIGNAL_1( Public, void colorChanged() )
    DECL_LSCS_SIGNAL_2( colorChanged )
    DECL_LSCS_SIGNAL_1( Public, void radiusChanged() )
    DECL_LSCS_SIGNAL_2( radiusChanged )

private :
    DECL_LSCS_SLOT_1( Private, void doUpdate() )
    DECL_LSCS_SLOT_2( doUpdate )

    void generateRoundedRect();
    void generateBorderedRect();
    void drawRect( QPainter &painter );

    Q_DISABLE_COPY( QDeclarativeRectangle )
    Q_DECLARE_PRIVATE_D( QGraphicsItem::d_ptr.data(), QDeclarativeRectangle )
};

QT_END_NAMESPACE

QML_DECLARE_TYPE( QDeclarativePen )
QML_DECLARE_TYPE( QDeclarativeGradientStop )
QML_DECLARE_TYPE( QDeclarativeGradient )
QML_DECLARE_TYPE( QDeclarativeRectangle )


#endif // QDECLARATIVERECT_H
