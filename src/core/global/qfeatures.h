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

#ifndef QFeatures_H
#define QFeatures_H

// QAction
//#define LSCS_NO_ACTION

// Big Codecs
//#define LSCS_NO_BIG_CODECS

// Color Names
//#define LSCS_NO_COLORNAMES

// QCopChannel
//#define LSCS_NO_COP

// CssParser
//#define LSCS_NO_CSSPARSER

// QCursor
//#define LSCS_NO_CURSOR

// QDesktopServices
//#define LSCS_NO_DESKTOPSERVICES

// QDirectPainter
//#define LSCS_NO_DIRECTPAINTER

// Document Object Model
//#define LSCS_NO_DOM

// Effects
//#define LSCS_NO_EFFECTS

// QFileSystemIterator
//#define LSCS_NO_FILESYSTEMITERATOR

// QFileSystemWatcher
//#define LSCS_NO_FILESYSTEMWATCHER

// Freetype Font Engine
//#define LSCS_USE_FREETYPE

// Gesture
//#define LSCS_NO_GESTURES

// QGroupBox
//#define LSCS_NO_GROUPBOX

// QImageIOPlugin
//#define LSCS_NO_IMAGEFORMATPLUGIN

// BMP Image Format
//#define LSCS_NO_IMAGEFORMAT_BMP

// JPEG Image Format
//#define LSCS_NO_IMAGEFORMAT_JPEG

// PNG Image Format
//#define LSCS_NO_IMAGEFORMAT_PNG

// PPM Image Format
//#define LSCS_NO_IMAGEFORMAT_PPM

// XBM Image Format
//#define LSCS_NO_IMAGEFORMAT_XBM

// QImage::createHeuristicMask()
//#define LSCS_NO_IMAGE_HEURISTIC_MASK

// Image Text
//#define LSCS_NO_IMAGE_TEXT

// QLCDNumber
//#define LSCS_NO_LCDNUMBER

// QLineEdit
//#define LSCS_NO_LINEEDIT

// QMessageBox
//#define LSCS_NO_MESSAGEBOX

// QMovie
//#define LSCS_NO_MOVIE

// QNetworkInterface
//#define LSCS_NO_NETWORKINTERFACE

// QNetworkProxy
//#define LSCS_NO_NETWORKPROXY

// Qt::WA_PaintOnScreen
//#define LSCS_NO_PAINTONSCREEN

// QPicture
//#define LSCS_NO_PICTURE

// QProcess
//#define LSCS_NO_PROCESS

// QProgressBar
//#define LSCS_NO_PROGRESSBAR

// Properties
//#define LSCS_NO_PROPERTIES

//  Universally Unique Identifier Convertion
//#define LSCS_NO_QUUID_STRING

// Raster Paint Engine callback functions
//#define LSCS_NO_RASTERCALLBACKS

// Resize Handler
//#define LSCS_NO_RESIZEHANDLER

// QRubberBand
//#define LSCS_NO_RUBBERBAND

// Session Manager
//#define LSCS_NO_SESSIONMANAGER

// QSettings
//#define LSCS_NO_SETTINGS

// QSharedMemory
//#define LSCS_NO_SHAREDMEMORY

// QShortcut
//#define LSCS_NO_SHORTCUT

// QSignalMapper
//#define LSCS_NO_SIGNALMAPPER

// QSizeGrip
//#define LSCS_NO_SIZEGRIP

// QSlider
//#define LSCS_NO_SLIDER

// Sounds
//#define LSCS_NO_SOUND

// Spin Widget
//#define LSCS_NO_SPINWIDGET

// Splash screen widget
//#define LSCS_NO_SPLASHSCREEN

// QStackedWidget
//#define LSCS_NO_STACKEDWIDGET

// QStatusBar
//#define LSCS_NO_STATUSBAR

// Status Tip
//#define LSCS_NO_STATUSTIP

// QMotifStyle
//#define LSCS_NO_STYLE_MOTIF

// QWindowsStyle
//#define LSCS_NO_STYLE_WINDOWS

// QSystemSemaphore
//#define LSCS_NO_SYSTEMSEMAPHORE

// QSystemTrayIcon
//#define LSCS_NO_SYSTEMTRAYICON

// QTabletEvent
//#define LSCS_NO_TABLETEVENT

// QTemporaryFile
//#define LSCS_NO_TEMPORARYFILE

// QTextCodec
//#define LSCS_NO_TEXTCODEC

// HtmlParser
//#define LSCS_NO_TEXTHTMLPARSER

// QToolTip
//#define LSCS_NO_TOOLTIP

