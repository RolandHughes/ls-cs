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
#include "JSHTMLOListElement.h"

#include "HTMLNames.h"
#include "HTMLOListElement.h"
#include "KURL.h"
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSHTMLOListElement );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLOListElementTableValues[5] =
{
    { "compact", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLOListElementCompact ), ( intptr_t )setJSHTMLOListElementCompact THUNK_GENERATOR( 0 ) },
    { "start", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLOListElementStart ), ( intptr_t )setJSHTMLOListElementStart THUNK_GENERATOR( 0 ) },
    { "type", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLOListElementType ), ( intptr_t )setJSHTMLOListElementType THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLOListElementConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLOListElementTable = { 8, 7, JSHTMLOListElementTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLOListElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLOListElementConstructorTable = { 1, 0, JSHTMLOListElementConstructorTableValues, 0 };
class JSHTMLOListElementConstructor : public DOMConstructorObject
{
public:
    JSHTMLOListElementConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSHTMLOListElementConstructor::s_info = { "HTMLOListElementConstructor", &DOMConstructorObject::s_info, &JSHTMLOListElementConstructorTable, 0 };

JSHTMLOListElementConstructor::JSHTMLOListElementConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSHTMLOListElementPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSHTMLOListElementConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSHTMLOListElementConstructor, JSDOMWrapper>( exec, &JSHTMLOListElementConstructorTable, this,
            propertyName, slot );
}

bool JSHTMLOListElementConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSHTMLOListElementConstructor, JSDOMWrapper>( exec, &JSHTMLOListElementConstructorTable, this,
            propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLOListElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLOListElementPrototypeTable = { 1, 0, JSHTMLOListElementPrototypeTableValues, 0 };
const ClassInfo JSHTMLOListElementPrototype::s_info = { "HTMLOListElementPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSHTMLOListElementPrototypeTable, 0 };

JSObject *JSHTMLOListElementPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSHTMLOListElement>( exec, globalObject );
}

const ClassInfo JSHTMLOListElement::s_info = { "HTMLOListElement", &JSHTMLElement::s_info, &JSHTMLOListElementTable, 0 };

JSHTMLOListElement::JSHTMLOListElement( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<HTMLOListElement> impl )
    : JSHTMLElement( structure, globalObject, impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSHTMLOListElement::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSHTMLOListElementPrototype( exec->globalData(), globalObject,
            JSHTMLOListElementPrototype::createStructure( exec->globalData(), JSHTMLElementPrototype::self( exec, globalObject ) ) );
}

bool JSHTMLOListElement::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSHTMLOListElement, Base>( exec, &JSHTMLOListElementTable, this, propertyName, slot );
}

bool JSHTMLOListElement::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSHTMLOListElement, Base>( exec, &JSHTMLOListElementTable, this, propertyName, descriptor );
}

JSValue jsHTMLOListElementCompact( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLOListElement *castedThis = static_cast<JSHTMLOListElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLOListElement *imp = static_cast<HTMLOListElement *>( castedThis->impl() );
    JSValue result = jsBoolean( imp->hasAttribute( WebCore::HTMLNames::compactAttr ) );
    return result;
}


JSValue jsHTMLOListElementStart( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLOListElement *castedThis = static_cast<JSHTMLOListElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLOListElement *imp = static_cast<HTMLOListElement *>( castedThis->impl() );
    JSValue result = jsNumber( imp->start() );
    return result;
}


JSValue jsHTMLOListElementType( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLOListElement *castedThis = static_cast<JSHTMLOListElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLOListElement *imp = static_cast<HTMLOListElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::typeAttr ) );
    return result;
}


JSValue jsHTMLOListElementConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLOListElement *domObject = static_cast<JSHTMLOListElement *>( asObject( slotBase ) );
    return JSHTMLOListElement::getConstructor( exec, domObject->globalObject() );
}

void JSHTMLOListElement::put( ExecState *exec, const Identifier &propertyName, JSValue value, PutPropertySlot &slot )
{
    lookupPut<JSHTMLOListElement, Base>( exec, propertyName, value, &JSHTMLOListElementTable, this, slot );
}

void setJSHTMLOListElementCompact( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLOListElement *castedThis = static_cast<JSHTMLOListElement *>( thisObject );
    HTMLOListElement *imp = static_cast<HTMLOListElement *>( castedThis->impl() );
    imp->setBooleanAttribute( WebCore::HTMLNames::compactAttr, value.toBoolean( exec ) );
}


void setJSHTMLOListElementStart( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLOListElement *castedThis = static_cast<JSHTMLOListElement *>( thisObject );
    HTMLOListElement *imp = static_cast<HTMLOListElement *>( castedThis->impl() );
    imp->setStart( value.toInt32( exec ) );
}


void setJSHTMLOListElementType( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLOListElement *castedThis = static_cast<JSHTMLOListElement *>( thisObject );
    HTMLOListElement *imp = static_cast<HTMLOListElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::typeAttr, valueToStringWithNullCheck( exec, value ) );
}


JSValue JSHTMLOListElement::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSHTMLOListElementConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}


}
