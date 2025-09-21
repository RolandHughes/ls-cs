/***********************************************************************
*
* Copyright (c) 2012-2025 Barbara Geller
* Copyright (c) 2012-2025 Ansel Sermersheim
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

#ifndef QABSTRACTTRANSITION_H
#define QABSTRACTTRANSITION_H

#include <qabstractstate.h>
#include <qlist.h>
#include <qobject.h>
#include <qscopedpointer.h>
#include <qstate.h>

#ifndef LSCS_NO_STATEMACHINE

class QEvent;
class QStateMachine;

class QAbstractTransitionPrivate;

#ifndef LSCS_NO_ANIMATION
class QAbstractAnimation;
#endif

class Q_CORE_EXPORT QAbstractTransition : public QObject
{
    CORE_LSCS_OBJECT( QAbstractTransition )

    CORE_LSCS_PROPERTY_READ( sourceState, sourceState )

    CORE_LSCS_PROPERTY_READ( targetState,   targetState )
    CORE_LSCS_PROPERTY_WRITE( targetState,  setTargetState )
    CORE_LSCS_PROPERTY_NOTIFY( targetState, targetStateChanged )

    CORE_LSCS_PROPERTY_READ( targetStates,   targetStates )
    CORE_LSCS_PROPERTY_WRITE( targetStates,  setTargetStates )
    CORE_LSCS_PROPERTY_NOTIFY( targetStates, targetStatesChanged )

    CORE_LSCS_PROPERTY_READ( transitionType,      transitionType )
    CORE_LSCS_PROPERTY_WRITE( transitionType,     setTransitionType )
    CORE_LSCS_PROPERTY_REVISION( transitionType,  1 )

public:
    enum TransitionType
    {
        ExternalTransition,
        InternalTransition
    };

    CORE_LSCS_ENUM( TransitionType )

    QAbstractTransition( QState *sourceState = nullptr );

    QAbstractTransition( const QAbstractTransition & ) = delete;
    QAbstractTransition &operator=( const QAbstractTransition & ) = delete;

    virtual ~QAbstractTransition();

    QState *sourceState() const;
    QAbstractState *targetState() const;
    void setTargetState( QAbstractState *target );
    QList<QAbstractState *> targetStates() const;
    void setTargetStates( const QList<QAbstractState *> &targets );

    TransitionType transitionType() const;
    void setTransitionType( TransitionType type );
    QStateMachine *machine() const;

#ifndef LSCS_NO_ANIMATION
    void addAnimation( QAbstractAnimation *animation );
    void removeAnimation( QAbstractAnimation *animation );
    QList<QAbstractAnimation *> animations() const;
#endif

    CORE_LSCS_SIGNAL_1( Public, void triggered() )
    CORE_LSCS_SIGNAL_2( triggered )

    CORE_LSCS_SIGNAL_1( Public, void targetStateChanged() )
    CORE_LSCS_SIGNAL_2( targetStateChanged )

    CORE_LSCS_SIGNAL_1( Public, void targetStatesChanged() )
    CORE_LSCS_SIGNAL_2( targetStatesChanged )

protected:
    virtual bool eventTest( QEvent *event ) = 0;
    virtual void onTransition( QEvent *event ) = 0;

    bool event( QEvent *event ) override;

    QAbstractTransition( QAbstractTransitionPrivate &dd, QState *parent );

    QScopedPointer<QAbstractTransitionPrivate> d_ptr;

private:
    Q_DECLARE_PRIVATE( QAbstractTransition )
};

#endif // LSCS_NO_STATEMACHINE

#endif
