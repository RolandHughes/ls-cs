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

#ifndef QGESTURE_H
#define QGESTURE_H

#include <qobject.h>
#include <qdatetime.h>
#include <qevent.h>
#include <qlist.h>
#include <qpoint.h>
#include <qrect.h>

#ifndef LSCS_NO_GESTURES

class QGesturePrivate;
class QPanGesturePrivate;
class QPinchGesturePrivate;
class QTapAndHoldGesturePrivate;
class QSwipeGesturePrivate;
class QTapGesturePrivate;
class QGestureEventPrivate;

class Q_GUI_EXPORT QGesture : public QObject
{
    GUI_LSCS_OBJECT( QGesture )
    Q_DECLARE_PRIVATE( QGesture )

    GUI_LSCS_PROPERTY_READ( state, state )
    GUI_LSCS_PROPERTY_READ( gestureType, gestureType )
    GUI_LSCS_PROPERTY_READ( gestureCancelPolicy, gestureCancelPolicy )
    GUI_LSCS_PROPERTY_WRITE( gestureCancelPolicy, setGestureCancelPolicy )
    GUI_LSCS_PROPERTY_READ( hotSpot, hotSpot )
    GUI_LSCS_PROPERTY_WRITE( hotSpot, setHotSpot )
    GUI_LSCS_PROPERTY_RESET( hotSpot, unsetHotSpot )
    GUI_LSCS_PROPERTY_READ( hasHotSpot, hasHotSpot )

public:
    explicit QGesture( QObject *parent = nullptr );
    ~QGesture();

    Qt::GestureType gestureType() const;

    Qt::GestureState state() const;

    QPointF hotSpot() const;
    void setHotSpot( const QPointF &value );
    bool hasHotSpot() const;
    void unsetHotSpot();

    enum GestureCancelPolicy
    {
        CancelNone = 0,
        CancelAllInContext
    };

    void setGestureCancelPolicy( GestureCancelPolicy policy );
    GestureCancelPolicy gestureCancelPolicy() const;

protected:
    QGesture( QGesturePrivate &dd, QObject *parent );
    QScopedPointer<QGesturePrivate> d_ptr;

private:
    friend class QGestureEvent;
    friend class QGestureRecognizer;
    friend class QGestureManager;
    friend class QGraphicsScenePrivate;
};

class Q_GUI_EXPORT QPanGesture : public QGesture
{
    GUI_LSCS_OBJECT( QPanGesture )
    Q_DECLARE_PRIVATE( QPanGesture )

    GUI_LSCS_PROPERTY_READ( lastOffset, lastOffset )
    GUI_LSCS_PROPERTY_WRITE( lastOffset, setLastOffset )
    GUI_LSCS_PROPERTY_READ( offset, offset )
    GUI_LSCS_PROPERTY_WRITE( offset, setOffset )
    GUI_LSCS_PROPERTY_READ( delta, delta )
    GUI_LSCS_PROPERTY_STORED( delta, false )
    GUI_LSCS_PROPERTY_READ( acceleration, acceleration )
    GUI_LSCS_PROPERTY_WRITE( acceleration, setAcceleration )

    // private properties
    GUI_LSCS_PROPERTY_READ( horizontalVelocity, lscs_horizontalVelocity )
    GUI_LSCS_PROPERTY_WRITE( horizontalVelocity, lscs_setHorizontalVelocity )

    // private properties
    GUI_LSCS_PROPERTY_READ( verticalVelocity, lscs_verticalVelocity )
    GUI_LSCS_PROPERTY_WRITE( verticalVelocity, lscs_setVerticalVelocity )

public:
    explicit QPanGesture( QObject *parent = nullptr );
    ~QPanGesture();

    QPointF lastOffset() const;
    QPointF offset() const;
    QPointF delta() const;
    qreal acceleration() const;

    void setLastOffset( const QPointF &value );
    void setOffset( const QPointF &value );
    void setAcceleration( qreal value );

    friend class QPanGestureRecognizer;
    friend class QWinNativePanGestureRecognizer;

private:
    // wrapper for overloaded method
    qreal lscs_horizontalVelocity() const;

    // wrapper for overloaded method
    void lscs_setHorizontalVelocity( qreal velocity );

    // wrapper for overloaded method
    qreal lscs_verticalVelocity() const;

    // wrapper for overloaded method
    void lscs_setVerticalVelocity( qreal velocity );
};

class Q_GUI_EXPORT QPinchGesture : public QGesture
{
    GUI_LSCS_OBJECT( QPinchGesture )
    Q_DECLARE_PRIVATE( QPinchGesture )

    GUI_LSCS_FLAG( ChangeFlags, ChangeFlag )

public:
    enum ChangeFlag
    {
        ScaleFactorChanged   = 0x1,
        RotationAngleChanged = 0x2,
        CenterPointChanged   = 0x4
    };
    using ChangeFlags = QFlags<ChangeFlag>;

    GUI_LSCS_PROPERTY_READ( totalChangeFlags, totalChangeFlags )
    GUI_LSCS_PROPERTY_WRITE( totalChangeFlags, setTotalChangeFlags )
    GUI_LSCS_PROPERTY_READ( changeFlags, changeFlags )
    GUI_LSCS_PROPERTY_WRITE( changeFlags, setChangeFlags )

    GUI_LSCS_PROPERTY_READ( totalScaleFactor, totalScaleFactor )
    GUI_LSCS_PROPERTY_WRITE( totalScaleFactor, setTotalScaleFactor )
    GUI_LSCS_PROPERTY_READ( lastScaleFactor, lastScaleFactor )
    GUI_LSCS_PROPERTY_WRITE( lastScaleFactor, setLastScaleFactor )
    GUI_LSCS_PROPERTY_READ( scaleFactor, scaleFactor )
    GUI_LSCS_PROPERTY_WRITE( scaleFactor, setScaleFactor )

    GUI_LSCS_PROPERTY_READ( totalRotationAngle, totalRotationAngle )
    GUI_LSCS_PROPERTY_WRITE( totalRotationAngle, setTotalRotationAngle )
    GUI_LSCS_PROPERTY_READ( lastRotationAngle, lastRotationAngle )
    GUI_LSCS_PROPERTY_WRITE( lastRotationAngle, setLastRotationAngle )
    GUI_LSCS_PROPERTY_READ( rotationAngle, rotationAngle )
    GUI_LSCS_PROPERTY_WRITE( rotationAngle, setRotationAngle )

    GUI_LSCS_PROPERTY_READ( startCenterPoint, startCenterPoint )
    GUI_LSCS_PROPERTY_WRITE( startCenterPoint, setStartCenterPoint )
    GUI_LSCS_PROPERTY_READ( lastCenterPoint, lastCenterPoint )
    GUI_LSCS_PROPERTY_WRITE( lastCenterPoint, setLastCenterPoint )
    GUI_LSCS_PROPERTY_READ( centerPoint, centerPoint )
    GUI_LSCS_PROPERTY_WRITE( centerPoint, setCenterPoint )

    explicit QPinchGesture( QObject *parent = nullptr );
    ~QPinchGesture();

    ChangeFlags totalChangeFlags() const;
    void setTotalChangeFlags( ChangeFlags value );

    ChangeFlags changeFlags() const;
    void setChangeFlags( ChangeFlags value );

    QPointF startCenterPoint() const;
    QPointF lastCenterPoint() const;
    QPointF centerPoint() const;
    void setStartCenterPoint( const QPointF &value );
    void setLastCenterPoint( const QPointF &value );
    void setCenterPoint( const QPointF &value );

    qreal totalScaleFactor() const;
    qreal lastScaleFactor() const;
    qreal scaleFactor() const;
    void setTotalScaleFactor( qreal value );
    void setLastScaleFactor( qreal value );
    void setScaleFactor( qreal value );

    qreal totalRotationAngle() const;
    qreal lastRotationAngle() const;
    qreal rotationAngle() const;
    void setTotalRotationAngle( qreal value );
    void setLastRotationAngle( qreal value );
    void setRotationAngle( qreal value );

    friend class QPinchGestureRecognizer;
};

Q_DECLARE_OPERATORS_FOR_FLAGS( QPinchGesture::ChangeFlags )

class Q_GUI_EXPORT QSwipeGesture : public QGesture
{
    GUI_LSCS_OBJECT( QSwipeGesture )
    Q_DECLARE_PRIVATE( QSwipeGesture )

    GUI_LSCS_ENUM( SwipeDirection )

    GUI_LSCS_PROPERTY_READ( horizontalDirection, horizontalDirection )
    GUI_LSCS_PROPERTY_STORED( horizontalDirection, false )
    GUI_LSCS_PROPERTY_READ( verticalDirection, verticalDirection )
    GUI_LSCS_PROPERTY_STORED( verticalDirection, false )
    GUI_LSCS_PROPERTY_READ( swipeAngle, swipeAngle )
    GUI_LSCS_PROPERTY_WRITE( swipeAngle, setSwipeAngle )

    // private properties
    GUI_LSCS_PROPERTY_READ( velocity, lscs_velocity )
    GUI_LSCS_PROPERTY_WRITE( velocity, lscs_setVelocity )

public:
    enum SwipeDirection
    {
        NoDirection,
        Left,
        Right,
        Up,
        Down
    };

    explicit QSwipeGesture( QObject *parent = nullptr );
    ~QSwipeGesture();

    SwipeDirection horizontalDirection() const;
    SwipeDirection verticalDirection() const;

    qreal swipeAngle() const;
    void setSwipeAngle( qreal value );

    friend class QSwipeGestureRecognizer;

private:
    // wrapper for overloaded method
    qreal lscs_velocity() const;

    // wrapper for overloaded method
    void lscs_setVelocity( qreal velocity );
};

class Q_GUI_EXPORT QTapGesture : public QGesture
{
    GUI_LSCS_OBJECT( QTapGesture )
    Q_DECLARE_PRIVATE( QTapGesture )

    GUI_LSCS_PROPERTY_READ( position, position )
    GUI_LSCS_PROPERTY_WRITE( position, setPosition )

public:
    explicit QTapGesture( QObject *parent = nullptr );
    ~QTapGesture();

    QPointF position() const;
    void setPosition( const QPointF &pos );

    friend class QTapGestureRecognizer;
};

class Q_GUI_EXPORT QTapAndHoldGesture : public QGesture
{
    GUI_LSCS_OBJECT( QTapAndHoldGesture )
    Q_DECLARE_PRIVATE( QTapAndHoldGesture )

    GUI_LSCS_PROPERTY_READ( position, position )
    GUI_LSCS_PROPERTY_WRITE( position, setPosition )

public:
    explicit QTapAndHoldGesture( QObject *parent = nullptr );
    ~QTapAndHoldGesture();

    QPointF position() const;
    void setPosition( const QPointF &pos );

    static void setTimeout( int msecs );
    static int timeout();

    friend class QTapAndHoldGestureRecognizer;
};

class Q_GUI_EXPORT QGestureEvent : public QEvent
{
public:
    explicit QGestureEvent( const QList<QGesture *> &gestures );
    ~QGestureEvent();

    QList<QGesture *> gestures() const;
    QGesture *gesture( Qt::GestureType gestureType ) const;

    QList<QGesture *> activeGestures() const;
    QList<QGesture *> canceledGestures() const;

    using QEvent::setAccepted;
    using QEvent::isAccepted;
    using QEvent::accept;
    using QEvent::ignore;

    void setAccepted( QGesture *gesture, bool isAccepted );
    void accept( QGesture *gesture );
    void ignore( QGesture *gesture );
    bool isAccepted( QGesture *gesture ) const;

    void setAccepted( Qt::GestureType gestureType, bool isAccepted );
    void accept( Qt::GestureType gestureType );
    void ignore( Qt::GestureType gestureType );
    bool isAccepted( Qt::GestureType gestureType ) const;

    void setWidget( QWidget *widget );
    QWidget *widget() const;

#ifndef LSCS_NO_GRAPHICSVIEW
    QPointF mapToGraphicsScene( const QPointF &gesturePoint ) const;
#endif

private:
    QList<QGesture *> m_gestures;
    QWidget *m_widget;
    QMap<Qt::GestureType, bool> m_accepted;
    QMap<Qt::GestureType, QWidget *> m_targetWidgets;

    friend class QApplication;
    friend class QGestureManager;
};

Q_GUI_EXPORT QDebug operator<<( QDebug, const QGesture * );
Q_GUI_EXPORT QDebug operator<<( QDebug, const QGestureEvent *event );

#endif // LSCS_NO_GESTURES

#endif
