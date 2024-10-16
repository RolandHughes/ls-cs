/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef JSMetadataCallback_h
#define JSMetadataCallback_h

#if ENABLE(FILE_SYSTEM)

#include "ActiveDOMCallback.h"
#include "JSCallbackData.h"
#include "MetadataCallback.h"
#include <wtf/Forward.h>

namespace WebCore
{

class JSMetadataCallback : public MetadataCallback, public ActiveDOMCallback
{
public:
    static PassRefPtr<JSMetadataCallback> create( JSC::JSObject *callback, JSDOMGlobalObject *globalObject )
    {
        return adoptRef( new JSMetadataCallback( callback, globalObject ) );
    }

    virtual ~JSMetadataCallback();

    // Functions
    virtual bool handleEvent( Metadata *metadata );

private:
    JSMetadataCallback( JSC::JSObject *callback, JSDOMGlobalObject * );

    JSCallbackData *m_data;
};

} // namespace WebCore

#endif // ENABLE(FILE_SYSTEM)

#endif
