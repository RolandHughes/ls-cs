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

#ifndef LSCS_NO_PRINTER

/*! \file lscs_spooler_device.cpp
 *  \brief Base class implementation for lscs spooler devices - some of these will be printers
 *
 *  \details Provides common API requesting information from and sending
 *  work to physical output devices for spoolers. These devices will
 *  contain one or more lscs_spooler objects depending on how many file
 *  data formats are supported by said device.
 *
 * \todo add a global variable for cups http so runtime can use something other
 * than CUPS_HTTP_DEFAULT. Add support for Windows and Mac.
 */

#if !defined(LSCS_NO_CUPS)
#include <cups/cups.h>
#endif

#include <qfile.h>
#include <lscs_spooler_device.h>
#include <lscs_spooler_device_cups.h>


/*! Static method to obtain name of default spooler device for system */
QString lscs_spooler_device::default_device_name()
{
    QString retVal;

#if !defined(LSCS_NO_CUPS)
#if (CUPS_VERSION_MAJOR > 2)
    retVal = QString::fromUtf8( cupsGetDefault( CUPS_HTTP_DEFAULT ) );
#else
    retVal = QString::fromUtf8( cupsGetDefault2( CUPS_HTTP_DEFAULT ) );
#endif
#else
#error "Only Cups currently supported"
#endif

    return retVal;

}

/*! Static method to return list of available spooling devices */
QStringList lscs_spooler_device::available_devices()
{
    QStringList retVal;

#if !defined(LSCS_NO_CUPS)
    cups_dest_t *dests = nullptr;

    int numDests = 0;
#if (CUPS_VERSION_MAJOR > 2)
    numDests = cupsGetDests( CUPS_HTTP_DEFAULT, &dests );
#else
    numDests = cupsGetDests( &dests );
#endif

    for ( int jjj=0; jjj < numDests; jjj++ )
    {
        retVal << QString::fromUtf8( dests[jjj].name );
    }

    cupsFreeDests( numDests, dests );

#else
#error "Only Cups currently supported"
#endif

    return retVal;

}

/*! Accessor method to obtain current device name */
QString lscs_spooler_device::device_name()
{
    return m_deviceName;
}

/*! Accessor method to obtain current device description */
QString lscs_spooler_device::description()
{
    return m_description;
}

/*! Accessor method to obtain current device location */
QString lscs_spooler_device::location()
{
    return m_location;
}

/*! Accessor method to obtain curren device address */
QString lscs_spooler_device::uri()
{
    return m_uri;
}

/*! Assign a device name */
void lscs_spooler_device::set_device_name( QString deviceName )
{
    m_deviceName = deviceName;
}

/*! Assign device description */
void lscs_spooler_device::set_description( QString description )
{
    m_description = description;
}

/*! Assign device location */
void lscs_spooler_device::set_location( QString location )
{
    m_location = location;
}

/*! Assign device address */
void lscs_spooler_device::set_uri( QString uri )
{
    m_uri = uri;
}

/*! Static method to submit a file directly to a spooler device with options
 *
 * \details Convenience method for submitting files that are already in a
 * device supported format.
 *
 * \param string containing full path to and name of file to print
 * \param optional int reference to receive status/return value
 * \param optional string reference to receive error message
 *
 * \return positive integer is job number - negative means error encountered
 */
int lscs_spooler_device::queue_file_to_default_device( QString fullPathAndFileName,
        int *deviceStatus,
        QString *errorMsg
                                                     )
{
    int retVal = -1; // assume failure

#if !defined(LSCS_NO_CUPS)

#if (CUPS_VERSION_MAJOR > 2)
    // if name is NULL we will get default
    //
    cups_dest_t *dest = cupsGetNamedDest( CUPS_HTTP_DEFAULT, NULL, NULL );

    if ( nullptr == dests )
    {
        if ( nullptr != deviceStatus )
        {
            *deviceStatus = cupsGetError();
        }

        if ( nullptr != errorMsg )
        {
            *errorMsg = QString::fromUtf8( cupsGetErrorString() );
        }

        return retVal;
    }

    // now see if we can open the file
    QFile fil( fullPathAndFileName );

    if ( !fil.open( QIODevice::ReadOnly ) )
    {
        if ( deviceStatus.has_value() )
        {
            *deviceStatus = fil.error();
        }

        if ( errorMsg.has_value() )
        {
            errorMsg = fil.errorString();
        }

        return retVal;
    }


    // create a job
    //
    int jobId = 0;
    size_t numOptions = 0;
    cups_option_t *options = NULL;

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, dest );

    QFileInfo filInfo( fullPathAndFileName );

    // TODO:: use file name extension to guess better on the data format
    if ( cupsCreateDestJob( CUPS_HTTP_DEFAULT, dest, info, &jobId,
                            filInfo.filename().toUtf8().constData(),
                            CUPS_FORMAT_AUTO,
                            numOptions, options ) != IPP_STATUS_OK )
    {
        if ( nullptr != deviceStatus )
        {
            *deviceStatus = cupsGetError();
        }

        if ( nullptr != errorMsg )
        {
            *errorMsg = QString::fromUtf8( cupsGetErrorString() );
        }

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
                         numOptions, options, true );

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

                if ( nullptr != errorMsg )
                {
                    errorMsg = QString::fromUtf8( cupsGetErrorString() );
                }

                // don't leave the job hanging on error
                fil.close();
                cupsFinishDestDocument( CUPS_HTTP_DEFAULT, dest, info );
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
    cupsFreeDestInfo( info );
    cupsFreeDests( 1, dest );
    retVal = jobId;

    return retVal;
#else
    QFile fil( fullPathAndFileName );
    int rslt = cupsPrintFile2( CUPS_HTTP_DEFAULT, NULL, fullPathAndFileName.toUtf8().constData(),
                               fil.fileName().toUtf8().constData(), 0, nullptr );

    if ( nullptr != deviceStatus )
    {
        *deviceStatus = rslt;
    }

    if ( nullptr != errorMsg )
    {
        *errorMsg = QString::fromUtf8( cupsLastErrorString() );
    }

    if ( rslt > 0 )
    {
        retVal = rslt;
    }

#endif


#else
#error "Only Cups currently supported"
#endif

    return retVal;
}

/*! Factory method to create appropriate spooler device for platform
 *
 * \param name of device as recognized by system
 *
 * \return pointer to device or nullptr if error
 */
lscs_spooler_device *lscs_spooler_device::create_spooler_device( const QString &name )
{
#if !defined(LSCS_NO_CUPS)
    return ( new lscs_spooler_device_cups( name ) );
#else
#error "Only Cups currently supported"
#endif

    return nullptr;
}

#endif
