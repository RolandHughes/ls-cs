/*
 * Copyright (C) 2004, 2005, 2006 Apple Computer, Inc.  All rights reserved.
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

#ifndef GraphicsTypes_h
#define GraphicsTypes_h

#include <wtf/Forward.h>

namespace WebCore
{

// Note: These constants exactly match the NSCompositeOperator constants of
// AppKit on Mac OS X Tiger. If these ever change, we'll need to change the
// Mac OS X Tiger platform code to map one to the other.
enum CompositeOperator
{
    CompositeClear,
    CompositeCopy,
    CompositeSourceOver,
    CompositeSourceIn,
    CompositeSourceOut,
    CompositeSourceAtop,
    CompositeDestinationOver,
    CompositeDestinationIn,
    CompositeDestinationOut,
    CompositeDestinationAtop,
    CompositeXOR,
    CompositePlusDarker,
    CompositeHighlight,
    CompositePlusLighter
};

// FIXME: Currently these constants have to match the values used in the SVG
// DOM API. That's a mistake. We need to make cut that dependency.
enum GradientSpreadMethod
{
    SpreadMethodPad = 1,
    SpreadMethodReflect = 2,
    SpreadMethodRepeat = 3
};

enum LineCap { ButtCap, RoundCap, SquareCap };

enum LineJoin { MiterJoin, RoundJoin, BevelJoin };

enum HorizontalAlignment { AlignLeft, AlignRight, AlignHCenter };

enum TextBaseline { AlphabeticTextBaseline, TopTextBaseline, MiddleTextBaseline, BottomTextBaseline, IdeographicTextBaseline, HangingTextBaseline };

enum TextAlign { StartTextAlign, EndTextAlign, LeftTextAlign, CenterTextAlign, RightTextAlign };

String compositeOperatorName( CompositeOperator );
bool parseCompositeOperator( const String &, CompositeOperator & );

String lineCapName( LineCap );
bool parseLineCap( const String &, LineCap & );

String lineJoinName( LineJoin );
bool parseLineJoin( const String &, LineJoin & );

String textAlignName( TextAlign );
bool parseTextAlign( const String &, TextAlign & );

String textBaselineName( TextBaseline );
bool parseTextBaseline( const String &, TextBaseline & );

} // namespace WebCore

#endif
