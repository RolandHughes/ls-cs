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

#if ENABLE(OFFLINE_WEB_APPLICATIONS)

#include "JSDOMApplicationCache.h"

#include "DOMApplicationCache.h"
#include "Event.h"
#include "EventListener.h"
#include "ExceptionCode.h"
#include "JSDOMBinding.h"
#include "JSEvent.h"
#include "JSEventListener.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSDOMApplicationCache );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDOMApplicationCacheTableValues[10] =
{
    { "status", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheStatus ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "onchecking", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheOnchecking ), ( intptr_t )setJSDOMApplicationCacheOnchecking THUNK_GENERATOR( 0 ) },
    { "onerror", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheOnerror ), ( intptr_t )setJSDOMApplicationCacheOnerror THUNK_GENERATOR( 0 ) },
    { "onnoupdate", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheOnnoupdate ), ( intptr_t )setJSDOMApplicationCacheOnnoupdate THUNK_GENERATOR( 0 ) },
    { "ondownloading", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheOndownloading ), ( intptr_t )setJSDOMApplicationCacheOndownloading THUNK_GENERATOR( 0 ) },
    { "onprogress", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheOnprogress ), ( intptr_t )setJSDOMApplicationCacheOnprogress THUNK_GENERATOR( 0 ) },
    { "onupdateready", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheOnupdateready ), ( intptr_t )setJSDOMApplicationCacheOnupdateready THUNK_GENERATOR( 0 ) },
    { "oncached", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheOncached ), ( intptr_t )setJSDOMApplicationCacheOncached THUNK_GENERATOR( 0 ) },
    { "onobsolete", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheOnobsolete ), ( intptr_t )setJSDOMApplicationCacheOnobsolete THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDOMApplicationCacheTable = { 33, 31, JSDOMApplicationCacheTableValues, 0 };
/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDOMApplicationCachePrototypeTableValues[12] =
{
    { "UNCACHED", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheUNCACHED ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "IDLE", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheIDLE ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "CHECKING", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheCHECKING ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "DOWNLOADING", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheDOWNLOADING ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "UPDATEREADY", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheUPDATEREADY ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "OBSOLETE", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMApplicationCacheOBSOLETE ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "update", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsDOMApplicationCachePrototypeFunctionUpdate ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "swapCache", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsDOMApplicationCachePrototypeFunctionSwapCache ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "addEventListener", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsDOMApplicationCachePrototypeFunctionAddEventListener ), ( intptr_t )3 THUNK_GENERATOR( 0 ) },
    { "removeEventListener", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsDOMApplicationCachePrototypeFunctionRemoveEventListener ), ( intptr_t )3 THUNK_GENERATOR( 0 ) },
    { "dispatchEvent", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsDOMApplicationCachePrototypeFunctionDispatchEvent ), ( intptr_t )1 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDOMApplicationCachePrototypeTable = { 33, 31, JSDOMApplicationCachePrototypeTableValues, 0 };
const ClassInfo JSDOMApplicationCachePrototype::s_info = { "DOMApplicationCachePrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSDOMApplicationCachePrototypeTable, 0 };

JSObject *JSDOMApplicationCachePrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSDOMApplicationCache>( exec, globalObject );
}

bool JSDOMApplicationCachePrototype::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticPropertySlot<JSDOMApplicationCachePrototype, JSObject>( exec, &JSDOMApplicationCachePrototypeTable, this,
            propertyName, slot );
}

bool JSDOMApplicationCachePrototype::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticPropertyDescriptor<JSDOMApplicationCachePrototype, JSObject>( exec, &JSDOMApplicationCachePrototypeTable, this,
            propertyName, descriptor );
}

const ClassInfo JSDOMApplicationCache::s_info = { "DOMApplicationCache", &JSDOMWrapper::s_info, &JSDOMApplicationCacheTable, 0 };

