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

#ifndef JSIDBDatabaseException_h
#define JSIDBDatabaseException_h

#if ENABLE(INDEXED_DATABASE)

#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObjectWithGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore
{

class IDBDatabaseException;

class JSIDBDatabaseException : public JSDOMWrapper
{
    typedef JSDOMWrapper Base;
public:
    JSIDBDatabaseException( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<IDBDatabaseException> );
    static JSC::JSObject *createPrototype( JSC::ExecState *, JSC::JSGlobalObject * );
    virtual bool getOwnPropertySlot( JSC::ExecState *, const JSC::Identifier &propertyName, JSC::PropertySlot & );
    virtual bool getOwnPropertyDescriptor( JSC::ExecState *, const JSC::Identifier &propertyName, JSC::PropertyDescriptor & );
    static const JSC::ClassInfo s_info;

    static JSC::Structure *createStructure( JSC::JSGlobalData &globalData, JSC::JSValue prototype )
    {
        return JSC::Structure::create( globalData, prototype, JSC::TypeInfo( JSC::ObjectType, StructureFlags ), AnonymousSlotCount,
                                       &s_info );
    }

    static JSC::JSValue getConstructor( JSC::ExecState *, JSC::JSGlobalObject * );
    IDBDatabaseException *impl() const
    {
        return m_impl.get();
    }

private:
    RefPtr<IDBDatabaseException> m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

JSC::JSValue toJS( JSC::ExecState *, JSDOMGlobalObject *, IDBDatabaseException * );
IDBDatabaseException *toIDBDatabaseException( JSC::JSValue );

class JSIDBDatabaseExceptionPrototype : public JSC::JSObjectWithGlobalObject
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
    JSIDBDatabaseExceptionPrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                                     JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsIDBDatabaseExceptionPrototypeFunctionToString( JSC::ExecState * );
// Attributes

JSC::JSValue jsIDBDatabaseExceptionCode( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionName( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionMessage( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
// Constants

JSC::JSValue jsIDBDatabaseExceptionNO_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionUNKNOWN_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionNON_TRANSIENT_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionNOT_FOUND_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionCONSTRAINT_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionDATA_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionNOT_ALLOWED_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionSERIAL_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionRECOVERABLE_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionTRANSIENT_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionTIMEOUT_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionDEADLOCK_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionREAD_ONLY_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsIDBDatabaseExceptionABORT_ERR( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif // ENABLE(INDEXED_DATABASE)

#endif
