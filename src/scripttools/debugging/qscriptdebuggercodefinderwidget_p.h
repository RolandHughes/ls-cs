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

#ifndef QSCRIPTDEBUGGERCODEFINDERWIDGET_P_H
#define QSCRIPTDEBUGGERCODEFINDERWIDGET_P_H

#include <qscriptdebuggercodefinderwidgetinterface_p.h>

LSCS_BEGIN_NAMESPACE

class QScriptDebuggerCodeFinderWidgetPrivate;

class QScriptDebuggerCodeFinderWidget : public QScriptDebuggerCodeFinderWidgetInterface
{
    SCRIPT_T_LSCS_OBJECT( QScriptDebuggerCodeFinderWidget )

public:
    QScriptDebuggerCodeFinderWidget( QWidget *parent = nullptr );
    ~QScriptDebuggerCodeFinderWidget();

    int findOptions() const;

    QString text() const;
    void setText( const QString &text );

    void setOK( bool ok );
    void setWrapped( bool wrapped );

protected:
    void keyPressEvent( QKeyEvent *e );

private:
    Q_DECLARE_PRIVATE( QScriptDebuggerCodeFinderWidget )
    Q_DISABLE_COPY( QScriptDebuggerCodeFinderWidget )

    LSCS_SLOT_1( Private, void _q_updateButtons() )
    LSCS_SLOT_2( _q_updateButtons )

    LSCS_SLOT_1( Private, void _q_onTextChanged( const QString &un_named_arg1 ) )
    LSCS_SLOT_2( _q_onTextChanged )

    LSCS_SLOT_1( Private, void _q_next() )
    LSCS_SLOT_2( _q_next )

    LSCS_SLOT_1( Private, void _q_previous() )
    LSCS_SLOT_2( _q_previous )

};

LSCS_END_NAMESPACE

#endif
