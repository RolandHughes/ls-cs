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

#ifndef JSSVGLength_h
#define JSSVGLength_h

#if ENABLE(SVG)

#include "JSDOMBinding.h"
#include "SVGAnimatedPropertyTearOff.h"
#include "SVGElement.h"
#include "SVGLength.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObjectWithGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore
{

class JSSVGLength : public JSDOMWrapper
{
    typedef JSDOMWrapper Base;
public:
    JSSVGLength( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<SVGPropertyTearOff<SVGLength> > );
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

    static JSC::JSValue getConstructor( JSC::ExecState *, JSC::JSGlobalObject * );

    // Custom attributes
    JSC::JSValue value( JSC::ExecState * ) const;
    void setValue( JSC::ExecState *, JSC::JSValue );

    // Custom functions
    JSC::JSValue convertToSpecifiedUnits( JSC::ExecState * );
    SVGPropertyTearOff<SVGLength> *impl() const
    {
        return m_impl.get();
    }

private:
    RefPtr<SVGPropertyTearOff<SVGLength> > m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

JSC::JSValue toJS( JSC::ExecState *, JSDOMGlobalObject *, SVGPropertyTearOff<SVGLength> * );
SVGPropertyTearOff<SVGLength> *toSVGLength( JSC::JSValue );

class JSSVGLengthPrototype : public JSC::JSObjectWithGlobalObject
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
    JSSVGLengthPrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                          JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsSVGLengthPrototypeFunctionNewValueSpecifiedUnits( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsSVGLengthPrototypeFunctionConvertToSpecifiedUnits( JSC::ExecState * );
// Attributes

JSC::JSValue jsSVGLengthUnitType( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGLengthValue( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSSVGLengthValue( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsSVGLengthValueInSpecifiedUnits( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSSVGLengthValueInSpecifiedUnits( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsSVGLengthValueAsString( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSSVGLengthValueAsString( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsSVGLengthConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
// Constants

JSC::JSValue jsSVGLengthSVG_LENGTHTYPE_UNKNOWN( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGLengthSVG_LENGTHTYPE_NUMBER( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGLengthSVG_LENGTHTYPE_PERCENTAGE( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGLengthSVG_LENGTHTYPE_EMS( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGLengthSVG_LENGTHTYPE_EXS( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGLengthSVG_LENGTHTYPE_PX( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGLengthSVG_LENGTHTYPE_CM( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGLengthSVG_LENGTHTYPE_MM( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGLengthSVG_LENGTHTYPE_IN( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGLengthSVG_LENGTHTYPE_PT( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGLengthSVG_LENGTHTYPE_PC( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif // ENABLE(SVG)

#endif
