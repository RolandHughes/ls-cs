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

#ifndef JSDeviceOrientationEvent_h
#define JSDeviceOrientationEvent_h

#if ENABLE(DEVICE_ORIENTATION)

#include "JSEvent.h"
#include <runtime/JSObjectWithGlobalObject.h>

namespace WebCore
{

class DeviceOrientationEvent;

class JSDeviceOrientationEvent : public JSEvent
{
    typedef JSEvent Base;
public:
    JSDeviceOrientationEvent( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<DeviceOrientationEvent> );
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

    // Custom attributes
    JSC::JSValue alpha( JSC::ExecState * ) const;
    JSC::JSValue beta( JSC::ExecState * ) const;
    JSC::JSValue gamma( JSC::ExecState * ) const;

    // Custom functions
    JSC::JSValue initDeviceOrientationEvent( JSC::ExecState * );
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};


class JSDeviceOrientationEventPrototype : public JSC::JSObjectWithGlobalObject
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
    JSDeviceOrientationEventPrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                                       JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsDeviceOrientationEventPrototypeFunctionInitDeviceOrientationEvent( JSC::ExecState * );
// Attributes

JSC::JSValue jsDeviceOrientationEventAlpha( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsDeviceOrientationEventBeta( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsDeviceOrientationEventGamma( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsDeviceOrientationEventConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif // ENABLE(DEVICE_ORIENTATION)

#endif
