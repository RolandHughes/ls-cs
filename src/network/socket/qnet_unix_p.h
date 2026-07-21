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

#ifndef QNET_UNIX_P_H
#define QNET_UNIX_P_H

#include <qcore_unix_p.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <resolv.h>
#include <sys/socket.h>
#include <sys/types.h>

// Almost always the same. If not, specify in qplatformdefs.h.
#if !defined(LSCS_SOCKOPTLEN_T)
# define LSCS_SOCKOPTLEN_T LSCS_SOCKLEN_T
#endif

// UnixWare 7 redefines socket -> _socket
static inline int lscs_safe_socket( int domain, int type, int protocol, int flags = 0 )
{
    Q_ASSERT( ( flags & ~O_NONBLOCK ) == 0 );

    int fd;

#ifdef LSCS_THREADSAFE_CLOEXEC
    int newtype = type | SOCK_CLOEXEC;

    if ( flags & O_NONBLOCK )
    {
        newtype |= SOCK_NONBLOCK;
    }

    fd = ::socket( domain, newtype, protocol );
    return fd;
#else

    fd = ::socket( domain, type, protocol );

    if ( fd == -1 )
    {
        return -1;
    }

    ::fcntl( fd, F_SETFD, FD_CLOEXEC );

    // set non-block too?
    if ( flags & O_NONBLOCK )
    {
        ::fcntl( fd, F_SETFL, ::fcntl( fd, F_GETFL ) | O_NONBLOCK );
    }

    return fd;
#endif
}

// Tru64 redefines accept -> _accept with _XOPEN_SOURCE_EXTENDED
static inline int lscs_safe_accept( int s, struct sockaddr *addr, LSCS_SOCKLEN_T *addrlen, int flags = 0 )
{
    Q_ASSERT( ( flags & ~O_NONBLOCK ) == 0 );

    int fd;
#ifdef LSCS_THREADSAFE_CLOEXEC
    // use accept4
    int sockflags = SOCK_CLOEXEC;

    if ( flags & O_NONBLOCK )
    {
        sockflags |= SOCK_NONBLOCK;
    }

    fd = ::accept4( s, addr, static_cast<LSCS_SOCKLEN_T *>( addrlen ), sockflags );
    return fd;
#else

    fd = ::accept( s, addr, static_cast<LSCS_SOCKLEN_T *>( addrlen ) );

    if ( fd == -1 )
    {
        return -1;
    }

    ::fcntl( fd, F_SETFD, FD_CLOEXEC );

    // set non-block too?
    if ( flags & O_NONBLOCK )
    {
        ::fcntl( fd, F_SETFL, ::fcntl( fd, F_GETFL ) | O_NONBLOCK );
    }

    return fd;
#endif
}

// UnixWare 7 redefines listen -> _listen
static inline int lscs_safe_listen( int s, int backlog )
{
    return ::listen( s, backlog );
}

static inline int lscs_safe_connect( int sockfd, const struct sockaddr *addr, LSCS_SOCKLEN_T addrlen )
{
    int ret;

    // Solaris e.g. expects a non-const 2nd parameter
    EINTR_LOOP( ret, LSCS_SOCKET_CONNECT( sockfd, const_cast<struct sockaddr *>( addr ), addrlen ) );
    return ret;
}
#undef LSCS_SOCKET_CONNECT
#define LSCS_SOCKET_CONNECT lscs_safe_connect

#if defined(socket)
# undef socket
#endif
#if defined(accept)
# undef accept
#endif
#if defined(listen)
# undef listen
#endif

template <typename T>
static inline int lscs_safe_ioctl( int sockfd, int request, T arg )
{
    return ::ioctl( sockfd, request, arg );
}

static inline in_addr_t lscs_safe_inet_addr( const char *cp )
{
    return ::inet_addr( cp );
}

static inline ssize_t lscs_safe_sendmsg( int sockfd, const struct msghdr *msg, int flags )
{
#ifdef MSG_NOSIGNAL
    flags |= MSG_NOSIGNAL;
#else
    lscs_ignore_sigpipe();
#endif

    int ret;
    EINTR_LOOP( ret, ::sendmsg( sockfd, msg, flags ) );

    return ret;
}
static inline int lscs_safe_recvmsg( int sockfd, struct msghdr *msg, int flags )
{
    int ret;

    EINTR_LOOP( ret, ::recvmsg( sockfd, msg, flags ) );
    return ret;
}

#endif // QNET_UNIX_P_H
