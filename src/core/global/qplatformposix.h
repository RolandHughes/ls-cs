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

#ifndef Q_POSIX_QPLATFORMDEFS_H
#define Q_POSIX_QPLATFORMDEFS_H

#if defined(LSCS_USE_XOPEN_LFS_EXTENSIONS) && defined(LSCS_LARGEFILE_SUPPORT)

#define LSCS_STATBUF              struct stat64
#define LSCS_FPOS_T               fpos64_t
#define LSCS_OFF_T                off64_t

#define LSCS_STAT                 ::stat64
#define LSCS_LSTAT                ::lstat64
#define LSCS_TRUNCATE             ::truncate64

// File I/O
#define LSCS_OPEN                 ::open64
#define LSCS_LSEEK                ::lseek64
#define LSCS_FSTAT                ::fstat64
#define LSCS_FTRUNCATE            ::ftruncate64

// Standard C89
#define LSCS_FOPEN                ::fopen64
#define LSCS_FSEEK                ::fseeko64
#define LSCS_FTELL                ::ftello64
#define LSCS_FGETPOS              ::fgetpos64
#define LSCS_FSETPOS              ::fsetpos64

#define LSCS_MMAP                 ::mmap64

#else

#define LSCS_FPOS_T               fpos_t
#define LSCS_OFF_T                long

#define LSCS_FOPEN                ::fopen
#define LSCS_FSEEK                ::fseek
#define LSCS_FTELL                ::ftell
#define LSCS_FGETPOS              ::fgetpos
#define LSCS_FSETPOS              ::fsetpos

#define LSCS_STATBUF              struct stat

#define LSCS_STAT                 ::stat
#define LSCS_LSTAT                ::lstat
#define LSCS_TRUNCATE             ::truncate

// File I/O
#define LSCS_OPEN                 ::open
#define LSCS_LSEEK                ::lseek
#define LSCS_FSTAT                ::fstat
#define LSCS_FTRUNCATE            ::ftruncate

// Posix extensions to C89
#if ! defined(LSCS_USE_XOPEN_LFS_EXTENSIONS) && ! defined(LSCS_NO_USE_FSEEKO)

#undef LSCS_OFF_T
#define LSCS_OFF_T                off_t

#undef LSCS_FSEEK
#define LSCS_FSEEK                ::fseeko

#undef LSCS_FTELL
#define LSCS_FTELL                ::ftello

#endif

#define LSCS_MMAP                 ::mmap

#endif

#define LSCS_STAT_MASK            S_IFMT
#define LSCS_STAT_REG             S_IFREG
#define LSCS_STAT_DIR             S_IFDIR
#define LSCS_STAT_LNK             S_IFLNK

#define LSCS_ACCESS               ::access
#define LSCS_GETCWD               ::getcwd
#define LSCS_CHDIR                ::chdir
#define LSCS_MKDIR                ::mkdir
#define LSCS_RMDIR                ::rmdir

// File I/O
#define LSCS_CLOSE                ::close
#define LSCS_READ                 ::read
#define LSCS_WRITE                ::write

#define LSCS_OPEN_LARGEFILE       0
#define LSCS_OPEN_RDONLY          O_RDONLY
#define LSCS_OPEN_WRONLY          O_WRONLY
#define LSCS_OPEN_RDWR            O_RDWR
#define LSCS_OPEN_CREAT           O_CREAT
#define LSCS_OPEN_TRUNC           O_TRUNC
#define LSCS_OPEN_APPEND          O_APPEND

// Posix extensions to C89
#define LSCS_FILENO               fileno

// Directory iteration
#define LSCS_DIR                  DIR

#define LSCS_OPENDIR              ::opendir
#define LSCS_CLOSEDIR             ::closedir

#if defined(LSCS_LARGEFILE_SUPPORT) && defined(LSCS_USE_XOPEN_LFS_EXTENSIONS) && ! defined(LSCS_NO_READDIR64)
#define LSCS_DIRENT               struct dirent64
#define LSCS_READDIR              ::readdir64
#define LSCS_READDIR_R            ::readdir64_r
#else
#define LSCS_DIRENT               struct dirent
#define LSCS_READDIR              ::readdir
#define LSCS_READDIR_R            ::readdir_r
#endif

#define LSCS_SOCKLEN_T            socklen_t

#define LSCS_SOCKET_CONNECT       ::connect
#define LSCS_SOCKET_BIND          ::bind

#define LSCS_SIGNAL_RETTYPE       void
#define LSCS_SIGNAL_ARGS          int
#define LSCS_SIGNAL_IGNORE        SIG_IGN

#endif
