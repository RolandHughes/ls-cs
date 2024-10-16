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

#if ENABLE(WEBGL)

#include "JSWebGLShader.h"

#include "WebGLShader.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSWebGLShader );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSWebGLShaderTableValues[2] =
{
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsWebGLShaderConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSWebGLShaderTable = { 2, 1, JSWebGLShaderTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSWebGLShaderConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSWebGLShaderConstructorTable = { 1, 0, JSWebGLShaderConstructorTableValues, 0 };
class JSWebGLShaderConstructor : public DOMConstructorObject
{
public:
    JSWebGLShaderConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSWebGLShaderConstructor::s_info = { "WebGLShaderConstructor", &DOMConstructorObject::s_info, &JSWebGLShaderConstructorTable, 0 };

JSWebGLShaderConstructor::JSWebGLShaderConstructor( ExecState *exec, Structure *structure, JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSWebGLShaderPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSWebGLShaderConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSWebGLShaderConstructor, JSDOMWrapper>( exec, &JSWebGLShaderConstructorTable, this, propertyName,
            slot );
}

bool JSWebGLShaderConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSWebGLShaderConstructor, JSDOMWrapper>( exec, &JSWebGLShaderConstructorTable, this, propertyName,
            descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSWebGLShaderPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSWebGLShaderPrototypeTable = { 1, 0, JSWebGLShaderPrototypeTableValues, 0 };
const ClassInfo JSWebGLShaderPrototype::s_info = { "WebGLShaderPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSWebGLShaderPrototypeTable, 0 };

JSObject *JSWebGLShaderPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSWebGLShader>( exec, globalObject );
}

const ClassInfo JSWebGLShader::s_info = { "WebGLShader", &JSDOMWrapper::s_info, &JSWebGLShaderTable, 0 };

JSWebGLShader::JSWebGLShader( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<WebGLShader> impl )
    : JSDOMWrapper( structure, globalObject )
    , m_impl( impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSWebGLShader::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSWebGLShaderPrototype( exec->globalData(), globalObject,
            JSWebGLShaderPrototype::createStructure( globalObject->globalData(), globalObject->objectPrototype() ) );
}

bool JSWebGLShader::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSWebGLShader, Base>( exec, &JSWebGLShaderTable, this, propertyName, slot );
}

bool JSWebGLShader::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName, PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSWebGLShader, Base>( exec, &JSWebGLShaderTable, this, propertyName, descriptor );
}

JSValue jsWebGLShaderConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSWebGLShader *domObject = static_cast<JSWebGLShader *>( asObject( slotBase ) );
    return JSWebGLShader::getConstructor( exec, domObject->globalObject() );
}

JSValue JSWebGLShader::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSWebGLShaderConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}

JSC::JSValue toJS( JSC::ExecState *exec, JSDOMGlobalObject *globalObject, WebGLShader *impl )
{
    return wrap<JSWebGLShader>( exec, globalObject, impl );
}

WebGLShader *toWebGLShader( JSC::JSValue value )
{
    return value.inherits( &JSWebGLShader::s_info ) ? static_cast<JSWebGLShader *>( asObject( value ) )->impl() : 0;
}

}

#endif // ENABLE(WEBGL)
