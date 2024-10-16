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

#include "JSSVGMarkerElement.h"

#include "CSSMutableStyleDeclaration.h"
#include "CSSStyleDeclaration.h"
#include "CSSValue.h"
#include "ExceptionCode.h"
#include "JSCSSStyleDeclaration.h"
#include "JSCSSValue.h"
#include "JSDOMBinding.h"
#include "JSSVGAngle.h"
#include "JSSVGAnimatedAngle.h"
#include "JSSVGAnimatedBoolean.h"
#include "JSSVGAnimatedEnumeration.h"
#include "JSSVGAnimatedLength.h"
#include "JSSVGAnimatedPreserveAspectRatio.h"
#include "JSSVGAnimatedRect.h"
#include "JSSVGAnimatedString.h"
#include "KURL.h"
#include "SVGMarkerElement.h"
#include <runtime/Error.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSSVGMarkerElement );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGMarkerElementTableValues[16] =
{
    { "refX", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementRefX ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "refY", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementRefY ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "markerUnits", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementMarkerUnits ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "markerWidth", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementMarkerWidth ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "markerHeight", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementMarkerHeight ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "orientType", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementOrientType ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "orientAngle", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementOrientAngle ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "xmllang", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementXmllang ), ( intptr_t )setJSSVGMarkerElementXmllang THUNK_GENERATOR( 0 ) },
    { "xmlspace", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementXmlspace ), ( intptr_t )setJSSVGMarkerElementXmlspace THUNK_GENERATOR( 0 ) },
    { "externalResourcesRequired", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementExternalResourcesRequired ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "className", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementClassName ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "style", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementStyle ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "viewBox", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementViewBox ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "preserveAspectRatio", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementPreserveAspectRatio ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGMarkerElementTable = { 33, 31, JSSVGMarkerElementTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGMarkerElementConstructorTableValues[7] =
{
    { "SVG_MARKERUNITS_UNKNOWN", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementSVG_MARKERUNITS_UNKNOWN ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "SVG_MARKERUNITS_USERSPACEONUSE", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementSVG_MARKERUNITS_USERSPACEONUSE ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "SVG_MARKERUNITS_STROKEWIDTH", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementSVG_MARKERUNITS_STROKEWIDTH ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "SVG_MARKER_ORIENT_UNKNOWN", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementSVG_MARKER_ORIENT_UNKNOWN ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "SVG_MARKER_ORIENT_AUTO", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementSVG_MARKER_ORIENT_AUTO ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "SVG_MARKER_ORIENT_ANGLE", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementSVG_MARKER_ORIENT_ANGLE ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGMarkerElementConstructorTable = { 16, 15, JSSVGMarkerElementConstructorTableValues, 0 };

COMPILE_ASSERT( 0 == SVGMarkerElement::SVG_MARKERUNITS_UNKNOWN,
                SVGMarkerElementEnumSVG_MARKERUNITS_UNKNOWNIsWrongUseDontCheckEnums );
COMPILE_ASSERT( 1 == SVGMarkerElement::SVG_MARKERUNITS_USERSPACEONUSE,
                SVGMarkerElementEnumSVG_MARKERUNITS_USERSPACEONUSEIsWrongUseDontCheckEnums );
COMPILE_ASSERT( 2 == SVGMarkerElement::SVG_MARKERUNITS_STROKEWIDTH,
                SVGMarkerElementEnumSVG_MARKERUNITS_STROKEWIDTHIsWrongUseDontCheckEnums );
COMPILE_ASSERT( 0 == SVGMarkerElement::SVG_MARKER_ORIENT_UNKNOWN,
                SVGMarkerElementEnumSVG_MARKER_ORIENT_UNKNOWNIsWrongUseDontCheckEnums );
COMPILE_ASSERT( 1 == SVGMarkerElement::SVG_MARKER_ORIENT_AUTO,
                SVGMarkerElementEnumSVG_MARKER_ORIENT_AUTOIsWrongUseDontCheckEnums );
COMPILE_ASSERT( 2 == SVGMarkerElement::SVG_MARKER_ORIENT_ANGLE,
                SVGMarkerElementEnumSVG_MARKER_ORIENT_ANGLEIsWrongUseDontCheckEnums );

class JSSVGMarkerElementConstructor : public DOMConstructorObject
{
public:
    JSSVGMarkerElementConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSSVGMarkerElementConstructor::s_info = { "SVGMarkerElementConstructor", &DOMConstructorObject::s_info, &JSSVGMarkerElementConstructorTable, 0 };

JSSVGMarkerElementConstructor::JSSVGMarkerElementConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSSVGMarkerElementPrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSSVGMarkerElementConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSSVGMarkerElementConstructor, JSDOMWrapper>( exec, &JSSVGMarkerElementConstructorTable, this,
            propertyName, slot );
}

bool JSSVGMarkerElementConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSSVGMarkerElementConstructor, JSDOMWrapper>( exec, &JSSVGMarkerElementConstructorTable, this,
            propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSSVGMarkerElementPrototypeTableValues[10] =
{
    { "SVG_MARKERUNITS_UNKNOWN", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementSVG_MARKERUNITS_UNKNOWN ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "SVG_MARKERUNITS_USERSPACEONUSE", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementSVG_MARKERUNITS_USERSPACEONUSE ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "SVG_MARKERUNITS_STROKEWIDTH", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementSVG_MARKERUNITS_STROKEWIDTH ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "SVG_MARKER_ORIENT_UNKNOWN", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementSVG_MARKER_ORIENT_UNKNOWN ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "SVG_MARKER_ORIENT_AUTO", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementSVG_MARKER_ORIENT_AUTO ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "SVG_MARKER_ORIENT_ANGLE", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsSVGMarkerElementSVG_MARKER_ORIENT_ANGLE ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "setOrientToAuto", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsSVGMarkerElementPrototypeFunctionSetOrientToAuto ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "setOrientToAngle", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsSVGMarkerElementPrototypeFunctionSetOrientToAngle ), ( intptr_t )1 THUNK_GENERATOR( 0 ) },
    { "getPresentationAttribute", DontDelete | Function, ( intptr_t )static_cast<NativeFunction>( jsSVGMarkerElementPrototypeFunctionGetPresentationAttribute ), ( intptr_t )1 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSSVGMarkerElementPrototypeTable = { 32, 31, JSSVGMarkerElementPrototypeTableValues, 0 };
const ClassInfo JSSVGMarkerElementPrototype::s_info = { "SVGMarkerElementPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSSVGMarkerElementPrototypeTable, 0 };

JSObject *JSSVGMarkerElementPrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSSVGMarkerElement>( exec, globalObject );
}

bool JSSVGMarkerElementPrototype::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticPropertySlot<JSSVGMarkerElementPrototype, JSObject>( exec, &JSSVGMarkerElementPrototypeTable, this, propertyName,
            slot );
}

bool JSSVGMarkerElementPrototype::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticPropertyDescriptor<JSSVGMarkerElementPrototype, JSObject>( exec, &JSSVGMarkerElementPrototypeTable, this,
            propertyName, descriptor );
}

const ClassInfo JSSVGMarkerElement::s_info = { "SVGMarkerElement", &JSSVGElement::s_info, &JSSVGMarkerElementTable, 0 };

JSSVGMarkerElement::JSSVGMarkerElement( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<SVGMarkerElement> impl )
    : JSSVGElement( structure, globalObject, impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSSVGMarkerElement::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSSVGMarkerElementPrototype( exec->globalData(), globalObject,
            JSSVGMarkerElementPrototype::createStructure( exec->globalData(), JSSVGElementPrototype::self( exec, globalObject ) ) );
}

bool JSSVGMarkerElement::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSSVGMarkerElement, Base>( exec, &JSSVGMarkerElementTable, this, propertyName, slot );
}

bool JSSVGMarkerElement::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSSVGMarkerElement, Base>( exec, &JSSVGMarkerElementTable, this, propertyName, descriptor );
}

JSValue jsSVGMarkerElementRefX( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedLength> obj = imp->refXAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGMarkerElementRefY( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedLength> obj = imp->refYAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGMarkerElementMarkerUnits( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedEnumeration> obj = imp->markerUnitsAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGMarkerElementMarkerWidth( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedLength> obj = imp->markerWidthAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGMarkerElementMarkerHeight( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedLength> obj = imp->markerHeightAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGMarkerElementOrientType( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedEnumeration> obj = imp->orientTypeAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGMarkerElementOrientAngle( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedAngle> obj = imp->orientAngleAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGMarkerElementXmllang( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->xmllang() );
    return result;
}


JSValue jsSVGMarkerElementXmlspace( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    JSValue result = jsString( exec, imp->xmlspace() );
    return result;
}


JSValue jsSVGMarkerElementExternalResourcesRequired( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedBoolean> obj = imp->externalResourcesRequiredAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGMarkerElementClassName( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedString> obj = imp->classNameAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGMarkerElementStyle( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->style() ) );
    return result;
}


JSValue jsSVGMarkerElementViewBox( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedRect> obj = imp->viewBoxAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGMarkerElementPreserveAspectRatio( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    RefPtr<SVGAnimatedPreserveAspectRatio> obj = imp->preserveAspectRatioAnimated();
    JSValue result =  toJS( exec, castedThis->globalObject(), obj.get() );
    return result;
}


JSValue jsSVGMarkerElementConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSSVGMarkerElement *domObject = static_cast<JSSVGMarkerElement *>( asObject( slotBase ) );
    return JSSVGMarkerElement::getConstructor( exec, domObject->globalObject() );
}

void JSSVGMarkerElement::put( ExecState *exec, const Identifier &propertyName, JSValue value, PutPropertySlot &slot )
{
    lookupPut<JSSVGMarkerElement, Base>( exec, propertyName, value, &JSSVGMarkerElementTable, this, slot );
}

void setJSSVGMarkerElementXmllang( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( thisObject );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    imp->setXmllang( ustringToString( value.toString( exec ) ) );
}


void setJSSVGMarkerElementXmlspace( ExecState *exec, JSObject *thisObject, JSValue value )
{
    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( thisObject );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    imp->setXmlspace( ustringToString( value.toString( exec ) ) );
}


JSValue JSSVGMarkerElement::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSSVGMarkerElementConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}

EncodedJSValue JSC_HOST_CALL jsSVGMarkerElementPrototypeFunctionSetOrientToAuto( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSSVGMarkerElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( thisValue ) );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );

    imp->setOrientToAuto();
    return JSValue::encode( jsUndefined() );
}

EncodedJSValue JSC_HOST_CALL jsSVGMarkerElementPrototypeFunctionSetOrientToAngle( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSSVGMarkerElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( thisValue ) );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    SVGPropertyTearOff<SVGAngle> *angle( toSVGAngle( exec->argument( 0 ) ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }

    if ( !angle )
    {
        setDOMException( exec, TYPE_MISMATCH_ERR );
        return JSValue::encode( jsUndefined() );
    }

    imp->setOrientToAngle( angle->propertyReference() );
    return JSValue::encode( jsUndefined() );
}

EncodedJSValue JSC_HOST_CALL jsSVGMarkerElementPrototypeFunctionGetPresentationAttribute( ExecState *exec )
{
    JSValue thisValue = exec->hostThisValue();

    if ( !thisValue.inherits( &JSSVGMarkerElement::s_info ) )
    {
        return throwVMTypeError( exec );
    }

    JSSVGMarkerElement *castedThis = static_cast<JSSVGMarkerElement *>( asObject( thisValue ) );
    SVGMarkerElement *imp = static_cast<SVGMarkerElement *>( castedThis->impl() );
    const String &name( ustringToString( exec->argument( 0 ).toString( exec ) ) );

    if ( exec->hadException() )
    {
        return JSValue::encode( jsUndefined() );
    }


    JSC::JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->getPresentationAttribute( name ) ) );
    return JSValue::encode( result );
}

// Constant getters

JSValue jsSVGMarkerElementSVG_MARKERUNITS_UNKNOWN( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 0 ) );
}

JSValue jsSVGMarkerElementSVG_MARKERUNITS_USERSPACEONUSE( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 1 ) );
}

JSValue jsSVGMarkerElementSVG_MARKERUNITS_STROKEWIDTH( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 2 ) );
}

JSValue jsSVGMarkerElementSVG_MARKER_ORIENT_UNKNOWN( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 0 ) );
}

JSValue jsSVGMarkerElementSVG_MARKER_ORIENT_AUTO( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 1 ) );
}

JSValue jsSVGMarkerElementSVG_MARKER_ORIENT_ANGLE( ExecState *exec, JSValue, const Identifier & )
{
    UNUSED_PARAM( exec );
    return jsNumber( static_cast<int>( 2 ) );
}


}

#endif // ENABLE(SVG)
