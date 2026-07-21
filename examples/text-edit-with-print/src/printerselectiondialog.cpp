//
// copyright (c) 2021-2025 Roland Hughes d/b/a Logikal Solutions
//
// The License.txt file describes the conditions under which this software may be distributed.
//
#include <qprinterinfo.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qdialogbuttonbox.h>
#include <qprinterinfo.h>

#include "printerselectiondialog.h"

PrinterSelectionDialog::PrinterSelectionDialog( QWidget *parent ) :
    QDialog( parent )
    , m_printerList( nullptr )
    , m_pagesLE( nullptr )
    , m_mainLayout( nullptr )
{
    QLabel *printerLbl = new QLabel( tr( "Available Printers:" ), this );

    m_printerList = new QListWidget( this );
    m_printerList->addItems( QPrinterInfo::availablePrinterNames() );

    QVBoxLayout *vb1 = new QVBoxLayout();
    vb1->addWidget( printerLbl, Qt::AlignHCenter );
    vb1->addWidget( m_printerList, Qt::AlignLeft );

    m_mainLayout = new QVBoxLayout();

#if defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_BSD4) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)
    QLabel *pagesLbl = new QLabel( tr( "Pages:" ), this );
    m_pagesLE = new QLineEdit();

    QHBoxLayout *hb1 = new QHBoxLayout();
    hb1->addWidget( pagesLbl, Qt::AlignLeft );
    hb1->addWidget( m_pagesLE, Qt::AlignRight );

    QLabel *instructionLbl = new QLabel( tr( "Leave blank for all pages" ), this );

    QVBoxLayout *vb2 = new QVBoxLayout();
    vb2->addLayout( hb1 );
    vb2->addWidget( instructionLbl, Qt::AlignCenter );

    QHBoxLayout *hb2 = new QHBoxLayout();
    hb2->addLayout( vb1 );
    hb2->addLayout( vb2 );

    m_mainLayout->addLayout( hb2 );
#else
    mainLayout->addLayout( vb1 );
#endif

    QDialogButtonBox *bb1 = new QDialogButtonBox( QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this );

    connect( bb1, &QDialogButtonBox::accepted, this, &QDialog::accept );
    connect( bb1, &QDialogButtonBox::rejected, this, &QDialog::reject );

    m_mainLayout->addWidget( bb1 );

    this->setLayout( m_mainLayout );
}

PrinterSelectionDialog::~PrinterSelectionDialog()
{
    if ( m_mainLayout )
    {
        // with all things properly parented, this will kill the children too.
        delete m_mainLayout;
        m_mainLayout = nullptr;
    }
}

QString PrinterSelectionDialog::getPrinterName()
{
    return m_printerList->currentItem()->text();
}

QString PrinterSelectionDialog::getPages()
{
    QString retVal;

#if defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_BSD4) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)
    retVal =  m_pagesLE->text();
#endif

    return retVal;

}