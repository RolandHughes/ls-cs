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

#ifndef QDECLARATIVEPATH_P_H
#define QDECLARATIVEPATH_P_H

#include <qdeclarativeitem.h>
#include <qdeclarative.h>
#include <QtCore/QObject>
#include <QtGui/QPainterPath>

QT_BEGIN_NAMESPACE

class QDeclarativePathElement : public QObject
{
    DECL_LSCS_OBJECT( QDeclarativePathElement )

public:
    QDeclarativePathElement( QObject *parent = nullptr ) : QObject( parent ) {}

    DECL_LSCS_SIGNAL_1( Public, void changed() )
    DECL_LSCS_SIGNAL_2( changed )
};

class QDeclarativePathAttribute : public QDeclarativePathElement
{
    DECL_LSCS_OBJECT( QDeclarativePathAttribute )

    DECL_LSCS_PROPERTY_READ( name, name )
    DECL_LSCS_PROPERTY_WRITE( name, setName )
    DECL_LSCS_PROPERTY_NOTIFY( name, nameChanged )
    DECL_LSCS_PROPERTY_READ( value, value )
    DECL_LSCS_PROPERTY_WRITE( value, setValue )
    DECL_LSCS_PROPERTY_NOTIFY( value, valueChanged )
public:
    QDeclarativePathAttribute( QObject *parent = nullptr ) : QDeclarativePathElement( parent ), _value( 0 ) {}


    QString name() const;
    void setName( const QString &name );

    qreal value() const;
    void setValue( qreal value );

    DECL_LSCS_SIGNAL_1( Public, void nameChanged() )
    DECL_LSCS_SIGNAL_2( nameChanged )
    DECL_LSCS_SIGNAL_1( Public, void valueChanged() )
    DECL_LSCS_SIGNAL_2( valueChanged )

private:
    QString _name;
    qreal _value;
};

class QDeclarativeCurve : public QDeclarativePathElement
{
    DECL_LSCS_OBJECT( QDeclarativeCurve )

    DECL_LSCS_PROPERTY_READ( x, x )
    DECL_LSCS_PROPERTY_WRITE( x, setX )
    DECL_LSCS_PROPERTY_NOTIFY( x, xChanged )
    DECL_LSCS_PROPERTY_READ( y, y )
    DECL_LSCS_PROPERTY_WRITE( y, setY )
    DECL_LSCS_PROPERTY_NOTIFY( y, yChanged )
public:
    QDeclarativeCurve( QObject *parent = nullptr ) : QDeclarativePathElement( parent ), _x( 0 ), _y( 0 ) {}

    qreal x() const;
    void setX( qreal x );

    qreal y() const;
    void setY( qreal y );

    virtual void addToPath( QPainterPath & ) {}

    DECL_LSCS_SIGNAL_1( Public, void xChanged() )
    DECL_LSCS_SIGNAL_2( xChanged )
    DECL_LSCS_SIGNAL_1( Public, void yChanged() )
    DECL_LSCS_SIGNAL_2( yChanged )

private:
    qreal _x;
    qreal _y;
};

class QDeclarativePathLine : public QDeclarativeCurve
{
    DECL_LSCS_OBJECT( QDeclarativePathLine )

public:
    QDeclarativePathLine( QObject *parent = nullptr ) : QDeclarativeCurve( parent ) {}

    void addToPath( QPainterPath &path );
};

class QDeclarativePathQuad : public QDeclarativeCurve
{
    DECL_LSCS_OBJECT( QDeclarativePathQuad )

    DECL_LSCS_PROPERTY_READ( controlX, controlX )
    DECL_LSCS_PROPERTY_WRITE( controlX, setControlX )
    DECL_LSCS_PROPERTY_NOTIFY( controlX, controlXChanged )
    DECL_LSCS_PROPERTY_READ( controlY, controlY )
    DECL_LSCS_PROPERTY_WRITE( controlY, setControlY )
    DECL_LSCS_PROPERTY_NOTIFY( controlY, controlYChanged )
public:
    QDeclarativePathQuad( QObject *parent = nullptr ) : QDeclarativeCurve( parent ), _controlX( 0 ), _controlY( 0 ) {}

    qreal controlX() const;
    void setControlX( qreal x );

    qreal controlY() const;
    void setControlY( qreal y );

    void addToPath( QPainterPath &path );

    DECL_LSCS_SIGNAL_1( Public, void controlXChanged() )
    DECL_LSCS_SIGNAL_2( controlXChanged )
    DECL_LSCS_SIGNAL_1( Public, void controlYChanged() )
    DECL_LSCS_SIGNAL_2( controlYChanged )

private:
    qreal _controlX;
    qreal _controlY;
};

class QDeclarativePathCubic : public QDeclarativeCurve
{
    DECL_LSCS_OBJECT( QDeclarativePathCubic )

    DECL_LSCS_PROPERTY_READ( control1X, control1X )
    DECL_LSCS_PROPERTY_WRITE( control1X, setControl1X )
    DECL_LSCS_PROPERTY_NOTIFY( control1X, control1XChanged )
    DECL_LSCS_PROPERTY_READ( control1Y, control1Y )
    DECL_LSCS_PROPERTY_WRITE( control1Y, setControl1Y )
    DECL_LSCS_PROPERTY_NOTIFY( control1Y, control1YChanged )
    DECL_LSCS_PROPERTY_READ( control2X, control2X )
    DECL_LSCS_PROPERTY_WRITE( control2X, setControl2X )
    DECL_LSCS_PROPERTY_NOTIFY( control2X, control2XChanged )
    DECL_LSCS_PROPERTY_READ( control2Y, control2Y )
    DECL_LSCS_PROPERTY_WRITE( control2Y, setControl2Y )
    DECL_LSCS_PROPERTY_NOTIFY( control2Y, control2YChanged )

    QDeclarativePathCubic( QObject *parent = nullptr ) : QDeclarativeCurve( parent ), _control1X( 0 ), _control1Y( 0 ),
        _control2X( 0 ),
        _control2Y( 0 ) {}

    qreal control1X() const;
    void setControl1X( qreal x );

    qreal control1Y() const;
    void setControl1Y( qreal y );

    qreal control2X() const;
    void setControl2X( qreal x );

    qreal control2Y() const;
    void setControl2Y( qreal y );

    void addToPath( QPainterPath &path );

public:
    DECL_LSCS_SIGNAL_1( Public, void control1XChanged() )
    DECL_LSCS_SIGNAL_2( control1XChanged )
    DECL_LSCS_SIGNAL_1( Public, void control1YChanged() )
    DECL_LSCS_SIGNAL_2( control1YChanged )
    DECL_LSCS_SIGNAL_1( Public, void control2XChanged() )
    DECL_LSCS_SIGNAL_2( control2XChanged )
    DECL_LSCS_SIGNAL_1( Public, void control2YChanged() )
    DECL_LSCS_SIGNAL_2( control2YChanged )

private:
    qreal _control1X;
    qreal _control1Y;
    qreal _control2X;
    qreal _control2Y;
};

class QDeclarativePathPercent : public QDeclarativePathElement
{
    DECL_LSCS_OBJECT( QDeclarativePathPercent )
    DECL_LSCS_PROPERTY_READ( value, value )
    DECL_LSCS_PROPERTY_WRITE( value, setValue )
    DECL_LSCS_PROPERTY_NOTIFY( value, valueChanged )

public:
    QDeclarativePathPercent( QObject *parent = nullptr ) : QDeclarativePathElement( parent ) {}

    qreal value() const;
    void setValue( qreal value );

    DECL_LSCS_SIGNAL_1( Public, void valueChanged() )
    DECL_LSCS_SIGNAL_2( valueChanged )

private:
    qreal _value;
};

class QDeclarativePathPrivate;
class QDeclarativePath : public QObject, public QDeclarativeParserStatus
{
    DECL_LSCS_OBJECT( QDeclarativePath )

    LSCS_INTERFACES( QDeclarativeParserStatus, QDeclarativeParserStatus )

    DECL_LSCS_PROPERTY_READ( pathElements, pathElements )
    DECL_LSCS_PROPERTY_READ( startX, startX )
    DECL_LSCS_PROPERTY_WRITE( startX, setStartX )
    DECL_LSCS_PROPERTY_NOTIFY( startX, startXChanged )
    DECL_LSCS_PROPERTY_READ( startY, startY )
    DECL_LSCS_PROPERTY_WRITE( startY, setStartY )
    DECL_LSCS_PROPERTY_NOTIFY( startY, startYChanged )
    DECL_LSCS_PROPERTY_READ( closed, isClosed )
    DECL_LSCS_PROPERTY_NOTIFY( closed, changed )
    DECL_LSCS_CLASSINFO( "DefaultProperty", "pathElements" )

public:
    QDeclarativePath( QObject *parent = nullptr );
    ~QDeclarativePath();

    QDeclarativeListProperty<QDeclarativePathElement> pathElements();

    qreal startX() const;
    void setStartX( qreal x );

    qreal startY() const;
    void setStartY( qreal y );

    bool isClosed() const;

    QPainterPath path() const;
    QStringList attributes() const;
    qreal attributeAt( const QString &, qreal ) const;
    QPointF pointAt( qreal ) const;

    DECL_LSCS_SIGNAL_1( Public, void changed() )
    DECL_LSCS_SIGNAL_2( changed )
    DECL_LSCS_SIGNAL_1( Public, void startXChanged() )
    DECL_LSCS_SIGNAL_2( startXChanged )
    DECL_LSCS_SIGNAL_1( Public, void startYChanged() )
    DECL_LSCS_SIGNAL_2( startYChanged )

protected:
    virtual void componentComplete();
    virtual void classBegin();

private :
    DECL_LSCS_SLOT_1( Private, void processPath() )
    DECL_LSCS_SLOT_2( processPath )

    struct AttributePoint
    {
        AttributePoint() : percent( 0 ), scale( 1 ), origpercent( 0 ) {}
        AttributePoint( const AttributePoint &other )
            : percent( other.percent ), scale( other.scale ), origpercent( other.origpercent ), values( other.values ) {}
        AttributePoint &operator=( const AttributePoint &other )
        {
            percent = other.percent;
            scale = other.scale;
            origpercent = other.origpercent;
            values = other.values;
            return *this;
        }
        qreal percent;      //massaged percent along the painter path
        qreal scale;
        qreal origpercent;  //'real' percent along the painter path
        QHash<QString, qreal> values;
    };

    void interpolate( int idx, const QString &name, qreal value );
    void endpoint( const QString &name );
    void createPointCache() const;

    Q_DISABLE_COPY( QDeclarativePath )
    Q_DECLARE_PRIVATE( QDeclarativePath )
};

QT_END_NAMESPACE

QML_DECLARE_TYPE( QDeclarativePathElement )
QML_DECLARE_TYPE( QDeclarativePathAttribute )
QML_DECLARE_TYPE( QDeclarativeCurve )
QML_DECLARE_TYPE( QDeclarativePathLine )
QML_DECLARE_TYPE( QDeclarativePathQuad )
QML_DECLARE_TYPE( QDeclarativePathCubic )
QML_DECLARE_TYPE( QDeclarativePathPercent )
QML_DECLARE_TYPE( QDeclarativePath )

#endif // QDECLARATIVEPATH_H
