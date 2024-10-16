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

#if ENABLE(SVG) && ENABLE(SVG_ANIMATION)

#include "JSSVGAnimateTransformElement.h"

#include "SVGAnimateTransformElement.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSSVGAnimateTransformElement );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGAnimateTransformElementTableValues[2] =
{
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGAnimateTransformElementConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGAnimateTransformElementTable = { 2, 1, JSSVGAnimateTransformElementTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGAnimateTransformElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGAnimateTransformElementConstructorTable = { 1, 0, JSSVGAnimateTransformElementConstructorTableValues, 0 };
class JSSVGAnimateTransformElementConstructor : public DOMConstructorObject
{
public:
    JSSVGAnimateTransformElementConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSSVGAnimateTransformElementConstructor::s_info = { "SVGAnimateTransformElementConstructor", &DOMConstructorObject::s_info, &JSSVGAnimateTransformElementConstructorTable, 0 };

JSSVGAnimateTransformElementConstructor::JSSVGAnimateTransformElementConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSSVGAnimateTransformElementPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSSVGAnimateTransformElementConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName,
        PropertySlot &slot )
{
    return getStaticValueSlot<JSSVGAnimateTransformElementConstructor, JSDOMWrapper>( exec,
            &JSSVGAnimateTransformElementConstructorTable, this, propertyName, slot );
}

bool JSSVGAnimateTransformElementConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSSVGAnimateTransformElementConstructor, JSDOMWrapper>( exec,
            &JSSVGAnimateTransformElementConstructorTable, this, propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGAnimateTransformElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGAnimateTransformElementPrototypeTable = { 1, 0, JSSVGAnimateTransformElementPrototypeTableValues, 0 };
const ClassInfo JSSVGAnimateTransformElementPrototype::s_info = { "SVGAnimateTransformElementPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSSVGAnimateTransformElementPrototypeTable, 0 };

JSObject *JSSVGAnimateTransformElementPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSSVGAnimateTransformElement>( exec, globalObject );
}

const ClassInfo JSSVGAnimateTransformElement::s_info = { "SVGAnimateTransformElement", &JSSVGAnimationElement::s_info, &JSSVGAnimateTransformElementTable, 0 };

JSSVGAnimateTransformElement::JSSVGAnimateTransformElement( Structure *structure, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGAnimateTransformElement> impl )
    : JSSVGAnimationElement( structure, globalObject, impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSSVGAnimateTransformElement::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSSVGAnimateTransformElementPrototype( exec->globalData(), globalObject,
            JSSVGAnimateTransformElementPrototype::createStructure( exec->globalData(), JSSVGAnimationElementPrototype::self( exec,
                    globalObject ) ) );
}

bool JSSVGAnimateTransformElement::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSSVGAnimateTransformElement, Base>( exec, &JSSVGAnimateTransformElementTable, this, propertyName,
            slot );
}

bool JSSVGAnimateTransformElement::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSSVGAnimateTransformElement, Base>( exec, &JSSVGAnimateTransformElementTable, this, propertyName,
            descriptor );
}

JSValue jsSVGAnimateTransformElementConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGAnimateTransformElement *domObject = static_cast<JSSVGAnimateTransformElement *>( asObject( slotBase ) );
    return JSSVGAnimateTransformElement::getConstructor( exec, domObject->globalObject() );
}

JSValue JSSVGAnimateTransformElement::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSSVGAnimateTransformElementConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}


}

#endif // ENABLE(SVG) && ENABLE(SVG_ANIMATION)
