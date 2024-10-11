/***********************************************************************
*
* Copyright (c) 2012-2024 Barbara Geller
* Copyright (c) 2012-2024 Ansel Sermersheim
*
* Copyright (c) 2015 The Qt Company Ltd.
* Copyright (c) 2012-2016 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
*
* This file is part of CopperSpice.
*
* CopperSpice is free software. You can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://www.gnu.org/licenses/
*
***********************************************************************/

#define LSCS_CARBON_MM
#include <lscs_carbon_wrapper_p.h>
#undef  LSCS_CARBON_MM

#include <Carbon/Carbon.h>

#ifdef __OBJC__
#include <AppKit/AppKit.h>

typedef NSWindow *OSWindowRef;
typedef NSView   *OSViewRef;
typedef NSMenu   *OSMenuRef;
typedef NSEvent  *OSEventRef;

#else
typedef void *OSWindowRef;
typedef void *OSViewRef;
typedef void *OSMenuRef;
typedef void *OSEventRef;

#endif

bool documentMode;

LSCS_FontUIFontType LSCS_HIThemeGetUIFontType(ThemeFontID themeID)
{
   return LSCS_FontUIFontType(HIThemeGetUIFontType(themeID));
}

CTFontRef LSCS_CTFontCreateUIFontForLanguage(LSCS_FontUIFontType uiType, CGFloat size, CFStringRef language )
{
  return CTFontCreateUIFontForLanguage(CTFontUIFontType(uiType), size, language);
}

void LSCS_HIThemeBrushCreateCGColor(ThemeBrush brush, CGColorRef *cgClr)
{
   HIThemeBrushCreateCGColor(brush, cgClr);
}

void LSCS_EnableSecureEventInput()
{
   EnableSecureEventInput();
}

void LSCS_DisableSecureEventInput()
{
   DisableSecureEventInput();
}

OSStatus LSCS_GetEventParameter(EventRef event, EventParamName eventName, EventParamType eventType,
                              EventParamType *eventTypePtr,
                              ByteCount bufferSize, ByteCount *actualSize, void *data)
{
   return GetEventParameter(event, eventName, eventType, eventTypePtr, bufferSize, actualSize, data);
}

OSType LSCS_GetEventKind(EventRef event)
{
   return GetEventKind(event);
}

OSType LSCS_GetEventClass(EventRef event)
{
   return GetEventClass(event);
}

EventTime LSCS_GetCurrentEventTime()
{
   return GetCurrentEventTime();
}

EventTime LSCS_GetEventTime(EventRef event)
{
   return GetEventTime(event);
}

UInt32 LSCS_GetCurrentKeyModifiers()
{
   return GetCurrentKeyModifiers();
}

UInt32 LSCS_GetCurrentEventKeyModifiers()
{
   return GetCurrentEventKeyModifiers();
}

EventQueueRef LSCS_GetMainEventQueue()
{
   return GetMainEventQueue();
}

EventLoopRef LSCS_GetMainEventLoop()
{
   return GetMainEventLoop();
}

EventTargetRef LSCS_GetEventMonitorTarget()
{
   return GetEventMonitorTarget();
}

UInt32 LSCS_GetCurrentEventButtonState()
{
   return GetCurrentEventButtonState();
}

ItemCount LSCS_GetNumEventsInQueue(EventQueueRef eventQueue)
{
   return GetNumEventsInQueue(eventQueue);
}

OSStatus LSCS_GetThemeMetric(ThemeMetric metric, SInt32 *callBack)
{
   return GetThemeMetric(metric, callBack);
}

OSStatus LSCS_RemoveEventHandler(EventHandlerRef event)
{
   return RemoveEventHandler(event);
}

OSStatus LSCS_PostEventToQueue(EventQueueRef eventQueue, EventRef event, EventPriority priority)
{
   return PostEventToQueue(eventQueue, event, priority);
}

OSStatus LSCS_RemoveEventFromQueue(EventQueueRef eventQueue, EventRef event)
{
   return RemoveEventFromQueue(eventQueue, event);
}

EventRef LSCS_RetainEvent(EventRef keydownEvent)
{
   return RetainEvent(keydownEvent);
}

void LSCS_ReleaseEvent(EventRef keydownEvent)
{
   ReleaseEvent(keydownEvent);
}

SInt16 LSCS_LMGetKbdType()
{
   return LMGetKbdType();
}

TISInputSourceRef LSCS_TISCopyCurrentKeyboardInputSource()
{
   return TISCopyCurrentKeyboardInputSource();
}

