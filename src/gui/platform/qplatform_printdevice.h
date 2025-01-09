/***********************************************************************
*
* Copyright (c) 2024 Roland Hughes d.b.a Logikal Solutions
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

#ifndef QPLATFORMPRINTDEVICE_H
#define QPLATFORMPRINTDEVICE_H

#include <qvector.h>
#include <qpagelayout.h>
#include <qprinter.h>

#ifndef LSCS_NO_PRINTER

class BdPrintDestination
{
public:
    QByteArray name;
    QByteArray instance;
    QByteArray uri;
};

class Q_GUI_EXPORT QPlatformPrintDevice
{
public:
    QPlatformPrintDevice();
    explicit QPlatformPrintDevice( const BdPrintDestination &id );
    explicit QPlatformPrintDevice( const QString &name );

    QPlatformPrintDevice( const QPlatformPrintDevice & ) = delete;
    QPlatformPrintDevice &operator=( const QPlatformPrintDevice & ) = delete;

    virtual ~QPlatformPrintDevice();

    virtual QString name();
    virtual QString location();
    virtual QString makeAndModel();
    virtual QString uri();
    virtual QString instance();

    virtual bool isValid();
    virtual bool isDefault();
    virtual bool isRemote();
    virtual bool supportsMultipleCopies();
    virtual bool supportsCollateCopies();
    virtual bool supportsCustomPageSizes();
    virtual bool isValidPageLayout( const QPageLayout &layout, int resolution );

    virtual PrinterState state();

    virtual QPageSize defaultPageSize();
    virtual QList<QPageSize> supportedPageSizes();

    virtual QPageSize supportedPageSize( const QPageSize &pageSize );
    virtual QPageSize supportedPageSize( QPageSize::PageSizeId pageSizeId );
    virtual QPageSize supportedPageSize( const QString &pageName );
    virtual QPageSize supportedPageSize( const QSize &pointSize );
    virtual QPageSize supportedPageSize( const QSizeF &size, QPageSize::Unit units );

    virtual QSize minimumPhysicalPageSize();
    virtual QSize maximumPhysicalPageSize();

    virtual QMarginsF printableMargins( const QPageSize &pageSize, QPageLayout::Orientation orientation,
                                        int resolution );

    virtual int defaultResolution();
    virtual QList<int> supportedResolutions();

    virtual QString defaultPrintQuality();
    virtual QStringList supportedPrintQualities();

    virtual QString defaultMediaSource();
    virtual QStringList supportedMediaSources();

    virtual QString defaultOutputBin();
    virtual QStringList supportedOutputBins();

    virtual QString defaultDuplexMode();
    virtual QStringList supportedDuplexModes();

    virtual QString defaultColorMode();
    virtual QStringList supportedColorModes();

    static QPageSize createPageSize( const QString &key, const QSize &size, const QString &localizedName );
    static QPageSize createPageSize( int windowsId, const QSize &size, const QString &localizedName );

    virtual QString lastPrintError();

protected:

    QPageSize supportedPageSizeMatch( const QPageSize &pageSize );

    QByteArray m_name;
    QByteArray m_instance;
    QByteArray m_location;
    QByteArray m_makeAndModel;
    QByteArray m_uri;



};

#endif // LSCS_NO_PRINTER

#endif
