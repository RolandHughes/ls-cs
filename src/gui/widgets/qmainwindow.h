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

#ifndef QMainWindow_H
#define QMainWindow_H

#include <qwidget.h>
#include <qtabwidget.h>

#ifndef LSCS_NO_MAINWINDOW

class QDockWidget;
class QMainWindowPrivate;
class QMenuBar;
class QStatusBar;
class QToolBar;
class QMenu;

class Q_GUI_EXPORT QMainWindow : public QWidget
{
    GUI_LSCS_OBJECT( QMainWindow )

    GUI_LSCS_ENUM( DockOption )
    GUI_LSCS_FLAG( DockOption, DockOptions )

    GUI_LSCS_PROPERTY_READ( iconSize, iconSize )
    GUI_LSCS_PROPERTY_WRITE( iconSize, setIconSize )

    GUI_LSCS_PROPERTY_READ( toolButtonStyle, toolButtonStyle )
    GUI_LSCS_PROPERTY_WRITE( toolButtonStyle, setToolButtonStyle )

#ifndef LSCS_NO_DOCKWIDGET
    GUI_LSCS_PROPERTY_READ( animated, isAnimated )
    GUI_LSCS_PROPERTY_WRITE( animated, setAnimated )

#ifndef LSCS_NO_TABBAR
    GUI_LSCS_PROPERTY_READ( documentMode, documentMode )
    GUI_LSCS_PROPERTY_WRITE( documentMode, setDocumentMode )
#endif

#ifndef LSCS_NO_TABWIDGET
    GUI_LSCS_PROPERTY_READ( tabShape, tabShape )
    GUI_LSCS_PROPERTY_WRITE( tabShape, setTabShape )
#endif

    GUI_LSCS_PROPERTY_READ( dockNestingEnabled, isDockNestingEnabled )
    GUI_LSCS_PROPERTY_WRITE( dockNestingEnabled, setDockNestingEnabled )
#endif // LSCS_NO_DOCKWIDGET

    GUI_LSCS_PROPERTY_READ( dockOptions, dockOptions )
    GUI_LSCS_PROPERTY_WRITE( dockOptions, setDockOptions )

#ifndef LSCS_NO_TOOLBAR
    GUI_LSCS_PROPERTY_READ( unifiedTitleAndToolBarOnMac, unifiedTitleAndToolBarOnMac )
    GUI_LSCS_PROPERTY_WRITE( unifiedTitleAndToolBarOnMac, setUnifiedTitleAndToolBarOnMac )
#endif

public:
    GUI_LSCS_REGISTER_ENUM(
        enum DockOption
    {
        AnimatedDocks    = 0x01,
        AllowNestedDocks = 0x02,
        AllowTabbedDocks = 0x04,
        ForceTabbedDocks = 0x08,   // implies AllowTabbedDocks, !AllowNestedDocks
        VerticalTabs     = 0x10,   // implies AllowTabbedDocks
        GroupedDragging  = 0x20    // implies AllowTabbedDocks
    };
    )
    using DockOptions = QFlags<DockOption>;

    explicit QMainWindow( QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::EmptyFlag );

    QMainWindow( const QMainWindow & ) = delete;
    QMainWindow &operator=( const QMainWindow & ) = delete;

    ~QMainWindow();

    QSize iconSize() const;
    void setIconSize( const QSize &iconSize );

    Qt::ToolButtonStyle toolButtonStyle() const;
    void setToolButtonStyle( Qt::ToolButtonStyle toolButtonStyle );

    void setDockOptions( DockOptions options );
    DockOptions dockOptions() const;

    bool isSeparator( const QPoint &pos ) const;

    QWidget *centralWidget() const;
    void setCentralWidget( QWidget *widget );

    QWidget *takeCentralWidget();

#ifndef LSCS_NO_DOCKWIDGET
    bool isAnimated() const;
    bool isDockNestingEnabled() const;

    void setCorner( Qt::Corner corner, Qt::DockWidgetArea area );
    Qt::DockWidgetArea corner( Qt::Corner corner ) const;

