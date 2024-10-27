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

#ifndef QAPPLICATION_H
#define QAPPLICATION_H

#include <qcoreapplication.h>
#include <qcursor.h>
#include <qicon.h>
#include <qinputmethod.h>
#include <qlocale.h>
#include <qpalette.h>
#include <qpoint.h>
#include <qscreen.h>
#include <qsize.h>
#include <qstring.h>
#include <qsessionmanager.h>
#include <qwindowdefs.h>

class QApplication;
class QApplicationPrivate;
class QDesktopWidget;
class QEventLoop;
class QPlatformNativeInterface;
class QStyle;
class QStyleHints;

#if defined(qApp)
#undef qApp
#endif

using QGuiApplication        = QApplication;
using QGuiApplicationPrivate = QApplicationPrivate;

#define qApp    (static_cast<QApplication *>(QCoreApplication::instance()))
#define qGuiApp (static_cast<QApplication *>(QCoreApplication::instance()))

class Q_GUI_EXPORT QApplication : public QCoreApplication
{
    GUI_LSCS_OBJECT( QApplication )

    GUI_LSCS_PROPERTY_READ( applicationDisplayName,  lscs_applicationDisplayName )
    GUI_LSCS_PROPERTY_WRITE( applicationDisplayName, lscs_setApplicationDisplayName )

    GUI_LSCS_PROPERTY_READ( platformName,   lscs_platformName )
    GUI_LSCS_PROPERTY_STORED( platformName, false )

    GUI_LSCS_PROPERTY_READ( primaryScreen,   lscs_primaryScreen )
    GUI_LSCS_PROPERTY_NOTIFY( primaryScreen, primaryScreenChanged )
    GUI_LSCS_PROPERTY_STORED( primaryScreen, false )

    GUI_LSCS_PROPERTY_READ( layoutDirection,  lscs_layoutDirection )
    GUI_LSCS_PROPERTY_WRITE( layoutDirection, lscs_setLayoutDirection )

    GUI_LSCS_PROPERTY_READ( windowIcon,  lscs_windowIcon )
    GUI_LSCS_PROPERTY_WRITE( windowIcon, lscs_setWindowIcon )

    GUI_LSCS_PROPERTY_READ( cursorFlashTime,  lscs_cursorFlashTime )
    GUI_LSCS_PROPERTY_WRITE( cursorFlashTime, lscs_setCursorFlashTime )

    GUI_LSCS_PROPERTY_READ( doubleClickInterval,  lscs_doubleClickInterval )
    GUI_LSCS_PROPERTY_WRITE( doubleClickInterval, lscs_setDoubleClickInterval )

    GUI_LSCS_PROPERTY_READ( keyboardInputInterval,  lscs_keyboardInputInterval )
    GUI_LSCS_PROPERTY_WRITE( keyboardInputInterval, lscs_setKeyboardInputInterval )

#ifndef LSCS_NO_WHEELEVENT
    GUI_LSCS_PROPERTY_READ( wheelScrollLines,  lscs_wheelScrollLines )
    GUI_LSCS_PROPERTY_WRITE( wheelScrollLines, lscs_setWheelScrollLines )
#endif

    GUI_LSCS_PROPERTY_READ( globalStrut,  lscs_globalStrut )
    GUI_LSCS_PROPERTY_WRITE( globalStrut, lscs_setGlobalStrut )

    GUI_LSCS_PROPERTY_READ( startDragTime,  lscs_startDragTime )
    GUI_LSCS_PROPERTY_WRITE( startDragTime, lscs_setStartDragTime )

    GUI_LSCS_PROPERTY_READ( startDragDistance,  lscs_startDragDistance )
    GUI_LSCS_PROPERTY_WRITE( startDragDistance, lscs_setStartDragDistance )

    GUI_LSCS_PROPERTY_READ( quitOnLastWindowClosed,  lscs_quitOnLastWindowClosed )
    GUI_LSCS_PROPERTY_WRITE( quitOnLastWindowClosed, lscs_setQuitOnLastWindowClosed )

#ifndef LSCS_NO_STYLE_STYLESHEET
    GUI_LSCS_PROPERTY_READ( styleSheet,  styleSheet )
    GUI_LSCS_PROPERTY_WRITE( styleSheet, setStyleSheet )
#endif

    GUI_LSCS_PROPERTY_READ( autoSipEnabled,  autoSipEnabled )
    GUI_LSCS_PROPERTY_WRITE( autoSipEnabled, setAutoSipEnabled )

public:
    enum ColorSpec
    {
        NormalColor = 0,
        CustomColor = 1,
        ManyColor   = 2
    };

    using FP_Void = void( * )();

    QApplication( int &argc, char **argv, int flags = ApplicationFlags );

