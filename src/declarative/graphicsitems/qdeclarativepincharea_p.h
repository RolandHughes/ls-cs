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

#ifndef QDECLARATIVEPINCHAREA_P_H
#define QDECLARATIVEPINCHAREA_P_H

#include <qdeclarativeitem.h>

LSCS_BEGIN_NAMESPACE

class QDeclarativePinch : public QObject
{
    DECL_LSCS_OBJECT( QDeclarativePinch )

    DECL_LSCS_ENUM( Axis )

    DECL_LSCS_PROPERTY_READ( *target, target )
    DECL_LSCS_PROPERTY_WRITE( *target, setTarget )
    DECL_LSCS_PROPERTY_RESET( *target, resetTarget )
    DECL_LSCS_PROPERTY_READ( minimumScale, minimumScale )
    DECL_LSCS_PROPERTY_WRITE( minimumScale, setMinimumScale )
    DECL_LSCS_PROPERTY_NOTIFY( minimumScale, minimumScaleChanged )
    DECL_LSCS_PROPERTY_READ( maximumScale, maximumScale )
    DECL_LSCS_PROPERTY_WRITE( maximumScale, setMaximumScale )
    DECL_LSCS_PROPERTY_NOTIFY( maximumScale, maximumScaleChanged )
    DECL_LSCS_PROPERTY_READ( minimumRotation, minimumRotation )
    DECL_LSCS_PROPERTY_WRITE( minimumRotation, setMinimumRotation )
    DECL_LSCS_PROPERTY_NOTIFY( minimumRotation, minimumRotationChanged )
    DECL_LSCS_PROPERTY_READ( maximumRotation, maximumRotation )
    DECL_LSCS_PROPERTY_WRITE( maximumRotation, setMaximumRotation )
    DECL_LSCS_PROPERTY_NOTIFY( maximumRotation, maximumRotationChanged )
    DECL_LSCS_PROPERTY_READ( dragAxis, axis )
    DECL_LSCS_PROPERTY_WRITE( dragAxis, setAxis )
    DECL_LSCS_PROPERTY_NOTIFY( dragAxis, dragAxisChanged )
    DECL_LSCS_PROPERTY_READ( minimumX, xmin )
    DECL_LSCS_PROPERTY_WRITE( minimumX, setXmin )
    DECL_LSCS_PROPERTY_NOTIFY( minimumX, minimumXChanged )
    DECL_LSCS_PROPERTY_READ( maximumX, xmax )
    DECL_LSCS_PROPERTY_WRITE( maximumX, setXmax )
    DECL_LSCS_PROPERTY_NOTIFY( maximumX, maximumXChanged )
    DECL_LSCS_PROPERTY_READ( minimumY, ymin )
    DECL_LSCS_PROPERTY_WRITE( minimumY, setYmin )
    DECL_LSCS_PROPERTY_NOTIFY( minimumY, minimumYChanged )
    DECL_LSCS_PROPERTY_READ( maximumY, ymax )
    DECL_LSCS_PROPERTY_WRITE( maximumY, setYmax )
    DECL_LSCS_PROPERTY_NOTIFY( maximumY, maximumYChanged )
    DECL_LSCS_PROPERTY_READ( active, active )
    DECL_LSCS_PROPERTY_NOTIFY( active, activeChanged )

public:
    QDeclarativePinch();

    QGraphicsObject *target() const
    {
        return m_target;
    }
    void setTarget( QGraphicsObject *target )
    {
        if ( target == m_target )
        {
            return;
        }

        m_target = target;
        emit targetChanged();
    }
    void resetTarget()
    {
        if ( !m_target )
        {
            return;
        }

        m_target = 0;
        emit targetChanged();
    }

    qreal minimumScale() const
    {
        return m_minScale;
    }
    void setMinimumScale( qreal s )
    {
        if ( s == m_minScale )
        {
            return;
        }

        m_minScale = s;
        emit minimumScaleChanged();
    }
    qreal maximumScale() const
    {
        return m_maxScale;
    }
    void setMaximumScale( qreal s )
    {
        if ( s == m_maxScale )
        {
            return;
        }

        m_maxScale = s;
        emit maximumScaleChanged();
    }

    qreal minimumRotation() const
    {
        return m_minRotation;
    }
    void setMinimumRotation( qreal r )
    {
        if ( r == m_minRotation )
        {
            return;
        }

        m_minRotation = r;
        emit minimumRotationChanged();
    }
    qreal maximumRotation() const
    {
        return m_maxRotation;
    }
    void setMaximumRotation( qreal r )
    {
        if ( r == m_maxRotation )
        {
            return;
        }

        m_maxRotation = r;
        emit maximumRotationChanged();
    }

    enum Axis { NoDrag = 0x00, XAxis = 0x01, YAxis = 0x02, XandYAxis = 0x03 };
    Axis axis() const
    {
        return m_axis;
    }
    void setAxis( Axis a )
    {
        if ( a == m_axis )
        {
            return;
        }

        m_axis = a;
        emit dragAxisChanged();
    }

    qreal xmin() const
    {
        return m_xmin;
    }
    void setXmin( qreal x )
    {
        if ( x == m_xmin )
        {
            return;
        }

        m_xmin = x;
        emit minimumXChanged();
    }
    qreal xmax() const
    {
        return m_xmax;
    }
    void setXmax( qreal x )
    {
        if ( x == m_xmax )
        {
            return;
        }

        m_xmax = x;
        emit maximumXChanged();
    }
    qreal ymin() const
    {
        return m_ymin;
    }
    void setYmin( qreal y )
    {
        if ( y == m_ymin )
        {
            return;
        }

        m_ymin = y;
        emit minimumYChanged();
    }
    qreal ymax() const
    {
        return m_ymax;
    }
    void setYmax( qreal y )
    {
        if ( y == m_ymax )
        {
            return;
        }

        m_ymax = y;
        emit maximumYChanged();
    }

    bool active() const
    {
        return m_active;
    }
    void setActive( bool a )
    {
        if ( a == m_active )
        {
            return;
        }

        m_active = a;
        emit activeChanged();
    }

public:
    DECL_LSCS_SIGNAL_1( Public, void targetChanged() )
    DECL_LSCS_SIGNAL_2( targetChanged )
    DECL_LSCS_SIGNAL_1( Public, void minimumScaleChanged() )
    DECL_LSCS_SIGNAL_2( minimumScaleChanged )
    DECL_LSCS_SIGNAL_1( Public, void maximumScaleChanged() )
    DECL_LSCS_SIGNAL_2( maximumScaleChanged )
    DECL_LSCS_SIGNAL_1( Public, void minimumRotationChanged() )
    DECL_LSCS_SIGNAL_2( minimumRotationChanged )
    DECL_LSCS_SIGNAL_1( Public, void maximumRotationChanged() )
    DECL_LSCS_SIGNAL_2( maximumRotationChanged )
    DECL_LSCS_SIGNAL_1( Public, void dragAxisChanged() )
    DECL_LSCS_SIGNAL_2( dragAxisChanged )
    DECL_LSCS_SIGNAL_1( Public, void minimumXChanged() )
    DECL_LSCS_SIGNAL_2( minimumXChanged )
    DECL_LSCS_SIGNAL_1( Public, void maximumXChanged() )
    DECL_LSCS_SIGNAL_2( maximumXChanged )
    DECL_LSCS_SIGNAL_1( Public, void minimumYChanged() )
    DECL_LSCS_SIGNAL_2( minimumYChanged )
    DECL_LSCS_SIGNAL_1( Public, void maximumYChanged() )
    DECL_LSCS_SIGNAL_2( maximumYChanged )
    DECL_LSCS_SIGNAL_1( Public, void activeChanged() )
    DECL_LSCS_SIGNAL_2( activeChanged )

private:
    QGraphicsObject *m_target;
    qreal m_minScale;
    qreal m_maxScale;
    qreal m_minRotation;
    qreal m_maxRotation;
    Axis m_axis;
    qreal m_xmin;
    qreal m_xmax;
    qreal m_ymin;
    qreal m_ymax;
    bool m_active;
};

class QDeclarativePinchEvent : public QObject
{
    DECL_LSCS_OBJECT( QDeclarativePinchEvent )

    DECL_LSCS_PROPERTY_READ( center, center )
    DECL_LSCS_PROPERTY_READ( startCenter, startCenter )
    DECL_LSCS_PROPERTY_READ( previousCenter, previousCenter )
    DECL_LSCS_PROPERTY_READ( scale, scale )
    DECL_LSCS_PROPERTY_READ( previousScale, previousScale )
    DECL_LSCS_PROPERTY_READ( angle, angle )
    DECL_LSCS_PROPERTY_READ( previousAngle, previousAngle )
    DECL_LSCS_PROPERTY_READ( rotation, rotation )
    DECL_LSCS_PROPERTY_READ( point1, point1 )
    DECL_LSCS_PROPERTY_READ( startPoint1, startPoint1 )
    DECL_LSCS_PROPERTY_READ( point2, point2 )
    DECL_LSCS_PROPERTY_READ( startPoint2, startPoint2 )
    DECL_LSCS_PROPERTY_READ( pointCount, pointCount )
    DECL_LSCS_PROPERTY_READ( accepted, accepted )
    DECL_LSCS_PROPERTY_WRITE( accepted, setAccepted )

public:
    QDeclarativePinchEvent( QPointF c, qreal s, qreal a, qreal r )
        : QObject(), m_center( c ), m_scale( s ), m_angle( a ), m_rotation( r )
        , m_pointCount( 0 ), m_accepted( true ) {}

