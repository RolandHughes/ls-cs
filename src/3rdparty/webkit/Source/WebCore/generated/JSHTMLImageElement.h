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

#ifndef JSHTMLImageElement_h
#define JSHTMLImageElement_h

#include "HTMLImageElement.h"
#include "JSHTMLElement.h"
#include <runtime/JSObjectWithGlobalObject.h>

namespace WebCore
{

class HTMLImageElement;

class JSHTMLImageElement : public JSHTMLElement
{
    typedef JSHTMLElement Base;
public:
    JSHTMLImageElement( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<HTMLImageElement> );
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
    HTMLImageElement *impl() const
    {
        return static_cast<HTMLImageElement *>( Base::impl() );
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

HTMLImageElement *toHTMLImageElement( JSC::JSValue );

class JSHTMLImageElementPrototype : public JSC::JSObjectWithGlobalObject
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
    JSHTMLImageElementPrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                                 JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = Base::StructureFlags;
};

// Attributes

JSC::JSValue jsHTMLImageElementName( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLImageElementName( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLImageElementAlign( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLImageElementAlign( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLImageElementAlt( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLImageElementAlt( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLImageElementBorder( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLImageElementBorder( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLImageElementHeight( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLImageElementHeight( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLImageElementHspace( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLImageElementHspace( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLImageElementIsMap( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLImageElementIsMap( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLImageElementLongDesc( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLImageElementLongDesc( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLImageElementSrc( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLImageElementSrc( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLImageElementUseMap( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLImageElementUseMap( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLImageElementVspace( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLImageElementVspace( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLImageElementWidth( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLImageElementWidth( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLImageElementComplete( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsHTMLImageElementLowsrc( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSHTMLImageElementLowsrc( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsHTMLImageElementNaturalHeight( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsHTMLImageElementNaturalWidth( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsHTMLImageElementX( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsHTMLImageElementY( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsHTMLImageElementConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif
