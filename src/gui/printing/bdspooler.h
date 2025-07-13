/*;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright (c) 2024-2025 Roland Hughes d.b.a Logikal Solutions
;;
;; This file is part of Ls-Cs.
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
#ifndef BDSPOOLER_H
#define BDSPOOLER_H

/*! \file bdspooler.h
 *  \brief Spooling interface for printing and standalone devices like milling machines
 *
 * \details In the late 1980s and early 1990s under DOS and GUI-DOS
 * (Windows); (Windows wasn't legally an operating system until
 * Windows NT despite packaging and marketing claims. It was a task
 * switching GUI on top of DOS like PresentationManager was on top of
 * OS/2); the platforms were not multi-process multi-user systems. DOS
 * had a TSR (Terminate and Stay Resident) program to support print
 * spooling to a printer so the PC didn't lock up until the printer was
 * done.
 *
 * Early UNIX also fell into this as it was designed to run a phone
 * switching device yet allow remote maintenance. Later it got batch
 * and print queues but initially was quite spartan compared to Midrange
 * and Mainframe computers.
 *
 * We will skip discussing Netware here.
 *
 * DOS and GUI-DOS did not have built-in printer drivers. Most printers
 * were direct connected to the PC either via LPT (parallel - most
 * common) or COM (serial - slower but supported greater distances when
 * using slower BAUD rates.) Each application had to include drivers for
 * the limited number of printers they chose to support. As a result
 * most applications didn't include the drivers and expected a printer
 * to support raw ASCII along with a couple of escape sequences. Most
 * printer manufacturers provided DIP switches to configure printer
 * emulation mode. Normally IBM Proprinter and Epson LQ were the most
 * often emulated which made life easier. Not easy because emulation
 * was always off just a bit, but easier.
 *
 * Printing technology involved the application opening the port,
 * generating up to one line of content, writing it to port, waiting for
 * response, and repeating for next line. Printers had very little
 * memory. If you had a raw text file you could send it to the printer
 * via the print command and the print spooler TSR would do the one
 * line at a time for you.
 *
 * Early inkjet printers operated much like the DOT-MATRIX printers
 * that came before them. Higher end DOT-MATRIX and low end HP Deskjet
 * printers would allow fonts to be downloaded to them. Previously
 * you chose one of the possibly 3 built-in fonts via DIP switch. Later
 * models got buttons that would let you switch between manually before
 * printing.
 *
 * Laser printers tried to change everything. Most supported only
 * Postscript. All of the required a full page of data sent in a single
 * chunk. Many were scattered about on proprietary networks while
 * others were direct connected via LPT ports. Because there was no
 * TCP/IP standard, most desktop operating systems had to have a
 * proprietary printer driver _and_ had to create a fake serial port
 * that mapped to the printer on the proprietary network.
 *
 * Printing technology from a software perspective, especially for
 * Cups, halted there. Operating systems on the lesser platforms
 * managed to finally get print queues and other spooling technology
 * but the programming libraries, especially cross platform were still
 * stuck at sending one page at a time.
 *
 * The Cups 3.x API forced all Linux and cross platform libraries to
 * jettison the page at a time printing logic. The new flow of sending
 * an entire file to a destination goes well beyond printing. Indeed
 * it supports sending faxes, the manufacture of small items all the
 * way up to 3D printed buildings. Even milling and other shop floor
 * machines that receive a set of instructions for a task they will
 * execute repeatedly are supported by this architecture. It provides
 * a clean interface for the sending of such content.
 *
 * Printing for most modern operating systems, especially now that we
 * have wireless printers that can come and go on the network, follows
 * the following pattern.
 *
 * \arg generate a file of apropriate content
 * \arg connect to device
 * \arg transmit file and options receiving optional job number
 * \arg possibly establish a callback function to be notified of issues or completion
 * \arg disconnect from device
 */

#include <qstring.h>

/*! \enum BdSpoolerType
 *  \brief indicates type of spooler
 */
enum class BdSpoolerType
{
    None, Text, Raw, Pdf, Postscript
};

/*! \class BdSpooler
 *  \brief Base spooler class for creating temporary file to queue to device.
 *
 *  \details Mostly virtual base class for all spoolers. Establishes the
 *   common interface.
 */
class Q_GUI_EXPORT BdSpooler : public QObject
{
    LSCS_OBJECT( BdSpooler )


public:
    explicit BdSpooler( const BdSpoolerType spoolerType, const QString fileDest = "" );
    BdSpooler();

    virtual ~BdSpooler() = default;


    BdSpoolerType spoolerType();

private:

    BdSpoolerType m_spoolerType;
};

#endif  // BDSPOOLER_H
