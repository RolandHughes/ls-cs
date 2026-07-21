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

#ifndef QMEMROTATE_P_H
#define QMEMROTATE_P_H

#include <qdrawhelper_p.h>

#define LSCS_ROTATION_CACHEDREAD 1
#define LSCS_ROTATION_CACHEDWRITE 2
#define LSCS_ROTATION_PACKING 3
#define LSCS_ROTATION_TILED 4

#ifndef LSCS_ROTATION_ALGORITHM

#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
#define LSCS_ROTATION_ALGORITHM LSCS_ROTATION_TILED
#else
#define LSCS_ROTATION_ALGORITHM LSCS_ROTATION_CACHEDREAD
#endif

#endif

#define LSCS_DECL_MEMROTATE(type)                            \
    void Q_GUI_EXPORT lscs_memrotate90(const type*, int, int, int, type*, int); \
    void Q_GUI_EXPORT lscs_memrotate180(const type*, int, int, int, type*, int); \
    void Q_GUI_EXPORT lscs_memrotate270(const type*, int, int, int, type*, int)

LSCS_DECL_MEMROTATE( quint32 );
LSCS_DECL_MEMROTATE( quint16 );
LSCS_DECL_MEMROTATE( quint24 );
LSCS_DECL_MEMROTATE( quint8 );

#undef LSCS_DECL_MEMROTATE

#endif
