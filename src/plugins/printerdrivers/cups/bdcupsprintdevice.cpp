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

#include <qstringlist.h>
#include <QRegularExpression>

#include <bdcupsprintdevice.h>

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//      text strings for cups printer options
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

/* Printer capability attribute of default resolution */
static const char *DEFAULT_RESOLUTION_NAME = "printer-resolution-default";

/* Printer URI request */
static const char *PRINTER_URI_REQUEST = "printer-uri";

/* The type of authentication required for printing to this destination:
 * "none", "username,password","domain,username,password", or "negotiate" (Kerberos).
 */
static const char *AUTH_REQUIRED_OPTION = "auth-info-required";

/* The human-readable description of the destination such as "My Laser Printer". */
static const char *INFO_OPTION = "printer-info";

/* "true" if the destination is accepting new jobs, "false" otherwise. */
static const char *ACCEPTING_JOBS_OPTION = "printer-is-accepting-jobs";

/* "true" if the destination is being shared with other computers, "false" otherwise. */
static const char *IS_SHARED_OPTION = "printer-is-shared";

/* The human-readable location of the destination such as "Lab 4". */
static const char *LOCATION_OPTION = "printer-location";

/* The human-readable make and model of the destination such as "ExampleCorp LaserPrinter 4000 Series". */
static const char *MAKE_AND_MODEL_OPTION = "printer-make-and-model";

/* "3" if the destination is idle, "4" if the destination is printing a job, and "5" if the destination is stopped. */
static const char *STATE_OPTION = "printer-state";

/* The UNIX time when the destination entered the current state. */
static const char *STATE_CHANGE_TIME_OPTION = "printer-state-change-time";

/* Additional comma-delimited state keywords for the destination such as "media-tray-empty-error" and "toner-low-warning". */
static const char *STATE_REASONS_OPTION = "printer-state-reasons";

/* The cups_ptype_t value associated with the destination. */
static const char *TYPE_OPTION = "printer-type";

/* The URI associated with the destination; if not set, this destination was discovered
 * but is not yet setup as a local printer.
 */
static const char *URI_OPTION = "printer-uri-supported";

/* list of requested attributes being requested */
static const char *ATTRIBUTE_LIST_REQUEST = "requested-attributes";

/* default media attributes */
static const char *MEDIA_COL_DEFAULT = "media-col-default";

/* media source sub attribute */
static const char *MEDIA_SOURCE = "media-source";

/* number of copies supported */
static const char *COPIES_SUPPORTED = "copies-supported";

/* can it collate copies */
static const char *MULTIPLE_DOCUMENT_HANDLING = "multiple-document-handling-supported";

/* color modes */
static const char *COLOR_MODE_SUPPORTED = "print-color-mode-supported";

BdCupsPrintDevice::BdCupsPrintDevice() :
    QPlatformPrintDevice()
    , m_cupsDest( nullptr )
{
}

BdCupsPrintDevice::BdCupsPrintDevice( const BdPrintDestination &id ) :
    QPlatformPrintDevice( id )
    , m_cupsDest( nullptr )
{
    /* We have bit of issue here with Cups being a C interface
       and most of our methods of obtaining a char * returning a
       const pointer. A valid pointer to a NULL buffer isn't the
       same as a NULL pointer.
    */
    int numDests = 0;

    if ( ( id.name.length() > 0 ) && ( id.instance.length() > 0 ) )
    {
        cupsGetDest( id.name.constData(), id.instance.constData(), numDests, m_cupsDest );
    }
    else if ( id.name.length() > 0 )
    {
        m_cupsDest = cupsGetNamedDest( CUPS_HTTP_DEFAULT, id.name.constData(), NULL );
    }
    else if ( id.instance.length() > 0 )
    {
        cupsGetDest( NULL, id.instance.constData(), numDests, m_cupsDest );
    }

    loadInfo();

}

BdCupsPrintDevice::BdCupsPrintDevice( const QString &name ) :
    QPlatformPrintDevice( name )
    , m_cupsDest( nullptr )
{
    m_cupsDest = cupsGetNamedDest( CUPS_HTTP_DEFAULT, name.toUtf8().constData(), NULL );

    if ( m_cupsDest == nullptr )
    {
        qDebug() << "****************cupsGetNamedDest returned nullptr" << endl;
    }

    loadInfo();
}

