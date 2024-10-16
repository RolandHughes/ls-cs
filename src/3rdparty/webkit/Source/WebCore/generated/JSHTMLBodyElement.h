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

#ifndef JSHTMLBodyElement_h
#define JSHTMLBodyElement_h

#include "JSHTMLElement.h"
#include <runtime/JSObjectWithGlobalObject.h>

namespace WebCore
{

class HTMLBodyElement;

class JSHTMLBodyElement : public JSHTMLElement
{
    typedef JSHTMLElement Base;
public:
    JSHTMLBodyElement( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<HTMLBodyElement> );
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


class JSHTMLBodyElementPrototype : public JSC::JSObjectWithGlobalObject
{
    typedef JSC::JSObjectWithGlobalObject Base;
public:
    static JSC::JSObject *self( JSC::ExecState *, JSC::JSGlobalObject * );
    static const JSC::ClassInfo s_info;
    static JSC::Structure *createStructure( JSC::JSGlobalData &globalData, JSC::JSValue prototype )
    {
        return JSC::Structure::create( globalData, prototype, JSC::TypeInfo( JSC::ObjectType, StructureFlags ), AnonymousSlotCount,
                                       &s_info );
    }
    JSHTMLBodyElementPrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                                JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = Base::StructureFlags;
};

// Attributes

JSC::JSValue jsHTMLBodyElementALink( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementALink( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementBackground( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementBackground( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementBgColor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementBgColor( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementLink( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementLink( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementText( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementText( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementVLink( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementVLink( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementOnbeforeunload( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementOnbeforeunload( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementOnhashchange( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementOnhashchange( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementOnmessage( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementOnmessage( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementOnoffline( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementOnoffline( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementOnonline( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementOnonline( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementOnpopstate( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementOnpopstate( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementOnresize( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementOnresize( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementOnstorage( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementOnstorage( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementOnunload( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementOnunload( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementOnblur( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementOnblur( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementOnerror( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementOnerror( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementOnfocus( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementOnfocus( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementOnload( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLBodyElementOnload( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLBodyElementConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif
