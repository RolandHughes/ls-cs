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

#ifndef QMDIAREA_H
#define QMDIAREA_H

#include <qabstractscrollarea.h>
#include <qtabwidget.h>

#ifndef LSCS_NO_MDIAREA

class QMdiSubWindow;
class QMdiAreaPrivate;

class Q_GUI_EXPORT QMdiArea : public QAbstractScrollArea
{
    GUI_LSCS_OBJECT( QMdiArea )

    GUI_LSCS_ENUM( ViewMode )

    GUI_LSCS_PROPERTY_READ( background, background )
    GUI_LSCS_PROPERTY_WRITE( background, setBackground )

    GUI_LSCS_PROPERTY_READ( activationOrder, activationOrder )
    GUI_LSCS_PROPERTY_WRITE( activationOrder, setActivationOrder )

    GUI_LSCS_PROPERTY_READ( viewMode, viewMode )
    GUI_LSCS_PROPERTY_WRITE( viewMode, setViewMode )

#ifndef LSCS_NO_TABBAR
    GUI_LSCS_PROPERTY_READ( documentMode, documentMode )
    GUI_LSCS_PROPERTY_WRITE( documentMode, setDocumentMode )
    GUI_LSCS_PROPERTY_READ( tabsClosable, tabsClosable )
    GUI_LSCS_PROPERTY_WRITE( tabsClosable, setTabsClosable )
    GUI_LSCS_PROPERTY_READ( tabsMovable, tabsMovable )
    GUI_LSCS_PROPERTY_WRITE( tabsMovable, setTabsMovable )
#endif

#ifndef LSCS_NO_TABWIDGET
    GUI_LSCS_PROPERTY_READ( tabShape, tabShape )
    GUI_LSCS_PROPERTY_WRITE( tabShape, setTabShape )
    GUI_LSCS_PROPERTY_READ( tabPosition, tabPosition )
    GUI_LSCS_PROPERTY_WRITE( tabPosition, setTabPosition )
#endif

    GUI_LSCS_ENUM( WindowOrder )

public:
    enum AreaOption
    {
        DontMaximizeSubWindowOnActivation = 0x1
    };
    using AreaOptions = QFlags<AreaOption>;

    GUI_LSCS_REGISTER_ENUM(
        enum WindowOrder
    {
        CreationOrder,
        StackingOrder,
        ActivationHistoryOrder
    };
    )

    GUI_LSCS_REGISTER_ENUM(
        enum ViewMode
    {
        SubWindowView,
        TabbedView
    };
    )

    QMdiArea( QWidget *parent = nullptr );

    QMdiArea( const QMdiArea & ) = delete;
    QMdiArea &operator=( const QMdiArea & ) = delete;

    ~QMdiArea();

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

    QMdiSubWindow *currentSubWindow() const;
    QMdiSubWindow *activeSubWindow() const;
    QList<QMdiSubWindow *> subWindowList( WindowOrder order = CreationOrder ) const;

    QMdiSubWindow *addSubWindow( QWidget *widget, Qt::WindowFlags flags = Qt::EmptyFlag );
    void removeSubWindow( QWidget *widget );

    QBrush background() const;
    void setBackground( const QBrush &background );

    WindowOrder activationOrder() const;
    void setActivationOrder( WindowOrder order );

    void setOption( AreaOption option, bool on = true );
    bool testOption( AreaOption option ) const;

    void setViewMode( ViewMode mode );
    ViewMode viewMode() const;

#ifndef LSCS_NO_TABBAR
    bool documentMode() const;
    void setDocumentMode( bool enable );

    void setTabsClosable( bool closeable );
    bool tabsClosable() const;

    void setTabsMovable( bool movable );
    bool tabsMovable() const;
#endif

#ifndef LSCS_NO_TABWIDGET
    void setTabShape( QTabWidget::TabShape shape );
    QTabWidget::TabShape tabShape() const;

    void setTabPosition( QTabWidget::TabPosition position );
    QTabWidget::TabPosition tabPosition() const;
#endif

    GUI_LSCS_SIGNAL_1( Public, void subWindowActivated( QMdiSubWindow *window ) )
    GUI_LSCS_SIGNAL_2( subWindowActivated, window )

    GUI_LSCS_SLOT_1( Public, void setActiveSubWindow( QMdiSubWindow *window ) )
    GUI_LSCS_SLOT_2( setActiveSubWindow )

    GUI_LSCS_SLOT_1( Public, void tileSubWindows() )
    GUI_LSCS_SLOT_2( tileSubWindows )

    GUI_LSCS_SLOT_1( Public, void cascadeSubWindows() )
    GUI_LSCS_SLOT_2( cascadeSubWindows )

    GUI_LSCS_SLOT_1( Public, void closeActiveSubWindow() )
    GUI_LSCS_SLOT_2( closeActiveSubWindow )

    GUI_LSCS_SLOT_1( Public, void closeAllSubWindows() )
    GUI_LSCS_SLOT_2( closeAllSubWindows )

    GUI_LSCS_SLOT_1( Public, void activateNextSubWindow() )
    GUI_LSCS_SLOT_2( activateNextSubWindow )

    GUI_LSCS_SLOT_1( Public, void activatePreviousSubWindow() )
    GUI_LSCS_SLOT_2( activatePreviousSubWindow )

protected:
    GUI_LSCS_SLOT_1( Protected, void setupViewport( QWidget *viewport ) override )
    GUI_LSCS_SLOT_2( setupViewport )

    bool event( QEvent *event ) override;
    bool eventFilter( QObject *object, QEvent *event ) override;
    void paintEvent( QPaintEvent *paintEvent ) override;
    void childEvent( QChildEvent *childEvent ) override;
    void resizeEvent( QResizeEvent *resizeEvent ) override;
    void timerEvent( QTimerEvent *timerEvent ) override;
    void showEvent( QShowEvent *showEvent ) override;
    bool viewportEvent( QEvent *event ) override;
    void scrollContentsBy( int dx, int dy ) override;

private:
    Q_DECLARE_PRIVATE( QMdiArea )

    GUI_LSCS_SLOT_1( Private, void _q_deactivateAllWindows() )
    GUI_LSCS_SLOT_2( _q_deactivateAllWindows )

    GUI_LSCS_SLOT_1( Private, void _q_processWindowStateChanged( Qt::WindowStates oldState, Qt::WindowStates newStates ) )
    GUI_LSCS_SLOT_2( _q_processWindowStateChanged )

    GUI_LSCS_SLOT_1( Private, void _q_currentTabChanged( int index ) )
    GUI_LSCS_SLOT_2( _q_currentTabChanged )

    GUI_LSCS_SLOT_1( Private, void _q_closeTab( int index ) )
    GUI_LSCS_SLOT_2( _q_closeTab )

    GUI_LSCS_SLOT_1( Private, void _q_moveTab( int from, int to ) )
    GUI_LSCS_SLOT_2( _q_moveTab )
};

Q_DECLARE_OPERATORS_FOR_FLAGS( QMdiArea::AreaOptions )

#endif // LSCS_NO_MDIAREA

#endif