BdCupsPrintDevice::~BdCupsPrintDevice()
{
    if ( m_cupsDest )
    {
        cupsFreeDests( 1, m_cupsDest );
    }

    m_cupsDest = nullptr;
}

void BdCupsPrintDevice::loadInfo()
{
    if ( !m_cupsDest )
    {
        return;
    }

    m_name = QByteArray( m_cupsDest->name );

    m_instance.clear();

    if ( m_cupsDest->instance )
    {
        m_instance = QByteArray( m_cupsDest->instance );
    }

    m_uri = printerOption( QString::fromUtf8( URI_OPTION ) ).toUtf8();

    m_makeAndModel = printerOption( QString::fromUtf8( MAKE_AND_MODEL_OPTION ) ).toUtf8();

    m_location = printerOption( QString::fromUtf8( LOCATION_OPTION ) ).toUtf8();

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

bool BdCupsPrintDevice::isRemote()
{
    return printerTypeFlags() & CUPS_PRINTER_REMOTE;
}

bool BdCupsPrintDevice::supportsMultipleCopies()
{
    return printerTypeFlags() & CUPS_PRINTER_COPIES;
}

bool BdCupsPrintDevice::supportsCollateCopies()
{
    return printerTypeFlags() & CUPS_PRINTER_COLLATE;
}

bool BdCupsPrintDevice::supportsCustomPageSizes()
{
    return printerTypeFlags() & CUPS_PRINTER_VARIABLE;
}

QString BdCupsPrintDevice::printerOption( const QString &key )
{
    return QString::fromUtf8( cupsGetOption( key.toUtf8().constData(), m_cupsDest->num_options, m_cupsDest->options ) );
}

cups_ptype_e BdCupsPrintDevice::printerTypeFlags()
{
    return static_cast<cups_ptype_e>( printerOption( QString::fromUtf8( TYPE_OPTION ) ).toInteger<uint>() ) ;
}

PrinterState BdCupsPrintDevice::state()
{
    // 3 = idle, 4 = printing, 5 = stopped
    int state = printerOption( QString::fromUtf8( STATE_OPTION ) ).toInteger<int>();

    switch ( state )
    {
        case 3:
            return PrinterState::Idle;
            break;

        case 4:
            return PrinterState::Active;
            break;

        case 5:
            return PrinterState::Stopped;
            break;

        default:
            // TODO:: we really need to handle other state values
            break;
    }

    return PrinterState::Error;
}


QPageSize BdCupsPrintDevice::defaultPageSize()
{
    QPageSize retVal;

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );
    cups_size_t mediaSize;

    if ( cupsGetDestMediaDefault( CUPS_HTTP_DEFAULT, m_cupsDest, info, CUPS_MEDIA_FLAGS_DEFAULT, &mediaSize ) )
    {
        QString key = QString::fromUtf8( mediaSize.media );
        QSize   size = QSize( mediaSize.width, mediaSize.length );
        // old code had different value for name but this should work
        // we really need to gut this keyed page size logic across all platforms
        // no need to store stuff anymore. The printer servers keep track of it.
        retVal = createPageSize( key, size, key );
    }

    cupsFreeDestInfo( info );

    return retVal;
}

QMarginsF BdCupsPrintDevice::printableMargins( const QPageSize &pageSize, QPageLayout::Orientation orientation,
        int resolution )
{
    // TODO:: consider orientation and resolution in calculation
    ( void ) orientation;
    ( void ) resolution;

    QMarginsF    retVal;
    cups_size_t  mediaSize;

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );
    QRect rectInPoints = pageSize.rectPoints();


    if ( cupsGetDestMediaBySize( CUPS_HTTP_DEFAULT, m_cupsDest, info,
                                 rectInPoints.width(), rectInPoints.height(),
                                 CUPS_MEDIA_FLAGS_DEFAULT, &mediaSize ) )
    {
        retVal = QMarginsF( mediaSize.left, mediaSize.top, mediaSize.right, mediaSize.bottom );
    }

    cupsFreeDestInfo( info );

    return retVal;
}

int BdCupsPrintDevice::defaultResolution()
{
    int retVal = 72;   // assume dot matrix based on Epson MX-80 - note graphics mode was only 60 dpi

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

    // CUPS_DEST_FLAGS_DEVICE
    http_t *http = cupsConnectDest( m_cupsDest, CUPS_DEST_FLAGS_NONE, 30000, NULL, m_resource, RESOURCE_SIZE, NULL, NULL );

    if ( http )
    {

        ipp_t *request = ippNewRequest( IPP_OP_GET_PRINTER_ATTRIBUTES );
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, m_uri.constData() );
        ipp_t *response = cupsDoRequest( http, request, m_resource );

        if ( !( cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST ) )
        {
            ipp_attribute_t *attr;

            if ( ( attr = ippFindAttribute( response, DEFAULT_RESOLUTION_NAME, IPP_TAG_RESOLUTION ) ) != NULL )
            {
                ippAttributeString( attr, m_value, VALUE_SIZE );
                QString resl = QString::fromUtf8( m_value );
                QRegularExpression exp( "^(\\d+)" );
                QRegularExpressionMatch mtch = exp.match( resl );

                if ( mtch.hasMatch() )
                {
                    QString txt = mtch.capturedTexts( )[0];
                    retVal = txt.toInteger<int>();
                }
            }
        }


        httpClose( http );
    }
    else
    {
        qDebug() << "unable to connect to printer";
    }

    return retVal;
}

QString BdCupsPrintDevice::lastPrintError()
{
    return QString::fromUtf8( cupsLastErrorString() );
}

QString BdCupsPrintDevice::defaultMediaSource()
{
    QString retVal = "auto";

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

    static const char *const requested_attributes[] =
    {
        "media-col-database"
    };

    // CUPS_DEST_FLAGS_DEVICE
    http_t *http = cupsConnectDest( m_cupsDest, CUPS_DEST_FLAGS_NONE, 30000, NULL, m_resource, RESOURCE_SIZE, NULL, NULL );

    if ( http )
    {
        ipp_t *request = ippNewRequest( IPP_OP_GET_PRINTER_ATTRIBUTES );
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, m_uri.constData() );
        ippAddStrings( request, IPP_TAG_OPERATION, IPP_TAG_KEYWORD, ATTRIBUTE_LIST_REQUEST,
                       ( int )( sizeof( requested_attributes ) / sizeof( requested_attributes[0] ) ), NULL, requested_attributes );
        ipp_t *response = cupsDoRequest( http, request, m_resource );

        if ( ( cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST ) )
        {
            return retVal;
        }

        ipp_attribute_t *attr = nullptr;
        ipp_attribute_t *defAttr = nullptr;

        if ( ( defAttr = ippFindAttribute( response, MEDIA_COL_DEFAULT, IPP_TAG_BEGIN_COLLECTION ) ) != NULL )
        {
            if ( ( attr = ippFindAttribute( ippGetCollection( defAttr, 0 ), MEDIA_SOURCE, IPP_TAG_ZERO ) ) != NULL )
            {
                ippAttributeString( attr, m_value, VALUE_SIZE );
                retVal = QString::fromUtf8( m_value );
            }

        }

        httpClose( http );
    }
    else
    {
        qDebug() << "unable to connect to printer";
    }

    return retVal;
}


QString BdCupsPrintDevice::defaultOutputBin()
{
    QString retVal( "auto" );

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

    static const char *const requested_attributes[] =
    {
        "output-bin-default"
    };

    // CUPS_DEST_FLAGS_DEVICE
    http_t *http = cupsConnectDest( m_cupsDest, CUPS_DEST_FLAGS_NONE, 30000, NULL, m_resource, RESOURCE_SIZE, NULL, NULL );

    if ( http )
    {
        ipp_t *request = ippNewRequest( IPP_OP_GET_PRINTER_ATTRIBUTES );
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, m_uri.constData() );
        ippAddStrings( request, IPP_TAG_OPERATION, IPP_TAG_KEYWORD, ATTRIBUTE_LIST_REQUEST,
                       ( int )( sizeof( requested_attributes ) / sizeof( requested_attributes[0] ) ), NULL, requested_attributes );
        ipp_t *response = cupsDoRequest( http, request, m_resource );

        if ( ( cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST ) )
        {
            return retVal;
        }

        ipp_attribute_t *attr = nullptr;

        if ( ( attr = ippFindAttribute( response, "output-bin-default", IPP_TAG_ZERO ) ) != NULL )
        {
            ippAttributeString( attr, m_value, VALUE_SIZE );
            retVal = QString::fromUtf8( m_value );
        }

        httpClose( http );
    }
    else
    {
        qDebug() << "unable to connect to printer";
    }

    return retVal;
}

