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

#include <qdiriterator.h>

#include <qalgorithms.h>
#include <qabstractfileengine.h>
#include <qset.h>
#include <qstack.h>
#include <qregularexpression.h>
#include <qvariant.h>

#include <qdir_p.h>
#include <qfileinfo_p.h>
#include <qfilesystemiterator_p.h>
#include <qfilesystementry_p.h>
#include <qfilesystemmetadata_p.h>
#include <qfilesystemengine_p.h>

static const QString CURRENT_DOT_DIR(".");
static const QString PARENT_DOT_DIR("..");

template <class Iterator>
class QDirIteratorPrivateIteratorStack : public QStack<Iterator *>
{
public:
    ~QDirIteratorPrivateIteratorStack()
    {
        qDeleteAll( *this );
    }
};

class QDirIteratorPrivate
{
public:
    QDirIteratorPrivate( const QFileSystemEntry &entry, const QStringList &nameFilters,
                         QDir::Filters filters, QDirIterator::IteratorFlags flags, bool resolveEngine = true );

    void advance();

    bool entryMatches( const QString &fileName, const QFileInfo &fileInfo );
    void pushDirectory( const QFileInfo &fileInfo );
    void checkAndPushDirectory( const QFileInfo & );
    bool matchesFilters( const QString &fileName, const QFileInfo &fi ) const;

    QScopedPointer<QAbstractFileEngine> m_engine;

    QFileSystemEntry m_dirEntry;
    QStringList m_nameFilters;
    QDir::Filters m_filters;
    const QDirIterator::IteratorFlags m_iteratorFlags;

    QVector<QRegularExpression> m_nameRegExps;

    QDirIteratorPrivateIteratorStack<QAbstractFileEngineIterator> m_fileEngineIterators;

#ifndef LSCS_NO_FILESYSTEMITERATOR
    QDirIteratorPrivateIteratorStack<QFileSystemIterator> m_nativeIterators;
#endif

    QFileInfo m_currentFileInfo;
    QFileInfo m_nextFileInfo;

    // Loop protection
    QSet<QString> m_visitedLinks;
};

QDirIteratorPrivate::QDirIteratorPrivate( const QFileSystemEntry &entry, const QStringList &nameFilters,
        QDir::Filters filters, QDirIterator::IteratorFlags flags, bool resolveEngine )
    : m_dirEntry( entry ), m_nameFilters( nameFilters.contains( "*" ) ? QStringList() : nameFilters ),
      m_filters( QDir::NoFilter == filters ? QDir::AllEntries : filters ), m_iteratorFlags( flags )
{
    if ( flags & QDirIterator::NoDot )
    {
        m_filters |= QDir::NoDot;
    }

    if ( flags & QDirIterator::NoDotDot )
    {
        m_filters |= QDir::NoDotDot;
    }

    if ( flags & QDirIterator::NoDotAndDotDot )
    {
        m_filters |= QDir::NoDotAndDotDot;
    }

    m_nameRegExps.reserve( nameFilters.size() );

    for ( int i = 0; i < m_nameFilters.size(); ++i )
    {
        QPatternOptionFlags options = QPatternOption::WildcardOption | QPatternOption::ExactMatchOption;

        if ( ! ( m_filters & QDir::CaseSensitive ) )
        {
            options |= QPatternOption::CaseInsensitiveOption;
        }

        QRegularExpression regExp( nameFilters.at( i ), options );
        m_nameRegExps.append( regExp );
    }

    QFileSystemMetaData metaData;

    if ( resolveEngine )
    {
        m_engine.reset( QFileSystemEngine::resolveEntryAndCreateLegacyEngine( m_dirEntry, metaData ) );
    }

    QFileInfo fileInfo( new QFileInfoPrivate( m_dirEntry, metaData ) );

    // Populate fields for hasNext() and next()
    pushDirectory( fileInfo );
    advance();
}

