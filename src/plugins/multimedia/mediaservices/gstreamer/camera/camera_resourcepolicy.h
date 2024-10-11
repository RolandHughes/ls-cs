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

#ifndef CAMERARESOURCEPOLICY_H
#define CAMERARESOURCEPOLICY_H

#include <qobject.h>

namespace ResourcePolicy
{
class ResourceSet;
}

class CamerabinResourcePolicy : public QObject
{
    LSCS_OBJECT( CamerabinResourcePolicy )

public:
    enum ResourceSet
    {
        NoResources,
        LoadedResources,
        ImageCaptureResources,
        VideoCaptureResources
    };

    CamerabinResourcePolicy( QObject *parent );
    ~CamerabinResourcePolicy();

    ResourceSet resourceSet() const;
    void setResourceSet( ResourceSet set );

    bool isResourcesGranted() const;

    bool canCapture() const;

public:
    LSCS_SIGNAL_1( Public, void resourcesDenied() )
    LSCS_SIGNAL_2( resourcesDenied )
    LSCS_SIGNAL_1( Public, void resourcesGranted() )
    LSCS_SIGNAL_2( resourcesGranted )
    LSCS_SIGNAL_1( Public, void resourcesLost() )
    LSCS_SIGNAL_2( resourcesLost )
    LSCS_SIGNAL_1( Public, void canCaptureChanged() )
    LSCS_SIGNAL_2( canCaptureChanged )

private :
    LSCS_SLOT_1( Private, void handleResourcesLost() )
    LSCS_SLOT_2( handleResourcesLost )
    LSCS_SLOT_1( Private, void handleResourcesGranted() )
    LSCS_SLOT_2( handleResourcesGranted )
    LSCS_SLOT_1( Private, void handleResourcesReleased() )
    LSCS_SLOT_2( handleResourcesReleased )
    LSCS_SLOT_1( Private, void resourcesAvailable() )
    LSCS_SLOT_2( resourcesAvailable )
    LSCS_SLOT_1( Private, void updateCanCapture() )
    LSCS_SLOT_2( updateCanCapture )

private:
    ResourceSet m_resourceSet;
    ResourcePolicy::ResourceSet *m_resource;
    bool m_releasingResources;
    bool m_canCapture;
};

#endif
