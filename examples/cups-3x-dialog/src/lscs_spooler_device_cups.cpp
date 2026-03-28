/*;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright (c) 2024-2026 Roland Hughes d.b.a Logikal Solutions
;;
;; This file is part of Ls-Cs, also known as LsCs
;;
;; Ls-Cs is free software. You can redistribute it and/or
;; modify it under the terms the Basis Doctrina License found in
;; Basis_Doctrina_License.txt
;;
;; Ls-Cs is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;*/

/*! \file lscs_print_device_cups.cpp
 * \brief Spooling device supporting Cups 3.x API
 *
 * \details Provides an interface to a Cups 3.x supported device. This does not
 *          necessarily mean a printer.
 */
#ifndef LSCS_LINUXBASE
// LSB merges everything into cups.h
#include <cups/language.h>
#endif

#include <qstringlist.h>
#include <qregularexpression.h>
#include <qfile.h>

#include <lscs_spooler_device_cups.h>

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//      text strings for cups printer options
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

/* Printer capability attribute of default resolution */
static const char *DEFAULT_RESOLUTION_NAME = "printer-resolution-default";

/* Printer URI request */
static const char *PRINTER_URI_REQUEST = "printer-uri";


/* The human-readable location of the destination such as "Lab 4". */
static const char *LOCATION_OPTION = "printer-location";

/* The human-readable make and model of the destination such as "ExampleCorp LaserPrinter 4000 Series". */
static const char *MAKE_AND_MODEL_OPTION = "printer-make-and-model";

/* "3" if the destination is idle, "4" if the destination is printing a job, and "5" if the destination is stopped. */
static const char *STATE_OPTION = "printer-state";

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


lscs_spooler_device_cups::lscs_spooler_device_cups( const QString &name ) :
    m_cupsDest( nullptr )
{
    QString workName = name;

    if ( name.length() < 1 )
    {
        workName = lscs_spooler_device::default_device_name();
    }

    m_cupsDest = cupsGetNamedDest( CUPS_HTTP_DEFAULT, workName.toUtf8().constData(), NULL );

    if ( m_cupsDest == nullptr )
    {
        qDebug() << "****************cupsGetNamedDest returned nullptr" << endl;
    }

    load_info();
}

lscs_spooler_device_cups::~lscs_spooler_device_cups()
{
    if ( m_cupsDest )
    {
        cupsFreeDests( 1, m_cupsDest );
    }

    m_cupsDest = nullptr;
}

void lscs_spooler_device_cups::load_info()
{
    if ( !m_cupsDest )
    {
        return;
    }

    set_device_name( QString::fromUtf8( m_cupsDest->name ) );

    m_instance.clear();

    if ( m_cupsDest->instance )
    {
        m_instance = QString::fromUtf8( m_cupsDest->instance );
    }

    set_uri( printer_option( QString::fromUtf8( URI_OPTION ) ) );
    set_description( printer_option( QString::fromUtf8( MAKE_AND_MODEL_OPTION ) ) );
    set_location( printer_option( QString::fromUtf8( LOCATION_OPTION ) ) );

}

bool lscs_spooler_device_cups::is_valid()
{
    bool retVal = false;

    if ( m_cupsDest )
    {
        retVal = true;
    }

    return retVal;
}

bool lscs_spooler_device_cups::is_default()
{
    return printer_type_flags() & CUPS_PRINTER_DEFAULT;
}

bool lscs_spooler_device_cups::is_remote()
{
    return printer_type_flags() & CUPS_PRINTER_REMOTE;
}

bool lscs_spooler_device_cups::supports_multiple_copies()
{
    return printer_type_flags() & CUPS_PRINTER_COPIES;
}

bool lscs_spooler_device_cups::supports_collate_copies()
{
    return printer_type_flags() & CUPS_PRINTER_COLLATE;
}

bool lscs_spooler_device_cups::supports_custom_page_sizes()
{
    return printer_type_flags() & CUPS_PRINTER_VARIABLE;
}

QString lscs_spooler_device_cups::printer_option( const QString &key )
{
    return QString::fromUtf8( cupsGetOption( key.toUtf8().constData(), m_cupsDest->num_options, m_cupsDest->options ) );
}

cups_ptype_e lscs_spooler_device_cups::printer_type_flags()
{
    return static_cast<cups_ptype_e>( printer_option( QString::fromUtf8( TYPE_OPTION ) ).toInteger<uint>() ) ;
}

