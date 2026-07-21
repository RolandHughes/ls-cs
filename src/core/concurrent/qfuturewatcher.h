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

#ifndef QFUTUREWATCHER_H
#define QFUTUREWATCHER_H

#include <qfuture.h>
#include <qobject.h>
#include <qscopedpointer.h>

class QEvent;
class QFutureWatcherBasePrivate;

class Q_CORE_EXPORT QFutureWatcherBase : public QObject
{
    CORE_LSCS_OBJECT( QFutureWatcherBase )
    Q_DECLARE_PRIVATE( QFutureWatcherBase )

public:
    QFutureWatcherBase( QObject *parent = nullptr );
    ~QFutureWatcherBase();

    int progressValue() const;
    int progressMinimum() const;
    int progressMaximum() const;
    QString progressText() const;

    bool isStarted() const;
    bool isFinished() const;
    bool isRunning() const;
    bool isCanceled() const;
    bool isPaused() const;

    void waitForFinished();

    void setPendingResultsLimit( int limit );

    bool event( QEvent *event ) override;

    CORE_LSCS_SIGNAL_1( Public, void started() )
    CORE_LSCS_SIGNAL_2( started )
    CORE_LSCS_SIGNAL_1( Public, void finished() )
    CORE_LSCS_SIGNAL_2( finished )
    CORE_LSCS_SIGNAL_1( Public, void canceled() )
    CORE_LSCS_SIGNAL_2( canceled )
    CORE_LSCS_SIGNAL_1( Public, void paused() )
    CORE_LSCS_SIGNAL_2( paused )
    CORE_LSCS_SIGNAL_1( Public, void resumed() )
    CORE_LSCS_SIGNAL_2( resumed )
    CORE_LSCS_SIGNAL_1( Public, void resultReadyAt( int index ) )
    CORE_LSCS_SIGNAL_2( resultReadyAt, index )
    CORE_LSCS_SIGNAL_1( Public, void resultsReadyAt( int beginIndex, int endIndex ) )
    CORE_LSCS_SIGNAL_2( resultsReadyAt, beginIndex, endIndex )
    CORE_LSCS_SIGNAL_1( Public, void progressRangeChanged( int minimum, int maximum ) )
    CORE_LSCS_SIGNAL_2( progressRangeChanged, minimum, maximum )
    CORE_LSCS_SIGNAL_1( Public, void progressValueChanged( int progressValue ) )
    CORE_LSCS_SIGNAL_2( progressValueChanged, progressValue )
    CORE_LSCS_SIGNAL_1( Public, void progressTextChanged( const QString &progressText ) )
    CORE_LSCS_SIGNAL_2( progressTextChanged, progressText )

    CORE_LSCS_SLOT_1( Public, void cancel() )
    CORE_LSCS_SLOT_2( cancel )
    CORE_LSCS_SLOT_1( Public, void setPaused( bool paused ) )
    CORE_LSCS_SLOT_2( setPaused )
    CORE_LSCS_SLOT_1( Public, void pause() )
    CORE_LSCS_SLOT_2( pause )
    CORE_LSCS_SLOT_1( Public, void resume() )
    CORE_LSCS_SLOT_2( resume )
    CORE_LSCS_SLOT_1( Public, void togglePaused() )
    CORE_LSCS_SLOT_2( togglePaused )

protected:
    void connectNotify ( const QMetaMethod &signal ) const override;
    void disconnectNotify ( const QMetaMethod &signal ) const override;

    // called from setFuture() implemented in template sub-classes
    void connectOutputInterface();
    void disconnectOutputInterface( bool pendingAssignment = false );

    QScopedPointer<QFutureWatcherBasePrivate> d_ptr;

private:
    // implemented in the template sub-classes
    virtual const QFutureInterfaceBase &futureInterface() const = 0;
    virtual QFutureInterfaceBase &futureInterface() = 0;
};

template <typename T>
class QFutureWatcher : public QFutureWatcherBase
{
public:
    QFutureWatcher( QObject *parent = nullptr )
        : QFutureWatcherBase( parent )
    {
    }

    ~QFutureWatcher()
    {
        disconnectOutputInterface();
    }

    void setFuture( const QFuture<T> &future );
    QFuture<T> future() const
    {
        return m_future;
    }

    T result() const
    {
        return m_future.result();
    }
    T resultAt( int index ) const
    {
        return m_future.resultAt( index );
    }

private:
    QFuture<T> m_future;
    const QFutureInterfaceBase &futureInterface() const override
    {
        return m_future.d;
    }

    QFutureInterfaceBase &futureInterface() override
    {
        return m_future.d;
    }
};

template <typename T>
inline void QFutureWatcher<T>::setFuture( const QFuture<T> &future )
{
    if ( future == m_future )
    {
        return;
    }

    disconnectOutputInterface( true );
    m_future = future;
    connectOutputInterface();
}

template <>
class QFutureWatcher<void> : public QFutureWatcherBase
{
public:
    QFutureWatcher( QObject *parent = nullptr )
        : QFutureWatcherBase( parent )
    {
    }

    ~QFutureWatcher()
    {
        disconnectOutputInterface();
    }

    void setFuture( const QFuture<void> &future );
    QFuture<void> future() const
    {
        return m_future;
    }

private:
    QFuture<void> m_future;
    const QFutureInterfaceBase &futureInterface() const override
    {
        return m_future.d;
    }

    QFutureInterfaceBase &futureInterface() override
    {
        return m_future.d;
    }
};

inline void QFutureWatcher<void>::setFuture( const QFuture<void> &future )
{
    if ( future == m_future )
    {
        return;
    }

    disconnectOutputInterface( true );
    m_future = future;
    connectOutputInterface();
}

#endif // QFUTUREWATCHER_H
