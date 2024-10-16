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
#include "JSStyleSheet.h"

#include "JSMediaList.h"
#include "JSNode.h"
#include "JSStyleSheet.h"
#include "KURL.h"
#include "MediaList.h"
#include "Node.h"
#include "StyleSheet.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSStyleSheet );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSStyleSheetTableValues[9] =
{
    { "type", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsStyleSheetType ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "disabled", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsStyleSheetDisabled ), ( intptr_t )setJSStyleSheetDisabled THUNK_GENERATOR( 0 ) },
    { "ownerNode", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsStyleSheetOwnerNode ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "parentStyleSheet", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsStyleSheetParentStyleSheet ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "href", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsStyleSheetHref ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "title", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsStyleSheetTitle ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "media", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsStyleSheetMedia ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsStyleSheetConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSStyleSheetTable = { 17, 15, JSStyleSheetTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSStyleSheetConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSStyleSheetConstructorTable = { 1, 0, JSStyleSheetConstructorTableValues, 0 };
class JSStyleSheetConstructor : public DOMConstructorObject
{
public:
    JSStyleSheetConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSStyleSheetConstructor::s_info = { "StyleSheetConstructor", &DOMConstructorObject::s_info, &JSStyleSheetConstructorTable, 0 };

JSStyleSheetConstructor::JSStyleSheetConstructor( ExecState *exec, Structure *structure, JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSStyleSheetPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSStyleSheetConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSStyleSheetConstructor, JSDOMWrapper>( exec, &JSStyleSheetConstructorTable, this, propertyName, slot );
}

bool JSStyleSheetConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSStyleSheetConstructor, JSDOMWrapper>( exec, &JSStyleSheetConstructorTable, this, propertyName,
            descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSStyleSheetPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSStyleSheetPrototypeTable = { 1, 0, JSStyleSheetPrototypeTableValues, 0 };
const ClassInfo JSStyleSheetPrototype::s_info = { "StyleSheetPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSStyleSheetPrototypeTable, 0 };

JSObject *JSStyleSheetPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSStyleSheet>( exec, globalObject );
}

const ClassInfo JSStyleSheet::s_info = { "StyleSheet", &JSDOMWrapper::s_info, &JSStyleSheetTable, 0 };

JSStyleSheet::JSStyleSheet( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<StyleSheet> impl )
    : JSDOMWrapper( structure, globalObject )
    , m_impl( impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSStyleSheet::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSStyleSheetPrototype( exec->globalData(), globalObject,
            JSStyleSheetPrototype::createStructure( globalObject->globalData(), globalObject->objectPrototype() ) );
}

bool JSStyleSheet::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSStyleSheet, Base>( exec, &JSStyleSheetTable, this, propertyName, slot );
}

bool JSStyleSheet::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName, PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSStyleSheet, Base>( exec, &JSStyleSheetTable, this, propertyName, descriptor );
}

JSValue jsStyleSheetType( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSStyleSheet *castedThis = static_cast<JSStyleSheet *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    StyleSheet *imp = static_cast<StyleSheet *>( castedThis->impl() );
    JSValue result = jsStringOrNull( exec, imp->type() );
    return result;
}


JSValue jsStyleSheetDisabled( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSStyleSheet *castedThis = static_cast<JSStyleSheet *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    StyleSheet *imp = static_cast<StyleSheet *>( castedThis->impl() );
    JSValue result = jsBoolean( imp->disabled() );
    return result;
}


JSValue jsStyleSheetOwnerNode( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSStyleSheet *castedThis = static_cast<JSStyleSheet *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    StyleSheet *imp = static_cast<StyleSheet *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->ownerNode() ) );
    return result;
}


JSValue jsStyleSheetParentStyleSheet( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSStyleSheet *castedThis = static_cast<JSStyleSheet *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    StyleSheet *imp = static_cast<StyleSheet *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->parentStyleSheet() ) );
    return result;
}


JSValue jsStyleSheetHref( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSStyleSheet *castedThis = static_cast<JSStyleSheet *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    StyleSheet *imp = static_cast<StyleSheet *>( castedThis->impl() );
    JSValue result = jsStringOrNull( exec, imp->href() );
    return result;
}


JSValue jsStyleSheetTitle( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSStyleSheet *castedThis = static_cast<JSStyleSheet *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    StyleSheet *imp = static_cast<StyleSheet *>( castedThis->impl() );
    JSValue result = jsStringOrNull( exec, imp->title() );
    return result;
}


JSValue jsStyleSheetMedia( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSStyleSheet *castedThis = static_cast<JSStyleSheet *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    StyleSheet *imp = static_cast<StyleSheet *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->media() ) );
    return result;
}


JSValue jsStyleSheetConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSStyleSheet *domObject = static_cast<JSStyleSheet *>( asObject( slotBase ) );
    return JSStyleSheet::getConstructor( exec, domObject->globalObject() );
}

void JSStyleSheet::put( ExecState *exec, const Identifier &propertyName, JSValue value, PutPropertySlot &slot )
{
    lookupPut<JSStyleSheet, Base>( exec, propertyName, value, &JSStyleSheetTable, this, slot );
}

void setJSStyleSheetDisabled( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSStyleSheet *castedThis = static_cast<JSStyleSheet *>( thisObject );
    StyleSheet *imp = static_cast<StyleSheet *>( castedThis->impl() );
    imp->setDisabled( value.toBoolean( exec ) );
}


JSValue JSStyleSheet::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSStyleSheetConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}

static inline bool isObservable( JSStyleSheet *jsStyleSheet )
{
    if ( jsStyleSheet->hasCustomProperties() )
    {
        return true;
    }

    return false;
}

bool JSStyleSheetOwner::isReachableFromOpaqueRoots( JSC::Handle<JSC::Unknown> handle, void *, SlotVisitor &visitor )
{
    JSStyleSheet *jsStyleSheet = static_cast<JSStyleSheet *>( handle.get().asCell() );

    if ( !isObservable( jsStyleSheet ) )
    {
        return false;
    }

    void *root = WebCore::root( jsStyleSheet->impl() );
    return visitor.containsOpaqueRoot( root );
}

void JSStyleSheetOwner::finalize( JSC::Handle<JSC::Unknown> handle, void *context )
{
    JSStyleSheet *jsStyleSheet = static_cast<JSStyleSheet *>( handle.get().asCell() );
    DOMWrapperWorld *world = static_cast<DOMWrapperWorld *>( context );
    uncacheWrapper( world, jsStyleSheet->impl(), jsStyleSheet );
}

StyleSheet *toStyleSheet( JSC::JSValue value )
{
    return value.inherits( &JSStyleSheet::s_info ) ? static_cast<JSStyleSheet *>( asObject( value ) )->impl() : 0;
}

}
