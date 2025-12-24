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

#ifndef QUNIQUEPOINTER_H
#define QUNIQUEPOINTER_H

#include <qglobal.h>

#include <lscs_unique_pointer.h>
#include <lscs_unique_array_pointer.h>

struct QMallocDeleter
{
    void operator()( void *ptr ) const
    {
        if ( ptr != nullptr )
        {
            qFree( ptr );
        }
    }
};

using QScopedPointerPodDeleter [[deprecated( "Use QMallocDeleter instead" )]] = QMallocDeleter;

#if ! defined(LSCS_DOXYPRESS)

template <typename T, typename Deleter = std::default_delete<T>>
class QUniquePointer : public LsCsPointer::LsCsUniquePointer<T, Deleter>
{
public:
    using LsCsPointer::LsCsUniquePointer<T, Deleter>::LsCsUniquePointer;

    QUniquePointer( LsCsPointer::LsCsUniquePointer<T, Deleter> other ) noexcept
        : LsCsPointer::LsCsUniquePointer<T, Deleter>( std::move( other ) )
    {
    }

    bool isNull() const
    {
        return LsCsPointer::LsCsUniquePointer<T, Deleter>::is_null();
    }
};

#endif

#if ! defined(LSCS_DOXYPRESS)

template <typename T, typename Deleter = std::default_delete<LsCsPointer::lscs_add_missing_extent_t<T>>>
class QUniqueArrayPointer : public LsCsPointer::LsCsUniqueArrayPointer<T, Deleter>
{
public:
    using LsCsPointer::LsCsUniqueArrayPointer<T, Deleter>::LsCsUniqueArrayPointer;

    QUniqueArrayPointer( LsCsPointer::LsCsUniqueArrayPointer<T, Deleter> other ) noexcept
        : LsCsPointer::LsCsUniqueArrayPointer<T, Deleter>( std::move( other ) )
    {
    }

    bool isNull() const
    {
        return LsCsPointer::LsCsUniqueArrayPointer<T, Deleter>::is_null();
    }
};

#endif

// free functions

// QScopedPointer
template < typename T, typename... Args, typename = typename std::enable_if_t < ! std::is_array_v<T >>>
QUniquePointer<T> QMakeUnique( Args && ... args )
{
    return LsCsPointer::make_unique<T>( std::forward<Args>( args )... );
}

// QScopedArrayPointer
template <typename T, typename = typename std::enable_if_t<std::is_array_v<T>>>
QUniquePointer<T> QMakeUnique( std::size_t size )
{
    return LsCsPointer::make_unique<T>( size );
}

#endif
