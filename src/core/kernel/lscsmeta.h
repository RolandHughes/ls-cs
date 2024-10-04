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

#ifndef LSCSMETA_H
#define LSCSMETA_H

#include <lscsmetafwd.h>
#include <lscsmeta_internal_1.h>

#include <qlist.h>
#include <qmap.h>
#include <qstring8.h>
#include <qstringfwd.h>
#include <qsharedpointer.h>
#include <qvariant.h>

#include <utility>
#include <tuple>

class QMetaObject;

class Q_CORE_EXPORT QMetaClassInfo
{
public:
    QMetaClassInfo() = default;
    QMetaClassInfo( const QString &name, const QString &value );

    const QString &name() const;
    const QString &value() const;

private:
    QString m_name;
    QString m_value;
};

class Q_CORE_EXPORT QMetaEnum
{
public:
    QMetaEnum();
    QMetaEnum( const QString &name, const QString &scope, bool isFlag );

    bool isFlag() const;
    bool isValid() const;

    const QString &key( int index ) const;
    int keyCount() const;
    int keyToValue( const QString &key ) const;
    int keysToValue( const QString &keys ) const;

    const QString &name() const;
    const QString &scope() const;

    void setData( QMap<QString, int> valueMap );

    int value( int index ) const;
    const QString &valueToKey( int value ) const;
    QString valueToKeys( int value ) const;

private:
    QString m_name;
    QString m_scope;
    bool m_flag;

    QMap<QString, int> m_data;
};

class Q_CORE_EXPORT QMetaMethod
{
public:
    enum Access
    {
        Private,
        Protected,
        Public
    };

    enum MethodType
    {
        Method,
        Signal,
        Slot,
        Constructor
    };

    // might be internal
    enum Attributes
    {
        Compatibility = 0x1,
        Cloned        = 0x2,
        Scriptable    = 0x4
    };

    QMetaMethod( const QString &typeName, const QString &signature, std::vector<QString> paramNames,
                 Access access, MethodType methodType, Attributes attributes, QMetaObject *obj );

    QMetaMethod();

    Access access() const;
    Attributes attributes() const;

    bool compare( const LsCsSignal::Internal::BentoAbstract &method ) const;

    template <typename SignalClass, typename ...SignalArgs>
    static QMetaMethod fromSignal( void ( SignalClass::* signalMethod )( SignalArgs ... ) );

    const CSBentoAbstract *getBentoBox() const;
    const QMetaObject *getMetaObject() const;

    bool isValid() const;

    const QString name() const;

    int methodIndex() const;
    MethodType methodType() const;

    QList<QString> parameterNames() const;
    QList<QString> parameterTypes() const;

    int parameterCount() const;
    uint parameterType( int index ) const;

    const QString &methodSignature() const;
    const QString &typeName() const;

    int revision() const;
    void setRevision( int revision );

    void setBentoBox( const CSBentoAbstract *method );

    void setTag( const QString &data );
    const QString &tag() const;

    template <class R, class ...Ts>
    bool invoke( QObject *object, Qt::ConnectionType type, LSCSReturnArgument<R> retval, Ts &&... Vs ) const;

    template <class R, class ...Ts>
    bool invoke( QObject *object, LSCSReturnArgument<R> retval, Ts &&... Vs ) const;

    template <class ...Ts>
    bool invoke( QObject *object, Qt::ConnectionType type, Ts &&... Vs ) const;

    template <class ...Ts>
    bool invoke( QObject *object, Ts &&... Vs ) const;

private:
    int m_revision;
    QString m_typeName;
    QString m_signature;

    QList<QString> m_paramNames;

    Access       m_access;
    MethodType   m_methodType;
    Attributes   m_attributes;
    QMetaObject *m_metaObject;

    QString m_tag;
    const CSBentoAbstract *m_bento;

    friend bool operator==( const QMetaMethod &method1, const QMetaMethod &method2 );
    friend bool operator!=( const QMetaMethod &method1, const QMetaMethod &method2 );
};

