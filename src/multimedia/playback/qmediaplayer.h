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

#ifndef QMEDIAPLAYER_H
#define QMEDIAPLAYER_H

#include <qaudio.h>
#include <qmediaobject.h>
#include <qmediacontent.h>
#include <qmediaplaylist.h>
#include <qnetworkconfiguration.h>

class QAbstractVideoSurface;
class QGraphicsVideoItem;
class QVideoWidget;
class QMediaPlayerPrivate;

class Q_MULTIMEDIA_EXPORT QMediaPlayer : public QMediaObject
{
    MULTI_LSCS_OBJECT( QMediaPlayer )

    MULTI_LSCS_PROPERTY_READ( media,   media )
    MULTI_LSCS_PROPERTY_WRITE( media,  lscs_setMedia )
    MULTI_LSCS_PROPERTY_NOTIFY( media, mediaChanged )

    MULTI_LSCS_PROPERTY_READ( currentMedia, currentMedia )
    MULTI_LSCS_PROPERTY_NOTIFY( currentMedia, currentMediaChanged )

    MULTI_LSCS_PROPERTY_READ( playlist, playlist )
    MULTI_LSCS_PROPERTY_WRITE( playlist, setPlaylist )

    MULTI_LSCS_PROPERTY_READ( duration, duration )
    MULTI_LSCS_PROPERTY_NOTIFY( duration, durationChanged )

    MULTI_LSCS_PROPERTY_READ( position, position )
    MULTI_LSCS_PROPERTY_WRITE( position, setPosition )
    MULTI_LSCS_PROPERTY_NOTIFY( position, positionChanged )

    MULTI_LSCS_PROPERTY_READ( volume, volume )
    MULTI_LSCS_PROPERTY_WRITE( volume, setVolume )
    MULTI_LSCS_PROPERTY_NOTIFY( volume, volumeChanged )

    MULTI_LSCS_PROPERTY_READ( muted, isMuted )
    MULTI_LSCS_PROPERTY_WRITE( muted, setMuted )
    MULTI_LSCS_PROPERTY_NOTIFY( muted, mutedChanged )

    MULTI_LSCS_PROPERTY_READ( bufferStatus, bufferStatus )
    MULTI_LSCS_PROPERTY_NOTIFY( bufferStatus, bufferStatusChanged )

    MULTI_LSCS_PROPERTY_READ( audioAvailable, isAudioAvailable )
    MULTI_LSCS_PROPERTY_NOTIFY( audioAvailable, audioAvailableChanged )

    MULTI_LSCS_PROPERTY_READ( videoAvailable, isVideoAvailable )
    MULTI_LSCS_PROPERTY_NOTIFY( videoAvailable, videoAvailableChanged )

    MULTI_LSCS_PROPERTY_READ( seekable, isSeekable )
    MULTI_LSCS_PROPERTY_NOTIFY( seekable, seekableChanged )

    MULTI_LSCS_PROPERTY_READ( playbackRate, playbackRate )
    MULTI_LSCS_PROPERTY_WRITE( playbackRate, setPlaybackRate )
    MULTI_LSCS_PROPERTY_NOTIFY( playbackRate, playbackRateChanged )

    MULTI_LSCS_PROPERTY_READ( state, state )
    MULTI_LSCS_PROPERTY_NOTIFY( state, stateChanged )

    MULTI_LSCS_PROPERTY_READ( mediaStatus, mediaStatus )
    MULTI_LSCS_PROPERTY_NOTIFY( mediaStatus, mediaStatusChanged )

    MULTI_LSCS_PROPERTY_READ( audioRole, audioRole )
    MULTI_LSCS_PROPERTY_WRITE( audioRole, setAudioRole )

    MULTI_LSCS_PROPERTY_READ( error, errorString )

    MULTI_LSCS_ENUM( State )
    MULTI_LSCS_ENUM( MediaStatus )
    MULTI_LSCS_ENUM( Error )

public:
    enum State
    {
        StoppedState,
        PlayingState,
        PausedState
    };

    enum MediaStatus
    {
        UnknownMediaStatus,
        NoMedia,
        LoadingMedia,
        LoadedMedia,
        StalledMedia,
        BufferingMedia,
        BufferedMedia,
        EndOfMedia,
        InvalidMedia
    };

    enum Flag
    {
        LowLatency = 0x01,
        StreamPlayback = 0x02,
        VideoSurface = 0x04
    };
    using Flags = QFlags<Flag>;

    enum Error
    {
        NoError,
        ResourceError,
        FormatError,
        NetworkError,
        AccessDeniedError,
        ServiceMissingError,
        MediaIsPlaylist
    };

    explicit QMediaPlayer( QObject *parent = nullptr, Flags flags = Flags() );

    QMediaPlayer( const QMediaPlayer & ) = delete;
    QMediaPlayer &operator=( const QMediaPlayer & ) = delete;

    ~QMediaPlayer();

    static QMultimedia::SupportEstimate hasSupport( const QString &mimeType,
            const QStringList &codecs = QStringList(), Flags flags = Flags() );

    static QStringList supportedMimeTypes( Flags flags = Flags() );

    void setVideoOutput( QVideoWidget *widget );
    void setVideoOutput( QGraphicsVideoItem *item );
    void setVideoOutput( QAbstractVideoSurface *surface );

    QMediaContent media() const;
    const QIODevice *mediaStream() const;
    QMediaPlaylist *playlist() const;
    QMediaContent currentMedia() const;

    State state() const;
    MediaStatus mediaStatus() const;

    qint64 duration() const;
    qint64 position() const;

    int volume() const;
    bool isMuted() const;
    bool isAudioAvailable() const;
    bool isVideoAvailable() const;

    int bufferStatus() const;

    bool isSeekable() const;
    qreal playbackRate() const;

    Error error() const;
    QString errorString() const;

    QNetworkConfiguration currentNetworkConfiguration() const;

    QMultimedia::AvailabilityStatus availability() const override;

    QAudio::Role audioRole() const;
    void setAudioRole( QAudio::Role audioRole );
    QList<QAudio::Role> supportedAudioRoles() const;

    MULTI_LSCS_SLOT_1( Public, void play() )
    MULTI_LSCS_SLOT_2( play )
    MULTI_LSCS_SLOT_1( Public, void pause() )
    MULTI_LSCS_SLOT_2( pause )
    MULTI_LSCS_SLOT_1( Public, void stop() )
    MULTI_LSCS_SLOT_2( stop )

    MULTI_LSCS_SLOT_1( Public, void setPosition( qint64 position ) )
    MULTI_LSCS_SLOT_2( setPosition )
    MULTI_LSCS_SLOT_1( Public, void setVolume( int volume ) )
    MULTI_LSCS_SLOT_2( setVolume )
    MULTI_LSCS_SLOT_1( Public, void setMuted( bool muted ) )
    MULTI_LSCS_SLOT_2( setMuted )

    MULTI_LSCS_SLOT_1( Public, void setPlaybackRate( qreal rate ) )
    MULTI_LSCS_SLOT_2( setPlaybackRate )

    MULTI_LSCS_SLOT_1( Public, void setMedia( const QMediaContent &media, QIODevice *stream = nullptr ) )
    MULTI_LSCS_SLOT_2( setMedia )

    MULTI_LSCS_SLOT_1( Public, void setPlaylist( QMediaPlaylist *playlist ) )
    MULTI_LSCS_SLOT_2( setPlaylist )

    MULTI_LSCS_SLOT_1( Public, void setNetworkConfigurations( const QList <QNetworkConfiguration> &configurations ) )
    MULTI_LSCS_SLOT_2( setNetworkConfigurations )

    MULTI_LSCS_SIGNAL_1( Public, void mediaChanged( const QMediaContent &media ) )
    MULTI_LSCS_SIGNAL_2( mediaChanged, media )

    MULTI_LSCS_SIGNAL_1( Public, void currentMediaChanged( const QMediaContent &content ) )
    MULTI_LSCS_SIGNAL_2( currentMediaChanged, content )

    MULTI_LSCS_SIGNAL_1( Public, void stateChanged( QMediaPlayer::State newState ) )
    MULTI_LSCS_SIGNAL_2( stateChanged, newState )
    MULTI_LSCS_SIGNAL_1( Public, void mediaStatusChanged( QMediaPlayer::MediaStatus status ) )
    MULTI_LSCS_SIGNAL_2( mediaStatusChanged, status )

