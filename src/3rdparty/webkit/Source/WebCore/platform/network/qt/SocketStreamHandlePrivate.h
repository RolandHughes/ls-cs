/*
 * Copyright (C) 2010 Nokia Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SocketStreamHandlePrivate_h
#define SocketStreamHandlePrivate_h

#include "SocketStreamHandleBase.h"

#include <QSslSocket>
#include <QTcpSocket>
#include <qsslerror.h>

namespace WebCore
{

class AuthenticationChallenge;
class Credential;
class SocketStreamHandleClient;
class SocketStreamHandlePrivate;

class SocketStreamHandlePrivate : public QObject
{
    WEB_LSCS_OBJECT( SocketStreamHandlePrivate )

public:
    SocketStreamHandlePrivate( SocketStreamHandle *, const KURL & );
    ~SocketStreamHandlePrivate();

public :
    WEB_LSCS_SLOT_1( Public, void socketConnected() )
    WEB_LSCS_SLOT_2( socketConnected )
    WEB_LSCS_SLOT_1( Public, void socketReadyRead() )
    WEB_LSCS_SLOT_2( socketReadyRead )
    WEB_LSCS_SLOT_1( Public, int send( const char *data,int len ) )
    WEB_LSCS_SLOT_2( send )
    WEB_LSCS_SLOT_1( Public, void close() )
    WEB_LSCS_SLOT_2( close )
    WEB_LSCS_SLOT_1( Public, void socketSentData() )
    WEB_LSCS_SLOT_2( socketSentData )
    WEB_LSCS_SLOT_1( Public, void socketClosed() )
    WEB_LSCS_SLOT_2( socketClosed )
    WEB_LSCS_SLOT_1( Public, void socketError( QAbstractSocket::SocketError error ) )
    WEB_LSCS_SLOT_2( socketError )
    WEB_LSCS_SLOT_1( Public, void socketClosedCallback() )
    WEB_LSCS_SLOT_2( socketClosedCallback )
    WEB_LSCS_SLOT_1( Public, void socketErrorCallback( int error ) )
    WEB_LSCS_SLOT_2( socketErrorCallback )

#ifdef LSCS_SSL
    WEB_LSCS_SLOT_1( Public, void socketSslErrors( const QList <QSslError> &error ) )
    WEB_LSCS_SLOT_2( socketSslErrors )
#endif

public:
    QTcpSocket *m_socket;
    SocketStreamHandle *m_streamHandle;
};

}

#endif
