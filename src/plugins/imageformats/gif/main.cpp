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

#ifdef LSCS_NO_IMAGEFORMAT_GIF
#undef LSCS_NO_IMAGEFORMAT_GIF
#endif
#include <qgifhandler_p.h>

class QGifPlugin : public QImageIOPlugin
{
    LSCS_OBJECT( QGifPlugin )

    LSCS_PLUGIN_IID( QImageIOHandlerInterface_ID )
    LSCS_PLUGIN_KEY( "gif" )

public:
    QGifPlugin();
    ~QGifPlugin();

    QStringList keys() const;
    Capabilities capabilities( QIODevice *device, const QByteArray &format ) const;
    QImageIOHandler *create( QIODevice *device, const QByteArray &format = QByteArray() ) const;
};

LSCS_PLUGIN_REGISTER( QGifPlugin )

QGifPlugin::QGifPlugin()
{
}

QGifPlugin::~QGifPlugin()
{
}

QStringList QGifPlugin::keys() const
{
    return QStringList() << "gif";
}

QImageIOPlugin::Capabilities QGifPlugin::capabilities( QIODevice *device, const QByteArray &format ) const
{
    if ( format == "gif" || ( device && device->isReadable() && QGifHandler::canRead( device ) ) )
    {
        return Capabilities( CanRead );
    }

    return 0;
}

QImageIOHandler *QGifPlugin::create( QIODevice *device, const QByteArray &format ) const
{
    QImageIOHandler *handler = new QGifHandler;
    handler->setDevice( device );
    handler->setFormat( format );
    return handler;
}

#endif
