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

#include <qvariantanimation.h>
#include <qvariantanimation_p.h>

#ifndef QT_NO_ANIMATION

#include <qcolor.h>
#include <qquaternion.h>
#include <qvector2d.h>
#include <qvector3d.h>
#include <qvector4d.h>

template <>
inline QColor lscs_genericFormula( const QColor &from, const QColor &to, double progress )
{
    return QColor( qBound( 0, lscs_genericFormula( from.red(),   to.red(),   progress ), 255 ),
                   qBound( 0, lscs_genericFormula( from.green(), to.green(), progress ), 255 ),
                   qBound( 0, lscs_genericFormula( from.blue(),  to.blue(),  progress ), 255 ),
                   qBound( 0, lscs_genericFormula( from.alpha(), to.alpha(), progress ), 255 ) );
}

template <>
inline QQuaternion lscs_genericFormula( const QQuaternion &from, const QQuaternion &to, double progress )
{
    return QQuaternion::slerp( from, to, progress );
}

void lscs_addGuiFormulas()
{
    QVariantAnimation::lscs_addCustomType<QColor>( lscs_variantFormula<QColor> );
    QVariantAnimation::lscs_addCustomType<QVector2D>( lscs_variantFormula<QVector2D> );
    QVariantAnimation::lscs_addCustomType<QVector3D>( lscs_variantFormula<QVector3D> );
    QVariantAnimation::lscs_addCustomType<QVector4D>( lscs_variantFormula<QVector4D> );
    QVariantAnimation::lscs_addCustomType<QQuaternion>( lscs_variantFormula<QQuaternion> );
}

#endif
