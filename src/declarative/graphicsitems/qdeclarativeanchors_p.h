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

#ifndef QDECLARATIVEANCHORS_P_H
#define QDECLARATIVEANCHORS_P_H

#include <qdeclarativeitem.h>
#include <qdeclarative.h>
#include <QtCore/QObject>
#include <qdeclarativeglobal_p.h>

LSCS_BEGIN_NAMESPACE

class QDeclarativeAnchorsPrivate;
class QDeclarativeAnchorLine;

class Q_DECLARATIVE_PRIVATE_EXPORT QDeclarativeAnchors : public QObject
{
    DECL_LSCS_OBJECT( QDeclarativeAnchors )

    DECL_LSCS_PROPERTY_READ( left, left )
    DECL_LSCS_PROPERTY_WRITE( left, setLeft )
    DECL_LSCS_PROPERTY_RESET( left, resetLeft )
    DECL_LSCS_PROPERTY_NOTIFY( left, leftChanged )
    DECL_LSCS_PROPERTY_READ( right, right )
    DECL_LSCS_PROPERTY_WRITE( right, setRight )
    DECL_LSCS_PROPERTY_RESET( right, resetRight )
    DECL_LSCS_PROPERTY_NOTIFY( right, rightChanged )
    DECL_LSCS_PROPERTY_READ( horizontalCenter, horizontalCenter )
    DECL_LSCS_PROPERTY_WRITE( horizontalCenter, setHorizontalCenter )
    DECL_LSCS_PROPERTY_RESET( horizontalCenter, resetHorizontalCenter )
    DECL_LSCS_PROPERTY_NOTIFY( horizontalCenter, horizontalCenterChanged )
    DECL_LSCS_PROPERTY_READ( top, top )
    DECL_LSCS_PROPERTY_WRITE( top, setTop )
    DECL_LSCS_PROPERTY_RESET( top, resetTop )
    DECL_LSCS_PROPERTY_NOTIFY( top, topChanged )
    DECL_LSCS_PROPERTY_READ( bottom, bottom )
    DECL_LSCS_PROPERTY_WRITE( bottom, setBottom )
    DECL_LSCS_PROPERTY_RESET( bottom, resetBottom )
    DECL_LSCS_PROPERTY_NOTIFY( bottom, bottomChanged )
    DECL_LSCS_PROPERTY_READ( verticalCenter, verticalCenter )
    DECL_LSCS_PROPERTY_WRITE( verticalCenter, setVerticalCenter )
    DECL_LSCS_PROPERTY_RESET( verticalCenter, resetVerticalCenter )
    DECL_LSCS_PROPERTY_NOTIFY( verticalCenter, verticalCenterChanged )
    DECL_LSCS_PROPERTY_READ( baseline, baseline )
    DECL_LSCS_PROPERTY_WRITE( baseline, setBaseline )
    DECL_LSCS_PROPERTY_RESET( baseline, resetBaseline )
    DECL_LSCS_PROPERTY_NOTIFY( baseline, baselineChanged )
    DECL_LSCS_PROPERTY_READ( margins, margins )
    DECL_LSCS_PROPERTY_WRITE( margins, setMargins )
    DECL_LSCS_PROPERTY_NOTIFY( margins, marginsChanged )
    DECL_LSCS_PROPERTY_READ( leftMargin, leftMargin )
    DECL_LSCS_PROPERTY_WRITE( leftMargin, setLeftMargin )
    DECL_LSCS_PROPERTY_NOTIFY( leftMargin, leftMarginChanged )
    DECL_LSCS_PROPERTY_READ( rightMargin, rightMargin )
    DECL_LSCS_PROPERTY_WRITE( rightMargin, setRightMargin )
    DECL_LSCS_PROPERTY_NOTIFY( rightMargin, rightMarginChanged )
    DECL_LSCS_PROPERTY_READ( horizontalCenterOffset, horizontalCenterOffset )
    DECL_LSCS_PROPERTY_WRITE( horizontalCenterOffset, setHorizontalCenterOffset )
    DECL_LSCS_PROPERTY_NOTIFY( horizontalCenterOffset, horizontalCenterOffsetChanged )
    DECL_LSCS_PROPERTY_READ( topMargin, topMargin )
    DECL_LSCS_PROPERTY_WRITE( topMargin, setTopMargin )
    DECL_LSCS_PROPERTY_NOTIFY( topMargin, topMarginChanged )
    DECL_LSCS_PROPERTY_READ( bottomMargin, bottomMargin )
    DECL_LSCS_PROPERTY_WRITE( bottomMargin, setBottomMargin )
    DECL_LSCS_PROPERTY_NOTIFY( bottomMargin, bottomMarginChanged )
    DECL_LSCS_PROPERTY_READ( verticalCenterOffset, verticalCenterOffset )
    DECL_LSCS_PROPERTY_WRITE( verticalCenterOffset, setVerticalCenterOffset )
    DECL_LSCS_PROPERTY_NOTIFY( verticalCenterOffset, verticalCenterOffsetChanged )
    DECL_LSCS_PROPERTY_READ( baselineOffset, baselineOffset )
    DECL_LSCS_PROPERTY_WRITE( baselineOffset, setBaselineOffset )
    DECL_LSCS_PROPERTY_NOTIFY( baselineOffset, baselineOffsetChanged )
    DECL_LSCS_PROPERTY_READ( *fill, fill )
    DECL_LSCS_PROPERTY_WRITE( *fill, setFill )
    DECL_LSCS_PROPERTY_RESET( *fill, resetFill )
    DECL_LSCS_PROPERTY_NOTIFY( *fill, fillChanged )
    DECL_LSCS_PROPERTY_READ( *centerIn, centerIn )
    DECL_LSCS_PROPERTY_WRITE( *centerIn, setCenterIn )
    DECL_LSCS_PROPERTY_RESET( *centerIn, resetCenterIn )
    DECL_LSCS_PROPERTY_NOTIFY( *centerIn, centerInChanged )

public:
    QDeclarativeAnchors( QObject *parent = nullptr );
    QDeclarativeAnchors( QGraphicsObject *item, QObject *parent = nullptr );
    virtual ~QDeclarativeAnchors();

    enum Anchor
    {
        LeftAnchor = 0x01,
        RightAnchor = 0x02,
        TopAnchor = 0x04,
        BottomAnchor = 0x08,
        HCenterAnchor = 0x10,
        VCenterAnchor = 0x20,
        BaselineAnchor = 0x40,
        Horizontal_Mask = LeftAnchor | RightAnchor | HCenterAnchor,
        Vertical_Mask = TopAnchor | BottomAnchor | VCenterAnchor | BaselineAnchor
    };
    using Anchors = QFlags<Anchor>;

    QDeclarativeAnchorLine left() const;
    void setLeft( const QDeclarativeAnchorLine &edge );
    void resetLeft();

    QDeclarativeAnchorLine right() const;
    void setRight( const QDeclarativeAnchorLine &edge );
    void resetRight();

    QDeclarativeAnchorLine horizontalCenter() const;
    void setHorizontalCenter( const QDeclarativeAnchorLine &edge );
    void resetHorizontalCenter();

    QDeclarativeAnchorLine top() const;
    void setTop( const QDeclarativeAnchorLine &edge );
    void resetTop();

    QDeclarativeAnchorLine bottom() const;
    void setBottom( const QDeclarativeAnchorLine &edge );
    void resetBottom();

    QDeclarativeAnchorLine verticalCenter() const;
    void setVerticalCenter( const QDeclarativeAnchorLine &edge );
    void resetVerticalCenter();

    QDeclarativeAnchorLine baseline() const;
    void setBaseline( const QDeclarativeAnchorLine &edge );
    void resetBaseline();

    qreal leftMargin() const;
    void setLeftMargin( qreal );

    qreal rightMargin() const;
    void setRightMargin( qreal );

    qreal horizontalCenterOffset() const;
    void setHorizontalCenterOffset( qreal );

    qreal topMargin() const;
    void setTopMargin( qreal );

    qreal bottomMargin() const;
    void setBottomMargin( qreal );

