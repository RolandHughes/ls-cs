//
// copyright (c) 2021-2025 Roland Hughes d/b/a Logikal Solutions
//
// The License.txt file describes the conditions under which this software may be distributed.
//
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include <qbytearray.h>
#include <cups/cups.h>

class QTabWidget;
class QVBoxLayout;
class QMenu;
class QAction;

class MainWindow : public QMainWindow
{
    LSCS_OBJECT( MainWindow )
public:
    MainWindow( QWidget *parent=0 );
    ~MainWindow();

    static const size_t RESOURCE_SIZE = 40000;
    static const size_t VALUE_SIZE = 4096;

    virtual void closeEvent( QCloseEvent *event );

    void newTabForFile( QString fileName );
    void newTabForText( QString text );
    void printCurrent();
    void updateTabText();
    void updateIsDirty();

private:
    void    about();
    void    addEmptyTab();
    void    commandLineDialog();
    void    createMenus();
    void    guiDialog();
    void    removeTab( int index );
    void	testAPI();

    QString printerOption( const QString &key );
    QString uniqueName();


    QTabWidget         *m_tabWidget;
    QVBoxLayout        *m_layout;

    QMenu              *m_menuFile;
    QMenu              *m_menuHelp;

    QAction            *m_actionAbout;
    QAction            *m_actionClose;
    QAction            *m_actionNewFile;
    QAction            *m_actionNewBuffer;
    QAction            *m_actionOpen;
    QAction            *m_actionSave;
    QAction            *m_actionSaveAs;
    QAction            *m_actionSep5;
    QAction            *m_actionSep6;
    QAction            *m_actionPrint;

    QAction            *m_actionExit;
    
    
#if defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_BSD4) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)    
    QAction			   *m_actionSep7;
    QAction			   *m_actionTestAPI;
    
    cups_dest_t *m_cupsDest;
    char        m_resource[ RESOURCE_SIZE];
    char        m_value[ VALUE_SIZE];
    
    QByteArray  m_uri;
    QByteArray  m_makeAndModel;
    QByteArray  m_location;
    QByteArray  m_instance;
    QByteArray  m_name;
#endif    
    
};
#endif /* MAINWINDOW_H */
