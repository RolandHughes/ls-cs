/*
    Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies)

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


#ifndef qdeclarativewebview_p_h
#define qdeclarativewebview_p_h

#include <QBasicTimer>
#include <QUrl>
#include <QtDeclarative/QDeclarativeItem>
#include <qaction.h>
#include <qnetaccess_manager.h>

#include "qgraphicswebview.h"
#include "qwebpage.h"

class QWebHistory;
class QWebSettings;
class QDeclarativeWebSettings;
class QDeclarativeWebViewPrivate;
class QNetworkRequest;
class QDeclarativeWebView;
class QDeclarativeWebViewPrivate;

class QDeclarativeWebPage : public QWebPage
{
    WEB_LSCS_OBJECT( QDeclarativeWebPage )

public:
    explicit QDeclarativeWebPage( QDeclarativeWebView *parent );
    ~QDeclarativeWebPage();

protected:
    QWebPage *createWindow( WebWindowType type );
    QString chooseFile( QWebFrame *originatingFrame, const QString &oldFile );
    void javaScriptAlert( QWebFrame *originatingFrame, const QString &msg );
    bool javaScriptConfirm( QWebFrame *originatingFrame, const QString &msg );
    bool javaScriptPrompt( QWebFrame *originatingFrame, const QString &msg, const QString &defaultValue, QString *result );

private:
    QDeclarativeWebView *viewItem();
};

class GraphicsWebView : public QGraphicsWebView
{
    WEB_LSCS_OBJECT( GraphicsWebView )

public:
    GraphicsWebView( QDeclarativeWebView *parent = 0 );

protected:
    void mousePressEvent( QGraphicsSceneMouseEvent *event );
    void mouseReleaseEvent( QGraphicsSceneMouseEvent *event );
    void mouseMoveEvent( QGraphicsSceneMouseEvent *event );
    void mouseDoubleClickEvent( QGraphicsSceneMouseEvent *event );
    void timerEvent( QTimerEvent *event );
    bool sceneEvent( QEvent *event );

public:
    WEB_LSCS_SIGNAL_1( Public, void doubleClick( int clickX,int clickY ) )
    WEB_LSCS_SIGNAL_2( doubleClick,clickX,clickY )

private:
    QDeclarativeWebView *parent;
    QPointF pressPoint;
    QBasicTimer pressTimer;
    int pressTime; // milliseconds before the touch event becomes a "tap and hold"
    friend class QDeclarativeWebView;
};

class QDeclarativeWebViewAttached;

// TODO: browser plugins

class QDeclarativeWebView : public QDeclarativeItem
{
    WEB_LSCS_OBJECT( QDeclarativeWebView )

    WEB_LSCS_ENUM( Status )
    WEB_LSCS_ENUM( SelectionMode )

    WEB_LSCS_PROPERTY_READ( title, title )
    WEB_LSCS_PROPERTY_NOTIFY( title, titleChanged )
    WEB_LSCS_PROPERTY_READ( icon, icon )
    WEB_LSCS_PROPERTY_NOTIFY( icon, iconChanged )
    WEB_LSCS_PROPERTY_READ( statusText, statusText )
    WEB_LSCS_PROPERTY_NOTIFY( statusText, statusTextChanged )

    WEB_LSCS_PROPERTY_READ( html, html )
    WEB_LSCS_PROPERTY_WRITE( html, setHtml )
    WEB_LSCS_PROPERTY_NOTIFY( html, htmlChanged )

    WEB_LSCS_PROPERTY_READ( pressGrabTime, pressGrabTime )
    WEB_LSCS_PROPERTY_WRITE( pressGrabTime, setPressGrabTime )
    WEB_LSCS_PROPERTY_NOTIFY( pressGrabTime, pressGrabTimeChanged )

    WEB_LSCS_PROPERTY_READ( preferredWidth, preferredWidth )
    WEB_LSCS_PROPERTY_WRITE( preferredWidth, setPreferredWidth )
    WEB_LSCS_PROPERTY_NOTIFY( preferredWidth, preferredWidthChanged )
    WEB_LSCS_PROPERTY_READ( preferredHeight, preferredHeight )
    WEB_LSCS_PROPERTY_WRITE( preferredHeight, setPreferredHeight )
    WEB_LSCS_PROPERTY_NOTIFY( preferredHeight, preferredHeightChanged )
    WEB_LSCS_PROPERTY_READ( url, url )
    WEB_LSCS_PROPERTY_WRITE( url, setUrl )
    WEB_LSCS_PROPERTY_NOTIFY( url, urlChanged )
    WEB_LSCS_PROPERTY_READ( progress, progress )
    WEB_LSCS_PROPERTY_NOTIFY( progress, progressChanged )
    WEB_LSCS_PROPERTY_READ( status, status )
    WEB_LSCS_PROPERTY_NOTIFY( status, statusChanged )

#ifndef LSCS_NO_ACTION
    WEB_LSCS_PROPERTY_READ( reload, reloadAction )
    WEB_LSCS_PROPERTY_CONSTANT( reload )
    WEB_LSCS_PROPERTY_READ( back, backAction )
    WEB_LSCS_PROPERTY_CONSTANT( back )
    WEB_LSCS_PROPERTY_READ( forward, forwardAction )
    WEB_LSCS_PROPERTY_CONSTANT( forward )
    WEB_LSCS_PROPERTY_READ( stop, stopAction )
    WEB_LSCS_PROPERTY_CONSTANT( stop )
#endif

    WEB_LSCS_PROPERTY_READ( settings, settingsObject )
    WEB_LSCS_PROPERTY_CONSTANT( settings )

    WEB_LSCS_PROPERTY_READ( javaScriptWindowObjects, javaScriptWindowObjects )
    WEB_LSCS_PROPERTY_CONSTANT( javaScriptWindowObjects )

    WEB_LSCS_PROPERTY_READ( newWindowComponent, newWindowComponent )
    WEB_LSCS_PROPERTY_WRITE( newWindowComponent, setNewWindowComponent )
    WEB_LSCS_PROPERTY_NOTIFY( newWindowComponent, newWindowComponentChanged )
    WEB_LSCS_PROPERTY_READ( newWindowParent, newWindowParent )
    WEB_LSCS_PROPERTY_WRITE( newWindowParent, setNewWindowParent )
    WEB_LSCS_PROPERTY_NOTIFY( newWindowParent, newWindowParentChanged )

    WEB_LSCS_PROPERTY_READ( renderingEnabled, renderingEnabled )
    WEB_LSCS_PROPERTY_WRITE( renderingEnabled, setRenderingEnabled )
    WEB_LSCS_PROPERTY_NOTIFY( renderingEnabled, renderingEnabledChanged )

    WEB_LSCS_PROPERTY_READ( contentsSize, contentsSize )
    WEB_LSCS_PROPERTY_NOTIFY( contentsSize, contentsSizeChanged )
    WEB_LSCS_PROPERTY_READ( contentsScale, contentsScale )
    WEB_LSCS_PROPERTY_WRITE( contentsScale, setContentsScale )
    WEB_LSCS_PROPERTY_NOTIFY( contentsScale, contentsScaleChanged )

    WEB_LSCS_PROPERTY_READ( backgroundColor, backgroundColor )
    WEB_LSCS_PROPERTY_WRITE( backgroundColor, setBackgroundColor )
    WEB_LSCS_PROPERTY_NOTIFY( backgroundColor, backgroundColorChanged )
    WEB_LSCS_PROPERTY_REVISION( backgroundColor, 1 )

public:
    QDeclarativeWebView( QDeclarativeItem *parent = nullptr );

    QDeclarativeWebView( const QDeclarativeWebView & ) = delete;
    QDeclarativeWebView &operator=( const QDeclarativeWebView & ) = delete;

    ~QDeclarativeWebView();

    QUrl url() const;
    void setUrl( const QUrl & );

    QString title() const;
    QPixmap icon() const;

    WEB_LSCS_INVOKABLE_METHOD_1( Public, bool heuristicZoom( int clickX, int clickY, qreal maxzoom ) )
    WEB_LSCS_INVOKABLE_METHOD_2( heuristicZoom )

    QRect elementAreaAt( int x, int y, int minwidth, int minheight ) const;

    int pressGrabTime() const;
    void setPressGrabTime( int );

    int preferredWidth() const;
    void setPreferredWidth( int );
    int preferredHeight() const;
    void setPreferredHeight( int );

    enum Status { Null, Ready, Loading, Error };
    Status status() const;
    qreal progress() const;
    QString statusText() const;

#ifndef LSCS_NO_ACTION
    QAction *reloadAction() const;
    QAction *backAction() const;
    QAction *forwardAction() const;
    QAction *stopAction() const;
#endif

    QWebPage *page() const;
    void setPage( QWebPage *page );

    void load( const QNetworkRequest &request,
               QNetworkAccessManager::Operation operation = QNetworkAccessManager::GetOperation,
               const QByteArray &body = QByteArray() );

    QString html() const;

    void setHtml( const QString &html, const QUrl &baseUrl = QUrl() );
    void setContent( const QByteArray &data, const QString &mimeType = QString(), const QUrl &baseUrl = QUrl() );

    QWebHistory *history() const;
    QWebSettings *settings() const;
    QDeclarativeWebSettings *settingsObject() const;

    bool renderingEnabled() const;
    void setRenderingEnabled( bool );

    QDeclarativeListProperty<QObject> javaScriptWindowObjects();

    static QDeclarativeWebViewAttached *qmlAttachedProperties( QObject * );

    QDeclarativeComponent *newWindowComponent() const;
    void setNewWindowComponent( QDeclarativeComponent *newWindow );
    QDeclarativeItem *newWindowParent() const;
    void setNewWindowParent( QDeclarativeItem *newWindow );

    bool isComponentCompletePublic() const
    {
        return isComponentComplete();
    }

    QSize contentsSize() const;

    void setContentsScale( qreal scale );
    qreal contentsScale() const;

    QColor backgroundColor() const;
    void setBackgroundColor( const QColor & );

    WEB_LSCS_SIGNAL_1( Public, void preferredWidthChanged() )
    WEB_LSCS_SIGNAL_2( preferredWidthChanged )
    WEB_LSCS_SIGNAL_1( Public, void preferredHeightChanged() )
    WEB_LSCS_SIGNAL_2( preferredHeightChanged )
    WEB_LSCS_SIGNAL_1( Public, void urlChanged() )
    WEB_LSCS_SIGNAL_2( urlChanged )
    WEB_LSCS_SIGNAL_1( Public, void progressChanged() )
    WEB_LSCS_SIGNAL_2( progressChanged )
    WEB_LSCS_SIGNAL_1( Public, void statusChanged( Status newStatus ) )
    WEB_LSCS_SIGNAL_2( statusChanged,newStatus )
    WEB_LSCS_SIGNAL_1( Public, void titleChanged( const QString &newTitle ) )
    WEB_LSCS_SIGNAL_2( titleChanged,newTitle )
    WEB_LSCS_SIGNAL_1( Public, void iconChanged() )
    WEB_LSCS_SIGNAL_2( iconChanged )
    WEB_LSCS_SIGNAL_1( Public, void statusTextChanged() )
    WEB_LSCS_SIGNAL_2( statusTextChanged )
    WEB_LSCS_SIGNAL_1( Public, void htmlChanged() )
    WEB_LSCS_SIGNAL_2( htmlChanged )
    WEB_LSCS_SIGNAL_1( Public, void pressGrabTimeChanged() )
    WEB_LSCS_SIGNAL_2( pressGrabTimeChanged )
    WEB_LSCS_SIGNAL_1( Public, void newWindowComponentChanged() )
    WEB_LSCS_SIGNAL_2( newWindowComponentChanged )
    WEB_LSCS_SIGNAL_1( Public, void newWindowParentChanged() )
    WEB_LSCS_SIGNAL_2( newWindowParentChanged )
    WEB_LSCS_SIGNAL_1( Public, void renderingEnabledChanged() )
    WEB_LSCS_SIGNAL_2( renderingEnabledChanged )
    WEB_LSCS_SIGNAL_1( Public, void contentsSizeChanged( const QSize &newSize ) )
    WEB_LSCS_SIGNAL_2( contentsSizeChanged,newSize )
    WEB_LSCS_SIGNAL_1( Public, void contentsScaleChanged() )
    WEB_LSCS_SIGNAL_2( contentsScaleChanged )

    WEB_LSCS_SIGNAL_1( Public, void backgroundColorChanged() )
    WEB_LSCS_SIGNAL_2( backgroundColorChanged )

    WEB_LSCS_SIGNAL_1( Public, void loadStarted() )
    WEB_LSCS_SIGNAL_2( loadStarted )

    WEB_LSCS_SIGNAL_1( Public, void loadFinished() )
    WEB_LSCS_SIGNAL_2( loadFinished )

    WEB_LSCS_SIGNAL_1( Public, void loadFailed() )
    WEB_LSCS_SIGNAL_2( loadFailed )

    WEB_LSCS_SIGNAL_1( Public, void doubleClick( int clickX,int clickY ) )
    WEB_LSCS_SIGNAL_2( doubleClick,clickX,clickY )

    WEB_LSCS_SIGNAL_1( Public, void zoomTo( qreal zoom,int centerX,int centerY ) )
    WEB_LSCS_SIGNAL_2( zoomTo,zoom,centerX,centerY )

    WEB_LSCS_SIGNAL_1( Public, void alert( const QString &message ) )
    WEB_LSCS_SIGNAL_2( alert,message )

    WEB_LSCS_SLOT_1( Public, QVariant evaluateJavaScript( const QString &scriptSource ) )
    WEB_LSCS_SLOT_2( evaluateJavaScript )

private:
    WEB_LSCS_SLOT_1( Private, void doLoadStarted() )
    WEB_LSCS_SLOT_2( doLoadStarted )
    WEB_LSCS_SLOT_1( Private, void doLoadProgress( int p ) )
    WEB_LSCS_SLOT_2( doLoadProgress )
    WEB_LSCS_SLOT_1( Private, void doLoadFinished( bool ok ) )
    WEB_LSCS_SLOT_2( doLoadFinished )
    WEB_LSCS_SLOT_1( Private, void setStatusText( const QString &text ) )
    WEB_LSCS_SLOT_2( setStatusText )
    WEB_LSCS_SLOT_1( Private, void windowObjectCleared() )
    WEB_LSCS_SLOT_2( windowObjectCleared )
    WEB_LSCS_SLOT_1( Private, void pageUrlChanged() )
    WEB_LSCS_SLOT_2( pageUrlChanged )
    WEB_LSCS_SLOT_1( Private, void initialLayout() )
    WEB_LSCS_SLOT_2( initialLayout )

    WEB_LSCS_SLOT_1( Private, void updateDeclarativeWebViewSize() )
    WEB_LSCS_SLOT_2( updateDeclarativeWebViewSize )

    WEB_LSCS_SLOT_1( Private, virtual void geometryChanged( const QRectF &newGeometry,const QRectF &oldGeometry ) )
    WEB_LSCS_SLOT_2( geometryChanged )
    WEB_LSCS_SLOT_1( Private, QDeclarativeWebView *createWindow( QWebPage::WebWindowType type ) )
    WEB_LSCS_SLOT_2( createWindow )

    void updateContentsSize();
    void init();
    virtual void componentComplete();

    QDeclarativeWebViewPrivate *d;
    QMouseEvent *sceneMouseEventToMouseEvent( QGraphicsSceneMouseEvent * );
    QMouseEvent *sceneHoverMoveEventToMouseEvent( QGraphicsSceneHoverEvent * );

    friend class QDeclarativeWebPage;
};

class QDeclarativeWebViewAttached : public QObject
{
    WEB_LSCS_OBJECT( QDeclarativeWebViewAttached )

    WEB_LSCS_PROPERTY_READ( windowObjectName, windowObjectName )
    WEB_LSCS_PROPERTY_WRITE( windowObjectName, setWindowObjectName )

public:
    QDeclarativeWebViewAttached( QObject *parent )
        : QObject( parent )
    {
    }

    QString windowObjectName() const
    {
        return m_windowObjectName;
    }

    void setWindowObjectName( const QString &n )
    {
        m_windowObjectName = n;
    }

private:
    QString m_windowObjectName;
};

class QDeclarativeWebSettings : public QObject
{
    WEB_LSCS_OBJECT( QDeclarativeWebSettings )

    WEB_LSCS_PROPERTY_READ( standardFontFamily, standardFontFamily )
    WEB_LSCS_PROPERTY_WRITE( standardFontFamily, setStandardFontFamily )
    WEB_LSCS_PROPERTY_READ( fixedFontFamily, fixedFontFamily )
    WEB_LSCS_PROPERTY_WRITE( fixedFontFamily, setFixedFontFamily )
    WEB_LSCS_PROPERTY_READ( serifFontFamily, serifFontFamily )
    WEB_LSCS_PROPERTY_WRITE( serifFontFamily, setSerifFontFamily )
    WEB_LSCS_PROPERTY_READ( sansSerifFontFamily, sansSerifFontFamily )
    WEB_LSCS_PROPERTY_WRITE( sansSerifFontFamily, setSansSerifFontFamily )
    WEB_LSCS_PROPERTY_READ( cursiveFontFamily, cursiveFontFamily )
    WEB_LSCS_PROPERTY_WRITE( cursiveFontFamily, setCursiveFontFamily )
    WEB_LSCS_PROPERTY_READ( fantasyFontFamily, fantasyFontFamily )
    WEB_LSCS_PROPERTY_WRITE( fantasyFontFamily, setFantasyFontFamily )

    WEB_LSCS_PROPERTY_READ( minimumFontSize, minimumFontSize )
    WEB_LSCS_PROPERTY_WRITE( minimumFontSize, setMinimumFontSize )
    WEB_LSCS_PROPERTY_READ( minimumLogicalFontSize, minimumLogicalFontSize )
    WEB_LSCS_PROPERTY_WRITE( minimumLogicalFontSize, setMinimumLogicalFontSize )
    WEB_LSCS_PROPERTY_READ( defaultFontSize, defaultFontSize )
    WEB_LSCS_PROPERTY_WRITE( defaultFontSize, setDefaultFontSize )
    WEB_LSCS_PROPERTY_READ( defaultFixedFontSize, defaultFixedFontSize )
    WEB_LSCS_PROPERTY_WRITE( defaultFixedFontSize, setDefaultFixedFontSize )

    WEB_LSCS_PROPERTY_READ( autoLoadImages, autoLoadImages )
    WEB_LSCS_PROPERTY_WRITE( autoLoadImages, setAutoLoadImages )
    WEB_LSCS_PROPERTY_READ( javascriptEnabled, javascriptEnabled )
    WEB_LSCS_PROPERTY_WRITE( javascriptEnabled, setJavascriptEnabled )
    WEB_LSCS_PROPERTY_READ( javaEnabled, javaEnabled )
    WEB_LSCS_PROPERTY_WRITE( javaEnabled, setJavaEnabled )
    WEB_LSCS_PROPERTY_READ( pluginsEnabled, pluginsEnabled )
    WEB_LSCS_PROPERTY_WRITE( pluginsEnabled, setPluginsEnabled )
    WEB_LSCS_PROPERTY_READ( privateBrowsingEnabled, privateBrowsingEnabled )
    WEB_LSCS_PROPERTY_WRITE( privateBrowsingEnabled, setPrivateBrowsingEnabled )
    WEB_LSCS_PROPERTY_READ( javascriptCanOpenWindows, javascriptCanOpenWindows )
    WEB_LSCS_PROPERTY_WRITE( javascriptCanOpenWindows, setJavascriptCanOpenWindows )
    WEB_LSCS_PROPERTY_READ( javascriptCanAccessClipboard, javascriptCanAccessClipboard )
    WEB_LSCS_PROPERTY_WRITE( javascriptCanAccessClipboard, setJavascriptCanAccessClipboard )
    WEB_LSCS_PROPERTY_READ( developerExtrasEnabled, developerExtrasEnabled )
    WEB_LSCS_PROPERTY_WRITE( developerExtrasEnabled, setDeveloperExtrasEnabled )
    WEB_LSCS_PROPERTY_READ( linksIncludedInFocusChain, linksIncludedInFocusChain )
    WEB_LSCS_PROPERTY_WRITE( linksIncludedInFocusChain, setLinksIncludedInFocusChain )
    WEB_LSCS_PROPERTY_READ( zoomTextOnly, zoomTextOnly )
    WEB_LSCS_PROPERTY_WRITE( zoomTextOnly, setZoomTextOnly )
    WEB_LSCS_PROPERTY_READ( printElementBackgrounds, printElementBackgrounds )
    WEB_LSCS_PROPERTY_WRITE( printElementBackgrounds, setPrintElementBackgrounds )
    WEB_LSCS_PROPERTY_READ( offlineStorageDatabaseEnabled, offlineStorageDatabaseEnabled )
    WEB_LSCS_PROPERTY_WRITE( offlineStorageDatabaseEnabled, setOfflineStorageDatabaseEnabled )
    WEB_LSCS_PROPERTY_READ( offlineWebApplicationCacheEnabled, offlineWebApplicationCacheEnabled )
    WEB_LSCS_PROPERTY_WRITE( offlineWebApplicationCacheEnabled, setOfflineWebApplicationCacheEnabled )
    WEB_LSCS_PROPERTY_READ( localStorageDatabaseEnabled, localStorageDatabaseEnabled )
    WEB_LSCS_PROPERTY_WRITE( localStorageDatabaseEnabled, setLocalStorageDatabaseEnabled )
    WEB_LSCS_PROPERTY_READ( localContentCanAccessRemoteUrls, localContentCanAccessRemoteUrls )
    WEB_LSCS_PROPERTY_WRITE( localContentCanAccessRemoteUrls, setLocalContentCanAccessRemoteUrls )

public:
    QDeclarativeWebSettings() {}

    QString standardFontFamily() const
    {
        return s->fontFamily( QWebSettings::StandardFont );
    }
    void setStandardFontFamily( const QString &f )
    {
        s->setFontFamily( QWebSettings::StandardFont, f );
    }
    QString fixedFontFamily() const
    {
        return s->fontFamily( QWebSettings::FixedFont );
    }
    void setFixedFontFamily( const QString &f )
    {
        s->setFontFamily( QWebSettings::FixedFont, f );
    }
    QString serifFontFamily() const
    {
        return s->fontFamily( QWebSettings::SerifFont );
    }
    void setSerifFontFamily( const QString &f )
    {
        s->setFontFamily( QWebSettings::SerifFont, f );
    }
    QString sansSerifFontFamily() const
    {
        return s->fontFamily( QWebSettings::SansSerifFont );
    }
    void setSansSerifFontFamily( const QString &f )
    {
        s->setFontFamily( QWebSettings::SansSerifFont, f );
    }
    QString cursiveFontFamily() const
    {
        return s->fontFamily( QWebSettings::CursiveFont );
    }
    void setCursiveFontFamily( const QString &f )
    {
        s->setFontFamily( QWebSettings::CursiveFont, f );
    }
    QString fantasyFontFamily() const
    {
        return s->fontFamily( QWebSettings::FantasyFont );
    }
    void setFantasyFontFamily( const QString &f )
    {
        s->setFontFamily( QWebSettings::FantasyFont, f );
    }

    int minimumFontSize() const
    {
        return s->fontSize( QWebSettings::MinimumFontSize );
    }
    void setMinimumFontSize( int size )
    {
        s->setFontSize( QWebSettings::MinimumFontSize, size );
    }
    int minimumLogicalFontSize() const
    {
        return s->fontSize( QWebSettings::MinimumLogicalFontSize );
    }
    void setMinimumLogicalFontSize( int size )
    {
        s->setFontSize( QWebSettings::MinimumLogicalFontSize, size );
    }
    int defaultFontSize() const
    {
        return s->fontSize( QWebSettings::DefaultFontSize );
    }
    void setDefaultFontSize( int size )
    {
        s->setFontSize( QWebSettings::DefaultFontSize, size );
    }
    int defaultFixedFontSize() const
    {
        return s->fontSize( QWebSettings::DefaultFixedFontSize );
    }
    void setDefaultFixedFontSize( int size )
    {
        s->setFontSize( QWebSettings::DefaultFixedFontSize, size );
    }

    bool autoLoadImages() const
    {
        return s->testAttribute( QWebSettings::AutoLoadImages );
    }
    void setAutoLoadImages( bool on )
    {
        s->setAttribute( QWebSettings::AutoLoadImages, on );
    }
    bool javascriptEnabled() const
    {
        return s->testAttribute( QWebSettings::JavascriptEnabled );
    }
    void setJavascriptEnabled( bool on )
    {
        s->setAttribute( QWebSettings::JavascriptEnabled, on );
    }
    bool javaEnabled() const
    {
        return s->testAttribute( QWebSettings::JavaEnabled );
    }
    void setJavaEnabled( bool on )
    {
        s->setAttribute( QWebSettings::JavaEnabled, on );
    }
    bool pluginsEnabled() const
    {
        return s->testAttribute( QWebSettings::PluginsEnabled );
    }
    void setPluginsEnabled( bool on )
    {
        s->setAttribute( QWebSettings::PluginsEnabled, on );
    }
    bool privateBrowsingEnabled() const
    {
        return s->testAttribute( QWebSettings::PrivateBrowsingEnabled );
    }
    void setPrivateBrowsingEnabled( bool on )
    {
        s->setAttribute( QWebSettings::PrivateBrowsingEnabled, on );
    }
    bool javascriptCanOpenWindows() const
    {
        return s->testAttribute( QWebSettings::JavascriptCanOpenWindows );
    }
    void setJavascriptCanOpenWindows( bool on )
    {
        s->setAttribute( QWebSettings::JavascriptCanOpenWindows, on );
    }
    bool javascriptCanAccessClipboard() const
    {
        return s->testAttribute( QWebSettings::JavascriptCanAccessClipboard );
    }
    void setJavascriptCanAccessClipboard( bool on )
    {
        s->setAttribute( QWebSettings::JavascriptCanAccessClipboard, on );
    }
    bool developerExtrasEnabled() const
    {
        return s->testAttribute( QWebSettings::DeveloperExtrasEnabled );
    }
    void setDeveloperExtrasEnabled( bool on )
    {
        s->setAttribute( QWebSettings::DeveloperExtrasEnabled, on );
    }
    bool linksIncludedInFocusChain() const
    {
        return s->testAttribute( QWebSettings::LinksIncludedInFocusChain );
    }
    void setLinksIncludedInFocusChain( bool on )
    {
        s->setAttribute( QWebSettings::LinksIncludedInFocusChain, on );
    }
    bool zoomTextOnly() const
    {
        return s->testAttribute( QWebSettings::ZoomTextOnly );
    }
    void setZoomTextOnly( bool on )
    {
        s->setAttribute( QWebSettings::ZoomTextOnly, on );
    }
    bool printElementBackgrounds() const
    {
        return s->testAttribute( QWebSettings::PrintElementBackgrounds );
    }
    void setPrintElementBackgrounds( bool on )
    {
        s->setAttribute( QWebSettings::PrintElementBackgrounds, on );
    }
    bool offlineStorageDatabaseEnabled() const
    {
        return s->testAttribute( QWebSettings::OfflineStorageDatabaseEnabled );
    }
    void setOfflineStorageDatabaseEnabled( bool on )
    {
        s->setAttribute( QWebSettings::OfflineStorageDatabaseEnabled, on );
    }
    bool offlineWebApplicationCacheEnabled() const
    {
        return s->testAttribute( QWebSettings::OfflineWebApplicationCacheEnabled );
    }
    void setOfflineWebApplicationCacheEnabled( bool on )
    {
        s->setAttribute( QWebSettings::OfflineWebApplicationCacheEnabled, on );
    }
    bool localStorageDatabaseEnabled() const
    {
        return s->testAttribute( QWebSettings::LocalStorageEnabled );
    }
    void setLocalStorageDatabaseEnabled( bool on )
    {
        s->setAttribute( QWebSettings::LocalStorageEnabled, on );
    }
    bool localContentCanAccessRemoteUrls() const
    {
        return s->testAttribute( QWebSettings::LocalContentCanAccessRemoteUrls );
    }
    void setLocalContentCanAccessRemoteUrls( bool on )
    {
        s->setAttribute( QWebSettings::LocalContentCanAccessRemoteUrls, on );
    }

    QWebSettings *s;
};

QML_DECLARE_TYPE( QDeclarativeWebView )
QML_DECLARE_TYPE( QDeclarativeWebSettings )
QML_DECLARE_TYPEINFO( QDeclarativeWebView, QML_HAS_ATTACHED_PROPERTIES )

#endif
