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

#include "JSSVGUseElement.h"

#include "CSSMutableStyleDeclaration.h"
#include "CSSStyleDeclaration.h"
#include "CSSValue.h"
#include "ExceptionCode.h"
#include "JSCSSStyleDeclaration.h"
#include "JSCSSValue.h"
#include "JSDOMBinding.h"
#include "JSSVGAnimatedBoolean.h"
#include "JSSVGAnimatedLength.h"
#include "JSSVGAnimatedString.h"
#include "JSSVGAnimatedTransformList.h"
#include "JSSVGElement.h"
#include "JSSVGElementInstance.h"
#include "JSSVGMatrix.h"
#include "JSSVGRect.h"
#include "JSSVGStringList.h"
#include "KURL.h"
#include "SVGElement.h"
#include "SVGElementInstance.h"
#include "SVGMatrix.h"
#include "SVGRect.h"
#include "SVGStringList.h"
#include "SVGUseElement.h"
#include <runtime/Error.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSSVGUseElement );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGUseElementTableValues[20] =
{
    { "x", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementX ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "y", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementY ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "width", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementWidth ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "height", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementHeight ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "instanceRoot", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementInstanceRoot ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "animatedInstanceRoot", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementAnimatedInstanceRoot ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "href", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementHref ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "requiredFeatures", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementRequiredFeatures ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "requiredExtensions", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementRequiredExtensions ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "systemLanguage", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementSystemLanguage ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "xmllang", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementXmllang ), ( intptr_t )setJSSVGUseElementXmllang THUNK_GENERATOR( 0 ) },
    { "xmlspace", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementXmlspace ), ( intptr_t )setJSSVGUseElementXmlspace THUNK_GENERATOR( 0 ) },
    { "externalResourcesRequired", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementExternalResourcesRequired ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "className", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementClassName ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "style", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementStyle ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "transform", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementTransform ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "nearestViewportElement", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementNearestViewportElement ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "farthestViewportElement", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementFarthestViewportElement ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGUseElementConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGUseElementTable = { 68, 63, JSSVGUseElementTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGUseElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGUseElementConstructorTable = { 1, 0, JSSVGUseElementConstructorTableValues, 0 };
class JSSVGUseElementConstructor : public DOMConstructorObject
{
public:
    JSSVGUseElementConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSSVGUseElementConstructor::s_info = { "SVGUseElementConstructor", &DOMConstructorObject::s_info, &JSSVGUseElementConstructorTable, 0 };

JSSVGUseElementConstructor::JSSVGUseElementConstructor( ExecState *exec, Structure *structure, JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSSVGUseElementPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSSVGUseElementConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSSVGUseElementConstructor, JSDOMWrapper>( exec, &JSSVGUseElementConstructorTable, this, propertyName,
            slot );
}

bool JSSVGUseElementConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSSVGUseElementConstructor, JSDOMWrapper>( exec, &JSSVGUseElementConstructorTable, this,
            propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGUseElementPrototypeTableValues[7] =
{
    { "hasExtension", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsSVGUseElementPrototypeFunctionHasExtension ), ( intptr_t )1 THUNK_GENERATOR( 0 ) },
    { "getPresentationAttribute", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsSVGUseElementPrototypeFunctionGetPresentationAttribute ), ( intptr_t )1 THUNK_GENERATOR( 0 ) },
    { "getBBox", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsSVGUseElementPrototypeFunctionGetBBox ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "getCTM", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsSVGUseElementPrototypeFunctionGetCTM ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "getScreenCTM", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsSVGUseElementPrototypeFunctionGetScreenCTM ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "getTransformToElement", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsSVGUseElementPrototypeFunctionGetTransformToElement ), ( intptr_t )1 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGUseElementPrototypeTable = { 17, 15, JSSVGUseElementPrototypeTableValues, 0 };
const ClassInfo JSSVGUseElementPrototype::s_info = { "SVGUseElementPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSSVGUseElementPrototypeTable, 0 };

JSObject *JSSVGUseElementPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSSVGUseElement>( exec, globalObject );
}

bool JSSVGUseElementPrototype::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticFunctionSlot<JSObject>( exec, &JSSVGUseElementPrototypeTable, this, propertyName, slot );
}

bool JSSVGUseElementPrototype::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticFunctionDescriptor<JSObject>( exec, &JSSVGUseElementPrototypeTable, this, propertyName, descriptor );
}

const ClassInfo JSSVGUseElement::s_info = { "SVGUseElement", &JSSVGElement::s_info, &JSSVGUseElementTable, 0 };

JSSVGUseElement::JSSVGUseElement( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<SVGUseElement> impl )
    : JSSVGElement( structure, globalObject, impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSSVGUseElement::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSSVGUseElementPrototype( exec->globalData(), globalObject,
            JSSVGUseElementPrototype::createStructure( exec->globalData(), JSSVGElementPrototype::self( exec, globalObject ) ) );
}

bool JSSVGUseElement::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSSVGUseElement, Base>( exec, &JSSVGUseElementTable, this, propertyName, slot );
}

bool JSSVGUseElement::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName, PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSSVGUseElement, Base>( exec, &JSSVGUseElementTable, this, propertyName, descriptor );
}

JSValue jsSVGUseElementX( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedLength> obj = imp->xAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGUseElementY( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedLength> obj = imp->yAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGUseElementWidth( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedLength> obj = imp->widthAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGUseElementHeight( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedLength> obj = imp->heightAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGUseElementInstanceRoot( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->instanceRoot() ) );
    return result;
}


JSValue jsSVGUseElementAnimatedInstanceRoot( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->animatedInstanceRoot() ) );
    return result;
}


