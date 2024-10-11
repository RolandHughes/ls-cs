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

#ifndef QSOUNDEFFECT_QAUDIO_H
#define QSOUNDEFFECT_QAUDIO_H

#include <qobject.h>
#include <qurl.h>
#include <qaudiooutput.h>
#include <qsamplecache_p.h>
#include <qsoundeffect.h>

class QSoundEffectPrivate;

class PrivateSoundSource : public QIODevice
{
    MULTI_LSCS_OBJECT( PrivateSoundSource )

public:
    PrivateSoundSource( QSoundEffectPrivate *s );
    ~PrivateSoundSource() {}

    qint64 readData( char *data, qint64 len ) override;
    qint64 writeData( const char *data, qint64 len ) override;

private:
    QUrl           m_url;
    int            m_loopCount;
    int            m_runningCount;
    bool           m_playing;
    QSoundEffect::Status  m_status;
    QAudioOutput   *m_audioOutput;
    QSample        *m_sample;
    bool           m_muted;
    qreal          m_volume;
    bool           m_sampleReady;
    qint64         m_offset;
    QString        m_category;

    QSoundEffectPrivate *soundeffect;

    MULTI_LSCS_SLOT_1( Private, void sampleReady() )
    MULTI_LSCS_SLOT_2( sampleReady )

    MULTI_LSCS_SLOT_1( Private, void decoderError() )
    MULTI_LSCS_SLOT_2( decoderError )

    MULTI_LSCS_SLOT_1( Private, void stateChanged( QAudio::State state ) )
    MULTI_LSCS_SLOT_2( stateChanged )

    friend class QSoundEffectPrivate;
};

class QSoundEffectPrivate : public QObject
{
    MULTI_LSCS_OBJECT( QSoundEffectPrivate )

public:
    explicit QSoundEffectPrivate( QObject *parent );
    ~QSoundEffectPrivate();

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
    QSoundEffect::Status status() const;

    void release();

    QString category() const;
    void setCategory( const QString & );

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
    void setStatus( QSoundEffect::Status status );
    void setPlaying( bool playing );
    void setLoopsRemaining( int loopsRemaining );

    PrivateSoundSource *m_soundSource;

    friend class PrivateSoundSource;
};

#endif
