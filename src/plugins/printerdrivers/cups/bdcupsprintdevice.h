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
 * We will maintain the _external_ interface but remove all ppd 
 * logic and configuration caching.
 */
class BdCupsPrintDevice:: public QPlatformPrintDevice
{
public:
    
    BdCupsPrintDevice();
    virtual ~BdCupsPrintDevice();

    explicit BdCupsPrintDevice( const QString &id);

    bool isValid() const override;
    bool isDefault() const override;

    QPrint::DeviceState state() const override;
    
    QPageSize defaultPageSize() const override;

    QMarginsF printableMargins( const QPageSize &pageSize, QPageLayout::Orientation orientation, int resolution) const override;

    int defaultResolutions() const override;

    QPrint::InputSlot defaultInputSlot() const override;

    QPrint::OutputBin defaultOutputBin() const override;

    QPrint::DuplexMode defaultDuplexMode() const override;

    QPrint::ColorMode defaultColorMode() const override;

protected:


private:
    void gatherPrinterInfo();
    QString printerOption( const QString &key ) const;
    cups_ptype_e printerTypeFlags() const;

    cups_dest_t *m_cupsDest;
    QByteArray m_cupsName;
    QByteArray m_cupsInstance;
    QByteArray m_uri;
};

#endif // BDCUPSPRINTDEVICE_H
