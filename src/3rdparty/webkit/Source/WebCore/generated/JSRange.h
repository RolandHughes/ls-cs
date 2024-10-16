/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef JSRange_h
#define JSRange_h

#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObjectWithGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore
{

class Range;

class JSRange : public JSDOMWrapper
{
    typedef JSDOMWrapper Base;
public:
    JSRange( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<Range> );
    static JSC::JSObject *createPrototype( JSC::ExecState *, JSC::JSGlobalObject * );
    virtual bool getOwnPropertySlot( JSC::ExecState *, const JSC::Identifier &propertyName, JSC::PropertySlot & );
    virtual bool getOwnPropertyDescriptor( JSC::ExecState *, const JSC::Identifier &propertyName, JSC::PropertyDescriptor & );
    static const JSC::ClassInfo s_info;

    static JSC::Structure *createStructure( JSC::JSGlobalData &globalData, JSC::JSValue prototype )
    {
        return JSC::Structure::create( globalData, prototype, JSC::TypeInfo( JSC::ObjectType, StructureFlags ), AnonymousSlotCount,
                                       &s_info );
    }

    static JSC::JSValue getConstructor( JSC::ExecState *, JSC::JSGlobalObject * );
    Range *impl() const
    {
        return m_impl.get();
    }

private:
    RefPtr<Range> m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

JSC::JSValue toJS( JSC::ExecState *, JSDOMGlobalObject *, Range * );
Range *toRange( JSC::JSValue );

class JSRangePrototype : public JSC::JSObjectWithGlobalObject
{
    typedef JSC::JSObjectWithGlobalObject Base;
public:
    static JSC::JSObject *self( JSC::ExecState *, JSC::JSGlobalObject * );
    static const JSC::ClassInfo s_info;
    virtual bool getOwnPropertySlot( JSC::ExecState *, const JSC::Identifier &, JSC::PropertySlot & );
    virtual bool getOwnPropertyDescriptor( JSC::ExecState *, const JSC::Identifier &, JSC::PropertyDescriptor & );
    static JSC::Structure *createStructure( JSC::JSGlobalData &globalData, JSC::JSValue prototype )
    {
        return JSC::Structure::create( globalData, prototype, JSC::TypeInfo( JSC::ObjectType, StructureFlags ), AnonymousSlotCount,
                                       &s_info );
    }
    JSRangePrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                      JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionSetStart( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionSetEnd( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionSetStartBefore( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionSetStartAfter( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionSetEndBefore( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionSetEndAfter( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionCollapse( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionSelectNode( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionSelectNodeContents( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionCompareBoundaryPoints( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionDeleteContents( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionExtractContents( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionCloneContents( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionInsertNode( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionSurroundContents( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionCloneRange( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionToString( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionDetach( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionGetClientRects( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionGetBoundingClientRect( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionCreateContextualFragment( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionIntersectsNode( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionCompareNode( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionComparePoint( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionIsPointInRange( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsRangePrototypeFunctionExpand( JSC::ExecState * );
// Attributes

JSC::JSValue jsRangeStartContainer( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsRangeStartOffset( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsRangeEndContainer( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsRangeEndOffset( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsRangeCollapsed( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsRangeCommonAncestorContainer( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsRangeConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
// Constants

JSC::JSValue jsRangeSTART_TO_START( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsRangeSTART_TO_END( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsRangeEND_TO_END( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsRangeEND_TO_START( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsRangeNODE_BEFORE( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsRangeNODE_AFTER( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsRangeNODE_BEFORE_AND_AFTER( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsRangeNODE_INSIDE( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif
