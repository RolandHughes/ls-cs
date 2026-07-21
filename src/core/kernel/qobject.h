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

#ifndef QOBJECT_H
#define QOBJECT_H

#include <lscsobject_macro.h>

// include before qmetaobject.h
#include <lscsregister1.h>

#include <qmetaobject.h>
#include <lscsregister2.h>

// must be after lscsregister2.h>
#include <lscsmeta.h>

#include <qlist.h>
#include <qpointer.h>
#include <qreadwritelock.h>
#include <qsharedpointer.h>
#include <qstring8.h>

#include <atomic>
#include <mutex>
#include <type_traits>

using QObjectList = QList<QObject *>;

#if ! defined(LSCS_NO_EMIT)
#define emit
#endif

class LSCSAbstractDeclarativeData;
class LSCSInternalChildren;
class LSCSInternalDeclarativeData;
class LSCSInternalEvents;
class LSCSInternalRefCount;
class LSCSInternalSender;
class LSCSInternalThreadData;

class QChildEvent;
class QEvent;
class QTimerEvent;
class QThread;
class QThreadData;

class QTimerInfo
{
public:
    int timerId;
    int interval;
    Qt::TimerType timerType;

    QTimerInfo( int id, int i, Qt::TimerType t )
        : timerId( id ), interval( i ), timerType( t )
    { }
};

class Q_CORE_EXPORT QObject : public virtual LsCsSignal::SignalBase, public virtual LsCsSignal::SlotBase
{
protected:
    // used in the LSCS_OBJECT macro to define lscs_parent (ex:QObject) and lscs_class (ex:MyClass)
    using lscs_class = QObject;

private:

#undef  LSCS_OVERRIDE
#define LSCS_OVERRIDE

    CORE_LSCS_OBJECT_INTERNAL( QObject )

#undef  LSCS_OVERRIDE
#define LSCS_OVERRIDE override

    CORE_LSCS_PROPERTY_READ( objectName,  objectName )
    CORE_LSCS_PROPERTY_WRITE( objectName, setObjectName )

public:
    CORE_LSCS_INVOKABLE_CONSTRUCTOR_1( Public, explicit QObject( QObject *parent = nullptr ) )
    CORE_LSCS_INVOKABLE_CONSTRUCTOR_2( QObject, QObject * )

    QObject( const QObject & ) = delete;
    QObject &operator=( const QObject & ) = delete;

    virtual ~QObject();

    bool blockSignals( bool block );
    const QList<QObject *> &children() const;

    bool connect( const QObject *sender, const QString &signalMethod, const QString &location,
                  const QString &slotMethod, Qt::ConnectionType type = Qt::AutoConnection );

    bool connect( const QObject *sender, const QString &signalMethod, const QString &slotMethod,
                  Qt::ConnectionType type = Qt::AutoConnection );

    static bool connect( const QObject *sender, const QString &signalMethod, const QString &location,
                         const QObject *receiver, const QString &slotMethod, Qt::ConnectionType type = Qt::AutoConnection );

    static bool connect( const QObject *sender, const QString &signalMethod,
                         const QObject *receiver, const QString &slotMethod, Qt::ConnectionType type = Qt::AutoConnection,
                         const QString &location = QString() );

    static bool connect( const QObject *sender, const QMetaMethod &signalMethod,
                         const QObject *receiver, const QMetaMethod &slotMethod, Qt::ConnectionType type = Qt::AutoConnection );

    bool disconnect( const QString &signalMethod = QString(), const QObject *receiver = nullptr,
                     const QString &slotMethod = QString() ) const;

    bool disconnect( const QString &signalMethod, const QString &location, const QObject *receiver = nullptr,
                     const QString &slotMethod = QString() ) const;

    bool disconnect( const QObject *receiver, const QString &slotMethod = QString() ) const;

    static bool disconnect( const QObject *sender, const QString &signalMethod,
                            const QObject *receiver, const QString &slotMethod );

    static bool disconnect( const QObject *sender, std::nullptr_t, const QObject *receiver, std::nullptr_t );

    static bool disconnect( const QObject *sender, const QMetaMethod &signalMethod,
                            const QObject *receiver, const QMetaMethod &slotMethod );

    static bool disconnect( const QObject *sender, const QString &signalMethod, const QString &location,
                            const QObject *receiver, const QString &slotMethod );

    void dumpObjectTree();
    void dumpObjectInfo();

    QList<QString> dynamicPropertyNames() const;

    virtual bool event( QEvent *event );
    virtual bool eventFilter( QObject *watched, QEvent *event );
    void installEventFilter( QObject *filterObj );

    bool inherits( const QString &className ) const;
    bool isWidgetType() const;
    bool isWindowType() const;

    void killTimer( int id );

    void moveToThread( QThread *targetThread );
    QString objectName() const;
    QObject *parent() const;

    void removeEventFilter( QObject *obj );

    void setObjectName( const QString &name );
    void setParent( QObject *parent );
    bool setProperty( const QString &name, const QVariant &value );
    bool signalsBlocked() const;

    int startTimer( int interval, Qt::TimerType timerType  = Qt::CoarseTimer );

    bool lscs_InstanceOf( const QString &iid );
    virtual bool lscs_interface_query( const QString &data ) const;

    QThread *thread() const;

    // signal & slot method ptr
    template<class Sender, class SignalClass, class ...SignalArgs, class Receiver, class SlotClass, class ...SlotArgs, class SlotReturn>
    static bool connect( const Sender *sender, void ( SignalClass::*signalMethod )( SignalArgs... ),
                         const Receiver *receiver, SlotReturn ( SlotClass::*slotMethod )( SlotArgs... ),
                         Qt::ConnectionType type = Qt::AutoConnection );

    // function ptr or lambda
    template<class Sender, class SignalClass, class ...SignalArgs, class Receiver, class T>
    static bool connect( const Sender *sender, void ( SignalClass::*signalMethod )( SignalArgs... ),
                         const Receiver *receiver, T slotLambda, Qt::ConnectionType type = Qt::AutoConnection );

    // signal & slot method ptr
    template<class Sender, class SignalClass, class ...SignalArgs, class Receiver, class SlotClass, class ...SlotArgs, class SlotReturn>
    static bool disconnect( const Sender *sender, void ( SignalClass::*signalMethod )( SignalArgs... ),
                            const Receiver *receiver, SlotReturn ( SlotClass::*slotMethod )( SlotArgs... ) );

    // signal method ptr, nullptr slot
    template<class Sender, class SignalClass, class ...SignalArgs, class Receiver>
    static bool disconnect( const Sender *sender, void ( SignalClass::*signalMethod )( SignalArgs... ),
                            const Receiver *receiver, std::nullptr_t slotMethod = nullptr );

    // function ptr or lambda
    template<class Sender, class SignalClass, class ...SignalArgs, class Receiver, class T>
    static bool disconnect( const Sender *sender, void ( SignalClass::*signalMethod )( SignalArgs... ),
                            const Receiver *receiver, T slotMethod );

    template<typename T>
    T findChild( const QString &childName = QString() ) const;

    template<class T>
    QList<T> findChildren( const QString &childName = QString(), Qt::FindChildOptions options = Qt::FindChildrenRecursively ) const;

    template<class T>
    QList<T> findChildren( const QRegularExpression &regExp, Qt::FindChildOptions options = Qt::FindChildrenRecursively ) const;

    template<class T = QVariant>
    T property( const QString &name ) const;

    static QMap<std::type_index, QMetaObject *> &m_metaObjectsAll();
    static std::recursive_mutex &m_metaObjectMutex();

    CORE_LSCS_SIGNAL_1( Public, void destroyed( QObject *obj = nullptr ) )
    CORE_LSCS_SIGNAL_2( destroyed, obj )

    CORE_LSCS_SIGNAL_1( Public, void objectNameChanged( const QString &objectName ) )
    CORE_LSCS_SIGNAL_2( objectNameChanged, objectName )

    CORE_LSCS_SLOT_1( Public, void deleteLater() )
    CORE_LSCS_SLOT_2( deleteLater )

protected:
    virtual bool lscs_isWidgetType() const;
    virtual bool lscs_isWindowType() const;

    void lscs_forceRemoveChild();

    virtual void childEvent( QChildEvent *event );
    virtual void connectNotify( const QMetaMethod &signalMethod ) const;
    virtual void customEvent( QEvent *event );

    virtual void disconnectNotify( const QMetaMethod &signalMethod ) const;
    virtual void timerEvent( QTimerEvent *event );

    bool isSignalConnected( const QMetaMethod &signalMethod ) const;

    int receivers( const QString &signal ) const;

    QObject *sender() const;
    int senderSignalIndex() const;

private:
    QObject *m_parent;
    QList<QObject *> m_children;

    QObject *m_currentChildBeingDeleted;
    LSCSAbstractDeclarativeData *m_declarativeData;

    QList< QPointer<QObject>> m_eventFilters;

    QString m_objectName;
    int m_postedEvents;

    mutable std::atomic<QtSharedPointer::ExternalRefCountData *> m_sharedRefCount;

    uint m_pendTimer           : 1;
    uint m_wasDeleted          : 1;
    uint m_sentChildRemoved    : 1;
    uint m_sendChildEvents     : 1;
    uint m_receiveChildEvents  : 1;

    std::atomic<bool> m_inThreadChangeEvent;
    std::atomic<bool> m_blockSig;

    // id of the thread which owns the object
    std::atomic<QThreadData *> m_threadData;

    QList<QString> m_extra_propertyNames;
    QList<QVariant> m_extra_propertyValues;

    void deleteChildren();
    bool isSender( const QObject *receiver, const QString &signal ) const;
    void moveToThread_helper();
    void removeObject();

    bool compareThreads() const override;
    void queueSlot( LsCsSignal::PendingSlot data, LsCsSignal::ConnectionKind ) override;

    QList<QObject *> receiverList( const QMetaMethod &signalMetaMethod ) const;
    QList<QObject *> senderList() const;

    void setThreadData_helper( QThreadData *currentData, QThreadData *targetData );

    static bool check_parent_thread( QObject *parent, QThreadData *parentThreadData, QThreadData *currentThreadData );

    template<class T>
    void findChildren_helper( const QString &name, const QRegularExpression *regExp, QList<T> &list,
                              Qt::FindChildOptions options ) const;

    CORE_LSCS_SLOT_1( Private, void internal_reregisterTimers( QList<QTimerInfo> timerList ) )
    CORE_LSCS_SLOT_2( internal_reregisterTimers )

    friend QMetaObject;
    friend LSCSInternalChildren;
    friend LSCSInternalDeclarativeData;
    friend LSCSInternalThreadData;
    friend LSCSInternalRefCount;
    friend LSCSInternalSender;
    friend LSCSInternalEvents;
};

template<class T>
T QObject::findChild( const QString &childName ) const
{
    T retval = nullptr;
    QObject *temp;

    for ( int i = 0; i < m_children.size(); ++i )
    {
        temp    = m_children.at( i );
        T child = dynamic_cast<T>( temp );

        if ( child )
        {

            if ( childName.isEmpty() || child->objectName() == childName )
            {
                retval = child;
                break;
            }
        }

        retval = temp->findChild<T>( childName );

        if ( retval )
        {
            break;
        }
    }

    return retval;
}

template<class T>
QList<T> QObject::findChildren( const QString &childName, Qt::FindChildOptions options ) const
{
    QList<T> list;
    this->findChildren_helper<T>( childName, nullptr, list, options );

    return list;
}

template<typename T>
QList<T> QObject::findChildren( const QRegularExpression &regExp, Qt::FindChildOptions options ) const
{
    QList<T> list;
    this->findChildren_helper<T>( QString(), &regExp, list, options );

    return list;
}

template<class T>
void QObject::findChildren_helper( const QString &name, const QRegularExpression *regExp, QList<T> &list,
                                   Qt::FindChildOptions options ) const
{
    for ( QObject *temp : m_children )
    {
        T child = dynamic_cast<T>( temp );

        if ( child )
        {

            if ( regExp )
            {

                if ( child->objectName().contains( *regExp ) )
                {
                    list.append( child );
                }

            }
            else
            {

                if ( name.isEmpty() || child->objectName() == name )
                {
                    list.append( child );
                }
            }
        }

        if ( options & Qt::FindChildrenRecursively )
        {
            temp->findChildren_helper<T>( name, regExp, list, options );
        }
    }
}

template<class T>
T QObject::property( const QString &name ) const
{
    const QMetaObject *meta = metaObject();

    if ( name.isEmpty() || ! meta )
    {
        throw std::logic_error( "QObject::property() Invalid name or meta object" );
    }

    int id = meta->indexOfProperty( name );

    if ( id < 0 )
    {
        // dynamic property or does not exist
        const int k = m_extra_propertyNames.indexOf( name );

        if ( k < 0 )
        {
            std::string msg = meta->className().toStdString() + "::property() Property " + lscsPrintable( name ) +
                              " is invalid or does not exist";
            throw std::invalid_argument( msg );
        }

        QVariant data = m_extra_propertyValues[k];

        if ( data.canConvert<T>() )
        {
            return data.value<T>();

        }
        else
        {
            std::string msg = meta->className().toStdString() + "::property() Property " + lscsPrintable( name ) +
                              " is not the correct type";
            throw std::invalid_argument( msg );
        }
    }

    QMetaProperty p = meta->property( id );

    if ( ! p.isReadable() )
    {
        qWarning( "%s::property() Property \"%s\" is invalid or does not exist", lscsPrintable( meta->className() ),
                  lscsPrintable( name ) );
    }

    return p.read<T>( this );
}

template<>
inline QVariant QObject::property<QVariant>( const QString &name ) const
{
    const QMetaObject *metaObj = metaObject();

    if ( name.isEmpty() || ! metaObj )
    {
        return QVariant();
    }

    int index = metaObj->indexOfProperty( name );

    if ( index < 0 )
    {
        const int k = m_extra_propertyNames.indexOf( name );

        if ( k == -1 )
        {
            return QVariant();
        }

        return m_extra_propertyValues.value( k );
    }

    QMetaProperty p = metaObj->property( index );

    if ( ! p.isReadable() )
    {
        qWarning( "%s::property() Property \"%s\" is invalid or does not exist", lscsPrintable( metaObj->className() ),
                  lscsPrintable( name ) );
    }

    return p.read( this );
}

template <class T>
inline T qobject_cast( QObject *object )
{
    return dynamic_cast<T>( object );
}

template <class T>
inline T qobject_cast( const QObject *object )
{
    return dynamic_cast<T>( object );
}

template <class T>
inline const QString &qobject_interface_iid()
{
    static QString retval;
    return retval;
}

Q_CORE_EXPORT QDebug operator<<( QDebug, const QObject * );

// **
class Q_CORE_EXPORT LSCSAbstractDeclarativeData
{
public:
    static void ( *destroyed )( LSCSAbstractDeclarativeData *, QObject * );
    static void ( *parentChanged )( LSCSAbstractDeclarativeData *, QObject *, QObject * );
    static void ( *signalEmitted )( LSCSAbstractDeclarativeData *, QObject *, int, void ** );
    static int  ( *receivers )( LSCSAbstractDeclarativeData *, const QObject *, int );
};

// **
class Q_CORE_EXPORT LsCSGadget_Fake_Parent final
{
    // no code should appear here
};