void *LSCS_TISGetInputSourceProperty(TISInputSourceRef source, CFStringRef string)
{
   return TISGetInputSourceProperty(source, string);
}

EventRef LSCS_FindSpecificEventInQueue(EventQueueRef eventQ, EventComparatorUPP callBack, void *data)
{
   return FindSpecificEventInQueue(eventQ, callBack, data);
}

OSAError LSCS_OSACompile(ComponentInstance component, const AEDesc *sourceData, SInt32 key, OSAID *id)
{
   return OSACompile(component, sourceData, key, id);
}

OSAError LSCS_OSAExecute(ComponentInstance component, OSAID id1, OSAID id2, SInt32 key, OSAID *id3)
{
   return OSAExecute(component, id1, id2, key, id3);
}

OSAError LSCS_OSAScriptError(ComponentInstance component, OSType type, DescType descType, AEDesc *sourceData)
{
   return OSAScriptError(component, type, descType, sourceData);
}

OSAError LSCS_OSADisplay(ComponentInstance component, OSAID id, DescType descType, SInt32 key, AEDesc *sourceData)
{
   return OSADisplay(component, id, descType, key, sourceData);
}

OSAError LSCS_OSADispose(ComponentInstance component, OSAID id)
{
   return OSADispose(component, id);
}

OSStatus LSCS_RemoveEventLoopTimer(EventLoopTimerRef timer)
{
   return RemoveEventLoopTimer(timer);
}

EventLoopTimerUPP LSCS_NewEventLoopTimerUPP(EventLoopTimerProcPtr callBack)
{
   return NewEventLoopTimerUPP(callBack);
}

EventHandlerUPP LSCS_NewEventHandlerUPP(EventHandlerProcPtr callBack)
{
   return NewEventHandlerUPP(callBack);
}

OSStatus LSCS_CreateEvent(CFAllocatorRef allocator, UInt32 id, UInt32 kind, EventTime time, EventAttributes flags,
                        EventRef *event)
{
   return CreateEvent(allocator, id, kind, time, flags, event);
}

OSStatus LSCS_InstallEventLoopTimer(EventLoopRef eventLopp, EventTimerInterval delay, EventTimerInterval interval,
                                  EventLoopTimerUPP callBack, void *data, EventLoopTimerRef *timer)
{
   return InstallEventLoopTimer(eventLopp, delay, interval, callBack, data, timer);
}

OSStatus LSCS_InstallEventHandler(EventTargetRef target, EventHandlerUPP handler, ItemCount numTypes,
                                const EventTypeSpec *list,
                                void *data, EventHandlerRef *ref)
{
   return InstallEventHandler(target, handler, numTypes, list, data, ref);
}

void LSCS_DisposeEventHandlerUPP(EventHandlerUPP userUPP)
{
   DisposeEventHandlerUPP(userUPP);
}

OSStatus LSCS_SetSystemUIMode(SystemUIMode mode, SystemUIOptions options)
{
   return SetSystemUIMode(mode, options);
}

OSStatus LSCS_HIThemeGetGrowBoxBounds(const HIPoint *origin, const HIThemeGrowBoxDrawInfo *drawInfo, HIRect *outBounds)
{
   return HIThemeGetGrowBoxBounds(origin, drawInfo, outBounds);
}

OSStatus LSCS_HIThemeGetButtonContentBounds(const HIRect *inBounds, const HIThemeButtonDrawInfo *drawInfo,
      HIRect *outBounds)
{
   return HIThemeGetButtonContentBounds(inBounds, drawInfo, outBounds);
}

OSStatus LSCS_HIThemeDrawButton(const HIRect *inBounds, const HIThemeButtonDrawInfo *inDrawInfo, CGContextRef inContext,
                              HIThemeOrientation inOrientation, HIRect *outLabelRect)
{
   return HIThemeDrawButton(inBounds, inDrawInfo, inContext, inOrientation, outLabelRect);
}

OSStatus LSCS_HIThemeSetFill(ThemeBrush brush, void *info, CGContextRef context, HIThemeOrientation orientation)
{
   return HIThemeSetFill(brush, info, context, orientation);
}

OSStatus LSCS_HIThemeDrawMenuBackground(const HIRect *rect, const HIThemeMenuDrawInfo *info, CGContextRef context,
                                      HIThemeOrientation orientation)
{
   return HIThemeDrawMenuBackground(rect, info, context, orientation);
}