    MULTI_LSCS_SIGNAL_1( Public, void durationChanged( qint64 duration ) )
    MULTI_LSCS_SIGNAL_2( durationChanged, duration )

    MULTI_LSCS_SIGNAL_1( Public, void positionChanged( qint64 position ) )
    MULTI_LSCS_SIGNAL_2( positionChanged, position )

    MULTI_LSCS_SIGNAL_1( Public, void volumeChanged( int volume ) )
    MULTI_LSCS_SIGNAL_2( volumeChanged, volume )
    MULTI_LSCS_SIGNAL_1( Public, void mutedChanged( bool muted ) )
    MULTI_LSCS_SIGNAL_2( mutedChanged, muted )
    MULTI_LSCS_SIGNAL_1( Public, void audioAvailableChanged( bool available ) )
    MULTI_LSCS_SIGNAL_2( audioAvailableChanged, available )
    MULTI_LSCS_SIGNAL_1( Public, void videoAvailableChanged( bool videoAvailable ) )
    MULTI_LSCS_SIGNAL_2( videoAvailableChanged, videoAvailable )

    MULTI_LSCS_SIGNAL_1( Public, void bufferStatusChanged( int percentFilled ) )
    MULTI_LSCS_SIGNAL_2( bufferStatusChanged, percentFilled )

    MULTI_LSCS_SIGNAL_1( Public, void seekableChanged( bool seekable ) )
    MULTI_LSCS_SIGNAL_2( seekableChanged, seekable )
    MULTI_LSCS_SIGNAL_1( Public, void playbackRateChanged( qreal rate ) )
    MULTI_LSCS_SIGNAL_2( playbackRateChanged, rate )

    MULTI_LSCS_SIGNAL_1( Public, void audioRoleChanged( QAudio::Role role ) )
    MULTI_LSCS_SIGNAL_2( audioRoleChanged, role )

    MULTI_LSCS_SIGNAL_1( Public, void error( QMediaPlayer::Error error ) )
    MULTI_LSCS_SIGNAL_OVERLOAD( error, ( QMediaPlayer::Error ), error )

    MULTI_LSCS_SIGNAL_1( Public, void networkConfigurationChanged( const QNetworkConfiguration &configuration ) )
    MULTI_LSCS_SIGNAL_2( networkConfigurationChanged, configuration )

private:
    Q_DECLARE_PRIVATE( QMediaPlayer )

    // wrapper for overloaded property
    void lscs_setMedia ( const QMediaContent &media )
    {
        setMedia( media );
    }

    MULTI_LSCS_SLOT_1( Private, void _q_stateChanged( QMediaPlayer::State state ) )
    MULTI_LSCS_SLOT_2( _q_stateChanged )

    MULTI_LSCS_SLOT_1( Private, void _q_mediaStatusChanged( QMediaPlayer::MediaStatus status ) )
    MULTI_LSCS_SLOT_2( _q_mediaStatusChanged )

    MULTI_LSCS_SLOT_1( Private, void _q_error( int error, const QString &errorString ) )
    MULTI_LSCS_SLOT_2( _q_error )

    MULTI_LSCS_SLOT_1( Private, void _q_updateMedia( const QMediaContent &media ) )
    MULTI_LSCS_SLOT_2( _q_updateMedia )

    MULTI_LSCS_SLOT_1( Private, void _q_playlistDestroyed() )
    MULTI_LSCS_SLOT_2( _q_playlistDestroyed )

    MULTI_LSCS_SLOT_1( Private, void _q_handleMediaChanged( const QMediaContent &media ) )
    MULTI_LSCS_SLOT_2( _q_handleMediaChanged )

    MULTI_LSCS_SLOT_1( Private, void _q_handlePlaylistLoaded() )
    MULTI_LSCS_SLOT_2( _q_handlePlaylistLoaded )

    MULTI_LSCS_SLOT_1( Private, void _q_handlePlaylistLoadFailed() )
    MULTI_LSCS_SLOT_2( _q_handlePlaylistLoadFailed )
};

#endif