void QDirIteratorPrivate::pushDirectory( const QFileInfo &fileInfo )
{
    QString path = fileInfo.filePath();

#ifdef Q_OS_WIN

    if ( fileInfo.isSymLink() )
    {
        path = fileInfo.canonicalFilePath();
    }

#endif

    if ( m_iteratorFlags & QDirIterator::FollowSymlinks )
    {
        m_visitedLinks << fileInfo.canonicalFilePath();
    }

    if ( m_engine )
    {
        m_engine->setFileName( path );
        QAbstractFileEngineIterator *it = m_engine->beginEntryList( m_filters, m_nameFilters );

        if ( it )
        {
            it->setPath( path );
            m_fileEngineIterators << it;
        }
        else
        {
            // No iterator; no entry list.
        }
    }
    else
    {
#ifndef LSCS_NO_FILESYSTEMITERATOR
        QFileSystemIterator *it = new QFileSystemIterator( fileInfo.d_ptr->fileEntry,
            m_filters, m_nameFilters, m_iteratorFlags );
        m_nativeIterators << it;
#endif
    }
}

inline bool QDirIteratorPrivate::entryMatches( const QString &fileName, const QFileInfo &fileInfo )
{
    checkAndPushDirectory( fileInfo );

    if ( matchesFilters( fileName, fileInfo ) )
    {
        m_currentFileInfo = m_nextFileInfo;
        m_nextFileInfo = fileInfo;

        //We found a matching entry.
        return true;
    }

    return false;
}

void QDirIteratorPrivate::advance()
{
    if ( m_engine )
    {

        while ( !m_fileEngineIterators.isEmpty() )
        {
            // Find the next valid iterator that matches the filters.
            QAbstractFileEngineIterator *it;

            while ( it = m_fileEngineIterators.top(), it->hasNext() )
            {
                it->next();

                if ( entryMatches( it->currentFileName(), it->currentFileInfo() ) )
                {
                    return;
                }
            }

            m_fileEngineIterators.pop();
            delete it;
        }

    }
    else
    {
#ifndef LSCS_NO_FILESYSTEMITERATOR
        QFileSystemEntry nextEntry;
        QFileSystemMetaData nextMetaData;

        while ( !m_nativeIterators.isEmpty() )
        {
            // Find the next valid iterator that matches the filters.
            QFileSystemIterator *it;

            while ( it = m_nativeIterators.top(), it->advance( nextEntry, nextMetaData ) )
            {
                QFileInfo info( new QFileInfoPrivate( nextEntry, nextMetaData ) );

                if ( entryMatches( nextEntry.fileName(), info ) )
                {
                    return;
                }
            }

            m_nativeIterators.pop();
            delete it;
        }

#endif
    }

    m_currentFileInfo = m_nextFileInfo;
    m_nextFileInfo = QFileInfo();
}

void QDirIteratorPrivate::checkAndPushDirectory( const QFileInfo &fileInfo )
{
    // If we're doing flat iteration, we're done.
    if ( !( m_iteratorFlags & QDirIterator::Subdirectories ) )
    {
        return;
    }

    // Never follow non-directory entries
    if ( !fileInfo.isDir() )
    {
        return;
    }

    // Follow symlinks only when asked
    if ( !( m_iteratorFlags & QDirIterator::FollowSymlinks ) && fileInfo.isSymLink() )
    {
        return;
    }

    // Never follow . and ..
    QString fileName = fileInfo.fileName(); // getting unprintable control characters

    if ( "." == fileName || ".." == fileName )
    {
        return;
    }

    // No hidden directories unless requested
    if ( ! ( m_filters & QDir::AllDirs ) && ! ( m_filters & QDir::Hidden ) && fileInfo.isHidden() )
    {
        return;
    }

    // Stop link loops
    if ( ! m_visitedLinks.isEmpty() && m_visitedLinks.contains( fileInfo.canonicalFilePath() ) )
    {
        return;
    }

    pushDirectory( fileInfo );
}

