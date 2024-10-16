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
#include "JSCrypto.h"

#include "Crypto.h"
#include "ExceptionCode.h"
#include "JSArrayBufferView.h"
#include "JSDOMBinding.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSCrypto );

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSCryptoPrototypeTableValues[2] =
{
    { "getRandomValues", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsCryptoPrototypeFunctionGetRandomValues ), ( intptr_t )1 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSCryptoPrototypeTable = { 2, 1, JSCryptoPrototypeTableValues, 0 };
const ClassInfo JSCryptoPrototype::s_info = { "CryptoPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSCryptoPrototypeTable, 0 };

JSObject *JSCryptoPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSCrypto>( exec, globalObject );
}

bool JSCryptoPrototype::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticFunctionSlot<JSObject>( exec, &JSCryptoPrototypeTable, this, propertyName, slot );
}

bool JSCryptoPrototype::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticFunctionDescriptor<JSObject>( exec, &JSCryptoPrototypeTable, this, propertyName, descriptor );
}

const ClassInfo JSCrypto::s_info = { "Crypto", &JSDOMWrapper::s_info, 0, 0 };

JSCrypto::JSCrypto( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<Crypto> impl )
    : JSDOMWrapper( structure, globalObject )
    , m_impl( impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSCrypto::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSCryptoPrototype( exec->globalData(), globalObject,
                                           JSCryptoPrototype::createStructure( globalObject->globalData(), globalObject->objectPrototype() ) );
}

EncodedJSValue JSC_HOST_CALL jsCryptoPrototypeFunctionGetRandomValues( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSCrypto::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSCrypto *castedThis = static_cast<JSCrypto *>( asObject( thisValue ) );
    Crypto *imp = static_cast<Crypto *>( castedThis->impl() );
    ExceptionCode ec = 0;
    ArrayBufferView *array( toArrayBufferView( exec->argument( 0 ) ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }

    imp->getRandomValues( array, ec );
    setDOMException( exec, ec );
    return JSValue::encode( jsUndefined() );
}

JSC::JSValue toJS( JSC::ExecState *exec, JSDOMGlobalObject *globalObject, Crypto *impl )
{
    return wrap<JSCrypto>( exec, globalObject, impl );
}

Crypto *toCrypto( JSC::JSValue value )
{
    return value.inherits( &JSCrypto::s_info ) ? static_cast<JSCrypto *>( asObject( value ) )->impl() : 0;
}

}
