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

#ifndef QDECLARATIVEPACKAGE_P_H
#define QDECLARATIVEPACKAGE_P_H

#include <qdeclarative.h>

LSCS_BEGIN_NAMESPACE

class QDeclarativePackagePrivate;
class QDeclarativePackageAttached;

class QDeclarativePackage : public QObject
{
    DECL_LSCS_OBJECT( QDeclarativePackage )
    Q_DECLARE_PRIVATE( QDeclarativePackage )

    DECL_LSCS_CLASSINFO( "DefaultProperty", "data" )
    DECL_LSCS_PROPERTY_READ( data, data )
    DECL_LSCS_PROPERTY_SCRIPTABLE( data, false )

public:
    QDeclarativePackage( QObject *parent = nullptr );
    virtual ~QDeclarativePackage();

    QDeclarativeListProperty<QObject> data();

    QObject *part( const QString & = QString() );
    bool hasPart( const QString & );

    static QDeclarativePackageAttached *qmlAttachedProperties( QObject * );
};

class QDeclarativePackageAttached : public QObject
{
    DECL_LSCS_OBJECT( QDeclarativePackageAttached )
    DECL_LSCS_PROPERTY_READ( name, name )
    DECL_LSCS_PROPERTY_WRITE( name, setName )
public:
    QDeclarativePackageAttached( QObject *parent );
    virtual ~QDeclarativePackageAttached();

    QString name() const;
    void setName( const QString &n );

    static QHash<QObject *, QDeclarativePackageAttached *> attached;
private:
    QString _name;
};

LSCS_END_NAMESPACE

QML_DECLARE_TYPE( QDeclarativePackage )
QML_DECLARE_TYPEINFO( QDeclarativePackage, QML_HAS_ATTACHED_PROPERTIES )

#endif // QDECLARATIVEPACKAGE_H
