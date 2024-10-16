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

#ifndef JSXMLHttpRequest_h
#define JSXMLHttpRequest_h

#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObjectWithGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore
{

class XMLHttpRequest;

class JSXMLHttpRequest : public JSDOMWrapper
{
    typedef JSDOMWrapper Base;
public:
    JSXMLHttpRequest( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<XMLHttpRequest> );
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

    virtual void visitChildren( JSC::SlotVisitor & );

    static JSC::JSValue getConstructor( JSC::ExecState *, JSC::JSGlobalObject * );

    // Custom attributes
    JSC::JSValue responseText( JSC::ExecState * ) const;
    JSC::JSValue response( JSC::ExecState * ) const;

    // Custom functions
    JSC::JSValue open( JSC::ExecState * );
    JSC::JSValue send( JSC::ExecState * );
    XMLHttpRequest *impl() const
    {
        return m_impl.get();
    }

private:
    RefPtr<XMLHttpRequest> m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::OverridesVisitChildren | Base::StructureFlags;
};

class JSXMLHttpRequestOwner : public JSC::WeakHandleOwner
{
    virtual bool isReachableFromOpaqueRoots( JSC::Handle<JSC::Unknown>, void *context, JSC::SlotVisitor & );
    virtual void finalize( JSC::Handle<JSC::Unknown>, void *context );
};

inline JSC::WeakHandleOwner *wrapperOwner( DOMWrapperWorld *, XMLHttpRequest * )
{
    DEFINE_STATIC_LOCAL( JSXMLHttpRequestOwner, jsXMLHttpRequestOwner, () );
    return &jsXMLHttpRequestOwner;
}

inline void *wrapperContext( DOMWrapperWorld *world, XMLHttpRequest * )
{
    return world;
}

JSC::JSValue toJS( JSC::ExecState *, JSDOMGlobalObject *, XMLHttpRequest * );
XMLHttpRequest *toXMLHttpRequest( JSC::JSValue );

class JSXMLHttpRequestPrototype : public JSC::JSObjectWithGlobalObject
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
    JSXMLHttpRequestPrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                               JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::OverridesVisitChildren | Base::StructureFlags;
};

class JSXMLHttpRequestConstructor : public DOMConstructorObject
{
public:
    JSXMLHttpRequestConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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
    static JSC::EncodedJSValue JSC_HOST_CALL constructJSXMLHttpRequest( JSC::ExecState * );
    virtual JSC::ConstructType getConstructData( JSC::ConstructData & );
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsXMLHttpRequestPrototypeFunctionOpen( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXMLHttpRequestPrototypeFunctionSetRequestHeader( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXMLHttpRequestPrototypeFunctionSend( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXMLHttpRequestPrototypeFunctionAbort( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXMLHttpRequestPrototypeFunctionGetAllResponseHeaders( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXMLHttpRequestPrototypeFunctionGetResponseHeader( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXMLHttpRequestPrototypeFunctionOverrideMimeType( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXMLHttpRequestPrototypeFunctionAddEventListener( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXMLHttpRequestPrototypeFunctionRemoveEventListener( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsXMLHttpRequestPrototypeFunctionDispatchEvent( JSC::ExecState * );
// Attributes

JSC::JSValue jsXMLHttpRequestOnabort( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSXMLHttpRequestOnabort( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsXMLHttpRequestOnerror( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSXMLHttpRequestOnerror( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsXMLHttpRequestOnload( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSXMLHttpRequestOnload( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsXMLHttpRequestOnloadstart( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSXMLHttpRequestOnloadstart( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsXMLHttpRequestOnprogress( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSXMLHttpRequestOnprogress( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsXMLHttpRequestOnreadystatechange( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSXMLHttpRequestOnreadystatechange( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsXMLHttpRequestReadyState( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsXMLHttpRequestWithCredentials( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSXMLHttpRequestWithCredentials( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsXMLHttpRequestUpload( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsXMLHttpRequestResponseText( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsXMLHttpRequestResponseXML( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsXMLHttpRequestResponseType( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSXMLHttpRequestResponseType( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsXMLHttpRequestResponse( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsXMLHttpRequestStatus( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsXMLHttpRequestStatusText( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsXMLHttpRequestConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
// Constants

JSC::JSValue jsXMLHttpRequestUNSENT( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsXMLHttpRequestOPENED( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsXMLHttpRequestHEADERS_RECEIVED( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsXMLHttpRequestLOADING( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsXMLHttpRequestDONE( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif
