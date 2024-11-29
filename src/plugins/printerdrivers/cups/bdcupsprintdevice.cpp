/***********************************************************************
*
* Copyright (c) 2024 Roland Hughes d.b.a Logikal Solutions
*
* This file is part of Ls-Cs.
*
* Ls-Cs is free software. You can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* Ls-Cs is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://www.gnu.org/licenses/
*
***********************************************************************/

#ifndef LSCS_LINUXBASE
// LSB merges everything into cups.h
#include <cups/language.h>
#endif

#include <bdcupsprintdevice.h>

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//      text strings for cups printer options
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

static const QString AUTH_REQUIRED_OPTION = "auth-info-required";       // The type of authentication required for printing to
// this destination: "none", "username,password",
// "domain,username,password", or "negotiate" (Kerberos).

static const QString INFO_OPTION = "printer-info";                      // The human-readable description of the destination
// such as "My Laser Printer".

static const QString ACCEPTING_JOBS_OPTION = "printer-is-accepting-jobs";   // "true" if the destination is accepting new jobs,
// "false" otherwise.

static const QString IS_SHARED_OPTION = "printer-is-shared";            // "true" if the destination is being shared with
// other computers, "false" otherwise.

static const QString LOCATION_OPTION = "printer-location";              // The human-readable location of the destination
// such as "Lab 4".

static const QString MAKE_AND_MODEL_OPTION = "printer-make-and-model";  // The human-readable make and model of the destination
// such as "ExampleCorp LaserPrinter 4000 Series".

static const QString STATE_OPTION = "printer-state";                    // "3" if the destination is idle, "4" if the
// destination is printing a job, and "5" if the
// destination is stopped.

static const QString STATE_CHANGE_TIME_OPTION = "printer-state-change-time";    // The UNIX time when the destination
// entered the current state.

static const QString STATE_REASONS_OPTION = "printer-state-reasons";    // Additional comma-delimited state keywords for
// the destination such as "media-tray-empty-error" and
// "toner-low-warning".

static const QString TYPE_OPTION = "printer-type";                      // The cups_ptype_t value associated with the destination.

static const QString URI_OPTION = "printer-uri-supported";              // The URI associated with the destination; if not set,
// this destination was discovered but is not yet setup
// as a local printer.

BdCupsPrintDevice::BdCupsPrintDevice() :
    QPlatformPrintDevice()
    , m_cupsDest( nullptr )
{
}

BdCupsPrintDevice( const BdPrintDestination &id ) :
    QPlatformPrintDevice( id )
    , m_cupsDest( nullptr )
{
    if ( id.name.length() > 0 )
    {
        m_cupsName      = id.name.toUtf8();
        m_cupsinstance  = id.instance.toUtf8();
        m_uri           = id.uri.toUtf8();

    }
}

BdCupsPrintDevice::~BdCupsPrintDevice()
{
    if ( m_cupsDest )
    {
        cupsFreeDests( 1, m_cupsDest );
    }

    m_cupsDest = nullptr;
}



bool BdCupsPrintDevice::isValid()
{
    bool retVal = false;

    if ( m_cupsDest )
    {
        retVal = true;
    }

    return retVal;
}

bool BdCupsPrintDevice::isDefault()
{
    return printerTypeFlags() & CUPS_PRINTER_DEFAULT;
}

QString BdCupsPrintDevice::printerOption( const QString &key) const
{
    return QString::fromUtf8(cupsGetOption( key.toUtf8(), m_cupsDest->num_options, m_cupsDest->options));
}

cups_ptype_e BdCupsPrintDevice::printerTypeFlags() const
{
    return static_cast<cups_ptype_e>(printerOption( TYPE_OPTION).toInteger<uint>());
}

QPrint::DeviceState BdCupsPrintDevice::state()
{
    // 3 = idle, 4 = printing, 5 = stopped
    int state = printerOption( STATE_OPTION ).toInteger<int>();

    switch ( state )
    {
        case 3:
            return QPrint::Idle;
            break;

        case 4:
            return QPrint::Active;
            break;

        default:
            // TODO:: we really need to handle other state values
            return QPrint::Error;
            break;
    }
}


QPageSize BdCupsPrintDevice::defaultPageSize() const
{
    QPageSize retVal;
    
    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );
    cups_size_t mediaSize;
    
    if (cupsGetDestMediaDefault( CUPS_HTTP_DEFAULT, m_cupsDest, info, CUPS_MEDIA_FLAGS_DEFAULT, &mediaSize ))
    {
            QString key = QString::fromUtf8( mediaSize.media);
            QSize   size = QSize( mediaSize.width, mediaSize.length);
                // old cold had different value for name but this should work
            retVal = createPageSize( key, size, key);
    }

    cupsFreeDestInfo( info );

    return retVal;
}

QMarginsF BdCupsPrintDevice::printableMargins( const QPageSize &pageSize, QPageLayout::Orientation orientation, int resolution) const
{
    // TODO:: consider orientation and resolution in calculation
    (void) orientation;
    (void) resolution;

    QMarginsF    retVal;
    cups_size_t  mediaSize;
    
    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );
    QRect rectInPoints = pageSize.rectPoints();
    

    if (cupsGetDestMediaBySize( CUPS_HTTP_DEFAULT, m_cupsDest, info,
                                rectInPoints.width(), rectInPoints.height(),
                                CUPS_MEDIA_FLAGS_DEFAULT, &mediaSize))
    {
        retVal = QMarginsF( mediaSize.left, mediaSize.top, mediaSize.right, mediaSize.bottom);
    }

    cupsFreeDestInfo( info );

    return retVal;
}

void BdCupsPrintDevice::loadResolutions() const
{
    m_resolutions.clear();

    
}
