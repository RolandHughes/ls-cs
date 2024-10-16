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
#include "JSStyleMedia.h"

#include "ExceptionCode.h"
#include "JSDOMBinding.h"
#include "KURL.h"
#include "StyleMedia.h"
#include <runtime/Error.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSStyleMedia );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSStyleMediaTableValues[3] =
{
    { "type", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsStyleMediaType ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsStyleMediaConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSStyleMediaTable = { 4, 3, JSStyleMediaTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSStyleMediaConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSStyleMediaConstructorTable = { 1, 0, JSStyleMediaConstructorTableValues, 0 };
class JSStyleMediaConstructor : public DOMConstructorObject
{
public:
    JSStyleMediaConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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
};

const ClassInfo JSStyleMediaConstructor::s_info = { "StyleMediaConstructor", &DOMConstructorObject::s_info, &JSStyleMediaConstructorTable, 0 };

JSStyleMediaConstructor::JSStyleMediaConstructor( ExecState *exec, Structure *structure, JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSStyleMediaPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSStyleMediaConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSStyleMediaConstructor, JSDOMWrapper>( exec, &JSStyleMediaConstructorTable, this, propertyName, slot );
}

bool JSStyleMediaConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSStyleMediaConstructor, JSDOMWrapper>( exec, &JSStyleMediaConstructorTable, this, propertyName,
            descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSStyleMediaPrototypeTableValues[2] =
{
    { "matchMedium", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsStyleMediaPrototypeFunctionMatchMedium ), ( intptr_t )1 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSStyleMediaPrototypeTable = { 2, 1, JSStyleMediaPrototypeTableValues, 0 };
const ClassInfo JSStyleMediaPrototype::s_info = { "StyleMediaPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSStyleMediaPrototypeTable, 0 };

JSObject *JSStyleMediaPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSStyleMedia>( exec, globalObject );
}

bool JSStyleMediaPrototype::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticFunctionSlot<JSObject>( exec, &JSStyleMediaPrototypeTable, this, propertyName, slot );
}

bool JSStyleMediaPrototype::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticFunctionDescriptor<JSObject>( exec, &JSStyleMediaPrototypeTable, this, propertyName, descriptor );
}

const ClassInfo JSStyleMedia::s_info = { "StyleMedia", &JSDOMWrapper::s_info, &JSStyleMediaTable, 0 };

JSStyleMedia::JSStyleMedia( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<StyleMedia> impl )
    : JSDOMWrapper( structure, globalObject )
    , m_impl( impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSStyleMedia::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSStyleMediaPrototype( exec->globalData(), globalObject,
            JSStyleMediaPrototype::createStructure( globalObject->globalData(), globalObject->objectPrototype() ) );
}

bool JSStyleMedia::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSStyleMedia, Base>( exec, &JSStyleMediaTable, this, propertyName, slot );
}

bool JSStyleMedia::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName, PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSStyleMedia, Base>( exec, &JSStyleMediaTable, this, propertyName, descriptor );
}

JSValue jsStyleMediaType( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSStyleMedia *castedThis = static_cast<JSStyleMedia *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    StyleMedia *imp = static_cast<StyleMedia *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->type() );
    return result;
}


JSValue jsStyleMediaConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSStyleMedia *domObject = static_cast<JSStyleMedia *>( asObject( slotBase ) );
    return JSStyleMedia::getConstructor( exec, domObject->globalObject() );
}

JSValue JSStyleMedia::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSStyleMediaConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}

EncodedJSValue JSC_HOST_CALL jsStyleMediaPrototypeFunctionMatchMedium( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSStyleMedia::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSStyleMedia *castedThis = static_cast<JSStyleMedia *>( asObject( thisValue ) );
    StyleMedia *imp = static_cast<StyleMedia *>( castedThis->impl() );
    const String &mediaquery( ustringToString( exec->argument( 0 ).toString( exec ) ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }


    JSC::JSValue result = jsBoolean( imp->matchMedium( mediaquery ) );
    return JSValue::encode( result );
}

static inline bool isObservable( JSStyleMedia *jsStyleMedia )
{
    if ( jsStyleMedia->hasCustomProperties() )
    {
        return true;
    }

    return false;
}

bool JSStyleMediaOwner::isReachableFromOpaqueRoots( JSC::Handle<JSC::Unknown> handle, void *, SlotVisitor &visitor )
{
    JSStyleMedia *jsStyleMedia = static_cast<JSStyleMedia *>( handle.get().asCell() );

    if ( !isObservable( jsStyleMedia ) )
    {
        return false;
    }

    Frame *root = jsStyleMedia->impl()->frame();

    if ( !root )
    {
        return false;
    }

    return visitor.containsOpaqueRoot( root );
}

void JSStyleMediaOwner::finalize( JSC::Handle<JSC::Unknown> handle, void *context )
{
    JSStyleMedia *jsStyleMedia = static_cast<JSStyleMedia *>( handle.get().asCell() );
    DOMWrapperWorld *world = static_cast<DOMWrapperWorld *>( context );
    uncacheWrapper( world, jsStyleMedia->impl(), jsStyleMedia );
}

JSC::JSValue toJS( JSC::ExecState *exec, JSDOMGlobalObject *globalObject, StyleMedia *impl )
{
    return wrap<JSStyleMedia>( exec, globalObject, impl );
}

StyleMedia *toStyleMedia( JSC::JSValue value )
{
    return value.inherits( &JSStyleMedia::s_info ) ? static_cast<JSStyleMedia *>( asObject( value ) )->impl() : 0;
}

}
