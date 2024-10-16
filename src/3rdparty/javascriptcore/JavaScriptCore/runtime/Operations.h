/*
 *  Copyright (C) 1999-2000 Harri Porten (porten@kde.org)
 *  Copyright (C) 2002, 2005, 2006, 2007, 2008, 2009 Apple Inc. All rights reserved.
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

#ifndef Operations_h
#define Operations_h

#include "Interpreter.h"
#include "JSImmediate.h"
#include "JSNumberCell.h"
#include "JSString.h"

namespace JSC
{

NEVER_INLINE JSValue throwOutOfMemoryError( ExecState * );
NEVER_INLINE JSValue jsAddSlowCase( CallFrame *, JSValue, JSValue );
JSValue jsTypeStringForValue( CallFrame *, JSValue );
bool jsIsObjectType( JSValue );
bool jsIsFunctionType( JSValue );

ALWAYS_INLINE JSValue jsString( ExecState *exec, JSString *s1, JSString *s2 )
{
    if ( !s1->length() )
    {
        return s2;
    }

    if ( !s2->length() )
    {
        return s1;
    }

    unsigned ropeLength = s1->ropeLength() + s2->ropeLength();
    JSGlobalData *globalData = &exec->globalData();

    if ( ropeLength <= JSString::s_maxInternalRopeLength )
    {
        return new ( globalData ) JSString( globalData, ropeLength, s1, s2 );
    }

    unsigned index = 0;
    RefPtr<JSString::Rope> rope = JSString::Rope::createOrNull( ropeLength );

    if ( UNLIKELY( !rope ) )
    {
        return throwOutOfMemoryError( exec );
    }

    rope->append( index, s1 );
    rope->append( index, s2 );
    ASSERT( index == ropeLength );
    return new ( globalData ) JSString( globalData, rope.release() );
}

ALWAYS_INLINE JSValue jsString( ExecState *exec, const UString &u1, JSString *s2 )
{
    unsigned ropeLength = 1 + s2->ropeLength();
    JSGlobalData *globalData = &exec->globalData();

    if ( ropeLength <= JSString::s_maxInternalRopeLength )
    {
        return new ( globalData ) JSString( globalData, ropeLength, u1, s2 );
    }

    unsigned index = 0;
    RefPtr<JSString::Rope> rope = JSString::Rope::createOrNull( ropeLength );

    if ( UNLIKELY( !rope ) )
    {
        return throwOutOfMemoryError( exec );
    }

    rope->append( index, u1 );
    rope->append( index, s2 );
    ASSERT( index == ropeLength );
    return new ( globalData ) JSString( globalData, rope.release() );
}

ALWAYS_INLINE JSValue jsString( ExecState *exec, JSString *s1, const UString &u2 )
{
    unsigned ropeLength = s1->ropeLength() + 1;
    JSGlobalData *globalData = &exec->globalData();

    if ( ropeLength <= JSString::s_maxInternalRopeLength )
    {
        return new ( globalData ) JSString( globalData, ropeLength, s1, u2 );
    }

    unsigned index = 0;
    RefPtr<JSString::Rope> rope = JSString::Rope::createOrNull( ropeLength );

    if ( UNLIKELY( !rope ) )
    {
        return throwOutOfMemoryError( exec );
    }

    rope->append( index, s1 );
    rope->append( index, u2 );
    ASSERT( index == ropeLength );
    return new ( globalData ) JSString( globalData, rope.release() );
}

ALWAYS_INLINE JSValue jsString( ExecState *exec, Register *strings, unsigned count )
{
    ASSERT( count >= 3 );

    unsigned ropeLength = 0;

    for ( unsigned i = 0; i < count; ++i )
    {
        JSValue v = strings[i].jsValue();

        if ( LIKELY( v.isString() ) )
        {
            ropeLength += asString( v )->ropeLength();
        }
        else
        {
            ++ropeLength;
        }
    }

    JSGlobalData *globalData = &exec->globalData();

    if ( ropeLength == 3 )
    {
        return new ( globalData ) JSString( exec, strings[0].jsValue(), strings[1].jsValue(), strings[2].jsValue() );
    }

    RefPtr<JSString::Rope> rope = JSString::Rope::createOrNull( ropeLength );

    if ( UNLIKELY( !rope ) )
    {
        return throwOutOfMemoryError( exec );
    }

    unsigned index = 0;

    for ( unsigned i = 0; i < count; ++i )
    {
        JSValue v = strings[i].jsValue();

        if ( LIKELY( v.isString() ) )
        {
            rope->append( index, asString( v ) );
        }
        else
        {
            rope->append( index, v.toString( exec ) );
        }
    }

    ASSERT( index == ropeLength );
    return new ( globalData ) JSString( globalData, rope.release() );
}

ALWAYS_INLINE JSValue jsString( ExecState *exec, JSValue thisValue, const ArgList &args )
{
    unsigned ropeLength = 0;

    if ( LIKELY( thisValue.isString() ) )
    {
        ropeLength += asString( thisValue )->ropeLength();
    }
    else
    {
        ++ropeLength;
    }

    for ( unsigned i = 0; i < args.size(); ++i )
    {
        JSValue v = args.at( i );

        if ( LIKELY( v.isString() ) )
        {
            ropeLength += asString( v )->ropeLength();
        }
        else
        {
            ++ropeLength;
        }
    }

    RefPtr<JSString::Rope> rope = JSString::Rope::createOrNull( ropeLength );

    if ( UNLIKELY( !rope ) )
    {
        return throwOutOfMemoryError( exec );
    }

    unsigned index = 0;

    if ( LIKELY( thisValue.isString() ) )
    {
        rope->append( index, asString( thisValue ) );
    }
    else
    {
        rope->append( index, thisValue.toString( exec ) );
    }

    for ( unsigned i = 0; i < args.size(); ++i )
    {
        JSValue v = args.at( i );

        if ( LIKELY( v.isString() ) )
        {
            rope->append( index, asString( v ) );
        }
        else
        {
            rope->append( index, v.toString( exec ) );
        }
    }

    ASSERT( index == ropeLength );

    JSGlobalData *globalData = &exec->globalData();
    return new ( globalData ) JSString( globalData, rope.release() );
}

// ECMA 11.9.3
inline bool JSValue::equal( ExecState *exec, JSValue v1, JSValue v2 )
{
    if ( v1.isInt32() && v2.isInt32() )
    {
        return v1 == v2;
    }

    return equalSlowCase( exec, v1, v2 );
}

ALWAYS_INLINE bool JSValue::equalSlowCaseInline( ExecState *exec, JSValue v1, JSValue v2 )
{
    do
    {
        if ( v1.isNumber() && v2.isNumber() )
        {
            return v1.uncheckedGetNumber() == v2.uncheckedGetNumber();
        }

        bool s1 = v1.isString();
        bool s2 = v2.isString();

        if ( s1 && s2 )
        {
            return asString( v1 )->value( exec ) == asString( v2 )->value( exec );
        }

        if ( v1.isUndefinedOrNull() )
        {
            if ( v2.isUndefinedOrNull() )
            {
                return true;
            }

            if ( !v2.isCell() )
            {
                return false;
            }

            return v2.asCell()->structure()->typeInfo().masqueradesAsUndefined();
        }

        if ( v2.isUndefinedOrNull() )
        {
            if ( !v1.isCell() )
            {
                return false;
            }

            return v1.asCell()->structure()->typeInfo().masqueradesAsUndefined();
        }

        if ( v1.isObject() )
        {
            if ( v2.isObject() )
                return v1 == v2
#ifdef QT_BUILD_SCRIPT_LIB
                       || asObject( v1 )->compareToObject( exec, asObject( v2 ) )
#endif
                       ;

            JSValue p1 = v1.toPrimitive( exec );

            if ( exec->hadException() )
            {
                return false;
            }

            v1 = p1;

            if ( v1.isInt32() && v2.isInt32() )
            {
                return v1 == v2;
            }

            continue;
        }

        if ( v2.isObject() )
        {
            JSValue p2 = v2.toPrimitive( exec );

            if ( exec->hadException() )
            {
                return false;
            }

            v2 = p2;

            if ( v1.isInt32() && v2.isInt32() )
            {
                return v1 == v2;
            }

            continue;
        }

        if ( s1 || s2 )
        {
            double d1 = v1.toNumber( exec );
            double d2 = v2.toNumber( exec );
            return d1 == d2;
        }

        if ( v1.isBoolean() )
        {
            if ( v2.isNumber() )
            {
                return static_cast<double>( v1.getBoolean() ) == v2.uncheckedGetNumber();
            }
        }
        else if ( v2.isBoolean() )
        {
            if ( v1.isNumber() )
            {
                return v1.uncheckedGetNumber() == static_cast<double>( v2.getBoolean() );
            }
        }

        return v1 == v2;
    }
    while ( true );
}

// ECMA 11.9.3
ALWAYS_INLINE bool JSValue::strictEqualSlowCaseInline( ExecState *exec, JSValue v1, JSValue v2 )
{
    ASSERT( v1.isCell() && v2.isCell() );

    if ( v1.asCell()->isString() && v2.asCell()->isString() )
    {
        return asString( v1 )->value( exec ) == asString( v2 )->value( exec );
    }

    return v1 == v2;
}

inline bool JSValue::strictEqual( ExecState *exec, JSValue v1, JSValue v2 )
{
    if ( v1.isInt32() && v2.isInt32() )
    {
        return v1 == v2;
    }

    if ( v1.isNumber() && v2.isNumber() )
    {
        return v1.uncheckedGetNumber() == v2.uncheckedGetNumber();
    }

    if ( !v1.isCell() || !v2.isCell() )
    {
        return v1 == v2;
    }

    return strictEqualSlowCaseInline( exec, v1, v2 );
}

ALWAYS_INLINE bool jsLess( CallFrame *callFrame, JSValue v1, JSValue v2 )
{
    if ( v1.isInt32() && v2.isInt32() )
    {
        return v1.asInt32() < v2.asInt32();
    }

    double n1;
    double n2;

    if ( v1.getNumber( n1 ) && v2.getNumber( n2 ) )
    {
        return n1 < n2;
    }

    JSGlobalData *globalData = &callFrame->globalData();

    if ( isJSString( globalData, v1 ) && isJSString( globalData, v2 ) )
    {
        return asString( v1 )->value( callFrame ) < asString( v2 )->value( callFrame );
    }

    JSValue p1;
    JSValue p2;
    bool wasNotString1 = v1.getPrimitiveNumber( callFrame, n1, p1 );
    bool wasNotString2 = v2.getPrimitiveNumber( callFrame, n2, p2 );

    if ( wasNotString1 | wasNotString2 )
    {
        return n1 < n2;
    }

    return asString( p1 )->value( callFrame ) < asString( p2 )->value( callFrame );
}

inline bool jsLessEq( CallFrame *callFrame, JSValue v1, JSValue v2 )
{
    if ( v1.isInt32() && v2.isInt32() )
    {
        return v1.asInt32() <= v2.asInt32();
    }

    double n1;
    double n2;

    if ( v1.getNumber( n1 ) && v2.getNumber( n2 ) )
    {
        return n1 <= n2;
    }

    JSGlobalData *globalData = &callFrame->globalData();

    if ( isJSString( globalData, v1 ) && isJSString( globalData, v2 ) )
    {
        return !( asString( v2 )->value( callFrame ) < asString( v1 )->value( callFrame ) );
    }

    JSValue p1;
    JSValue p2;
    bool wasNotString1 = v1.getPrimitiveNumber( callFrame, n1, p1 );
    bool wasNotString2 = v2.getPrimitiveNumber( callFrame, n2, p2 );

    if ( wasNotString1 | wasNotString2 )
    {
        return n1 <= n2;
    }

    return !( asString( p2 )->value( callFrame ) < asString( p1 )->value( callFrame ) );
}

// Fast-path choices here are based on frequency data from SunSpider:
//    <times> Add case: <t1> <t2>
//    ---------------------------
//    5626160 Add case: 3 3 (of these, 3637690 are for immediate values)
//    247412  Add case: 5 5
//    20900   Add case: 5 6
//    13962   Add case: 5 3
//    4000    Add case: 3 5

ALWAYS_INLINE JSValue jsAdd( CallFrame *callFrame, JSValue v1, JSValue v2 )
{
    double left = 0.0, right;

    if ( v1.getNumber( left ) && v2.getNumber( right ) )
    {
        return jsNumber( callFrame, left + right );
    }

    if ( v1.isString() )
    {
        return v2.isString()
               ? jsString( callFrame, asString( v1 ), asString( v2 ) )
               : jsString( callFrame, asString( v1 ), v2.toPrimitiveString( callFrame ) );
    }

    // All other cases are pretty uncommon
    return jsAddSlowCase( callFrame, v1, v2 );
}

inline size_t normalizePrototypeChain( CallFrame *callFrame, JSValue base, JSValue slotBase, const Identifier &propertyName,
                                       size_t &slotOffset )
{
    JSCell *cell = asCell( base );
    size_t count = 0;

    while ( slotBase != cell )
    {
        JSValue v = cell->structure()->prototypeForLookup( callFrame );

        // If we didn't find slotBase in base's prototype chain, then base
        // must be a proxy for another object.

        if ( v.isNull() )
        {
            return 0;
        }

        cell = asCell( v );

        // Since we're accessing a prototype in a loop, it's a good bet that it
        // should not be treated as a dictionary.
        if ( cell->structure()->isDictionary() )
        {
            asObject( cell )->flattenDictionaryObject();

            if ( slotBase == cell )
            {
                slotOffset = cell->structure()->get( propertyName );
            }
        }

        ++count;
    }

    ASSERT( count );
    return count;
}

inline size_t normalizePrototypeChain( CallFrame *callFrame, JSCell *base )
{
    size_t count = 0;

    while ( 1 )
    {
        JSValue v = base->structure()->prototypeForLookup( callFrame );

        if ( v.isNull() )
        {
            return count;
        }

        base = asCell( v );

        // Since we're accessing a prototype in a loop, it's a good bet that it
        // should not be treated as a dictionary.
        if ( base->structure()->isDictionary() )
        {
            asObject( base )->flattenDictionaryObject();
        }

        ++count;
    }
}

ALWAYS_INLINE JSValue resolveBase( CallFrame *callFrame, Identifier &property, ScopeChainNode *scopeChain )
{
    ScopeChainIterator iter = scopeChain->begin();
    ScopeChainIterator next = iter;
    ++next;
    ScopeChainIterator end = scopeChain->end();
    ASSERT( iter != end );

    PropertySlot slot;
    JSObject *base;

    while ( true )
    {
        base = *iter;

        if ( next == end || base->getPropertySlot( callFrame, property, slot ) )
        {
            return base;
        }

        iter = next;
        ++next;
    }

    ASSERT_NOT_REACHED();
    return JSValue();
}
} // namespace JSC

#endif // Operations_h
