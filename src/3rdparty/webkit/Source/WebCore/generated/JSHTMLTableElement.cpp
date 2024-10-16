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
#include "JSHTMLTableElement.h"

#include "ExceptionCode.h"
#include "HTMLCollection.h"
#include "HTMLElement.h"
#include "HTMLNames.h"
#include "HTMLTableCaptionElement.h"
#include "HTMLTableElement.h"
#include "HTMLTableSectionElement.h"
#include "JSDOMBinding.h"
#include "JSHTMLCollection.h"
#include "JSHTMLElement.h"
#include "JSHTMLTableCaptionElement.h"
#include "JSHTMLTableSectionElement.h"
#include "KURL.h"
#include <runtime/Error.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSHTMLTableElement );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLTableElementTableValues[16] =
{
    { "caption", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementCaption ), ( intptr_t )setJSHTMLTableElementCaption THUNK_GENERATOR( 0 ) },
    { "tHead", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementTHead ), ( intptr_t )setJSHTMLTableElementTHead THUNK_GENERATOR( 0 ) },
    { "tFoot", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementTFoot ), ( intptr_t )setJSHTMLTableElementTFoot THUNK_GENERATOR( 0 ) },
    { "rows", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementRows ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "tBodies", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementTBodies ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "align", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementAlign ), ( intptr_t )setJSHTMLTableElementAlign THUNK_GENERATOR( 0 ) },
    { "bgColor", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementBgColor ), ( intptr_t )setJSHTMLTableElementBgColor THUNK_GENERATOR( 0 ) },
    { "border", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementBorder ), ( intptr_t )setJSHTMLTableElementBorder THUNK_GENERATOR( 0 ) },
    { "cellPadding", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementCellPadding ), ( intptr_t )setJSHTMLTableElementCellPadding THUNK_GENERATOR( 0 ) },
    { "cellSpacing", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementCellSpacing ), ( intptr_t )setJSHTMLTableElementCellSpacing THUNK_GENERATOR( 0 ) },
    { "frame", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementFrame ), ( intptr_t )setJSHTMLTableElementFrame THUNK_GENERATOR( 0 ) },
    { "rules", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementRules ), ( intptr_t )setJSHTMLTableElementRules THUNK_GENERATOR( 0 ) },
    { "summary", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementSummary ), ( intptr_t )setJSHTMLTableElementSummary THUNK_GENERATOR( 0 ) },
    { "width", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementWidth ), ( intptr_t )setJSHTMLTableElementWidth THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsHTMLTableElementConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLTableElementTable = { 35, 31, JSHTMLTableElementTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLTableElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLTableElementConstructorTable = { 1, 0, JSHTMLTableElementConstructorTableValues, 0 };
class JSHTMLTableElementConstructor : public DOMConstructorObject
{
public:
    JSHTMLTableElementConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSHTMLTableElementConstructor::s_info = { "HTMLTableElementConstructor", &DOMConstructorObject::s_info, &JSHTMLTableElementConstructorTable, 0 };

JSHTMLTableElementConstructor::JSHTMLTableElementConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSHTMLTableElementPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSHTMLTableElementConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSHTMLTableElementConstructor, JSDOMWrapper>( exec, &JSHTMLTableElementConstructorTable, this,
            propertyName, slot );
}

bool JSHTMLTableElementConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSHTMLTableElementConstructor, JSDOMWrapper>( exec, &JSHTMLTableElementConstructorTable, this,
            propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLTableElementPrototypeTableValues[9] =
{
    { "createTHead", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsHTMLTableElementPrototypeFunctionCreateTHead ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "deleteTHead", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsHTMLTableElementPrototypeFunctionDeleteTHead ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "createTFoot", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsHTMLTableElementPrototypeFunctionCreateTFoot ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "deleteTFoot", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsHTMLTableElementPrototypeFunctionDeleteTFoot ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "createCaption", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsHTMLTableElementPrototypeFunctionCreateCaption ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "deleteCaption", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsHTMLTableElementPrototypeFunctionDeleteCaption ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "insertRow", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsHTMLTableElementPrototypeFunctionInsertRow ), ( intptr_t )1 THUNK_GENERATOR( 0 ) },
    { "deleteRow", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsHTMLTableElementPrototypeFunctionDeleteRow ), ( intptr_t )1 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLTableElementPrototypeTable = { 19, 15, JSHTMLTableElementPrototypeTableValues, 0 };
const ClassInfo JSHTMLTableElementPrototype::s_info = { "HTMLTableElementPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSHTMLTableElementPrototypeTable, 0 };

JSObject *JSHTMLTableElementPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSHTMLTableElement>( exec, globalObject );
}

bool JSHTMLTableElementPrototype::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticFunctionSlot<JSObject>( exec, &JSHTMLTableElementPrototypeTable, this, propertyName, slot );
}

bool JSHTMLTableElementPrototype::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticFunctionDescriptor<JSObject>( exec, &JSHTMLTableElementPrototypeTable, this, propertyName, descriptor );
}

