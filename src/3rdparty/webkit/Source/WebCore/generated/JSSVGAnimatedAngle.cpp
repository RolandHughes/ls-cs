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

#if ENABLE(SVG)

#include "JSSVGAnimatedAngle.h"

#include "JSSVGAngle.h"
#include "SVGAngle.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSSVGAnimatedAngle );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGAnimatedAngleTableValues[4] =
{
    { "baseVal", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGAnimatedAngleBaseVal ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "animVal", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGAnimatedAngleAnimVal ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGAnimatedAngleConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGAnimatedAngleTable = { 8, 7, JSSVGAnimatedAngleTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGAnimatedAngleConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGAnimatedAngleConstructorTable = { 1, 0, JSSVGAnimatedAngleConstructorTableValues, 0 };
class JSSVGAnimatedAngleConstructor : public DOMConstructorObject
{
public:
    JSSVGAnimatedAngleConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSSVGAnimatedAngleConstructor::s_info = { "SVGAnimatedAngleConstructor", &DOMConstructorObject::s_info, &JSSVGAnimatedAngleConstructorTable, 0 };

JSSVGAnimatedAngleConstructor::JSSVGAnimatedAngleConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSSVGAnimatedAnglePrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSSVGAnimatedAngleConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSSVGAnimatedAngleConstructor, JSDOMWrapper>( exec, &JSSVGAnimatedAngleConstructorTable, this,
            propertyName, slot );
}

bool JSSVGAnimatedAngleConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSSVGAnimatedAngleConstructor, JSDOMWrapper>( exec, &JSSVGAnimatedAngleConstructorTable, this,
            propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGAnimatedAnglePrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGAnimatedAnglePrototypeTable = { 1, 0, JSSVGAnimatedAnglePrototypeTableValues, 0 };
const ClassInfo JSSVGAnimatedAnglePrototype::s_info = { "SVGAnimatedAnglePrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSSVGAnimatedAnglePrototypeTable, 0 };

JSObject *JSSVGAnimatedAnglePrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSSVGAnimatedAngle>( exec, globalObject );
}

const ClassInfo JSSVGAnimatedAngle::s_info = { "SVGAnimatedAngle", &JSDOMWrapper::s_info, &JSSVGAnimatedAngleTable, 0 };

JSSVGAnimatedAngle::JSSVGAnimatedAngle( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<SVGAnimatedAngle> impl )
    : JSDOMWrapper( structure, globalObject )
    , m_impl( impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSSVGAnimatedAngle::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSSVGAnimatedAnglePrototype( exec->globalData(), globalObject,
            JSSVGAnimatedAnglePrototype::createStructure( globalObject->globalData(), globalObject->objectPrototype() ) );
}

bool JSSVGAnimatedAngle::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSSVGAnimatedAngle, Base>( exec, &JSSVGAnimatedAngleTable, this, propertyName, slot );
}

bool JSSVGAnimatedAngle::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSSVGAnimatedAngle, Base>( exec, &JSSVGAnimatedAngleTable, this, propertyName, descriptor );
}

JSValue jsSVGAnimatedAngleBaseVal( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGAnimatedAngle *castedThis = static_cast<JSSVGAnimatedAngle *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGAnimatedAngle *imp = static_cast<SVGAnimatedAngle *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(),
                           WTF::getPtr( static_cast<SVGPropertyTearOff<SVGAngle>*>( imp->baseVal() ) ) );
    return result;
}


JSValue jsSVGAnimatedAngleAnimVal( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGAnimatedAngle *castedThis = static_cast<JSSVGAnimatedAngle *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGAnimatedAngle *imp = static_cast<SVGAnimatedAngle *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(),
                           WTF::getPtr( static_cast<SVGPropertyTearOff<SVGAngle>*>( imp->animVal() ) ) );
    return result;
}


JSValue jsSVGAnimatedAngleConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGAnimatedAngle *domObject = static_cast<JSSVGAnimatedAngle *>( asObject( slotBase ) );
    return JSSVGAnimatedAngle::getConstructor( exec, domObject->globalObject() );
}

JSValue JSSVGAnimatedAngle::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSSVGAnimatedAngleConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}

JSC::JSValue toJS( JSC::ExecState *exec, JSDOMGlobalObject *globalObject, SVGAnimatedAngle *impl )
{
    return wrap<JSSVGAnimatedAngle>( exec, globalObject, impl );
}

SVGAnimatedAngle *toSVGAnimatedAngle( JSC::JSValue value )
{
    return value.inherits( &JSSVGAnimatedAngle::s_info ) ? static_cast<JSSVGAnimatedAngle *>( asObject( value ) )->impl() : 0;
}

}

#endif // ENABLE(SVG)
