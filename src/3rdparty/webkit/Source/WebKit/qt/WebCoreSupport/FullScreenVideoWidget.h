/*
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FullScreenVideoWidget_h
#define FullScreenVideoWidget_h

#include <QTimer>
#include <QVideoWidget>

class QMediaPlayer;

namespace WebCore
{

class FullScreenVideoWidget : public QVideoWidget
{
    WEB_LSCS_OBJECT( FullScreenVideoWidget )
public:
    FullScreenVideoWidget();
    virtual ~FullScreenVideoWidget();
    void show( QMediaPlayer * );

public:
    WEB_LSCS_SIGNAL_1( Public, void didExitFullScreen() )
    WEB_LSCS_SIGNAL_2( didExitFullScreen )

protected:
    virtual void closeEvent( QCloseEvent * );
    virtual bool event( QEvent * );
    virtual void keyPressEvent( QKeyEvent * );

private :
    WEB_LSCS_SLOT_1( Private, void hideCursor() )
    WEB_LSCS_SLOT_2( hideCursor )

private:
    void showCursor();
    QMediaPlayer *m_mediaPlayer;
    QTimer m_cursorTimer;
};

}

#endif // FullScreenVideoWidget_h
