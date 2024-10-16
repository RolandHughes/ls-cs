/*
 * THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.
 *
 * This file was generated by the dom/make_names.pl script.
 *
 * Copyright (C) 2005, 2006, 2007, 2008, 2009 Apple Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "JSSVGElementWrapperFactory.h"

#if ENABLE(SVG)

#include "JSSVGAElement.h"
#include "JSSVGAltGlyphElement.h"
#include "JSSVGAnimateElement.h"
#include "JSSVGAnimateColorElement.h"
#include "JSSVGAnimateTransformElement.h"
#include "JSSVGCircleElement.h"
#include "JSSVGClipPathElement.h"
#include "JSSVGCursorElement.h"
#include "JSSVGDefsElement.h"
#include "JSSVGDescElement.h"
#include "JSSVGEllipseElement.h"
#include "JSSVGFEBlendElement.h"
#include "JSSVGFEColorMatrixElement.h"
#include "JSSVGFEComponentTransferElement.h"
#include "JSSVGFECompositeElement.h"
#include "JSSVGFEConvolveMatrixElement.h"
#include "JSSVGFEDiffuseLightingElement.h"
#include "JSSVGFEDisplacementMapElement.h"
#include "JSSVGFEDistantLightElement.h"
#include "JSSVGFEDropShadowElement.h"
#include "JSSVGFEFloodElement.h"
#include "JSSVGFEFuncAElement.h"
#include "JSSVGFEFuncBElement.h"
#include "JSSVGFEFuncGElement.h"
#include "JSSVGFEFuncRElement.h"
#include "JSSVGFEGaussianBlurElement.h"
#include "JSSVGFEImageElement.h"
#include "JSSVGFEMergeElement.h"
#include "JSSVGFEMergeNodeElement.h"
#include "JSSVGFEMorphologyElement.h"
#include "JSSVGFEOffsetElement.h"
#include "JSSVGFEPointLightElement.h"
#include "JSSVGFESpecularLightingElement.h"
#include "JSSVGFESpotLightElement.h"
#include "JSSVGFETileElement.h"
#include "JSSVGFETurbulenceElement.h"
#include "JSSVGFilterElement.h"
#include "JSSVGFontElement.h"
#include "JSSVGFontFaceElement.h"
#include "JSSVGFontFaceFormatElement.h"
#include "JSSVGFontFaceNameElement.h"
#include "JSSVGFontFaceSrcElement.h"
#include "JSSVGFontFaceUriElement.h"
#include "JSSVGForeignObjectElement.h"
#include "JSSVGGElement.h"
#include "JSSVGGlyphElement.h"
#include "JSSVGImageElement.h"
#include "JSSVGLineElement.h"
#include "JSSVGLinearGradientElement.h"
#include "JSSVGMarkerElement.h"
#include "JSSVGMaskElement.h"
#include "JSSVGMetadataElement.h"
#include "JSSVGMissingGlyphElement.h"
#include "JSSVGPathElement.h"
#include "JSSVGPatternElement.h"
#include "JSSVGPolygonElement.h"
#include "JSSVGPolylineElement.h"
#include "JSSVGRadialGradientElement.h"
#include "JSSVGRectElement.h"
#include "JSSVGScriptElement.h"
#include "JSSVGSetElement.h"
#include "JSSVGStopElement.h"
#include "JSSVGStyleElement.h"
#include "JSSVGSVGElement.h"
#include "JSSVGSwitchElement.h"
#include "JSSVGSymbolElement.h"
#include "JSSVGTextElement.h"
#include "JSSVGTextPathElement.h"
#include "JSSVGTitleElement.h"
#include "JSSVGTRefElement.h"
#include "JSSVGTSpanElement.h"
#include "JSSVGUseElement.h"
#include "JSSVGViewElement.h"
#include "JSSVGVKernElement.h"

#include "SVGNames.h"

#include "SVGAElement.h"
#include "SVGAltGlyphElement.h"
#include "SVGAnimateElement.h"
#include "SVGAnimateColorElement.h"
#include "SVGAnimateMotionElement.h"
#include "SVGAnimateTransformElement.h"
#include "SVGCircleElement.h"
#include "SVGClipPathElement.h"
#include "SVGCursorElement.h"
#include "SVGDefsElement.h"
#include "SVGDescElement.h"
#include "SVGEllipseElement.h"
#include "SVGFEBlendElement.h"
#include "SVGFEColorMatrixElement.h"
#include "SVGFEComponentTransferElement.h"
#include "SVGFECompositeElement.h"
#include "SVGFEConvolveMatrixElement.h"
#include "SVGFEDiffuseLightingElement.h"
#include "SVGFEDisplacementMapElement.h"
#include "SVGFEDistantLightElement.h"
#include "SVGFEDropShadowElement.h"
#include "SVGFEFloodElement.h"
#include "SVGFEFuncAElement.h"
#include "SVGFEFuncBElement.h"
#include "SVGFEFuncGElement.h"
#include "SVGFEFuncRElement.h"
#include "SVGFEGaussianBlurElement.h"
#include "SVGFEImageElement.h"
#include "SVGFEMergeElement.h"
#include "SVGFEMergeNodeElement.h"
#include "SVGFEMorphologyElement.h"
#include "SVGFEOffsetElement.h"
#include "SVGFEPointLightElement.h"
#include "SVGFESpecularLightingElement.h"
#include "SVGFESpotLightElement.h"
#include "SVGFETileElement.h"
#include "SVGFETurbulenceElement.h"
#include "SVGFilterElement.h"
#include "SVGFontElement.h"
#include "SVGFontFaceElement.h"
#include "SVGFontFaceFormatElement.h"
#include "SVGFontFaceNameElement.h"
#include "SVGFontFaceSrcElement.h"
#include "SVGFontFaceUriElement.h"
#include "SVGForeignObjectElement.h"
#include "SVGGElement.h"
#include "SVGGlyphElement.h"
#include "SVGHKernElement.h"
#include "SVGImageElement.h"
#include "SVGLineElement.h"
#include "SVGLinearGradientElement.h"
#include "SVGMarkerElement.h"
#include "SVGMaskElement.h"
#include "SVGMetadataElement.h"
#include "SVGMissingGlyphElement.h"
#include "SVGMPathElement.h"
#include "SVGPathElement.h"
#include "SVGPatternElement.h"
#include "SVGPolygonElement.h"
#include "SVGPolylineElement.h"
#include "SVGRadialGradientElement.h"
#include "SVGRectElement.h"
#include "SVGScriptElement.h"
#include "SVGSetElement.h"
#include "SVGStopElement.h"
#include "SVGStyleElement.h"
#include "SVGSVGElement.h"
#include "SVGSwitchElement.h"
#include "SVGSymbolElement.h"
#include "SVGTextElement.h"
#include "SVGTextPathElement.h"
#include "SVGTitleElement.h"
#include "SVGTRefElement.h"
#include "SVGTSpanElement.h"
#include "SVGUseElement.h"
#include "SVGViewElement.h"
#include "SVGVKernElement.h"

#include <wtf/StdLibExtras.h>

#if ENABLE(VIDEO)
#include "Document.h"
#include "Settings.h"
#endif

using namespace JSC;

namespace WebCore
{

using namespace SVGNames;

typedef JSDOMWrapper *( *CreateSVGElementWrapperFunction )( ExecState *, JSDOMGlobalObject *, PassRefPtr<SVGElement> );

static JSDOMWrapper *createSVGAElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject, PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGAElement, element.get() );
}

static JSDOMWrapper *createSVGAltGlyphElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGAltGlyphElement, element.get() );
}

static JSDOMWrapper *createSVGAnimateElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGAnimateElement, element.get() );
}

static JSDOMWrapper *createSVGAnimateColorElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGAnimateColorElement, element.get() );
}

static JSDOMWrapper *createSVGAnimateTransformElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGAnimateTransformElement, element.get() );
}

static JSDOMWrapper *createSVGCircleElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGCircleElement, element.get() );
}

static JSDOMWrapper *createSVGClipPathElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGClipPathElement, element.get() );
}

static JSDOMWrapper *createSVGCursorElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGCursorElement, element.get() );
}

static JSDOMWrapper *createSVGDefsElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGDefsElement, element.get() );
}

static JSDOMWrapper *createSVGDescElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGDescElement, element.get() );
}

static JSDOMWrapper *createSVGEllipseElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGEllipseElement, element.get() );
}

static JSDOMWrapper *createSVGFEBlendElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEBlendElement, element.get() );
}

static JSDOMWrapper *createSVGFEColorMatrixElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEColorMatrixElement, element.get() );
}

static JSDOMWrapper *createSVGFEComponentTransferElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEComponentTransferElement, element.get() );
}

static JSDOMWrapper *createSVGFECompositeElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFECompositeElement, element.get() );
}

static JSDOMWrapper *createSVGFEConvolveMatrixElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEConvolveMatrixElement, element.get() );
}

static JSDOMWrapper *createSVGFEDiffuseLightingElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEDiffuseLightingElement, element.get() );
}

static JSDOMWrapper *createSVGFEDisplacementMapElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEDisplacementMapElement, element.get() );
}

static JSDOMWrapper *createSVGFEDistantLightElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEDistantLightElement, element.get() );
}

static JSDOMWrapper *createSVGFEDropShadowElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEDropShadowElement, element.get() );
}

static JSDOMWrapper *createSVGFEFloodElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEFloodElement, element.get() );
}

static JSDOMWrapper *createSVGFEFuncAElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEFuncAElement, element.get() );
}

static JSDOMWrapper *createSVGFEFuncBElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEFuncBElement, element.get() );
}

static JSDOMWrapper *createSVGFEFuncGElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEFuncGElement, element.get() );
}

static JSDOMWrapper *createSVGFEFuncRElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEFuncRElement, element.get() );
}

static JSDOMWrapper *createSVGFEGaussianBlurElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEGaussianBlurElement, element.get() );
}

static JSDOMWrapper *createSVGFEImageElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEImageElement, element.get() );
}

static JSDOMWrapper *createSVGFEMergeElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEMergeElement, element.get() );
}

static JSDOMWrapper *createSVGFEMergeNodeElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEMergeNodeElement, element.get() );
}

static JSDOMWrapper *createSVGFEMorphologyElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEMorphologyElement, element.get() );
}

static JSDOMWrapper *createSVGFEOffsetElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEOffsetElement, element.get() );
}

static JSDOMWrapper *createSVGFEPointLightElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFEPointLightElement, element.get() );
}

static JSDOMWrapper *createSVGFESpecularLightingElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFESpecularLightingElement, element.get() );
}

static JSDOMWrapper *createSVGFESpotLightElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFESpotLightElement, element.get() );
}

static JSDOMWrapper *createSVGFETileElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFETileElement, element.get() );
}

static JSDOMWrapper *createSVGFETurbulenceElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFETurbulenceElement, element.get() );
}

static JSDOMWrapper *createSVGFilterElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFilterElement, element.get() );
}

static JSDOMWrapper *createSVGFontElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFontElement, element.get() );
}

static JSDOMWrapper *createSVGFontFaceElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFontFaceElement, element.get() );
}

static JSDOMWrapper *createSVGFontFaceFormatElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFontFaceFormatElement, element.get() );
}

static JSDOMWrapper *createSVGFontFaceNameElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFontFaceNameElement, element.get() );
}

static JSDOMWrapper *createSVGFontFaceSrcElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFontFaceSrcElement, element.get() );
}

static JSDOMWrapper *createSVGFontFaceUriElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGFontFaceUriElement, element.get() );
}

static JSDOMWrapper *createSVGForeignObjectElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGForeignObjectElement, element.get() );
}

static JSDOMWrapper *createSVGGElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject, PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGGElement, element.get() );
}

static JSDOMWrapper *createSVGGlyphElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGGlyphElement, element.get() );
}

static JSDOMWrapper *createSVGImageElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGImageElement, element.get() );
}

static JSDOMWrapper *createSVGLineElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGLineElement, element.get() );
}

static JSDOMWrapper *createSVGLinearGradientElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGLinearGradientElement, element.get() );
}

static JSDOMWrapper *createSVGMarkerElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGMarkerElement, element.get() );
}

static JSDOMWrapper *createSVGMaskElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGMaskElement, element.get() );
}

static JSDOMWrapper *createSVGMetadataElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGMetadataElement, element.get() );
}

static JSDOMWrapper *createSVGMissingGlyphElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGMissingGlyphElement, element.get() );
}

static JSDOMWrapper *createSVGPathElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGPathElement, element.get() );
}

static JSDOMWrapper *createSVGPatternElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGPatternElement, element.get() );
}

static JSDOMWrapper *createSVGPolygonElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGPolygonElement, element.get() );
}

static JSDOMWrapper *createSVGPolylineElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGPolylineElement, element.get() );
}

static JSDOMWrapper *createSVGRadialGradientElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGRadialGradientElement, element.get() );
}

static JSDOMWrapper *createSVGRectElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGRectElement, element.get() );
}

static JSDOMWrapper *createSVGScriptElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGScriptElement, element.get() );
}

static JSDOMWrapper *createSVGSetElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGSetElement, element.get() );
}

static JSDOMWrapper *createSVGStopElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGStopElement, element.get() );
}

static JSDOMWrapper *createSVGStyleElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGStyleElement, element.get() );
}

static JSDOMWrapper *createSVGSVGElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGSVGElement, element.get() );
}

static JSDOMWrapper *createSVGSwitchElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGSwitchElement, element.get() );
}

static JSDOMWrapper *createSVGSymbolElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGSymbolElement, element.get() );
}

static JSDOMWrapper *createSVGTextElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGTextElement, element.get() );
}

static JSDOMWrapper *createSVGTextPathElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGTextPathElement, element.get() );
}

static JSDOMWrapper *createSVGTitleElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGTitleElement, element.get() );
}

static JSDOMWrapper *createSVGTRefElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGTRefElement, element.get() );
}

static JSDOMWrapper *createSVGTSpanElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGTSpanElement, element.get() );
}

static JSDOMWrapper *createSVGUseElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGUseElement, element.get() );
}

static JSDOMWrapper *createSVGViewElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGViewElement, element.get() );
}

static JSDOMWrapper *createSVGVKernElementWrapper( ExecState *exec, JSDOMGlobalObject *globalObject,
        PassRefPtr<SVGElement> element )
{
    return CREATE_DOM_WRAPPER( exec, globalObject, SVGVKernElement, element.get() );
}

JSDOMWrapper *createJSSVGWrapper( ExecState *exec, JSDOMGlobalObject *globalObject, PassRefPtr<SVGElement> element )
{
    typedef HashMap<WTF::AtomicStringImpl *, CreateSVGElementWrapperFunction> FunctionMap;
    DEFINE_STATIC_LOCAL( FunctionMap, map, () );

    if ( map.isEmpty() )
    {
        map.set( aTag.localName().impl(), createSVGAElementWrapper );
        map.set( altGlyphTag.localName().impl(), createSVGAltGlyphElementWrapper );
        map.set( animateTag.localName().impl(), createSVGAnimateElementWrapper );
        map.set( animateColorTag.localName().impl(), createSVGAnimateColorElementWrapper );
        map.set( animateTransformTag.localName().impl(), createSVGAnimateTransformElementWrapper );
        map.set( circleTag.localName().impl(), createSVGCircleElementWrapper );
        map.set( clipPathTag.localName().impl(), createSVGClipPathElementWrapper );
        map.set( cursorTag.localName().impl(), createSVGCursorElementWrapper );
        map.set( defsTag.localName().impl(), createSVGDefsElementWrapper );
        map.set( descTag.localName().impl(), createSVGDescElementWrapper );
        map.set( ellipseTag.localName().impl(), createSVGEllipseElementWrapper );
        map.set( feBlendTag.localName().impl(), createSVGFEBlendElementWrapper );
        map.set( feColorMatrixTag.localName().impl(), createSVGFEColorMatrixElementWrapper );
        map.set( feComponentTransferTag.localName().impl(), createSVGFEComponentTransferElementWrapper );
        map.set( feCompositeTag.localName().impl(), createSVGFECompositeElementWrapper );
        map.set( feConvolveMatrixTag.localName().impl(), createSVGFEConvolveMatrixElementWrapper );
        map.set( feDiffuseLightingTag.localName().impl(), createSVGFEDiffuseLightingElementWrapper );
        map.set( feDisplacementMapTag.localName().impl(), createSVGFEDisplacementMapElementWrapper );
        map.set( feDistantLightTag.localName().impl(), createSVGFEDistantLightElementWrapper );
        map.set( feDropShadowTag.localName().impl(), createSVGFEDropShadowElementWrapper );
        map.set( feFloodTag.localName().impl(), createSVGFEFloodElementWrapper );
        map.set( feFuncATag.localName().impl(), createSVGFEFuncAElementWrapper );
        map.set( feFuncBTag.localName().impl(), createSVGFEFuncBElementWrapper );
        map.set( feFuncGTag.localName().impl(), createSVGFEFuncGElementWrapper );
        map.set( feFuncRTag.localName().impl(), createSVGFEFuncRElementWrapper );
        map.set( feGaussianBlurTag.localName().impl(), createSVGFEGaussianBlurElementWrapper );
        map.set( feImageTag.localName().impl(), createSVGFEImageElementWrapper );
        map.set( feMergeTag.localName().impl(), createSVGFEMergeElementWrapper );
        map.set( feMergeNodeTag.localName().impl(), createSVGFEMergeNodeElementWrapper );
        map.set( feMorphologyTag.localName().impl(), createSVGFEMorphologyElementWrapper );
        map.set( feOffsetTag.localName().impl(), createSVGFEOffsetElementWrapper );
        map.set( fePointLightTag.localName().impl(), createSVGFEPointLightElementWrapper );
        map.set( feSpecularLightingTag.localName().impl(), createSVGFESpecularLightingElementWrapper );
        map.set( feSpotLightTag.localName().impl(), createSVGFESpotLightElementWrapper );
        map.set( feTileTag.localName().impl(), createSVGFETileElementWrapper );
        map.set( feTurbulenceTag.localName().impl(), createSVGFETurbulenceElementWrapper );
        map.set( filterTag.localName().impl(), createSVGFilterElementWrapper );
        map.set( fontTag.localName().impl(), createSVGFontElementWrapper );
        map.set( font_faceTag.localName().impl(), createSVGFontFaceElementWrapper );
        map.set( font_face_formatTag.localName().impl(), createSVGFontFaceFormatElementWrapper );
        map.set( font_face_nameTag.localName().impl(), createSVGFontFaceNameElementWrapper );
        map.set( font_face_srcTag.localName().impl(), createSVGFontFaceSrcElementWrapper );
        map.set( font_face_uriTag.localName().impl(), createSVGFontFaceUriElementWrapper );
        map.set( foreignObjectTag.localName().impl(), createSVGForeignObjectElementWrapper );
        map.set( gTag.localName().impl(), createSVGGElementWrapper );
        map.set( glyphTag.localName().impl(), createSVGGlyphElementWrapper );
        map.set( imageTag.localName().impl(), createSVGImageElementWrapper );
        map.set( lineTag.localName().impl(), createSVGLineElementWrapper );
        map.set( linearGradientTag.localName().impl(), createSVGLinearGradientElementWrapper );
        map.set( markerTag.localName().impl(), createSVGMarkerElementWrapper );
        map.set( maskTag.localName().impl(), createSVGMaskElementWrapper );
        map.set( metadataTag.localName().impl(), createSVGMetadataElementWrapper );
        map.set( missing_glyphTag.localName().impl(), createSVGMissingGlyphElementWrapper );
        map.set( pathTag.localName().impl(), createSVGPathElementWrapper );
        map.set( patternTag.localName().impl(), createSVGPatternElementWrapper );
        map.set( polygonTag.localName().impl(), createSVGPolygonElementWrapper );
        map.set( polylineTag.localName().impl(), createSVGPolylineElementWrapper );
        map.set( radialGradientTag.localName().impl(), createSVGRadialGradientElementWrapper );
        map.set( rectTag.localName().impl(), createSVGRectElementWrapper );
        map.set( scriptTag.localName().impl(), createSVGScriptElementWrapper );
        map.set( setTag.localName().impl(), createSVGSetElementWrapper );
        map.set( stopTag.localName().impl(), createSVGStopElementWrapper );
        map.set( styleTag.localName().impl(), createSVGStyleElementWrapper );
        map.set( svgTag.localName().impl(), createSVGSVGElementWrapper );
        map.set( switchTag.localName().impl(), createSVGSwitchElementWrapper );
        map.set( symbolTag.localName().impl(), createSVGSymbolElementWrapper );
        map.set( textTag.localName().impl(), createSVGTextElementWrapper );
        map.set( textPathTag.localName().impl(), createSVGTextPathElementWrapper );
        map.set( titleTag.localName().impl(), createSVGTitleElementWrapper );
        map.set( trefTag.localName().impl(), createSVGTRefElementWrapper );
        map.set( tspanTag.localName().impl(), createSVGTSpanElementWrapper );
        map.set( useTag.localName().impl(), createSVGUseElementWrapper );
        map.set( viewTag.localName().impl(), createSVGViewElementWrapper );
        map.set( vkernTag.localName().impl(), createSVGVKernElementWrapper );
    }

    CreateSVGElementWrapperFunction createWrapperFunction = map.get( element->localName().impl() );

    if ( createWrapperFunction )
    {
        return createWrapperFunction( exec, globalObject, element );
    }

    return CREATE_DOM_WRAPPER( exec, globalObject, SVGElement, element.get() );
}

}

#endif
