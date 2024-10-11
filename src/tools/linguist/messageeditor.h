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

#ifndef MESSAGEEDITOR_H
#define MESSAGEEDITOR_H

#include <messagemodel.h>

#include <qframe.h>
#include <qlocale.h>
#include <qscrollarea.h>
#include <qtimer.h>

class QBoxLayout;
class QMainWindow;
class QTextEdit;

class FormMultiWidget;
class FormWidget;
class FormatTextEdit;
class MessageEditor;

struct MessageEditorData
{
    QWidget *container;
    FormWidget *transCommentText;
    QList<FormMultiWidget *> transTexts;
    QString invariantForm;
    QString firstForm;
    qreal fontSize;
    bool pluralEditMode;
};

class MessageEditor : public QScrollArea
{
    LSCS_OBJECT( MessageEditor )

public:
    MessageEditor( MultiDataModel *dataModel, QMainWindow *parent = nullptr );

    void showNothing();
    void showMessage( const MultiDataIndex &index );
    void setNumerusForms( int model, const QStringList &numerusForms );
    bool eventFilter( QObject *, QEvent * ) override;
    void setTranslationNumerus( int model, const QString &translation, int numerus );

    int activeModel() const
    {
        return ( m_editors.count() != 1 ) ? m_currentModel : 0;
    }

    void setEditorFocusModel( int model );
    void setUnfinishedEditorFocus();
    bool focusNextUnfinished();

    void setVisualizeWhitespace( bool value );
    void setFontSize( const float fontSize );
    float fontSize();

    LSCS_SIGNAL_1( Public, void translationChanged( const QStringList &translations ) )
    LSCS_SIGNAL_2( translationChanged,translations )

    LSCS_SIGNAL_1( Public, void translatorCommentChanged( const QString &comment ) )
    LSCS_SIGNAL_2( translatorCommentChanged,comment )

    LSCS_SIGNAL_1( Public, void activeModelChanged( int model ) )
    LSCS_SIGNAL_2( activeModelChanged,model )

    LSCS_SIGNAL_1( Public, void undoAvailable( bool avail ) )
    LSCS_SIGNAL_2( undoAvailable,avail )

    LSCS_SIGNAL_1( Public, void redoAvailable( bool avail ) )
    LSCS_SIGNAL_2( redoAvailable,avail )

    LSCS_SIGNAL_1( Public, void cutAvailable( bool avail ) )
    LSCS_SIGNAL_2( cutAvailable,avail )

    LSCS_SIGNAL_1( Public, void copyAvailable( bool avail ) )
    LSCS_SIGNAL_2( copyAvailable,avail )

    LSCS_SIGNAL_1( Public, void pasteAvailable( bool avail ) )
    LSCS_SIGNAL_2( pasteAvailable,avail )

    LSCS_SIGNAL_1( Public, void beginFromSourceAvailable( bool enable ) )
    LSCS_SIGNAL_2( beginFromSourceAvailable,enable )

    LSCS_SLOT_1( Public, void undo() )
    LSCS_SLOT_2( undo )

    LSCS_SLOT_1( Public, void redo() )
    LSCS_SLOT_2( redo )

    LSCS_SLOT_1( Public, void cut() )
    LSCS_SLOT_2( cut )

    LSCS_SLOT_1( Public, void copy() )
    LSCS_SLOT_2( copy )

    LSCS_SLOT_1( Public, void paste() )
    LSCS_SLOT_2( paste )

    LSCS_SLOT_1( Public, void selectAll() )
    LSCS_SLOT_2( selectAll )

    LSCS_SLOT_1( Public, void beginFromSource() )
    LSCS_SLOT_2( beginFromSource )

    LSCS_SLOT_1( Public, void setEditorFocus() )
    LSCS_SLOT_2( setEditorFocus )

    LSCS_SLOT_1( Public, void setTranslation( int model, const QString &translation ) )
    LSCS_SLOT_2( setTranslation )

    LSCS_SLOT_1( Public, void setLengthVariants( bool on ) )
    LSCS_SLOT_2( setLengthVariants )

    LSCS_SLOT_1( Public, void increaseFontSize() )
    LSCS_SLOT_2( increaseFontSize )

    LSCS_SLOT_1( Public, void decreaseFontSize() )
    LSCS_SLOT_2( decreaseFontSize )

    LSCS_SLOT_1( Public, void resetFontSize() )
    LSCS_SLOT_2( resetFontSize )

private:
    LSCS_SLOT_1( Private, void editorCreated( QTextEdit *editor ) )
    LSCS_SLOT_2( editorCreated )

    LSCS_SLOT_1( Private, void editorDestroyed() )
    LSCS_SLOT_2( editorDestroyed )

    LSCS_SLOT_1( Private, void selectionChanged( QTextEdit *editor ) )
    LSCS_SLOT_2( selectionChanged )

    LSCS_SLOT_1( Private, void resetHoverSelection() )
    LSCS_SLOT_2( resetHoverSelection )

    LSCS_SLOT_1( Private, void emitTranslationChanged( QTextEdit *editor ) )
    LSCS_SLOT_2( emitTranslationChanged )

    LSCS_SLOT_1( Private, void emitTranslatorCommentChanged( QTextEdit *editor ) )
    LSCS_SLOT_2( emitTranslatorCommentChanged )

    LSCS_SLOT_1( Private, void updateCanPaste() )
    LSCS_SLOT_2( updateCanPaste )

    LSCS_SLOT_1( Private, void clipboardChanged() )
    LSCS_SLOT_2( clipboardChanged )

    LSCS_SLOT_1( Private, void messageModelAppended() )
    LSCS_SLOT_2( messageModelAppended )

    LSCS_SLOT_1( Private, void messageModelDeleted( int model ) )
    LSCS_SLOT_2( messageModelDeleted )

    LSCS_SLOT_1( Private, void allModelsDeleted() )
    LSCS_SLOT_2( allModelsDeleted )

    LSCS_SLOT_1( Private, void setTargetLanguage( int model ) )
    LSCS_SLOT_2( setTargetLanguage )

    LSCS_SLOT_1( Private, void reallyFixTabOrder() )
    LSCS_SLOT_2( reallyFixTabOrder )

    void setupEditorPage();
    void setEditingEnabled( int model, bool enabled );
    bool focusNextUnfinished( int start );
    void resetSelection();
    void grabFocus( QWidget *widget );
    void trackFocus( QWidget *widget );
    void activeModelAndNumerus( int *model, int *numerus ) const;
    QTextEdit *activeTranslation() const;
    QTextEdit *activeOr1stTranslation() const;
    QTextEdit *activeTransComment() const;
    QTextEdit *activeEditor() const;
    QTextEdit *activeOr1stEditor() const;
    MessageEditorData *modelForWidget( const QObject *o );
    int activeTranslationNumerus() const;
    QStringList translations( int model ) const;
    void updateBeginFromSource();
    void updateUndoRedo();
    void updateCanCutCopy();
    void addPluralForm( int model, const QString &label, bool writable );
    void fixTabOrder();
    QPalette paletteForModel( int model ) const;
    void applyFontSize();

    MultiDataModel *m_dataModel;

    MultiDataIndex m_currentIndex;
    int m_currentModel;
    int m_currentNumerus;

    bool m_lengthVariants;
    float m_fontSize;

    bool m_undoAvail;
    bool m_redoAvail;
    bool m_cutAvail;
    bool m_copyAvail;

    bool m_clipboardEmpty;
    bool m_visualizeWhitespace;

    QTextEdit *m_selectionHolder;
    QWidget *m_focusWidget;
    QBoxLayout *m_layout;
    FormWidget *m_source;
    FormWidget *m_pluralSource;
    FormWidget *m_commentText;
    QList<MessageEditorData> m_editors;

    QTimer m_tabOrderTimer;
};

#endif
