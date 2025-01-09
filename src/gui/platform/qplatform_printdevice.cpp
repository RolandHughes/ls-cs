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

#include "qplatform_printdevice.h"

#include "qprintdevice_p.h"
#include "qprintdialog.h"
#include <qpagelayout.h>

#ifndef LSCS_NO_PRINTER

QPlatformPrintDevice::QPlatformPrintDevice()
{
}

QPlatformPrintDevice::QPlatformPrintDevice( const BdPrintDestination &id )
    :m_name( id.name ), m_instance( id.instance ), m_uri( id.uri )
{

}

QPlatformPrintDevice::QPlatformPrintDevice( const QString &name )
    :m_name( name.toUtf8() )
{
}

QPlatformPrintDevice::~QPlatformPrintDevice()
{
}

QString QPlatformPrintDevice::name()
{
    return QString::fromUtf8( m_name );
}

QString QPlatformPrintDevice::location()
{
    return QString::fromUtf8( m_location );
}

QString QPlatformPrintDevice::makeAndModel()
{
    return QString::fromUtf8( m_makeAndModel );
}

QString QPlatformPrintDevice::uri()
{
    return QString::fromUtf8( m_uri );
}

QString QPlatformPrintDevice::instance()
{
    return QString::fromUtf8( m_instance );
}

bool QPlatformPrintDevice::isValid()
{
    return false;
}

bool QPlatformPrintDevice::isDefault()
{
    return false;
}

bool QPlatformPrintDevice::isRemote()
{
    return false;
}

bool QPlatformPrintDevice::isValidPageLayout( const QPageLayout &layout, int resolution )
{
    // Check the page size is supported
    if ( !supportedPageSize( layout.pageSize() ).isValid() )
    {
        return false;
    }

    // Check the margins are valid
    QMarginsF pointMargins = layout.margins( QPageSize::Unit::Point );
    QMarginsF printMargins = printableMargins( layout.pageSize(), layout.orientation(), resolution );

    return pointMargins.left() >= printMargins.left()
           && pointMargins.right() >= printMargins.right()
           && pointMargins.top() >= printMargins.top()
           && pointMargins.bottom() >= printMargins.bottom();
}

PrinterState QPlatformPrintDevice::state()
{
    return PrinterState::Error;
}

bool QPlatformPrintDevice::supportsMultipleCopies()
{
    // default does nothing
    return false;
}

bool QPlatformPrintDevice::supportsCollateCopies()
{
    // default does nothing
    return false;
}

QPageSize QPlatformPrintDevice::defaultPageSize()
{
    // default does nothing
    return QPageSize();
}

QList<QPageSize> QPlatformPrintDevice::supportedPageSizes()
{
    // default does nothing
    QList<QPageSize> retVal;

    return retVal;
}

QPageSize QPlatformPrintDevice::supportedPageSize( const QPageSize &pageSize )
{
    if ( !pageSize.isValid() )
    {
        return QPageSize();
    }

    return supportedPageSizeMatch( pageSize );
}

QPageSize QPlatformPrintDevice::supportedPageSize( QPageSize::PageSizeId pageSizeId )
{
    return supportedPageSizeMatch( QPageSize( pageSizeId ) );
}

QPageSize QPlatformPrintDevice::supportedPageSize( const QString &pageName )
{
    // default does nothing
    return QPageSize();
}

QPageSize QPlatformPrintDevice::supportedPageSize( const QSize &sizePoints )
{
    return supportedPageSizeMatch( QPageSize( sizePoints ) );
}

QPageSize QPlatformPrintDevice::supportedPageSize( const QSizeF &size, QPageSize::Unit units )
{
    return supportedPageSizeMatch( QPageSize( size, units ) );
}

QPageSize QPlatformPrintDevice::supportedPageSizeMatch( const QPageSize &pageSize )
{
    // Try to find a supported page size based on point size
    for ( const QPageSize &ps : supportedPageSizes() )
    {
        if ( ps.sizePoints() == pageSize.sizePoints() )
        {
            return ps;
        }
    }

    return QPageSize();
}

bool QPlatformPrintDevice::supportsCustomPageSizes()
{
    return false;
}

QSize QPlatformPrintDevice::minimumPhysicalPageSize()
{
    // default does nothing
    return QSize();
}

QSize QPlatformPrintDevice::maximumPhysicalPageSize()
{
    // default does nothing
    return QSize();
}

QMarginsF QPlatformPrintDevice::printableMargins( const QPageSize &pageSize,
        QPageLayout::Orientation orientation, int resolution )
{
    ( void ) pageSize;
    ( void ) orientation;
    ( void ) resolution;

    return QMarginsF( 0, 0, 0, 0 );
}

int QPlatformPrintDevice::defaultResolution()
{
    return 0;
}

QList<int> QPlatformPrintDevice::supportedResolutions()
{
    // default does nothing
    QList<int> retVal;

    return retVal;
}

QString QPlatformPrintDevice::defaultMediaSource()
{
    return QString();
}

QStringList QPlatformPrintDevice::supportedMediaSources()
{
    // default does nothing
    QStringList retVal;
    return retVal;
}

QString QPlatformPrintDevice::defaultOutputBin()
{
    // default does nothing
    return QString();
}

QStringList QPlatformPrintDevice::supportedOutputBins()
{
    // default does nothing
    QStringList retVal;
    return retVal;
}

QString QPlatformPrintDevice::defaultDuplexMode()
{
    return QString( "one-sided" );
}

QStringList QPlatformPrintDevice::supportedDuplexModes()
{
    // default does nothing
    QStringList retVal;
    return retVal;
}

QString QPlatformPrintDevice::defaultColorMode()
{
    return QString( "monochrome" );
}

QStringList QPlatformPrintDevice::supportedColorModes()
{
    // default does nothing
    QStringList retVal;
    return retVal;
}

QPageSize QPlatformPrintDevice::createPageSize( const QString &key, const QSize &size, const QString &localizedName )
{
    return QPageSize( key, size, localizedName );
}

QPageSize QPlatformPrintDevice::createPageSize( int windowsId, const QSize &size, const QString &localizedName )
{
    return QPageSize( windowsId, size, localizedName );
}

QString QPlatformPrintDevice::defaultPrintQuality()
{
    return QString( "normal" );
}

QStringList QPlatformPrintDevice::supportedPrintQualities()
{
    QStringList retVal;
    retVal << QString( "normal" );
    return retVal;
}

QString QPlatformPrintDevice::lastPrintError()
{
    // default does nothing
    return QString();
}

#endif // LSCS_NO_PRINTER