    qreal margins() const;
    void setMargins( qreal );

    qreal verticalCenterOffset() const;
    void setVerticalCenterOffset( qreal );

    qreal baselineOffset() const;
    void setBaselineOffset( qreal );

    QGraphicsObject *fill() const;
    void setFill( QGraphicsObject * );
    void resetFill();

    QGraphicsObject *centerIn() const;
    void setCenterIn( QGraphicsObject * );
    void resetCenterIn();

    Anchors usedAnchors() const;

    void classBegin();
    void componentComplete();

    bool mirrored();

public:
    DECL_LSCS_SIGNAL_1( Public, void leftChanged() )
    DECL_LSCS_SIGNAL_2( leftChanged )
    DECL_LSCS_SIGNAL_1( Public, void rightChanged() )
    DECL_LSCS_SIGNAL_2( rightChanged )
    DECL_LSCS_SIGNAL_1( Public, void topChanged() )
    DECL_LSCS_SIGNAL_2( topChanged )
    DECL_LSCS_SIGNAL_1( Public, void bottomChanged() )
    DECL_LSCS_SIGNAL_2( bottomChanged )
    DECL_LSCS_SIGNAL_1( Public, void verticalCenterChanged() )
    DECL_LSCS_SIGNAL_2( verticalCenterChanged )
    DECL_LSCS_SIGNAL_1( Public, void horizontalCenterChanged() )
    DECL_LSCS_SIGNAL_2( horizontalCenterChanged )
    DECL_LSCS_SIGNAL_1( Public, void baselineChanged() )
    DECL_LSCS_SIGNAL_2( baselineChanged )
    DECL_LSCS_SIGNAL_1( Public, void fillChanged() )
    DECL_LSCS_SIGNAL_2( fillChanged )
    DECL_LSCS_SIGNAL_1( Public, void centerInChanged() )
    DECL_LSCS_SIGNAL_2( centerInChanged )
    DECL_LSCS_SIGNAL_1( Public, void leftMarginChanged() )
    DECL_LSCS_SIGNAL_2( leftMarginChanged )
    DECL_LSCS_SIGNAL_1( Public, void rightMarginChanged() )
    DECL_LSCS_SIGNAL_2( rightMarginChanged )
    DECL_LSCS_SIGNAL_1( Public, void topMarginChanged() )
    DECL_LSCS_SIGNAL_2( topMarginChanged )
    DECL_LSCS_SIGNAL_1( Public, void bottomMarginChanged() )
    DECL_LSCS_SIGNAL_2( bottomMarginChanged )
    DECL_LSCS_SIGNAL_1( Public, void marginsChanged() )
    DECL_LSCS_SIGNAL_2( marginsChanged )
    DECL_LSCS_SIGNAL_1( Public, void verticalCenterOffsetChanged() )
    DECL_LSCS_SIGNAL_2( verticalCenterOffsetChanged )
    DECL_LSCS_SIGNAL_1( Public, void horizontalCenterOffsetChanged() )
    DECL_LSCS_SIGNAL_2( horizontalCenterOffsetChanged )
    DECL_LSCS_SIGNAL_1( Public, void baselineOffsetChanged() )
    DECL_LSCS_SIGNAL_2( baselineOffsetChanged )

private:
    friend class QDeclarativeItem;
    friend class QDeclarativeItemPrivate;
    friend class QDeclarativeGraphicsWidget;
    Q_DISABLE_COPY( QDeclarativeAnchors )
    Q_DECLARE_PRIVATE( QDeclarativeAnchors )

    DECL_LSCS_SLOT_1( Private, void _q_widgetGeometryChanged() )
    DECL_LSCS_SLOT_2( _q_widgetGeometryChanged )

    DECL_LSCS_SLOT_1( Private, void _q_widgetDestroyed( QObject *obj ) )
    DECL_LSCS_SLOT_2( _q_widgetDestroyed )

};
Q_DECLARE_OPERATORS_FOR_FLAGS( QDeclarativeAnchors::Anchors )

LSCS_END_NAMESPACE

QML_DECLARE_TYPE( QDeclarativeAnchors )

#endif
