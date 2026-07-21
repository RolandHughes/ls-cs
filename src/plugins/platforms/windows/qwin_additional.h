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

#ifndef QTWINDOWS_ADDITIONAL_H
#define QTWINDOWS_ADDITIONAL_H

#include <qglobal.h>
#include <lscs_windows.h>

#ifndef WM_THEMECHANGED
#   define WM_THEMECHANGED 0x031A
#endif

#ifndef WM_DWMCOMPOSITIONCHANGED
#   define WM_DWMCOMPOSITIONCHANGED 0x31E
#endif

#ifndef GWL_HWNDPARENT
#   define GWL_HWNDPARENT (-8)
#endif

// other definitions and declarations missing
// when using MinGW or older Windows SDKs


#ifndef WM_TOUCH
#   define WM_TOUCH 0x0240
#endif

#ifndef WM_GESTURE
#  define WM_GESTURE 0x0119
#endif

#endif
