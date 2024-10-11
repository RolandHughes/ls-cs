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

#ifndef CAMERA_SESSION_H
#define CAMERA_SESSION_H

#include <qcamera.h>
#include <qmediarecordercontrol.h>
#include <qurl.h>
#include <qdir.h>

#include <qgstreamerbushelper_p.h>
#include <qgstreamerbufferprobe_p.h>
#include <qmediastoragelocation_p.h>

#include <gst/gst.h>
#ifdef HAVE_GST_PHOTOGRAPHY
#include <gst/interfaces/photography.h>
#endif

class QGstreamerMessage;
class QGstreamerBusHelper;
class CameraBinControl;
class CameraBinAudioEncoder;
class CameraBinVideoEncoder;
class CameraBinImageEncoder;
class CameraBinRecorder;
class CameraBinContainer;
class CameraBinExposure;
class CameraBinFlash;
class CameraBinFocus;
class CameraBinImageProcessing;
class CameraBinLocks;
class CameraBinZoom;
class CameraBinCaptureDestination;
class CameraBinCaptureBufferFormat;
class QGstreamerVideoRendererInterface;
class CameraBinViewfinderSettings;

class QGstreamerElementFactory
{
public:
    virtual GstElement *buildElement() = 0;
};

class CameraBinSession : public QObject, public QGstreamerBusMessageFilter, public QGstreamerSyncMessageFilter
{
    LSCS_OBJECT( CameraBinSession )

    LSCS_PROPERTY_READ( duration, duration )
    LSCS_PROPERTY_NOTIFY( duration, durationChanged )

    LSCS_INTERFACES( QGstreamerBusMessageFilter, QGstreamerSyncMessageFilter )

public:
    CameraBinSession( GstElementFactory *sourceFactory, QObject *parent );
    ~CameraBinSession();

#ifdef HAVE_GST_PHOTOGRAPHY
    GstPhotography *photography();
#endif

    GstElement *cameraBin()
    {
        return m_camerabin;
    }

    GstElement *cameraSource()
    {
        return m_cameraSrc;
    }

    QGstreamerBusHelper *bus()
    {
        return m_busHelper;
    }

    QList< QPair<int, int> > supportedFrameRates( const QSize &frameSize, bool *continuous ) const;
    QList<QSize> supportedResolutions( QPair<int, int> rate, bool *continuous, QCamera::CaptureModes mode ) const;

    QCamera::CaptureModes captureMode()
    {
        return m_captureMode;
    }

    void setCaptureMode( QCamera::CaptureModes mode );

    QUrl outputLocation() const;
    bool setOutputLocation( const QUrl &sink );

    GstElement *buildCameraSource();
    GstElementFactory *sourceFactory() const
    {
        return m_sourceFactory;
    }

    CameraBinControl *cameraControl() const
    {
        return m_cameraControl;
    }

    CameraBinAudioEncoder *audioEncodeControl() const
    {
        return m_audioEncodeControl;
    }

    CameraBinVideoEncoder *videoEncodeControl() const
    {
        return m_videoEncodeControl;
    }

    CameraBinImageEncoder *imageEncodeControl() const
    {
        return m_imageEncodeControl;
    }

#ifdef HAVE_GST_PHOTOGRAPHY
    CameraBinExposure *cameraExposureControl();
    CameraBinFlash *cameraFlashControl();
    CameraBinFocus *cameraFocusControl();
    CameraBinLocks *cameraLocksControl();
#endif

    CameraBinZoom *cameraZoomControl() const
    {
        return m_cameraZoomControl;
    }

    CameraBinImageProcessing *imageProcessingControl() const
    {
        return m_imageProcessingControl;
    }

    CameraBinCaptureDestination *captureDestinationControl() const
    {
        return m_captureDestinationControl;
    }

    CameraBinCaptureBufferFormat *captureBufferFormatControl() const
    {
        return m_captureBufferFormatControl;
    }

    CameraBinRecorder *recorderControl() const
    {
        return m_recorderControl;
    }

    CameraBinContainer *mediaContainerControl() const
    {
        return m_mediaContainerControl;
    }

    QGstreamerElementFactory *audioInput() const
    {
        return m_audioInputFactory;
    }

    void setAudioInput( QGstreamerElementFactory *audioInput );

    QGstreamerElementFactory *videoInput() const
    {
        return m_videoInputFactory;
    }

    void setVideoInput( QGstreamerElementFactory *videoInput );
    bool isReady() const;

    QObject *viewfinder() const
    {
        return m_viewfinder;
    }

    void setViewfinder( QObject *viewfinder );

    QList<QCameraViewfinderSettings> supportedViewfinderSettings() const;
    QCameraViewfinderSettings viewfinderSettings() const;

    void setViewfinderSettings( const QCameraViewfinderSettings &settings )
    {
        m_viewfinderSettings = settings;
    }

    void captureImage( int requestId, const QString &fileName );

    QCamera::Status status() const;
    QCamera::State pendingState() const;
    bool isBusy() const;

    qint64 duration() const;

    void recordVideo();
    void stopVideoRecording();

    bool isMuted() const;

    QString device() const
    {
        return m_inputDevice;
    }

    bool processSyncMessage( const QGstreamerMessage &message ) override;
    bool processBusMessage( const QGstreamerMessage &message ) override;

    LSCS_SIGNAL_1( Public, void statusChanged( QCamera::Status newStatus ) )
    LSCS_SIGNAL_2( statusChanged, newStatus )

    LSCS_SIGNAL_1( Public, void pendingStateChanged( QCamera::State state ) )
    LSCS_SIGNAL_2( pendingStateChanged, state )

    LSCS_SIGNAL_1( Public, void durationChanged( qint64 duration ) )
    LSCS_SIGNAL_2( durationChanged, duration )