    void addDockWidget( Qt::DockWidgetArea area, QDockWidget *dockwidget );
    void addDockWidget( Qt::DockWidgetArea area, QDockWidget *dockwidget, Qt::Orientation orientation );
    void splitDockWidget( QDockWidget *first, QDockWidget *second, Qt::Orientation orientation );
    void tabifyDockWidget( QDockWidget *first, QDockWidget *second );

    QList<QDockWidget *> tabifiedDockWidgets( QDockWidget *dockwidget ) const;
    void removeDockWidget( QDockWidget *dockwidget );
    bool restoreDockWidget( QDockWidget *dockwidget );

    Qt::DockWidgetArea dockWidgetArea( QDockWidget *dockwidget ) const;

    void resizeDocks( const QList<QDockWidget *> &docks,
                      const QList<int> &sizes, Qt::Orientation orientation );

    GUI_LSCS_SLOT_1( Public, void setAnimated( bool enabled ) )
    GUI_LSCS_SLOT_2( setAnimated )

    GUI_LSCS_SLOT_1( Public, void setDockNestingEnabled( bool enabled ) )
    GUI_LSCS_SLOT_2( setDockNestingEnabled )
#endif

#ifndef LSCS_NO_TABBAR
    bool documentMode() const;
    void setDocumentMode( bool enabled );
#endif

#ifndef LSCS_NO_TABWIDGET
    QTabWidget::TabShape tabShape() const;
    void setTabShape( QTabWidget::TabShape tabShape );
    QTabWidget::TabPosition tabPosition( Qt::DockWidgetArea area ) const;
    void setTabPosition( Qt::DockWidgetAreas areas, QTabWidget::TabPosition tabPosition );
#endif

#ifndef LSCS_NO_MENU
    virtual QMenu *createPopupMenu();
#endif

#ifndef LSCS_NO_MENUBAR
    QMenuBar *menuBar() const;
    void setMenuBar( QMenuBar *menuBar );

    QWidget  *menuWidget() const;
    void setMenuWidget( QWidget *menuBar );
#endif

#ifndef LSCS_NO_STATUSBAR
    QStatusBar *statusBar() const;
    void setStatusBar( QStatusBar *statusbar );
#endif

#ifndef LSCS_NO_TOOLBAR
    void addToolBarBreak( Qt::ToolBarArea area = Qt::TopToolBarArea );
    void insertToolBarBreak( QToolBar *location );

    void addToolBar( Qt::ToolBarArea area, QToolBar *toolbar );
    void addToolBar( QToolBar *toolbar );
    QToolBar *addToolBar( const QString &title );

    void insertToolBar( QToolBar *location, QToolBar *newToolbar );
    void removeToolBar( QToolBar *toolbar );
    void removeToolBarBreak( QToolBar *location );

    bool unifiedTitleAndToolBarOnMac() const;

    Qt::ToolBarArea toolBarArea( QToolBar *toolbar ) const;
    bool toolBarBreak( QToolBar *toolbar ) const;

    GUI_LSCS_SLOT_1( Public, void setUnifiedTitleAndToolBarOnMac( bool set ) )
    GUI_LSCS_SLOT_2( setUnifiedTitleAndToolBarOnMac )
#endif

    QByteArray saveState( int version = 0 ) const;
    bool restoreState( const QByteArray &state, int version = 0 );

    GUI_LSCS_SIGNAL_1( Public, void iconSizeChanged( const QSize &iconSize ) )
    GUI_LSCS_SIGNAL_2( iconSizeChanged, iconSize )
    GUI_LSCS_SIGNAL_1( Public, void toolButtonStyleChanged( Qt::ToolButtonStyle toolButtonStyle ) )
    GUI_LSCS_SIGNAL_2( toolButtonStyleChanged, toolButtonStyle )

protected:
#ifndef LSCS_NO_CONTEXTMENU
    void contextMenuEvent( QContextMenuEvent *event ) override;
#endif

    bool event( QEvent *event ) override;

private:
    Q_DECLARE_PRIVATE( QMainWindow )
};

Q_DECLARE_OPERATORS_FOR_FLAGS( QMainWindow::DockOptions )

#endif // LSCS_NO_MAINWINDOW

#endif