inline bool operator==( const QMetaMethod &method1, const QMetaMethod &method2 )
{
    if ( method1.m_metaObject != method2.m_metaObject )
    {
        return false;
    }

    if ( method1.m_signature != method2.m_signature )
    {
        return false;
    }

    return true;
}

inline bool operator!=( const QMetaMethod &method1, const QMetaMethod &method2 )
{
    return !( method1 == method2 );
}

class Q_CORE_EXPORT QMetaProperty
{
public:
    enum Kind
    {
        READ,
        WRITE,
        RESET,
        NOTIFY,
        REVISION,
        DESIGNABLE,
        SCRIPTABLE,
        STORED,
        USER,
        CONSTANT,
        FINAL
    };

    QMetaProperty( const QString &name = QString(), QMetaObject *object = nullptr );

    bool isReadable() const;
    bool isWritable() const;
    bool isResettable() const;
    bool isDesignable( const QObject *object = nullptr ) const;
    bool isScriptable( const QObject *object = nullptr ) const;
    bool isStored( const QObject *object = nullptr ) const;
    bool isUser( const QObject *object = nullptr ) const;
    bool isConstant() const;
    bool isFinal() const;
    bool isValid() const;
    bool isFlagType() const;
    bool isEnumType() const;

    QMetaEnum enumerator() const;

    bool hasNotifySignal() const;
    bool hasStdCppSet() const;

    const QString &name() const;
    QMetaMethod notifySignal() const;
    int notifySignalIndex() const;
    int propertyIndex() const;

    QVariant read( const QObject *obj ) const;

    // Note: Doxypress docs must be located here due to an overload with similar signatures

    //! Reads the property's value from the given \a obj. Returns the property value if
    //! valid, otherwise returns a default constructed T.
    template <class T>
    T read( const QObject *obj ) const;

    bool reset( QObject *obj ) const;
    int revision() const;

    void setConstant();
    void setFinal();
    void setRevision( int value );
    void setTypeName( const QString &typeName );

    const QString &typeName() const;
    QVariant::Type type() const;
    uint userType() const;
    bool write( QObject *object, const QVariant &value ) const;

    // properties
    void setReadMethod( std::type_index returnTypeId, QString ( *returnTypeFuncPtr )(), JarReadAbstract *jarRead );
    void setWriteMethod( JarWriteAbstract *method, const QString &methodName );

    template <class T>
    void setNotifyMethod( T method );

    template <class T>
    void setResetMethod( void ( T::*method )() );

    void setDesignable( JarReadAbstract *method );
    void setScriptable( JarReadAbstract *method );
    void setStored( JarReadAbstract *method );
    void setUser( JarReadAbstract *method );

private:
    void loadTypeName() const;

    QMetaObject *m_metaObject;

    QString m_name;
    QString m_typeName;
    QString m_writeMethodName;

    std::type_index m_returnTypeId;
    QString ( *m_returnTypeFuncPtr )();

    bool m_read_able;
    bool m_write_able;
    bool m_reset_able;
    bool m_notify_able;

    int  m_revision;
    bool m_constant;
    bool m_final;

    //
    JarReadAbstract *m_readJar;
    JarReadAbstract *m_designJar;
    JarReadAbstract *m_scriptJar;
    JarReadAbstract *m_storedJar;
    JarReadAbstract *m_userJar;

    JarWriteAbstract *m_writeJar;
    JarResetAbstract *m_resetJar;

    CSBentoAbstract *m_notifyBento;
};

// **

template <typename SignalClass, typename ...SignalArgs>
QMetaMethod QMetaMethod::fromSignal( void ( SignalClass::* signalMethod )( SignalArgs ... ) )
{
    const auto &metaObj = SignalClass::staticMetaObject();

    CSBento<void( SignalClass::* )( SignalArgs ... )> tmp = CSBento<void( SignalClass::* )( SignalArgs ... )>( signalMethod );
    QMetaMethod testMethod = metaObj.lookUpMethod( tmp );

    if ( testMethod.methodType() == QMetaMethod::Signal )
    {
        return testMethod;
    }

    return QMetaMethod();
}

// QMetaMethod::invoke moved to lscsobject_internal.h becasue invoke() calls methods in QObject
// template <class ...Ts>
// bool QMetaMethod::invoke(QObject *object, Qt::ConnectionType type, LSCSReturnArgument<R> retval, Ts&&...Vs)

