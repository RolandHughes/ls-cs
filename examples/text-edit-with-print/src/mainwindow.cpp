//
// copyright (c) 2021-2025 Roland Hughes d/b/a Logikal Solutions
//
// The License.txt file describes the conditions under which this software may be distributed.
//

#include "mainwindow.h"

#include <qvboxlayout.h>
#include <qwidget.h>
#include <qmenu.h>
#include <qstandardpaths.h>
#include <qmessagebox.h>
#include <qmenubar.h>
#include <qfiledialog.h>
#include <qcloseevent.h>
#include <qtabwidget.h>
#include <qfileinfo.h>
#include <qtabbar.h>
#include <qregularexpression.h>
#include <qstringparser.h>
#include <qprintdialog.h>
#include <qprinter.h>
#include <qprinterinfo.h>
#include <qtemporaryfile.h>

#include "myeditwidget.h"
#include "printerselectiondialog.h"

/* The URI associated with the destination; if not set, this destination was discovered
 * but is not yet setup as a local printer.
 */
static const char *URI_OPTION = "printer-uri-supported";

/* The human-readable location of the destination such as "Lab 4". */
static const char *LOCATION_OPTION = "printer-location";

/* The human-readable make and model of the destination such as "ExampleCorp LaserPrinter 4000 Series". */
static const char *MAKE_AND_MODEL_OPTION = "printer-make-and-model";

/* Printer URI request */
static const char *PRINTER_URI_REQUEST = "printer-uri";

/* list of requested attributes being requested */
static const char *ATTRIBUTE_LIST_REQUEST = "requested-attributes";


/*  When creating a MainWindow for a tabbed text editor you have two
 *  main schools of thought:
 *
 *  1) Every tab must have a file
 *  2) Every tab is just a buffer that may or may not have a file.
 *
 *  If you are going to be a purist when pursuing school of thought one,
 *  you cannot create the tab widget until the user opens or creates a new
 *  file. You also have to get rid of the tabbed widget when they close the
 *  last file. This can cause some odd UI behavior.
 *
 *  Many of today's editors follow school of thought two. This means when a
 *  user choose Save, the MainWindow must go down the SaveAs path if the
 *  buffer does not have a file name and path.
 *
 *  The trade-off between the two views really stands out when it comes to
 *  making persistent buffers. Your main window or some other class must
 *  always create a unique buffer name. It must be unique within the current
 *  run and the cache directory on disk.
 *
 */

/* use this to have QPrinterInfo dump information about printer */
#define TEST_YOUR_PLATFORM 1

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent )
{
#if defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_BSD4) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)
    m_cupsDest = nullptr;
#endif
    setMinimumHeight( 600 );
    setMinimumWidth( 450 );

    createMenus();

    m_tabWidget  = new QTabWidget();
    m_layout     = new QVBoxLayout();

    // This puts an X in the corner of the tab so the user can one click close it
    //
    m_tabWidget->setTabsClosable( true );

    // You need to have a target slot for the signal
    //
    connect( m_tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::removeTab );

    // When filename doesn't fit you want it to read file... not ...txt
    //
    m_tabWidget->setElideMode( Qt::ElideRight );

    // Allow user to move tabs
    //
    m_tabWidget->tabBar()->setMovable( true );

    // If the user moves a tab they must want it current
    //
    m_tabWidget->tabBar()->setChangeCurrentOnDrag( true );

    // Change the tab shape and location
    //
    m_tabWidget->tabBar()->setShape( QTabBar::TriangularNorth );


    addEmptyTab();

    m_layout->addWidget( m_tabWidget );

    QWidget *widget = new QWidget();
    widget->setLayout( m_layout );
    setCentralWidget( widget );

}

MainWindow::~MainWindow()
{

    delete m_tabWidget;
    delete m_layout;

#if defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_BSD4) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)

    if ( m_cupsDest )
    {
        delete m_cupsDest;
        m_cupsDest = nullptr;
    }

#endif
    m_tabWidget = nullptr;
    m_layout    = nullptr;

}

void MainWindow::createMenus()
{
    m_menuFile         = menuBar()->addMenu( tr( "&File" ) );
    m_actionNewFile    = m_menuFile->addAction( tr( "New File" ) );
    m_actionNewBuffer  = m_menuFile->addAction( tr( "New Buffer" ) );
    m_actionOpen       = m_menuFile->addAction( tr( "Open" ) );
    m_actionClose      = m_menuFile->addAction( tr( "Close" ) );
    m_actionSave       = m_menuFile->addAction( tr( "Save" ) );
    m_actionSaveAs     = m_menuFile->addAction( tr( "SaveAs" ) );
    m_actionSep5       = m_menuFile->addSeparator();
    m_actionPrint      = m_menuFile->addAction( tr( "Print" ) );
#if defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_BSD4) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)
    m_actionSep6       = m_menuFile->addSeparator();
    m_actionTestAPI    = m_menuFile->addAction( tr( "Test API" ) );
#endif
    m_actionSep7       = m_menuFile->addSeparator();
    m_actionExit       = m_menuFile->addAction( tr( "Exit" ) );

    m_menuHelp         = menuBar()->addMenu( tr( "Help" ) );
    m_actionAbout      = m_menuHelp->addAction( tr( "About" ) );

    // Tooltips
    //
    m_actionNewFile->setToolTip( tr( "Create New File" ) );
    m_actionNewBuffer->setToolTip( tr( "Create New Buffer" ) );
    m_actionOpen->setToolTip( tr( "Open Existing File" ) );
    m_actionClose->setToolTip( tr( "Close File" ) );
    m_actionSave->setToolTip( tr( "Save File" ) );
    m_actionSaveAs->setToolTip( tr( "Save File As" ) );
    m_actionPrint->setToolTip( tr( "Print current tab content" ) );
#if defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_BSD4) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)
    m_actionTestAPI->setToolTip( tr( "Test CUPS 3.x API" ) );
#endif
    m_actionExit->setToolTip( tr( "Exit program" ) );

    m_actionAbout->setToolTip( tr( "Show About Box" ) );


    // Menu connections
    //
    connect( m_actionNewBuffer, &QAction::triggered, this,
             [this]()
    {
        if ( m_tabWidget )
        {
            addEmptyTab();
        }
    } );

    connect( m_actionNewFile, &QAction::triggered, this,
             [this]()
    {
        if ( m_tabWidget )
        {
            // re-use current empty tab
            //
            MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );

            if ( !ptr->isEmpty() )
            {
                // current tab was not empty, just add one.
                //
                // TODO:: add method to search for empty tab to use and create one if
                //        empty tab does not exist.
                addEmptyTab();
                ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );
            }

            if ( ptr )
            {
                ptr->newDoc();
                updateTabText();
            }
        }
    } );


    connect( m_actionOpen, &QAction::triggered, this,
             [this]()
    {
        if ( m_tabWidget )
        {
            // re-use current empty tab
            //
            MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );

            if ( !ptr->isEmpty() )
            {
                // current tab was not empty, just add one.
                //
                // TODO:: add method to search for empty tab to use and create one if
                //        empty tab does not exist.
                addEmptyTab();
                ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );
            }

            if ( ptr )
            {
                ptr->openDoc();
                updateTabText();
            }
        }
    } );

    connect( m_actionClose, &QAction::triggered, this,
             [this]()
    {
        if ( m_tabWidget )
        {
            MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );

            if ( ptr )
            {
                ptr->closeDoc();
            }
        }
    } );

    connect( m_actionSave, &QAction::triggered, this,
             [this]()
    {
        if ( m_tabWidget )
        {
            MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );

            if ( ptr )
            {
                ptr->save();
            }
        }
    } );

    connect( m_actionSaveAs, &QAction::triggered, this,
             [this]()
    {
        if ( m_tabWidget )
        {
            MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );

            if ( ptr )
            {
                ptr->saveAs();
                updateTabText();
            }
        }
    } );

    connect( m_actionPrint, &QAction::triggered,
             this, [this]()
    {
        if ( m_tabWidget )
        {
            printCurrent();
        }
    } );

#if defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_BSD4) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)
    connect( m_actionTestAPI, &QAction::triggered, this, [this]()
    {
        testAPI();
    } );
#endif

    connect( m_actionExit, &QAction::triggered,
             this, [this]()
    {
        close();
    } );

    connect( m_actionAbout, &QAction::triggered, this, &MainWindow::about );

}

void MainWindow::about()
{
    QString txt = "This example builds on the simple text editor adding the ability \n"
                  "to print either via the command line to a chosen printer or \n"
                  "a graphical print dialog\n";

    QMessageBox::about( this, "text-edit-with-print", txt );
}


void MainWindow::closeEvent( QCloseEvent *event )
{
    // Ignore the event to prevent window closure
    event->ignore();

    bool userCancelled = false;

    if ( m_tabWidget )
    {
        /*
         * Need to call the closeDoc() method for each valid edit Widget
         * so user can be prompted about unsaved changes.
         */
        while ( ( m_tabWidget->currentIndex() > -1 ) && ( !userCancelled ) )
        {
            MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );

            if ( ptr )
            {
                userCancelled = !ptr->closeDoc();

                if ( !userCancelled )
                {
                    m_tabWidget->removeTab( m_tabWidget->currentIndex() );
                }
            }
        }
    }

    if ( !userCancelled )
    {
        event->accept();
    }
}

void MainWindow::addEmptyTab()
{
    if ( m_tabWidget )
    {
        m_tabWidget->setCurrentIndex( m_tabWidget->addTab( new MyEditWidget(), uniqueName() ) );

        MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );

        if ( ptr )
        {
            connect( ptr, &MyEditWidget::newTabForFile,        this, &MainWindow::newTabForFile );
            connect( ptr, &MyEditWidget::newTabForText,        this, &MainWindow::newTabForText );
            connect( ptr, &MyEditWidget::updateTabText,        this, &MainWindow::updateTabText );
            connect( ptr, &MyEditWidget::updateDirtyIndicator, this, &MainWindow::updateIsDirty );
        }
    }
}

void MainWindow::removeTab( int index )
{
    if ( m_tabWidget )
    {
        MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->widget( index ) );

        if ( ptr )
        {
            ptr->closeDoc();

            if ( m_tabWidget->count() > 1 )
            {
                m_tabWidget->removeTab( index );
            }
        }
    }
}

QString MainWindow::uniqueName()
{
    static const QString BASE_NAME = "New_Buffer_";
    static const QString NAME_FORMAT = BASE_NAME + "%1";
    QString retVal = QStringParser::formatArg( NAME_FORMAT, 1 );

    /*
     * Putting this hear as a place holder.
     * You need to spin through all of the tab names and if you are
     * creating a cache directory, all of those file names to
     * determine what the next highest unique name is.
     */
    if ( m_tabWidget )
    {
        QVector<QString> names;
        QRegularExpression exp( BASE_NAME + "([0-9]+)" );

        for ( int jjj=0; jjj<m_tabWidget->tabBar()->count(); jjj++ )
        {
            QString txt = m_tabWidget->tabBar()->tabText( jjj );

            if ( txt.contains( exp ) )
            {
                qDebug() << "appending: " << txt << "\n";
                names.append( txt );
            }
        }

        if ( names.count() > 0 )
        {
            std::sort( names.begin(), names.end() );
            QString lastStr = names.takeLast();
            QRegularExpressionMatch match = exp.match( lastStr );

            if ( match.hasMatch() )
            {
                int lastNumber = QStringParser::toInteger<int>( match.captured( 1 ) );
                lastNumber++;
                qDebug() << "new Number: " << lastNumber;
                retVal = QStringParser::formatArg( NAME_FORMAT, lastNumber );
            }

        }
    }

    return retVal;
}

void MainWindow::newTabForFile( QString fileName )
{
    if ( m_tabWidget )
    {

        addEmptyTab();
        MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );

        if ( ptr )
        {
            ptr->loadFile( fileName );

            if ( ptr->currentFile().length() > 0 )
            {
                QString txt = QFileInfo( ptr->currentFile() ).fileName();
                updateTabText();
            }
        }
    }
}

void MainWindow::newTabForText( QString text )
{
    if ( m_tabWidget )
    {
        addEmptyTab();
        MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );

        if ( ptr )
        {
            ptr->setText( text );
        }
    }

}

void MainWindow::updateTabText()
{
    MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );

    if ( ptr->currentFile().length() > 0 )
    {
        QString txt = QFileInfo( ptr->currentFile() ).fileName();
        m_tabWidget->setTabText( m_tabWidget->currentIndex(), txt );
    }
}

void MainWindow::updateIsDirty()
{
    QPalette palette;

    for ( int jjj=0; jjj < m_tabWidget->count(); ++jjj )
    {
        MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->widget( jjj ) );

        if ( ptr && ptr->isDirty() )
        {
            m_tabWidget->tabBar()->setTabTextColor( jjj, Qt::red );
        }
        else
        {
            m_tabWidget->tabBar()->setTabTextColor( jjj, palette.color( QPalette::Foreground ) );
        }
    }
}

