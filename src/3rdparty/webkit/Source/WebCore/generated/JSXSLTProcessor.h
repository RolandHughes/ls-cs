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

#ifndef JSXSLTProcessor_h
#define JSXSLTProcessor_h

#if ENABLE(XSLT)

#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObjectWithGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore
{

class XSLTProcessor;

class JSXSLTProcessor : public JSDOMWrapper
{
    typedef JSDOMWrapper Base;
public:
    JSXSLTProcessor( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<XSLTProcessor> );
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

    // Custom functions
    JSC::JSValue importStylesheet( JSC::ExecState * );
    JSC::JSValue transformToFragment( JSC::ExecState * );
    JSC::JSValue transformToDocument( JSC::ExecState * );
    JSC::JSValue setParameter( JSC::ExecState * );
    JSC::JSValue getParameter( JSC::ExecState * );
    JSC::JSValue removeParameter( JSC::ExecState * );
    XSLTProcessor *impl() const
    {
        return m_impl.get();
    }

private:
    RefPtr<XSLTProcessor> m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

JSC::JSValue toJS( JSC::ExecState *, JSDOMGlobalObject *, XSLTProcessor * );
XSLTProcessor *toXSLTProcessor( JSC::JSValue );

class JSXSLTProcessorPrototype : public JSC::JSObjectWithGlobalObject
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
    JSXSLTProcessorPrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                              JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

class JSXSLTProcessorConstructor : public DOMConstructorObject
{
public:
    JSXSLTProcessorConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

    virtual bool getOwnPropertySlot( JSC::ExecState *, const JSC::Identifier &, JSC::PropertySlot & );
    virtual bool getOwnPropertyDescriptor( JSC::ExecState *, const JSC::Identifier &, JSC::PropertyDescriptor & );
    static const JSC::ClassInfo s_info;
    static JSC::Structure *createStructure( JSC::JSGlobalData &globalData, JSC::JSValue prototype )
    {
        return JSC::Structure::create( globalData, prototype, JSC::TypeInfo( JSC::ObjectType, StructureFlags ), AnonymousSlotCount,
                                       &s_info );
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::ImplementsHasInstance |
                                           DOMConstructorObject::StructureFlags;
    static JSC::EncodedJSValue JSC_HOST_CALL constructJSXSLTProcessor( JSC::ExecState * );
    virtual JSC::ConstructType getConstructData( JSC::ConstructData & );
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionImportStylesheet( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionTransformToFragment( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionTransformToDocument( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionSetParameter( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionGetParameter( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionRemoveParameter( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionClearParameters( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXSLTProcessorPrototypeFunctionReset( JSC::ExecState * );
// Attributes

JSC::JSValue jsXSLTProcessorConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif // ENABLE(XSLT)

#endif