    QApplication( const QApplication & ) = delete;
    QApplication &operator=( const QApplication & ) = delete;

    virtual ~QApplication();

    static void setApplicationDisplayName( const QString &name );
    static QString applicationDisplayName();

    // wrapper for static method
    inline void lscs_setApplicationDisplayName( const QString &name );

    // wrapper for static method
    inline QString lscs_applicationDisplayName() const;

    static QApplication *instance()
    {
        return ( static_cast<QApplication *>( QCoreApplication::instance() ) );
    }

    static QWindowList allWindows();
    static QWindowList topLevelWindows();

    static QWindow *topLevelWindowAt( const QPoint &pos );
    static QWidget *topLevelWidgetAt( const QPoint &pos );

    static QString platformName();

    // wrapper for static method
    inline QString lscs_platformName() const;

    static QWindow *modalWindow();

    static QWindow *focusWindow();
    static QObject *focusObject();

    static QScreen *primaryScreen();

    // wrapper for static method
    inline QScreen *lscs_primaryScreen() const;

    static QList<QScreen *> screens();
    qreal devicePixelRatio() const;

    static QStyle *style();
    static void setStyle( QStyle *style );
    static QStyle *setStyle( const QString &style );

    static int colorSpec();
    static void setColorSpec( int spec );

#ifndef LSCS_NO_CURSOR
    static QCursor *overrideCursor();
    static void setOverrideCursor( const QCursor &cursor );
    static void changeOverrideCursor( const QCursor &cursor );
    static void restoreOverrideCursor();
#endif

    static QFont font();
    static QFont font( const QWidget *widget );
    static QFont font( const QString &className );
    static void setFont( const QFont &font, const QString &className = QString() );

    static QPalette palette();
    static QPalette palette( const QWidget *widget );
    static QPalette palette( const QString &className );
    static void setPalette( const QPalette &palette, const QString &className = QString() );

    static QFontMetrics fontMetrics();

    // emerald - may go away
    static void setWindowIcon( const QIcon &icon );
    static QIcon windowIcon();

    // wrapper for static method
    inline void lscs_setWindowIcon( const QIcon &icon );

    // wrapper for static method
    inline QIcon lscs_windowIcon() const;

    static QWidgetList allWidgets();
    static QWidgetList topLevelWidgets();

    static QDesktopWidget *desktop();

    static QWidget *activePopupWidget();
    static QWidget *activeModalWidget();

#ifndef LSCS_NO_CLIPBOARD
    static QClipboard *clipboard();
#endif

    static QWidget *focusWidget();

    static QWidget *activeWindow();
    static void setActiveWindow( QWidget *active );

    static QWidget *widgetAt( const QPoint &point );

    static inline QWidget *widgetAt( int x, int y )
    {
        return widgetAt( QPoint( x, y ) );
    }
    static void beep();
    static void alert( QWidget *widget, int duration = 0 );

    static Qt::KeyboardModifiers keyboardModifiers();
    static Qt::KeyboardModifiers queryKeyboardModifiers();
    static Qt::MouseButtons mouseButtons();

    static void setCursorFlashTime( int duration );
    static int cursorFlashTime();

    // wrapper for static method
    inline void lscs_setCursorFlashTime( int duration );

    // wrapper for static method
    inline int lscs_cursorFlashTime() const;

    static void setDoubleClickInterval( int interval );
    static int doubleClickInterval();

    // wrapper for static method
    inline void lscs_setDoubleClickInterval( int interval );

    // wrapper for static method
    inline int lscs_doubleClickInterval() const;

    static void setKeyboardInputInterval( int interval );
    static int keyboardInputInterval();

    // wrapper for static method
    inline void lscs_setKeyboardInputInterval( int interval );

    // wrapper for static method
    inline int lscs_keyboardInputInterval() const;

#ifndef LSCS_NO_WHEELEVENT
    static void setWheelScrollLines( int lines );
    static int wheelScrollLines();

    // wrapper for overloaded property
    inline void lscs_setWheelScrollLines( int lines );

    // wrapper for overloaded property
    inline int lscs_wheelScrollLines()  const;
#endif

    static void setGlobalStrut( const QSize &size );
    static QSize globalStrut();

    // wrapper for static method
    inline void lscs_setGlobalStrut( const QSize &size );

    // wrapper for static method
    inline QSize lscs_globalStrut() const;

    static void setStartDragTime( int time );
    static int startDragTime();

    // wrapper for static method
    inline void lscs_setStartDragTime( int time );

    // wrapper for static method
    inline int lscs_startDragTime() const;

    static void setStartDragDistance( int distance );
    static int startDragDistance();

    // wrapper for static method
    inline void lscs_setStartDragDistance( int distance );

