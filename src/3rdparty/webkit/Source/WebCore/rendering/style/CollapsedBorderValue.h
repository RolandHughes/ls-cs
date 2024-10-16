/*
 * Copyright (C) 2000 Lars Knoll (knoll@kde.org)
 *           (C) 2000 Antti Koivisto (koivisto@kde.org)
 *           (C) 2000 Dirk Mueller (mueller@kde.org)
 * Copyright (C) 2003, 2005, 2006, 2007, 2008 Apple Inc. All rights reserved.
 * Copyright (C) 2006 Graham Dennis (graham.dennis@gmail.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef CollapsedBorderValue_h
#define CollapsedBorderValue_h

#include "BorderValue.h"

namespace WebCore
{

class CollapsedBorderValue
{
    friend class RenderStyle;
public:
    CollapsedBorderValue()
        : m_border( 0 )
        , m_precedence( BOFF )
    {
    }

    CollapsedBorderValue( const BorderValue *b, Color c, EBorderPrecedence p )
        : m_border( b )
        , m_borderColor( c )
        , m_precedence( p )
    {
    }

    int width() const
    {
        return m_border && m_border->nonZero() ? m_border->width() : 0;
    }
    EBorderStyle style() const
    {
        return m_border ? m_border->style() : BHIDDEN;
    }
    bool exists() const
    {
        return m_border;
    }
    const Color &color() const
    {
        return m_borderColor;
    }
    bool isTransparent() const
    {
        return m_border ? m_border->isTransparent() : true;
    }
    EBorderPrecedence precedence() const
    {
        return m_precedence;
    }

    bool operator==( const CollapsedBorderValue &o ) const
    {
        if ( !m_border )
        {
            return !o.m_border;
        }

        if ( !o.m_border )
        {
            return false;
        }

        return *m_border == *o.m_border && m_borderColor == o.m_borderColor && m_precedence == o.m_precedence;
    }

private:
    const BorderValue *m_border;
    Color m_borderColor;
    EBorderPrecedence m_precedence;
};

} // namespace WebCore

#endif // CollapsedBorderValue_h
