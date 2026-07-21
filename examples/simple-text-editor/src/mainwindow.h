//
// copyright (c) 2021 Roland Hughes d/b/a Logikal Solutions
//
// The License.txt file describes the conditions under which this software may be distributed.
//
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

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

    virtual void closeEvent( QCloseEvent *event );

    void newTabForFile( QString fileName );
    void newTabForText( QString text );
    void updateTabText();
    void updateIsDirty();

private:
    void    about();
    void    createMenus();
    void    addEmptyTab();
    void    removeTab( int index );

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

    QAction            *m_actionExit;
};
#endif /* MAINWINDOW_H */
