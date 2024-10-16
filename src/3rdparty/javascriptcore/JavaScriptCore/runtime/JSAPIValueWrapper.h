/*
 *  Copyright (C) 1999-2001 Harri Porten (porten@kde.org)
 *  Copyright (C) 2001 Peter Kelly (pmk@post.com)
 *  Copyright (C) 2003, 2004, 2005, 2007, 2008 Apple Inc. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 *
 */

#ifndef JSAPIValueWrapper_h
#define JSAPIValueWrapper_h

#include <wtf/Platform.h>

#include "JSCell.h"
#include "CallFrame.h"

namespace JSC
{

class JSAPIValueWrapper : public JSCell
{
    friend JSValue jsAPIValueWrapper( ExecState *, JSValue );
public:
    JSValue value() const
    {
        return m_value;
    }

    virtual bool isAPIValueWrapper() const
    {
        return true;
    }

    static PassRefPtr<Structure> createStructure( JSValue prototype )
    {
        return Structure::create( prototype, TypeInfo( CompoundType, OverridesMarkChildren | OverridesGetPropertyNames ) );
    }


private:
    JSAPIValueWrapper( ExecState *exec, JSValue value )
        : JSCell( exec->globalData().apiWrapperStructure.get() )
        , m_value( value )
    {
        ASSERT( !value.isCell() );
    }

    JSValue m_value;
};

inline JSValue jsAPIValueWrapper( ExecState *exec, JSValue value )
{
    return new ( exec ) JSAPIValueWrapper( exec, value );
}

} // namespace JSC

#endif // JSAPIValueWrapper_h
