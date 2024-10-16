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

#if ENABLE(XPATH)

#include "JSXPathExpression.h"

#include "ExceptionCode.h"
#include "JSDOMBinding.h"
#include "JSNode.h"
#include "JSXPathResult.h"
#include "XPathExpression.h"
#include "XPathResult.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSXPathExpression );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSXPathExpressionTableValues[2] =
{
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsXPathExpressionConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSXPathExpressionTable = { 2, 1, JSXPathExpressionTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSXPathExpressionConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSXPathExpressionConstructorTable = { 1, 0, JSXPathExpressionConstructorTableValues, 0 };
class JSXPathExpressionConstructor : public DOMConstructorObject
{
public:
    JSXPathExpressionConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSXPathExpressionConstructor::s_info = { "XPathExpressionConstructor", &DOMConstructorObject::s_info, &JSXPathExpressionConstructorTable, 0 };

JSXPathExpressionConstructor::JSXPathExpressionConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSXPathExpressionPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSXPathExpressionConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSXPathExpressionConstructor, JSDOMWrapper>( exec, &JSXPathExpressionConstructorTable, this,
            propertyName, slot );
}

bool JSXPathExpressionConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSXPathExpressionConstructor, JSDOMWrapper>( exec, &JSXPathExpressionConstructorTable, this,
            propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSXPathExpressionPrototypeTableValues[2] =
{
    { "evaluate", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsXPathExpressionPrototypeFunctionEvaluate ), ( intptr_t )3 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSXPathExpressionPrototypeTable = { 2, 1, JSXPathExpressionPrototypeTableValues, 0 };
const ClassInfo JSXPathExpressionPrototype::s_info = { "XPathExpressionPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSXPathExpressionPrototypeTable, 0 };

JSObject *JSXPathExpressionPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSXPathExpression>( exec, globalObject );
}

bool JSXPathExpressionPrototype::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticFunctionSlot<JSObject>( exec, &JSXPathExpressionPrototypeTable, this, propertyName, slot );
}

bool JSXPathExpressionPrototype::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticFunctionDescriptor<JSObject>( exec, &JSXPathExpressionPrototypeTable, this, propertyName, descriptor );
}

const ClassInfo JSXPathExpression::s_info = { "XPathExpression", &JSDOMWrapper::s_info, &JSXPathExpressionTable, 0 };

JSXPathExpression::JSXPathExpression( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<XPathExpression> impl )
    : JSDOMWrapper( structure, globalObject )
    , m_impl( impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSXPathExpression::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSXPathExpressionPrototype( exec->globalData(), globalObject,
            JSXPathExpressionPrototype::createStructure( globalObject->globalData(), globalObject->objectPrototype() ) );
}

bool JSXPathExpression::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSXPathExpression, Base>( exec, &JSXPathExpressionTable, this, propertyName, slot );
}

bool JSXPathExpression::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSXPathExpression, Base>( exec, &JSXPathExpressionTable, this, propertyName, descriptor );
}

JSValue jsXPathExpressionConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSXPathExpression *domObject = static_cast<JSXPathExpression *>( asObject( slotBase ) );
    return JSXPathExpression::getConstructor( exec, domObject->globalObject() );
}

JSValue JSXPathExpression::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSXPathExpressionConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}

EncodedJSValue JSC_HOST_CALL jsXPathExpressionPrototypeFunctionEvaluate( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSXPathExpression::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSXPathExpression *castedThis = static_cast<JSXPathExpression *>( asObject( thisValue ) );
    XPathExpression *imp = static_cast<XPathExpression *>( castedThis->impl() );
    ExceptionCode ec = 0;
    Node *contextNode( toNode( exec->argument( 0 ) ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }

    unsigned short type( exec->argument( 1 ).toUInt32( exec ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }

    XPathResult *inResult( toXPathResult( exec->argument( 2 ) ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }


    JSC::JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->evaluate( contextNode, type, inResult, ec ) ) );
    setDOMException( exec, ec );
    return JSValue::encode( result );
}

JSC::JSValue toJS( JSC::ExecState *exec, JSDOMGlobalObject *globalObject, XPathExpression *impl )
{
    return wrap<JSXPathExpression>( exec, globalObject, impl );
}

XPathExpression *toXPathExpression( JSC::JSValue value )
{
    return value.inherits( &JSXPathExpression::s_info ) ? static_cast<JSXPathExpression *>( asObject( value ) )->impl() : 0;
}

}

#endif // ENABLE(XPATH)
