#include <QCoreApplication>
#include <QString>
#include <QStringParser>
#include <QTextStream>
#include <QTimer>
#include <QRegularExpression>
#include <cups/cups.h>
#include <limits.h>
#include "cups-experiment_build_info.h"

class SomeClass
{
    LSCS_GADGET( SomeClass )
public:
    QString name() { return m_name;}

private:
    QString m_name;
};

class Task : public QObject
{
    LSCS_OBJECT( Task )
public:
    Task( QObject *parent = 0 ) : QObject( parent ) {m_ptr = new SomeClass();}

    ~Task() { delete m_ptr;}

    LSCS_SLOT_1( Public, void run() )
    LSCS_SLOT_2( run )

    LSCS_SIGNAL_1( Public, void finished() )
    LSCS_SIGNAL_2( finished )

private:
    SomeClass *m_ptr;

};

int print_dest(void *cb_data, unsigned flags, cups_dest_t *dest)
{
    QTextStream out(stdout);
    
    const char *DEFAULT_RESOLUTION_NAME = "printer-resolution-default";
    
    if (cb_data != nullptr)
    {
        out << "cb_data was not null\n";
    }

    out << "flags: " << flags << endl;

    if (dest != nullptr)
    {
        out << "Dest Name: " << QString::fromUtf8( dest->name) << endl;
    
        if (dest->instance)
        {
            out << "Dest Instance: " << QString::fromUtf8( dest->instance) << endl;
        }
        
        QString uri = QString::fromUtf8( cupsGetOption("printer-uri-supported", dest->num_options, dest->options));
        out << "uri: " << uri << endl;
        
        cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, dest );
        
        //;;;;;;;;;;;;;;;;;;;;;;;;
        //   All of this just to get default resolution
        //;;;;;;;;;;;;;;;;;;;;;;;;
        char resource[8192];
        http_t *http = cupsConnectDest(dest, CUPS_DEST_FLAGS_DEVICE, 30000, NULL, resource, sizeof(resource), NULL, NULL);
        
        ipp_t *request = ippNewRequest(IPP_OP_GET_PRINTER_ATTRIBUTES);
        ippAddString(request, IPP_TAG_OPERATION, IPP_TAG_URI, "printer-uri", NULL, uri.toUtf8().constData());
        ipp_t *response = cupsDoRequest(http, request, resource);
        
        if (cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST)
        {
        	out << "\n IPP request failed: " << QString::fromUtf8(cupsLastErrorString()) << endl;
        }
        else
        {
        	ipp_attribute_t *attr;
        	if ((attr = ippFindAttribute(response, DEFAULT_RESOLUTION_NAME, IPP_TAG_RESOLUTION)) != NULL)
        	{
        		char value[4096];
        		ippAttributeString(attr, value, sizeof(value));
        		QString resl = QString::fromUtf8( value);
        		out << "  resolution printer-resolution-default: " << resl << endl;
        		QRegularExpression exp( "^(\\d+)");
        		QRegularExpressionMatch mtch = exp.match(resl);
        		if (mtch.hasMatch())
        		{
        			QString txt = mtch.capturedTexts( )[0];
        			out << "text value: " << txt <<"  integer value: " << txt.toInteger<int>() << endl;
        		}
        	}
        	
        }
        //;;;;;;;;;;;;;;;;;;;;;;;;
        //   End default resolution
        //;;;;;;;;;;;;;;;;;;;;;;;;
        
        
        out << "\tOption#\tName\tValue" << endl;
        for (int jjj=0; jjj < dest->num_options; jjj++)
        {
        	QString nameStr  = QString::fromUtf8(dest->options[jjj].name);
        	QString valueStr = QString::fromUtf8(dest->options[jjj].value); 
        	out << "\t" << jjj << "\t" << nameStr << "\t" << valueStr;
        	
        	if (nameStr == "printer-type")
        	{
        		cups_ptype_e printerTypeFlags = static_cast<cups_ptype_e>(valueStr.toInteger<uint>());
        		if (printerTypeFlags & CUPS_PRINTER_DEFAULT)
        		{
        			out << "      ***********  Default printer  ";
        		}
        		if (printerTypeFlags & CUPS_PRINTER_DUPLEX)
        		{
        			out << "      duplex  ";
        		}
        		if (printerTypeFlags & CUPS_PRINTER_COLOR)
        		{
        			out << "      color  ";
        		}
        		if (printerTypeFlags & CUPS_PRINTER_COPIES)
        		{
        			out << "      copies  ";
        		}
        		if (printerTypeFlags & CUPS_PRINTER_DISCOVERED)
        		{
        			out << "      discovered  ";
        		}
        		if (printerTypeFlags & CUPS_PRINTER_MFP)
        		{
        			out << "      MFP  ";
        		}
        		
        	}
        	
        	out << endl;
        }
        
        cups_size_t mediaSize;
        int mediaCount = cupsGetDestMediaCount(CUPS_HTTP_DEFAULT, dest, info, CUPS_MEDIA_FLAGS_DEFAULT);
        for (int jjj=0; jjj < mediaCount; jjj++)
        {
        	if (cupsGetDestMediaByIndex(CUPS_HTTP_DEFAULT, dest, info, jjj, CUPS_MEDIA_FLAGS_DEFAULT, &mediaSize))
        	{
        		QString str = QString::fromUtf8(mediaSize.media);
        		out << "Media: " << str << endl;
        		out << "\tWidth:" << mediaSize.width / 2540.0 << endl;
        		out << "\tLength:" << mediaSize.length / 2540.0 << endl;
        	}
        }
        
        cupsFreeDestInfo( info );
        //ippDelete( request);
        
    }
    

    out << endl;
    
    return (true);
}

void Task::run()
{
    // Do processing here

    QTextStream out(stdout);

    cupsEnumDests(CUPS_DEST_FLAGS_NONE, 1000, NULL, 0, 0, print_dest, NULL);

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
