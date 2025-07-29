#include <QString>
#include <QStringParser>
#include <QTextStream>
#include <QTimer>
#include <QRegularExpression>
#include <cups/cups.h>
#include <limits.h>
#include <qstringlist.h>
#include "cups-experiment_build_info.h"
#include <iostream>
#include <string>
#include <QFile>

class SomeClass
{
    LSCS_GADGET ( SomeClass )
public:
    QString name()
    {
        return m_name;
    }

private:
    QString m_name;
};

class Task: public QObject
{
    LSCS_OBJECT ( Task )
public:
    Task( QObject *parent = 0 ) :
        QObject( parent )
    {
        m_ptr = new SomeClass();
    }

    ~Task()
    {
        delete m_ptr;
    }

    LSCS_SLOT_1( Public, void run() )
    LSCS_SLOT_2( run )

    LSCS_SIGNAL_1( Public, void finished() )
    LSCS_SIGNAL_2( finished )

private:
    SomeClass *m_ptr;

};

int print_dest( void *cb_data, unsigned flags, cups_dest_t *dest )
{
    QTextStream out( stdout );

    const char *DEFAULT_RESOLUTION_NAME = "printer-resolution-default";

    if ( cb_data != nullptr )
    {
        out << "cb_data was not null\n";
    }

    out << "flags: " << flags << endl;

    if ( dest != nullptr )
    {
        out << "Dest Name: " << QString::fromUtf8( dest->name ) << endl;

        if ( dest->instance )
        {
            out << "Dest Instance: " << QString::fromUtf8( dest->instance ) << endl;
        }

        QString uri = QString::fromUtf8( cupsGetOption( "printer-uri-supported", dest->num_options, dest->options ) );
        out << "uri: " << uri << endl;

        cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, dest );

        static const char *const requested_attributes[] =
        {
            "all", "printer-description", "job-template", "printer-resolution-supported", "print-quality-supported",
            "media-source-supported", "output-bin-supported", "sides-supported ", "print-color-mode-supported",
            "media-col-database", "orientation-requested-supported"
        };

        char resource[40000];
        const char *name = nullptr;
        char value[4096];
        http_t *http = cupsConnectDest( dest, CUPS_DEST_FLAGS_DEVICE, 30000, NULL, resource, sizeof( resource ), NULL, NULL );

        ipp_t *request = ippNewRequest( IPP_OP_GET_PRINTER_ATTRIBUTES );
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, "printer-uri", NULL, uri.toUtf8().constData() );
        ippAddStrings( request, IPP_TAG_OPERATION, IPP_TAG_KEYWORD, "requested-attributes",
                       ( int ) ( sizeof( requested_attributes ) / sizeof( requested_attributes[0] ) ), NULL, requested_attributes );
        ipp_t *response = cupsDoRequest( http, request, resource );

        if ( cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST )
        {
            out << "\n IPP request failed: " << QString::fromUtf8( cupsLastErrorString() ) << endl;
        }
        else
        {
            ipp_attribute_t *attr = nullptr;
            ipp_attribute_t *defAttr = nullptr;
            QRegularExpression exp( "^(\\d+)" );

            if ( ( attr = ippFindAttribute( response, DEFAULT_RESOLUTION_NAME, IPP_TAG_RESOLUTION ) ) != NULL )
            {
                ippAttributeString( attr, value, sizeof( value ) );
                QString resl = QString::fromUtf8( value );
                out << "  resolution printer-resolution-default: " << resl << endl;
                QRegularExpressionMatch mtch = exp.match( resl );

                if ( mtch.hasMatch() )
                {
                    QString txt = mtch.capturedTexts()[0];
                    out << "text value: " << txt << "  integer value: " << txt.toInteger<int>() << endl;
                }
            }
            else
            {
                out << "unable to get attribute for " << DEFAULT_RESOLUTION_NAME << endl;
            }

            if ( ( attr = ippFindAttribute( response, "printer-resolution-supported", IPP_TAG_RESOLUTION ) ) != NULL )
            {
                ippAttributeString( attr, value, sizeof( value ) );
                QString str = QString::fromUtf8( value );
                QStringList lst = str.split( "," );

                for ( QString txt : lst )
                {
                    QRegularExpressionMatch mtch2 = exp.match( txt );

                    if ( mtch2.hasMatch() )
                    {
                        QString dpi = mtch2.capturedTexts()[0];
                        out << "\t DPI   " << dpi << endl;
                    }
                }

            }
            else
            {
                out << "unable to get attribute for printer-resolution-supported" << endl;
            }

            if ( ( defAttr = ippFindAttribute( response, "media-col-default", IPP_TAG_BEGIN_COLLECTION ) ) != NULL )
            {
                if ( ( attr = ippFindAttribute( ippGetCollection( defAttr, 0 ), "media-source", IPP_TAG_ZERO ) ) != NULL )
                {
                    name = ippGetName( attr );
                    ippAttributeString( attr, value, sizeof( value ) );
                    out << endl << "\t==========  media-source: " << QString::fromUtf8( name ) << "  default: "
                        << QString::fromUtf8( value ) << endl << endl;
                }

            }

            if ( ( attr = ippFindAttribute( response, "orientation-requested-supported", IPP_TAG_ZERO ) ) != NULL )
            {
                ippAttributeString( attr, value, sizeof( value ) );
                QString str = QString::fromUtf8( value );
                QStringList lst = str.split( "," );

                out << "\t !!!!!!! orientation: " << endl;

                for ( QString orientStr : lst )
                {
                    out << "\t                      " << orientStr << endl;
                }
            }

            else
            {
                out << "unable to locate media-source-supported" << endl;
            }

            if ( ( attr = ippFindAttribute( response, "media-source-supported", IPP_TAG_ZERO ) ) != NULL )
            {
                int srcCnt = ippGetCount( attr );

                for ( int yyy = 0; yyy < srcCnt; yyy++ )
                {

                    out << "\t ;;;;;;;;;;;;;media source: " << yyy << "  name: "
                        << QString::fromUtf8( ippGetString( attr, yyy, NULL ) ) << endl;
                }
            }

            else
            {
                out << "unable to locate media-source-supported" << endl;
            }

            if ( ( attr = ippFindAttribute( response, "output-bin-supported", IPP_TAG_ZERO ) ) != NULL )
            {
                int binCount = ippGetCount( attr );

                for ( int uuu = 0; uuu < binCount; uuu++ )
                {
                    out << "\t ++++++++++++output bin: " << uuu << "  name: " << QString::fromUtf8( ippGetString( attr, uuu, NULL ) )
                        << endl;
                }
            }
            else
            {
                out << "++++++++++++++ unable to locate output-bin-supported" << endl;
            }

            if ( ( attr = ippFindAttribute( response, "output-bin-default", IPP_TAG_ZERO ) ) != NULL )
            {
                name = ippGetName( attr );
                ippAttributeString( attr, value, sizeof( value ) );
                out << endl << "\t``````````  output-bin-default: " << QString::fromUtf8( name ) << "   value: "
                    << QString::fromUtf8( value ) << endl;
            }

            if ( ( attr = ippFindAttribute( response, "sides-supported", IPP_TAG_ZERO ) ) != NULL )
            {
                int sidesCount = ippGetCount( attr );

                for ( int sss = 0; sss < sidesCount; sss++ )
                {
                    out << "\t ********side: " << sss << "  name: " << QString::fromUtf8( ippGetString( attr, sss, NULL ) ) << endl;
                }
            }

            if ( ( attr = ippFindAttribute( response, "print-color-mode-supported", IPP_TAG_ZERO ) ) != NULL )
            {
                int colorCount = ippGetCount( attr );

                for ( int ccc = 0; ccc < colorCount; ccc++ )
                {
                    out << "\t ********color: " << ccc << "  name: " << QString::fromUtf8( ippGetString( attr, ccc, NULL ) ) << endl;
                }
            }

            if ( ( attr = ippFindAttribute( response, CUPS_PRINT_QUALITY_SUPPORTED, IPP_TAG_ZERO ) ) != NULL )
            {
                out << "xxxxxxxxxxxx found CUPS_PRINT_QUALITY_SUPPORTED" << endl;
                int cnt = ippGetCount( attr );

                for ( int jjj = 0; jjj < cnt; jjj++ )
                {
                    int eee = ippGetInteger( attr, jjj );
                    out << "jjj: " << jjj << "  integer: " << eee << "   string version: "
                        << QString::fromUtf8( ippEnumString( CUPS_PRINT_QUALITY_SUPPORTED, eee ) ) << endl;
                }

            }
            else
            {
                out << "unable to get attribute for CUPS_PRINT_QUALITY_SUPPORTED  IPP_TAG_ZERO" << endl;
            }

            if ( ( attr = cupsFindDestDefault( CUPS_HTTP_DEFAULT, dest, info, CUPS_PRINT_COLOR_MODE ) ) != NULL )
            {
                name = ippGetName( attr );
                ippAttributeString( attr, value, sizeof( value ) );
                out << endl << "\t---------- CUPS_PRINT_COLOR_MODE   name: " << QString::fromUtf8( name ) << "  default: "
                    << QString::fromUtf8( value ) << endl;
            }

            if ( ( attr = cupsFindDestDefault( CUPS_HTTP_DEFAULT, dest, info, CUPS_SIDES ) ) != NULL )
            {
                name = ippGetName( attr );
                ippAttributeString( attr, value, sizeof( value ) );
                out << endl << "\t........... CUPS_SIDES   name: " << QString::fromUtf8( name ) << "  default: "
                    << QString::fromUtf8( value ) << endl;
            }

#if 0
            int mediaCount = cupsGetDestMediaCount( CUPS_HTTP_DEFAULT, dest, info, CUPS_MEDIA_FLAGS_DEFAULT );
            out << endl << endl << "\tSupported Media:" << endl;
            out << "Name\t    Width    Length    bottom    left    right    top\n";

            for ( int jjj = 0; jjj < mediaCount; jjj++ )
            {
                cups_size_t media;

                if ( cupsGetDestMediaByIndex( CUPS_HTTP_DEFAULT, dest, info, jjj, CUPS_MEDIA_FLAGS_DEFAULT, &media ) )
                {
                    QString mediaName = QString::fromUtf8( media.media );
                    out << mediaName << "\t" << media.width << "    " << media.length << "    " << media.bottom << "    "
                        << media.left << "    " << media.right << "    " << media.top << endl;
                }

            }


            out << "*****************\n";
            out << "*****************\n";
            out << "*****************\n";

            for ( ipp_attribute_t *attr = ippFirstAttribute( response ); attr; attr = ippNextAttribute( response ) )
            {
                name = ippGetName( attr );

                if ( name )
                {
                    ippAttributeString( attr, value, sizeof( value ) );
                    int tagValue = ippGetGroupTag( attr );
                    out << QString::fromUtf8( name ) << " = " << QString::fromUtf8( value ) << "     tag: " << tagValue << endl;
                }
            }

            out << "*****************\n";
            out << "*****************\n";
            out << "*****************\n";
#endif
        }

        out << "\tOption#\tName\tValue" << endl;

        for ( int jjj = 0; jjj < dest->num_options; jjj++ )
        {
            QString nameStr = QString::fromUtf8( dest->options[jjj].name );
            QString valueStr = QString::fromUtf8( dest->options[jjj].value );
            out << "\t" << jjj << "\t" << nameStr << "\t" << valueStr;

            if ( nameStr == "printer-type" )
            {
                cups_ptype_e printerTypeFlags = static_cast<cups_ptype_e>( valueStr.toInteger<uint>() );

                if ( printerTypeFlags & CUPS_PRINTER_DEFAULT )
                {
                    out << "      ***********  Default printer  ";
                }

                if ( printerTypeFlags & CUPS_PRINTER_DUPLEX )
                {
                    out << "      duplex  ";
                }

                if ( printerTypeFlags & CUPS_PRINTER_COLOR )
                {
                    out << "      color  ";
                }

                if ( printerTypeFlags & CUPS_PRINTER_COPIES )
                {
                    out << "      copies  ";
                }

                if ( printerTypeFlags & CUPS_PRINTER_DISCOVERED )
                {
                    out << "      discovered  ";
                }

                if ( printerTypeFlags & CUPS_PRINTER_MFP )
                {
                    out << "      MFP  ";
                }

            }

            out << endl;
        }

