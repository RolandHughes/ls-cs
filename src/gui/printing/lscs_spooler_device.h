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
#ifndef LSCS_SPOOLER_DEVICE_H
#define LSCS_SPOOLER_DEVICE_H

#ifndef LSCS_NO_PRINTER

#include <lscs_spooler.h>
#include <qpagesize.h>
#include <qstringlist.h>


/*! \file lscs_spooler_device.h
 *  \brief Base class for lscs_spooler devices - some of these will be printers
 *
 *  \details Provides common API requesting information from and sending
 *  work to physical output devices for spoolers. These devices will
 *  contain one or more lscs_spooler objects depending on how many file
 *  data formats are supported by said device.
 */

enum class LsCsSpoolerDeviceRange:int  { AllPages, Selection, PageRange, CurrentPage };
enum class LsCsSpoolerDeviceState:int  { Idle=3, Active, Stopped, Error };
enum class LsCsSpoolerDeviceDirection:int { Forward, Reverse };

class Q_GUI_EXPORT lscs_spooler_device : public QObject
{
    LSCS_OBJECT( lscs_spooler_device )

public:
    lscs_spooler_device() = default;
    virtual ~lscs_spooler_device() = default;

    static lscs_spooler_device *create_spooler_device( const QString &name );
    static QString  default_device_name();
    static QStringList available_devices();
    static int queue_file_to_default_device( QString fullPathAndFileName,
            int *deviceStatus = nullptr,
            QString *errorMsg = nullptr
                                           );

    virtual int queue_file( QString fullPathAndFileName,
                            QStringList &options,
                            int *deviceStatus = nullptr,
                            QString *errorMsg = nullptr
                          ) = 0;

    QString device_name();
    QString description();
    QString location();
    QString uri();

    void set_device_name( QString deviceName );
    void set_description( QString description );
    void set_location( QString location );
    void set_uri( QString uri );

    virtual bool is_valid() = 0;
    virtual bool is_default() = 0;
    virtual bool is_remote() = 0;
    virtual bool supports_multiple_copies() = 0;
    virtual bool supports_collate_copies() = 0;
    virtual bool supports_custom_page_sizes() = 0;

    virtual QPageSize default_page_size() = 0;
    virtual QList<QPageSize> supported_page_sizes() = 0;

    virtual QPageSize supported_page_size( const QString &pageName ) = 0;

    virtual QSize minimum_physical_page_size() = 0;
    virtual QSize maximum_physical_page_size() = 0;

    virtual int default_resolution() = 0;
    virtual QList<int> supported_resolutions() = 0;

    virtual QString last_known_error() = 0;

    virtual QString default_media_source() = 0;
    virtual QStringList supported_media_sources() = 0;

    virtual QString default_output_bin() = 0;
    virtual QStringList supported_output_bins() = 0;

    virtual QString default_duplex_mode() = 0;
    virtual QStringList supported_duplex_modes() = 0;

    virtual QString default_color_mode() = 0;
    virtual QStringList supported_color_modes() = 0;

    virtual void load_info() = 0;

protected:

private:

    QString         m_deviceName;   /*!< Name of device obtained from platform */
    QString         m_description;  /*!< Description of device obtained from platform */
    QString         m_location;     /*!< Human readable device location obtained from platform */
    QString         m_uri;          /*!< Address of device */

};


#endif // LSCS_NO_PRINTER

#endif