    LSCS_SIGNAL_1( Public, void error( int error, const QString &errorString ) )
    LSCS_SIGNAL_2( error, error, errorString )

    LSCS_SIGNAL_1( Public, void imageExposed( int requestId ) )
    LSCS_SIGNAL_2( imageExposed, requestId )

    LSCS_SIGNAL_1( Public, void imageCaptured( int requestId, const QImage &img ) )
    LSCS_SIGNAL_2( imageCaptured, requestId, img )

    LSCS_SIGNAL_1( Public, void mutedChanged( bool muted ) )
    LSCS_SIGNAL_2( mutedChanged, muted )

    LSCS_SIGNAL_1( Public, void viewfinderChanged() )
    LSCS_SIGNAL_2( viewfinderChanged )

    LSCS_SIGNAL_1( Public, void readyChanged( bool isReady ) )
    LSCS_SIGNAL_2( readyChanged, isReady )

    LSCS_SIGNAL_1( Public, void busyChanged( bool busy ) )
    LSCS_SIGNAL_2( busyChanged, busy )

    LSCS_SLOT_1( Public, void setDevice( const QString &device ) )
    LSCS_SLOT_2( setDevice )

    LSCS_SLOT_1( Public, void setState( QCamera::State start ) )
    LSCS_SLOT_2( setState )

    LSCS_SLOT_1( Public, void setCaptureDevice( const QString &deviceName ) )
    LSCS_SLOT_2( setCaptureDevice )

    LSCS_SLOT_1( Public, void setMetaData( const QMap <QByteArray, QVariant> &value ) )
    LSCS_SLOT_2( setMetaData )

    LSCS_SLOT_1( Public, void setMuted( bool value ) )
    LSCS_SLOT_2( setMuted )

    QString m_imageFileName;
    int m_requestId;

private:
    LSCS_SLOT_1( Private, void handleViewfinderChange() )
    LSCS_SLOT_2( handleViewfinderChange )

    LSCS_SLOT_1( Private, void setupCaptureResolution() )
    LSCS_SLOT_2( setupCaptureResolution )

    void load();
    void unload();
    void start();
    void stop();

    void setStatus( QCamera::Status status );
    void setStateHelper( QCamera::State state );
    void setError( int error, const QString &errorString );

    bool setupCameraBin();
    void setAudioCaptureCaps();
    GstCaps *supportedCaps( QCamera::CaptureModes mode ) const;
    void updateSupportedViewfinderSettings();
    static void updateBusyStatus( GObject *o, GParamSpec *p, gpointer d );

    QString currentContainerFormat() const;

    static void elementAdded( GstBin *bin, GstElement *element, CameraBinSession *session );
    static void elementRemoved( GstBin *bin, GstElement *element, CameraBinSession *session );

    QUrl m_sink;
    QUrl m_actualSink;
    bool m_recordingActive;
    QString m_captureDevice;
    QCamera::Status m_status;
    QCamera::State m_pendingState;
    QString m_inputDevice;
    bool m_muted;
    bool m_busy;
    QMediaStorageLocation m_mediaStorageLocation;

    QCamera::CaptureModes m_captureMode;
    QMap<QByteArray, QVariant> m_metaData;

    QGstreamerElementFactory *m_audioInputFactory;
    QGstreamerElementFactory *m_videoInputFactory;
    QObject *m_viewfinder;
    QGstreamerVideoRendererInterface *m_viewfinderInterface;
    QList<QCameraViewfinderSettings> m_supportedViewfinderSettings;
    QCameraViewfinderSettings m_viewfinderSettings;
    QCameraViewfinderSettings m_actualViewfinderSettings;

    CameraBinControl *m_cameraControl;
    CameraBinAudioEncoder *m_audioEncodeControl;
    CameraBinVideoEncoder *m_videoEncodeControl;
    CameraBinImageEncoder *m_imageEncodeControl;
    CameraBinRecorder *m_recorderControl;
    CameraBinContainer *m_mediaContainerControl;

#ifdef HAVE_GST_PHOTOGRAPHY
    CameraBinExposure *m_cameraExposureControl;
    CameraBinFlash *m_cameraFlashControl;
    CameraBinFocus *m_cameraFocusControl;
    CameraBinLocks *m_cameraLocksControl;
#endif

    CameraBinZoom *m_cameraZoomControl;
    CameraBinImageProcessing *m_imageProcessingControl;
    CameraBinCaptureDestination *m_captureDestinationControl;
    CameraBinCaptureBufferFormat *m_captureBufferFormatControl;

    QGstreamerBusHelper *m_busHelper;
    GstBus *m_bus;
    GstElement *m_camerabin;
    GstElement *m_cameraSrc;
    GstElement *m_videoSrc;
    GstElement *m_viewfinderElement;
    GstElementFactory *m_sourceFactory;
    bool m_viewfinderHasChanged;
    bool m_inputDeviceHasChanged;
    bool m_usingWrapperCameraBinSrc;

    class ViewfinderProbe : public QGstreamerBufferProbe
    {
    public:
        ViewfinderProbe( CameraBinSession *s )
            : QGstreamerBufferProbe( QGstreamerBufferProbe::ProbeCaps ), session( s )
        {
        }

        void probeCaps( GstCaps *caps ) override;

    private:
        CameraBinSession *const session;
    };

    ViewfinderProbe m_viewfinderProbe;

    GstElement *m_audioSrc;
    GstElement *m_audioConvert;
    GstElement *m_capsFilter;
    GstElement *m_fileSink;
    GstElement *m_audioEncoder;
    GstElement *m_videoEncoder;
    GstElement *m_muxer;
};

#endif
