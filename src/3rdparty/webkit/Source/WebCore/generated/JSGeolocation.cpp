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

#include "config.h"

#if ENABLE(GEOLOCATION)

#include "JSGeolocation.h"

#include "ExceptionCode.h"
#include "Geolocation.h"
#include "JSDOMBinding.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSGeolocation );

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSGeolocationPrototypeTableValues[4] =
{
    { "getCurrentPosition", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsGeolocationPrototypeFunctionGetCurrentPosition ), ( intptr_t )3 THUNK_GENERATOR( 0 ) },
    { "watchPosition", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsGeolocationPrototypeFunctionWatchPosition ), ( intptr_t )3 THUNK_GENERATOR( 0 ) },
    { "clearWatch", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsGeolocationPrototypeFunctionClearWatch ), ( intptr_t )1 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSGeolocationPrototypeTable = { 9, 7, JSGeolocationPrototypeTableValues, 0 };
const ClassInfo JSGeolocationPrototype::s_info = { "GeolocationPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSGeolocationPrototypeTable, 0 };

JSObject *JSGeolocationPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSGeolocation>( exec, globalObject );
}

bool JSGeolocationPrototype::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticFunctionSlot<JSObject>( exec, &JSGeolocationPrototypeTable, this, propertyName, slot );
}

bool JSGeolocationPrototype::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticFunctionDescriptor<JSObject>( exec, &JSGeolocationPrototypeTable, this, propertyName, descriptor );
}

const ClassInfo JSGeolocation::s_info = { "Geolocation", &JSDOMWrapper::s_info, 0, 0 };

JSGeolocation::JSGeolocation( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<Geolocation> impl )
    : JSDOMWrapper( structure, globalObject )
    , m_impl( impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSGeolocation::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSGeolocationPrototype( exec->globalData(), globalObject,
            JSGeolocationPrototype::createStructure( globalObject->globalData(), globalObject->objectPrototype() ) );
}

EncodedJSValue JSC_HOST_CALL jsGeolocationPrototypeFunctionGetCurrentPosition( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSGeolocation::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSGeolocation *castedThis = static_cast<JSGeolocation *>( asObject( thisValue ) );
    return JSValue::encode( castedThis->getCurrentPosition( exec ) );
}

EncodedJSValue JSC_HOST_CALL jsGeolocationPrototypeFunctionWatchPosition( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSGeolocation::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSGeolocation *castedThis = static_cast<JSGeolocation *>( asObject( thisValue ) );
    return JSValue::encode( castedThis->watchPosition( exec ) );
}

EncodedJSValue JSC_HOST_CALL jsGeolocationPrototypeFunctionClearWatch( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSGeolocation::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSGeolocation *castedThis = static_cast<JSGeolocation *>( asObject( thisValue ) );
    Geolocation *imp = static_cast<Geolocation *>( castedThis->impl() );
    int watchId( exec->argument( 0 ).toInt32( exec ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }

    imp->clearWatch( watchId );
    return JSValue::encode( jsUndefined() );
}

static inline bool isObservable( JSGeolocation *jsGeolocation )
{
    if ( jsGeolocation->hasCustomProperties() )
    {
        return true;
    }

    return false;
}

bool JSGeolocationOwner::isReachableFromOpaqueRoots( JSC::Handle<JSC::Unknown> handle, void *, SlotVisitor &visitor )
{
    JSGeolocation *jsGeolocation = static_cast<JSGeolocation *>( handle.get().asCell() );

    if ( !isObservable( jsGeolocation ) )
    {
        return false;
    }

    Frame *root = jsGeolocation->impl()->frame();

    if ( !root )
    {
        return false;
    }

    return visitor.containsOpaqueRoot( root );
}

void JSGeolocationOwner::finalize( JSC::Handle<JSC::Unknown> handle, void *context )
{
    JSGeolocation *jsGeolocation = static_cast<JSGeolocation *>( handle.get().asCell() );
    DOMWrapperWorld *world = static_cast<DOMWrapperWorld *>( context );
    uncacheWrapper( world, jsGeolocation->impl(), jsGeolocation );
}

JSC::JSValue toJS( JSC::ExecState *exec, JSDOMGlobalObject *globalObject, Geolocation *impl )
{
    return wrap<JSGeolocation>( exec, globalObject, impl );
}

Geolocation *toGeolocation( JSC::JSValue value )
{
    return value.inherits( &JSGeolocation::s_info ) ? static_cast<JSGeolocation *>( asObject( value ) )->impl() : 0;
}

}

#endif // ENABLE(GEOLOCATION)
