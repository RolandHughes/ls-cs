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

#ifndef QUNDOGROUP_H
#define QUNDOGROUP_H

#include <qobject.h>
#include <qscopedpointer.h>
#include <qstring.h>

class QAction;
class QUndoGroupPrivate;
class QUndoStack;

#ifndef QT_NO_UNDOGROUP

class Q_GUI_EXPORT QUndoGroup : public QObject
{
    GUI_LSCS_OBJECT( QUndoGroup )

public:
    explicit QUndoGroup( QObject *parent = nullptr );

    QUndoGroup( const QUndoGroup & ) = delete;
    QUndoGroup &operator=( const QUndoGroup & ) = delete;

    ~QUndoGroup();

    void addStack( QUndoStack *stack );
    void removeStack( QUndoStack *stack );
    QList<QUndoStack *> stacks() const;
    QUndoStack *activeStack() const;

#ifndef QT_NO_ACTION
    QAction *createUndoAction( QObject *parent, const QString &prefix = QString() ) const;
    QAction *createRedoAction( QObject *parent, const QString &prefix = QString() ) const;
#endif

    bool canUndo() const;
    bool canRedo() const;
    QString undoText() const;
    QString redoText() const;
    bool isClean() const;

    GUI_LSCS_SLOT_1( Public, void undo() )
    GUI_LSCS_SLOT_2( undo )

    GUI_LSCS_SLOT_1( Public, void redo() )
    GUI_LSCS_SLOT_2( redo )

    GUI_LSCS_SLOT_1( Public, void setActiveStack( QUndoStack *stack ) )
    GUI_LSCS_SLOT_2( setActiveStack )

    GUI_LSCS_SIGNAL_1( Public, void activeStackChanged( QUndoStack *stack ) )
    GUI_LSCS_SIGNAL_2( activeStackChanged, stack )
    GUI_LSCS_SIGNAL_1( Public, void indexChanged( int idx ) )
    GUI_LSCS_SIGNAL_2( indexChanged, idx )
    GUI_LSCS_SIGNAL_1( Public, void cleanChanged( bool clean ) )
    GUI_LSCS_SIGNAL_2( cleanChanged, clean )
    GUI_LSCS_SIGNAL_1( Public, void canUndoChanged( bool canUndo ) )
    GUI_LSCS_SIGNAL_2( canUndoChanged, canUndo )
    GUI_LSCS_SIGNAL_1( Public, void canRedoChanged( bool canRedo ) )
    GUI_LSCS_SIGNAL_2( canRedoChanged, canRedo )
    GUI_LSCS_SIGNAL_1( Public, void undoTextChanged( const QString &undoText ) )
    GUI_LSCS_SIGNAL_2( undoTextChanged, undoText )
    GUI_LSCS_SIGNAL_1( Public, void redoTextChanged( const QString &redoText ) )
    GUI_LSCS_SIGNAL_2( redoTextChanged, redoText )

protected:
    QScopedPointer<QUndoGroupPrivate> d_ptr;

private:
    Q_DECLARE_PRIVATE( QUndoGroup )
};

#endif // QT_NO_UNDOGROUP

#endif // QUNDOGROUP_H
