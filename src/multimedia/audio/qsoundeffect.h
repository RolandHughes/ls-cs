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

#ifndef QSOUNDEFFECT_H
#define QSOUNDEFFECT_H

#include <qobject.h>
#include <qurl.h>
#include <qstringlist.h>

class QSoundEffectPrivate;

class Q_MULTIMEDIA_EXPORT QSoundEffect : public QObject
{
    MULTI_LSCS_OBJECT( QSoundEffect )

    MULTI_LSCS_CLASSINFO( "DefaultMethod", "play()" )

    MULTI_LSCS_PROPERTY_READ( source, source )
    MULTI_LSCS_PROPERTY_WRITE( source, setSource )
    MULTI_LSCS_PROPERTY_NOTIFY( source, sourceChanged )

    MULTI_LSCS_PROPERTY_READ( loops, loopCount )
    MULTI_LSCS_PROPERTY_WRITE( loops, setLoopCount )
    MULTI_LSCS_PROPERTY_NOTIFY( loops, loopCountChanged )

    MULTI_LSCS_PROPERTY_READ( loopsRemaining, loopsRemaining )
    MULTI_LSCS_PROPERTY_NOTIFY( loopsRemaining, loopsRemainingChanged )

    MULTI_LSCS_PROPERTY_READ( volume, volume )
    MULTI_LSCS_PROPERTY_WRITE( volume, setVolume )
    MULTI_LSCS_PROPERTY_NOTIFY( volume, volumeChanged )

    MULTI_LSCS_PROPERTY_READ( muted, isMuted )
    MULTI_LSCS_PROPERTY_WRITE( muted, setMuted )
    MULTI_LSCS_PROPERTY_NOTIFY( muted, mutedChanged )

    MULTI_LSCS_PROPERTY_READ( playing, isPlaying )
    MULTI_LSCS_PROPERTY_NOTIFY( playing, playingChanged )

    MULTI_LSCS_PROPERTY_READ( status, status )
    MULTI_LSCS_PROPERTY_NOTIFY( status, statusChanged )

    MULTI_LSCS_PROPERTY_READ( category, category )
    MULTI_LSCS_PROPERTY_WRITE( category, setCategory )
    MULTI_LSCS_PROPERTY_NOTIFY( category, categoryChanged )

    MULTI_LSCS_ENUM( Loop )
    MULTI_LSCS_ENUM( Status )

public:
    enum Loop
    {
        Infinite = -2
    };

    enum Status
    {
        Null,
        Loading,
        Ready,
        Error
    };

    explicit QSoundEffect( QObject *parent = nullptr );

    QSoundEffect( const QSoundEffect & ) = delete;
    QSoundEffect &operator=( const QSoundEffect & ) = delete;

    ~QSoundEffect();

    static QStringList supportedMimeTypes();

    QUrl source() const;
    void setSource( const QUrl &url );

    int loopCount() const;
    int loopsRemaining() const;
    void setLoopCount( int loopCount );

    qreal volume() const;
    void setVolume( qreal volume );

    bool isMuted() const;
    void setMuted( bool muted );

    bool isLoaded() const;

    bool isPlaying() const;
    Status status() const;

    QString category() const;
    void setCategory( const QString &category );

    MULTI_LSCS_SIGNAL_1( Public, void sourceChanged() )
    MULTI_LSCS_SIGNAL_2( sourceChanged )

    MULTI_LSCS_SIGNAL_1( Public, void loopCountChanged() )
    MULTI_LSCS_SIGNAL_2( loopCountChanged )

    MULTI_LSCS_SIGNAL_1( Public, void loopsRemainingChanged() )
    MULTI_LSCS_SIGNAL_2( loopsRemainingChanged )

    MULTI_LSCS_SIGNAL_1( Public, void volumeChanged() )
    MULTI_LSCS_SIGNAL_2( volumeChanged )

    MULTI_LSCS_SIGNAL_1( Public, void mutedChanged() )
    MULTI_LSCS_SIGNAL_2( mutedChanged )

    MULTI_LSCS_SIGNAL_1( Public, void loadedChanged() )
    MULTI_LSCS_SIGNAL_2( loadedChanged )

    MULTI_LSCS_SIGNAL_1( Public, void playingChanged() )
    MULTI_LSCS_SIGNAL_2( playingChanged )

    MULTI_LSCS_SIGNAL_1( Public, void statusChanged() )
    MULTI_LSCS_SIGNAL_2( statusChanged )

    MULTI_LSCS_SIGNAL_1( Public, void categoryChanged() )
    MULTI_LSCS_SIGNAL_2( categoryChanged )

    MULTI_LSCS_SLOT_1( Public, void play() )
    MULTI_LSCS_SLOT_2( play )

    MULTI_LSCS_SLOT_1( Public, void stop() )
    MULTI_LSCS_SLOT_2( stop )

private:
    QSoundEffectPrivate *d;
};


#endif
