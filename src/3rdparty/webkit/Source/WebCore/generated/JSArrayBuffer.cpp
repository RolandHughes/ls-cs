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
#include "JSArrayBuffer.h"

#include "ArrayBuffer.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSArrayBuffer );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSArrayBufferTableValues[3] =
{
    { "byteLength", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsArrayBufferByteLength ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsArrayBufferConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSArrayBufferTable = { 5, 3, JSArrayBufferTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSArrayBufferConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSArrayBufferConstructorTable = { 1, 0, JSArrayBufferConstructorTableValues, 0 };
const ClassInfo JSArrayBufferConstructor::s_info = { "ArrayBufferConstructor", &DOMConstructorObject::s_info, &JSArrayBufferConstructorTable, 0 };

JSArrayBufferConstructor::JSArrayBufferConstructor( ExecState *exec, Structure *structure, JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSArrayBufferPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSArrayBufferConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSArrayBufferConstructor, JSDOMWrapper>( exec, &JSArrayBufferConstructorTable, this, propertyName,
            slot );
}

bool JSArrayBufferConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSArrayBufferConstructor, JSDOMWrapper>( exec, &JSArrayBufferConstructorTable, this, propertyName,
            descriptor );
}

ConstructType JSArrayBufferConstructor::getConstructData( ConstructData &constructData )
{
    constructData.native.function = constructJSArrayBuffer;
    return ConstructTypeHost;
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSArrayBufferPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSArrayBufferPrototypeTable = { 1, 0, JSArrayBufferPrototypeTableValues, 0 };
static const HashTable *getJSArrayBufferPrototypeTable( ExecState *exec )
{
    return getHashTableForGlobalData( exec->globalData(), &JSArrayBufferPrototypeTable );
}

const ClassInfo JSArrayBufferPrototype::s_info = { "ArrayBufferPrototype", &JSC::JSObjectWithGlobalObject::s_info, 0, getJSArrayBufferPrototypeTable };

JSObject *JSArrayBufferPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSArrayBuffer>( exec, globalObject );
}

static const HashTable *getJSArrayBufferTable( ExecState *exec )
{
    return getHashTableForGlobalData( exec->globalData(), &JSArrayBufferTable );
}

const ClassInfo JSArrayBuffer::s_info = { "ArrayBuffer", &JSDOMWrapper::s_info, 0, getJSArrayBufferTable };

JSArrayBuffer::JSArrayBuffer( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<ArrayBuffer> impl )
    : JSDOMWrapper( structure, globalObject )
    , m_impl( impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSArrayBuffer::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSArrayBufferPrototype( exec->globalData(), globalObject,
            JSArrayBufferPrototype::createStructure( globalObject->globalData(), globalObject->objectPrototype() ) );
}

bool JSArrayBuffer::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSArrayBuffer, Base>( exec, getJSArrayBufferTable( exec ), this, propertyName, slot );
}

bool JSArrayBuffer::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName, PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSArrayBuffer, Base>( exec, getJSArrayBufferTable( exec ), this, propertyName, descriptor );
}

JSValue jsArrayBufferByteLength( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSArrayBuffer *castedThis = static_cast<JSArrayBuffer *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    ArrayBuffer *imp = static_cast<ArrayBuffer *>( castedThis->impl() );
    JSValue result = jsNumber( imp->byteLength() );
    return result;
}


JSValue jsArrayBufferConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSArrayBuffer *domObject = static_cast<JSArrayBuffer *>( asObject( slotBase ) );
    return JSArrayBuffer::getConstructor( exec, domObject->globalObject() );
}

JSValue JSArrayBuffer::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSArrayBufferConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}

static inline bool isObservable( JSArrayBuffer *jsArrayBuffer )
{
    if ( jsArrayBuffer->hasCustomProperties() )
    {
        return true;
    }

    return false;
}

bool JSArrayBufferOwner::isReachableFromOpaqueRoots( JSC::Handle<JSC::Unknown> handle, void *, SlotVisitor &visitor )
{
    JSArrayBuffer *jsArrayBuffer = static_cast<JSArrayBuffer *>( handle.get().asCell() );

    if ( !isObservable( jsArrayBuffer ) )
    {
        return false;
    }

    ArrayBuffer *root = jsArrayBuffer->impl();
    return visitor.containsOpaqueRoot( root );
}

void JSArrayBufferOwner::finalize( JSC::Handle<JSC::Unknown> handle, void *context )
{
    JSArrayBuffer *jsArrayBuffer = static_cast<JSArrayBuffer *>( handle.get().asCell() );
    DOMWrapperWorld *world = static_cast<DOMWrapperWorld *>( context );
    uncacheWrapper( world, jsArrayBuffer->impl(), jsArrayBuffer );
}

JSC::JSValue toJS( JSC::ExecState *exec, JSDOMGlobalObject *globalObject, ArrayBuffer *impl )
{
    return wrap<JSArrayBuffer>( exec, globalObject, impl );
}

ArrayBuffer *toArrayBuffer( JSC::JSValue value )
{
    return value.inherits( &JSArrayBuffer::s_info ) ? static_cast<JSArrayBuffer *>( asObject( value ) )->impl() : 0;
}

}