void MainWindow::printCurrent()
{
    QString titleStr = tr( "Printing Method" );
    QString questionStr = tr( "Command line for specific printer or traditional print dialog?" );
    QString btn0Str = tr( "Command" );
    QString btn1Str = tr( "Dialog" );
    QString btn2Str = tr( "Cancel" );

    int btnInt = QMessageBox::question( this, titleStr, questionStr, btn0Str, btn1Str, btn2Str, 0, 2 );

    switch ( btnInt )
    {
        case 0:
            commandLineDialog();
            break;

        case 1:
            guiDialog();
            break;

        case 2:
        default:
            break;
    }
}

void MainWindow::commandLineDialog()
{
    // cheap hack to allow command line printing of text files
    //
    PrinterSelectionDialog *dlg = new PrinterSelectionDialog( this );
    int rslt = dlg->exec();

    if ( QDialog::Accepted != rslt )
    {
        delete dlg;
        return;
    }

    QString printerName = dlg->getPrinterName();
    QString pages;
    QString duplexStr;
    QString cmd;

    // put contents of widget into temporary file
    QTemporaryFile file;
    MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );

    if ( nullptr != ptr )
    {
        if ( file.open() )
        {
            qDebug() << "text being written: " << ptr->text().toUtf8() << endl;
            file.write( ptr->text().toUtf8() );
            file.flush();
            file.close();
        }
    }

    // bail if did not successfully create temporary file.
    if ( file.fileName().length() < 1 )
    {
        delete dlg;
        return;
    }

    QPrinterInfo info = QPrinterInfo::printerInfo( printerName );

#if defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_BSD4) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)

    QStringList duplexList = info.supportedDuplexModes();

    QString str1( "two-sided-long-edge" );

    if ( duplexList.contains( str1, Qt::CaseInsensitive ) )
    {
        qDebug() << "duplex found";
        duplexStr = "-o sides=two-sided-long-edge";
    }

    if ( dlg->getPages().length() > 0 )
    {
        pages = QString( "-P %1" );
        pages = QStringParser::formatArg( pages, dlg->getPages() );
    }

    cmd = QString( "lp -d %1 -o cpi=10 -o fit-to-page %2 %3 %4" );
    cmd = QStringParser::formatArg( cmd, printerName );
    cmd = QStringParser::formatArg( cmd, duplexStr );
    cmd = QStringParser::formatArg( cmd, pages );
    cmd = QStringParser::formatArg( cmd, file.fileName() );

#elif defined(Q_OS_WIN) || defined(Q_OS_WIN32) || defined(Q_OS_WIN64)

    cmd = QString( "PRINT /D:%1 %2" );
    cmd = QStringParser::formatArg( printerName );
    cmd = QStringParser::formatArg( file.fileName() );

#endif

    system( cmd.toStdString().c_str() );

    delete dlg;

}

void MainWindow::guiDialog()
{
    qDebug() << "################ creating QPrinterInfo for default printer";
    QPrinterInfo info( QPrinterInfo::defaultPrinter() );
    qDebug() << "################ finished creating QPrinterInfo for default printer" << endl;

#if TEST_YOUR_PLATFORM
    qDebug() << "printerName:           " << info.printerName();
    qDebug() << "description:           " << info.description();
    qDebug() << "location:              " << info.location();
    qDebug() << "make and model:        " << info.makeAndModel();
    qDebug() << "isNull:                " << info.isNull();
    qDebug() << "isDefault:             " << info.isDefault();
    qDebug() << "isRemote:              " << info.isRemote();
    qDebug() << "state:                 " << static_cast<int>( info.state() );
    qDebug() << "default resolution:    " << info.defaultResolution();
    qDebug() << "supported resolutions: " << info.supportedResolutions() << endl;
    qDebug() << "defaultDuplexMode:     " << info.defaultDuplexMode();
    qDebug() << "supportedDuplexModes:  " << info.supportedDuplexModes() << endl;
    qDebug() << "defaultColorMode:      " << info.defaultColorMode();
    qDebug() << "supportedColorModes:   " << info.supportedColorModes() << endl;
    qDebug() << "default PageSize:      " << info.defaultPageSize();
    qDebug() << "supported Page sizes:  " << info.supportedPageSizes();
    qDebug() << "supports custom page:  " << info.supportsCustomPageSizes();
    qDebug() << "minimum page size:     " << info.minimumPhysicalPageSize();
    qDebug() << "maximum page size:     " << info.maximumPhysicalPageSize();
    qDebug() << "default Media Source:  " << info.defaultMediaSource();
    qDebug() << "media sources:         " << info.supportedMediaSources() << endl;
    qDebug() << "default output bin:    " << info.defaultOutputBin();
    qDebug() << "supported output bins: " << info.supportedOutputBins() << endl;
    qDebug() << "supportedResolutions:  " << info.supportedResolutions() << endl;
#endif

    QPrinter *printer = new QPrinter( info.defaultPrinter() );

    QPrintDialog *dlg = new QPrintDialog( printer, this );

    dlg->setWindowTitle( tr( "Print editor contents" ) );

    if ( dlg->exec() == QDialog::Accepted )
    {
        MyEditWidget *ptr = static_cast<MyEditWidget *>( m_tabWidget->currentWidget() );

        if ( ptr != nullptr )
        {
            qDebug() << "calling print()" << endl;
            ptr->print( printer );
        }
        else
        {
            qDebug() << "ptr was null" << endl;
        }
    }

    delete printer;
    delete dlg;
}

