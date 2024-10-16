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
#include "JSHTMLLegendElement.h"

#include "HTMLFormElement.h"
#include "HTMLLegendElement.h"
#include "HTMLNames.h"
#include "JSHTMLFormElement.h"
#include "KURL.h"
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSHTMLLegendElement );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLLegendElementTableValues[5] =
{
    { "form", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLLegendElementForm ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "accessKey", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLLegendElementAccessKey ), ( intptr_t )setJSHTMLLegendElementAccessKey THUNK_GENERATOR( 0 ) },
    { "align", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLLegendElementAlign ), ( intptr_t )setJSHTMLLegendElementAlign THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLLegendElementConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLLegendElementTable = { 9, 7, JSHTMLLegendElementTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLLegendElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLLegendElementConstructorTable = { 1, 0, JSHTMLLegendElementConstructorTableValues, 0 };
class JSHTMLLegendElementConstructor : public DOMConstructorObject
{
public:
    JSHTMLLegendElementConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSHTMLLegendElementConstructor::s_info = { "HTMLLegendElementConstructor", &DOMConstructorObject::s_info, &JSHTMLLegendElementConstructorTable, 0 };

JSHTMLLegendElementConstructor::JSHTMLLegendElementConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSHTMLLegendElementPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSHTMLLegendElementConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSHTMLLegendElementConstructor, JSDOMWrapper>( exec, &JSHTMLLegendElementConstructorTable, this,
            propertyName, slot );
}

bool JSHTMLLegendElementConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSHTMLLegendElementConstructor, JSDOMWrapper>( exec, &JSHTMLLegendElementConstructorTable, this,
            propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLLegendElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLLegendElementPrototypeTable = { 1, 0, JSHTMLLegendElementPrototypeTableValues, 0 };
const ClassInfo JSHTMLLegendElementPrototype::s_info = { "HTMLLegendElementPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSHTMLLegendElementPrototypeTable, 0 };

JSObject *JSHTMLLegendElementPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSHTMLLegendElement>( exec, globalObject );
}

const ClassInfo JSHTMLLegendElement::s_info = { "HTMLLegendElement", &JSHTMLElement::s_info, &JSHTMLLegendElementTable, 0 };

JSHTMLLegendElement::JSHTMLLegendElement( Structure *structure, JSDOMGlobalObject *globalObject,
        PassRefPtr<HTMLLegendElement> impl )
    : JSHTMLElement( structure, globalObject, impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSHTMLLegendElement::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSHTMLLegendElementPrototype( exec->globalData(), globalObject,
            JSHTMLLegendElementPrototype::createStructure( exec->globalData(), JSHTMLElementPrototype::self( exec, globalObject ) ) );
}

bool JSHTMLLegendElement::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSHTMLLegendElement, Base>( exec, &JSHTMLLegendElementTable, this, propertyName, slot );
}

bool JSHTMLLegendElement::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSHTMLLegendElement, Base>( exec, &JSHTMLLegendElementTable, this, propertyName, descriptor );
}

JSValue jsHTMLLegendElementForm( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLLegendElement *castedThis = static_cast<JSHTMLLegendElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLLegendElement *imp = static_cast<HTMLLegendElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->form() ) );
    return result;
}


JSValue jsHTMLLegendElementAccessKey( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLLegendElement *castedThis = static_cast<JSHTMLLegendElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLLegendElement *imp = static_cast<HTMLLegendElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::accesskeyAttr ) );
    return result;
}


JSValue jsHTMLLegendElementAlign( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLLegendElement *castedThis = static_cast<JSHTMLLegendElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLLegendElement *imp = static_cast<HTMLLegendElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::alignAttr ) );
    return result;
}


JSValue jsHTMLLegendElementConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLLegendElement *domObject = static_cast<JSHTMLLegendElement *>( asObject( slotBase ) );
    return JSHTMLLegendElement::getConstructor( exec, domObject->globalObject() );
}

void JSHTMLLegendElement::put( ExecState *exec, const Identifier &propertyName, JSValue value, PutPropertySlot &slot )
{
    lookupPut<JSHTMLLegendElement, Base>( exec, propertyName, value, &JSHTMLLegendElementTable, this, slot );
}

void setJSHTMLLegendElementAccessKey( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLLegendElement *castedThis = static_cast<JSHTMLLegendElement *>( thisObject );
    HTMLLegendElement *imp = static_cast<HTMLLegendElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::accesskeyAttr, valueToStringWithNullCheck( exec, value ) );
}


void setJSHTMLLegendElementAlign( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLLegendElement *castedThis = static_cast<JSHTMLLegendElement *>( thisObject );
    HTMLLegendElement *imp = static_cast<HTMLLegendElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::alignAttr, valueToStringWithNullCheck( exec, value ) );
}


JSValue JSHTMLLegendElement::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSHTMLLegendElementConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}


}
