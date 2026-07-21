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

#ifndef AVFMEDIAPLAYERCONTROL_H
#define AVFMEDIAPLAYERCONTROL_H

#include <QMediaPlayerControl>
#include <QObject>

class AVFMediaPlayerSession;

class AVFMediaPlayerControl : public QMediaPlayerControl
{
    LSCS_OBJECT( AVFMediaPlayerControl )

public:
    explicit AVFMediaPlayerControl( QObject *parent = nullptr );
    ~AVFMediaPlayerControl();

    void setSession( AVFMediaPlayerSession *session );

    QMediaPlayer::State state() const override;
    QMediaPlayer::MediaStatus mediaStatus() const override;

    QMediaContent media() const override;
    const QIODevice *mediaStream() const override;
    void setMedia( const QMediaContent &content, QIODevice *stream ) override;

    qint64 position() const override;
    qint64 duration() const override;

    int bufferStatus() const override;

    int volume() const override;
    bool isMuted() const override;

    bool isAudioAvailable() const override;
    bool isVideoAvailable() const override;

    bool isSeekable() const override;
    QMediaTimeRange availablePlaybackRanges() const override;

    qreal playbackRate() const override;
    void setPlaybackRate( qreal rate ) override;

    LSCS_SLOT_1( Public, void setPosition( qint64 pos ) override )
    LSCS_SLOT_2( setPosition )

    LSCS_SLOT_1( Public, void play() override )
    LSCS_SLOT_2( play )
    LSCS_SLOT_1( Public, void pause() override )
    LSCS_SLOT_2( pause )
    LSCS_SLOT_1( Public, void stop() override )
    LSCS_SLOT_2( stop )

    LSCS_SLOT_1( Public, void setVolume( int volume ) override )
    LSCS_SLOT_2( setVolume )
    LSCS_SLOT_1( Public, void setMuted( bool muted ) override )
    LSCS_SLOT_2( setMuted )

private:
    AVFMediaPlayerSession *m_session;
};

#endif
