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

#ifndef QGSTREAMERPLAYERSESSION_H
#define QGSTREAMERPLAYERSESSION_H

#include <qobject.h>
#include <qmutex.h>
#include <qnetwork_request.h>
#include <qgstreamerplayercontrol.h>

#include <qmediaplayer.h>
#include <qmediastreamscontrol.h>
#include <qaudioformat.h>

#include <qgstreamerbushelper_p.h>

#if defined(HAVE_GST_APPSRC)
#include <qgstappsrc_p.h>
#endif

#include <gst/gst.h>

class QGstreamerBusHelper;
class QGstreamerMessage;
class QGstreamerVideoRendererInterface;
class QGstreamerVideoProbeControl;
class QGstreamerAudioProbeControl;

typedef enum
{
    GST_AUTOPLUG_SELECT_TRY,
    GST_AUTOPLUG_SELECT_EXPOSE,
    GST_AUTOPLUG_SELECT_SKIP
} GstAutoplugSelectResult;

class QGstreamerPlayerSession : public QObject, public QGstreamerBusMessageFilter
{
    LSCS_OBJECT_MULTIPLE( QGstreamerPlayerSession, QObject )

    LSCS_INTERFACES( QGstreamerBusMessageFilter )

public:
    QGstreamerPlayerSession( QObject *parent );
    virtual ~QGstreamerPlayerSession();

    GstElement *playbin() const;
    QGstreamerBusHelper *bus() const
    {
        return m_busHelper;
    }

    QNetworkRequest request() const;

    QMediaPlayer::State state() const
    {
        return m_state;
    }

    QMediaPlayer::State pendingState() const
    {
        return m_pendingState;
    }

    qint64 duration() const;
    qint64 position() const;

    int volume() const;
    bool isMuted() const;

    bool isAudioAvailable() const;

    void setVideoRenderer( QObject *renderer );
    bool isVideoAvailable() const;

    bool isSeekable() const;

    qreal playbackRate() const;
    void setPlaybackRate( qreal rate );

    QMediaTimeRange availablePlaybackRanges() const;

    QMap<QByteArray, QVariant> tags() const
    {
        return m_tags;
    }

    QMap<QString, QVariant> streamProperties( int streamNumber ) const
    {
        return m_streamProperties[streamNumber];
    }

    int streamCount() const
    {
        return m_streamProperties.count();
    }

    QMediaStreamsControl::StreamType streamType( int streamNumber )
    {
        return m_streamTypes.value( streamNumber, QMediaStreamsControl::UnknownStream );
    }

    int activeStream( QMediaStreamsControl::StreamType streamType ) const;
    void setActiveStream( QMediaStreamsControl::StreamType streamType, int streamNumber );

    bool processBusMessage( const QGstreamerMessage &message ) override;

#if defined(HAVE_GST_APPSRC)
    QGstAppSrc *appsrc() const
    {
        return m_appSrc;
    }
    static void configureAppSrcElement( GObject *, GObject *, GParamSpec *, QGstreamerPlayerSession *_this );
#endif

    bool isLiveSource() const;

    void addProbe( QGstreamerVideoProbeControl *probe );
    void removeProbe( QGstreamerVideoProbeControl *probe );

    void addProbe( QGstreamerAudioProbeControl *probe );
    void removeProbe( QGstreamerAudioProbeControl *probe );

    void endOfMediaReset();

    LSCS_SLOT_1( Public, void loadFromUri( const QNetworkRequest &url ) )
    LSCS_SLOT_2( loadFromUri )

    LSCS_SLOT_1( Public, void loadFromStream( const QNetworkRequest &url, QIODevice *stream ) )
    LSCS_SLOT_2( loadFromStream )

    LSCS_SLOT_1( Public, bool play() )
    LSCS_SLOT_2( play )

    LSCS_SLOT_1( Public, bool pause() )
    LSCS_SLOT_2( pause )

    LSCS_SLOT_1( Public, void stop() )
    LSCS_SLOT_2( stop )

    LSCS_SLOT_1( Public, bool seek( qint64 pos ) )
    LSCS_SLOT_2( seek )

    LSCS_SLOT_1( Public, void setVolume( int volume ) )
    LSCS_SLOT_2( setVolume )

    LSCS_SLOT_1( Public, void setMuted( bool muted ) )
    LSCS_SLOT_2( setMuted )

    LSCS_SLOT_1( Public, void showPrerollFrames( bool enabled ) )
    LSCS_SLOT_2( showPrerollFrames )

    LSCS_SIGNAL_1( Public, void durationChanged( qint64 duration ) )
    LSCS_SIGNAL_2( durationChanged, duration )

    LSCS_SIGNAL_1( Public, void positionChanged( qint64 position ) )
    LSCS_SIGNAL_2( positionChanged, position )

    LSCS_SIGNAL_1( Public, void stateChanged( QMediaPlayer::State state ) )
    LSCS_SIGNAL_2( stateChanged, state )

    LSCS_SIGNAL_1( Public, void volumeChanged( int volume ) )
    LSCS_SIGNAL_2( volumeChanged, volume )

    LSCS_SIGNAL_1( Public, void mutedStateChanged( bool muted ) )
    LSCS_SIGNAL_2( mutedStateChanged, muted )

    LSCS_SIGNAL_1( Public, void audioAvailableChanged( bool audioAvailable ) )
    LSCS_SIGNAL_2( audioAvailableChanged, audioAvailable )

