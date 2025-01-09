/***********************************************************************
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

#ifndef QPRINTER_H
#define QPRINTER_H

#include <qstring.h>
#include <qscopedpointer.h>
#include <qpagedpaintdevice.h>
#include <qpagelayout.h>

#ifndef LSCS_NO_PRINTER

class QPrinterPrivate;
class QPaintEngine;
class QPrintEngine;
class QPrinterInfo;
class QPageSize;
class QPageMargins;

enum class PrinterPrintRange:int  { AllPages, Selection, PageRange, CurrentPage };
enum class PrinterPageOrder:int   { FirstPageFirst, LastPageFirst };
enum class PrinterMode:int        { ScreenResolution, PrinterResolution, HighResolution };
enum class PrinterState:int       { Idle=3, Active, Stopped, Error };
enum class PrinterFormat:int      { Native, Pdf, Text };
    // TODO:: Add support for Text so we can print to dot matrix
    //        counting pages by both lines and formfeeds.


class Q_GUI_EXPORT QPrinter : public QPagedPaintDevice
{
    Q_DECLARE_PRIVATE( QPrinter )

public:
    using Orientation = QPageLayout::Orientation;
    using Unit = QPageSize::Unit;


    static const QString ONE_SIDED;
    static const QString TWO_SIDED_LONG_EDGE;
    static const QString TWO_SIDED_SHORT_EDGE;
    static const QString MEDIA_SOURCE_AUTO;
    
    explicit QPrinter( PrinterMode mode = PrinterMode::ScreenResolution );
    explicit QPrinter( const QPrinterInfo &printer, PrinterMode mode = PrinterMode::ScreenResolution );

    QPrinter( const QPrinter & ) = delete;
    QPrinter &operator=( const QPrinter & ) = delete;

    ~QPrinter();

    int devType() const override;

    void setOutputFormat( PrinterFormat outputFormat );
    PrinterFormat outputFormat();

    void setPrinterName( const QString &name );
    QString printerName() const;

    bool isValid();

    void setOutputFileName( const QString &fileName );
    QString outputFileName();

    void setPrintProgram( const QString &command );
    QString printProgram();

    void setDocName( const QString &name );
    QString docName();

    void setCreator( const QString &creator );
    QString creator();

    void setMargins( const QMarginsF &margins ) override;
    QMarginsF margins( QPageSize::Unit unit ) const;

    bool setPageLayout( const QPageLayout &newPageLayout ) override;
    QPageLayout pageLayout() const override;

    bool setPageOrientation( QPageLayout::Orientation orientation ) override;
    void setOrientation( Orientation orientation );
    Orientation orientation();

    bool setPageMargins( const QMarginsF &margins, QPageSize::Unit units ) override;
    bool setPageMargins( const QMarginsF &margins ) override;

    bool setPageSize( const QPageSize &pageSize ) override;
    void setPageSize( QPageSize::PageSizeId sizeId ) override;
    QPageSize::PageSizeId pageSize() const;

    void setPageSizeMM( const QSizeF &size ) override;

    void setPaperSize( QPageSize::PageSizeId paperSize );
    void setPaperSize( const QSizeF &paperSize, Unit unit );
    QPageSize::PageSizeId paperSize();
    QSizeF paperSize( Unit unit );

    void setPaperName( const QString &paperName );
    QString paperName() const;

    void setPrintRange( PrinterPrintRange range );
    PrinterPrintRange printRange();

    void setPageOrder( PrinterPageOrder pageOrder );
    PrinterPageOrder pageOrder();

    void setResolution( int dpi );
    int resolution() const;

    void setColorMode( QString colorMode );
    QString colorMode();

    void setCollateCopies( bool collate );
    bool collateCopies();

    void setFullPage( bool fullPage );
    bool fullPage();

    void setNumCopies( int numCopies );
    int numCopies();

    int actualNumCopies();

    void setCopyCount( int count );
    int copyCount();
    bool supportsMultipleCopies();

    void setPaperSource( QString source );
    QString paperSource();

    void setDuplex( QString duplexModeStr );
    QString duplex();

    QList<int> supportedResolutions();

#ifdef Q_OS_WIN
    QList<PaperSource> supportedPaperSources();
#endif

    void setFontEmbeddingEnabled( bool enable );
    bool fontEmbeddingEnabled();

    bool doubleSidedPrinting();

    void setWinPageSize( int pageSize );
    int winPageSize();

    QRect paperRect();
    QRect pageRect();
    QRectF paperRect( Unit unit );
    QRectF pageRect( Unit unit );

    QString printerSelectionOption();
    void setPrinterSelectionOption( const QString &option );

    bool newPage() override;
    bool abort();

    PrinterState printerState();

    QPaintEngine *paintEngine() const override;
    QPrintEngine *printEngine() const;

    void setFromTo( int fromPage, int toPage );
    int fromPage() const;
    int toPage() const;

protected:
    int metric( PaintDeviceMetric ) const override;
    void setEngines( QPrintEngine *printEngine, QPaintEngine *paintEngine );

private:
    QScopedPointer<QPrinterPrivate> d_ptr;

    friend class QPrintDialogPrivate;
    friend class QAbstractPrintDialog;
    friend class QAbstractPrintDialogPrivate;
    friend class QPrintPreviewWidgetPrivate;
    friend class QTextDocument;
    friend class QPageSetupWidget;
};

#endif // LSCS_NO_PRINTER

#endif