QStringList BdCupsPrintDevice::supportedOutputBins()
{
    QStringList retVal;

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );
    static const char *const requested_attributes[] =
    {
        "output-bin-supported"
    };

    // CUPS_DEST_FLAGS_DEVICE
    http_t *http = cupsConnectDest( m_cupsDest, CUPS_DEST_FLAGS_NONE, 30000, NULL, m_resource, RESOURCE_SIZE, NULL, NULL );

    if ( http )
    {
        ipp_t *request = ippNewRequest( IPP_OP_GET_PRINTER_ATTRIBUTES );
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, m_uri.constData() );
        ippAddStrings( request, IPP_TAG_OPERATION, IPP_TAG_KEYWORD, ATTRIBUTE_LIST_REQUEST,
                       ( int )( sizeof( requested_attributes ) / sizeof( requested_attributes[0] ) ), NULL, requested_attributes );
        ipp_t *response = cupsDoRequest( http, request, m_resource );

        if ( ( cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST ) )
        {
            httpClose( http );
            cupsFreeDestInfo( info );
            return retVal;
        }

        ipp_attribute_t *attr = nullptr;

        if ( ( attr = ippFindAttribute( response, "output-bin-supported", IPP_TAG_ZERO ) ) != NULL )
        {
            int binCount = ippGetCount( attr );

            for ( int uuu = 0; uuu < binCount; uuu++ )
            {
                retVal << QString::fromUtf8( ippGetString( attr, uuu, NULL ) );
            }
        }

        httpClose( http );
    }
    else
    {
        qDebug() << "unable to connect to printer";
    }

    cupsFreeDestInfo( info );
    return retVal;
}

QString BdCupsPrintDevice::defaultDuplexMode()
{
    QString retVal = "one-sided";

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }


    ipp_attribute_t *attr = nullptr;
    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );


    if ( ( attr = cupsFindDestDefault( CUPS_HTTP_DEFAULT, m_cupsDest, info, CUPS_SIDES ) ) != NULL )
    {
        ippAttributeString( attr, m_value, VALUE_SIZE );
        retVal = QString::fromUtf8( m_value );
    }

    cupsFreeDestInfo( info );

    return retVal;
}


QString BdCupsPrintDevice::defaultColorMode()
{
    QString retVal;

    ipp_attribute_t *attr = nullptr;
    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );

    if ( ( attr = cupsFindDestDefault( CUPS_HTTP_DEFAULT, m_cupsDest, info, CUPS_PRINT_COLOR_MODE ) ) != NULL )
    {
        ippAttributeString( attr, m_value, VALUE_SIZE );
        retVal = QString::fromUtf8( m_value );
    }

    cupsFreeDestInfo( info );

    return retVal;
}

QList<QPageSize> BdCupsPrintDevice::supportedPageSizes()
{
    QList<QPageSize> retVal;

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

    ipp_attribute_t *attr = nullptr;
    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );

    int mediaCount = cupsGetDestMediaCount( CUPS_HTTP_DEFAULT, m_cupsDest, info, CUPS_MEDIA_FLAGS_DEFAULT );

    for ( int jjj=0; jjj < mediaCount; jjj++ )
    {
        cups_size_t media;

        if ( cupsGetDestMediaByIndex( CUPS_HTTP_DEFAULT, m_cupsDest, info, jjj, CUPS_MEDIA_FLAGS_DEFAULT, &media ) )
        {
            QString mediaName = QString::fromUtf8( media.media );
            retVal.append( QPageSize( QSize( media.width, media.length ),mediaName ) );
        }

    }

    cupsFreeDestInfo( info );

    return retVal;
}

QPageSize BdCupsPrintDevice::supportedPageSize( const QString &pageName )
{
    QPageSize retVal;

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

    ipp_attribute_t *attr = nullptr;
    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );

    cups_size_t media;
    QString localName( pageName );

    if ( cupsGetDestMediaByName( CUPS_HTTP_DEFAULT, m_cupsDest, info,
                                 localName.toUtf8().constData(),
                                 CUPS_MEDIA_FLAGS_DEFAULT, &media ) )
    {
        QString mediaName = QString::fromUtf8( media.media );
        retVal = QPageSize( QSize( media.width, media.length ), mediaName );
    }


    cupsFreeDestInfo( info );

    return retVal;
}