    LSCS_SIGNAL_1( Public, void videoAvailableChanged( bool videoAvailable ) )
    LSCS_SIGNAL_2( videoAvailableChanged, videoAvailable )

    LSCS_SIGNAL_1( Public, void bufferingProgressChanged( int percentFilled ) )
    LSCS_SIGNAL_2( bufferingProgressChanged, percentFilled )

    LSCS_SIGNAL_1( Public, void playbackFinished() )
    LSCS_SIGNAL_2( playbackFinished )

    LSCS_SIGNAL_1( Public, void tagsChanged() )
    LSCS_SIGNAL_2( tagsChanged )

    LSCS_SIGNAL_1( Public, void streamsChanged() )
    LSCS_SIGNAL_2( streamsChanged )

    LSCS_SIGNAL_1( Public, void seekableChanged( bool seekable ) )
    LSCS_SIGNAL_2( seekableChanged, seekable )

    LSCS_SIGNAL_1( Public, void error( int error, const QString &errorString ) )
    LSCS_SIGNAL_2( error, error, errorString )

    LSCS_SIGNAL_1( Public, void invalidMedia() )
    LSCS_SIGNAL_2( invalidMedia )

    LSCS_SIGNAL_1( Public, void playbackRateChanged( qreal rate ) )
    LSCS_SIGNAL_2( playbackRateChanged, rate )

private:
    static void playbinNotifySource( GObject *o, GParamSpec *p, gpointer d );
    static void handleVolumeChange( GObject *o, GParamSpec *p, gpointer d );
    static void handleMutedChange( GObject *o, GParamSpec *p, gpointer d );

#if !GST_CHECK_VERSION(1,0,0)
    static void insertColorSpaceElement( GstElement *element, gpointer data );
#endif

    static void handleElementAdded( GstBin *bin, GstElement *element, QGstreamerPlayerSession *session );
    static void handleStreamsChange( GstBin *bin, gpointer user_data );
    static GstAutoplugSelectResult handleAutoplugSelect( GstBin *bin, GstPad *pad, GstCaps *caps,
            GstElementFactory *factory, QGstreamerPlayerSession *session );

    void processInvalidMedia( QMediaPlayer::Error errorCode, const QString &errorString );

    void removeVideoBufferProbe();
    void addVideoBufferProbe();
    void removeAudioBufferProbe();
    void addAudioBufferProbe();
    void flushVideoProbes();
    void resumeVideoProbes();

    static void playlistTypeFindFunction( GstTypeFind *find, gpointer userData );

    QNetworkRequest m_request;
    QMediaPlayer::State m_state;
    QMediaPlayer::State m_pendingState;
    QGstreamerBusHelper *m_busHelper;
    GstElement *m_playbin;

    GstElement *m_videoSink;

    GstElement *m_videoOutputBin;
    GstElement *m_videoIdentity;

#if ! GST_CHECK_VERSION(1,0,0)
    GstElement *m_colorSpace;
    bool m_usingColorspaceElement;
#endif

    GstElement *m_pendingVideoSink;
    GstElement *m_nullVideoSink;

    GstElement *m_audioSink;
    GstElement *m_volumeElement;

    GstBus *m_bus;
    QObject *m_videoOutput;
    QGstreamerVideoRendererInterface *m_renderer;

#if defined(HAVE_GST_APPSRC)
    QGstAppSrc *m_appSrc;
#endif

    QMap<QByteArray, QVariant> m_tags;
    QList< QMap<QString, QVariant>> m_streamProperties;
    QList<QMediaStreamsControl::StreamType> m_streamTypes;
    QMap<QMediaStreamsControl::StreamType, int> m_playbin2StreamOffset;

    QGstreamerVideoProbeControl *m_videoProbe;
    QGstreamerAudioProbeControl *m_audioProbe;

    int m_volume;
    qreal m_playbackRate;
    bool m_muted;
    bool m_audioAvailable;
    bool m_videoAvailable;
    bool m_seekable;

    mutable qint64 m_lastPosition;
    qint64 m_duration;
    int m_durationQueries;

    bool m_displayPrerolledFrame;

    enum SourceType
    {
        UnknownSrc,
        SoupHTTPSrc,
        UDPSrc,
        MMSSrc,
        RTSPSrc,
    };
    SourceType m_sourceType;
    bool m_everPlayed;
    bool m_isLiveSource;

    bool m_isPlaylist;
    gulong pad_probe_id;

    LSCS_SLOT_1( Private, void getStreamsInfo() )
    LSCS_SLOT_2( getStreamsInfo )

    LSCS_SLOT_1( Private, void setSeekable( bool seekable ) )
    LSCS_SLOT_2( setSeekable )

    LSCS_SLOT_1( Private, void finishVideoOutputChange() )
    LSCS_SLOT_2( finishVideoOutputChange )

    LSCS_SLOT_1( Private, void updateVideoRenderer() )
    LSCS_SLOT_2( updateVideoRenderer )

    LSCS_SLOT_1( Private, void updateVideoResolutionTag() )
    LSCS_SLOT_2( updateVideoResolutionTag )

    LSCS_SLOT_1( Private, void updateVolume() )
    LSCS_SLOT_2( updateVolume )

    LSCS_SLOT_1( Private, void updateMuted() )
    LSCS_SLOT_2( updateMuted )

    LSCS_SLOT_1( Private, void updateDuration() )
    LSCS_SLOT_2( updateDuration )
};

#endif
