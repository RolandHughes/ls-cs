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

#ifndef QNUMERIC_P_H
#define QNUMERIC_P_H

#include <qglobal.h>

#if ! defined(Q_CC_MIPS)

static const union
{
    unsigned char c[8];
    double d;
} lscs_be_inf_bytes = { { 0x7f, 0xf0, 0, 0, 0, 0, 0, 0 } };

static const union
{
    unsigned char c[8];
    double d;
} lscs_le_inf_bytes = { { 0, 0, 0, 0, 0, 0, 0xf0, 0x7f } };

static const union
{
    unsigned char c[8];
    double d;
} lscs_armfpa_inf_bytes = { { 0, 0, 0xf0, 0x7f, 0, 0, 0, 0 } };

static inline double lscs_inf()
{
#ifdef LSCS_ARMFPA
    return lscs_armfpa_inf_bytes.d;

#else
    return ( QSysInfo::ByteOrder == QSysInfo::BigEndian
             ? lscs_be_inf_bytes.d : lscs_le_inf_bytes.d );
#endif
}

// Signaling NAN
static const union
{
    unsigned char c[8];
    double d;
} lscs_be_snan_bytes = { { 0x7f, 0xf8, 0, 0, 0, 0, 0, 0 } };

static const union
{
    unsigned char c[8];
    double d;
} lscs_le_snan_bytes = { { 0, 0, 0, 0, 0, 0, 0xf8, 0x7f } };

static const union
{
    unsigned char c[8];
    double d;
} lscs_armfpa_snan_bytes = { { 0, 0, 0xf8, 0x7f, 0, 0, 0, 0 } };

static inline double lscs_snan()
{
#ifdef LSCS_ARMFPA
    return lscs_armfpa_snan_bytes.d;
#else
    return ( QSysInfo::ByteOrder == QSysInfo::BigEndian
             ? lscs_be_snan_bytes.d : lscs_le_snan_bytes.d );
#endif
}

// Quiet NAN
static const union
{
    unsigned char c[8];
    double d;
} lscs_be_qnan_bytes = { { 0xff, 0xf8, 0, 0, 0, 0, 0, 0 } };

static const union
{
    unsigned char c[8];
    double d;
} lscs_le_qnan_bytes = { { 0, 0, 0, 0, 0, 0, 0xf8, 0xff } };

static const union
{
    unsigned char c[8];
    double d;
} lscs_armfpa_qnan_bytes = { { 0, 0, 0xf8, 0xff, 0, 0, 0, 0 } };

static inline double lscs_qnan()
{
#ifdef LSCS_ARMFPA
    return lscs_armfpa_qnan_bytes.d;
#else
    return ( QSysInfo::ByteOrder == QSysInfo::BigEndian
             ? lscs_be_qnan_bytes.d : lscs_le_qnan_bytes.d );
#endif
}

#else // Q_CC_MIPS

static const unsigned char lscs_be_inf_bytes[] = { 0x7f, 0xf0, 0, 0, 0, 0, 0, 0 };
static const unsigned char lscs_le_inf_bytes[] = { 0, 0, 0, 0, 0, 0, 0xf0, 0x7f };
static const unsigned char lscs_armfpa_inf_bytes[] = { 0, 0, 0xf0, 0x7f, 0, 0, 0, 0 };

static inline double lscs_inf()
{
    const unsigned char *bytes;

#ifdef LSCS_ARMFPA
    bytes = lscs_armfpa_inf_bytes;
#else
    bytes = ( QSysInfo::ByteOrder == QSysInfo::BigEndian
              ? lscs_be_inf_bytes : lscs_le_inf_bytes );
#endif

    union
    {
        unsigned char c[8];
        double d;
    } returnValue;

    memcpy( returnValue.c, bytes, sizeof( returnValue.c ) );

    return returnValue.d;
}

// Signaling NAN
static const unsigned char lscs_be_snan_bytes[] = { 0x7f, 0xf8, 0, 0, 0, 0, 0, 0 };
static const unsigned char lscs_le_snan_bytes[] = { 0, 0, 0, 0, 0, 0, 0xf8, 0x7f };
static const unsigned char lscs_armfpa_snan_bytes[] = { 0, 0, 0xf8, 0x7f, 0, 0, 0, 0 };

static inline double lscs_snan()
{
    const unsigned char *bytes;
#ifdef LSCS_ARMFPA
    bytes = lscs_armfpa_snan_bytes;
#else
    bytes = ( QSysInfo::ByteOrder == QSysInfo::BigEndian
              ? lscs_be_snan_bytes : lscs_le_snan_bytes );
#endif

    union
    {
        unsigned char c[8];
        double d;
    } returnValue;

    memcpy( returnValue.c, bytes, sizeof( returnValue.c ) );

    return returnValue.d;
}

// Quiet NAN
static const unsigned char lscs_be_qnan_bytes[] = { 0xff, 0xf8, 0, 0, 0, 0, 0, 0 };
static const unsigned char lscs_le_qnan_bytes[] = { 0, 0, 0, 0, 0, 0, 0xf8, 0xff };
static const unsigned char lscs_armfpa_qnan_bytes[] = { 0, 0, 0xf8, 0xff, 0, 0, 0, 0 };
static inline double lscs_qnan()
{
    const unsigned char *bytes;
#ifdef LSCS_ARMFPA
    bytes = lscs_armfpa_qnan_bytes;
#else
    bytes = ( QSysInfo::ByteOrder == QSysInfo::BigEndian
              ? lscs_be_qnan_bytes : lscs_le_qnan_bytes );
#endif

    union
    {
        unsigned char c[8];
        double d;
    } returnValue;

    memcpy( returnValue.c, bytes, sizeof( returnValue.c ) );

    return returnValue.d;
}

#endif // Q_CC_MIPS

static inline bool lscs_is_inf( double d )
{
    uchar *ch = ( uchar * )&d;

#ifdef LSCS_ARMFPA
    return ( ch[3] & 0x7f ) == 0x7f && ch[2] == 0xf0;
#else

    if constexpr ( QSysInfo::ByteOrder == QSysInfo::BigEndian )
    {
        return ( ch[0] & 0x7f ) == 0x7f && ch[1] == 0xf0;
    }
    else
    {
        return ( ch[7] & 0x7f ) == 0x7f && ch[6] == 0xf0;
    }

#endif
}

static inline bool lscs_is_nan( double d )
{
    uchar *ch = ( uchar * )&d;

#ifdef LSCS_ARMFPA
    return ( ch[3] & 0x7f ) == 0x7f && ch[2] > 0xf0;
#else

    if constexpr ( QSysInfo::ByteOrder == QSysInfo::BigEndian )
    {
        return ( ch[0] & 0x7f ) == 0x7f && ch[1] > 0xf0;
    }
    else
    {
        return ( ch[7] & 0x7f ) == 0x7f && ch[6] > 0xf0;
    }

#endif
}

static inline bool lscs_is_finite( double d )
{
    uchar *ch = ( uchar * )&d;

#ifdef LSCS_ARMFPA
    return ( ch[3] & 0x7f ) != 0x7f || ( ch[2] & 0xf0 ) != 0xf0;
#else

    if constexpr ( QSysInfo::ByteOrder == QSysInfo::BigEndian )
    {
        return ( ch[0] & 0x7f ) != 0x7f || ( ch[1] & 0xf0 ) != 0xf0;
    }
    else
    {
        return ( ch[7] & 0x7f ) != 0x7f || ( ch[6] & 0xf0 ) != 0xf0;
    }

#endif
}

static inline bool lscs_is_inf( float d )
{
    uchar *ch = ( uchar * )&d;

    if constexpr ( QSysInfo::ByteOrder == QSysInfo::BigEndian )
    {
        return ( ch[0] & 0x7f ) == 0x7f && ch[1] == 0x80;
    }
    else
    {
        return ( ch[3] & 0x7f ) == 0x7f && ch[2] == 0x80;
    }
}

static inline bool lscs_is_nan( float d )
{
    uchar *ch = ( uchar * )&d;

    if constexpr ( QSysInfo::ByteOrder == QSysInfo::BigEndian )
    {
        return ( ch[0] & 0x7f ) == 0x7f && ch[1] > 0x80;
    }
    else
    {
        return ( ch[3] & 0x7f ) == 0x7f && ch[2] > 0x80;
    }
}

static inline bool lscs_is_finite( float d )
{
    uchar *ch = ( uchar * )&d;

    if constexpr ( QSysInfo::ByteOrder == QSysInfo::BigEndian )
    {
        return ( ch[0] & 0x7f ) != 0x7f || ( ch[1] & 0x80 ) != 0x80;
    }
    else
    {
        return ( ch[3] & 0x7f ) != 0x7f || ( ch[2] & 0x80 ) != 0x80;
    }
}

#endif
