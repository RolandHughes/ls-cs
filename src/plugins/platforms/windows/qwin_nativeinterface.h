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

#ifndef QWINDOWSNATIVEINTERFACE_H
#define QWINDOWSNATIVEINTERFACE_H

#include <qfont.h>
#include <qplatform_nativeinterface.h>

class QWindowsNativeInterface : public QPlatformNativeInterface
{
    LSCS_OBJECT( QWindowsNativeInterface )

    LSCS_PROPERTY_READ( asyncExpose, asyncExpose )
    LSCS_PROPERTY_WRITE( asyncExpose, setAsyncExpose )

    LSCS_PROPERTY_READ( gpu, gpu )
    LSCS_PROPERTY_STORED( gpu, false )

public:
    using FP_Void = void( * )();

    void *nativeResourceForIntegration( const QByteArray &resource ) override;

#ifndef LSCS_NO_OPENGL
    void *nativeResourceForContext( const QByteArray &resource, QOpenGLContext *context ) override;
#endif

    void *nativeResourceForWindow( const QByteArray &resource, QWindow *window ) override;

    LSCS_INVOKABLE_METHOD_1( Public, void *createMessageWindow( const QString &classNameTemplate, const QString &windowName,
                           void *eventProc ) const )
    LSCS_INVOKABLE_METHOD_2( createMessageWindow )

    LSCS_INVOKABLE_METHOD_1( Public, QString registerWindowClass( const QString &classNameIn, void *eventProc ) const )
    LSCS_INVOKABLE_METHOD_2( registerWindowClass )

    LSCS_INVOKABLE_METHOD_1( Public, void beep() )
    LSCS_INVOKABLE_METHOD_2( beep )

    LSCS_INVOKABLE_METHOD_1( Public, void registerWindowsMime( void *mimeIn ) )
    LSCS_INVOKABLE_METHOD_2( registerWindowsMime )

    LSCS_INVOKABLE_METHOD_1( Public, void unregisterWindowsMime( void *mime ) )
    LSCS_INVOKABLE_METHOD_2( unregisterWindowsMime )

    LSCS_INVOKABLE_METHOD_1( Public, int registerMimeType( const QString &mimeType ) )
    LSCS_INVOKABLE_METHOD_2( registerMimeType )

    LSCS_INVOKABLE_METHOD_1( Public, QFont logFontToQFont( const void *logFont, int verticalDpi ) )
    LSCS_INVOKABLE_METHOD_2( logFontToQFont )

    bool asyncExpose() const;
    void setAsyncExpose( bool value );

    QVariant gpu() const;

    QVariantMap windowProperties( QPlatformWindow *window ) const override;
    QVariant windowProperty( QPlatformWindow *window, const QString &name ) const override;
    QVariant windowProperty( QPlatformWindow *window, const QString &name, const QVariant &defaultValue ) const override;
    void setWindowProperty( QPlatformWindow *window, const QString &name, const QVariant &value ) override;

    FP_Void platformFunction( const QByteArray &function ) const override;
};

#endif
