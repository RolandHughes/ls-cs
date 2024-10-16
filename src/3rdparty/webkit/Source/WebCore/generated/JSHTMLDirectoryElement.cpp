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
#include "JSHTMLDirectoryElement.h"

#include "HTMLDirectoryElement.h"
#include "HTMLNames.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSHTMLDirectoryElement );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLDirectoryElementTableValues[3] =
{
    { "compact", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLDirectoryElementCompact ), ( intptr_t )setJSHTMLDirectoryElementCompact THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLDirectoryElementConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLDirectoryElementTable = { 4, 3, JSHTMLDirectoryElementTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLDirectoryElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLDirectoryElementConstructorTable = { 1, 0, JSHTMLDirectoryElementConstructorTableValues, 0 };
class JSHTMLDirectoryElementConstructor : public DOMConstructorObject
{
public:
    JSHTMLDirectoryElementConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSHTMLDirectoryElementConstructor::s_info = { "HTMLDirectoryElementConstructor", &DOMConstructorObject::s_info, &JSHTMLDirectoryElementConstructorTable, 0 };

JSHTMLDirectoryElementConstructor::JSHTMLDirectoryElementConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSHTMLDirectoryElementPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSHTMLDirectoryElementConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSHTMLDirectoryElementConstructor, JSDOMWrapper>( exec, &JSHTMLDirectoryElementConstructorTable, this,
            propertyName, slot );
}

bool JSHTMLDirectoryElementConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSHTMLDirectoryElementConstructor, JSDOMWrapper>( exec, &JSHTMLDirectoryElementConstructorTable,
            this, propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLDirectoryElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLDirectoryElementPrototypeTable = { 1, 0, JSHTMLDirectoryElementPrototypeTableValues, 0 };
const ClassInfo JSHTMLDirectoryElementPrototype::s_info = { "HTMLDirectoryElementPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSHTMLDirectoryElementPrototypeTable, 0 };

JSObject *JSHTMLDirectoryElementPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSHTMLDirectoryElement>( exec, globalObject );
}

const ClassInfo JSHTMLDirectoryElement::s_info = { "HTMLDirectoryElement", &JSHTMLElement::s_info, &JSHTMLDirectoryElementTable, 0 };

JSHTMLDirectoryElement::JSHTMLDirectoryElement( Structure *structure, JSDOMGlobalObject *globalObject,
        PassRefPtr<HTMLDirectoryElement> impl )
    : JSHTMLElement( structure, globalObject, impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSHTMLDirectoryElement::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSHTMLDirectoryElementPrototype( exec->globalData(), globalObject,
            JSHTMLDirectoryElementPrototype::createStructure( exec->globalData(), JSHTMLElementPrototype::self( exec, globalObject ) ) );
}

bool JSHTMLDirectoryElement::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSHTMLDirectoryElement, Base>( exec, &JSHTMLDirectoryElementTable, this, propertyName, slot );
}

bool JSHTMLDirectoryElement::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSHTMLDirectoryElement, Base>( exec, &JSHTMLDirectoryElementTable, this, propertyName,
            descriptor );
}

JSValue jsHTMLDirectoryElementCompact( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLDirectoryElement *castedThis = static_cast<JSHTMLDirectoryElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLDirectoryElement *imp = static_cast<HTMLDirectoryElement *>( castedThis->impl() );
    JSValue result = jsBoolean( imp->hasAttribute( WebCore::HTMLNames::compactAttr ) );
    return result;
}


JSValue jsHTMLDirectoryElementConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLDirectoryElement *domObject = static_cast<JSHTMLDirectoryElement *>( asObject( slotBase ) );
    return JSHTMLDirectoryElement::getConstructor( exec, domObject->globalObject() );
}

void JSHTMLDirectoryElement::put( ExecState *exec, const Identifier &propertyName, JSValue value, PutPropertySlot &slot )
{
    lookupPut<JSHTMLDirectoryElement, Base>( exec, propertyName, value, &JSHTMLDirectoryElementTable, this, slot );
}

void setJSHTMLDirectoryElementCompact( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLDirectoryElement *castedThis = static_cast<JSHTMLDirectoryElement *>( thisObject );
    HTMLDirectoryElement *imp = static_cast<HTMLDirectoryElement *>( castedThis->impl() );
    imp->setBooleanAttribute( WebCore::HTMLNames::compactAttr, value.toBoolean( exec ) );
}


JSValue JSHTMLDirectoryElement::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSHTMLDirectoryElementConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}


}
