/***********************************************************************
*
* Copyright (c) 2012-2025 Barbara Geller
* Copyright (c) 2012-2025 Ansel Sermersheim
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

#ifndef QPLATFORMDEFS_H
#define QPLATFORMDEFS_H

#include <qglobal.h>

// configure generates the following h file and it contains the defines for have_x_h
#include <lscs_config.h>

#ifdef HAVE_FEATURES_H
#include <features.h>
#endif

#ifdef HAVE_PTHREAD_H
#include <pthread.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#endif

#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif

#ifdef HAVE_GRP_H
#include <grp.h>
#endif

#ifdef HAVE_PWD_H
#include <pwd.h>
#endif

#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif

#ifdef HAVE_DLFCN_H
#include <dlfcn.h>
#endif

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif

#ifdef HAVE_SYS_IPC_H
#include <sys/ipc.h>
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#ifdef HAVE_SYS_SHM_H
#include <sys/shm.h>
#endif

#ifdef HAVE_SOCKET_H
#include <sys/socket.h>
#endif

#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif

#ifdef HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif

#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif

#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif

#ifdef HAVE_NET_IF_H
#include <net/if.h>
#endif


// ***********

#if defined(Q_OS_WIN)

#if defined(UNICODE) && ! defined(_UNICODE)
#define _UNICODE
#endif

#include <lscs_windows.h>

#include <direct.h>
#include <errno.h>
#include <fcntl.h>
#include <io.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <tchar.h>

#if ! defined(_WIN32_WINNT) || (_WIN32_WINNT-0 < 0x0500)

enum EXTENDED_NAME_FORMAT
{
    NameUnknown           = 0,
    NameFullyQualifiedDN  = 1,
    NameSamCompatible     = 2,
    NameDisplay           = 3,
    NameUniqueId          = 6,
    NameCanonical         = 7,
    NameUserPrincipal     = 8,
    NameCanonicalEx       = 9,
    NameServicePrincipal  = 10,
    NameDnsDomain         = 12
};
using PEXTENDED_NAME_FORMAT = *EXTENDED_NAME_FORMAT;

#endif

#ifdef LSCS_LARGEFILE_SUPPORT

#define LSCS_STATBUF            struct _stati64      // non-ANSI defs
#define LSCS_STATBUF4TSTAT      struct _stati64      // non-ANSI defs
#define LSCS_STAT               ::_stati64
#define LSCS_FSTAT              ::_fstati64

#else
#define LSCS_STATBUF            struct _stat         // non-ANSI defs
#define LSCS_STATBUF4TSTAT      struct _stat         // non-ANSI defs
#define LSCS_STAT               ::_stat
#define LSCS_FSTAT              ::_fstat

#endif

#define LSCS_STAT_REG           _S_IFREG
#define LSCS_STAT_DIR           _S_IFDIR
#define LSCS_STAT_MASK          _S_IFMT

#if defined(_S_IFLNK)
#define LSCS_STAT_LNK           _S_IFLNK
#endif

#define LSCS_FILENO             _fileno
#define LSCS_OPEN               ::_open
#define LSCS_CLOSE              ::_close

//  block A
#ifdef LSCS_LARGEFILE_SUPPORT
#define LSCS_LSEEK              ::_lseeki64

#ifndef UNICODE
#define LSCS_TSTAT              ::_stati64
#else
#define LSCS_TSTAT              ::_wstati64
#endif

#else
#define LSCS_LSEEK              ::_lseek

#ifndef UNICODE
#define LSCS_TSTAT              ::_stat
#else
#define LSCS_TSTAT              ::_wstat
#endif

#endif  // end block A

#define LSCS_READ               ::_read
#define LSCS_WRITE              ::_write
#define LSCS_ACCESS             ::_access
#define LSCS_GETCWD             ::_getcwd
#define LSCS_CHDIR              ::_chdir
#define LSCS_MKDIR              ::_mkdir
#define LSCS_RMDIR              ::_rmdir

#define LSCS_OPEN_LARGEFILE     0
#define LSCS_OPEN_RDONLY        _O_RDONLY
#define LSCS_OPEN_WRONLY        _O_WRONLY
#define LSCS_OPEN_RDWR          _O_RDWR
#define LSCS_OPEN_CREAT         _O_CREAT
#define LSCS_OPEN_TRUNC         _O_TRUNC
#define LSCS_OPEN_APPEND        _O_APPEND

#if defined(O_TEXT)
#define LSCS_OPEN_TEXT         _O_TEXT
#define LSCS_OPEN_BINARY       _O_BINARY
#endif

#define LSCS_FPOS_T              fpos_t
#define LSCS_OFF_T               long

#define LSCS_FOPEN               ::fopen
#define LSCS_FSEEK               ::fseek
#define LSCS_FTELL               ::ftell
#define LSCS_FGETPOS             ::fgetpos
#define LSCS_FSETPOS             ::fsetpos

#ifdef LSCS_LARGEFILE_SUPPORT
#undef LSCS_FSEEK
#undef LSCS_FTELL
#undef LSCS_OFF_T

#define LSCS_FSEEK              ::fseeko64
#define LSCS_FTELL              ::ftello64
#define LSCS_OFF_T              off64_t
#endif

#define LSCS_SNPRINTF           ::_snprintf
#define LSCS_VSNPRINTF          ::_vsnprintf

#define F_OK                  0
#define X_OK                  1
#define W_OK                  2
#define R_OK                  4


// ***********
#elif defined(Q_OS_UNIX) && ! defined(Q_OS_DARWIN)

// may need to reset default environment if _BSD_SOURCE is defined

#define _XOPEN_SOURCE 700

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#define LSCS_USE_XOPEN_LFS_EXTENSIONS
#include <qplatformposix.h>

#undef LSCS_SOCKLEN_T
#define LSCS_SOCKLEN_T          socklen_t

#define LSCS_SNPRINTF           ::snprintf
#define LSCS_VSNPRINTF          ::vsnprintf


// ***********
#elif defined(Q_OS_DARWIN)

#include <qplatformposix.h>

#undef LSCS_OPEN_LARGEFILE
#define LSCS_OPEN_LARGEFILE     0

#undef LSCS_SOCKLEN_T
#define LSCS_SOCKLEN_T          socklen_t

#define LSCS_SNPRINTF           ::snprintf
#define LSCS_VSNPRINTF          ::vsnprintf


// ***********
#elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_DRAGONFLY)

#include <qplatformposix.h>

#undef LSCS_OPEN_LARGEFILE
#define LSCS_OPEN_LARGEFILE    0

#define LSCS_SNPRINTF          ::snprintf
#define LSCS_VSNPRINTF         ::vsnprintf

#endif

#endif
