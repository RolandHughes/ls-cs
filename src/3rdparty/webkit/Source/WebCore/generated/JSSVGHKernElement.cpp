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

#if ENABLE(SVG) && ENABLE(SVG_FONTS)

#include "JSSVGHKernElement.h"

#include "SVGHKernElement.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSSVGHKernElement );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGHKernElementTableValues[2] =
{
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGHKernElementConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGHKernElementTable = { 2, 1, JSSVGHKernElementTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGHKernElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGHKernElementConstructorTable = { 1, 0, JSSVGHKernElementConstructorTableValues, 0 };
class JSSVGHKernElementConstructor : public DOMConstructorObject
{
public:
    JSSVGHKernElementConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSSVGHKernElementConstructor::s_info = { "SVGHKernElementConstructor", &DOMConstructorObject::s_info, &JSSVGHKernElementConstructorTable, 0 };

JSSVGHKernElementConstructor::JSSVGHKernElementConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSSVGHKernElementPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSSVGHKernElementConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSSVGHKernElementConstructor, JSDOMWrapper>( exec, &JSSVGHKernElementConstructorTable, this,
            propertyName, slot );
}

bool JSSVGHKernElementConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSSVGHKernElementConstructor, JSDOMWrapper>( exec, &JSSVGHKernElementConstructorTable, this,
            propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGHKernElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGHKernElementPrototypeTable = { 1, 0, JSSVGHKernElementPrototypeTableValues, 0 };
const ClassInfo JSSVGHKernElementPrototype::s_info = { "SVGHKernElementPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSSVGHKernElementPrototypeTable, 0 };

JSObject *JSSVGHKernElementPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSSVGHKernElement>( exec, globalObject );
}

const ClassInfo JSSVGHKernElement::s_info = { "SVGHKernElement", &JSSVGElement::s_info, &JSSVGHKernElementTable, 0 };

JSSVGHKernElement::JSSVGHKernElement( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<SVGHKernElement> impl )
    : JSSVGElement( structure, globalObject, impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSSVGHKernElement::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSSVGHKernElementPrototype( exec->globalData(), globalObject,
            JSSVGHKernElementPrototype::createStructure( exec->globalData(), JSSVGElementPrototype::self( exec, globalObject ) ) );
}

bool JSSVGHKernElement::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSSVGHKernElement, Base>( exec, &JSSVGHKernElementTable, this, propertyName, slot );
}

bool JSSVGHKernElement::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSSVGHKernElement, Base>( exec, &JSSVGHKernElementTable, this, propertyName, descriptor );
}

JSValue jsSVGHKernElementConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGHKernElement *domObject = static_cast<JSSVGHKernElement *>( asObject( slotBase ) );
    return JSSVGHKernElement::getConstructor( exec, domObject->globalObject() );
}

JSValue JSSVGHKernElement::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSSVGHKernElementConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}


}

#endif // ENABLE(SVG) && ENABLE(SVG_FONTS)