template <class R, class ...Ts>
bool QMetaMethod::invoke( QObject *object, LSCSReturnArgument<R> retval, Ts &&...Vs ) const
{
    // calls first overload
    return this->invoke( object, Qt::AutoConnection, retval, std::forward<Ts>( Vs )... );
}

template <class ...Ts>
bool QMetaMethod::invoke( QObject *object, Ts &&...Vs ) const
{
    // calls third overload, no return value from the invoked method
    return this->invoke( object, Qt::AutoConnection, std::forward<Ts>( Vs )... );
}

// **
template <class T, class = void>
class LSCS_ReturnType
{
public:
    static const QString &getName()
    {
        static_assert( ! std::is_same_v<T, T>, "Requested type name has not been registered." );
        static const QString retval;
        return retval;
    }
};

#if ! defined (LSCS_DOXYPRESS)

#define LSCS_REGISTER_CLASS(dataType) \
   class dataType;                  \
   LSCS_REGISTER_TYPE(dataType)

// specialization of a templated function
#define LSCS_REGISTER_TYPE(dataType)                       \
   template <>                                           \
   inline const QString &lscs_typeToName<dataType>()       \
   {                                                     \
      static const QString retval(#dataType);            \
      return retval;                                     \
   }

// specialization of a templated class
#define LSCS_REGISTER_TEMPLATE(dataType)                    \
   template <class... Ts>                                 \
   class LSCS_ReturnType<dataType<Ts...>>                   \
   {                                                      \
    public:                                               \
      static const QString &getName();                    \
   };                                                     \
   template <class... Ts>                                 \
   const QString &LSCS_ReturnType< dataType<Ts...> >::getName()                               \
   {                                                                                        \
      static const QString retval(QString(#dataType) + "<" + lscs_typeToName<Ts...>() + ">"); \
      return retval;                                                                        \
   }

#endif   // doxypress

// methods for these 2 class, located in csmeta_internal2.h around line 113
template <class E>
class LSCS_ReturnType<E, typename std::enable_if<std::is_enum_v<E>>::type>
{
public:
    static const QString &getName();
};

template <class E>
class LSCS_ReturnType<QFlags<E>>
{
public:
    static const QString &getName();
};

// QObject and children
template <class T>
class LSCS_ReturnType<T, typename std::enable_if< std::is_base_of< QMetaObject,
          typename std::remove_reference< decltype( T::staticMetaObject() )>::type >::value>::type >
{
public:
    static const QString &getName();
};

template <class T>
const QString &LSCS_ReturnType<T, typename std::enable_if< std::is_base_of< QMetaObject,
      typename std::remove_reference<decltype( T::staticMetaObject() )>::type>::value>::type>::getName()
{
    return T::staticMetaObject().className();
}

// standard template function   ( class T1 = lscs_internalEmpty, default value located in lscsmetafwd.h )
template <class T1>
const QString &lscs_typeToName()
{
    if constexpr ( std::is_same_v<T1, lscs_internalEmpty> )
    {
        static const QString retval( "" );
        return retval;

    }
    else if constexpr ( std::is_const_v<std::remove_pointer_t<T1>> &&std::is_pointer_v<T1> )
    {
        static const QString retval = "const " + lscs_typeToName<std::remove_const_t<std::remove_pointer_t<T1>>>() + "*";
        return retval;

    }
    else if constexpr ( std::is_pointer_v<T1> )
    {
        static const QString retval = lscs_typeToName<std::remove_pointer_t<T1>>() + "*";
        return retval;

    }
    else if constexpr ( std::is_const_v<std::remove_reference_t<T1>> &&std::is_lvalue_reference_v<T1> )
    {
        static const QString retval = "const " + lscs_typeToName<std::remove_const_t<std::remove_reference_t<T1>>>() + "&";
        return retval;

    }
    else if constexpr ( std::is_lvalue_reference_v<T1> )
    {
        static const QString retval = lscs_typeToName<std::remove_reference_t<T1>>() + "&";
        return retval;

    }
    else if constexpr ( std::is_rvalue_reference_v<T1> )
    {
        static const QString retval = lscs_typeToName<std::remove_reference_t<T1>>() + "&&";
        return retval;

    }
    else if constexpr ( std::is_base_of_v<QObject, T1> )
    {
        // T1 inherits from QObject
        return T1::staticMetaObject().className();

    }
    else
    {
        // uses the class which was set up in the lscs_register_template macro
        return LSCS_ReturnType<T1>::getName();
    }
}

template <class T>
const QString &lscs_typeToName_fold()
{
    static const QString retval = "," + lscs_typeToName<T>();

    return retval;
}

template <class T1, class T2, class ...Ts>
const QString &lscs_typeToName()
{
    // fold expression
    static const QString retval = ( ( lscs_typeToName<T1>() + "," + lscs_typeToName<T2>() ) + ... + lscs_typeToName_fold<Ts>() );

    return retval;
}

// register names of all types which are used in QVariant

// primitive
LSCS_REGISTER_TYPE( bool )
LSCS_REGISTER_TYPE( short )
LSCS_REGISTER_TYPE( unsigned short )
LSCS_REGISTER_TYPE( int )
LSCS_REGISTER_TYPE( unsigned int )
LSCS_REGISTER_TYPE( long )
LSCS_REGISTER_TYPE( unsigned long )
LSCS_REGISTER_TYPE( long long )
LSCS_REGISTER_TYPE( unsigned long long )
LSCS_REGISTER_TYPE( double )
LSCS_REGISTER_TYPE( long double )
LSCS_REGISTER_TYPE( float )

LSCS_REGISTER_TYPE( char )
LSCS_REGISTER_TYPE( signed char )
LSCS_REGISTER_TYPE( unsigned char )
//  LSCS_REGISTER_TYPE(char8_t)          // add with C++20
LSCS_REGISTER_TYPE( char16_t )
LSCS_REGISTER_TYPE( char32_t )
LSCS_REGISTER_TYPE( void )

LSCS_REGISTER_CLASS( QBitArray )
LSCS_REGISTER_CLASS( QByteArray )
LSCS_REGISTER_CLASS( QChar32 )
LSCS_REGISTER_CLASS( QString8 )
LSCS_REGISTER_CLASS( QString16 )
LSCS_REGISTER_CLASS( QStringList )

LSCS_REGISTER_CLASS( QDate )
LSCS_REGISTER_CLASS( QDateTime )
LSCS_REGISTER_CLASS( QTime )
LSCS_REGISTER_CLASS( QTimeZone )
LSCS_REGISTER_CLASS( QLocale )

LSCS_REGISTER_CLASS( QJsonValue )
LSCS_REGISTER_CLASS( QJsonObject )
LSCS_REGISTER_CLASS( QJsonArray )
LSCS_REGISTER_CLASS( QJsonDocument )

LSCS_REGISTER_CLASS( QLine )
LSCS_REGISTER_CLASS( QLineF )
LSCS_REGISTER_CLASS( QPoint )
LSCS_REGISTER_CLASS( QPointF )
LSCS_REGISTER_CLASS( QPolygon )
LSCS_REGISTER_CLASS( QPolygonF )
LSCS_REGISTER_CLASS( QRect )
LSCS_REGISTER_CLASS( QRectF )
LSCS_REGISTER_CLASS( QSize )
LSCS_REGISTER_CLASS( QSizeF )

// core
LSCS_REGISTER_CLASS( QEasingCurve )
LSCS_REGISTER_CLASS( QMargins )
LSCS_REGISTER_CLASS( QModelIndex )
LSCS_REGISTER_CLASS( QPersistentModelIndex )
LSCS_REGISTER_CLASS( QUrl )
LSCS_REGISTER_CLASS( QUuid )
LSCS_REGISTER_CLASS( QVariant )

// gui
LSCS_REGISTER_CLASS( QBitmap )
LSCS_REGISTER_CLASS( QBrush )
LSCS_REGISTER_CLASS( QColor )
LSCS_REGISTER_CLASS( QCursor )
LSCS_REGISTER_CLASS( QFont )
LSCS_REGISTER_CLASS( QIcon )
LSCS_REGISTER_CLASS( QImage )
LSCS_REGISTER_CLASS( QKeySequence )
LSCS_REGISTER_CLASS( QMatrix )
LSCS_REGISTER_CLASS( QMatrix4x4 )
LSCS_REGISTER_CLASS( QPalette )
LSCS_REGISTER_CLASS( QPen )
LSCS_REGISTER_CLASS( QPixmap )
LSCS_REGISTER_CLASS( QQuaternion )
LSCS_REGISTER_CLASS( QRegion )
LSCS_REGISTER_CLASS( QSizePolicy )
LSCS_REGISTER_CLASS( QTextLength )
LSCS_REGISTER_CLASS( QTextFormat )
LSCS_REGISTER_CLASS( QTransform )
LSCS_REGISTER_CLASS( QVector2D )
LSCS_REGISTER_CLASS( QVector3D )
LSCS_REGISTER_CLASS( QVector4D )

LSCS_REGISTER_TYPE( QRegularExpression8 )
LSCS_REGISTER_TYPE( QRegularExpression16 )
LSCS_REGISTER_TYPE( QStringView8 )
LSCS_REGISTER_TYPE( QStringView16 )

LSCS_REGISTER_TEMPLATE( QHash )
LSCS_REGISTER_TEMPLATE( QList )
LSCS_REGISTER_TEMPLATE( QMap )
LSCS_REGISTER_TEMPLATE( QMultiHash )
LSCS_REGISTER_TEMPLATE( QMultiMap )

// added for invokable or property return types
LSCS_REGISTER_CLASS( QTimerInfo )
LSCS_REGISTER_TEMPLATE( QSharedPointer )
LSCS_REGISTER_TEMPLATE( QWeakPointer )
LSCS_REGISTER_TEMPLATE( std::pair )

#if ! defined (LSCS_DOXYPRESS)

// next 8 function are specializations for containers to omit the Compare template when it is not specified
template <class Key, class Value>
class LSCS_ReturnType<QMap<Key, Value, qMapCompare<Key>>>
{
public:
    static const QString &getName()
    {
        static QString retval( "QMap<" + lscs_typeToName<Key>() + "," + lscs_typeToName<Value>() + ">" );
        return retval;
    }
};

template <class Key, class Value>
class LSCS_ReturnType<QMultiMap<Key, Value, qMapCompare<Key>>>
{
public:
    static const QString &getName()
    {
        static const QString retval( "QMultiMap<" + lscs_typeToName<Key>() + "," + lscs_typeToName<Value>() + ">" );
        return retval;
    }
};

template <class Key, class Value>
class LSCS_ReturnType<QHash<Key, Value, qHashFunc<Key>, qHashEqual<Key>>>
{
public:
    static const QString &getName()
    {
        static const QString retval( "QHash<" + lscs_typeToName<Key>() + "," + lscs_typeToName<Value>() + ">" );
        return retval;
    }
};

template <class Key, class Value>
class LSCS_ReturnType<QMultiHash<Key, Value, qHashFunc<Key>, qHashEqual<Key>>>
{
public:
    static const QString &getName()
    {
        static const QString retval( "QMultiHash<" + lscs_typeToName<Key>() + "," + lscs_typeToName<Value>() + ">" );
        return retval;
    }
};

#endif   // doxypress

// **
template <class T>
T QMetaProperty::read( const QObject *object ) const
{
    if ( ! object || ! m_readJar )
    {
        throw std::logic_error( "QMetaProperty::read() Object was null" );
    }

    return m_readJar->run<T>( object );
}

template <class T>
void QMetaProperty::setNotifyMethod( T method )
{
    if ( ! method )
    {
        return;
    }

    CSBento<T> *temp = new CSBento<T>( method );
    m_notifyBento  = temp;

    m_notify_able = true;
}

template <class T>
void QMetaProperty::setResetMethod( void ( T::*method )() )
{
    if ( ! method )
    {
        return;
    }

    m_resetJar   = new SpiceJarReset<T>( method );
    m_reset_able = true;
}

#endif
