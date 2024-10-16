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

#if ENABLE(WORKERS)

#include "JSDedicatedWorkerContext.h"

#include "DedicatedWorkerContext.h"
#include "EventListener.h"
#include "JSEventListener.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSDedicatedWorkerContext );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDedicatedWorkerContextTableValues[2] =
{
    { "onmessage", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDedicatedWorkerContextOnmessage ), ( intptr_t )setJSDedicatedWorkerContextOnmessage THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDedicatedWorkerContextTable = { 2, 1, JSDedicatedWorkerContextTableValues, 0 };
/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDedicatedWorkerContextPrototypeTableValues[2] =
{
    { "postMessage", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsDedicatedWorkerContextPrototypeFunctionPostMessage ), ( intptr_t )2 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDedicatedWorkerContextPrototypeTable = { 2, 1, JSDedicatedWorkerContextPrototypeTableValues, 0 };
static const HashTable *getJSDedicatedWorkerContextPrototypeTable( ExecState *exec )
{
    return getHashTableForGlobalData( exec->globalData(), &JSDedicatedWorkerContextPrototypeTable );
}

const ClassInfo JSDedicatedWorkerContextPrototype::s_info = { "DedicatedWorkerContextPrototype", &JSC::JSObjectWithGlobalObject::s_info, 0, getJSDedicatedWorkerContextPrototypeTable };

void *JSDedicatedWorkerContextPrototype::operator new ( size_t size, JSGlobalData *globalData )
{
    return globalData->heap.allocate( size );
}

bool JSDedicatedWorkerContextPrototype::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticFunctionSlot<JSObject>( exec, getJSDedicatedWorkerContextPrototypeTable( exec ), this, propertyName, slot );
}

bool JSDedicatedWorkerContextPrototype::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticFunctionDescriptor<JSObject>( exec, getJSDedicatedWorkerContextPrototypeTable( exec ), this, propertyName,
            descriptor );
}

static const HashTable *getJSDedicatedWorkerContextTable( ExecState *exec )
{
    return getHashTableForGlobalData( exec->globalData(), &JSDedicatedWorkerContextTable );
}

const ClassInfo JSDedicatedWorkerContext::s_info = { "DedicatedWorkerContext", &JSWorkerContext::s_info, 0, getJSDedicatedWorkerContextTable };

JSDedicatedWorkerContext::JSDedicatedWorkerContext( JSGlobalData &globalData, Structure *structure,
        PassRefPtr<DedicatedWorkerContext> impl )
    : JSWorkerContext( globalData, structure, impl )
{
    ASSERT( inherits( &s_info ) );
}

bool JSDedicatedWorkerContext::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSDedicatedWorkerContext, Base>( exec, getJSDedicatedWorkerContextTable( exec ), this, propertyName,
            slot );
}

bool JSDedicatedWorkerContext::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSDedicatedWorkerContext, Base>( exec, getJSDedicatedWorkerContextTable( exec ), this,
            propertyName, descriptor );
}

JSValue jsDedicatedWorkerContextOnmessage( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSDedicatedWorkerContext *castedThis = static_cast<JSDedicatedWorkerContext *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    DedicatedWorkerContext *imp = static_cast<DedicatedWorkerContext *>( castedThis->impl() );

    if ( EventListener *listener = imp->onmessage() )
    {
        if ( const JSEventListener *jsListener = JSEventListener::cast( listener ) )
        {
            if ( JSObject *jsFunction = jsListener->jsFunction( imp ) )
            {
                return jsFunction;
            }
        }
    }

    return jsNull();
}


void JSDedicatedWorkerContext::put( ExecState *exec, const Identifier &propertyName, JSValue value, PutPropertySlot &slot )
{
    lookupPut<JSDedicatedWorkerContext, Base>( exec, propertyName, value, getJSDedicatedWorkerContextTable( exec ), this, slot );
}

void setJSDedicatedWorkerContextOnmessage( ExecState *exec, JSObject *thisObject, JSValue value )
{
    UNUSED_PARAM( exec );
    JSDedicatedWorkerContext *castedThis = static_cast<JSDedicatedWorkerContext *>( thisObject );
    DedicatedWorkerContext *imp = static_cast<DedicatedWorkerContext *>( castedThis->impl() );
    imp->setOnmessage( createJSAttributeEventListener( exec, value, thisObject ) );
}


EncodedJSValue JSC_HOST_CALL jsDedicatedWorkerContextPrototypeFunctionPostMessage( ExecState *exec )
{
    JSDedicatedWorkerContext *castedThis = toJSDedicatedWorkerContext( exec->hostThisValue().toThisObject( exec ) );

    if ( !castedThis )
    {
        return throwVMTypeError( exec );
    }

    return JSValue::encode( castedThis->postMessage( exec ) );
}

DedicatedWorkerContext *toDedicatedWorkerContext( JSC::JSValue value )
{
    return value.inherits( &JSDedicatedWorkerContext::s_info ) ? static_cast<JSDedicatedWorkerContext *>( asObject(
                value ) )->impl() : 0;
}

}

#endif // ENABLE(WORKERS)
