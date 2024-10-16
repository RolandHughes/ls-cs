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
#include "JSHTMLParamElement.h"

#include "HTMLNames.h"
#include "HTMLParamElement.h"
#include "KURL.h"
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSHTMLParamElement );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLParamElementTableValues[6] =
{
    { "name", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLParamElementName ), ( intptr_t )setJSHTMLParamElementName THUNK_GENERATOR( 0 ) },
    { "type", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLParamElementType ), ( intptr_t )setJSHTMLParamElementType THUNK_GENERATOR( 0 ) },
    { "value", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLParamElementValue ), ( intptr_t )setJSHTMLParamElementValue THUNK_GENERATOR( 0 ) },
    { "valueType", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLParamElementValueType ), ( intptr_t )setJSHTMLParamElementValueType THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLParamElementConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLParamElementTable = { 18, 15, JSHTMLParamElementTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLParamElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLParamElementConstructorTable = { 1, 0, JSHTMLParamElementConstructorTableValues, 0 };
class JSHTMLParamElementConstructor : public DOMConstructorObject
{
public:
    JSHTMLParamElementConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSHTMLParamElementConstructor::s_info = { "HTMLParamElementConstructor", &DOMConstructorObject::s_info, &JSHTMLParamElementConstructorTable, 0 };

JSHTMLParamElementConstructor::JSHTMLParamElementConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSHTMLParamElementPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSHTMLParamElementConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSHTMLParamElementConstructor, JSDOMWrapper>( exec, &JSHTMLParamElementConstructorTable, this,
            propertyName, slot );
}

bool JSHTMLParamElementConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSHTMLParamElementConstructor, JSDOMWrapper>( exec, &JSHTMLParamElementConstructorTable, this,
            propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLParamElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLParamElementPrototypeTable = { 1, 0, JSHTMLParamElementPrototypeTableValues, 0 };
const ClassInfo JSHTMLParamElementPrototype::s_info = { "HTMLParamElementPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSHTMLParamElementPrototypeTable, 0 };

JSObject *JSHTMLParamElementPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSHTMLParamElement>( exec, globalObject );
}

const ClassInfo JSHTMLParamElement::s_info = { "HTMLParamElement", &JSHTMLElement::s_info, &JSHTMLParamElementTable, 0 };

JSHTMLParamElement::JSHTMLParamElement( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<HTMLParamElement> impl )
    : JSHTMLElement( structure, globalObject, impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSHTMLParamElement::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSHTMLParamElementPrototype( exec->globalData(), globalObject,
            JSHTMLParamElementPrototype::createStructure( exec->globalData(), JSHTMLElementPrototype::self( exec, globalObject ) ) );
}

bool JSHTMLParamElement::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSHTMLParamElement, Base>( exec, &JSHTMLParamElementTable, this, propertyName, slot );
}

bool JSHTMLParamElement::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSHTMLParamElement, Base>( exec, &JSHTMLParamElementTable, this, propertyName, descriptor );
}

JSValue jsHTMLParamElementName( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLParamElement *castedThis = static_cast<JSHTMLParamElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLParamElement *imp = static_cast<HTMLParamElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::nameAttr ) );
    return result;
}


JSValue jsHTMLParamElementType( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLParamElement *castedThis = static_cast<JSHTMLParamElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLParamElement *imp = static_cast<HTMLParamElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::typeAttr ) );
    return result;
}


JSValue jsHTMLParamElementValue( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLParamElement *castedThis = static_cast<JSHTMLParamElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLParamElement *imp = static_cast<HTMLParamElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::valueAttr ) );
    return result;
}


JSValue jsHTMLParamElementValueType( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLParamElement *castedThis = static_cast<JSHTMLParamElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLParamElement *imp = static_cast<HTMLParamElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::valuetypeAttr ) );
    return result;
}


JSValue jsHTMLParamElementConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLParamElement *domObject = static_cast<JSHTMLParamElement *>( asObject( slotBase ) );
    return JSHTMLParamElement::getConstructor( exec, domObject->globalObject() );
}

void JSHTMLParamElement::put( ExecState *exec, const Identifier &propertyName, JSValue value, PutPropertySlot &slot )
{
    lookupPut<JSHTMLParamElement, Base>( exec, propertyName, value, &JSHTMLParamElementTable, this, slot );
}

void setJSHTMLParamElementName( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLParamElement *castedThis = static_cast<JSHTMLParamElement *>( thisObject );
    HTMLParamElement *imp = static_cast<HTMLParamElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::nameAttr, valueToStringWithNullCheck( exec, value ) );
}


void setJSHTMLParamElementType( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLParamElement *castedThis = static_cast<JSHTMLParamElement *>( thisObject );
    HTMLParamElement *imp = static_cast<HTMLParamElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::typeAttr, valueToStringWithNullCheck( exec, value ) );
}


void setJSHTMLParamElementValue( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLParamElement *castedThis = static_cast<JSHTMLParamElement *>( thisObject );
    HTMLParamElement *imp = static_cast<HTMLParamElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::valueAttr, valueToStringWithNullCheck( exec, value ) );
}


void setJSHTMLParamElementValueType( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLParamElement *castedThis = static_cast<JSHTMLParamElement *>( thisObject );
    HTMLParamElement *imp = static_cast<HTMLParamElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::valuetypeAttr, valueToStringWithNullCheck( exec, value ) );
}


JSValue JSHTMLParamElement::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSHTMLParamElementConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}


}