    QPointF center() const
    {
        return m_center;
    }
    QPointF startCenter() const
    {
        return m_startCenter;
    }
    void setStartCenter( QPointF c )
    {
        m_startCenter = c;
    }
    QPointF previousCenter() const
    {
        return m_lastCenter;
    }
    void setPreviousCenter( QPointF c )
    {
        m_lastCenter = c;
    }
    qreal scale() const
    {
        return m_scale;
    }
    qreal previousScale() const
    {
        return m_lastScale;
    }
    void setPreviousScale( qreal s )
    {
        m_lastScale = s;
    }
    qreal angle() const
    {
        return m_angle;
    }
    qreal previousAngle() const
    {
        return m_lastAngle;
    }
    void setPreviousAngle( qreal a )
    {
        m_lastAngle = a;
    }
    qreal rotation() const
    {
        return m_rotation;
    }
    QPointF point1() const
    {
        return m_point1;
    }
    void setPoint1( QPointF p )
    {
        m_point1 = p;
    }
    QPointF startPoint1() const
    {
        return m_startPoint1;
    }
    void setStartPoint1( QPointF p )
    {
        m_startPoint1 = p;
    }
    QPointF point2() const
    {
        return m_point2;
    }
    void setPoint2( QPointF p )
    {
        m_point2 = p;
    }
    QPointF startPoint2() const
    {
        return m_startPoint2;
    }
    void setStartPoint2( QPointF p )
    {
        m_startPoint2 = p;
    }
    int pointCount() const
    {
        return m_pointCount;
    }
    void setPointCount( int count )
    {
        m_pointCount = count;
    }

    bool accepted() const
    {
        return m_accepted;
    }
    void setAccepted( bool a )
    {
        m_accepted = a;
    }

private:
    QPointF m_center;
    QPointF m_startCenter;
    QPointF m_lastCenter;
    qreal m_scale;
    qreal m_lastScale;
    qreal m_angle;
    qreal m_lastAngle;
    qreal m_rotation;
    QPointF m_point1;
    QPointF m_point2;
    QPointF m_startPoint1;
    QPointF m_startPoint2;
    int m_pointCount;
    bool m_accepted;
};


class QDeclarativeMouseEvent;
class QDeclarativePinchAreaPrivate;
class QDeclarativePinchArea : public QDeclarativeItem
{
    DECL_LSCS_OBJECT( QDeclarativePinchArea )

    DECL_LSCS_PROPERTY_READ( enabled, isEnabled )
    DECL_LSCS_PROPERTY_WRITE( enabled, setEnabled )
    DECL_LSCS_PROPERTY_NOTIFY( enabled, enabledChanged )
    DECL_LSCS_PROPERTY_READ( *pinch, pinch )
    DECL_LSCS_PROPERTY_CONSTANT( *pinch )

public:
    QDeclarativePinchArea( QDeclarativeItem *parent = 0 );
    ~QDeclarativePinchArea();

    bool isEnabled() const;
    void setEnabled( bool );

    QDeclarativePinch *pinch();

    DECL_LSCS_SIGNAL_1( Public, void enabledChanged() )
    DECL_LSCS_SIGNAL_2( enabledChanged )
    DECL_LSCS_SIGNAL_1( Public, void pinchStarted( QDeclarativePinchEvent *pinch ) )
    DECL_LSCS_SIGNAL_2( pinchStarted, pinch )
    DECL_LSCS_SIGNAL_1( Public, void pinchUpdated( QDeclarativePinchEvent *pinch ) )
    DECL_LSCS_SIGNAL_2( pinchUpdated, pinch )
    DECL_LSCS_SIGNAL_1( Public, void pinchFinished( QDeclarativePinchEvent *pinch ) )
    DECL_LSCS_SIGNAL_2( pinchFinished, pinch )

protected:
    void mousePressEvent( QGraphicsSceneMouseEvent *event );
    void mouseReleaseEvent( QGraphicsSceneMouseEvent *event );
    void mouseMoveEvent( QGraphicsSceneMouseEvent *event );
    bool sceneEvent( QEvent * );
    bool sendMouseEvent( QGraphicsSceneMouseEvent *event );
    bool sceneEventFilter( QGraphicsItem *i, QEvent *e );
    bool event( QEvent * );

    virtual void geometryChanged( const QRectF &newGeometry,
                                  const QRectF &oldGeometry );
    virtual QVariant itemChange( GraphicsItemChange change, const QVariant &value );

private:
    void updatePinch();
    void handlePress();
    void handleRelease();

    Q_DISABLE_COPY( QDeclarativePinchArea )
    Q_DECLARE_PRIVATE_D( QGraphicsItem::d_ptr.data(), QDeclarativePinchArea )
};

LSCS_END_NAMESPACE

QML_DECLARE_TYPE( QDeclarativePinch )
QML_DECLARE_TYPE( QDeclarativePinchEvent )
QML_DECLARE_TYPE( QDeclarativePinchArea )

#endif // QDECLARATIVEPINCHAREA_H
