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

#include <qplatform_printersupport.h>

#include <qplatform_printdevice.h>
#include <qpagesize.h>
#include <qprinterinfo.h>
#include <qprinter.h>
#include <qprinterinfo_p.h>
#include <qprintdevice_p.h>

#ifndef LSCS_NO_PRINTER

QPlatformPrinterSupport::QPlatformPrinterSupport()
{
}

QPlatformPrinterSupport::~QPlatformPrinterSupport()
{
}

QPrintEngine *QPlatformPrinterSupport::createNativePrintEngine( PrinterMode mode )
{
    ( void ) mode;
    return nullptr;
}

QPaintEngine *QPlatformPrinterSupport::createPaintEngine( QPrintEngine *engine, PrinterMode mode )
{
    ( void ) engine;
    ( void ) mode;
    return nullptr;
}

QPrintDevice QPlatformPrinterSupport::createPrintDevice( QPlatformPrintDevice *device )
{
    ( void ) device;
    qDebug() << "QPlatformPrinterSupport::createPrintDevice() called";
    if (!device)
    {
        qDebug() << "\t device recieved - m_name : " << device->name()
                 << "   m_instance : " << device->instance()
                 << "   m_location : " << device->location()
                 << "   m_makeAndModel : " << device->makeAndModel() 
                 << "   m_uri : " << device->uri() << endl;
    }
    
    return QPrintDevice( device );
}

QPrintDevice QPlatformPrinterSupport::createPrintDevice( const QString &id )
{
    ( void ) id;
    return QPrintDevice();
}

QPrintDevice QPlatformPrinterSupport::createDefaultPrintDevice()
{
    return createPrintDevice( defaultPrintDeviceId() );
}

QStringList QPlatformPrinterSupport::availablePrintDeviceIds() const
{
    return QStringList();
}

QString QPlatformPrinterSupport::defaultPrintDeviceId() const
{
    return QString();
}

QPageSize QPlatformPrinterSupport::createPageSize( const QString &id, QSize size, const QString &localizedName )
{
    ( void ) id;
    ( void ) size;
    ( void ) localizedName;
    return QPageSize();
}

#endif // LSCS_NO_PRINTER
