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

#ifndef JSEvent_h
#define JSEvent_h

#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObjectWithGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore
{

class Event;

class JSEvent : public JSDOMWrapper
{
    typedef JSDOMWrapper Base;
public:
    JSEvent( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<Event> );
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

    // Custom attributes
    JSC::JSValue clipboardData( JSC::ExecState * ) const;
    Event *impl() const
    {
        return m_impl.get();
    }

private:
    RefPtr<Event> m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

JSC::JSValue toJS( JSC::ExecState *, JSDOMGlobalObject *, Event * );
Event *toEvent( JSC::JSValue );

class JSEventPrototype : public JSC::JSObjectWithGlobalObject
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
    JSEventPrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                      JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsEventPrototypeFunctionStopPropagation( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsEventPrototypeFunctionPreventDefault( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsEventPrototypeFunctionInitEvent( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsEventPrototypeFunctionStopImmediatePropagation( JSC::ExecState * );
// Attributes

JSC::JSValue jsEventType( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventTarget( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventCurrentTarget( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventEventPhase( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventBubbles( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventCancelable( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventTimeStamp( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventDefaultPrevented( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventSrcElement( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventReturnValue( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSEventReturnValue( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsEventCancelBubble( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSEventCancelBubble( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsEventClipboardData( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
// Constants

JSC::JSValue jsEventCAPTURING_PHASE( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventAT_TARGET( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventBUBBLING_PHASE( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventMOUSEDOWN( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventMOUSEUP( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventMOUSEOVER( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventMOUSEOUT( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventMOUSEMOVE( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventMOUSEDRAG( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventCLICK( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventDBLCLICK( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventKEYDOWN( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventKEYUP( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventKEYPRESS( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventDRAGDROP( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventFOCUS( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventBLUR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventSELECT( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsEventCHANGE( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif
