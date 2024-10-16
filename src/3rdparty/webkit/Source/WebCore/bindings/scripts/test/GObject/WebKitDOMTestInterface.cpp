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

#include <glib-object.h>
#include "config.h"

#if ENABLE(Condition1) || ENABLE(Condition2)

#include <wtf/GetPtr.h>
#include <wtf/RefPtr.h>
#include "DOMObjectCache.h"
#include "ExceptionCode.h"
#include "JSMainThreadExecState.h"
#include "TestInterface.h"
#include "WebKitDOMBinding.h"
#include "gobject/ConvertToUTF8String.h"
#include "webkit/WebKitDOMTestInterface.h"
#include "webkit/WebKitDOMTestInterfacePrivate.h"
#include "webkitdefines.h"
#include "webkitglobalsprivate.h"
#include "webkitmarshal.h"

namespace WebKit
{

WebKitDOMTestInterface *kit( WebCore::TestInterface *obj )
{
    g_return_val_if_fail( obj, 0 );

    if ( gpointer ret = DOMObjectCache::get( obj ) )
    {
        return static_cast<WebKitDOMTestInterface *>( ret );
    }

    return static_cast<WebKitDOMTestInterface *>( DOMObjectCache::put( obj, WebKit::wrapTestInterface( obj ) ) );
}

} // namespace WebKit //


G_DEFINE_TYPE( WebKitDOMTestInterface, webkit_dom_test_interface, WEBKIT_TYPE_DOM_OBJECT )

namespace WebKit
{

WebCore::TestInterface *core( WebKitDOMTestInterface *request )
{
    g_return_val_if_fail( request, 0 );

    WebCore::TestInterface *coreObject = static_cast<WebCore::TestInterface *>( WEBKIT_DOM_OBJECT( request )->coreObject );
    g_return_val_if_fail( coreObject, 0 );

    return coreObject;
}

} // namespace WebKit
enum
{
    PROP_0,
};


static void webkit_dom_test_interface_finalize( GObject *object )
{
    WebKitDOMObject *dom_object = WEBKIT_DOM_OBJECT( object );

    if ( dom_object->coreObject )
    {
        WebCore::TestInterface *coreObject = static_cast<WebCore::TestInterface *>( dom_object->coreObject );

        WebKit::DOMObjectCache::forget( coreObject );
        coreObject->deref();

        dom_object->coreObject = NULL;
    }

    G_OBJECT_CLASS( webkit_dom_test_interface_parent_class )->finalize( object );
}

static void webkit_dom_test_interface_set_property( GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec )
{
    WebCore::JSMainThreadNullState state;

    switch ( prop_id )
    {
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID( object, prop_id, pspec );
            break;
    }
}


static void webkit_dom_test_interface_get_property( GObject *object, guint prop_id, GValue *value, GParamSpec *pspec )
{
    WebCore::JSMainThreadNullState state;

    switch ( prop_id )
    {
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID( object, prop_id, pspec );
            break;
    }
}


static void webkit_dom_test_interface_constructed( GObject *object )
{

    if ( G_OBJECT_CLASS( webkit_dom_test_interface_parent_class )->constructed )
    {
        G_OBJECT_CLASS( webkit_dom_test_interface_parent_class )->constructed( object );
    }
}

static void webkit_dom_test_interface_class_init( WebKitDOMTestInterfaceClass *requestClass )
{
    GObjectClass *gobjectClass = G_OBJECT_CLASS( requestClass );
    gobjectClass->finalize = webkit_dom_test_interface_finalize;
    gobjectClass->set_property = webkit_dom_test_interface_set_property;
    gobjectClass->get_property = webkit_dom_test_interface_get_property;
    gobjectClass->constructed = webkit_dom_test_interface_constructed;



}

static void webkit_dom_test_interface_init( WebKitDOMTestInterface *request )
{
}

namespace WebKit
{
WebKitDOMTestInterface *wrapTestInterface( WebCore::TestInterface *coreObject )
{
    g_return_val_if_fail( coreObject, 0 );

    /* We call ref() rather than using a C++ smart pointer because we can't store a C++ object
     * in a C-allocated GObject structure.  See the finalize() code for the
     * matching deref().
     */
    coreObject->ref();

    return  WEBKIT_DOM_TEST_INTERFACE( g_object_new( WEBKIT_TYPE_DOM_TEST_INTERFACE,
                                       "core-object", coreObject, NULL ) );
}
} // namespace WebKit
#endif /* ENABLE(Condition1) || ENABLE(Condition2) */
