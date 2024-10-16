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

#ifndef JSSVGGElement_h
#define JSSVGGElement_h

#if ENABLE(SVG)

#include "JSSVGElement.h"
#include "SVGElement.h"
#include <runtime/JSObjectWithGlobalObject.h>

namespace WebCore
{

class SVGGElement;

class JSSVGGElement : public JSSVGElement
{
    typedef JSSVGElement Base;
public:
    JSSVGGElement( JSC::Structure *, JSDOMGlobalObject *, PassRefPtr<SVGGElement> );
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
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};


class JSSVGGElementPrototype : public JSC::JSObjectWithGlobalObject
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
    JSSVGGElementPrototype( JSC::JSGlobalData &globalData, JSC::JSGlobalObject *globalObject,
                            JSC::Structure *structure ) : JSC::JSObjectWithGlobalObject( globalData, globalObject, structure ) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsSVGGElementPrototypeFunctionHasExtension( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsSVGGElementPrototypeFunctionGetPresentationAttribute( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsSVGGElementPrototypeFunctionGetBBox( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsSVGGElementPrototypeFunctionGetCTM( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsSVGGElementPrototypeFunctionGetScreenCTM( JSC::ExecState * );
JSC::EncodedJSValue JSC_HOST_CALL jsSVGGElementPrototypeFunctionGetTransformToElement( JSC::ExecState * );
// Attributes

JSC::JSValue jsSVGGElementRequiredFeatures( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGGElementRequiredExtensions( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGGElementSystemLanguage( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGGElementXmllang( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSSVGGElementXmllang( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsSVGGElementXmlspace( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
void setJSSVGGElementXmlspace( JSC::ExecState *, JSC::JSObject *, JSC::JSValue );
JSC::JSValue jsSVGGElementExternalResourcesRequired( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGGElementClassName( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGGElementStyle( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGGElementTransform( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGGElementNearestViewportElement( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGGElementFarthestViewportElement( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );
JSC::JSValue jsSVGGElementConstructor( JSC::ExecState *, JSC::JSValue, const JSC::Identifier & );

} // namespace WebCore

#endif // ENABLE(SVG)

#endif
