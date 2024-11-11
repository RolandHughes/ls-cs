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

#ifndef QDECLARATIVELAYOUTITEM_P_H
#define QDECLARATIVELAYOUTITEM_P_H

#include <qdeclarativeitem.h>
#include <QGraphicsLayoutItem>
#include <QSizeF>

LSCS_BEGIN_NAMESPACE

class QDeclarativeLayoutItem : public QDeclarativeItem, public QGraphicsLayoutItem
{
    DECL_LSCS_OBJECT( QDeclarativeLayoutItem )

    LSCS_INTERFACES( QGraphicsLayoutItem )
    DECL_LSCS_PROPERTY_READ( maximumSize, maximumSize )
    DECL_LSCS_PROPERTY_WRITE( maximumSize, setMaximumSize )
    DECL_LSCS_PROPERTY_NOTIFY( maximumSize, maximumSizeChanged )
    DECL_LSCS_PROPERTY_READ( minimumSize, minimumSize )
    DECL_LSCS_PROPERTY_WRITE( minimumSize, setMinimumSize )
    DECL_LSCS_PROPERTY_NOTIFY( minimumSize, minimumSizeChanged )
    DECL_LSCS_PROPERTY_READ( preferredSize, preferredSize )
    DECL_LSCS_PROPERTY_WRITE( preferredSize, setPreferredSize )
    DECL_LSCS_PROPERTY_NOTIFY( preferredSize, preferredSizeChanged )

public:
    QDeclarativeLayoutItem( QDeclarativeItem *parent = 0 );

    QSizeF maximumSize() const
    {
        return m_maximumSize;
    }
    void setMaximumSize( const QSizeF &s )
    {
        if ( s == m_maximumSize )
        {
            return;
        }

        m_maximumSize = s;
        emit maximumSizeChanged();
    }

    QSizeF minimumSize() const
    {
        return m_minimumSize;
    }
    void setMinimumSize( const QSizeF &s )
    {
        if ( s == m_minimumSize )
        {
            return;
        }

        m_minimumSize = s;
        emit minimumSizeChanged();
    }

    QSizeF preferredSize() const
    {
        return m_preferredSize;
    }
    void setPreferredSize( const QSizeF &s )
    {
        if ( s == m_preferredSize )
        {
            return;
        }

        m_preferredSize = s;
        emit preferredSizeChanged();
    }

    virtual void setGeometry( const QRectF &rect );

    DECL_LSCS_SIGNAL_1( Public, void maximumSizeChanged() )
    DECL_LSCS_SIGNAL_2( maximumSizeChanged )
    DECL_LSCS_SIGNAL_1( Public, void minimumSizeChanged() )
    DECL_LSCS_SIGNAL_2( minimumSizeChanged )
    DECL_LSCS_SIGNAL_1( Public, void preferredSizeChanged() )
    DECL_LSCS_SIGNAL_2( preferredSizeChanged )

protected:
    virtual QSizeF sizeHint( Qt::SizeHint which, const QSizeF &constraint = QSizeF() ) const;

private:
    QSizeF m_maximumSize;
    QSizeF m_minimumSize;
    QSizeF m_preferredSize;
};

LSCS_END_NAMESPACE

QML_DECLARE_TYPE( QDeclarativeLayoutItem )

#endif