    // wrapper for static method
    inline int lscs_startDragDistance() const;

    static void setLayoutDirection( Qt::LayoutDirection direction );
    static Qt::LayoutDirection layoutDirection();

    // wrapper for static method
    inline void lscs_setLayoutDirection( Qt::LayoutDirection direction );

    // wrapper for static method
    inline Qt::LayoutDirection lscs_layoutDirection() const;

    static inline bool isRightToLeft()
    {
        return layoutDirection() == Qt::RightToLeft;
    }

    static inline bool isLeftToRight()
    {
        return layoutDirection() == Qt::LeftToRight;
    }

    static QStyleHints *styleHints();
    static void setDesktopSettingsAware( bool on );
    static bool desktopSettingsAware();

    static QInputMethod *inputMethod();

    static QPlatformNativeInterface *platformNativeInterface();

    static FP_Void platformFunction( const QByteArray &function );

    static Qt::ApplicationState applicationState();

    static int exec();
    bool notify( QObject *receiver, QEvent *event ) override;

    static bool isEffectEnabled( Qt::UIEffect effect );
    static void setEffectEnabled( Qt::UIEffect effect, bool enable = true );

#ifndef LSCS_NO_SESSIONMANAGER
    // session management
    bool isSessionRestored() const;
    QString sessionId() const;
    QString sessionKey() const;
    bool isSavingSession() const;

    static bool isFallbackSessionManagementEnabled();
    static void setFallbackSessionManagementEnabled( bool enable );
#endif

    static void setQuitOnLastWindowClosed( bool quit );
    static bool quitOnLastWindowClosed();

    // wrapper for static method
    inline void lscs_setQuitOnLastWindowClosed( bool quit );

    // wrapper for static method
    inline bool lscs_quitOnLastWindowClosed() const;

    static void sync();

    QPixmap lscs_internal_applyQIconStyle( QIcon::Mode mode, const QPixmap &basePixmap ) const;

    GUI_LSCS_SIGNAL_1( Public, void screenAdded( QScreen *screen ) )
    GUI_LSCS_SIGNAL_2( screenAdded, screen )

    GUI_LSCS_SIGNAL_1( Public, void screenRemoved( QScreen *screen ) )
    GUI_LSCS_SIGNAL_2( screenRemoved, screen )

    GUI_LSCS_SIGNAL_1( Public, void primaryScreenChanged( QScreen *screen ) )
    GUI_LSCS_SIGNAL_2( primaryScreenChanged, screen )

    GUI_LSCS_SIGNAL_1( Public, void focusObjectChanged( QObject *focusObject ) )
    GUI_LSCS_SIGNAL_2( focusObjectChanged, focusObject )

    GUI_LSCS_SIGNAL_1( Public, void focusWindowChanged( QWindow *focusWindow ) )
    GUI_LSCS_SIGNAL_2( focusWindowChanged, focusWindow )

    GUI_LSCS_SIGNAL_1( Public, void applicationStateChanged( Qt::ApplicationState state ) )
    GUI_LSCS_SIGNAL_2( applicationStateChanged, state )

    GUI_LSCS_SIGNAL_1( Public, void layoutDirectionChanged( Qt::LayoutDirection direction ) )
    GUI_LSCS_SIGNAL_2( layoutDirectionChanged, direction )

    GUI_LSCS_SIGNAL_1( Public, void paletteChanged( const QPalette &palette ) )
    GUI_LSCS_SIGNAL_2( paletteChanged, palette )

    GUI_LSCS_SIGNAL_1( Public, void lastWindowClosed() )
    GUI_LSCS_SIGNAL_2( lastWindowClosed )

    GUI_LSCS_SIGNAL_1( Public, void focusChanged( QWidget *old, QWidget *current ) )
    GUI_LSCS_SIGNAL_2( focusChanged, old, current )

    GUI_LSCS_SIGNAL_1( Public, void fontDatabaseChanged() )
    GUI_LSCS_SIGNAL_2( fontDatabaseChanged )

#ifndef LSCS_NO_SESSIONMANAGER
    // CopperSpice - api change to pass a pointer instead of a reference
    GUI_LSCS_SIGNAL_1( Public, void commitDataRequest( QSessionManager *sessionManager ) )
    GUI_LSCS_SIGNAL_2( commitDataRequest, sessionManager )

    // CopperSpice - api change to pass a pointer instead of a reference
    GUI_LSCS_SIGNAL_1( Public, void saveStateRequest( QSessionManager *sessionManager ) )
    GUI_LSCS_SIGNAL_2( saveStateRequest, sessionManager )
#endif

