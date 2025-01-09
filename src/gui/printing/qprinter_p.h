/***********************************************************************
*
* Copyright (c) 2012-2024 Barbara Geller
* Copyright (c) 2012-2024 Ansel Sermersheim
*
* Copyright (c) 2015 The Qt Company Ltd.
* Copyright (c) 2012-2016 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
*
* This file is part of CopperSpice.
*
* CopperSpice is free software. You can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://www.gnu.org/licenses/
*
***********************************************************************/

#ifndef QPRINTER_P_H
#define QPRINTER_P_H

#include <qglobal.h>

#ifndef LSCS_NO_PRINTER

#include <qprinter.h>
#include <qprinterinfo.h>
#include <qprintengine.h>
#include <qpointer.h>
#include <qset.h>

#include <limits.h>

class QPrintEngine;
class QPreviewPaintEngine;
class QPicture;

class QPrinterPrivate
{
    Q_DECLARE_PUBLIC( QPrinter )

public:
    QPrinterPrivate( QPrinter *printer )
        : printEngine( nullptr ), paintEngine( nullptr ), realPrintEngine( nullptr ), realPaintEngine( nullptr ),
#ifndef LSCS_NO_PRINTPREVIEWWIDGET
          previewEngine( nullptr ),
#endif
          q_ptr( printer ), printRange( PrinterPrintRange::AllPages ), use_default_engine( true ),
          validPrinter( false )
    {
    }

    ~QPrinterPrivate()
    {
    }

    void init( const QPrinterInfo &printer, PrinterMode mode );

    QPrinterInfo findValidPrinter( const QPrinterInfo &printer = QPrinterInfo() );
    void initEngines( PrinterFormat outputFormat, const QPrinterInfo &printer );
    void changeEngines( PrinterFormat outputFormat, const QPrinterInfo &printer );

#ifndef LSCS_NO_PRINTPREVIEWWIDGET
    QList<const QPicture *> previewPages() const;
    void setPreviewMode( bool );
#endif

    void setProperty( QPrintEngine::PrintEnginePropertyKey key, const QVariant &value );

    PrinterMode printerMode;
    PrinterFormat outputFormat;

    QPrintEngine *printEngine;
    QPaintEngine *paintEngine;

    QPrintEngine *realPrintEngine;
    QPaintEngine *realPaintEngine;

#ifndef LSCS_NO_PRINTPREVIEWWIDGET
    QPreviewPaintEngine *previewEngine;
#endif

    QPrinter *q_ptr;
    PrinterPrintRange printRange;

    uint use_default_engine : 1;
    uint had_default_engines : 1;
    uint validPrinter : 1;
    uint hasCustomPageMargins : 1;

    // Used to remember which properties have been manually set by the user.
    QSet<QPrintEngine::PrintEnginePropertyKey> m_properties;
};

#endif // LSCS_NO_PRINTER

#endif
