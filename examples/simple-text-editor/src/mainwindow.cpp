//
// copyright (c) 2021 Roland Hughes d/b/a Logikal Solutions
//
// The License.txt file describes the conditions under which this software may be distributed.
//

#include "mainwindow.h"

#include <QVBoxLayout>
#include <QWidget>
#include <QMenu>
#include <QStandardPaths>
#include <QMessageBox>
#include <QMenuBar>
#include <QFileDialog>
#include <QCloseEvent>
#include <QTabWidget>
#include <QFileInfo>
#include <QTabBar>
#include <QRegularExpression>
#include <QStringParser>

#include "myeditwidget.h"

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
MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent )
{

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

    connect( m_actionExit, &QAction::triggered,
             this, [this]()
    {
        close();
    } );

    connect( m_actionAbout, &QAction::triggered, this, &MainWindow::about );

}

void MainWindow::about()
{
    QString txt = "Focus of this example is using QTextEdit in a multiple tab editor\n"
                  "If you start your design with a single edit window you will end up with\n"
                  "a MainWindow that is rather tightly coupled with the editor. This example\n"
                  "tries to provide a guide to the proper separation of duties. We created\n"
                  "a wrapper class for the QTextEdit object so we can provide customization\n"
                  "without having to butcher the library. We try to keep signals and slots\n"
                  "to a minimum between the two classes.\n"
                  "Addition of syntax highlighting, spell check, etc. is left as an\n"
                  "exercise for the user.";

    QMessageBox::about( this, "About Example 2", txt );
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
