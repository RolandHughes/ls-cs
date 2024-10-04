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

#ifndef AVFMEDIAPLAYERSESSION_H
#define AVFMEDIAPLAYERSESSION_H

#include <QObject>
#include <QByteArray>
#include <QSet>
#include <QResource>

#include <QMediaPlayerControl>
#include <QMediaPlayer>

class AVFMediaPlayerService;
class AVFVideoOutput;

class AVFMediaPlayerSession : public QObject
{
    LSCS_OBJECT( AVFMediaPlayerSession )

public:
    AVFMediaPlayerSession( AVFMediaPlayerService *service, QObject *parent = nullptr );
    virtual ~AVFMediaPlayerSession();

    void setVideoOutput( AVFVideoOutput *output );
    void *currentAssetHandle();

    QMediaPlayer::State state() const;
    QMediaPlayer::MediaStatus mediaStatus() const;

    QMediaContent media() const;
    const QIODevice *mediaStream() const;
    void setMedia( const QMediaContent &content, QIODevice *stream );

    qint64 position() const;
    qint64 duration() const;

    int bufferStatus() const;

    int volume() const;
    bool isMuted() const;

    bool isAudioAvailable() const;
    bool isVideoAvailable() const;

    bool isSeekable() const;
    QMediaTimeRange availablePlaybackRanges() const;

    qreal playbackRate() const;

    inline bool isVolumeSupported() const
    {
        return m_volumeSupported;
    }

    LSCS_SLOT_1( Public, void setPlaybackRate( qreal rate ) )
    LSCS_SLOT_2( setPlaybackRate )

    LSCS_SLOT_1( Public, void setPosition( qint64 pos ) )
    LSCS_SLOT_2( setPosition )

    LSCS_SLOT_1( Public, void play() )
    LSCS_SLOT_2( play )
    LSCS_SLOT_1( Public, void pause() )
    LSCS_SLOT_2( pause )

    LSCS_SLOT_1( Public, void stop() )
    LSCS_SLOT_2( stop )

    LSCS_SLOT_1( Public, void setVolume( int volume ) )
    LSCS_SLOT_2( setVolume )

    LSCS_SLOT_1( Public, void setMuted( bool muted ) )
    LSCS_SLOT_2( setMuted )

    LSCS_SLOT_1( Public, void processEOS() )
    LSCS_SLOT_2( processEOS )

    LSCS_SLOT_1( Public, void processLoadStateChange() )
    LSCS_SLOT_2( processLoadStateChange )

    LSCS_SLOT_1( Public, void processPositionChange() )
    LSCS_SLOT_2( processPositionChange )

    LSCS_SLOT_1( Public, void processMediaLoadError() )
    LSCS_SLOT_2( processMediaLoadError )

    LSCS_SIGNAL_1( Public, void positionChanged( qint64 position ) )
    LSCS_SIGNAL_2( positionChanged, position )

    LSCS_SIGNAL_1( Public, void durationChanged( qint64 duration ) )
    LSCS_SIGNAL_2( durationChanged, duration )

    LSCS_SIGNAL_1( Public, void stateChanged( QMediaPlayer::State newState ) )
    LSCS_SIGNAL_2( stateChanged, newState )

    LSCS_SIGNAL_1( Public, void mediaStatusChanged( QMediaPlayer::MediaStatus status ) )
    LSCS_SIGNAL_2( mediaStatusChanged, status )

    LSCS_SIGNAL_1( Public, void volumeChanged( int volume ) )
    LSCS_SIGNAL_2( volumeChanged, volume )

    LSCS_SIGNAL_1( Public, void mutedChanged( bool muted ) )
    LSCS_SIGNAL_2( mutedChanged, muted )

    LSCS_SIGNAL_1( Public, void audioAvailableChanged( bool audioAvailable ) )
    LSCS_SIGNAL_2( audioAvailableChanged, audioAvailable )

    LSCS_SIGNAL_1( Public, void videoAvailableChanged( bool videoAvailable ) )
    LSCS_SIGNAL_2( videoAvailableChanged, videoAvailable )

    LSCS_SIGNAL_1( Public, void playbackRateChanged( qreal rate ) )
    LSCS_SIGNAL_2( playbackRateChanged, rate )

    LSCS_SIGNAL_1( Public, void seekableChanged( bool seekable ) )
    LSCS_SIGNAL_2( seekableChanged, seekable )

    LSCS_SIGNAL_1( Public, void error( int error, const QString &errorString ) )
    LSCS_SIGNAL_2( error, error, errorString )

private:
    class ResourceHandler
    {
    public:
        ResourceHandler()
            : resource( nullptr )
        {
        }

        ~ResourceHandler()
        {
            clear();
        }

        void setResourceFile( const QString &file )
        {
            if ( resource )
            {
                if ( resource->fileName() == file )
                {
                    return;
                }

                delete resource;
                rawData.clear();
            }

            resource = new QResource( file );
        }

        bool isValid() const
        {
            return resource && resource->isValid() && resource->data() != nullptr;
        }

        const uchar *data()
        {
            if ( !isValid() )
            {
                return nullptr;
            }

            if ( resource->isCompressed() )
            {
                if ( rawData.size() == 0 )
                {
                    rawData = qUncompress( resource->data(), resource->size() );
                }

                return ( const uchar * )rawData.constData();
            }

            return resource->data();
        }

        qint64 size()
        {
            if ( data() == nullptr )
            {
                return 0;
            }

            return resource->isCompressed() ? rawData.size() : resource->size();
        }

        void clear()
        {
            delete resource;
            rawData.clear();
        }

        QResource *resource;
        QByteArray rawData;
    };

    void setAudioAvailable( bool available );
    void setVideoAvailable( bool available );
    void setSeekable( bool seekable );

    AVFMediaPlayerService *m_service;
    AVFVideoOutput *m_videoOutput;

    QMediaPlayer::State m_state;
    QMediaPlayer::MediaStatus m_mediaStatus;
    QIODevice *m_mediaStream;
    QMediaContent m_resources;
    ResourceHandler m_resourceHandler;

    const bool m_volumeSupported;
    bool m_muted;
    bool m_tryingAsync;
    int m_volume;
    qreal m_rate;
    qint64 m_requestedPosition;

    qint64 m_duration;
    bool m_videoAvailable;
    bool m_audioAvailable;
    bool m_seekable;

    void *m_observer;
};

#endif
