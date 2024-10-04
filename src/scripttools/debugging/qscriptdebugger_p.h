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

#ifndef QSCRIPTDEBUGGER_P_H
#define QSCRIPTDEBUGGER_P_H

#include <QtCore/qobject.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerFrontend;
class QScriptDebuggerConsoleWidgetInterface;
class QScriptDebuggerScriptsWidgetInterface;
class QScriptDebuggerCodeWidgetInterface;
class QScriptDebuggerCodeFinderWidgetInterface;
class QScriptBreakpointsWidgetInterface;
class QScriptDebuggerStackWidgetInterface;
class QScriptDebuggerLocalsWidgetInterface;
class QScriptDebugOutputWidgetInterface;
class QScriptErrorLogWidgetInterface;
class QScriptDebuggerWidgetFactoryInterface;
class QAction;
class QEvent;
class QMenu;

#ifndef QT_NO_TOOLBAR
class QToolBar;
#endif

class QScriptDebuggerPrivate;

class QScriptDebugger : public QObject
{
    SCRIPT_T_LSCS_OBJECT( QScriptDebugger )

public:
    // mirrors QScriptEngineDebugger::DebuggerWidget
    enum DebuggerWidget
    {
        ConsoleWidget,
        StackWidget,
        ScriptsWidget,
        LocalsWidget,
        CodeWidget,
        CodeFinderWidget,
        BreakpointsWidget,
        DebugOutputWidget,
        ErrorLogWidget
    };
    // mirrors QScriptEngineDebugger::DebuggerAction
    enum DebuggerAction
    {
        InterruptAction,
        ContinueAction,
        StepIntoAction,
        StepOverAction,
        StepOutAction,
        RunToCursorAction,
        RunToNewScriptAction,
        ToggleBreakpointAction,
        ClearDebugOutputAction,
        ClearErrorLogAction,
        ClearConsoleAction,
        FindInScriptAction,
        FindNextInScriptAction,
        FindPreviousInScriptAction,
        GoToLineAction
    };

    QScriptDebugger( QObject *parent = nullptr );
    ~QScriptDebugger();

    QScriptDebuggerFrontend *frontend() const;
    void setFrontend( QScriptDebuggerFrontend *frontend );

    QWidget *widget( DebuggerWidget widget );
    QAction *action( DebuggerAction action, QObject *parent );

    QScriptDebuggerConsoleWidgetInterface *consoleWidget() const;
    void setConsoleWidget( QScriptDebuggerConsoleWidgetInterface *consoleWidget );

    QScriptDebuggerScriptsWidgetInterface *scriptsWidget() const;
    void setScriptsWidget( QScriptDebuggerScriptsWidgetInterface *scriptsWidget );

    QScriptDebuggerCodeWidgetInterface *codeWidget() const;
    void setCodeWidget( QScriptDebuggerCodeWidgetInterface *codeWidget );

    QScriptDebuggerCodeFinderWidgetInterface *codeFinderWidget() const;
    void setCodeFinderWidget( QScriptDebuggerCodeFinderWidgetInterface *codeFinderWidget );

    QScriptDebuggerStackWidgetInterface *stackWidget() const;
    void setStackWidget( QScriptDebuggerStackWidgetInterface *stackWidget );

    QScriptDebuggerLocalsWidgetInterface *localsWidget() const;
    void setLocalsWidget( QScriptDebuggerLocalsWidgetInterface *localsWidget );

    QScriptBreakpointsWidgetInterface *breakpointsWidget() const;
    void setBreakpointsWidget( QScriptBreakpointsWidgetInterface *breakpointsWidget );

    QScriptDebugOutputWidgetInterface *debugOutputWidget() const;
    void setDebugOutputWidget( QScriptDebugOutputWidgetInterface *debugOutputWidget );

    QScriptErrorLogWidgetInterface *errorLogWidget() const;
    void setErrorLogWidget( QScriptErrorLogWidgetInterface *errorLogWidget );

    QScriptDebuggerWidgetFactoryInterface *widgetFactory() const;
    void setWidgetFactory( QScriptDebuggerWidgetFactoryInterface *factory );

    QAction *interruptAction( QObject *parent ) const;
    QAction *continueAction( QObject *parent ) const;
    QAction *stepIntoAction( QObject *parent ) const;
    QAction *stepOverAction( QObject *parent ) const;
    QAction *stepOutAction( QObject *parent ) const;
    QAction *runToCursorAction( QObject *parent ) const;
    QAction *runToNewScriptAction( QObject *parent ) const;

    QAction *toggleBreakpointAction( QObject *parent ) const;

    QAction *findInScriptAction( QObject *parent ) const;
    QAction *findNextInScriptAction( QObject *parent ) const;
    QAction *findPreviousInScriptAction( QObject *parent ) const;
    QAction *goToLineAction( QObject *parent ) const;

    QAction *clearDebugOutputAction( QObject *parent ) const;
    QAction *clearConsoleAction( QObject *parent ) const;
    QAction *clearErrorLogAction( QObject *parent ) const;

    QMenu *createStandardMenu( QWidget *widgetParent, QObject *actionParent );

#ifndef QT_NO_TOOLBAR
    QToolBar *createStandardToolBar( QWidget *widgetParent, QObject *actionParent );
#endif

    bool eventFilter( QObject *, QEvent *e );
    bool isInteractive() const;

    LSCS_SIGNAL_1( Public, void stopped() )
    LSCS_SIGNAL_2( stopped )
    LSCS_SIGNAL_1( Public, void started() )
    LSCS_SIGNAL_2( started )

protected:
    void timerEvent( QTimerEvent *e );

    QScriptDebugger( QScriptDebuggerPrivate &dd, QObject *parent );

private:
    Q_DECLARE_PRIVATE( QScriptDebugger )
    Q_DISABLE_COPY( QScriptDebugger )


    LSCS_SLOT_1( Private, void _q_onLineEntered( const QString &un_named_arg1 ) )
    LSCS_SLOT_2( _q_onLineEntered )

    LSCS_SLOT_1( Private, void _q_onCurrentFrameChanged( int un_named_arg1 ) )
    LSCS_SLOT_2( _q_onCurrentFrameChanged )

    LSCS_SLOT_1( Private, void _q_onCurrentScriptChanged( qint64 un_named_arg1 ) )
    LSCS_SLOT_2( _q_onCurrentScriptChanged )

    LSCS_SLOT_1( Private, void _q_onScriptLocationSelected( int un_named_arg1 ) )
    LSCS_SLOT_2( _q_onScriptLocationSelected )

    LSCS_SLOT_1( Private, void _q_interrupt() )
    LSCS_SLOT_2( _q_interrupt )

    LSCS_SLOT_1( Private, void _q_continue() )
    LSCS_SLOT_2( _q_continue )

    LSCS_SLOT_1( Private, void _q_stepInto() )
    LSCS_SLOT_2( _q_stepInto )

    LSCS_SLOT_1( Private, void _q_stepOver() )
    LSCS_SLOT_2( _q_stepOver )

    LSCS_SLOT_1( Private, void _q_stepOut() )
    LSCS_SLOT_2( _q_stepOut )

    LSCS_SLOT_1( Private, void _q_runToCursor() )
    LSCS_SLOT_2( _q_runToCursor )

    LSCS_SLOT_1( Private, void _q_runToNewScript() )
    LSCS_SLOT_2( _q_runToNewScript )

    LSCS_SLOT_1( Private, void _q_toggleBreakpoint() )
    LSCS_SLOT_2( _q_toggleBreakpoint )

    LSCS_SLOT_1( Private, void _q_clearDebugOutput() )
    LSCS_SLOT_2( _q_clearDebugOutput )

    LSCS_SLOT_1( Private, void _q_clearErrorLog() )
    LSCS_SLOT_2( _q_clearErrorLog )

    LSCS_SLOT_1( Private, void _q_clearConsole() )
    LSCS_SLOT_2( _q_clearConsole )

    LSCS_SLOT_1( Private, void _q_findInScript() )
    LSCS_SLOT_2( _q_findInScript )

    LSCS_SLOT_1( Private, void _q_findNextInScript() )
    LSCS_SLOT_2( _q_findNextInScript )

    LSCS_SLOT_1( Private, void _q_findPreviousInScript() )
    LSCS_SLOT_2( _q_findPreviousInScript )

    LSCS_SLOT_1( Private, void _q_onFindCodeRequest( const QString &un_named_arg1, int un_named_arg2 ) )
    LSCS_SLOT_2( _q_onFindCodeRequest )

    LSCS_SLOT_1( Private, void _q_goToLine() )
    LSCS_SLOT_2( _q_goToLine )


};

QT_END_NAMESPACE

#endif
