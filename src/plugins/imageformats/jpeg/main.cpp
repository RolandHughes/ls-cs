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

#include <qimageiohandler.h>
#include <qstringlist.h>

#ifndef LSCS_NO_IMAGEFORMATPLUGIN

#ifdef LSCS_NO_IMAGEFORMAT_JPEG
#undef LSCS_NO_IMAGEFORMAT_JPEG
#endif

#include <qjpeghandler_p.h>

class QJpegPlugin : public QImageIOPlugin
{
    LSCS_OBJECT( QJpegPlugin )

    LSCS_PLUGIN_IID( QImageIOHandlerInterface_ID )
    LSCS_PLUGIN_KEY( "jpeg, jpg" )

public:
    QStringList keys() const;
    Capabilities capabilities( QIODevice *device, const QByteArray &format ) const;
    QImageIOHandler *create( QIODevice *device, const QByteArray &format = QByteArray() ) const;
};

LSCS_PLUGIN_REGISTER( QJpegPlugin )

QStringList QJpegPlugin::keys() const
{
    return QStringList() << "jpeg" << "jpg";
}

QImageIOPlugin::Capabilities QJpegPlugin::capabilities( QIODevice *device, const QByteArray &format ) const
{
    if ( format == "jpeg" || format == "jpg" )
    {
        return Capabilities( CanRead | CanWrite );
    }

    if ( !format.isEmpty() )
    {
        return 0;
    }

    if ( !device->isOpen() )
    {
        return 0;
    }

    Capabilities cap;

    if ( device->isReadable() && QJpegHandler::canRead( device ) )
    {
        cap |= CanRead;
    }

    if ( device->isWritable() )
    {
        cap |= CanWrite;
    }

    return cap;
}

QImageIOHandler *QJpegPlugin::create( QIODevice *device, const QByteArray &format ) const
{
    QImageIOHandler *handler = new QJpegHandler;
    handler->setDevice( device );
    handler->setFormat( format );
    return handler;
}

#endif