LsCsSpoolerDeviceState lscs_spooler_device_cups::state()
{
    // 3 = idle, 4 = printing, 5 = stopped
    int state = printer_option( QString::fromUtf8( STATE_OPTION ) ).toInteger<int>();

    switch ( state )
    {
        case 3:
            return LsCsSpoolerDeviceState::Idle;
            break;

        case 4:
            return LsCsSpoolerDeviceState::Active;
            break;

        case 5:
            return LsCsSpoolerDeviceState::Stopped;
            break;

        default:
            // TODO:: we really need to handle other state values
            break;
    }

    return LsCsSpoolerDeviceState::Error;
}


QPageSize lscs_spooler_device_cups::default_page_size()
{
    QPageSize retVal;

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );
    cups_size_t mediaSize;

    if ( cupsGetDestMediaDefault( CUPS_HTTP_DEFAULT, m_cupsDest, info, CUPS_MEDIA_FLAGS_DEFAULT, &mediaSize ) )
    {
        // thankfully cups uses mm which is the default unit for QSize.
        QSize   size = QSize( mediaSize.width, mediaSize.length );
        retVal = QPageSize( size,
                            QPageSize::Millimeter,
                            QString::fromUtf8( mediaSize.media ),
                            QPageSize::FuzzyOrientationMatch );
    }

    cupsFreeDestInfo( info );

    return retVal;
}

QMarginsF lscs_spooler_device_cups::printable_margins( const QPageSize &pageSize, QPageLayout::Orientation orientation,
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

int lscs_spooler_device_cups::default_resolution()
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
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, uri().toUtf8().constData() );
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

QString lscs_spooler_device_cups::last_known_error()
{
    return QString::fromUtf8( cupsLastErrorString() );
}

QString lscs_spooler_device_cups::default_media_source()
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
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, uri().toUtf8().constData() );
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


QString lscs_spooler_device_cups::default_output_bin()
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
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, uri().toUtf8().constData() );
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

QStringList lscs_spooler_device_cups::supported_output_bins()
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
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, uri().toUtf8().constData() );
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

QString lscs_spooler_device_cups::default_duplex_mode()
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


QString lscs_spooler_device_cups::default_color_mode()
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

QList<QPageSize> lscs_spooler_device_cups::supported_page_sizes()
{
    QList<QPageSize> retVal;

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

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

QPageSize lscs_spooler_device_cups::supported_page_size( const QString &pageName )
{
    QPageSize retVal;

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

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

QSize lscs_spooler_device_cups::minimum_physical_page_size()
{
    QSize retVal;

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

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

QSize lscs_spooler_device_cups::maximum_physical_page_size()
{
    QSize retVal;

    if ( m_cupsDest == nullptr )
    {
        return retVal;
    }

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

QList<int> lscs_spooler_device_cups::supported_resolutions()
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
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, uri().toUtf8().constData() );
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

QStringList lscs_spooler_device_cups::supported_media_sources()
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
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, uri().toUtf8().constData() );
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


QStringList lscs_spooler_device_cups::supported_duplex_modes()
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
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, uri().toUtf8().constData() );
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


QStringList lscs_spooler_device_cups::supported_color_modes()
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
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, uri().toUtf8().constData() );
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

