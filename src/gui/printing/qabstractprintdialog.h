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

#ifndef QABSTRACTPRINTDIALOG_H
#define QABSTRACTPRINTDIALOG_H

#include <qdialog.h>
#include <qprinter.h>

#ifndef LSCS_NO_PRINTER

class QAbstractPrintDialogPrivate;

enum class PDOption : int
    {
        None                    = 0x0000, // obsolete
        PrintToFile             = 0x0001,
        PrintSelection          = 0x0002,
        PrintPageRange          = 0x0004,
        PrintShowPageSize       = 0x0008,
        PrintCollateCopies      = 0x0010,
        DontUseSheet            = 0x0020,
        PrintCurrentPage        = 0x0040
    };

    using PDOptions = QFlags<PDOption>;
Q_DECLARE_OPERATORS_FOR_FLAGS( PDOptions )
//GUI_LSCS_ENUM( PrintDialogOptions )


class Q_GUI_EXPORT QAbstractPrintDialog : public QDialog
{
    GUI_LSCS_OBJECT( QAbstractPrintDialog )

public:


#ifndef LSCS_NO_PRINTDIALOG
    explicit QAbstractPrintDialog( QPrinter *printer, QWidget *parent = nullptr );

    QAbstractPrintDialog( const QAbstractPrintDialog & ) = delete;
    QAbstractPrintDialog &operator=( const QAbstractPrintDialog & ) = delete;

    ~QAbstractPrintDialog();

    int exec() override = 0;

    // obsolete
    void addEnabledOption( PDOptions option );
    void setEnabledOptions( PDOptions options );
    PDOptions enabledOptions() const;
    bool isOptionEnabled( PDOptions option ) const;

    void setOptionTabs( const QList<QWidget *> &tabs );

    void setPrintRange( PrinterPrintRange range );
    PrinterPrintRange printRange() const;

    void setMinMax( int min, int max );
    int minPage() const;
    int maxPage() const;

    void setFromTo( int fromPage, int toPage );
    int fromPage() const;
    int toPage() const;

    QPrinter *printer() const;

protected:
    QAbstractPrintDialog( QAbstractPrintDialogPrivate &ptr, QPrinter *printer, QWidget *parent = nullptr );

private:
    Q_DECLARE_PRIVATE( QAbstractPrintDialog )

#endif // LSCS_NO_PRINTDIALOG
};


#endif // LSCS_NO_PRINTER

#endif