// QUdpSocket
//#define LSCS_NO_UDPSOCKET

// QUndoCommand
//#define LSCS_NO_UNDOCOMMAND

// QUrlInfo
//#define LSCS_NO_URLINFO

// QValidator
//#define LSCS_NO_VALIDATOR

// QWheelEvent
//#define LSCS_NO_WHEELEVENT


// QButtonGroup
#if !defined(LSCS_NO_BUTTONGROUP) && (defined(LSCS_NO_GROUPBOX))
#define LSCS_NO_BUTTONGROUP
#endif

// Codecs
#if !defined(LSCS_NO_CODECS) && (defined(LSCS_NO_TEXTCODEC))
#define LSCS_NO_CODECS
#endif

// QDial
#if !defined(LSCS_NO_DIAL) && (defined(LSCS_NO_SLIDER))
#define LSCS_NO_DIAL
#endif

// QFileSystemModel
#if !defined(LSCS_NO_FILESYSTEMMODEL) && (defined(LSCS_NO_FILESYSTEMWATCHER))
#define LSCS_NO_FILESYSTEMMODEL
#endif

// QMenu
#if !defined(LSCS_NO_MENU) && (defined(LSCS_NO_ACTION))
#define LSCS_NO_MENU
#endif

// QNetworkDiskCache
#if !defined(LSCS_NO_NETWORKDISKCACHE) && (defined(LSCS_NO_TEMPORARYFILE))
#define LSCS_NO_NETWORKDISKCACHE
#endif

// QProgressDialog
#if !defined(LSCS_NO_PROGRESSDIALOG) && (defined(LSCS_NO_PROGRESSBAR))
#define LSCS_NO_PROGRESSDIALOG
#endif

// QScrollBar
#if !defined(LSCS_NO_SCROLLBAR) && (defined(LSCS_NO_SLIDER))
#define LSCS_NO_SCROLLBAR
#endif

//  SOCKS5
#if !defined(LSCS_NO_SOCKS5) && (defined(LSCS_NO_NETWORKPROXY))
#define LSCS_NO_SOCKS5
#endif

// QSplitter
#if !defined(LSCS_NO_SPLITTER) && (defined(LSCS_NO_RUBBERBAND))
#define LSCS_NO_SPLITTER
#endif

// QCDEStyle
#if !defined(LSCS_NO_STYLE_CDE) && (defined(LSCS_NO_STYLE_MOTIF))
#define LSCS_NO_STYLE_CDE
#endif

// QToolButton
#if !defined(LSCS_NO_TOOLBUTTON) && (defined(LSCS_NO_ACTION))
#define LSCS_NO_TOOLBUTTON
#endif

// QUndoStack
#if !defined(LSCS_NO_UNDOSTACK) && (defined(LSCS_NO_UNDOCOMMAND))
#define LSCS_NO_UNDOSTACK
#endif

// Context menu
#if !defined(LSCS_NO_CONTEXTMENU) && (defined(LSCS_NO_MENU))
#define LSCS_NO_CONTEXTMENU
#endif

// QtDBus module
#if !defined(LSCS_NO_DBUS) && defined(LSCS_NO_DOM)
#define LSCS_NO_DBUS
#endif

// File Transfer Protocol
#if !defined(LSCS_NO_FTP) && (defined(LSCS_NO_URLINFO))
#define LSCS_NO_FTP
#endif

// QScrollArea
#if !defined(LSCS_NO_SCROLLAREA) && (defined(LSCS_NO_SCROLLBAR))
#define LSCS_NO_SCROLLAREA
#endif

// QTabBar
#if !defined(LSCS_NO_TABBAR) && (defined(LSCS_NO_TOOLBUTTON))
#define LSCS_NO_TABBAR
#endif

// OdfWriter
#if ! defined(LSCS_NO_TEXTODFWRITER) && (0)   // removed test which was always false
#define LSCS_NO_TEXTODFWRITER
#endif

// QUndoGroup
#if !defined(LSCS_NO_UNDOGROUP) && (defined(LSCS_NO_UNDOSTACK))
#define LSCS_NO_UNDOGROUP
#endif

// QWhatsThis
#if !defined(LSCS_NO_WHATSTHIS) && (defined(LSCS_NO_TOOLBUTTON))
#define LSCS_NO_WHATSTHIS
#endif

// Drag and drop
#if !defined(LSCS_NO_DRAGANDDROP) && defined(LSCS_NO_IMAGEFORMAT_XPM)
#define LSCS_NO_DRAGANDDROP
#endif

// QGraphicsView
#if !defined(LSCS_NO_GRAPHICSVIEW) && (defined(LSCS_NO_SCROLLAREA))
#define LSCS_NO_GRAPHICSVIEW
#endif

