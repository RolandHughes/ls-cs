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
#ifndef BDSPOOLERDEVICE_H
#define BDSPOOLERDEVICE_H

#ifndef LSCS_NO_PRINTER

#include <bdspooler.h>
#include <qpagesize.h>
#include <qstringlist.h>


/*! \file bdspoolerdevice.h
 *  \brief Base class for BdSpooler devices - some of these will be printers
 *
 *  \details Provides common API requesting information from and sending
 *  work to physical output devices for spoolers. These devices will
 *  contain one or more BdSpooler objects depending on how many file
 *  data formats are supported by said device.
 */

enum class BdSpoolerDeviceRange:int  { AllPages, Selection, PageRange, CurrentPage };
enum class BdSpoolerDeviceState:int  { Idle=3, Active, Stopped, Error };
enum class BdSpoolerDeviceDirection:int { Forward, Reverse };

class Q_GUI_EXPORT BdSpoolerDevice : public QObject
{
    LSCS_OBJECT( BdSpoolerDevice )

public:
    BdSpoolerDevice() = default;
    virtual ~BdSpoolerDevice() = default;

    static BdSpoolerDevice *createSpoolerDevice( const QString &name );
    static QString  defaultDeviceName();
    static QStringList availableDevices();
    static int queueFileToDefaultDevice( QString fullPathAndFileName,
                                         int *deviceStatus = nullptr,
                                         QString *errorMsg = nullptr
                                       );

    virtual int queueFile( QString fullPathAndFileName,
                           QStringList &options,
                           int *deviceStatus = nullptr,
                           QString *errorMsg = nullptr
                         ) = 0;

    QString deviceName();
    QString description();
    QString location();
    QString uri();

    void setDeviceName( QString deviceName );
    void setDescription( QString description );
    void setLocation( QString location );
    void setUri( QString uri );

    virtual bool isValid() = 0;
    virtual bool isDefault() = 0;
    virtual bool isRemote() = 0;
    virtual bool supportsMultipleCopies() = 0;
    virtual bool supportsCollateCopies() = 0;
    virtual bool supportsCustomPageSizes() = 0;

    virtual QPageSize defaultPageSize() = 0;
    virtual QList<QPageSize> supportedPageSizes() = 0;

    virtual QPageSize supportedPageSize( const QString &pageName ) = 0;

    virtual QSize minimumPhysicalPageSize() = 0;
    virtual QSize maximumPhysicalPageSize() = 0;

    virtual int defaultResolution() = 0;
    virtual QList<int> supportedResolutions() = 0;

    virtual QString lastKnownError() = 0;

    virtual QString defaultMediaSource() = 0;
    virtual QStringList supportedMediaSources() = 0;

    virtual QString defaultOutputBin() = 0;
    virtual QStringList supportedOutputBins() = 0;

    virtual QString defaultDuplexMode() = 0;
    virtual QStringList supportedDuplexModes() = 0;

    virtual QString defaultColorMode() = 0;
    virtual QStringList supportedColorModes() = 0;

    virtual void loadInfo() = 0;

protected:

private:

    QString         m_deviceName;   /*!< Name of device obtained from platform */
    QString         m_description;  /*!< Description of device obtained from platform */
    QString         m_location;     /*!< Human readable device location obtained from platform */
    QString         m_uri;          /*!< Address of device */

};


#endif // LSCS_NO_PRINTER

#endif
