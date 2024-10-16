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

#include "JSSVGAnimatedEnumeration.h"

#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSSVGAnimatedEnumeration );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGAnimatedEnumerationTableValues[4] =
{
    { "baseVal", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGAnimatedEnumerationBaseVal ), ( intptr_t )setJSSVGAnimatedEnumerationBaseVal THUNK_GENERATOR( 0 ) },
    { "animVal", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGAnimatedEnumerationAnimVal ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGAnimatedEnumerationConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGAnimatedEnumerationTable = { 8, 7, JSSVGAnimatedEnumerationTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGAnimatedEnumerationConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGAnimatedEnumerationConstructorTable = { 1, 0, JSSVGAnimatedEnumerationConstructorTableValues, 0 };
class JSSVGAnimatedEnumerationConstructor : public DOMConstructorObject
{
public:
    JSSVGAnimatedEnumerationConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSSVGAnimatedEnumerationConstructor::s_info = { "SVGAnimatedEnumerationConstructor", &DOMConstructorObject::s_info, &JSSVGAnimatedEnumerationConstructorTable, 0 };

JSSVGAnimatedEnumerationConstructor::JSSVGAnimatedEnumerationConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSSVGAnimatedEnumerationPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSSVGAnimatedEnumerationConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName,
        PropertySlot &slot )
{
    return getStaticValueSlot<JSSVGAnimatedEnumerationConstructor, JSDOMWrapper>( exec, &JSSVGAnimatedEnumerationConstructorTable,
            this, propertyName, slot );
}

bool JSSVGAnimatedEnumerationConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSSVGAnimatedEnumerationConstructor, JSDOMWrapper>( exec,
            &JSSVGAnimatedEnumerationConstructorTable, this, propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGAnimatedEnumerationPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGAnimatedEnumerationPrototypeTable = { 1, 0, JSSVGAnimatedEnumerationPrototypeTableValues, 0 };
const ClassInfo JSSVGAnimatedEnumerationPrototype::s_info = { "SVGAnimatedEnumerationPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSSVGAnimatedEnumerationPrototypeTable, 0 };

JSObject *JSSVGAnimatedEnumerationPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSSVGAnimatedEnumeration>( exec, globalObject );
}

const ClassInfo JSSVGAnimatedEnumeration::s_info = { "SVGAnimatedEnumeration", &JSDOMWrapper::s_info, &JSSVGAnimatedEnumerationTable, 0 };

JSSVGAnimatedEnumeration::JSSVGAnimatedEnumeration( Structure *structure, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGAnimatedEnumeration> impl )
    : JSDOMWrapper( structure, globalObject )
    , m_impl( impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSSVGAnimatedEnumeration::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSSVGAnimatedEnumerationPrototype( exec->globalData(), globalObject,
            JSSVGAnimatedEnumerationPrototype::createStructure( globalObject->globalData(), globalObject->objectPrototype() ) );
}

bool JSSVGAnimatedEnumeration::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSSVGAnimatedEnumeration, Base>( exec, &JSSVGAnimatedEnumerationTable, this, propertyName, slot );
}

bool JSSVGAnimatedEnumeration::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSSVGAnimatedEnumeration, Base>( exec, &JSSVGAnimatedEnumerationTable, this, propertyName,
            descriptor );
}

JSValue jsSVGAnimatedEnumerationBaseVal( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGAnimatedEnumeration *castedThis = static_cast<JSSVGAnimatedEnumeration *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGAnimatedEnumeration *imp = static_cast<SVGAnimatedEnumeration *>( castedThis->impl() );
    JSValue result = jsNumber( imp->baseVal() );
    return result;
}


JSValue jsSVGAnimatedEnumerationAnimVal( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGAnimatedEnumeration *castedThis = static_cast<JSSVGAnimatedEnumeration *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGAnimatedEnumeration *imp = static_cast<SVGAnimatedEnumeration *>( castedThis->impl() );
    JSValue result = jsNumber( imp->animVal() );
    return result;
}


JSValue jsSVGAnimatedEnumerationConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGAnimatedEnumeration *domObject = static_cast<JSSVGAnimatedEnumeration *>( asObject( slotBase ) );
    return JSSVGAnimatedEnumeration::getConstructor( exec, domObject->globalObject() );
}

void JSSVGAnimatedEnumeration::put( ExecState *exec, const Identifier &propertyName, JSValue value, PutPropertySlot &slot )
{
    lookupPut<JSSVGAnimatedEnumeration, Base>( exec, propertyName, value, &JSSVGAnimatedEnumerationTable, this, slot );
}

void setJSSVGAnimatedEnumerationBaseVal( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSSVGAnimatedEnumeration *castedThis = static_cast<JSSVGAnimatedEnumeration *>( thisObject );
    SVGAnimatedEnumeration *imp = static_cast<SVGAnimatedEnumeration *>( castedThis->impl() );
    imp->setBaseVal( value.toUInt32( exec ) );
}


JSValue JSSVGAnimatedEnumeration::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSSVGAnimatedEnumerationConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}

JSC::JSValue toJS( JSC::ExecState *exec, JSDOMGlobalObject *globalObject, SVGAnimatedEnumeration *impl )
{
    return wrap<JSSVGAnimatedEnumeration>( exec, globalObject, impl );
}

SVGAnimatedEnumeration *toSVGAnimatedEnumeration( JSC::JSValue value )
{
    return value.inherits( &JSSVGAnimatedEnumeration::s_info ) ? static_cast<JSSVGAnimatedEnumeration *>( asObject(
                value ) )->impl() : 0;
}

}

#endif // ENABLE(SVG)
