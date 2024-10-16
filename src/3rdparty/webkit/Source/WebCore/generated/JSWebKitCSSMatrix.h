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

#ifndef JSWebKitCSSMatrix_h
#define JSWebKitCSSMatrix_h

#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObjectWithGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore
{

class WebKitCSSMatrix;

class JSWebKitCSSMatrix : public JSDOMWrapper
{
    typedef JSDOMWrapper Base;
public:
    JSWebKitCSSMatrix( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<WebKitCSSMatrix> );
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
    WebKitCSSMatrix *impl() const
    {
        return m_impl.get();
    }

private:
    RefPtr<WebKitCSSMatrix> m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

JSC::JSValue toJS( JSC::ExecState *, JSDOMGlobalObject *, WebKitCSSMatrix * );
WebKitCSSMatrix *toWebKitCSSMatrix( JSC::JSValue );

class JSWebKitCSSMatrixPrototype : public JSC::JSObjectWithGlobalObject
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
    JSWebKitCSSMatrixPrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                                JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

class JSWebKitCSSMatrixConstructor : public DOMConstructorObject
{
public:
    JSWebKitCSSMatrixConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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
    static JSC::EncodedJSValue JSC_HOST_CALL constructJSWebKitCSSMatrix( JSC::ExecState * );
    virtual JSC::ConstructType getConstructData( JSC::ConstructData & );
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsWebKitCSSMatrixPrototypeFunctionSetMatrixValue( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsWebKitCSSMatrixPrototypeFunctionMultiply( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsWebKitCSSMatrixPrototypeFunctionInverse( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsWebKitCSSMatrixPrototypeFunctionTranslate( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsWebKitCSSMatrixPrototypeFunctionScale( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsWebKitCSSMatrixPrototypeFunctionRotate( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsWebKitCSSMatrixPrototypeFunctionRotateAxisAngle( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsWebKitCSSMatrixPrototypeFunctionSkewX( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsWebKitCSSMatrixPrototypeFunctionSkewY( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsWebKitCSSMatrixPrototypeFunctionToString( JSC::ExecState * );
// Attributes

JSC::JSValue jsWebKitCSSMatrixA( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixA( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixB( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixB( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixC( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixC( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixD( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixD( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixE( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixE( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixF( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixF( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM11( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM11( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM12( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM12( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM13( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM13( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM14( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM14( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM21( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM21( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM22( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM22( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM23( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM23( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM24( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM24( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM31( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM31( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM32( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM32( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM33( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM33( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM34( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM34( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM41( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM41( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM42( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM42( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM43( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM43( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixM44( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSWebKitCSSMatrixM44( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsWebKitCSSMatrixConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif
