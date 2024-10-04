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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ui_mainwindow.h>

#include <messagemodel.h>
#include <phrase.h>
#include <recentfiles.h>

#include <qhash.h>
#include <qlocale.h>
#include <qmainwindow.h>

#include <optional>

class QAction;
class QDialog;
class QIcon;
class QLabel;
class QMenu;
class QPixmap;
class QPrinter;
class QProcess;
class QSortFilterProxyModel;
class QStackedWidget;
class QTableView;
class QTreeView;

class BatchTranslationDialog;
class ErrorsView;
class FindDialog;
class FocusWatcher;
class MessageEditor;
class PhraseView;
class SettingsDialog;
class SourceCodeView;
class Statistics;
class TranslateDialog;

// class FormPreviewView;

class MainWindow : public QMainWindow
{
    LSCS_OBJECT( MainWindow )

public:
    enum { PhraseCloseMenu, PhraseEditMenu, PhrasePrintMenu};

    MainWindow();
    ~MainWindow();

    bool openFiles( const QStringList &names, bool readWrite = true );
    static RecentFiles &recentFiles();
    static const QString &resourcePrefix();
    static QString friendlyString( const QString &str );

protected:
    void readConfig();
    void writeConfig();
    void closeEvent( QCloseEvent * ) override;
    bool eventFilter( QObject *object, QEvent *event ) override;

private:
    // file
    LSCS_SLOT_1( Private, void open() )
    LSCS_SLOT_2( open )

    LSCS_SLOT_1( Private, void openAux() )
    LSCS_SLOT_2( openAux )

    LSCS_SLOT_1( Private, void recentFileActivated( QAction *action ) )
    LSCS_SLOT_2( recentFileActivated )

    LSCS_SLOT_1( Private, void saveAll() )
    LSCS_SLOT_2( saveAll )

    LSCS_SLOT_1( Private, void save() )
    LSCS_SLOT_2( save )

    LSCS_SLOT_1( Private, void saveAs() )
    LSCS_SLOT_2( saveAs )

    LSCS_SLOT_1( Private, void releaseAll() )
    LSCS_SLOT_2( releaseAll )

    LSCS_SLOT_1( Private, void release() )
    LSCS_SLOT_2( release )

    LSCS_SLOT_1( Private, void releaseAs() )
    LSCS_SLOT_2( releaseAs )

    LSCS_SLOT_1( Private, void print() )
    LSCS_SLOT_2( print )

    LSCS_SLOT_1( Private, void closeFile() )
    LSCS_SLOT_2( closeFile )

    LSCS_SLOT_1( Private, bool closeAll() )
    LSCS_SLOT_2( closeAll )

    // edit
    LSCS_SLOT_1( Private, void findAgain() )
    LSCS_SLOT_2( findAgain )

    LSCS_SLOT_1( Private, void batchTranslateDialog() )
    LSCS_SLOT_2( batchTranslateDialog )

    LSCS_SLOT_1( Private, void searchTranslateDialog() )
    LSCS_SLOT_2( searchTranslateDialog )

    // translations
    LSCS_SLOT_1( Private, bool previous( bool checkUnfinished = false ) )
    LSCS_SLOT_2( previous )

    LSCS_SLOT_1( Private, bool next( bool checkUnfinished = false ) )
    LSCS_SLOT_2( next )

    LSCS_SLOT_1( Private, void doneAndNext() )
    LSCS_SLOT_2( doneAndNext )

    LSCS_SLOT_1( Private, void setupRecentFilesMenu() )
    LSCS_SLOT_2( setupRecentFilesMenu )

    LSCS_SLOT_1( Private, void updateTranslateHit( bool &hit ) )
    LSCS_SLOT_2( updateTranslateHit )

    LSCS_SLOT_1( Private, void translate( int mode ) )
    LSCS_SLOT_2( translate )

    // phrases
    LSCS_SLOT_1( Private, void newPhraseBook() )
    LSCS_SLOT_2( newPhraseBook )

    LSCS_SLOT_1( Private, void selectPhraseBook() )
    LSCS_SLOT_2( selectPhraseBook )

    LSCS_SLOT_1( Private, void closePhraseBook( QAction *action ) )
    LSCS_SLOT_2( closePhraseBook )

    LSCS_SLOT_1( Private, void editPhraseBook( QAction *action ) )
    LSCS_SLOT_2( editPhraseBook )

    LSCS_SLOT_1( Private, void printPhraseBook( QAction *action ) )
    LSCS_SLOT_2( printPhraseBook )

    LSCS_SLOT_1( Private, void addToPhraseBook() )
    LSCS_SLOT_2( addToPhraseBook )

    // view
    LSCS_SLOT_1( Private, void resetSorting() )
    LSCS_SLOT_2( resetSorting )

    LSCS_SLOT_1( Private, void settingsDialog( std::optional<int> model = std::optional<int>() ) )
    LSCS_SLOT_2( settingsDialog )

    // help
    LSCS_SLOT_1( Private, void manual() )
    LSCS_SLOT_2( manual )

    LSCS_SLOT_1( Private, void about() )
    LSCS_SLOT_2( about )

    //
    LSCS_SLOT_1( Private, void updateViewMenu() )
    LSCS_SLOT_2( updateViewMenu )

    LSCS_SLOT_1( Private, void fileAboutToShow() )
    LSCS_SLOT_2( fileAboutToShow )

    LSCS_SLOT_1( Private, void editAboutToShow() )
    LSCS_SLOT_2( editAboutToShow )

    LSCS_SLOT_1( Private, void showContextDock() )
    LSCS_SLOT_2( showContextDock )

    LSCS_SLOT_1( Private, void showMessagesDock() )
    LSCS_SLOT_2( showMessagesDock )

    LSCS_SLOT_1( Private, void showPhrasesDock() )
    LSCS_SLOT_2( showPhrasesDock )

    LSCS_SLOT_1( Private, void showSourceCodeDock() )
    LSCS_SLOT_2( showSourceCodeDock )

    LSCS_SLOT_1( Private, void showErrorDock() )
    LSCS_SLOT_2( showErrorDock )

    LSCS_SLOT_1( Private, void setupPhrase() )
    LSCS_SLOT_2( setupPhrase )

    LSCS_SLOT_1( Private, bool maybeSaveAll() )
    LSCS_SLOT_2( maybeSaveAll )

    LSCS_SLOT_1( Private, bool maybeSave( int model ) )
    LSCS_SLOT_2( maybeSave )

    LSCS_SLOT_1( Private, void updateProgress() )
    LSCS_SLOT_2( updateProgress )

    LSCS_SLOT_1( Private, void maybeUpdateStatistics( const MultiDataIndex &index ) )
    LSCS_SLOT_2( maybeUpdateStatistics )

    LSCS_SLOT_1( Private, void translationChanged( const MultiDataIndex &index ) )
    LSCS_SLOT_2( translationChanged )

    LSCS_SLOT_1( Private, void updateCaption() )
    LSCS_SLOT_2( updateCaption )

    LSCS_SLOT_1( Private, void updateModelIndex( const QModelIndex &index ) )
    LSCS_SLOT_2( updateModelIndex )

    LSCS_SLOT_1( Private, void selectedContextChanged( const QModelIndex &sortedIndex,const QModelIndex &oldIndex ) )
    LSCS_SLOT_2( selectedContextChanged )

    LSCS_SLOT_1( Private, void selectedMessageChanged( const QModelIndex &sortedIndex,const QModelIndex &oldIndex ) )
    LSCS_SLOT_2( selectedMessageChanged )

    // To synchronize from the message editor to the model
    LSCS_SLOT_1( Private, void updateTranslation( const QStringList &translations ) )
    LSCS_SLOT_2( updateTranslation )

    LSCS_SLOT_1( Private, void updateTranslatorComment( const QString &comment ) )
    LSCS_SLOT_2( updateTranslatorComment )

    LSCS_SLOT_1( Private, void updateActiveModel( int model ) )
    LSCS_SLOT_2( updateActiveModel )

    LSCS_SLOT_1( Private, void refreshItemViews() )
    LSCS_SLOT_2( refreshItemViews )

    LSCS_SLOT_1( Private, void toggleFinished( const QModelIndex &index ) )
    LSCS_SLOT_2( toggleFinished )

    LSCS_SLOT_1( Private, void prevUnfinished() )
    LSCS_SLOT_2( prevUnfinished )

    LSCS_SLOT_1( Private, void nextUnfinished() )
    LSCS_SLOT_2( nextUnfinished )

    LSCS_SLOT_1( Private, void findNext( const QString &text, DataModel::FindLocation where, bool matchCase, bool ignoreAccelerators,
                                       bool skipObsolete ) )
    LSCS_SLOT_2( findNext )

    LSCS_SLOT_1( Private, void revalidate() )
    LSCS_SLOT_2( revalidate )

    LSCS_SLOT_1( Private, void toggleStatistics() )
    LSCS_SLOT_2( toggleStatistics )

    LSCS_SLOT_1( Private, void toggleVisualizeWhitespace() )
    LSCS_SLOT_2( toggleVisualizeWhitespace )

    LSCS_SLOT_1( Private, void updatePhraseDicts() )
    LSCS_SLOT_2( updatePhraseDicts )

    LSCS_SLOT_1( Private, void updatePhraseDict( int model ) )
    LSCS_SLOT_2( updatePhraseDict )

    QModelIndex nextContext( const QModelIndex &index ) const;
    QModelIndex prevContext( const QModelIndex &index ) const;

    QModelIndex nextMessage( const QModelIndex &currentIndex, bool checkUnfinished = false ) const;
    QModelIndex prevMessage( const QModelIndex &currentIndex, bool checkUnfinished = false ) const;

    void updateStatistics();
    void initViewHeaders();
    void modelCountChanged();
    void setupMenuBar();
    void setupToolBars();
    void setCurrentMessage( const QModelIndex &index );
    void setCurrentMessage( const QModelIndex &index, int model );

    QModelIndex setMessageViewRoot( const QModelIndex &index );
    QModelIndex currentContextIndex() const;
    QModelIndex currentMessageIndex() const;

    PhraseBook *openPhraseBook( const QString &name );

    bool isPhraseBookOpen( const QString &name );
    bool savePhraseBook( QString *name, PhraseBook &pb );
    bool maybeSavePhraseBook( PhraseBook *phraseBook );
    bool maybeSavePhraseBooks();
    QStringList pickTranslationFiles();

    void updateLatestModel( int model );
    void updateSourceView( int model, MessageItem *item );
    void updatePhraseBookActions();
    void updatePhraseDictInternal( int model );
    void releaseInternal( int model );
    void saveInternal( int model );

    QPrinter *printer();

    // may want to move to DataModel
    void updateDanger( const MultiDataIndex &index, bool verbose );

    bool searchItem( DataModel::FindLocation where, const QString &searchWhat );

    QProcess  *m_assistantProcess;
    QTreeView *m_contextView;
    QTreeView *m_messageView;
    QPrinter  *m_printer;

    MultiDataModel *m_dataModel;
    MessageModel   *m_messageModel;
    MessageEditor  *m_messageEditor;
    PhraseView     *m_phraseView;
    SourceCodeView *m_sourceCodeView;
    FocusWatcher   *m_focusWatcher;

    QDockWidget *m_contextDock;
    QDockWidget *m_messagesDock;
    QDockWidget *m_phrasesDock;
    QDockWidget *m_sourceAndFormDock;
    QDockWidget *m_errorsDock;

    QStackedWidget *m_sourceAndFormView;

    QSortFilterProxyModel *m_sortedContextsModel;
    QSortFilterProxyModel *m_sortedMessagesModel;

    // FormPreviewView *m_formPreviewView;
    ErrorsView *m_errorsView;
    QLabel *m_progressLabel;
    QLabel *m_modifiedLabel;

    QString m_phraseBookDir;

    // model : keyword -> list of appropriate phrases in the phrasebooks
    QList<QHash<QString, QList<Phrase *> > > m_phraseDict;
    QList<PhraseBook *> m_phraseBooks;
    QMap<QAction *, PhraseBook *> m_phraseBookMenu[3];

    FindDialog *m_findDialog;
    QString m_findText;
    Qt::CaseSensitivity m_findMatchCase;
    bool m_findIgnoreAccelerators;
    bool m_findSkipObsolete;

    DataModel::FindLocation m_findWhere;

    TranslateDialog *m_translateDialog;
    QString m_latestFindText;
    int m_latestCaseSensitivity;
    int m_remainingCount;
    int m_hitCount;

    BatchTranslationDialog *m_batchTranslateDialog;
    SettingsDialog *m_settingsDialog;

    bool m_settingCurrentMessage;
    int m_fileActiveModel;
    int m_editActiveModel;
    MultiDataIndex m_currentIndex;

    Ui::MainWindow m_ui;         // menus and actions
    Statistics *m_statistics;
};

#endif
