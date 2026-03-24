/* myeditwidget.cpp
 *
 * To avoid creating a MainWindow class that is a mess, one should create their own
 * wrapper class for QTextEdit. This way you can put all of the heavy lifting
 * like file loading and such into the widget keeping MainWindow concerned only
 * with MainWindow things.
 *
 */
//
// copyright (c) 2021 Roland Hughes d/b/a Logikal Solutions
//
// The License.txt file describes the conditions under which this software may be distributed.
//


#include "myeditwidget.h"

#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

MyEditWidget::MyEditWidget( QWidget *parent ) :
    QTextEdit( parent )
    , m_isDirty( false )
{

    setTabStopWidth( 4 );
    setUndoRedoEnabled( true );
    setBackgroundColor( QColor( "#004d00" ) );
    setTextColor( Qt::white );

    // allow widget to accept drops
    //
    setAcceptDrops( true );

    connect( this, &QTextEdit::undoAvailable, this, &MyEditWidget::savePointReached );

    // Set a default font that should be available everywhere
    //
    QString defaultFont = "Monospace";
    setFontFamily( defaultFont );
    setFontPointSize( 11 );
    setFontWeight( QFont::Normal );
}

void MyEditWidget::clearEditWidget()
{
    clear();

    m_currentFile   = "";
    m_isDirty       = false;
    updateDirtyIndicator();
    updateTabText();
}


void MyEditWidget::loadFile( QString fullPathToFile )
{
    closeDoc();

    m_currentFile = fullPathToFile;

    QFile file( m_currentFile );

    if ( ! file.open( QIODevice::ReadWrite | QIODevice::Text ) )
    {
        QMessageBox::warning( this, tr( "File Open" ), tr( "Unable to open file" ),
                              QMessageBox::Ignore, QMessageBox::NoButton );
        m_currentFile = "";
    }
    else
    {

        setText( QString::fromUtf8( file.readAll().constData() ) );
        file.close();

        moveCursor( QTextCursor::Start );

        m_isDirty     = false;
        updateTabText();
        updateDirtyIndicator();
    }
}

bool MyEditWidget::closeDoc()
{
    bool retVal = true;

    if ( m_isDirty )
    {
        QMessageBox::StandardButton btn = QMessageBox::information( this, tr( "Confirm" ),
                                          tr( "Document has unsaved changes" ),
                                          ( QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel ),
                                          QMessageBox::Save );

        switch ( btn )
        {
            case QMessageBox::Save:
                save();
                clearEditWidget();
                break;

            case QMessageBox::Cancel:
                retVal = false;
                break;

            case QMessageBox::Discard:
            default:
                clearEditWidget();
                break;
        }
    }

    return retVal;
}

void MyEditWidget::save()
{

    if ( m_currentFile.length() < 1 )
    {
        saveAs();
    }
    else
    {
        QFile file( m_currentFile );

        if ( ! file.open( QIODevice::WriteOnly | QIODevice::Text ) )
        {
            QMessageBox::warning( this, tr( "File Open" ), tr( "Unable to save file" ),
                                  QMessageBox::Ignore, QMessageBox::NoButton );
        }
        else
        {
            file.write( toPlainText().toUtf8() );
            file.flush();
            file.close();
            m_isDirty = false;
            updateDirtyIndicator();
        }
    }

}

void MyEditWidget::savePointReached( bool yesNo )
{
    m_isDirty = yesNo;
    updateDirtyIndicator();
}

void MyEditWidget::newDoc()
{
    QString selectedFilter;
    QFileDialog::FileDialogOptions options;

    // force windows 7 and 8 to honor initial path
    options = QFileDialog::ForceInitialDir_Win7;

    QFileDialog *dlg = new QFileDialog( this, "Open",
                                        QStandardPaths::writableLocation( QStandardPaths::HomeLocation ),
                                        selectedFilter );

    dlg->setOptions( options );
    dlg->setAcceptMode( QFileDialog::AcceptOpen );
    dlg->setConfirmOverwrite( true );
    dlg->setOptions( options );
    dlg->setFileMode( QFileDialog::AnyFile );

    dlg->exec();

    QStringList files = dlg->selectedFiles();

    if ( files.length() > 0 )
    {
        QString fileName = files.takeFirst();

        if ( QFile::exists( fileName ) )
        {
            QMessageBox::StandardButton btn = QMessageBox::question( this,
                                              "Confirm",
                                              "File exists. Do you wish to overwrite?" );

            if ( QMessageBox::Yes == btn )
            {
                m_currentFile = fileName;
            }
        }
        else
        {
            m_currentFile = fileName;
        }
    }
}

void MyEditWidget::openDoc()
{
    QString selectedFilter;
    QFileDialog::FileDialogOptions options;

    // force windows 7 and 8 to honor initial path
    options = QFileDialog::ForceInitialDir_Win7;

    QFileDialog *dlg = new QFileDialog( this, "Open",
                                        QStandardPaths::writableLocation( QStandardPaths::HomeLocation ),
                                        selectedFilter );

    dlg->setOptions( options );
    dlg->setAcceptMode( QFileDialog::AcceptOpen );
    dlg->setOptions( options );
    dlg->setFileMode( QFileDialog::ExistingFile );

    dlg->exec();

    QStringList files = dlg->selectedFiles();

    if ( files.length() > 0 )
    {
        loadFile( files.takeFirst() );
    }
}

void MyEditWidget::saveAs()
{
    QString selectedFilter;
    QFileDialog::FileDialogOptions options;

    // force windows 7 and 8 to honor initial path
    options = QFileDialog::ForceInitialDir_Win7;

    QFileDialog *dlg = new QFileDialog( this, "Save As",
                                        QStandardPaths::writableLocation( QStandardPaths::HomeLocation ),
                                        selectedFilter );

    dlg->setOptions( options );
    dlg->setAcceptMode( QFileDialog::AcceptSave );
    dlg->setConfirmOverwrite( true );
    dlg->setOptions( options );

    dlg->exec();

    QStringList files = dlg->selectedFiles();

    if ( files.length() > 0 )
    {
        m_currentFile = files.takeFirst();
        save();
    }
}

QString MyEditWidget::currentFile()
{
    return m_currentFile;
}

bool MyEditWidget::isEmpty()
{
    bool retVal = true;

    if ( m_currentFile.length() > 0 )
    {
        retVal = false;
    }

    if ( !document()->isEmpty() )
    {
        retVal = false;
    }

    return retVal;
}

// drag & drop
void MyEditWidget::dragEnterEvent( QDragEnterEvent *event )
{
    if ( event->mimeData()->hasFormat( "text/uri-list" ) )
    {
        event->acceptProposedAction();
    }
    else if ( event->mimeData()->hasFormat( "text/plain" ) )
    {
        event->acceptProposedAction();
    }
}

void MyEditWidget::dropEvent( QDropEvent *event )
{
    const QMimeData *mimeData = event->mimeData();

    bool useCurrentTab = true;

    if ( !isEmpty() )
    {
        QMessageBox::StandardButton btn = QMessageBox::question( this,
                                          "Confirm",
                                          "Buffer is in use. Do you wish to paste at cursor location?" );

        if ( QMessageBox::No == btn )
        {
            useCurrentTab = false;
        }
    }

    if ( mimeData->hasUrls() )
    {

        QList<QUrl> urls = mimeData->urls();

        if ( !urls.isEmpty() )
        {

            // if you are always forcing a new tab you can
            // loop through entire list.
            //
            QString fileName = urls.first().toLocalFile();

            if ( ! fileName.isEmpty() )
            {
                if ( useCurrentTab )
                {
                    loadFile( fileName );
                }
                else
                {
                    newTabForFile( fileName );
                }
            }
        }

    }
    else if ( mimeData->hasText() )
    {
        if ( useCurrentTab )
        {
            insertFromMimeData( mimeData );
        }
        else
        {
            newTabForText( mimeData->text() );
        }
    }

}

bool MyEditWidget::isDirty()
{
    return m_isDirty;
}

void MyEditWidget::setBackgroundColor( QColor background )
{
    QPalette p = palette();
    p.setColor( QPalette::Base, background );
    setPalette( p );
}