// **
class Q_CORE_EXPORT LSCSInternalChildren
{
private:
    static void deleteChildren( QObject *object );
    static void moveChildren( QObject *object, int from, int to );
    static void removeOne( QObject *object, QObject *value );
    static void set_mParent( QObject *object, QObject *value );

    friend class QWidget;
    friend class QWidgetPrivate;
};

class Q_CORE_EXPORT LSCSInternalDeclarativeData
{
private:
    static LSCSAbstractDeclarativeData *get_m_declarativeData( const QObject *object );
    static void set_m_declarativeData( QObject *object, LSCSAbstractDeclarativeData *value );

    friend class QWidget;
    friend class QGraphicsItem;
};

class Q_CORE_EXPORT LSCSInternalEvents
{
private:
    static int get_m_PostedEvents( const QObject *object );
    static void incr_PostedEvents( QObject *object );
    static void decr_PostedEvents( QObject *object );

    static bool get_m_sendChildEvents( const QObject *object );
    static bool get_m_receiveChildEvents( const QObject *object );
    static void set_m_sendChildEvents( QObject *object, bool data );
    static void set_m_receiveChildEvents( QObject *object, bool data );

    static QList<QPointer<QObject>> &get_m_EventFilters( QObject *object );
    static std::atomic<bool> &get_m_inThreadChangeEvent( QObject *object );

    friend class QApplication;
    friend class QCoreApplication;
    friend class QCoreApplicationPrivate;
    friend class QEventDispatcherMac;
    friend class QEventDispatcherMacPrivate;
    friend class QEventDispatcherWin32Private;
    friend class QFocusFramePrivate;
    friend class QStateMachinePrivate;
    friend class QTimerInfoList;
    friend class QThreadData;
    friend class QWidget;
    friend class QWidgetPrivate;

    friend struct QDeclarativeGraphics_DerivedObject;
};

class Q_CORE_EXPORT LSCSInternalRefCount
{
private:
    static bool get_m_wasDeleted( const QObject *object );
    static std::atomic<QtSharedPointer::ExternalRefCountData *> &get_m_SharedRefCount( const QObject *object );

    static void set_m_wasDeleted( QObject *object, bool data );

    friend class QGraphicsItem;
    friend class QStackedLayout;
    friend class QtFriendlyLayoutWidget;
    friend struct QtSharedPointer::ExternalRefCountData;
};

class Q_CORE_EXPORT LSCSInternalSender
{
private:
    static bool isSender( const QObject *object, const QObject *receiver, const QString &signal );
    static QObjectList receiverList( const QObject *object, const QMetaMethod &signalMetaMethod );
    static QObjectList senderList( const QObject *object );

    friend class QACConnectionObject;
};

class Q_CORE_EXPORT LSCSInternalThreadData
{
private:
    static QThreadData *get_m_ThreadData( const QObject *object );
    static std::atomic<QThreadData *> &get_AtomicThreadData( QObject *object );

    friend class QApplication;
    friend class QApplicationPrivate;
    friend class QAbstractEventDispatcher;
    friend class QAbstractEventDispatcherPrivate;
    friend class QAbstractSocket;
    friend class QAbstractSocketPrivate;
    friend class QCoreApplication;
    friend class QCoreApplicationPrivate;
    friend class QCocoaWindow;
    friend class QEventLoop;
    friend class QEventLoopPrivate;
    friend class QEventDispatcherMac;
    friend class QEventDispatcherMacPrivate;
    friend class QEventDispatcherUNIX;
    friend class QEventDispatcherUNIXPrivate;
    friend class QEventDispatcherWin32;
    friend class QEventDispatcherWin32Private;
    friend class QNativeSocketEngine;
    friend class QProcessPrivate;
    friend class QSocketNotifier;
    friend class QTimerInfoList;
    friend class QWinEventNotifier;

#ifdef LSCS_BUILD_GUI_LIB
    friend QThreadData *internal_get_ThreadData( QObject *object );
#endif

};

// best way to handle declarations
#include <lscsobject_internal.h>

#endif
