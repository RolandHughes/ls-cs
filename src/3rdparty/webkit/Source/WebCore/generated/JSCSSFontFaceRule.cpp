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
#include "JSCSSFontFaceRule.h"

#include "CSSFontFaceRule.h"
#include "CSSMutableStyleDeclaration.h"
#include "CSSStyleDeclaration.h"
#include "JSCSSStyleDeclaration.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSCSSFontFaceRule );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSCSSFontFaceRuleTableValues[3] =
{
    { "style", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsCSSFontFaceRuleStyle ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsCSSFontFaceRuleConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSCSSFontFaceRuleTable = { 4, 3, JSCSSFontFaceRuleTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSCSSFontFaceRuleConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSCSSFontFaceRuleConstructorTable = { 1, 0, JSCSSFontFaceRuleConstructorTableValues, 0 };
class JSCSSFontFaceRuleConstructor : public DOMConstructorObject
{
public:
    JSCSSFontFaceRuleConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSCSSFontFaceRuleConstructor::s_info = { "CSSFontFaceRuleConstructor", &DOMConstructorObject::s_info, &JSCSSFontFaceRuleConstructorTable, 0 };

JSCSSFontFaceRuleConstructor::JSCSSFontFaceRuleConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSCSSFontFaceRulePrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSCSSFontFaceRuleConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSCSSFontFaceRuleConstructor, JSDOMWrapper>( exec, &JSCSSFontFaceRuleConstructorTable, this,
            propertyName, slot );
}

bool JSCSSFontFaceRuleConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSCSSFontFaceRuleConstructor, JSDOMWrapper>( exec, &JSCSSFontFaceRuleConstructorTable, this,
            propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSCSSFontFaceRulePrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSCSSFontFaceRulePrototypeTable = { 1, 0, JSCSSFontFaceRulePrototypeTableValues, 0 };
const ClassInfo JSCSSFontFaceRulePrototype::s_info = { "CSSFontFaceRulePrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSCSSFontFaceRulePrototypeTable, 0 };

JSObject *JSCSSFontFaceRulePrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSCSSFontFaceRule>( exec, globalObject );
}

const ClassInfo JSCSSFontFaceRule::s_info = { "CSSFontFaceRule", &JSCSSRule::s_info, &JSCSSFontFaceRuleTable, 0 };

JSCSSFontFaceRule::JSCSSFontFaceRule( Structure *structure, JSDOMGlobalObject *globalObject, PassRefPtr<CSSFontFaceRule> impl )
    : JSCSSRule( structure, globalObject, impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSCSSFontFaceRule::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSCSSFontFaceRulePrototype( exec->globalData(), globalObject,
            JSCSSFontFaceRulePrototype::createStructure( exec->globalData(), JSCSSRulePrototype::self( exec, globalObject ) ) );
}

bool JSCSSFontFaceRule::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSCSSFontFaceRule, Base>( exec, &JSCSSFontFaceRuleTable, this, propertyName, slot );
}

bool JSCSSFontFaceRule::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSCSSFontFaceRule, Base>( exec, &JSCSSFontFaceRuleTable, this, propertyName, descriptor );
}

JSValue jsCSSFontFaceRuleStyle( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSCSSFontFaceRule *castedThis = static_cast<JSCSSFontFaceRule *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    CSSFontFaceRule *imp = static_cast<CSSFontFaceRule *>( castedThis->impl() );
    JSValue result = toJS( exec, castedThis->globalObject(), WTF::getPtr( imp->style() ) );
    return result;
}


JSValue jsCSSFontFaceRuleConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSCSSFontFaceRule *domObject = static_cast<JSCSSFontFaceRule *>( asObject( slotBase ) );
    return JSCSSFontFaceRule::getConstructor( exec, domObject->globalObject() );
}

JSValue JSCSSFontFaceRule::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSCSSFontFaceRuleConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}


}