bool QDirIteratorPrivate::matchesFilters( const QString &fileName, const QFileInfo &fi ) const
{
    Q_ASSERT( !fileName.isEmpty() );

    // filter . and ..

    QString nameStr = fileName;
    const bool dotDirToSkip = nameStr == CURRENT_DOT_DIR || nameStr == PARENT_DOT_DIR;

    if ( m_filters & QDir::NoDot )
    {
        if ( nameStr == CURRENT_DOT_DIR )
        {
            return false;
        }
    }

    if ( m_filters & QDir::NoDotDot )
    {
        if ( nameStr == PARENT_DOT_DIR )
        {
            return false;
        }
    }

    // name filter
    // Pass all entries through name filters, except dirs if the AllDirs

    if ( ! m_nameFilters.isEmpty() && ! ( ( m_filters & QDir::AllDirs ) && fi.isDir() ) )
    {
        bool matched = false;

        for ( const auto &regExp : m_nameRegExps )
        {
            if ( regExp.match( nameStr ).hasMatch() )
            {
                matched = true;
                break;
            }
        }

        if ( ! matched )
        {
            return false;
        }
    }

    // skip symlinks
    const bool skipSymlinks  = ( m_filters & QDir::NoSymLinks );
    const bool includeSystem = ( m_filters & QDir::System );

    if ( skipSymlinks && fi.isSymLink() )
    {
        // The only reason to save this file is if it is a broken link and we are requesting system files.
        if ( !includeSystem || fi.exists() )
        {
            return false;
        }
    }

    // filter hidden
    const bool includeHidden = ( m_filters & QDir::Hidden );

    if ( (! includeHidden) && (! dotDirToSkip) && (fi.isHidden() ))
    {
        return false;
    }

    // filter system files
    if ( !includeSystem && ( !( fi.isFile() || fi.isDir() || fi.isSymLink() ) || ( !fi.exists() && fi.isSymLink() ) ) )
    {
        return false;
    }

    // skip directories
    const bool skipDirs = !( m_filters & ( QDir::Dirs | QDir::AllDirs ) );

    if ( skipDirs && fi.isDir() )
    {
        return false;
    }

    // skip files
    const bool skipFiles = !( m_filters & QDir::Files );

    if ( skipFiles && fi.isFile() )
    {
        // Basically we need a reason not to exclude this file otherwise we just eliminate it
        return false;
    }

    // filter permissions
    const bool filterPermissions = ( ( m_filters & QDir::PermissionMask )
                                     && ( m_filters & QDir::PermissionMask ) != QDir::PermissionMask );
    const bool doWritable   = !filterPermissions || ( m_filters & QDir::Writable );
    const bool doExecutable = !filterPermissions || ( m_filters & QDir::Executable );
    const bool doReadable   = !filterPermissions || ( m_filters & QDir::Readable );

    if ( filterPermissions && ( ( doReadable && ! fi.isReadable() )
                                || ( doWritable && ! fi.isWritable() ) || ( doExecutable && !fi.isExecutable() ) ) )
    {
        return false;
    }

    return true;
}

QDirIterator::QDirIterator( const QDir &dir, IteratorFlags flags )
{
    const QDirPrivate *other = dir.d_ptr.constData();
    d.reset( new QDirIteratorPrivate( other->dirEntry, other->nameFilters, other->filters, flags, ! other->fileEngine.isNull() ) );
}

QDirIterator::QDirIterator( const QString &path, QDir::Filters filters, IteratorFlags flags )
    : d( new QDirIteratorPrivate( QFileSystemEntry( path ), QStringList(), filters, flags ) )
{
}

QDirIterator::QDirIterator( const QString &path, IteratorFlags flags )
    : d( new QDirIteratorPrivate( QFileSystemEntry( path ), QStringList(), QDir::NoFilter, flags ) )
{
}

QDirIterator::QDirIterator( const QString &path, const QStringList &nameFilters,
                            QDir::Filters filters, IteratorFlags flags )
    : d( new QDirIteratorPrivate( QFileSystemEntry( path ), nameFilters, filters, flags ) )
{
}

QDirIterator::~QDirIterator()
{
}

QString QDirIterator::next()
{
    d->advance();
    return filePath();
}

bool QDirIterator::hasNext() const
{
    if ( d->m_engine )
    {
        return !d->m_fileEngineIterators.isEmpty();

    }
    else
#ifndef LSCS_NO_FILESYSTEMITERATOR
        return !d->m_nativeIterators.isEmpty();

#else
        return false;
#endif
}

QString QDirIterator::fileName() const
{
    return d->m_currentFileInfo.fileName();
}

QString QDirIterator::filePath() const
{
    return d->m_currentFileInfo.filePath();
}

QFileInfo QDirIterator::fileInfo() const
{
    return d->m_currentFileInfo;
}

QString QDirIterator::path() const
{
    return d->m_dirEntry.filePath();
}
