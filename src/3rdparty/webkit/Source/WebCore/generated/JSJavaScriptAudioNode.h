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

#ifndef JSJavaScriptAudioNode_h
#define JSJavaScriptAudioNode_h

#if ENABLE(WEB_AUDIO)

#include "JSAudioNode.h"
#include <runtime/JSObjectWithGlobalObject.h>

namespace WebCore
{

class JavaScriptAudioNode;

class JSJavaScriptAudioNode : public JSAudioNode
{
    typedef JSAudioNode Base;
public:
    JSJavaScriptAudioNode( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<JavaScriptAudioNode> );
    static JSC::JSObject *createPrototype( JSC::ExecState *, JSC::JSGlobalObject * );
    virtual bool getOwnPropertySlot( JSC::ExecState *, const JSC::Identifier &propertyName, JSC::PropertySlot & );
    virtual bool getOwnPropertyDescriptor( JSC::ExecState *, const JSC::Identifier &propertyName, JSC::PropertyDescriptor & );
    virtual void put( JSC::ExecState *, const JSC::Identifier &propertyName, JSC::JSValue, JSC::PutPropertySlot & );
    static const JSC::ClassInfo s_info;

    static JSC::Structure *createStructure( JSC::JSGlobalData &globalData, JSC::JSValue prototype )
    {
        return JSC::Structure::create( globalData, prototype, JSC::TypeInfo( JSC::ObjectType, StructureFlags ), AnonymousSlotCount,
                                       &s_info );
    }

    virtual void visitChildren( JSC::SlotVisitor & );

    static JSC::JSValue getConstructor( JSC::ExecState *, JSC::JSGlobalObject * );
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::OverridesVisitChildren | Base::StructureFlags;
};

JSC::JSValue toJS( JSC::ExecState *, JSDOMGlobalObject *, JavaScriptAudioNode * );

class JSJavaScriptAudioNodePrototype : public JSC::JSObjectWithGlobalObject
{
    typedef JSC::JSObjectWithGlobalObject Base;
public:
    static JSC::JSObject *self( JSC::ExecState *, JSC::JSGlobalObject * );
    static const JSC::ClassInfo s_info;
    static JSC::Structure *createStructure( JSC::JSGlobalData &globalData, JSC::JSValue prototype )
    {
        return JSC::Structure::create( globalData, prototype, JSC::TypeInfo( JSC::ObjectType, StructureFlags ), AnonymousSlotCount,
                                       &s_info );
    }
    JSJavaScriptAudioNodePrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                                    JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesVisitChildren | Base::StructureFlags;
};

// Attributes

JSC::JSValue jsJavaScriptAudioNodeOnaudioprocess( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSJavaScriptAudioNodeOnaudioprocess( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsJavaScriptAudioNodeBufferSize( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsJavaScriptAudioNodeConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif // ENABLE(WEB_AUDIO)

#endif