JSDOMApplicationCache::JSDOMApplicationCache( Structure *structure, JSDOMGlobalObject *globalObject,
        PassRefPtr<DOMApplicationCache> impl )
    : JSDOMWrapper( structure, globalObject )
    , m_impl( impl )
{
    ASSERT( inherits( &s_info ) );
}

void JSDOMApplicationCache::visitChildren( SlotVisitor &visitor )
{
    Base::visitChildren( visitor );
    impl()->visitJSEventListeners( visitor );
}

JSObject *JSDOMApplicationCache::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSDOMApplicationCachePrototype( exec->globalData(), globalObject,
            JSDOMApplicationCachePrototype::createStructure( globalObject->globalData(), globalObject->objectPrototype() ) );
}

bool JSDOMApplicationCache::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSDOMApplicationCache, Base>( exec, &JSDOMApplicationCacheTable, this, propertyName, slot );
}

bool JSDOMApplicationCache::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSDOMApplicationCache, Base>( exec, &JSDOMApplicationCacheTable, this, propertyName, descriptor );
}

JSValue jsDOMApplicationCacheStatus( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    JSValue result = jsNumber( imp->status() );
    return result;
}


JSValue jsDOMApplicationCacheOnchecking( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );

    if ( EventListener *listener = imp->onchecking() )
    {
        if ( const JSEventListener *jsListener = JSEventListener::cast( listener ) )
        {
            if ( JSObject *jsFunction = jsListener->jsFunction( imp->scriptExecutionContext() ) )
            {
                return jsFunction;
            }
        }
    }

    return jsNull();
}


JSValue jsDOMApplicationCacheOnerror( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );

    if ( EventListener *listener = imp->onerror() )
    {
        if ( const JSEventListener *jsListener = JSEventListener::cast( listener ) )
        {
            if ( JSObject *jsFunction = jsListener->jsFunction( imp->scriptExecutionContext() ) )
            {
                return jsFunction;
            }
        }
    }

    return jsNull();
}


JSValue jsDOMApplicationCacheOnnoupdate( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );

    if ( EventListener *listener = imp->onnoupdate() )
    {
        if ( const JSEventListener *jsListener = JSEventListener::cast( listener ) )
        {
            if ( JSObject *jsFunction = jsListener->jsFunction( imp->scriptExecutionContext() ) )
            {
                return jsFunction;
            }
        }
    }

    return jsNull();
}


JSValue jsDOMApplicationCacheOndownloading( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );

    if ( EventListener *listener = imp->ondownloading() )
    {
        if ( const JSEventListener *jsListener = JSEventListener::cast( listener ) )
        {
            if ( JSObject *jsFunction = jsListener->jsFunction( imp->scriptExecutionContext() ) )
            {
                return jsFunction;
            }
        }
    }

    return jsNull();
}


JSValue jsDOMApplicationCacheOnprogress( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );

    if ( EventListener *listener = imp->onprogress() )
    {
        if ( const JSEventListener *jsListener = JSEventListener::cast( listener ) )
        {
            if ( JSObject *jsFunction = jsListener->jsFunction( imp->scriptExecutionContext() ) )
            {
                return jsFunction;
            }
        }
    }

    return jsNull();
}


JSValue jsDOMApplicationCacheOnupdateready( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );

    if ( EventListener *listener = imp->onupdateready() )
    {
        if ( const JSEventListener *jsListener = JSEventListener::cast( listener ) )
        {
            if ( JSObject *jsFunction = jsListener->jsFunction( imp->scriptExecutionContext() ) )
            {
                return jsFunction;
            }
        }
    }

    return jsNull();
}


JSValue jsDOMApplicationCacheOncached( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );

    if ( EventListener *listener = imp->oncached() )
    {
        if ( const JSEventListener *jsListener = JSEventListener::cast( listener ) )
        {
            if ( JSObject *jsFunction = jsListener->jsFunction( imp->scriptExecutionContext() ) )
            {
                return jsFunction;
            }
        }
    }

    return jsNull();
}


JSValue jsDOMApplicationCacheOnobsolete( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );

    if ( EventListener *listener = imp->onobsolete() )
    {
        if ( const JSEventListener *jsListener = JSEventListener::cast( listener ) )
        {
            if ( JSObject *jsFunction = jsListener->jsFunction( imp->scriptExecutionContext() ) )
            {
                return jsFunction;
            }
        }
    }

    return jsNull();
}


void JSDOMApplicationCache::put( ExecState *exec, const Identifier &propertyName, JSValue value, PutPropertySlot &slot )
{
    lookupPut<JSDOMApplicationCache, Base>( exec, propertyName, value, &JSDOMApplicationCacheTable, this, slot );
}

void setJSDOMApplicationCacheOnchecking( ExecState *exec, JSObject *thisObject, JSValue value )
{
    UNUSED_PARAM( exec );
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( thisObject );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    imp->setOnchecking( createJSAttributeEventListener( exec, value, thisObject ) );
}


void setJSDOMApplicationCacheOnerror( ExecState *exec, JSObject *thisObject, JSValue value )
{
    UNUSED_PARAM( exec );
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( thisObject );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    imp->setOnerror( createJSAttributeEventListener( exec, value, thisObject ) );
}


void setJSDOMApplicationCacheOnnoupdate( ExecState *exec, JSObject *thisObject, JSValue value )
{
    UNUSED_PARAM( exec );
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( thisObject );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    imp->setOnnoupdate( createJSAttributeEventListener( exec, value, thisObject ) );
}


void setJSDOMApplicationCacheOndownloading( ExecState *exec, JSObject *thisObject, JSValue value )
{
    UNUSED_PARAM( exec );
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( thisObject );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    imp->setOndownloading( createJSAttributeEventListener( exec, value, thisObject ) );
}


void setJSDOMApplicationCacheOnprogress( ExecState *exec, JSObject *thisObject, JSValue value )
{
    UNUSED_PARAM( exec );
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( thisObject );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    imp->setOnprogress( createJSAttributeEventListener( exec, value, thisObject ) );
}


void setJSDOMApplicationCacheOnupdateready( ExecState *exec, JSObject *thisObject, JSValue value )
{
    UNUSED_PARAM( exec );
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( thisObject );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    imp->setOnupdateready( createJSAttributeEventListener( exec, value, thisObject ) );
}


void setJSDOMApplicationCacheOncached( ExecState *exec, JSObject *thisObject, JSValue value )
{
    UNUSED_PARAM( exec );
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( thisObject );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    imp->setOncached( createJSAttributeEventListener( exec, value, thisObject ) );
}


void setJSDOMApplicationCacheOnobsolete( ExecState *exec, JSObject *thisObject, JSValue value )
{
    UNUSED_PARAM( exec );
    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( thisObject );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    imp->setOnobsolete( createJSAttributeEventListener( exec, value, thisObject ) );
}


EncodedJSValue JSC_HOST_CALL jsDOMApplicationCachePrototypeFunctionUpdate( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSDOMApplicationCache::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( thisValue ) );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    ExceptionCode ec = 0;

    imp->update( ec );
    setDOMException( exec, ec );
    return JSValue::encode( jsUndefined() );
}

EncodedJSValue JSC_HOST_CALL jsDOMApplicationCachePrototypeFunctionSwapCache( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSDOMApplicationCache::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( thisValue ) );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    ExceptionCode ec = 0;

    imp->swapCache( ec );
    setDOMException( exec, ec );
    return JSValue::encode( jsUndefined() );
}

EncodedJSValue JSC_HOST_CALL jsDOMApplicationCachePrototypeFunctionAddEventListener( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSDOMApplicationCache::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( thisValue ) );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    JSValue listener = exec->argument( 1 );

    if ( !listener.isObject() )
    {
        return JSValue::encode( jsUndefined() );
    }

    imp->addEventListener( ustringToAtomicString( exec->argument( 0 ).toString( exec ) ),
                           JSEventListener::create( asObject( listener ), castedThis, false, currentWorld( exec ) ), exec->argument( 2 ).toBoolean( exec ) );
    return JSValue::encode( jsUndefined() );
}

EncodedJSValue JSC_HOST_CALL jsDOMApplicationCachePrototypeFunctionRemoveEventListener( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSDOMApplicationCache::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( thisValue ) );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    JSValue listener = exec->argument( 1 );

    if ( !listener.isObject() )
    {
        return JSValue::encode( jsUndefined() );
    }

    imp->removeEventListener( ustringToAtomicString( exec->argument( 0 ).toString( exec ) ),
                              JSEventListener::create( asObject( listener ), castedThis, false, currentWorld( exec ) ).get(),
                              exec->argument( 2 ).toBoolean( exec ) );
    return JSValue::encode( jsUndefined() );
}

EncodedJSValue JSC_HOST_CALL jsDOMApplicationCachePrototypeFunctionDispatchEvent( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSDOMApplicationCache::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSDOMApplicationCache *castedThis = static_cast<JSDOMApplicationCache *>( asObject( thisValue ) );
    DOMApplicationCache *imp = static_cast<DOMApplicationCache *>( castedThis->impl() );
    ExceptionCode ec = 0;
    Event *evt( toEvent( exec->argument( 0 ) ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }


    JSC::JSValue result = jsBoolean( imp->dispatchEvent( evt, ec ) );
    setDOMException( exec, ec );
    return JSValue::encode( result );
}

// Constant getters

JSValue jsDOMApplicationCacheUNCACHED( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 0 ) );
}

JSValue jsDOMApplicationCacheIDLE( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 1 ) );
}

JSValue jsDOMApplicationCacheCHECKING( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 2 ) );
}

JSValue jsDOMApplicationCacheDOWNLOADING( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 3 ) );
}

JSValue jsDOMApplicationCacheUPDATEREADY( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 4 ) );
}

JSValue jsDOMApplicationCacheOBSOLETE( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 5 ) );
}

static inline bool isObservable( JSDOMApplicationCache *jsDOMApplicationCache )
{
    if ( jsDOMApplicationCache->hasCustomProperties() )
    {
        return true;
    }

    if ( jsDOMApplicationCache->impl()->hasEventListeners() )
    {
        return true;
    }

    return false;
}

bool JSDOMApplicationCacheOwner::isReachableFromOpaqueRoots( JSC::Handle<JSC::Unknown> handle, void *, SlotVisitor &visitor )
{
    JSDOMApplicationCache *jsDOMApplicationCache = static_cast<JSDOMApplicationCache *>( handle.get().asCell() );

    if ( !isObservable( jsDOMApplicationCache ) )
    {
        return false;
    }

    Frame *root = jsDOMApplicationCache->impl()->frame();

    if ( !root )
    {
        return false;
    }

    return visitor.containsOpaqueRoot( root );
}

void JSDOMApplicationCacheOwner::finalize( JSC::Handle<JSC::Unknown> handle, void *context )
{
    JSDOMApplicationCache *jsDOMApplicationCache = static_cast<JSDOMApplicationCache *>( handle.get().asCell() );
    DOMWrapperWorld *world = static_cast<DOMWrapperWorld *>( context );
    uncacheWrapper( world, jsDOMApplicationCache->impl(), jsDOMApplicationCache );
}

JSC::JSValue toJS( JSC::ExecState *exec, JSDOMGlobalObject *globalObject, DOMApplicationCache *impl )
{
    return wrap<JSDOMApplicationCache>( exec, globalObject, impl );
}

DOMApplicationCache *toDOMApplicationCache( JSC::JSValue value )
{
    return value.inherits( &JSDOMApplicationCache::s_info ) ? static_cast<JSDOMApplicationCache *>( asObject( value ) )->impl() : 0;
}

}

#endif // ENABLE(OFFLINE_WEB_APPLICATIONS)
