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

#include <qprintdevice_p.h>
#include <qplatform_printdevice.h>

#include <qstringlist.h>

#ifndef LSCS_NO_PRINTER

QPrintDevice::QPrintDevice()
    : d( new QPlatformPrintDevice() )
{
    qDebug() << "QPrintDevice() default constructor called.";
}

QPrintDevice::QPrintDevice( const QString &id )
    : d( new QPlatformPrintDevice( id ) )
{
    qDebug() << "QPrintDevice constructor called with id: " << id;
}

QPrintDevice::QPrintDevice( QPlatformPrintDevice *dd )
    : d( dd )
{
    qDebug() << "QPrintDevice constructor called with:  ";

    if ( dd == nullptr )
    {
        qDebug() << "a null pointer";
    }
    else
    {
        qDebug() << " name: " << dd->name() << "  isValid: " << dd->isValid()
                 << " uri: " << dd->uri() << " makeAndModel: " << dd->makeAndModel()
                 << " state: " << static_cast<int>( dd->state() ) << endl << endl;
    }
}

QPrintDevice::QPrintDevice( const QPrintDevice &other )
    : d( other.d )
{
    qDebug() << "QPrintDevice copy constructor called name: " << d->name()
             << "    isValid:  " << d->isValid()
             << "    uri: " << d->uri()
             << "    makeAndModel: " << d->makeAndModel()
             << "    state: " << static_cast<int>( d->state() ) << endl << endl;
}

QPrintDevice::~QPrintDevice()
{
}

QPrintDevice &QPrintDevice::operator=( const QPrintDevice &other )
{
    d = other.d;
    qDebug() << "QPrintDevice assignment operator called name: " << d->name()
             << "    isValid:  " << d->isValid()
             << "    uri: " << d->uri()
             << "    makeAndModel: " << d->makeAndModel()
             << "    state: " << static_cast<int>( d->state() ) << endl << endl;
    return *this;
}

bool QPrintDevice::operator==( const QPrintDevice &other ) const
{
    bool retVal = false;

    if ( d && other.d )
    {
        if ( ( d->name() == other.d->name() )
                && ( d->instance() == other.d->instance() )
                && ( d->location() == other.d->location() )
                && ( d->makeAndModel() == other.d->makeAndModel() )
                && ( d->uri() == other.d->uri() ) )
        {
            retVal = true;
        }
    }

    return retVal;
}

QString QPrintDevice::name() const
{
    return isValid() ? d->name() : QString();
}

QString QPrintDevice::location() const
{
    return isValid() ? d->location() : QString();
}

QString QPrintDevice::makeAndModel() const
{
    return isValid() ? d->makeAndModel() : QString();
}

QString QPrintDevice::uri() const
{
    return isValid() ? d->uri() : QString();
}

QString QPrintDevice::lastPrintError() const
{
    return isValid() ? d->lastPrintError() : QString();
}

bool QPrintDevice::isValid() const
{
    return ( d && d->isValid() );
}

bool QPrintDevice::isDefault() const
{
    return isValid() && d->isDefault();
}

bool QPrintDevice::isRemote() const
{
    return isValid() && d->isRemote();
}

PrinterState QPrintDevice::state() const
{
    return isValid() ? d->state() : PrinterState::Error;
}

bool QPrintDevice::isValidPageLayout( const QPageLayout &layout, int resolution ) const
{
    return isValid() && d->isValidPageLayout( layout, resolution );
}

bool QPrintDevice::supportsMultipleCopies() const
{
    return isValid() && d->supportsMultipleCopies();
}

bool QPrintDevice::supportsCollateCopies() const
{
    return isValid() && d->supportsCollateCopies();
}

QPageSize QPrintDevice::defaultPageSize() const
{
    return isValid() ? d->defaultPageSize() : QPageSize();
}

QList<QPageSize> QPrintDevice::supportedPageSizes() const
{
    return isValid() ? d->supportedPageSizes() : QList<QPageSize>();
}

QPageSize QPrintDevice::supportedPageSize( const QPageSize &pageSize ) const
{
    return isValid() ? d->supportedPageSize( pageSize ) : QPageSize();
}

QPageSize QPrintDevice::supportedPageSize( QPageSize::PageSizeId pageSizeId ) const
{
    return isValid() ? d->supportedPageSize( pageSizeId ) : QPageSize();
}

QPageSize QPrintDevice::supportedPageSize( const QString &pageName ) const
{
    return isValid() ? d->supportedPageSize( pageName ) : QPageSize();
}

QPageSize QPrintDevice::supportedPageSize( const QSize &pointSize ) const
{
    return isValid() ? d->supportedPageSize( pointSize ) : QPageSize();
}

QPageSize QPrintDevice::supportedPageSize( const QSizeF &size, QPageSize::Unit units ) const
{
    return isValid() ? d->supportedPageSize( size, units ) : QPageSize();
}

bool QPrintDevice::supportsCustomPageSizes() const
{
    return isValid() && d->supportsCustomPageSizes();
}

QSize QPrintDevice::minimumPhysicalPageSize() const
{
    return isValid() ? d->minimumPhysicalPageSize() : QSize();
}

QSize QPrintDevice::maximumPhysicalPageSize() const
{
    return isValid() ? d->maximumPhysicalPageSize() : QSize();
}

QMarginsF QPrintDevice::printableMargins( const QPageSize &pageSize,
        QPageLayout::Orientation orientation,
        int resolution ) const
{
    return isValid() ? d->printableMargins( pageSize, orientation, resolution ) : QMarginsF();
}

int QPrintDevice::defaultResolution() const
{
    return isValid() ? d->defaultResolution() : 0;
}

QList<int> QPrintDevice::supportedResolutions() const
{
    return isValid() ? d->supportedResolutions() : QList<int>();
}

QString QPrintDevice::defaultMediaSource() const
{
    return isValid() ? d->defaultMediaSource() : QString( "auto" );
}

QStringList QPrintDevice::supportedMediaSources() const
{
    return isValid() ? d->supportedMediaSources() : QStringList();
}

QString QPrintDevice::defaultOutputBin() const
{
    return isValid() ? d->defaultOutputBin() : QString();
}

QStringList QPrintDevice::supportedOutputBins() const
{
    return isValid() ? d->supportedOutputBins() : QStringList();
}

QString QPrintDevice::defaultDuplexMode() const
{
    return isValid() ? d->defaultDuplexMode() : QString();
}

QStringList QPrintDevice::supportedDuplexModes() const
{
    return isValid() ? d->supportedDuplexModes() : QStringList();
}

QString QPrintDevice::defaultColorMode() const
{
    return isValid() ? d->defaultColorMode() : QString();
}

QStringList QPrintDevice::supportedColorModes() const
{
    return isValid() ? d->supportedColorModes() : QStringList();
}


#endif // LSCS_NO_PRINTER