// Hyper Text Transfer Protocol
#if !defined(LSCS_NO_HTTP) && defined(LSCS_NO_HOSTINFO)
#define LSCS_NO_HTTP
#endif

// QMdiArea
#if !defined(LSCS_NO_MDIAREA) && (defined(LSCS_NO_SCROLLAREA))
#define LSCS_NO_MDIAREA
#endif

// QPrinter
#if !defined(LSCS_NO_PRINTER) && (defined(LSCS_NO_PICTURE) || defined(LSCS_NO_TEMPORARYFILE))
#define LSCS_NO_PRINTER
#endif

// QSpinBox
#if !defined(LSCS_NO_SPINBOX) && (defined(LSCS_NO_SPINWIDGET) || defined(LSCS_NO_LINEEDIT) || defined(LSCS_NO_VALIDATOR))
#define LSCS_NO_SPINBOX
#endif

// QCleanLooksStyle
#if !defined(LSCS_NO_STYLE_CLEANLOOKS) && (defined(LSCS_NO_STYLE_WINDOWS) || defined(LSCS_NO_IMAGEFORMAT_XPM))
#define LSCS_NO_STYLE_CLEANLOOKS
#endif

// QPlastiqueStyle
#if !defined(LSCS_NO_STYLE_PLASTIQUE) && (defined(LSCS_NO_STYLE_WINDOWS) || defined(LSCS_NO_IMAGEFORMAT_XPM))
#define LSCS_NO_STYLE_PLASTIQUE
#endif

// QStyleSheetStyle
#if !defined(LSCS_NO_STYLE_STYLESHEET) && (defined(LSCS_NO_STYLE_WINDOWS) || defined(LSCS_NO_CSSPARSER))
#define LSCS_NO_STYLE_STYLESHEET
#endif

// QtSvg module
#if !defined(LSCS_NO_SVG) && defined(LSCS_NO_CSSPARSER)
#define LSCS_NO_SVG
#endif

// QTextCodecPlugin
#if !defined(LSCS_NO_TEXTCODECPLUGIN) && (defined(LSCS_NO_TEXTCODEC))
#define LSCS_NO_TEXTCODECPLUGIN
#endif

// QColorDialog
#if !defined(LSCS_NO_COLORDIALOG) && (defined(LSCS_NO_SPINBOX))
#define LSCS_NO_COLORDIALOG
#endif

// QGraphicsEffect
#if !defined(LSCS_NO_GRAPHICSEFFECT) && (defined(LSCS_NO_GRAPHICSVIEW))
#define LSCS_NO_GRAPHICSEFFECT
#endif

// The Model/View Framework
#if !defined(LSCS_NO_ITEMVIEWS) && (defined(LSCS_NO_RUBBERBAND) || defined(LSCS_NO_SCROLLAREA))
#define LSCS_NO_ITEMVIEWS
#endif

// QMenuBar
#if !defined(LSCS_NO_MENUBAR) && (defined(LSCS_NO_MENU) || defined(LSCS_NO_TOOLBUTTON))
#define LSCS_NO_MENUBAR
#endif

// QSvgGenerator
#if !defined(LSCS_NO_SVGGENERATOR) && (defined(LSCS_NO_SVG))
#define LSCS_NO_SVGGENERATOR
#endif

// QSvgRenderer
#if !defined(LSCS_NO_SVGRENDERER) && (defined(LSCS_NO_SVG))
#define LSCS_NO_SVGRENDERER
#endif

// QTabWidget
#if !defined(LSCS_NO_TABWIDGET) && (defined(LSCS_NO_TABBAR) || defined(LSCS_NO_STACKEDWIDGET))
#define LSCS_NO_TABWIDGET
#endif

// QTextEdit
#if !defined(LSCS_NO_TEXTEDIT) && (defined(LSCS_NO_SCROLLAREA))
#define LSCS_NO_TEXTEDIT
#endif

// QErrorMessage
#if !defined(LSCS_NO_ERRORMESSAGE) && (defined(LSCS_NO_TEXTEDIT))
#define LSCS_NO_ERRORMESSAGE
#endif

// QListView
#if !defined(LSCS_NO_LISTVIEW) && (defined(LSCS_NO_ITEMVIEWS))
#define LSCS_NO_LISTVIEW
#endif

// QMainWindow
#if !defined(LSCS_NO_MAINWINDOW) && (defined(LSCS_NO_MENU) || defined(LSCS_NO_RESIZEHANDLER) || defined(LSCS_NO_TOOLBUTTON))
#define LSCS_NO_MAINWINDOW
#endif