int lscs_spooler_device_cups::queue_file( QString fullPathAndFileName,
        QStringList &options,
        int *deviceStatus,
        QString *errMsg )
{
    int retVal = -1;  // assume failure

    if ( nullptr == m_cupsDest )
    {
        if ( nullptr != errMsg )
        {
            *errMsg = tr( "cupsDest was null" );
        }

        return retVal;
    }

    if ( fullPathAndFileName.length() < 1 )
    {
        if ( nullptr != errMsg )
        {
            *errMsg = tr( "cupsDest was null" );
        }

        return retVal;
    }

    // now see if we can open the file
    QFile fil( fullPathAndFileName );

    if ( !fil.exists() )
    {
        if ( nullptr != errMsg )
        {
            QString str( "file not found %1" );
            str = QStringParser::formatArg( str, fullPathAndFileName );
            *errMsg = str;
        }

        return retVal;
    }

    if ( !fil.open( QIODevice::ReadOnly ) )
    {
        if ( nullptr != deviceStatus )
        {
            *deviceStatus = fil.error();
        }

        if ( nullptr != errMsg )
        {
            *errMsg = fil.errorString();
        }

        return retVal;
    }

    // getting here means we have a supposedly valid cups destination pointer
    // and we can open the file for reading.
    int numOptions = 0;
    cups_option_t *optns = NULL;

    for ( QString optnStr : options )
    {
        if ( optnStr.contains( '=' ) )
        {
            QStringList oStr = optnStr.split( '=' );
            numOptions = cupsAddOption( oStr[0].toUtf8().constData(), oStr[1].toUtf8().constData(),
                                        numOptions, &optns );
        }
        else
        {
            if ( nullptr != errMsg )
            {
                QString msg( "option |%1| not in |name=value| format" );
                msg = QStringParser::formatArg( msg, optnStr );
                *errMsg = msg;
                cupsFreeOptions( numOptions, optns );
                fil.close();
                return retVal;
            }
        }
    }

#if (CUPS_VERSION_MAJOR > 2)

    // create a job
    //
    int jobId = 0;

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );

    QFileInfo filInfo( fullPathAndFileName );


    // TODO:: use file name extension to guess better on the data format
    if ( cupsCreateDestJob( CUPS_HTTP_DEFAULT, dest, info, &jobId,
                            filInfo.filename().toUtf8().constData(),
                            CUPS_FORMAT_AUTO,
                            numOptions, optns ) != IPP_STATUS_OK )
    {
        if ( nullptr != deviceStatus )
        {
            *deviceStatus = cupsGetError();
        }

        if ( nullptr != errorMsg )
        {
            *errorMsg = QString::fromUtf8( cupsGetErrorString() );
        }

        cupsFreeOptions( numOptions, optn );
        cupsFreeDestInfo( info );
        cupsFreeDests( 1, dest );
        fil.close();
        return retVal;
    }

    // start the document
    //
    http_status_t stat = cupsStartDestDocument( CUPS_HTTP_DEFAULT,
                         dest, info,
                         filInfo.toUtf8().constData(),
                         numOptions, optns, true );

    if ( stat != HTTP_STATUS_CONTINUE )
    {
        if ( nullptr != deviceStatus )
        {
            *deviceStatus = cupsGetError();
        }

        if ( nullptr != errorMsg )
        {
            *errorMsg = QString::fromUtf8( cupsGetErrorString() );
        }

        // don't leave the job hanging on error
        cupsFinishDestDocument( CUPS_HTTP_DEFAULT, dest, info );
        cupsFreeOptions( numOptions, optn );
        cupsFreeDestInfo( info );
        cupsFreeDests( 1, dest );
        return retVal;
    }

    // send the data
    //
    //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    // With Cups 3.x API we can send a chunk at a time. Many battery powered
    // embedded systems have 512MB (or less) of RAM. Too many PC developers
    // think RAM is limitless and would try to load the entire file. A log
    // or other data file from many days of operation could easily exceed the
    // physical RAM size. Older DOT-MATRIX printers like the Star Micronics
    // NX-2420 Rainbow only had a 256 byte buffer to receive data.
    // Beagle board computers have a 24K serial buffer.
    // Some Zebra printers only make a 3MB buffer available for the user.
    // We will compromise and only do 8K at a time.
    //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    static const int CHUNK_SIZE = 8 * 1024;
    QByteArray chunk;
    bool keepSending = true;

    while ( keepSending )
    {
        chunk = fil.read( CHUNK_SIZE );

        if ( chunk.size() > 0 )
        {
            stat = cupsWriteRequestData( CUPS_HTTP_DEFAULT,
                                         chunk.consData(),
                                         chunk.size() );

            if ( stat != HTTP_STATUS_CONTINUE )
            {
                if ( nullptr != deviceStatus )
                {
                    *deviceStatus = cupsGetError();
                }

                if ( errorMsg.has_value() )
                {
                    errorMsg = QString::fromUtf8( cupsGetErrorString() );
                }

                // don't leave the job hanging on error
                fil.close();
                cupsFinishDestDocument( CUPS_HTTP_DEFAULT, dest, info );
                cupsFreeOptions( numOptions, optn );
                cupsFreeDestInfo( info );
                cupsFreeDests( 1, dest );
                return retVal;
            }

        }
        else
        {
            keepSending = false;
        }
    }

    cupsFinishDestDocument( CUPS_HTTP_DEFAULT, dest, info );
    cupsFreeOptions( numOptions, optn );
    cupsFreeDestInfo( info );
    cupsFreeDests( 1, dest );
    retVal = jobId;

    return retVal;
#else
    int rslt = cupsPrintFile2( CUPS_HTTP_DEFAULT, NULL, fullPathAndFileName.toUtf8().constData(),
                               fil.fileName().toUtf8().constData(), numOptions, optns );

    if ( nullptr != deviceStatus )
    {
        *deviceStatus = rslt;
    }

    if ( nullptr != errMsg )
    {
        *errMsg = QString::fromUtf8( cupsLastErrorString() );
    }

    if ( rslt > 0 )
    {
        retVal = rslt;
    }

#endif
    return retVal;
}
