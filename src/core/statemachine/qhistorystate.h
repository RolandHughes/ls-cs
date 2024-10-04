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

#ifndef QHISTORYSTATE_H
#define QHISTORYSTATE_H

#include <qabstractstate.h>

#ifndef QT_NO_STATEMACHINE

class QAbstractTransition;
class QHistoryStatePrivate;

class Q_CORE_EXPORT QHistoryState : public QAbstractState
{
    CORE_LSCS_OBJECT( QHistoryState )

    CORE_LSCS_PROPERTY_READ( defaultState,   defaultState )
    CORE_LSCS_PROPERTY_WRITE( defaultState,  setDefaultState )
    CORE_LSCS_PROPERTY_NOTIFY( defaultState, defaultStateChanged )

    CORE_LSCS_PROPERTY_READ( defaultTransition,   defaultTransition )
    CORE_LSCS_PROPERTY_WRITE( defaultTransition,  setDefaultTransition )
    CORE_LSCS_PROPERTY_NOTIFY( defaultTransition, defaultTransitionChanged )

    CORE_LSCS_PROPERTY_READ( historyType,   historyType )
    CORE_LSCS_PROPERTY_WRITE( historyType,  setHistoryType )
    CORE_LSCS_PROPERTY_NOTIFY( historyType, historyTypeChanged )

public:
    enum HistoryType
    {
        ShallowHistory,
        DeepHistory
    };

    CORE_LSCS_ENUM( HistoryType )

    QHistoryState( QState *parent = nullptr );
    QHistoryState( HistoryType type, QState *parent = nullptr );

    QHistoryState( const QHistoryState & ) = delete;
    QHistoryState &operator=( const QHistoryState & ) = delete;

    ~QHistoryState();

    QAbstractState *defaultState() const;
    void setDefaultState( QAbstractState *state );

    QAbstractTransition *defaultTransition() const;
    void setDefaultTransition( QAbstractTransition *transition );

    HistoryType historyType() const;
    void setHistoryType( HistoryType type );

    CORE_LSCS_SIGNAL_1( Public, void defaultTransitionChanged() )
    CORE_LSCS_SIGNAL_2( defaultTransitionChanged )

    CORE_LSCS_SIGNAL_1( Public, void defaultStateChanged() )
    CORE_LSCS_SIGNAL_2( defaultStateChanged )

    CORE_LSCS_SIGNAL_1( Public, void historyTypeChanged() )
    CORE_LSCS_SIGNAL_2( historyTypeChanged )

protected:
    void onEntry( QEvent *event ) override;
    void onExit( QEvent *event ) override;

    bool event( QEvent *event ) override;

private:
    Q_DECLARE_PRIVATE( QHistoryState )
};

#endif //QT_NO_STATEMACHINE

#endif