#if 0
        cups_size_t mediaSize;
        int mediaCount = cupsGetDestMediaCount( CUPS_HTTP_DEFAULT, dest, info, CUPS_MEDIA_FLAGS_DEFAULT );

        for ( int jjj=0; jjj < mediaCount; jjj++ )
        {
            if ( cupsGetDestMediaByIndex( CUPS_HTTP_DEFAULT, dest, info, jjj, CUPS_MEDIA_FLAGS_DEFAULT, &mediaSize ) )
            {
                QString str = QString::fromUtf8( mediaSize.media );
                out << "Media: " << str << endl;
                out << "\tWidth:" << mediaSize.width / 2540.0 << endl;
                out << "\tLength:" << mediaSize.length / 2540.0 << endl;
            }
        }

#endif
        httpClose( http );
        cupsFreeDestInfo( info );
        //ippDelete( request);

    }

    out << endl;

    return ( true );
}

void Task::run()
{
// Do processing here

    QTextStream out( stdout );

    cupsEnumDests( CUPS_DEST_FLAGS_NONE, 1000, NULL, 0, 0, print_dest, NULL );

    cups_dest_t *dests = nullptr;
    size_t destCnt = cupsGetDests( &dests );  //cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

    out << "================================================================================" << endl << endl;
    out << "destCnt: " << destCnt << endl;

    for ( size_t jjj = 0; jjj < destCnt; jjj++ )
    {
        cups_dest_t *workDest = &dests[jjj];

        if ( workDest != nullptr )
        {
            cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, workDest );
            out << QString::fromUtf8( workDest->name ) << endl;
            QString uri = QString::fromUtf8( cupsGetOption( "printer-uri-supported", workDest->num_options, workDest->options ) );
            out << "uri: " << uri << endl << endl;

            out << "\tOption#\tName\tValue" << endl;

            for ( int jjj = 0; jjj < workDest->num_options; jjj++ )
            {
                QString nameStr = QString::fromUtf8( workDest->options[jjj].name );
                QString valueStr = QString::fromUtf8( workDest->options[jjj].value );
                out << "\t" << jjj << "\t" << nameStr << "\t" << valueStr << endl;

            }

            static const char *const requested_attributes[] =
            {
                "all", "printer-description", "job-template", "printer-resolution-supported", "print-quality-supported",
                "media-source-supported", "output-bin-supported", "sides-supported ", "print-color-mode-supported",
                "media-col-database", "orientation-requested-supported"
            };

            char resource[40000];
            http_t *http = cupsConnectDest( workDest, CUPS_DEST_FLAGS_DEVICE, 30000, NULL, resource, sizeof( resource ), NULL, NULL );

            ipp_t *request = ippNewRequest( IPP_OP_GET_PRINTER_ATTRIBUTES );
            ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, "printer-uri", NULL, uri.toUtf8().constData() );
            ippAddStrings( request, IPP_TAG_OPERATION, IPP_TAG_KEYWORD, "requested-attributes",
                           ( int ) ( sizeof( requested_attributes ) / sizeof( requested_attributes[0] ) ), NULL, requested_attributes );
            ipp_t *response = cupsDoRequest( http, request, resource );


            ipp_attribute_t *attr = nullptr;

            if ( cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST )
            {
                out << "\n IPP request failed: " << QString::fromUtf8( cupsLastErrorString() ) << endl;
            }
            else
            {
                if ( ( attr = ippFindAttribute( response, CUPS_PRINT_QUALITY_SUPPORTED, IPP_TAG_ZERO ) ) != NULL )
                {
                    out << "xxxxxxxxxxxx found CUPS_PRINT_QUALITY_SUPPORTED" << endl;
                    int cnt = ippGetCount( attr );

                    for ( int jjj = 0; jjj < cnt; jjj++ )
                    {
                        int eee = ippGetInteger( attr, jjj );
                        out << "jjj: " << jjj << "  integer: " << eee << "   string version: "
                            << QString::fromUtf8( ippEnumString( CUPS_PRINT_QUALITY_SUPPORTED, eee ) ) << endl;
                    }

                }
                else
                {
                    out << "unable to get attribute for CUPS_PRINT_QUALITY_SUPPORTED  IPP_TAG_ZERO" << endl;
                }

            }

            httpClose( http );

            cupsFreeDestInfo( info );
        }
    }

    cupsFreeDests( destCnt, dests );

    destCnt = cupsGetDests2( CUPS_HTTP_DEFAULT, &dests );

    out << "================================================================================" << endl << endl;
    out << endl << endl << "getDest2 destCnt: " << destCnt << endl;

    for ( size_t jjj = 0; jjj < destCnt; jjj++ )
    {
        cups_dest_t *workDest = &dests[jjj];

        if ( workDest != nullptr )
        {
            cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, workDest );
            out << QString::fromUtf8( workDest->name ) << endl;
            QString uri = QString::fromUtf8( cupsGetOption( "printer-uri-supported", workDest->num_options, workDest->options ) );
            out << "uri: " << uri << endl << endl;
            out << "\tOption#\tName\tValue" << endl;

            for ( int jjj = 0; jjj < workDest->num_options; jjj++ )
            {
                QString nameStr = QString::fromUtf8( workDest->options[jjj].name );
                QString valueStr = QString::fromUtf8( workDest->options[jjj].value );
                out << "\t" << jjj << "\t" << nameStr << "\t" << valueStr << endl;

            }

            static const char *const requested_attributes[] =
            {
                "all", "printer-description", "job-template", "printer-resolution-supported", "print-quality-supported",
                "media-source-supported", "output-bin-supported", "sides-supported ", "print-color-mode-supported",
                "media-col-database", "orientation-requested-supported"
            };

            char resource[40000];
            http_t *http = cupsConnectDest( workDest, CUPS_DEST_FLAGS_DEVICE, 30000, NULL, resource, sizeof( resource ), NULL, NULL );

            ipp_t *request = ippNewRequest( IPP_OP_GET_PRINTER_ATTRIBUTES );
            ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, "printer-uri", NULL, uri.toUtf8().constData() );
            ippAddStrings( request, IPP_TAG_OPERATION, IPP_TAG_KEYWORD, "requested-attributes",
                           ( int ) ( sizeof( requested_attributes ) / sizeof( requested_attributes[0] ) ), NULL, requested_attributes );
            ipp_t *response = cupsDoRequest( http, request, resource );

            if ( cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST )
            {
                out << "\n IPP request failed: " << QString::fromUtf8( cupsLastErrorString() ) << endl;
            }
            else
            {
                ipp_attribute_t *attr = nullptr;

                if ( ( attr = ippFindAttribute( response, CUPS_PRINT_QUALITY_SUPPORTED, IPP_TAG_ZERO ) ) != NULL )
                {
                    out << "xxxxxxxxxxxx found CUPS_PRINT_QUALITY_SUPPORTED" << endl;
                    int cnt = ippGetCount( attr );

                    for ( int jjj = 0; jjj < cnt; jjj++ )
                    {
                        int eee = ippGetInteger( attr, jjj );
                        out << "jjj: " << jjj << "  integer: " << eee << "   string version: "
                            << QString::fromUtf8( ippEnumString( CUPS_PRINT_QUALITY_SUPPORTED, eee ) ) << endl;
                    }

                }
                else
                {
                    out << "unable to get attribute for CUPS_PRINT_QUALITY_SUPPORTED  IPP_TAG_ZERO" << endl;
                }

            }

            httpClose( http );

            cupsFreeDestInfo( info );
        }
    }

    cupsFreeDests( destCnt, dests );
    bool doneFlg = false;
    std::string filePath;

    while ( !doneFlg )
    {
        std::cout << "\n\n\n\n\nPlease enter full path and name of file to print on default printer or exit to quit: ";
        std::cin >> filePath;
        QString str( QString::fromStdString( filePath ) );

        if ( str.compare( QString( "exit" ), Qt::CaseInsensitive ) == 0 )
        {
            doneFlg = true;
            continue;
        }

        QFile file( str );

        if ( !file.exists() )
        {
            std::cout << "\n\n*************** file not found\n\n";
            continue;
        }

        std::string titleStr = "Test print of " + filePath;
        int jobNo = cupsPrintFile( cupsGetDefault(), filePath.c_str(), titleStr.c_str(), 0, NULL );
        std::cout << "Submitted job: " << jobNo << std::endl;
        doneFlg = true;
    }

    emit finished();
}

int main( int argc, char *argv[] )
{
    QCoreApplication a( argc, argv );

// parent task to application so it will be cleaned up
//
    Task *task = new Task( &a );

// make sure we know when things are done
//
    QObject::connect( task, SIGNAL( finished() ), &a, SLOT( quit() ) );

// Timer won't run until event loop starts
//
    QTimer::singleShot( 0, task, SLOT( run() ) );

// Go for it!
    return a.exec();
}
