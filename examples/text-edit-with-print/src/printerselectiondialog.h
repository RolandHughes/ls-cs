//
// copyright (c) 2021-2025 Roland Hughes d/b/a Logikal Solutions
//
// The License.txt file describes the conditions under which this software may be distributed.
//
#ifndef PRINTERSELECTIONDIALOG_H
#define PRINTERSELECTIONDIALOG_H

#include <qdialog.h>
#include <qstring.h>

class QListWidget;
class QLineEdit;
class QVBoxLayout;

class PrinterSelectionDialog : public QDialog
{
    LSCS_OBJECT( PrinterSelectionDialog )

public:
    explicit PrinterSelectionDialog( QWidget *parent = nullptr );
    ~PrinterSelectionDialog();

    QString getPrinterName();
    QString getPages();

private:
    QListWidget *m_printerList;
    QLineEdit   *m_pagesLE;
    QVBoxLayout *m_mainLayout;
};

#endif // PRINTERSELECTIONDIALOG_H