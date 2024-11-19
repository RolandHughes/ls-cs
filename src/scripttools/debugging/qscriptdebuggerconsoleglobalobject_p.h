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

#ifndef QSCRIPTDEBUGGERCONSOLEGLOBALOBJECT_P_H
#define QSCRIPTDEBUGGERCONSOLEGLOBALOBJECT_P_H

#include <QtCore/qobject.h>
#include <QtCore/qstringlist.h>
#include <qscriptdebuggerconsolecommandgroupdata_p.h>
#include <qscriptdebuggerconsolecommand_p.h>

LSCS_BEGIN_NAMESPACE

class QScriptDebuggerCommandSchedulerInterface;
class QScriptMessageHandlerInterface;
class QScriptDebuggerResponseHandlerInterface;
class QScriptDebuggerConsole;
class QScriptDebuggerValue;
class QScriptDebuggerCommand;
class QScriptBreakpointData;
class QScriptDebuggerConsoleGlobalObjectPrivate;

class QScriptDebuggerConsoleGlobalObject : public QObject
{
    SCRIPT_T_LSCS_OBJECT( QScriptDebuggerConsoleGlobalObject )

public:
    QScriptDebuggerConsoleGlobalObject( QObject *parent = nullptr );
    ~QScriptDebuggerConsoleGlobalObject();

    QScriptDebuggerCommandSchedulerInterface *scheduler() const;
    void setScheduler( QScriptDebuggerCommandSchedulerInterface *scheduler );

    QScriptDebuggerResponseHandlerInterface *responseHandler() const;
    void setResponseHandler( QScriptDebuggerResponseHandlerInterface *responseHandler );

    QScriptMessageHandlerInterface *messageHandler() const;
    void setMessageHandler( QScriptMessageHandlerInterface *messageHandler );

    QScriptDebuggerConsole *console() const;
    void setConsole( QScriptDebuggerConsole *console );

    LSCS_SLOT_1( Public, int scheduleInterrupt() )
    LSCS_SLOT_2( scheduleInterrupt )
    LSCS_SLOT_1( Public, int scheduleContinue() )
    LSCS_SLOT_2( scheduleContinue )
    LSCS_SLOT_1( Public, int scheduleStepInto( int count = 1 ) )
    LSCS_SLOT_2( scheduleStepInto )
    LSCS_SLOT_1( Public, int scheduleStepOver( int count = 1 ) )
    LSCS_SLOT_2( scheduleStepOver )
    LSCS_SLOT_1( Public, int scheduleStepOut() )
    LSCS_SLOT_2( scheduleStepOut )
    LSCS_SLOT_1( Public, int scheduleRunToLocation( const QString &fileName, int lineNumber ) )
    LSCS_SLOT_2( scheduleRunToLocation )
    LSCS_SLOT_1( Public, int scheduleRunToLocation( qint64 scriptId, int lineNumber ) )
    LSCS_SLOT_2( scheduleRunToLocation )
    LSCS_SLOT_1( Public, int scheduleForceReturn( int contextIndex, const QScriptDebuggerValue &value ) )
    LSCS_SLOT_2( scheduleForceReturn )

    LSCS_SLOT_1( Public, int scheduleSetBreakpoint( const QScriptBreakpointData &data ) )
    LSCS_SLOT_2( scheduleSetBreakpoint )
    LSCS_SLOT_1( Public, int scheduleDeleteBreakpoint( int id ) )
    LSCS_SLOT_2( scheduleDeleteBreakpoint )
    LSCS_SLOT_1( Public, int scheduleDeleteAllBreakpoints() )
    LSCS_SLOT_2( scheduleDeleteAllBreakpoints )
    LSCS_SLOT_1( Public, int scheduleGetBreakpoints() )
    LSCS_SLOT_2( scheduleGetBreakpoints )
    LSCS_SLOT_1( Public, int scheduleGetBreakpointData( int id ) )
    LSCS_SLOT_2( scheduleGetBreakpointData )
    LSCS_SLOT_1( Public, int scheduleSetBreakpointData( int id, const QScriptBreakpointData &data ) )
    LSCS_SLOT_2( scheduleSetBreakpointData )

    LSCS_SLOT_1( Public, int scheduleGetScripts() )
    LSCS_SLOT_2( scheduleGetScripts )
    LSCS_SLOT_1( Public, int scheduleGetScriptData( qint64 id ) )
    LSCS_SLOT_2( scheduleGetScriptData )
    LSCS_SLOT_1( Public, int scheduleScriptsCheckpoint() )
    LSCS_SLOT_2( scheduleScriptsCheckpoint )
    LSCS_SLOT_1( Public, int scheduleGetScriptsDelta() )
    LSCS_SLOT_2( scheduleGetScriptsDelta )
    LSCS_SLOT_1( Public, int scheduleResolveScript( const QString &fileName ) )
    LSCS_SLOT_2( scheduleResolveScript )

    LSCS_SLOT_1( Public, int scheduleGetBacktrace() )
    LSCS_SLOT_2( scheduleGetBacktrace )
    LSCS_SLOT_1( Public, int scheduleGetThisObject( int contextIndex ) )
    LSCS_SLOT_2( scheduleGetThisObject )
    LSCS_SLOT_1( Public, int scheduleGetActivationObject( int contextIndex ) )
    LSCS_SLOT_2( scheduleGetActivationObject )
    LSCS_SLOT_1( Public, int scheduleGetContextCount() )
    LSCS_SLOT_2( scheduleGetContextCount )
    LSCS_SLOT_1( Public, int scheduleGetContextInfo( int contextIndex ) )
    LSCS_SLOT_2( scheduleGetContextInfo )

    LSCS_SLOT_1( Public, int scheduleNewScriptValueIterator( const QScriptDebuggerValue &object ) )
    LSCS_SLOT_2( scheduleNewScriptValueIterator )
    LSCS_SLOT_1( Public, int scheduleGetPropertiesByIterator( int id, int count ) )
    LSCS_SLOT_2( scheduleGetPropertiesByIterator )
    LSCS_SLOT_1( Public, int scheduleDeleteScriptValueIterator( int id ) )
    LSCS_SLOT_2( scheduleDeleteScriptValueIterator )

    LSCS_SLOT_1( Public, int scheduleEvaluate( int contextIndex, const QString &program, const QString &fileName = QString(),
               intlineNumber = 1 ) )
    LSCS_SLOT_2( scheduleEvaluate )

    LSCS_SLOT_1( Public, int scheduleScriptValueToString( const QScriptDebuggerValue &value ) )
    LSCS_SLOT_2( scheduleScriptValueToString )

    LSCS_SLOT_1( Public, int scheduleClearExceptions() )
    LSCS_SLOT_2( scheduleClearExceptions )

    LSCS_SLOT_1( Public, int scheduleCommand( const QScriptDebuggerCommand &command ) )
    LSCS_SLOT_2( scheduleCommand )

    // message handler
    LSCS_SLOT_1( Public, void message( const QString &text, const QString &fileName = QString(), intlineNumber = -1,
                                     intcolumnNumber = -1 ) )
    LSCS_SLOT_2( message )
    LSCS_SLOT_1( Public, void warning( const QString &text, const QString &fileName = QString(), intlineNumber = -1,
                                     intcolumnNumber = -1 ) )
    LSCS_SLOT_2( warning )
    LSCS_SLOT_1( Public, void error( const QString &text, const QString &fileName = QString(), intlineNumber = -1,
                                   intcolumnNumber = -1 ) )
    LSCS_SLOT_2( error )

    // console state
    LSCS_SLOT_1( Public, int getCurrentFrameIndex() )
    LSCS_SLOT_2( getCurrentFrameIndex )
    LSCS_SLOT_1( Public, void setCurrentFrameIndex( int index ) )
    LSCS_SLOT_2( setCurrentFrameIndex )
    LSCS_SLOT_1( Public, qint64 getCurrentScriptId() )
    LSCS_SLOT_2( getCurrentScriptId )
    LSCS_SLOT_1( Public, void setCurrentScriptId( qint64 id ) )
    LSCS_SLOT_2( setCurrentScriptId )
    LSCS_SLOT_1( Public, qint64 getSessionId() )
    LSCS_SLOT_2( getSessionId )
    LSCS_SLOT_1( Public, int getCurrentLineNumber() )
    LSCS_SLOT_2( getCurrentLineNumber )
    LSCS_SLOT_1( Public, void setCurrentLineNumber( int lineNumber ) )
    LSCS_SLOT_2( setCurrentLineNumber )

    // command introspection
    LSCS_SLOT_1( Public, QScriptDebuggerConsoleCommandGroupMap getCommandGroups() )
    LSCS_SLOT_2( getCommandGroups )
    LSCS_SLOT_1( Public, QScriptDebuggerConsoleCommand *findCommand( const QString &command )const )
    LSCS_SLOT_2( findCommand )
    LSCS_SLOT_1( Public, QScriptDebuggerConsoleCommandList getCommandsInGroup( const QString &name )const )
    LSCS_SLOT_2( getCommandsInGroup )
    LSCS_SLOT_1( Public, QStringList getCommandCompletions( const QString &prefix )const )
    LSCS_SLOT_2( getCommandCompletions )

    LSCS_SLOT_1( Public, bool checkSyntax( const QString &program ) )
    LSCS_SLOT_2( checkSyntax )

    LSCS_SLOT_1( Public, void setEvaluateAction( int action ) )
    LSCS_SLOT_2( setEvaluateAction )

private:
    Q_DECLARE_PRIVATE( QScriptDebuggerConsoleGlobalObject )
    Q_DISABLE_COPY( QScriptDebuggerConsoleGlobalObject )
};

LSCS_END_NAMESPACE

#endif
