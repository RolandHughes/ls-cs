/***********************************************************************
*
* Copyright (c) 2024 Roland Hughes  DBA  Logikal Solutions
*
* This file is part of LsCs.
*
* LsCs is free software. You can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* LsCs is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://www.gnu.org/licenses/
*
***********************************************************************/
#include <lscsioutils.h>
#include <qdir.h>
#include <qstringlist.h>

#if defined(Q_OS_UNIX)
#include <pwd.h>
#include <unistd.h>        // for pathconf() on OS X

#elif defined(Q_OS_WIN)
#include <lscs_windows.h>
#endif

#ifdef Q_OS_UNIX
QString lscs_tildeExpansion( const QString &path, bool *expanded )
{
    if ( expanded != nullptr )
    {
        *expanded = false;
    }

    if ( ! path.startsWith( '~' ) )
    {
        return path;
    }

    QString retval = path;

    QStringList tokens = retval.split( QDir::separator() );

    if ( tokens.first() == "~" )
    {
        retval.replace( 0, 1, QDir::homePath() );

    }
    else
    {
        QString userName = tokens.first();
        userName.remove( 0, 1 );

#if defined(_POSIX_THREAD_SAFE_FUNCTIONS) && ! defined(Q_OS_OPENBSD)
        passwd pw;
        passwd *tmpPw;
        char buf[200];

        const int bufSize = sizeof( buf );
        int err = getpwnam_r( userName.constData(), &pw, buf, bufSize, &tmpPw );

        if ( err || ! tmpPw )
        {
            return retval;
        }

        const QString homePath = QString::fromUtf8( pw.pw_dir );

#else
        passwd *pw = getpwnam( userName.constData() );

        if ( ! pw )
        {
            return ret;
        }

        const QString homePath = QString::frommUtf8( pw->pw_dir );
#endif

        retval.replace( 0, tokens.first().length(), homePath );
    }

    if ( expanded != nullptr )
    {
        *expanded = true;
    }

    return retval;
}
#endif
