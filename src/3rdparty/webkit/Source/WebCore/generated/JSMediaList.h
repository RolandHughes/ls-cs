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

#ifndef JSMediaList_h
#define JSMediaList_h

#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObjectWithGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore
{

class MediaList;

class JSMediaList : public JSDOMWrapper
{
    typedef JSDOMWrapper Base;
public:
    JSMediaList( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<MediaList> );
    static JSC::JSObject *createPrototype( JSC::ExecState *, JSC::JSGlobalObject * );
    virtual bool getOwnPropertySlot( JSC::ExecState *, const JSC::Identifier &propertyName, JSC::PropertySlot & );
    virtual bool getOwnPropertyDescriptor( JSC::ExecState *, const JSC::Identifier &propertyName, JSC::PropertyDescriptor & );
    virtual bool getOwnPropertySlot( JSC::ExecState *, unsigned propertyName, JSC::PropertySlot & );
    virtual void put( JSC::ExecState *, const JSC::Identifier &propertyName, JSC::JSValue, JSC::PutPropertySlot & );
    static const JSC::ClassInfo s_info;

    static JSC::Structure *createStructure( JSC::JSGlobalData &globalData, JSC::JSValue prototype )
    {
        return JSC::Structure::create( globalData, prototype, JSC::TypeInfo( JSC::ObjectType, StructureFlags ), AnonymousSlotCount,
                                       &s_info );
    }

    virtual void getOwnPropertyNames( JSC::ExecState *, JSC::PropertyNameArray &,
                                      JSC::EnumerationMode mode = JSC::ExcludeDontEnumProperties );
    static JSC::JSValue getConstructor( JSC::ExecState *, JSC::JSGlobalObject * );
    MediaList *impl() const
    {
        return m_impl.get();
    }

private:
    RefPtr<MediaList> m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesGetPropertyNames | JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
    static JSC::JSValue indexGetter( JSC::ExecState *, JSC::JSValue, unsigned );
};

class JSMediaListOwner : public JSC::WeakHandleOwner
{
    virtual bool isReachableFromOpaqueRoots( JSC::Handle<JSC::Unknown>, void *context, JSC::SlotVisitor & );
    virtual void finalize( JSC::Handle<JSC::Unknown>, void *context );
};

inline JSC::WeakHandleOwner *wrapperOwner( DOMWrapperWorld *, MediaList * )
{
    DEFINE_STATIC_LOCAL( JSMediaListOwner, jsMediaListOwner, () );
    return &jsMediaListOwner;
}

inline void *wrapperContext( DOMWrapperWorld *world, MediaList * )
{
    return world;
}

JSC::JSValue toJS( JSC::ExecState *, JSDOMGlobalObject *, MediaList * );
MediaList *toMediaList( JSC::JSValue );

class JSMediaListPrototype : public JSC::JSObjectWithGlobalObject
{
    typedef JSC::JSObjectWithGlobalObject Base;
public:
    static JSC::JSObject *self( JSC::ExecState *, JSC::JSGlobalObject * );
    static const JSC::ClassInfo s_info;
    virtual bool getOwnPropertySlot( JSC::ExecState *, const JSC::Identifier &, JSC::PropertySlot & );
    virtual bool getOwnPropertyDescriptor( JSC::ExecState *, const JSC::Identifier &, JSC::PropertyDescriptor & );
    static JSC::Structure *createStructure( JSC::JSGlobalData &globalData, JSC::JSValue prototype )
    {
        return JSC::Structure::create( globalData, prototype, JSC::TypeInfo( JSC::ObjectType, StructureFlags ), AnonymousSlotCount,
                                       &s_info );
    }
    JSMediaListPrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                          JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsMediaListPrototypeFunctionItem( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsMediaListPrototypeFunctionDeleteMedium( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsMediaListPrototypeFunctionAppendMedium( JSC::ExecState * );
// Attributes

JSC::JSValue jsMediaListMediaText( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSMediaListMediaText( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsMediaListLength( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsMediaListConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif
