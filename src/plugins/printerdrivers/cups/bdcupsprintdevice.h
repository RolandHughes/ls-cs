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
#ifndef BDCUPSPRINTDEVICE_H
#define BDCUPSPRINTDEVICE_H

#include <qbytearray.h>
#include <qhash.h>
#include <qmargins.h>
#include <qplatform_printdevice.h>

#include <cups/cups.h>


/* CUPS legacy interface consisted of functions to mine ppd files
 * (Postscript Printer Description). Given this interface was
 * created for computers available in early 2000, it was limited
 * by Pentium III as the fastest (or close enough) desktop CPU on the market.
 * There were still a lot of 386 and 486 computers in use.
 *
 * Disk technology was equally slow. Lots of ST-506 and ESDI drives
 * being used in production systems. Even the SCSI drives available
 * for personal computers were both small and incredibly slow.
 *
 * Most application frameworks and applications of the day used the
 * ppd functions early on when creating a printer software device.
 * They gathered all of the information and saved it in memory. This
 * created a lot of problems. Most printer developers would not create
 * ppd files unless they were targetting a business and then they would
 * only create files for the higher end printers.
 *
 * Most end users would "try whatever file happened to exist" in their Linux
 * distro. Lots of Dot Matrix printers had DIP switches to emulate IBM
 * Pro-Printer or specific Epson models. Emulation was never perfect.
 *
 * Volunteers would create generic files as best they could. Generally
 * this meant it worked for some of the printers some of the time.
 *
 * Adding insult to injury, high end printing systems were dynamically
 * configurable. The number of drawers could change throughout the day;
 * collaters could come and go. 3D printers really threw a monkey
 * wrench into it because the really good ones have interchangeable
 * heads and spools. It may be printing with plastic in the morning
 * then some kind of metal or even concrete in the afternoon.
 *
 * We will support only the 3.x ipp api and will always request
 * information directly from Cups.
 *
 * Application can be up for days/weeks/months at a time. A duplex or
 * collate unit could fail and get replaced or simply be added over
 * that time. The system will not have restarted, but the printer
 * will have changed capabilities.
 */
typedef struct
{
    int numDests;
    cups_dest_t *dests;
} bd_dest_list_t;

class BdCupsPrintDevice : public QPlatformPrintDevice
{
public:

    BdCupsPrintDevice();
    BdCupsPrintDevice( const QString &name );
    virtual ~BdCupsPrintDevice();

    explicit BdCupsPrintDevice( const BdPrintDestination &id );

    static const size_t RESOURCE_SIZE = 40000;
    static const size_t VALUE_SIZE = 4096;

    bool isValid();
    bool isDefault();
    bool isRemote();
    bool supportsMultipleCopies();
    bool supportsCollateCopies();
    bool supportsCustomPageSizes();

    PrinterState state();


    QPageSize defaultPageSize();
    QList<QPageSize> supportedPageSizes();

    QPageSize supportedPageSize( const QString &pageName );

    QSize minimumPhysicalPageSize();
    QSize maximumPhysicalPageSize();

    QMarginsF printableMargins( const QPageSize &pageSize, QPageLayout::Orientation orientation, int resolution );

    int defaultResolution();
    QList<int> supportedResolutions();

    QString lastPrintError();

    QString defaultMediaSource();
    QStringList supportedMediaSources();

    QString defaultOutputBin();
    QStringList supportedOutputBins();

    QString defaultDuplexMode();
    QStringList supportedDuplexModes();

    QString defaultColorMode();
    QStringList supportedColorModes();

protected:

private:
    void loadInfo();
    QString printerOption( const QString &key );
    cups_ptype_e printerTypeFlags();

    cups_dest_t *m_cupsDest;
    char        m_resource[ RESOURCE_SIZE];
    char        m_value[ VALUE_SIZE];

};

#endif // BDCUPSPRINTDEVICE_H
