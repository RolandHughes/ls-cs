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

#ifndef JSHTMLFrameSetElement_h
#define JSHTMLFrameSetElement_h

#include "JSHTMLElement.h"
#include <runtime/JSObjectWithGlobalObject.h>

namespace WebCore
{

class HTMLFrameSetElement;

class JSHTMLFrameSetElement : public JSHTMLElement
{
    typedef JSHTMLElement Base;
public:
    JSHTMLFrameSetElement( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<HTMLFrameSetElement> );
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
private:
    static bool canGetItemsForName( JSC::ExecState *, HTMLFrameSetElement *, const JSC::Identifier & );
    static JSC::JSValue nameGetter( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
};


class JSHTMLFrameSetElementPrototype : public JSC::JSObjectWithGlobalObject
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
    JSHTMLFrameSetElementPrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                                    JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = Base::StructureFlags;
};

// Attributes

JSC::JSValue jsHTMLFrameSetElementCols( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementCols( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementRows( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementRows( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementOnbeforeunload( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementOnbeforeunload( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementOnhashchange( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementOnhashchange( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementOnmessage( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementOnmessage( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementOnoffline( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementOnoffline( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementOnonline( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementOnonline( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementOnpopstate( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementOnpopstate( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementOnresize( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementOnresize( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementOnstorage( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementOnstorage( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementOnunload( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementOnunload( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementOnblur( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementOnblur( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementOnerror( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementOnerror( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementOnfocus( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementOnfocus( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementOnload( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLFrameSetElementOnload( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLFrameSetElementConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif
