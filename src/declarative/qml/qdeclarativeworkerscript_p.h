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

#ifndef QDECLARATIVEWORKERSCRIPT_P_H
#define QDECLARATIVEWORKERSCRIPT_P_H

#include <qdeclarative.h>
#include <qdeclarativeparserstatus.h>
#include <QtCore/qthread.h>
#include <QtScript/qscriptvalue.h>
#include <QtCore/qurl.h>

LSCS_BEGIN_NAMESPACE

class QDeclarativeWorkerScript;
class QDeclarativeWorkerScriptEnginePrivate;

class QDeclarativeWorkerScriptEngine : public QThread
{
    DECL_LSCS_OBJECT( QDeclarativeWorkerScriptEngine )

public:
    QDeclarativeWorkerScriptEngine( QDeclarativeEngine *parent = 0 );
    virtual ~QDeclarativeWorkerScriptEngine();

    int registerWorkerScript( QDeclarativeWorkerScript * );
    void removeWorkerScript( int );
    void executeUrl( int, const QUrl & );
    void sendMessage( int, const QVariant & );

protected:
    virtual void run();

private:
    QDeclarativeWorkerScriptEnginePrivate *d;
};

class QDeclarativeWorkerScript : public QObject, public QDeclarativeParserStatus
{
    DECL_LSCS_OBJECT( QDeclarativeWorkerScript )
    DECL_LSCS_PROPERTY_READ( source, source )
    DECL_LSCS_PROPERTY_WRITE( source, setSource )
    DECL_LSCS_PROPERTY_NOTIFY( source, sourceChanged )

    LSCS_INTERFACES( QDeclarativeParserStatus )
public:
    QDeclarativeWorkerScript( QObject *parent = nullptr );
    virtual ~QDeclarativeWorkerScript();

    QUrl source() const;
    void setSource( const QUrl & );

    DECL_LSCS_SLOT_1( Public, void sendMessage( const QScriptValue &un_named_arg1 ) )
    DECL_LSCS_SLOT_2( sendMessage )

    DECL_LSCS_SIGNAL_1( Public, void sourceChanged() )
    DECL_LSCS_SIGNAL_2( sourceChanged )
    DECL_LSCS_SIGNAL_1( Public, void message( const QScriptValue &messageObject ) )
    DECL_LSCS_SIGNAL_2( message, messageObject )

protected:
    virtual void classBegin();
    virtual void componentComplete();
    virtual bool event( QEvent * );

private:
    QDeclarativeWorkerScriptEngine *engine();
    QDeclarativeWorkerScriptEngine *m_engine;
    int m_scriptId;
    QUrl m_source;
    bool m_componentComplete;
};

LSCS_END_NAMESPACE

QML_DECLARE_TYPE( QDeclarativeWorkerScript )

#endif // QDECLARATIVEWORKERSCRIPT_P_H