#if defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_BSD4) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)
QString MainWindow::printerOption( const QString &key )
{
    return QString::fromUtf8( cupsGetOption( key.toUtf8().constData(), m_cupsDest->num_options, m_cupsDest->options ) );
}


void MainWindow::testAPI()
{
    QTextStream out( stdout );
    m_cupsDest = cupsGetNamedDest( CUPS_HTTP_DEFAULT, cupsGetDefault(), NULL );

    if ( !m_cupsDest )
    {
        out << "****unable to get default print destination" << endl;;
        return;
    }

    cups_dinfo_t *info = cupsCopyDestInfo( CUPS_HTTP_DEFAULT, m_cupsDest );

    m_name = QByteArray( m_cupsDest->name );
    m_instance.clear();

    if ( m_cupsDest->instance )
    {
        m_instance = QByteArray( m_cupsDest->instance );
    }

    m_uri = printerOption( QString::fromUtf8( URI_OPTION ) ).toUtf8();
    m_makeAndModel = printerOption( QString::fromUtf8( MAKE_AND_MODEL_OPTION ) ).toUtf8();
    m_location = printerOption( QString::fromUtf8( LOCATION_OPTION ) ).toUtf8();

    out << "Printer name: " << QString::fromUtf8( m_name ) << endl;
    out << "instance: " << QString::fromUtf8( m_instance ) << endl;
    out << "uri: " << QString::fromUtf8( m_uri ) << endl;
    out << "make and model: " << QString::fromUtf8( m_makeAndModel ) << endl;
    out << "location: " << QString::fromUtf8( m_location ) << endl;

    static const char *const requested_attributes[] =
    {
        CUPS_PRINT_COLOR_MODE_SUPPORTED
    };

    http_t *http = cupsConnectDest( m_cupsDest, CUPS_DEST_FLAGS_NONE, 30000, NULL, m_resource, RESOURCE_SIZE, NULL, NULL );

    if ( http )
    {
        ipp_t *request = ippNewRequest( IPP_OP_GET_PRINTER_ATTRIBUTES );
        ippAddString( request, IPP_TAG_OPERATION, IPP_TAG_URI, PRINTER_URI_REQUEST, NULL, m_uri.constData() );
        ippAddStrings( request, IPP_TAG_OPERATION, IPP_TAG_KEYWORD, ATTRIBUTE_LIST_REQUEST,
                       ( int )( sizeof( requested_attributes ) / sizeof( requested_attributes[0] ) ), NULL, requested_attributes );
        ipp_t *response = cupsDoRequest( http, request, m_resource );

        if ( ( cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST ) )
        {
            out << "request error: " << QString::fromUtf8( ippErrorString( cupsLastError() ) ) << endl;
            httpClose( http );
            cupsFreeDestInfo( info );
            return;
        }

        ipp_attribute_t *attr = nullptr;

        if ( ( attr = ippFindAttribute( response, CUPS_PRINT_COLOR_MODE_SUPPORTED, IPP_TAG_ZERO ) ) != NULL )
        {
            int binCount = ippGetCount( attr );
            out << "---supported color modes" << endl;

            for ( int uuu = 0; uuu < binCount; uuu++ )
            {
                out << QString::fromUtf8( ippGetString( attr, uuu, NULL ) ) << endl;
            }
        }

        httpClose( http );
    }
    else
    {
        out << "ErrorString: " << QString::fromUtf8( ippErrorString( cupsLastError() ) ) << endl;
        out << "unable to connect to printer" << endl;
    }

    cupsFreeDestInfo( info );

}
#endif