QSize BdCupsPrintDevice::minimumPhysicalPageSize()
{
    QSize retVal;

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

    ipp_attribute_t *attr = nullptr;
    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );

    int mediaCount = cupsGetDestMediaCount( CUPS_HTTP_DEFAULT, m_cupsDest, info, CUPS_MEDIA_FLAGS_DEFAULT );

    if ( mediaCount > 0 )
    {
        cups_size_t media;

        if ( cupsGetDestMediaByIndex( CUPS_HTTP_DEFAULT, m_cupsDest, info, 0, CUPS_MEDIA_FLAGS_DEFAULT, &media ) )
        {
            retVal = QSize( media.width, media.length );
        }

    }

    cupsFreeDestInfo( info );

    return retVal;

}

QSize BdCupsPrintDevice::maximumPhysicalPageSize()
{
    QSize retVal;

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

    ipp_attribute_t *attr = nullptr;
    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );

    int mediaCount = cupsGetDestMediaCount( CUPS_HTTP_DEFAULT, m_cupsDest, info, CUPS_MEDIA_FLAGS_DEFAULT );

    if ( mediaCount > 0 )
    {
        cups_size_t media;

        if ( cupsGetDestMediaByIndex( CUPS_HTTP_DEFAULT, m_cupsDest, info, mediaCount - 1, CUPS_MEDIA_FLAGS_DEFAULT, &media ) )
        {
            retVal = QSize( media.width, media.length );
        }

    }

    cupsFreeDestInfo( info );

    return retVal;
}

QList<int> BdCupsPrintDevice::supportedResolutions()
{
    QList<int> retVal;

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

    static const char *const requested_attributes[] =
    {
        "printer-resolution-supported"
    };

    // CUPS_DEST_FLAGS_DEVICE
    http_t *http = cupsConnectDest( m_cupsDest, CUPS_DEST_FLAGS_NONE, 30000, NULL, m_resource, RESOURCE_SIZE, NULL, NULL );

    if ( http )
    {
        ipp_t *request = ippNewRequest( IPP_OP_GET_PRINTER_ATTRIBUTES );
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, m_uri.constData() );
        ippAddStrings( request, IPP_TAG_OPERATION, IPP_TAG_KEYWORD, ATTRIBUTE_LIST_REQUEST,
                       ( int )( sizeof( requested_attributes ) / sizeof( requested_attributes[0] ) ), NULL, requested_attributes );
        ipp_t *response = cupsDoRequest( http, request, m_resource );

        if ( ( cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST ) )
        {
            return retVal;
        }

        ipp_attribute_t *attr = nullptr;

        if ( ( attr = ippFindAttribute( response, "printer-resolution-supported", IPP_TAG_RESOLUTION ) ) != NULL )
        {
            ippAttributeString( attr, m_value, VALUE_SIZE );
            QString str = QString::fromUtf8( m_value );
            QStringList lst = str.split( "," );
            QRegularExpression exp( "^(\\d+)" );

            for ( QString txt : lst )
            {
                QRegularExpressionMatch mtch2 = exp.match( txt );

                if ( mtch2.hasMatch() )
                {
                    QString dpi = mtch2.capturedTexts()[0];
                    retVal.append( dpi.toInteger<int>() );
                }
            }
        }

        httpClose( http );
    }
    else
    {
        qDebug() << "Unable to connect to printer";
    }

    return retVal;
}