// QAbstractProxyModel
#if !defined(LSCS_NO_PROXYMODEL) && (defined(LSCS_NO_ITEMVIEWS))
#define LSCS_NO_PROXYMODEL
#endif

// QStandardItemModel
#if !defined(LSCS_NO_STANDARDITEMMODEL) && (defined(LSCS_NO_ITEMVIEWS))
#define LSCS_NO_STANDARDITEMMODEL
#endif

// QStringListModel
#if !defined(LSCS_NO_STRINGLISTMODEL) && (defined(LSCS_NO_ITEMVIEWS))
#define LSCS_NO_STRINGLISTMODEL
#endif

// QSvgWidget
#if !defined(LSCS_NO_SVGWIDGET) && (defined(LSCS_NO_SVGRENDERER))
#define LSCS_NO_SVGWIDGET
#endif

// QSyntaxHighlighter
#if !defined(LSCS_NO_SYNTAXHIGHLIGHTER) && (defined(LSCS_NO_TEXTEDIT))
#define LSCS_NO_SYNTAXHIGHLIGHTER
#endif

// QTableView
#if !defined(LSCS_NO_TABLEVIEW) && (defined(LSCS_NO_ITEMVIEWS))
#define LSCS_NO_TABLEVIEW
#endif

// QTextBrowser
#if !defined(LSCS_NO_TEXTBROWSER) && (defined(LSCS_NO_TEXTEDIT))
#define LSCS_NO_TEXTBROWSER
#endif

// QToolBox
#if !defined(LSCS_NO_TOOLBOX) && (defined(LSCS_NO_TOOLBUTTON) || defined(LSCS_NO_SCROLLAREA))
#define LSCS_NO_TOOLBOX
#endif

// QTreeView
#if !defined(LSCS_NO_TREEVIEW) && (defined(LSCS_NO_ITEMVIEWS))
#define LSCS_NO_TREEVIEW
#endif

// Accessibility
#if !defined(LSCS_NO_ACCESSIBILITY) && defined(LSCS_NO_MENUBAR)
#define LSCS_NO_ACCESSIBILITY
#endif

// QColumnView
#if !defined(LSCS_NO_COLUMNVIEW) && (defined(LSCS_NO_LISTVIEW))
#define LSCS_NO_COLUMNVIEW
#endif

// QCompleter
#if !defined(LSCS_NO_COMPLETER) && (defined(LSCS_NO_PROXYMODEL))
#define LSCS_NO_COMPLETER
#endif

// Common UNIX Printing System
#if !defined(LSCS_NO_CUPS) && (defined(LSCS_NO_PRINTER))
#define LSCS_NO_CUPS
#endif

// QDataWidgetMapper
#if !defined(LSCS_NO_DATAWIDGETMAPPER) && defined(LSCS_NO_ITEMVIEWS)
#define LSCS_NO_DATAWIDGETMAPPER
#endif

// QListWidget
#if ! defined(LSCS_NO_LISTWIDGET) && defined(LSCS_NO_LISTVIEW)
#define LSCS_NO_LISTWIDGET
#endif

// QSortFilterProxyModel
#if !defined(LSCS_NO_SORTFILTERPROXYMODEL) && (defined(LSCS_NO_PROXYMODEL))
#define LSCS_NO_SORTFILTERPROXYMODEL
#endif

// QTableWidget
#if !defined(LSCS_NO_TABLEWIDGET) && (defined(LSCS_NO_TABLEVIEW))
#define LSCS_NO_TABLEWIDGET
#endif

// QToolBar
#if !defined(LSCS_NO_TOOLBAR) && (defined(LSCS_NO_MAINWINDOW))
#define LSCS_NO_TOOLBAR
#endif

// QTreeWidget
#if !defined(LSCS_NO_TREEWIDGET) && (defined(LSCS_NO_TREEVIEW))
#define LSCS_NO_TREEWIDGET
#endif

// QDirModel
#if !defined(LSCS_NO_DIRMODEL) && (defined(LSCS_NO_ITEMVIEWS) || defined(LSCS_NO_FILESYSTEMMODEL))
#define LSCS_NO_DIRMODEL
#endif

// QDockwidget
#if !defined(LSCS_NO_DOCKWIDGET) && (defined(LSCS_NO_RUBBERBAND) || defined(LSCS_NO_MAINWINDOW))
#define LSCS_NO_DOCKWIDGET
#endif

// QUndoView
#if !defined(LSCS_NO_UNDOVIEW) && (defined(LSCS_NO_UNDOSTACK) || defined(LSCS_NO_LISTVIEW))
#define LSCS_NO_UNDOVIEW
#endif

// QCompleter
#if !defined(LSCS_NO_FSCOMPLETER) && (defined(LSCS_NO_FILESYSTEMMODEL) || defined(LSCS_NO_COMPLETER))
#define LSCS_NO_FSCOMPLETER
#endif

// QGraphicsSvgItem
#if !defined(LSCS_NO_GRAPHICSSVGITEM) && (defined(LSCS_NO_SVGRENDERER) || defined(LSCS_NO_GRAPHICSVIEW))
#define LSCS_NO_GRAPHICSSVGITEM
#endif

// QComboBox
#if !defined(LSCS_NO_COMBOBOX) && (defined(LSCS_NO_LINEEDIT) || defined(LSCS_NO_STANDARDITEMMODEL) || defined(LSCS_NO_LISTVIEW))
#define LSCS_NO_COMBOBOX
#endif

// QWorkSpace
#if !defined(LSCS_NO_WORKSPACE) && (defined(LSCS_NO_SCROLLBAR) || defined(LSCS_NO_MAINWINDOW) || defined(LSCS_NO_MENUBAR))
#define LSCS_NO_WORKSPACE
#endif

// QPrintPreviewWidget
#if !defined(LSCS_NO_PRINTPREVIEWWIDGET) && (defined(LSCS_NO_GRAPHICSVIEW) || defined(LSCS_NO_PRINTER) || defined(LSCS_NO_MAINWINDOW))
#define LSCS_NO_PRINTPREVIEWWIDGET
#endif

// QCalendarWidget
#if !defined(LSCS_NO_CALENDARWIDGET) && (defined(LSCS_NO_TABLEVIEW) || defined(LSCS_NO_MENU) || defined(LSCS_NO_SPINBOX) || defined(LSCS_NO_TOOLBUTTON))
#define LSCS_NO_CALENDARWIDGET
#endif

// QDateTimeEdit
#if !defined(LSCS_NO_DATETIMEEDIT) && defined(LSCS_NO_CALENDARWIDGET)
#define LSCS_NO_DATETIMEEDIT
#endif

// QInputDialog
#if !defined(LSCS_NO_INPUTDIALOG) && (defined(LSCS_NO_COMBOBOX) || defined(LSCS_NO_SPINBOX) || defined(LSCS_NO_STACKEDWIDGET))
#define LSCS_NO_INPUTDIALOG
#endif

// QFontComboBox
#if !defined(LSCS_NO_FONTCOMBOBOX) && (defined(LSCS_NO_COMBOBOX) || defined(LSCS_NO_STRINGLISTMODEL))
#define LSCS_NO_FONTCOMBOBOX
#endif

// QFontDialog
#if !defined(LSCS_NO_FONTDIALOG) && (defined(LSCS_NO_STRINGLISTMODEL) || defined(LSCS_NO_COMBOBOX) || defined(LSCS_NO_VALIDATOR) || defined(LSCS_NO_GROUPBOX))
#define LSCS_NO_FONTDIALOG
#endif

// QPrintDialog
#if !defined(LSCS_NO_PRINTDIALOG) && (defined(LSCS_NO_PRINTER) || defined(LSCS_NO_COMBOBOX) || defined(LSCS_NO_BUTTONGROUP) || defined(LSCS_NO_SPINBOX) || defined(LSCS_NO_TREEVIEW) || defined(LSCS_NO_TABWIDGET))
#define LSCS_NO_PRINTDIALOG
#endif

// QFileDialog
#if !defined(LSCS_NO_FILEDIALOG) && (defined(LSCS_NO_DIRMODEL) || defined(LSCS_NO_TREEVIEW) || defined(LSCS_NO_COMBOBOX) || defined(LSCS_NO_TOOLBUTTON) || defined(LSCS_NO_BUTTONGROUP) || defined(LSCS_NO_TOOLTIP) || defined(LSCS_NO_SPLITTER) || defined(LSCS_NO_STACKEDWIDGET) || defined(LSCS_NO_PROXYMODEL))
#define LSCS_NO_FILEDIALOG
#endif

// QPrintPreviewDialog
#if !defined(LSCS_NO_PRINTPREVIEWDIALOG) && (defined(LSCS_NO_PRINTPREVIEWWIDGET) || defined(LSCS_NO_PRINTDIALOG) || defined(LSCS_NO_TOOLBAR))
#define LSCS_NO_PRINTPREVIEWDIALOG
#endif

//Input Method
#if defined(LSCS_NO_IM)
#define LSCS_NO_XIM
#endif

#endif