    QString styleSheet() const;

#ifndef LSCS_NO_STYLE_STYLESHEET
    GUI_LSCS_SLOT_1( Public, void setStyleSheet( const QString &sheet ) )
    GUI_LSCS_SLOT_2( setStyleSheet )
#endif

    GUI_LSCS_SLOT_1( Public, void setAutoSipEnabled( const bool enabled ) )
    GUI_LSCS_SLOT_2( setAutoSipEnabled )

    GUI_LSCS_SLOT_1( Public, bool autoSipEnabled() const )
    GUI_LSCS_SLOT_2( autoSipEnabled )

    GUI_LSCS_SLOT_1( Public, static void closeAllWindows() )
    GUI_LSCS_SLOT_2( closeAllWindows )

    GUI_LSCS_SLOT_1( Public, static void aboutCs() )
    GUI_LSCS_SLOT_2( aboutCs )

    GUI_LSCS_SLOT_1( Public, static void aboutQt() )
    GUI_LSCS_SLOT_2( aboutQt )

protected:
    bool event( QEvent *event ) override;
    bool compressEvent( QEvent *event, QObject *receiver, QPostEventList *eventList ) override;

    QApplication( QApplicationPrivate &p );

private:
    Q_DECLARE_PRIVATE( QApplication )

    friend class QGraphicsWidget;
    friend class QGraphicsItem;
    friend class QGraphicsScene;
    friend class QGraphicsScenePrivate;
    friend class QWidget;
    friend class QWidgetPrivate;
    friend class QWidgetWindow;
    friend class QTranslator;
    friend class QWidgetAnimator;

    friend class QAction;
    friend class QFontDatabasePrivate;
    friend class QPlatformIntegration;

#ifndef LSCS_NO_SHORTCUT
    friend class QShortcut;
    friend class QLineEdit;
    friend class QTextControl;
#endif

#ifndef LSCS_NO_GESTURES
    friend class QGestureManager;
#endif

#ifndef LSCS_NO_SESSIONMANAGER
    friend class QPlatformSessionManager;
#endif

    GUI_LSCS_SLOT_1( Private, void _q_updateFocusObject( QObject *object ) )
    GUI_LSCS_SLOT_2( _q_updateFocusObject )
};

void QApplication::lscs_setApplicationDisplayName( const QString &name )
{
    setApplicationDisplayName( name );
}

QString QApplication::lscs_applicationDisplayName() const
{
    return applicationDisplayName();
}

QString QApplication::lscs_platformName() const
{
    return platformName();
}

QScreen *QApplication::lscs_primaryScreen() const
{
    return primaryScreen();
}

void QApplication::lscs_setWindowIcon( const QIcon &icon )
{
    setWindowIcon( icon );
}

QIcon QApplication::lscs_windowIcon() const
{
    return windowIcon();
}

void QApplication::lscs_setCursorFlashTime( int duration )
{
    setCursorFlashTime( duration );
}

int QApplication::lscs_cursorFlashTime() const
{
    return cursorFlashTime();
}

void QApplication::lscs_setDoubleClickInterval( int interval )
{
    setDoubleClickInterval( interval );
}

int QApplication::lscs_doubleClickInterval() const
{
    return doubleClickInterval();
}

void QApplication::lscs_setKeyboardInputInterval( int interval )
{
    setKeyboardInputInterval( interval );
}

int QApplication::lscs_keyboardInputInterval() const
{
    return keyboardInputInterval();
}

#ifndef LSCS_NO_WHEELEVENT
void QApplication::lscs_setWheelScrollLines( int lines )
{
    setWheelScrollLines( lines );
}

int QApplication::lscs_wheelScrollLines()  const
{
    return wheelScrollLines();
}
#endif

void QApplication::lscs_setGlobalStrut( const QSize &size )
{
    setGlobalStrut( size );
}

QSize QApplication::lscs_globalStrut() const
{
    return globalStrut();
}

void QApplication::lscs_setStartDragTime( int time )
{
    setStartDragTime( time );
}

int QApplication::lscs_startDragTime() const
{
    return startDragTime();
}

void QApplication::lscs_setStartDragDistance( int distance )
{
    setStartDragDistance( distance );
}

int QApplication::lscs_startDragDistance() const
{
    return startDragDistance();
}

void QApplication::lscs_setLayoutDirection( Qt::LayoutDirection direction )
{
    setLayoutDirection( direction );
}

void QApplication::lscs_setQuitOnLastWindowClosed( bool quit )
{
    setQuitOnLastWindowClosed( quit );
}

bool QApplication::lscs_quitOnLastWindowClosed() const
{
    return quitOnLastWindowClosed();
}

Qt::LayoutDirection QApplication::lscs_layoutDirection() const
{
    return layoutDirection();
}

#endif