QStringList BdCupsPrintDevice::supportedMediaSources()
{
    QStringList retVal;

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

    static const char *const requested_attributes[] =
    {
        "media-sources-supported"
    };

    // CUPS_DEST_FLAGS_DEVICE
    http_t *http = cupsConnectDest( m_cupsDest, CUPS_DEST_FLAGS_NONE, 30000, NULL, m_resource, RESOURCE_SIZE, NULL, NULL );

    if ( http )
    {

        ipp_t *request = ippNewRequest( IPP_OP_GET_PRINTER_ATTRIBUTES );
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, m_uri.constData() );
        ippAddStrings( request, IPP_TAG_OPERATION, IPP_TAG_KEYWORD, ATTRIBUTE_LIST_REQUEST,
                       ( int )( sizeof( requested_attributes ) / sizeof( requested_attributes[0] ) ), NULL, requested_attributes );
        ipp_t *response = cupsDoRequest( http, request, m_resource );

        if ( ( cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST ) )
        {
            return retVal;
        }

        ipp_attribute_t *attr = nullptr;

        if ( ( attr = ippFindAttribute( response, "media-source-supported", IPP_TAG_ZERO ) ) != NULL )
        {
            int srcCnt = ippGetCount( attr );

            for ( int yyy=0; yyy < srcCnt; yyy++ )
            {
                retVal.append( QString::fromUtf8( ippGetString( attr, yyy, NULL ) ) );
            }
        }

        httpClose( http );
    }
    else
    {
        qDebug() << "unable to connect to printer";
    }

    return retVal;
}


QStringList BdCupsPrintDevice::supportedDuplexModes()
{
    QStringList retVal;

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );
    static const char *const requested_attributes[] =
    {
        CUPS_SIDES_SUPPORTED
    };

    // CUPS_DEST_FLAGS_DEVICE
    http_t *http = cupsConnectDest( m_cupsDest, CUPS_DEST_FLAGS_NONE, 30000, NULL, m_resource, RESOURCE_SIZE, NULL, NULL );

    if ( http )
    {
        ipp_t *request = ippNewRequest( IPP_OP_GET_PRINTER_ATTRIBUTES );
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, m_uri.constData() );
        ippAddStrings( request, IPP_TAG_OPERATION, IPP_TAG_KEYWORD, ATTRIBUTE_LIST_REQUEST,
                       ( int )( sizeof( requested_attributes ) / sizeof( requested_attributes[0] ) ), NULL, requested_attributes );
        ipp_t *response = cupsDoRequest( http, request, m_resource );

        if ( ( cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST ) )
        {
            httpClose( http );
            cupsFreeDestInfo( info );
            return retVal;
        }

        ipp_attribute_t *attr = nullptr;

        if ( ( attr = ippFindAttribute( response, CUPS_SIDES_SUPPORTED, IPP_TAG_ZERO ) ) != NULL )
        {
            int binCount = ippGetCount( attr );

            for ( int uuu = 0; uuu < binCount; uuu++ )
            {
                retVal << QString::fromUtf8( ippGetString( attr, uuu, NULL ) );
            }
        }

        httpClose( http );
    }
    else
    {
        qDebug() << "unable to connect to printer";
    }

    cupsFreeDestInfo( info );
    return retVal;
}


QStringList BdCupsPrintDevice::supportedColorModes()
{
    QStringList retVal;

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );
    static const char *const requested_attributes[] =
    {
        CUPS_PRINT_COLOR_MODE_SUPPORTED
    };

    // CUPS_DEST_FLAGS_DEVICE
    http_t *http = cupsConnectDest( m_cupsDest, CUPS_DEST_FLAGS_NONE, 30000, NULL, m_resource, RESOURCE_SIZE, NULL, NULL );

    if ( http )
    {
        ipp_t *request = ippNewRequest( IPP_OP_GET_PRINTER_ATTRIBUTES );
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, m_uri.constData() );
        ippAddStrings( request, IPP_TAG_OPERATION, IPP_TAG_KEYWORD, ATTRIBUTE_LIST_REQUEST,
                       ( int )( sizeof( requested_attributes ) / sizeof( requested_attributes[0] ) ), NULL, requested_attributes );
        ipp_t *response = cupsDoRequest( http, request, m_resource );

        if ( ( cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST ) )
        {
            httpClose( http );
            cupsFreeDestInfo( info );
            return retVal;
        }

        ipp_attribute_t *attr = nullptr;

        if ( ( attr = ippFindAttribute( response, CUPS_PRINT_COLOR_MODE_SUPPORTED, IPP_TAG_ZERO ) ) != NULL )
        {
            int binCount = ippGetCount( attr );

            for ( int uuu = 0; uuu < binCount; uuu++ )
            {
                retVal << QString::fromUtf8( ippGetString( attr, uuu, NULL ) );
            }
        }

        httpClose( http );
    }
    else
    {
        qDebug() << "unable to connect to printer";
    }

    cupsFreeDestInfo( info );
    return retVal;
}
