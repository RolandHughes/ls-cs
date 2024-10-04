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

#ifndef QCAMERA_H
#define QCAMERA_H

#include <qcameraexposure.h>
#include <qcamerafocus.h>
#include <qcameraimageprocessing.h>
#include <qcameraviewfindersettings.h>
#include <qmediacontrol.h>
#include <qmediaobject.h>
#include <qmediaservice.h>
#include <qpair.h>
#include <qpoint.h>
#include <qrect.h>
#include <qsize.h>
#include <qstringlist.h>

class QAbstractVideoSurface;
class QCameraInfo;
class QCameraPrivate;
class QGraphicsVideoItem;
class QVideoWidget;

class Q_MULTIMEDIA_EXPORT QCamera : public QMediaObject
{
    MULTI_LSCS_OBJECT( QCamera )

    MULTI_LSCS_PROPERTY_READ( state, state )
    MULTI_LSCS_PROPERTY_NOTIFY( state, stateChanged )

    MULTI_LSCS_PROPERTY_READ( status, status )
    MULTI_LSCS_PROPERTY_NOTIFY( status, statusChanged )

    MULTI_LSCS_PROPERTY_READ( captureMode, captureMode )
    MULTI_LSCS_PROPERTY_WRITE( captureMode, setCaptureMode )
    MULTI_LSCS_PROPERTY_NOTIFY( captureMode, captureModeChanged )

    MULTI_LSCS_PROPERTY_READ( lockStatus, cs_lockStatus )
    MULTI_LSCS_PROPERTY_NOTIFY( lockStatus, cs_lockStatusChanged )

    MULTI_LSCS_ENUM( Status )
    MULTI_LSCS_ENUM( State )
    MULTI_LSCS_ENUM( CaptureMode )
    MULTI_LSCS_ENUM( Error )
    MULTI_LSCS_ENUM( LockStatus )
    MULTI_LSCS_ENUM( LockChangeReason )
    MULTI_LSCS_ENUM( LockType )
    MULTI_LSCS_ENUM( Position )

public:
    struct FrameRateRange
    {
        constexpr FrameRateRange()
            : minimumFrameRate( 0 ), maximumFrameRate( 0 )
        {
        }

        constexpr FrameRateRange( qreal minimum, qreal maximum )
            : minimumFrameRate( minimum ), maximumFrameRate( maximum )
        {
        }

        qreal minimumFrameRate;
        qreal maximumFrameRate;
    };

    enum Status
    {
        UnavailableStatus,
        UnloadedStatus,
        UnloadingStatus,
        LoadingStatus,
        LoadedStatus,
        StandbyStatus,
        StartingStatus,
        StoppingStatus,
        ActiveStatus
    };

    enum State
    {
        UnloadedState,
        LoadedState,
        ActiveState
    };

    enum CaptureMode
    {
        CaptureViewfinder = 0,
        CaptureStillImage = 0x01,
        CaptureVideo      = 0x02
    };
    using CaptureModes = QFlags<CaptureMode>;

    enum Error
    {
        NoError,
        CameraError,
        InvalidRequestError,
        ServiceMissingError,
        NotSupportedFeatureError
    };

    enum LockStatus
    {
        Unlocked,
        Searching,
        Locked
    };

    enum LockChangeReason
    {
        UserRequest,
        LockAcquired,
        LockFailed,
        LockLost,
        LockTemporaryLost
    };

    enum LockType
    {
        NoLock = 0,
        LockExposure = 0x01,
        LockWhiteBalance = 0x02,
        LockFocus = 0x04
    };
    using LockTypes = QFlags<LockType>;

    enum Position
    {
        UnspecifiedPosition,
        BackFace,
        FrontFace
    };

    explicit QCamera( QObject *parent = nullptr );
    explicit QCamera( const QByteArray &deviceName, QObject *parent = nullptr );
    explicit QCamera( const QCameraInfo &cameraInfo, QObject *parent = nullptr );
    explicit QCamera( QCamera::Position position, QObject *parent = nullptr );

    QCamera( const QCamera & ) = delete;
    QCamera &operator=( const QCamera & ) = delete;

    ~QCamera();

    QMultimedia::AvailabilityStatus availability() const override;

    State state() const;
    Status status() const;

    CaptureModes captureMode() const;
    bool isCaptureModeSupported( CaptureModes mode ) const;

    QCameraExposure *exposure() const;
    QCameraFocus *focus() const;
    QCameraImageProcessing *imageProcessing() const;

    void setViewfinder( QVideoWidget *viewfinder );
    void setViewfinder( QGraphicsVideoItem *viewfinder );
    void setViewfinder( QAbstractVideoSurface *surface );

    QCameraViewfinderSettings viewfinderSettings() const;
    void setViewfinderSettings( const QCameraViewfinderSettings &settings );

    QList<QCameraViewfinderSettings> supportedViewfinderSettings(
        const QCameraViewfinderSettings &settings = QCameraViewfinderSettings() ) const;

    QList<QSize> supportedViewfinderResolutions(
        const QCameraViewfinderSettings &settings = QCameraViewfinderSettings() ) const;

    QList<FrameRateRange> supportedViewfinderFrameRateRanges(
        const QCameraViewfinderSettings &settings = QCameraViewfinderSettings() ) const;

    QList<QVideoFrame::PixelFormat> supportedViewfinderPixelFormats(
        const QCameraViewfinderSettings &settings = QCameraViewfinderSettings() ) const;

    QCamera::Error error() const;
    QString errorString() const;

    QCamera::LockTypes supportedLocks() const;
    QCamera::LockTypes requestedLocks() const;

    // wrapper for overloaded method
    QCamera::LockStatus cs_lockStatus() const
    {
        return lockStatus();
    }

    QCamera::LockStatus lockStatus() const;
    QCamera::LockStatus lockStatus( QCamera::LockType lockType ) const;

    MULTI_LSCS_SLOT_1( Public, void setCaptureMode( QCamera::CaptureModes mode ) )
    MULTI_LSCS_SLOT_2( setCaptureMode )

    MULTI_LSCS_SLOT_1( Public, void load() )
    MULTI_LSCS_SLOT_2( load )

    MULTI_LSCS_SLOT_1( Public, void unload() )
    MULTI_LSCS_SLOT_2( unload )

    MULTI_LSCS_SLOT_1( Public, void start() )
    MULTI_LSCS_SLOT_2( start )

    MULTI_LSCS_SLOT_1( Public, void stop() )
    MULTI_LSCS_SLOT_2( stop )

    MULTI_LSCS_SLOT_1( Public, void searchAndLock() )
    MULTI_LSCS_SLOT_OVERLOAD( searchAndLock, () )

    MULTI_LSCS_SLOT_1( Public, void searchAndLock( QCamera::LockTypes locks ) )
    MULTI_LSCS_SLOT_OVERLOAD( searchAndLock, ( QCamera::LockTypes ) )

    MULTI_LSCS_SLOT_1( Public, void unlock() )
    MULTI_LSCS_SLOT_OVERLOAD( unlock, () )

    MULTI_LSCS_SLOT_1( Public, void unlock( QCamera::LockTypes locks ) )
    MULTI_LSCS_SLOT_OVERLOAD( unlock, ( QCamera::LockTypes ) )


    MULTI_LSCS_SIGNAL_1( Public, void captureModeChanged( QCamera::CaptureModes mode ) )
    MULTI_LSCS_SIGNAL_2( captureModeChanged, mode )

    MULTI_LSCS_SIGNAL_1( Public, void error( QCamera::Error error ) )
    MULTI_LSCS_SIGNAL_OVERLOAD( error, ( QCamera::Error ), error )

    MULTI_LSCS_SIGNAL_1( Public, void stateChanged( QCamera::State state ) )
    MULTI_LSCS_SIGNAL_2( stateChanged, state )

    MULTI_LSCS_SIGNAL_1( Public, void statusChanged( QCamera::Status status ) )
    MULTI_LSCS_SIGNAL_2( statusChanged, status )

    MULTI_LSCS_SIGNAL_1( Public, void locked() )
    MULTI_LSCS_SIGNAL_2( locked )

    MULTI_LSCS_SIGNAL_1( Public, void lockFailed() )
    MULTI_LSCS_SIGNAL_2( lockFailed )

    MULTI_LSCS_SIGNAL_1( Public, void cs_lockStatusChanged( QCamera::LockStatus status, QCamera::LockChangeReason reason ) )
    MULTI_LSCS_SIGNAL_2( cs_lockStatusChanged, status, reason )

    MULTI_LSCS_SIGNAL_1( Public, void lockStatusChanged( QCamera::LockStatus status, QCamera::LockChangeReason reason ) )
    MULTI_LSCS_SIGNAL_OVERLOAD( lockStatusChanged, ( QCamera::LockStatus, QCamera::LockChangeReason ), status, reason )

    MULTI_LSCS_SIGNAL_1( Public, void lockStatusChanged( QCamera::LockType type, QCamera::LockStatus status,
                       QCamera::LockChangeReason reason ) )
    MULTI_LSCS_SIGNAL_OVERLOAD( lockStatusChanged, ( QCamera::LockType, QCamera::LockStatus, QCamera::LockChangeReason ), type, status,
                              reason )

private:
    Q_DECLARE_PRIVATE( QCamera )

    MULTI_LSCS_SLOT_1( Private, void _q_preparePropertyChange( int changeType ) )
    MULTI_LSCS_SLOT_2( _q_preparePropertyChange )

    MULTI_LSCS_SLOT_1( Private, void _q_restartCamera() )
    MULTI_LSCS_SLOT_2( _q_restartCamera )

    MULTI_LSCS_SLOT_1( Private, void _q_error( int error, const QString &errorString ) )
    MULTI_LSCS_SLOT_2( _q_error )

    MULTI_LSCS_SLOT_1( Private, void _q_updateLockStatus( QCamera::LockType type, QCamera::LockStatus status,
                     QCamera::LockChangeReason reason ) )
    MULTI_LSCS_SLOT_2( _q_updateLockStatus )

    MULTI_LSCS_SLOT_1( Private, void _q_updateState( QCamera::State state ) )
    MULTI_LSCS_SLOT_2( _q_updateState )

    friend class QCameraInfo;
};

Q_DECLARE_OPERATORS_FOR_FLAGS( QCamera::LockTypes )

constexpr inline bool operator==( const QCamera::FrameRateRange &r1, const QCamera::FrameRateRange &r2 )
{
    return r1.minimumFrameRate == r2.minimumFrameRate && r1.maximumFrameRate == r2.maximumFrameRate;
}

constexpr inline bool operator!=( const QCamera::FrameRateRange &r1, const QCamera::FrameRateRange &r2 )
{
    return ! ( r1 == r2 );
}

#endif