OSStatus LSCS_HIThemeGetMenuBackgroundShape(const HIRect *menuRect, const HIThemeMenuDrawInfo *mdi, HIShapeRef *shape)
{
   return HIThemeGetMenuBackgroundShape(menuRect, mdi, shape);
}

OSStatus LSCS_HIThemeDrawGroupBox(const HIRect *hirect, const HIThemeGroupBoxDrawInfo *drawInfo, CGContextRef context,
                                HIThemeOrientation orientation)
{
   return HIThemeDrawGroupBox(hirect, drawInfo, context, orientation);
}

OSStatus LSCS_CopyThemeIdentifier(CFStringRef *theme)
{
   return CopyThemeIdentifier(theme);
}

OSStatus LSCS_HIThemeDrawFrame(const HIRect *hirect, const HIThemeFrameDrawInfo *drawInfo, CGContextRef context,
                  HIThemeOrientation orientation)
{
   return HIThemeDrawFrame(hirect, drawInfo, context, orientation);
}

OSStatus LSCS_HIThemeDrawPopupArrow(const HIRect *hirect, const HIThemePopupArrowDrawInfo *drawInfo, CGContextRef context,
                  HIThemeOrientation orientation)
{
   return HIThemeDrawPopupArrow(hirect, drawInfo, context, orientation);
}


OSStatus LSCS_HIThemeDrawSeparator(const HIRect *hirect, const HIThemeSeparatorDrawInfo *drawInfo, CGContextRef context,
                  HIThemeOrientation orientation)
{
   return HIThemeDrawSeparator(hirect, drawInfo, context, orientation);
}

OSStatus LSCS_HIThemeDrawTabPane(const HIRect *hirect, const HIThemeTabPaneDrawInfo *info, CGContextRef context,
                  HIThemeOrientation orientation)
{
   return HIThemeDrawTabPane(hirect, info, context, orientation);
}

OSStatus LSCS_HIThemeDrawTextBox(CFTypeRef text, const HIRect *hirect, HIThemeTextInfo *info, CGContextRef context,
                  HIThemeOrientation orientation)
{
   return HIThemeDrawTextBox(text, hirect, info, context, orientation);
}

OSStatus LSCS_HIThemeDrawTab(const HIRect *hirect, const HIThemeTabDrawInfo *info, CGContextRef context,
                           HIThemeOrientation orientation, HIRect *outRect)
{
   return HIThemeDrawTab(hirect, info, context, orientation, outRect);
}

OSStatus LSCS_HIThemeDrawWindowFrame(const HIRect *hirect, const HIThemeWindowDrawInfo *info, CGContextRef context,
                                   HIThemeOrientation orientation, HIRect *outRect)
{
   return HIThemeDrawWindowFrame(hirect, info, context, orientation, outRect);
}

OSStatus LSCS_HIThemeDrawFocusRect(const HIRect *hirect, unsigned char data, CGContextRef context,
                                 HIThemeOrientation orientation)
{
   return HIThemeDrawFocusRect(hirect, data, context, orientation);
}

OSStatus LSCS_HIThemeGetWindowShape(const HIRect *hirect, const HIThemeWindowDrawInfo *info, WindowRegionCode code,
                                  HIShapeRef *outShape)
{
   return HIThemeGetWindowShape(hirect, info, code, outShape);
}

OSStatus LSCS_HIThemeDrawMenuSeparator(const HIRect *hirect1, const HIRect *hirect2, const HIThemeMenuItemDrawInfo *info,
                                     CGContextRef context, HIThemeOrientation orientation)
{
   return HIThemeDrawMenuSeparator(hirect1, hirect2, info, context, orientation);
}

OSStatus LSCS_HIThemeDrawMenuItem(const HIRect *hirect1, const HIRect *hirect2, const HIThemeMenuItemDrawInfo *info,
                                CGContextRef context, HIThemeOrientation orientation, HIRect *outRect)
{
   return HIThemeDrawMenuItem(hirect1, hirect2, info, context, orientation, outRect);
}

OSStatus LSCS_HIThemeGetTextDimensions(CFTypeRef string, CGFloat width, HIThemeTextInfo *tti, CGFloat *outWidth,
                                     CGFloat *outHeight, CGFloat *outBaseline)
{
   return HIThemeGetTextDimensions(string, width, tti, outWidth, outHeight, outBaseline);
}

