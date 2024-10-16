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

#if ENABLE(FILE_SYSTEM)

#include "JSDOMFileSystemSync.h"

#include "DOMFileSystemSync.h"
#include "DirectoryEntrySync.h"
#include "JSDirectoryEntrySync.h"
#include "KURL.h"
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSDOMFileSystemSync );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDOMFileSystemSyncTableValues[4] =
{
    { "name", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMFileSystemSyncName ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "root", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMFileSystemSyncRoot ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsDOMFileSystemSyncConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDOMFileSystemSyncTable = { 9, 7, JSDOMFileSystemSyncTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDOMFileSystemSyncConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDOMFileSystemSyncConstructorTable = { 1, 0, JSDOMFileSystemSyncConstructorTableValues, 0 };
class JSDOMFileSystemSyncConstructor : public DOMConstructorObject
{
public:
    JSDOMFileSystemSyncConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSDOMFileSystemSyncConstructor::s_info = { "DOMFileSystemSyncConstructor", &DOMConstructorObject::s_info, &JSDOMFileSystemSyncConstructorTable, 0 };

JSDOMFileSystemSyncConstructor::JSDOMFileSystemSyncConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSDOMFileSystemSyncPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSDOMFileSystemSyncConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSDOMFileSystemSyncConstructor, JSDOMWrapper>( exec, &JSDOMFileSystemSyncConstructorTable, this,
            propertyName, slot );
}

bool JSDOMFileSystemSyncConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSDOMFileSystemSyncConstructor, JSDOMWrapper>( exec, &JSDOMFileSystemSyncConstructorTable, this,
            propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDOMFileSystemSyncPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDOMFileSystemSyncPrototypeTable = { 1, 0, JSDOMFileSystemSyncPrototypeTableValues, 0 };
static const HashTable *getJSDOMFileSystemSyncPrototypeTable( ExecState *exec )
{
    return getHashTableForGlobalData( exec->globalData(), &JSDOMFileSystemSyncPrototypeTable );
}

const ClassInfo JSDOMFileSystemSyncPrototype::s_info = { "DOMFileSystemSyncPrototype", &JSC::JSObjectWithGlobalObject::s_info, 0, getJSDOMFileSystemSyncPrototypeTable };

JSObject *JSDOMFileSystemSyncPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSDOMFileSystemSync>( exec, globalObject );
}

static const HashTable *getJSDOMFileSystemSyncTable( ExecState *exec )
{
    return getHashTableForGlobalData( exec->globalData(), &JSDOMFileSystemSyncTable );
}

const ClassInfo JSDOMFileSystemSync::s_info = { "DOMFileSystemSync", &JSDOMWrapper::s_info, 0, getJSDOMFileSystemSyncTable };

JSDOMFileSystemSync::JSDOMFileSystemSync( Structure *structure, JSDOMGlobalObject *globalObject,
        PassRefPtr<DOMFileSystemSync> impl )
    : JSDOMWrapper( structure, globalObject )
    , m_impl( impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSDOMFileSystemSync::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSDOMFileSystemSyncPrototype( exec->globalData(), globalObject,
            JSDOMFileSystemSyncPrototype::createStructure( globalObject->globalData(), globalObject->objectPrototype() ) );
}

bool JSDOMFileSystemSync::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSDOMFileSystemSync, Base>( exec, getJSDOMFileSystemSyncTable( exec ), this, propertyName, slot );
}

bool JSDOMFileSystemSync::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSDOMFileSystemSync, Base>( exec, getJSDOMFileSystemSyncTable( exec ), this, propertyName,
            descriptor );
}

JSValue jsDOMFileSystemSyncName( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSDOMFileSystemSync *castedThis = static_cast<JSDOMFileSystemSync *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    DOMFileSystemSync *imp = static_cast<DOMFileSystemSync *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->name() );
    return result;
}


JSValue jsDOMFileSystemSyncRoot( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSDOMFileSystemSync *castedThis = static_cast<JSDOMFileSystemSync *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    DOMFileSystemSync *imp = static_cast<DOMFileSystemSync *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->root() ) );
    return result;
}


JSValue jsDOMFileSystemSyncConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSDOMFileSystemSync *domObject = static_cast<JSDOMFileSystemSync *>( asObject( slotBase ) );
    return JSDOMFileSystemSync::getConstructor( exec, domObject->globalObject() );
}

JSValue JSDOMFileSystemSync::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSDOMFileSystemSyncConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}

JSC::JSValue toJS( JSC::ExecState *exec, JSDOMGlobalObject *globalObject, DOMFileSystemSync *impl )
{
    return wrap<JSDOMFileSystemSync>( exec, globalObject, impl );
}

DOMFileSystemSync *toDOMFileSystemSync( JSC::JSValue value )
{
    return value.inherits( &JSDOMFileSystemSync::s_info ) ? static_cast<JSDOMFileSystemSync *>( asObject( value ) )->impl() : 0;
}

}

#endif // ENABLE(FILE_SYSTEM)