const ClassInfo JSHTMLTableElement::s_info = { "HTMLTableElement", &JSHTMLElement::s_info, &JSHTMLTableElementTable, 0 };

JSHTMLTableElement::JSHTMLTableElement( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<HTMLTableElement> impl )
    : JSHTMLElement( structure, globalObject, impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSHTMLTableElement::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSHTMLTableElementPrototype( exec->globalData(), globalObject,
            JSHTMLTableElementPrototype::createStructure( exec->globalData(), JSHTMLElementPrototype::self( exec, globalObject ) ) );
}

bool JSHTMLTableElement::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSHTMLTableElement, Base>( exec, &JSHTMLTableElementTable, this, propertyName, slot );
}

bool JSHTMLTableElement::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSHTMLTableElement, Base>( exec, &JSHTMLTableElementTable, this, propertyName, descriptor );
}

JSValue jsHTMLTableElementCaption( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->caption() ) );
    return result;
}


JSValue jsHTMLTableElementTHead( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->tHead() ) );
    return result;
}


JSValue jsHTMLTableElementTFoot( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->tFoot() ) );
    return result;
}


JSValue jsHTMLTableElementRows( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->rows() ) );
    return result;
}


JSValue jsHTMLTableElementTBodies( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->tBodies() ) );
    return result;
}


JSValue jsHTMLTableElementAlign( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::alignAttr ) );
    return result;
}


JSValue jsHTMLTableElementBgColor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::bgcolorAttr ) );
    return result;
}


JSValue jsHTMLTableElementBorder( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::borderAttr ) );
    return result;
}


JSValue jsHTMLTableElementCellPadding( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::cellpaddingAttr ) );
    return result;
}


JSValue jsHTMLTableElementCellSpacing( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::cellspacingAttr ) );
    return result;
}


JSValue jsHTMLTableElementFrame( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::frameAttr ) );
    return result;
}


JSValue jsHTMLTableElementRules( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::rulesAttr ) );
    return result;
}


JSValue jsHTMLTableElementSummary( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::summaryAttr ) );
    return result;
}


JSValue jsHTMLTableElementWidth( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->getAttribute( WebCore::HTMLNames::widthAttr ) );
    return result;
}


JSValue jsHTMLTableElementConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSHTMLTableElement *domObject = static_cast<JSHTMLTableElement *>( asObject( slotBase ) );
    return JSHTMLTableElement::getConstructor( exec, domObject->globalObject() );
}

void JSHTMLTableElement::put( ExecState *exec, const Identifier &propertyName, JSValue value, PutPropertySlot &slot )
{
    lookupPut<JSHTMLTableElement, Base>( exec, propertyName, value, &JSHTMLTableElementTable, this, slot );
}

void setJSHTMLTableElementCaption( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( thisObject );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    ExceptionCode ec = 0;
    imp->setCaption( toHTMLTableCaptionElement( value ), ec );
    setDOMException( exec, ec );
}


void setJSHTMLTableElementTHead( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( thisObject );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    ExceptionCode ec = 0;
    imp->setTHead( toHTMLTableSectionElement( value ), ec );
    setDOMException( exec, ec );
}


void setJSHTMLTableElementTFoot( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( thisObject );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    ExceptionCode ec = 0;
    imp->setTFoot( toHTMLTableSectionElement( value ), ec );
    setDOMException( exec, ec );
}


void setJSHTMLTableElementAlign( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( thisObject );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::alignAttr, valueToStringWithNullCheck( exec, value ) );
}


void setJSHTMLTableElementBgColor( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( thisObject );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::bgcolorAttr, valueToStringWithNullCheck( exec, value ) );
}


void setJSHTMLTableElementBorder( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( thisObject );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::borderAttr, valueToStringWithNullCheck( exec, value ) );
}


void setJSHTMLTableElementCellPadding( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( thisObject );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::cellpaddingAttr, valueToStringWithNullCheck( exec, value ) );
}


void setJSHTMLTableElementCellSpacing( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( thisObject );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::cellspacingAttr, valueToStringWithNullCheck( exec, value ) );
}


void setJSHTMLTableElementFrame( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( thisObject );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::frameAttr, valueToStringWithNullCheck( exec, value ) );
}


void setJSHTMLTableElementRules( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( thisObject );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::rulesAttr, valueToStringWithNullCheck( exec, value ) );
}


void setJSHTMLTableElementSummary( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( thisObject );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::summaryAttr, valueToStringWithNullCheck( exec, value ) );
}


void setJSHTMLTableElementWidth( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( thisObject );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    imp->setAttribute( WebCore::HTMLNames::widthAttr, valueToStringWithNullCheck( exec, value ) );
}


JSValue JSHTMLTableElement::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSHTMLTableElementConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}

EncodedJSValue JSC_HOST_CALL jsHTMLTableElementPrototypeFunctionCreateTHead( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSHTMLTableElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( thisValue ) );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );


    JSC::JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->createTHead() ) );
    return JSValue::encode( result );
}

EncodedJSValue JSC_HOST_CALL jsHTMLTableElementPrototypeFunctionDeleteTHead( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSHTMLTableElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( thisValue ) );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );

    imp->deleteTHead();
    return JSValue::encode( jsUndefined() );
}

EncodedJSValue JSC_HOST_CALL jsHTMLTableElementPrototypeFunctionCreateTFoot( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSHTMLTableElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( thisValue ) );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );


    JSC::JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->createTFoot() ) );
    return JSValue::encode( result );
}

EncodedJSValue JSC_HOST_CALL jsHTMLTableElementPrototypeFunctionDeleteTFoot( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSHTMLTableElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( thisValue ) );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );

    imp->deleteTFoot();
    return JSValue::encode( jsUndefined() );
}

EncodedJSValue JSC_HOST_CALL jsHTMLTableElementPrototypeFunctionCreateCaption( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSHTMLTableElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( thisValue ) );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );


    JSC::JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->createCaption() ) );
    return JSValue::encode( result );
}

EncodedJSValue JSC_HOST_CALL jsHTMLTableElementPrototypeFunctionDeleteCaption( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSHTMLTableElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( thisValue ) );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );

    imp->deleteCaption();
    return JSValue::encode( jsUndefined() );
}

EncodedJSValue JSC_HOST_CALL jsHTMLTableElementPrototypeFunctionInsertRow( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSHTMLTableElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( thisValue ) );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    ExceptionCode ec = 0;
    int index( exec->argument( 0 ).toInt32( exec ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }


    JSC::JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->insertRow( index, ec ) ) );
    setDOMException( exec, ec );
    return JSValue::encode( result );
}

EncodedJSValue JSC_HOST_CALL jsHTMLTableElementPrototypeFunctionDeleteRow( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSHTMLTableElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSHTMLTableElement *castedThis = static_cast<JSHTMLTableElement *>( asObject( thisValue ) );
    HTMLTableElement *imp = static_cast<HTMLTableElement *>( castedThis->impl() );
    ExceptionCode ec = 0;
    int index( exec->argument( 0 ).toInt32( exec ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }

    imp->deleteRow( index, ec );
    setDOMException( exec, ec );
    return JSValue::encode( jsUndefined() );
}


}
