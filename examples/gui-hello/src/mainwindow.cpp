#include <QString>
#include <QLabel>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QStringParser>

#include "mainwindow.h"
#include "gui-hello_build_info.h"

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent )
{
    m_hello             = new QLabel( "Hello World!" );
    m_layout            = new QVBoxLayout();
    m_widget            = new QWidget();
    m_textEdit          = new QTextEdit();

    m_textEdit->setMinimumHeight( 600 );
    m_textEdit->setMinimumWidth( 450 );
    m_textEdit->setFontFamily( "Monospaced" );
    m_textEdit->setFontPointSize( 12 );

    m_layout->addWidget( m_hello );
    m_layout->addWidget( m_textEdit );

    m_widget->setLayout( m_layout );

    populateTextEdit();

    setCentralWidget( m_widget );
}

MainWindow::~MainWindow()
{
    delete m_widget;
}

void MainWindow::populateTextEdit()
{
    // CopperSpice deliberately took out automatic conversion from char *
    // that was a massive mistake.
    QString txt = "<b>Version:</b> %1";
    txt = txt.formatArg( QString::fromUtf8( versionString ) );
    m_textEdit->append( txt );

    txt = QString( "<b>Build Date:</b> %1\n" ).formatArg( QString::fromUtf8( buildDate ) );
    m_textEdit->append( txt );

    m_textEdit->setTextBackgroundColor( Qt::lightGray );
    m_textEdit->append( QString( "<b>Sizes on your machine:</b>" ) );

    m_textEdit->setTextColor( Qt::darkRed );
    txt = QString( "     unsigned char      %1" ).formatArg( sizeof( unsigned char ) );
    m_textEdit->append( txt );

    m_textEdit->setTextColor( Qt::darkGreen );
    txt = QString( "     qint8              %1" ).formatArg( sizeof( qint8 ) );
    m_textEdit->append( txt );

    m_textEdit->setTextColor( Qt::darkRed );
    txt = QString( "     qint16             %1" ).formatArg( sizeof( qint16 ) );
    m_textEdit->append( txt );

    m_textEdit->setTextColor( Qt::darkGreen );
    txt = QString( "     qint32              %1" ).formatArg( sizeof( qint32 ) );
    m_textEdit->append( txt );

    m_textEdit->setTextColor( Qt::darkRed );
    txt = QString( "     qint64             %1" ).formatArg( sizeof( qint64 ) );
    m_textEdit->append( txt );

    m_textEdit->setTextColor( Qt::darkGreen );
    txt = QString( "     short int          %1" ).formatArg( sizeof( short int ) );
    m_textEdit->append( txt );

    m_textEdit->setTextColor( Qt::darkRed );
    txt = QString( "     int                %1" ).formatArg( sizeof( int ) );
    m_textEdit->append( txt );

    m_textEdit->setTextColor( Qt::darkGreen );
    txt = QString( "     long               %1" ).formatArg( sizeof( long ) );
    m_textEdit->append( txt );

    m_textEdit->setTextColor( Qt::darkRed );
    txt = QString( "     long long          %1" ).formatArg( sizeof( long long ) );
    m_textEdit->append( txt );

    m_textEdit->setTextColor( Qt::darkGreen );
    txt = QString( "     float              %1" ).formatArg( sizeof( float ) );
    m_textEdit->append( txt );

    m_textEdit->setTextColor( Qt::darkRed );
    txt = QString( "     double             %1" ).formatArg( sizeof( double ) );
    m_textEdit->append( txt );

    m_textEdit->setTextColor( Qt::darkGreen );
    txt = QString( "     long double        %1" ).formatArg( sizeof( long double ) );
    m_textEdit->append( txt );

    m_textEdit->setTextBackgroundColor( Qt::black );
    m_textEdit->setTextColor( Qt::yellow );

    // each append is a paragraph so you don't need the \n until you want an extra line
    m_textEdit->append( QString( "\n\nNext we will do some regular expression matching." ) );
    m_textEdit->append( QString( "This section can be useful if you want to try out some" ) );
    m_textEdit->append( QString( "regular expressions for your own programs.\n\n" ) );
    m_textEdit->append( QString( "str1:   MOVE =fred 1234 thru 5678 TO =Ethyl 5" ) );
    m_textEdit->append( QString( "str2:   MOVE 1:5 TO 108" ) );
    m_textEdit->append( QString( "str3:   MOVE =JANE 543 THRU 643 TO .\n" ) );
    // extra slashes due to string escape sequences
    m_textEdit->append(
        QString( "rangeExpression( \"(\\\\d+ THRU \\\\d+)|(\\\\d+:\\\\d+)\", QPatternOption::CaseInsensitiveOption )\n" ) );

    // Some regular expression experiments.
    //
    QString str1 = "MOVE =fred 1234 thru 5678 TO =Ethyl 5";
    QString str2 = "MOVE 1:5 TO 108";
    QString str3 = "MOVE =JANE 543 THRU 643 TO .";

    QRegularExpression rangeExpression( "(\\d+ THRU \\d+)|(\\d+:\\d+)", QPatternOption::CaseInsensitiveOption );
    QRegularExpressionMatch match1 = rangeExpression.match( str1 );
    QRegularExpressionMatch match2 = rangeExpression.match( str2 );
    QRegularExpressionMatch match3 = rangeExpression.match( str3 );

    if ( match1.hasMatch() )
    {
        m_textEdit->append( QString( "<b>match1:</b>" ) );

        for ( QString str : match1.capturedTexts() )
        {
            txt = QString( "    %1" ).formatArg( str );
            m_textEdit->append( txt );
        }
    }

    if ( match2.hasMatch() )
    {
        m_textEdit->append( QString( "<b>match2:</b>" ) );

        for ( QString str : match2.capturedTexts() )
        {
            txt = QString( "    %1" ).formatArg( str );
            m_textEdit->append( txt );
        }
    }

    if ( match3.hasMatch() )
    {
        m_textEdit->append( QString( "<b>match3:</b>" ) );

        for ( QString str : match3.capturedTexts() )
        {
            txt = QString( "    %1" ).formatArg( str );
            m_textEdit->append( txt );
        }
    }

}
