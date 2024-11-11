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

#ifndef QDECLARATIVESYSTEMPALETTE_P_H
#define QDECLARATIVESYSTEMPALETTE_P_H

#include <qdeclarative.h>
#include <QtCore/qobject.h>
#include <QPalette>

LSCS_BEGIN_NAMESPACE

class QDeclarativeSystemPalettePrivate;

class QDeclarativeSystemPalette : public QObject
{
    DECL_LSCS_OBJECT( QDeclarativeSystemPalette )

    LSCS_ENUM( ColorGroup )
    Q_DECLARE_PRIVATE( QDeclarativeSystemPalette )

    DECL_LSCS_PROPERTY_READ( colorGroup, colorGroup )
    DECL_LSCS_PROPERTY_WRITE( colorGroup, setColorGroup )
    DECL_LSCS_PROPERTY_NOTIFY( colorGroup, paletteChanged )
    DECL_LSCS_PROPERTY_READ( window, window )
    DECL_LSCS_PROPERTY_NOTIFY( window, paletteChanged )
    DECL_LSCS_PROPERTY_READ( windowText, windowText )
    DECL_LSCS_PROPERTY_NOTIFY( windowText, paletteChanged )
    DECL_LSCS_PROPERTY_READ( base, base )
    DECL_LSCS_PROPERTY_NOTIFY( base, paletteChanged )
    DECL_LSCS_PROPERTY_READ( text, text )
    DECL_LSCS_PROPERTY_NOTIFY( text, paletteChanged )
    DECL_LSCS_PROPERTY_READ( alternateBase, alternateBase )
    DECL_LSCS_PROPERTY_NOTIFY( alternateBase, paletteChanged )
    DECL_LSCS_PROPERTY_READ( button, button )
    DECL_LSCS_PROPERTY_NOTIFY( button, paletteChanged )
    DECL_LSCS_PROPERTY_READ( buttonText, buttonText )
    DECL_LSCS_PROPERTY_NOTIFY( buttonText, paletteChanged )
    DECL_LSCS_PROPERTY_READ( light, light )
    DECL_LSCS_PROPERTY_NOTIFY( light, paletteChanged )
    DECL_LSCS_PROPERTY_READ( midlight, midlight )
    DECL_LSCS_PROPERTY_NOTIFY( midlight, paletteChanged )
    DECL_LSCS_PROPERTY_READ( dark, dark )
    DECL_LSCS_PROPERTY_NOTIFY( dark, paletteChanged )
    DECL_LSCS_PROPERTY_READ( mid, mid )
    DECL_LSCS_PROPERTY_NOTIFY( mid, paletteChanged )
    DECL_LSCS_PROPERTY_READ( shadow, shadow )
    DECL_LSCS_PROPERTY_NOTIFY( shadow, paletteChanged )
    DECL_LSCS_PROPERTY_READ( highlight, highlight )
    DECL_LSCS_PROPERTY_NOTIFY( highlight, paletteChanged )
    DECL_LSCS_PROPERTY_READ( highlightedText, highlightedText )
    DECL_LSCS_PROPERTY_NOTIFY( highlightedText, paletteChanged )

public:
    QDeclarativeSystemPalette( QObject *parent = nullptr );
    ~QDeclarativeSystemPalette();

    enum ColorGroup { Active = QPalette::Active, Inactive = QPalette::Inactive, Disabled = QPalette::Disabled };

    QColor window() const;
    QColor windowText() const;

    QColor base() const;
    QColor text() const;
    QColor alternateBase() const;

    QColor button() const;
    QColor buttonText() const;

    QColor light() const;
    QColor midlight() const;
    QColor dark() const;
    QColor mid() const;
    QColor shadow() const;

    QColor highlight() const;
    QColor highlightedText() const;

    QDeclarativeSystemPalette::ColorGroup colorGroup() const;
    void setColorGroup( QDeclarativeSystemPalette::ColorGroup );

    DECL_LSCS_SIGNAL_1( Public, void paletteChanged() )
    DECL_LSCS_SIGNAL_2( paletteChanged )

private:
    bool eventFilter( QObject *watched, QEvent *event );
    bool event( QEvent *event );

};

LSCS_END_NAMESPACE

QML_DECLARE_TYPE( QDeclarativeSystemPalette )


#endif // QDECLARATIVESYSTEMPALETTE_H
