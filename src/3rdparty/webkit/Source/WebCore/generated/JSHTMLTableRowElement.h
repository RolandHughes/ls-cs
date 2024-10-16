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

#ifndef JSHTMLTableRowElement_h
#define JSHTMLTableRowElement_h

#include "JSHTMLElement.h"
#include <runtime/JSObjectWithGlobalObject.h>

namespace WebCore
{

class HTMLTableRowElement;

class JSHTMLTableRowElement : public JSHTMLElement
{
    typedef JSHTMLElement Base;
public:
    JSHTMLTableRowElement( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<HTMLTableRowElement> );
    static JSC::JSObject *createPrototype( JSC::ExecState *, JSC::JSGlobalObject * );
    virtual bool getOwnPropertySlot( JSC::ExecState *, const JSC::Identifier &propertyName, JSC::PropertySlot & );
    virtual bool getOwnPropertyDescriptor( JSC::ExecState *, const JSC::Identifier &propertyName, JSC::PropertyDescriptor & );
    virtual void put( JSC::ExecState *, const JSC::Identifier &propertyName, JSC::JSValue, JSC::PutPropertySlot & );
    static const JSC::ClassInfo s_info;

    static JSC::Structure *createStructure( JSC::JSGlobalData &globalData, JSC::JSValue prototype )
    {
        return JSC::Structure::create( globalData, prototype, JSC::TypeInfo( JSC::ObjectType, StructureFlags ), AnonymousSlotCount,
                                       &s_info );
    }

    static JSC::JSValue getConstructor( JSC::ExecState *, JSC::JSGlobalObject * );
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};


class JSHTMLTableRowElementPrototype : public JSC::JSObjectWithGlobalObject
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
    JSHTMLTableRowElementPrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                                    JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsHTMLTableRowElementPrototypeFunctionInsertCell( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsHTMLTableRowElementPrototypeFunctionDeleteCell( JSC::ExecState * );
// Attributes

JSC::JSValue jsHTMLTableRowElementRowIndex( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsHTMLTableRowElementSectionRowIndex( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsHTMLTableRowElementCells( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsHTMLTableRowElementAlign( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLTableRowElementAlign( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLTableRowElementBgColor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLTableRowElementBgColor( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLTableRowElementCh( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLTableRowElementCh( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLTableRowElementChOff( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLTableRowElementChOff( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLTableRowElementVAlign( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLTableRowElementVAlign( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLTableRowElementConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif
