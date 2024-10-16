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

#if ENABLE(WEB_AUDIO)

#include "JSJavaScriptAudioNode.h"

#include "EventListener.h"
#include "JSEventListener.h"
#include "JavaScriptAudioNode.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore
{

ASSERT_CLASS_FITS_IN_CELL( JSJavaScriptAudioNode );

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSJavaScriptAudioNodeTableValues[4] =
{
    { "onaudioprocess", DontDelete, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsJavaScriptAudioNodeOnaudioprocess ), ( intptr_t )setJSJavaScriptAudioNodeOnaudioprocess THUNK_GENERATOR( 0 ) },
    { "bufferSize", DontDelete | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsJavaScriptAudioNodeBufferSize ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { "constructor", DontEnum | ReadOnly, ( intptr_t )static_cast<PropertySlot::GetValueFunc>( jsJavaScriptAudioNodeConstructor ), ( intptr_t )0 THUNK_GENERATOR( 0 ) },
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSJavaScriptAudioNodeTable = { 8, 7, JSJavaScriptAudioNodeTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSJavaScriptAudioNodeConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSJavaScriptAudioNodeConstructorTable = { 1, 0, JSJavaScriptAudioNodeConstructorTableValues, 0 };
class JSJavaScriptAudioNodeConstructor : public DOMConstructorObject
{
public:
    JSJavaScriptAudioNodeConstructor( JSC::ExecState *, JSC::Structure *, JSDOMGlobalObject * );

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

const ClassInfo JSJavaScriptAudioNodeConstructor::s_info = { "JavaScriptAudioNodeConstructor", &DOMConstructorObject::s_info, &JSJavaScriptAudioNodeConstructorTable, 0 };

JSJavaScriptAudioNodeConstructor::JSJavaScriptAudioNodeConstructor( ExecState *exec, Structure *structure,
        JSDOMGlobalObject *globalObject )
    : DOMConstructorObject( structure, globalObject )
{
    ASSERT( inherits( &s_info ) );
    putDirect( exec->globalData(), exec->propertyNames().prototype, JSJavaScriptAudioNodePrototype::self( exec, globalObject ),
               DontDelete | ReadOnly );
}

bool JSJavaScriptAudioNodeConstructor::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSJavaScriptAudioNodeConstructor, JSDOMWrapper>( exec, &JSJavaScriptAudioNodeConstructorTable, this,
            propertyName, slot );
}

bool JSJavaScriptAudioNodeConstructor::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSJavaScriptAudioNodeConstructor, JSDOMWrapper>( exec, &JSJavaScriptAudioNodeConstructorTable,
            this, propertyName, descriptor );
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSJavaScriptAudioNodePrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR( 0 ) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSJavaScriptAudioNodePrototypeTable = { 1, 0, JSJavaScriptAudioNodePrototypeTableValues, 0 };
const ClassInfo JSJavaScriptAudioNodePrototype::s_info = { "JavaScriptAudioNodePrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSJavaScriptAudioNodePrototypeTable, 0 };

JSObject *JSJavaScriptAudioNodePrototype::self( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMPrototype<JSJavaScriptAudioNode>( exec, globalObject );
}

const ClassInfo JSJavaScriptAudioNode::s_info = { "JavaScriptAudioNode", &JSAudioNode::s_info, &JSJavaScriptAudioNodeTable, 0 };

JSJavaScriptAudioNode::JSJavaScriptAudioNode( Structure *structure, JSDOMGlobalObject *globalObject,
        PassRefPtr<JavaScriptAudioNode> impl )
    : JSAudioNode( structure, globalObject, impl )
{
    ASSERT( inherits( &s_info ) );
}

JSObject *JSJavaScriptAudioNode::createPrototype( ExecState *exec, JSGlobalObject *globalObject )
{
    return new ( exec ) JSJavaScriptAudioNodePrototype( exec->globalData(), globalObject,
            JSJavaScriptAudioNodePrototype::createStructure( exec->globalData(), JSAudioNodePrototype::self( exec, globalObject ) ) );
}

bool JSJavaScriptAudioNode::getOwnPropertySlot( ExecState *exec, const Identifier &propertyName, PropertySlot &slot )
{
    return getStaticValueSlot<JSJavaScriptAudioNode, Base>( exec, &JSJavaScriptAudioNodeTable, this, propertyName, slot );
}

bool JSJavaScriptAudioNode::getOwnPropertyDescriptor( ExecState *exec, const Identifier &propertyName,
        PropertyDescriptor &descriptor )
{
    return getStaticValueDescriptor<JSJavaScriptAudioNode, Base>( exec, &JSJavaScriptAudioNodeTable, this, propertyName, descriptor );
}

JSValue jsJavaScriptAudioNodeOnaudioprocess( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSJavaScriptAudioNode *castedThis = static_cast<JSJavaScriptAudioNode *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    JavaScriptAudioNode *imp = static_cast<JavaScriptAudioNode *>( castedThis->impl() );

    if ( EventListener *listener = imp->onaudioprocess() )
    {
        if ( const JSEventListener *jsListener = JSEventListener::cast( listener ) )
        {
            if ( JSObject *jsFunction = jsListener->jsFunction( imp->scriptExecutionContext() ) )
            {
                return jsFunction;
            }
        }
    }

    return jsNull();
}


JSValue jsJavaScriptAudioNodeBufferSize( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSJavaScriptAudioNode *castedThis = static_cast<JSJavaScriptAudioNode *>( asObject( slotBase ) );
    UNUSED_PARAM( exec );
    JavaScriptAudioNode *imp = static_cast<JavaScriptAudioNode *>( castedThis->impl() );
    JSValue result = jsNumber( imp->bufferSize() );
    return result;
}


JSValue jsJavaScriptAudioNodeConstructor( ExecState *exec, JSValue slotBase, const Identifier & )
{
    JSJavaScriptAudioNode *domObject = static_cast<JSJavaScriptAudioNode *>( asObject( slotBase ) );
    return JSJavaScriptAudioNode::getConstructor( exec, domObject->globalObject() );
}

void JSJavaScriptAudioNode::put( ExecState *exec, const Identifier &propertyName, JSValue value, PutPropertySlot &slot )
{
    lookupPut<JSJavaScriptAudioNode, Base>( exec, propertyName, value, &JSJavaScriptAudioNodeTable, this, slot );
}

void setJSJavaScriptAudioNodeOnaudioprocess( ExecState *exec, JSObject *thisObject, JSValue value )
{
    UNUSED_PARAM( exec );
    JSJavaScriptAudioNode *castedThis = static_cast<JSJavaScriptAudioNode *>( thisObject );
    JavaScriptAudioNode *imp = static_cast<JavaScriptAudioNode *>( castedThis->impl() );
    imp->setOnaudioprocess( createJSAttributeEventListener( exec, value, thisObject ) );
}


JSValue JSJavaScriptAudioNode::getConstructor( ExecState *exec, JSGlobalObject *globalObject )
{
    return getDOMConstructor<JSJavaScriptAudioNodeConstructor>( exec, static_cast<JSDOMGlobalObject *>( globalObject ) );
}

JSC::JSValue toJS( JSC::ExecState *exec, JSDOMGlobalObject *globalObject, JavaScriptAudioNode *impl )
{
    return wrap<JSJavaScriptAudioNode>( exec, globalObject, impl );
}


}

#endif // ENABLE(WEB_AUDIO)
