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

#if ENABLE(WEB_TIMING)

#include "JSPerformanceNavigation.h"

#include "PerformanceNavigation.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSPerformanceNavigation );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSPerformanceNavigationTableValues[3] =
{
    { "type", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsPerformanceNavigationType ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "redirectCount", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsPerformanceNavigationRedirectCount ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSPerformanceNavigationTable = { 5, 3, JSPerformanceNavigationTableValues, 0 };
/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSPerformanceNavigationPrototypeTableValues[5] =
{
    { "TYPE_NAVIGATE", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsPerformanceNavigationTYPE_NAVIGATE ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "TYPE_RELOAD", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsPerformanceNavigationTYPE_RELOAD ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "TYPE_BACK_FORWARD", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsPerformanceNavigationTYPE_BACK_FORWARD ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "TYPE_RESERVED", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsPerformanceNavigationTYPE_RESERVED ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSPerformanceNavigationPrototypeTable = { 9, 7, JSPerformanceNavigationPrototypeTableValues, 0 };
const ClassInfo JSPerformanceNavigationPrototype::s_info = { "PerformanceNavigationPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSPerformanceNavigationPrototypeTable, 0 };

JSObject *JSPerformanceNavigationPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSPerformanceNavigation>( exec, globalObject );
}

bool JSPerformanceNavigationPrototype::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSPerformanceNavigationPrototype, JSObject>( exec, &JSPerformanceNavigationPrototypeTable, this,
            propertyName, slot );
}

bool JSPerformanceNavigationPrototype::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSPerformanceNavigationPrototype, JSObject>( exec, &JSPerformanceNavigationPrototypeTable, this,
            propertyName, descriptor );
}

const ClassInfo JSPerformanceNavigation::s_info = { "PerformanceNavigation", &JSDOMWrapper::s_info, &JSPerformanceNavigationTable, 0 };

JSPerformanceNavigation::JSPerformanceNavigation( Structure *structure, JSDOMGlobalObject *globalObject,
        PassRefPtr<PerformanceNavigation> impl )
    : JSDOMWrapper( structure, globalObject )
    , m_impl( impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSPerformanceNavigation::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSPerformanceNavigationPrototype( exec->globalData(), globalObject,
            JSPerformanceNavigationPrototype::createStructure( globalObject->globalData(), globalObject->objectPrototype() ) );
}

bool JSPerformanceNavigation::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSPerformanceNavigation, Base>( exec, &JSPerformanceNavigationTable, this, propertyName, slot );
}

bool JSPerformanceNavigation::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSPerformanceNavigation, Base>( exec, &JSPerformanceNavigationTable, this, propertyName,
            descriptor );
}

JSValue jsPerformanceNavigationType( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSPerformanceNavigation *castedThis = static_cast<JSPerformanceNavigation *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    PerformanceNavigation *imp = static_cast<PerformanceNavigation *>( castedThis->impl() );
    JSValue result = jsNumber( imp->type() );
    return result;
}


JSValue jsPerformanceNavigationRedirectCount( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSPerformanceNavigation *castedThis = static_cast<JSPerformanceNavigation *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    PerformanceNavigation *imp = static_cast<PerformanceNavigation *>( castedThis->impl() );
    JSValue result = jsNumber( imp->redirectCount() );
    return result;
}


// Constant getters

JSValue jsPerformanceNavigationTYPE_NAVIGATE( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 0 ) );
}

JSValue jsPerformanceNavigationTYPE_RELOAD( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 1 ) );
}

JSValue jsPerformanceNavigationTYPE_BACK_FORWARD( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 2 ) );
}

JSValue jsPerformanceNavigationTYPE_RESERVED( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 255 ) );
}

JSC::JSValue toJS( JSC::ExecState *exec, JSDOMGlobalObject *globalObject, PerformanceNavigation *impl )
{
    return wrap<JSPerformanceNavigation>( exec, globalObject, impl );
}

PerformanceNavigation *toPerformanceNavigation( JSC::JSValue value )
{
    return value.inherits( &JSPerformanceNavigation::s_info ) ? static_cast<JSPerformanceNavigation *>( asObject(
                value ) )->impl() : 0;
}

}

#endif // ENABLE(WEB_TIMING)
