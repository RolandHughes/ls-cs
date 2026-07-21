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

#include <qaccessiblewidget_common_p.h>

#include <qpushbutton.h>
#include <qtoolbutton.h>
#include <qtreeview.h>
#include <qvariant.h>
#include <qaccessible.h>

#include <qaccessiblemenu_p.h>
#include <qwidget_p.h>

#include <qaccessiblewidget_simple_p.h>
#include <qaccessiblewidget_range_p.h>
#include <qaccessiblewidget_complex_p.h>
#include <qaccessiblewidget_views_p.h>

#ifndef LSCS_NO_ACCESSIBILITY

QAccessibleInterface *qAccessibleFactory( const QString &classname, QObject *object )
{
    QAccessibleInterface *iface = nullptr;

    if ( !object || !object->isWidgetType() )
    {
        return iface;
    }

    QWidget *widget = static_cast<QWidget *>( object );

    // QWidget emits destroyed() from its destructor instead of letting the QObject
    // destructor do it, which means the QWidget is unregistered from the accessibillity
    // cache. But QWidget destruction also emits enter and leave events, which may end
    // up here, so we have to ensure that we don't fill the cache with an entry of
    // a widget that is going away.

    if ( QWidgetPrivate::get( widget )->m_privateData.in_destructor )
    {
        return iface;
    }

    if ( false )
    {
#ifndef LSCS_NO_LINEEDIT
    }
    else if ( classname == QLatin1String( "QLineEdit" ) )
    {
        if ( widget->objectName() == QLatin1String( "lscs_spinbox_lineedit" ) )
        {
            iface = nullptr;
        }
        else
        {
            iface = new QAccessibleLineEdit( widget );
        }

#endif

#ifndef LSCS_NO_COMBOBOX
    }
    else if ( classname == QLatin1String( "QComboBox" ) )
    {
        iface = new QAccessibleComboBox( widget );
#endif

#ifndef LSCS_NO_SPINBOX
    }
    else if ( classname == QLatin1String( "QAbstractSpinBox" ) )
    {
        iface = new QAccessibleAbstractSpinBox( widget );
    }
    else if ( classname == QLatin1String( "QSpinBox" ) )
    {
        iface = new QAccessibleSpinBox( widget );
    }
    else if ( classname == QLatin1String( "QDoubleSpinBox" ) )
    {
        iface = new QAccessibleDoubleSpinBox( widget );
#endif

#ifndef LSCS_NO_SCROLLBAR
    }
    else if ( classname == QLatin1String( "QScrollBar" ) )
    {
        iface = new QAccessibleScrollBar( widget );
#endif

    }
    else if ( classname == QLatin1String( "QAbstractSlider" ) )
    {
        iface = new QAccessibleAbstractSlider( widget );
#ifndef LSCS_NO_SLIDER
    }
    else if ( classname == QLatin1String( "QSlider" ) )
    {
        iface = new QAccessibleSlider( widget );
#endif

#ifndef LSCS_NO_TOOLBUTTON
    }
    else if ( classname == QLatin1String( "QToolButton" ) )
    {
        iface = new QAccessibleToolButton( widget );
#endif // LSCS_NO_TOOLBUTTON
    }
    else if ( classname == QLatin1String( "QCheckBox" )
              || classname == QLatin1String( "QRadioButton" )
              || classname == QLatin1String( "QPushButton" )
              || classname == QLatin1String( "QAbstractButton" ) )
    {
        iface = new QAccessibleButton( widget );
    }
    else if ( classname == QLatin1String( "QDialog" ) )
    {
        iface = new QAccessibleWidget( widget, QAccessible::Dialog );
    }
    else if ( classname == QLatin1String( "QMessageBox" ) )
    {
        iface = new QAccessibleWidget( widget, QAccessible::AlertMessage );

#ifndef LSCS_NO_MAINWINDOW
    }
    else if ( classname == QLatin1String( "QMainWindow" ) )
    {
        iface = new QAccessibleMainWindow( widget );
#endif

    }
    else if ( classname == QLatin1String( "QLabel" ) || classname == QLatin1String( "QLCDNumber" ) )
    {
        iface = new QAccessibleDisplay( widget );

#ifndef LSCS_NO_GROUPBOX
    }
    else if ( classname == QLatin1String( "QGroupBox" ) )
    {
        iface = new QAccessibleGroupBox( widget );
#endif

    }
    else if ( classname == QLatin1String( "QStatusBar" ) )
    {
        iface = new QAccessibleDisplay( widget );

#ifndef LSCS_NO_PROGRESSBAR
    }
    else if ( classname == QLatin1String( "QProgressBar" ) )
    {
        iface = new QAccessibleProgressBar( widget );
#endif

    }
    else if ( classname == QLatin1String( "QToolBar" ) )
    {
        iface = new QAccessibleWidget( widget, QAccessible::ToolBar, widget->windowTitle() );
#ifndef LSCS_NO_MENUBAR
    }
    else if ( classname == QLatin1String( "QMenuBar" ) )
    {
        iface = new QAccessibleMenuBar( widget );
#endif
#ifndef LSCS_NO_MENU
    }
    else if ( classname == QLatin1String( "QMenu" ) )
    {
        iface = new QAccessibleMenu( widget );
#endif
#ifndef LSCS_NO_ITEMVIEWS
    }
    else if ( classname == QLatin1String( "QTreeView" ) )
    {
        iface = new QAccessibleTree( widget );
    }
    else if ( classname == QLatin1String( "QTableView" ) || classname == QLatin1String( "QListView" ) )
    {
        iface = new QAccessibleTable( widget );
        // ### This should be cleaned up. We return the parent for the scrollarea to hide it.
#endif // LSCS_NO_ITEMVIEWS
#ifndef LSCS_NO_TABBAR
    }
    else if ( classname == QLatin1String( "QTabBar" ) )
    {
        iface = new QAccessibleTabBar( widget );
#endif
    }
    else if ( classname == QLatin1String( "QSizeGrip" ) )
    {
        iface = new QAccessibleWidget( widget, QAccessible::Grip );
#ifndef LSCS_NO_SPLITTER
    }
    else if ( classname == QLatin1String( "QSplitter" ) )
    {
        iface = new QAccessibleWidget( widget, QAccessible::Splitter );
    }
    else if ( classname == QLatin1String( "QSplitterHandle" ) )
    {
        iface = new QAccessibleWidget( widget, QAccessible::Grip );
#endif
#if !defined(LSCS_NO_TEXTEDIT) && !defined(LSCS_NO_CURSOR)
    }
    else if ( classname == QLatin1String( "QTextEdit" ) )
    {
        iface = new QAccessibleTextEdit( widget );
    }
    else if ( classname == QLatin1String( "QPlainTextEdit" ) )
    {
        iface = new QAccessiblePlainTextEdit( widget );
#endif
    }
    else if ( classname == QLatin1String( "QTipLabel" ) )
    {
        iface = new QAccessibleDisplay( widget, QAccessible::ToolTip );
    }
    else if ( classname == QLatin1String( "QFrame" ) )
    {
        iface = new QAccessibleWidget( widget, QAccessible::Border );
#ifndef LSCS_NO_STACKEDWIDGET
    }
    else if ( classname == QLatin1String( "QStackedWidget" ) )
    {
        iface = new QAccessibleStackedWidget( widget );
#endif
#ifndef LSCS_NO_TOOLBOX
    }
    else if ( classname == QLatin1String( "QToolBox" ) )
    {
        iface = new QAccessibleToolBox( widget );
#endif
#ifndef LSCS_NO_MDIAREA
    }
    else if ( classname == QLatin1String( "QMdiArea" ) )
    {
        iface = new QAccessibleMdiArea( widget );
    }
    else if ( classname == QLatin1String( "QMdiSubWindow" ) )
    {
        iface = new QAccessibleMdiSubWindow( widget );
#endif
    }
    else if ( classname == QLatin1String( "QDialogButtonBox" ) )
    {
        iface = new QAccessibleDialogButtonBox( widget );
#ifndef LSCS_NO_DIAL
    }
    else if ( classname == QLatin1String( "QDial" ) )
    {
        iface = new QAccessibleDial( widget );
#endif
#ifndef LSCS_NO_RUBBERBAND
    }
    else if ( classname == QLatin1String( "QRubberBand" ) )
    {
        iface = new QAccessibleWidget( widget, QAccessible::Border );
#endif
#if !defined(LSCS_NO_TEXTBROWSER) && !defined(LSCS_NO_CURSOR)
    }
    else if ( classname == QLatin1String( "QTextBrowser" ) )
    {
        iface = new QAccessibleTextBrowser( widget );
#endif
#ifndef LSCS_NO_SCROLLAREA
    }
    else if ( classname == QLatin1String( "QAbstractScrollArea" ) )
    {
        iface = new QAccessibleAbstractScrollArea( widget );
    }
    else if ( classname == QLatin1String( "QScrollArea" ) )
    {
        iface = new QAccessibleScrollArea( widget );
#endif
#ifndef LSCS_NO_CALENDARWIDGET
    }
    else if ( classname == QLatin1String( "QCalendarWidget" ) )
    {
        iface = new QAccessibleCalendarWidget( widget );
#endif
#ifndef LSCS_NO_DOCKWIDGET
    }
    else if ( classname == QLatin1String( "QDockWidget" ) )
    {
        iface = new QAccessibleDockWidget( widget );
#endif

    }
    else if ( classname == QLatin1String( "QDesktopScreenWidget" ) )
    {
        iface = nullptr;
    }
    else if ( classname == QLatin1String( "QWidget" ) )
    {
        iface = new QAccessibleWidget( widget );
    }
    else if ( classname == QLatin1String( "QWindowContainer" ) )
    {
        iface = new QAccessibleWindowContainer( widget );
    }

    return iface;
}

#endif // LSCS_NO_ACCESSIBILITY
