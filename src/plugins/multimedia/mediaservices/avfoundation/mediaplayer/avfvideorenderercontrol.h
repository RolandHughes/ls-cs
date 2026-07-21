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

#ifndef AVFVIDEORENDERERCONTROL_H
#define AVFVIDEORENDERERCONTROL_H

#include <qvideorenderercontrol.h>
#include <qmutex.h>
#include <qsize.h>
#include <avfvideooutput.h>

#import <CoreVideo/CVBase.h>

class AVFDisplayLink;
class AVFVideoFrameRenderer;

class AVFVideoRendererControl : public QVideoRendererControl, public AVFVideoOutput
{
    LSCS_OBJECT_MULTIPLE( AVFVideoRendererControl, QVideoRendererControl )
    LSCS_INTERFACES( AVFVideoOutput )

public:
    explicit AVFVideoRendererControl( QObject *parent = nullptr );
    virtual ~AVFVideoRendererControl();

    QAbstractVideoSurface *surface() const override;
    void setSurface( QAbstractVideoSurface *surface ) override;

    void setLayer( void *playerLayer ) override;

    LSCS_SIGNAL_1( Public, void surfaceChanged( QAbstractVideoSurface *surface ) )
    LSCS_SIGNAL_2( surfaceChanged, surface )

private:
    void setupVideoOutput();

    QMutex m_mutex;
    QAbstractVideoSurface *m_surface;

    void *m_playerLayer;

    AVFVideoFrameRenderer *m_frameRenderer;
    AVFDisplayLink *m_displayLink;
    QSize m_nativeSize;
    bool m_enableOpenGL;

    LSCS_SLOT_1( Private, void updateVideoFrame( const CVTimeStamp &ts ) )
    LSCS_SLOT_2( updateVideoFrame )
};

#endif