JSValue jsSVGUseElementHref( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedString> obj = imp->hrefAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGUseElementRequiredFeatures( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(),
                           WTF::getPtr( SVGStaticListPropertyTearOff<SVGStringList>::create(
                                            GetOwnerElementForType<SVGUseElement, IsDerivedFromSVGElement<SVGUseElement>::value>::ownerElement( imp ),
                                            imp->requiredFeatures() ) ) );
    return result;
}


JSValue jsSVGUseElementRequiredExtensions( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(),
                           WTF::getPtr( SVGStaticListPropertyTearOff<SVGStringList>::create(
                                            GetOwnerElementForType<SVGUseElement, IsDerivedFromSVGElement<SVGUseElement>::value>::ownerElement( imp ),
                                            imp->requiredExtensions() ) ) );
    return result;
}


JSValue jsSVGUseElementSystemLanguage( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(),
                           WTF::getPtr( SVGStaticListPropertyTearOff<SVGStringList>::create(
                                            GetOwnerElementForType<SVGUseElement, IsDerivedFromSVGElement<SVGUseElement>::value>::ownerElement( imp ),
                                            imp->systemLanguage() ) ) );
    return result;
}


JSValue jsSVGUseElementXmllang( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->xmllang() );
    return result;
}


JSValue jsSVGUseElementXmlspace( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->xmlspace() );
    return result;
}


JSValue jsSVGUseElementExternalResourcesRequired( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedBoolean> obj = imp->externalResourcesRequiredAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGUseElementClassName( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedString> obj = imp->classNameAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGUseElementStyle( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->style() ) );
    return result;
}


JSValue jsSVGUseElementTransform( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedTransformList> obj = imp->transformAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGUseElementNearestViewportElement( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->nearestViewportElement() ) );
    return result;
}


JSValue jsSVGUseElementFarthestViewportElement( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->farthestViewportElement() ) );
    return result;
}


JSValue jsSVGUseElementConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGUseElement *domObject = static_cast<JSSVGUseElement *>( asObject( slotBase ) );
    return JSSVGUseElement::getConstructor( exec, domObject->globalObject() );
}

void JSSVGUseElement::put( ExecState *exec, const Identifier &propertyName, JSValue value, PutPropertySlot &slot )
{
    lookupPut<JSSVGUseElement, Base>( exec, propertyName, value, &JSSVGUseElementTable, this, slot );
}

void setJSSVGUseElementXmllang( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( thisObject );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    imp->setXmllang( ustringToString( value.toString( exec ) ) );
}


void setJSSVGUseElementXmlspace( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( thisObject );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    imp->setXmlspace( ustringToString( value.toString( exec ) ) );
}


JSValue JSSVGUseElement::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSSVGUseElementConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}

EncodedJSValue JSC_HOST_CALL jsSVGUseElementPrototypeFunctionHasExtension( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSSVGUseElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( thisValue ) );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    const String &extension( ustringToString( exec->argument( 0 ).toString( exec ) ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }


    JSC::JSValue result = jsBoolean( imp->hasExtension( extension ) );
    return JSValue::encode( result );
}

EncodedJSValue JSC_HOST_CALL jsSVGUseElementPrototypeFunctionGetPresentationAttribute( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSSVGUseElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( thisValue ) );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    const String &name( ustringToString( exec->argument( 0 ).toString( exec ) ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }


    JSC::JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->getPresentationAttribute( name ) ) );
    return JSValue::encode( result );
}

EncodedJSValue JSC_HOST_CALL jsSVGUseElementPrototypeFunctionGetBBox( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSSVGUseElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( thisValue ) );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );


    JSC::JSValue result = toJS( exec, castedThis->globalObject(),
                                WTF::getPtr( SVGPropertyTearOff<FloatRect>::create( imp->getBBox() ) ) );
    return JSValue::encode( result );
}

EncodedJSValue JSC_HOST_CALL jsSVGUseElementPrototypeFunctionGetCTM( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSSVGUseElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( thisValue ) );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );


    JSC::JSValue result = toJS( exec, castedThis->globalObject(),
                                WTF::getPtr( SVGPropertyTearOff<SVGMatrix>::create( imp->getCTM() ) ) );
    return JSValue::encode( result );
}

EncodedJSValue JSC_HOST_CALL jsSVGUseElementPrototypeFunctionGetScreenCTM( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSSVGUseElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( thisValue ) );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );


    JSC::JSValue result = toJS( exec, castedThis->globalObject(),
                                WTF::getPtr( SVGPropertyTearOff<SVGMatrix>::create( imp->getScreenCTM() ) ) );
    return JSValue::encode( result );
}

EncodedJSValue JSC_HOST_CALL jsSVGUseElementPrototypeFunctionGetTransformToElement( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSSVGUseElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSSVGUseElement *castedThis = static_cast<JSSVGUseElement *>( asObject( thisValue ) );
    SVGUseElement *imp = static_cast<SVGUseElement *>( castedThis->impl() );
    ExceptionCode ec = 0;
    SVGElement *element( toSVGElement( exec->argument( 0 ) ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }


    JSC::JSValue result = toJS( exec, castedThis->globalObject(),
                                WTF::getPtr( SVGPropertyTearOff<SVGMatrix>::create( imp->getTransformToElement( element, ec ) ) ) );
    setDOMException( exec, ec );
    return JSValue::encode( result );
}


}

#endif // ENABLE(SVG)
