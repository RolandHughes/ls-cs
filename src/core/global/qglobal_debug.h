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

#ifndef QGLOBAL_DEBUG_H
#define QGLOBAL_DEBUG_H

#if defined(LSCS_DISABLE_DEBUG)
# undef  QT_DEBUG
#else
# define QT_DEBUG
#endif

// ** (1) uncomment or pass any of the following defines in the CS build files

// #define LSCS_SHOW_DEBUG_CORE
// #define LSCS_SHOW_DEBUG_CORE_OSX
// #define LSCS_SHOW_DEBUG_CORE_IO
// #define LSCS_SHOW_DEBUG_CORE_PLUGIN
// #define LSCS_SHOW_DEBUG_CORE_SEMAPHORE
// #define LSCS_SHOW_DEBUG_CORE_STATEMACHINE

// #define LSCS_SHOW_DEBUG_GUI
// #define LSCS_SHOW_DEBUG_GUI_DPI
// #define LSCS_SHOW_DEBUG_GUI_GRAPHICSVIEW
// #define LSCS_SHOW_DEBUG_GUI_IMAGE
// #define LSCS_SHOW_DEBUG_GUI_OPENGL
// #define LSCS_SHOW_DEBUG_GUI_PAINTING
// #define LSCS_SHOW_DEBUG_GUI_STYLES
// #define LSCS_SHOW_DEBUG_GUI_TEXT
// #define LSCS_SHOW_DEBUG_GUI_WIDGETS

// #define LSCS_SHOW_DEBUG_MULTIMEDIA
// #define LSCS_SHOW_DEBUG_NETWORK
// #define LSCS_SHOW_DEBUG_OPENGL

// #define LSCS_SHOW_DEBUG_PLATFORM
// #define LSCS_SHOW_DEBUG_PLATFORM_MEDIA
// #define LSCS_SHOW_DEBUG_PLATFORM_PASTEBOARD
// #define LSCS_SHOW_DEBUG_PLATFORM_WINDOW

// #define LSCS_SHOW_DEBUG_SQL
// #define LSCS_SHOW_DEBUG_SVG
// #define LSCS_SHOW_DEBUG_XML


// ** (2) uncomment or pass the following define in the CS build files

// #define LSCS_DISABLE_ASSERT

#endif