OSStatus LSCS_HIThemeDrawMenuBarBackground(const HIRect *hirect, const HIThemeMenuBarDrawInfo *bdi, CGContextRef context,
      HIThemeOrientation orientation)
{
   return HIThemeDrawMenuBarBackground(hirect, bdi, context, orientation);
}

OSStatus LSCS_HIThemeDrawTrack(const HIThemeTrackDrawInfo *tdi, const HIRect *hirect, CGContextRef context,
                             HIThemeOrientation orientation)
{
   return HIThemeDrawTrack(tdi, hirect, context, orientation);
}

OSStatus LSCS_HIThemeDrawGrowBox(const HIPoint *pt, const HIThemeGrowBoxDrawInfo *gdi, CGContextRef context,
                               HIThemeOrientation orientation)
{
   return HIThemeDrawGrowBox(pt, gdi, context, orientation);
}

OSStatus LSCS_HIThemeDrawPaneSplitter(const HIRect *hirect, const HIThemeSplitterDrawInfo *info, CGContextRef context,
                                    HIThemeOrientation orientation)
{
   return HIThemeDrawPaneSplitter(hirect, info, context, orientation);
}

OSStatus LSCS_HIThemeGetButtonShape(const HIRect *hirect, const HIThemeButtonDrawInfo *bdi, HIShapeRef *shape)
{
   return HIThemeGetButtonShape(hirect, bdi, shape);
}

OSStatus LSCS_HIThemeGetTrackThumbShape(const HIThemeTrackDrawInfo *tdi, HIShapeRef *shape)
{
   return HIThemeGetTrackThumbShape(tdi, shape);
}

OSStatus LSCS_HIThemeDrawTrackTickMarks(const HIThemeTrackDrawInfo *tdi, ItemCount numMarks, CGContextRef context,
                                      HIThemeOrientation orientation)
{
   return HIThemeDrawTrackTickMarks(tdi, numMarks, context, orientation);
}

OSStatus LSCS_HIThemeGetButtonBackgroundBounds(const HIRect *newRect, const HIThemeButtonDrawInfo *info, HIRect *outRect)
{
   return HIThemeGetButtonBackgroundBounds(newRect, info, outRect);
}

OSStatus LSCS_HIThemeDrawTitleBarWidget(const HIRect *titleBarRect, const HIThemeWindowWidgetDrawInfo *info,
                                      CGContextRef context,
                                      HIThemeOrientation orientation)
{
   return HIThemeDrawTitleBarWidget(titleBarRect, info, context, orientation);
}

OSStatus LSCS_HIThemeGetTrackBounds(const HIThemeTrackDrawInfo *info, HIRect *macRect)
{
   return HIThemeGetTrackBounds(info, macRect);
}

OSStatus LSCS_HIThemeGetTrackDragRect(const HIThemeTrackDrawInfo *info, HIRect *macRect)
{
   return HIThemeGetTrackDragRect(info, macRect);
}

unsigned char LSCS_HIThemeHitTestTrack(const HIThemeTrackDrawInfo *info, const HIPoint *point,
                                     ControlPartCode *outPartHit)
{
   return HIThemeHitTestTrack(info, point, outPartHit);
}

unsigned char LSCS_HIThemeHitTestScrollBarArrows(const HIRect *bounds, const HIScrollBarTrackInfo *info,
      unsigned char isHoriz,
      const HIPoint *point, HIRect *outBounds,  ControlPartCode *outPartCode)
{
   return HIThemeHitTestScrollBarArrows(bounds, info, isHoriz, point, outBounds, outPartCode);
}

OSStatus LSCS_HIThemeGetTrackPartBounds(const HIThemeTrackDrawInfo *info, ControlPartCode inPartCode,
                                      HIRect *outPartBounds)
{
   return HIThemeGetTrackPartBounds(info, inPartCode, outPartBounds);
}

OSStatus LSCS_GetThemeMenuSeparatorHeight(SInt16 *ash)
{
   return GetThemeMenuSeparatorHeight(ash);
}


// wrappers
void qt_mac_updateContentBorderMetrics(void * /*OSWindowRef */window, const ::HIContentBorderMetrics &metrics)
{
   OSWindowRef theWindow = static_cast<OSWindowRef>(window);

   if ([theWindow styleMask] & NSWindowStyleMaskTexturedBackground) {
      [theWindow setContentBorderThickness: metrics.top forEdge: NSMaxYEdge];
   }

   [theWindow setContentBorderThickness: metrics.bottom forEdge: NSMinYEdge];
}
