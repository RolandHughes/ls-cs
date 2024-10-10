#include "mainwindow.h"

#include <QStandardPaths>
#include <QSettings>
#include <QLabel>
#include <QVBoxLayout>
#include <QMovie>
#include <QByteArray>
#include <QPushButton>
#include <QColorDialog>
#include <QStandardPaths>
#include <QPlainTextEdit>
#include <QDir>
#include <QPrintDialog>
#include <QPrinter>

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent )
{
    m_hello             = new QLabel( "Hello World!" );
    m_layout            = new QVBoxLayout();
    m_widget            = new QWidget();
    m_printBtn          = new QPushButton( "Print" );
    m_textEdit          = new QPlainTextEdit();

    m_textEdit->setMinimumHeight( 600);
    m_textEdit->setMinimumWidth( 450);

    m_layout->addWidget( m_hello );
    m_layout->addWidget( m_printBtn );
    m_layout->addWidget( m_textEdit );

    m_widget->setLayout( m_layout );

    connect( m_printBtn, &QPushButton::clicked, this, &MainWindow::printSomething );

    setCentralWidget( m_widget );
}

MainWindow::~MainWindow()
{
    delete m_widget;
    delete m_layout;
}

void MainWindow::printSomething()
{
   QPrinter printer(QPrinter::HighResolution);

   QPrintDialog dialog(&printer, this);
   dialog.setWindowTitle("Print Document");

   if (dialog.exec() == QDialog::Accepted) {
      qDebug() << "accepted\n";
   }
}