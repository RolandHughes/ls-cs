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

#ifndef QABSTRACTITEMVIEW_H
#define QABSTRACTITEMVIEW_H

#include <qabstractitemdelegate.h>
#include <qabstractitemmodel.h>
#include <qabstractscrollarea.h>
#include <qitemselectionmodel.h>

#ifndef LSCS_NO_ITEMVIEWS

class QAbstractItemViewPrivate;
class QDrag;
class QEvent;
class QMenu;

class Q_GUI_EXPORT QAbstractItemView : public QAbstractScrollArea
{
    GUI_LSCS_OBJECT( QAbstractItemView )

    GUI_LSCS_ENUM( SelectionMode )
    GUI_LSCS_ENUM( SelectionBehavior )
    GUI_LSCS_ENUM( ScrollHint )
    GUI_LSCS_ENUM( ScrollMode )
    GUI_LSCS_ENUM( DragDropMode )

    GUI_LSCS_ENUM( EditTrigger )
    GUI_LSCS_FLAG( EditTrigger, EditTriggers )

    GUI_LSCS_PROPERTY_READ( autoScroll, hasAutoScroll )
    GUI_LSCS_PROPERTY_WRITE( autoScroll, setAutoScroll )

    GUI_LSCS_PROPERTY_READ( autoScrollMargin, autoScrollMargin )
    GUI_LSCS_PROPERTY_WRITE( autoScrollMargin, setAutoScrollMargin )

    GUI_LSCS_PROPERTY_READ( editTriggers, editTriggers )
    GUI_LSCS_PROPERTY_WRITE( editTriggers, setEditTriggers )

    GUI_LSCS_PROPERTY_READ( tabKeyNavigation, tabKeyNavigation )
    GUI_LSCS_PROPERTY_WRITE( tabKeyNavigation, setTabKeyNavigation )

#ifndef LSCS_NO_DRAGANDDROP
    GUI_LSCS_PROPERTY_READ( showDropIndicator, showDropIndicator )
    GUI_LSCS_PROPERTY_WRITE( showDropIndicator, setDropIndicatorShown )

    GUI_LSCS_PROPERTY_READ( dragEnabled, dragEnabled )
    GUI_LSCS_PROPERTY_WRITE( dragEnabled, setDragEnabled )

    GUI_LSCS_PROPERTY_READ( dragDropOverwriteMode, dragDropOverwriteMode )
    GUI_LSCS_PROPERTY_WRITE( dragDropOverwriteMode, setDragDropOverwriteMode )

    GUI_LSCS_PROPERTY_READ( dragDropMode, dragDropMode )
    GUI_LSCS_PROPERTY_WRITE( dragDropMode, setDragDropMode )

    GUI_LSCS_PROPERTY_READ( defaultDropAction, defaultDropAction )
    GUI_LSCS_PROPERTY_WRITE( defaultDropAction, setDefaultDropAction )
#endif

    GUI_LSCS_PROPERTY_READ( alternatingRowColors, alternatingRowColors )
    GUI_LSCS_PROPERTY_WRITE( alternatingRowColors, setAlternatingRowColors )
    GUI_LSCS_PROPERTY_READ( selectionMode, selectionMode )
    GUI_LSCS_PROPERTY_WRITE( selectionMode, setSelectionMode )

    GUI_LSCS_PROPERTY_READ( selectionBehavior, selectionBehavior )
    GUI_LSCS_PROPERTY_WRITE( selectionBehavior, setSelectionBehavior )

    GUI_LSCS_PROPERTY_READ( iconSize, iconSize )
    GUI_LSCS_PROPERTY_WRITE( iconSize, setIconSize )
    GUI_LSCS_PROPERTY_NOTIFY( iconSize, iconSizeChanged )

    GUI_LSCS_PROPERTY_READ( textElideMode, textElideMode )
    GUI_LSCS_PROPERTY_WRITE( textElideMode, setTextElideMode )

    GUI_LSCS_PROPERTY_READ( verticalScrollMode, verticalScrollMode )
    GUI_LSCS_PROPERTY_WRITE( verticalScrollMode, setVerticalScrollMode )

    GUI_LSCS_PROPERTY_READ( horizontalScrollMode, horizontalScrollMode )
    GUI_LSCS_PROPERTY_WRITE( horizontalScrollMode, setHorizontalScrollMode )

public:
    GUI_LSCS_REGISTER_ENUM(
        enum SelectionMode
    {
        NoSelection,
        SingleSelection,
        MultiSelection,
        ExtendedSelection,
        ContiguousSelection
    };
    )

    GUI_LSCS_REGISTER_ENUM(
        enum SelectionBehavior
    {
        SelectItems,
        SelectRows,
        SelectColumns
    };
    )

    enum ScrollHint
    {
        EnsureVisible,
        PositionAtTop,
        PositionAtBottom,
        PositionAtCenter
    };

    GUI_LSCS_REGISTER_ENUM(
        enum EditTrigger
    {
        NoEditTriggers  = 0,
        CurrentChanged  = 1,
        DoubleClicked   = 2,
        SelectedClicked = 4,
        EditKeyPressed  = 8,
        AnyKeyPressed   = 16,
        AllEditTriggers = 31
    };
    )

    using EditTriggers = QFlags<EditTrigger>;

    GUI_LSCS_REGISTER_ENUM(
        enum ScrollMode
    {
        ScrollPerItem,
        ScrollPerPixel
    };
    )

#ifndef LSCS_NO_DRAGANDDROP
    GUI_LSCS_REGISTER_ENUM(
        enum DragDropMode
    {
        NoDragDrop,
        DragOnly,
        DropOnly,
        DragDrop,
        InternalMove
    };
    )
#endif

    explicit QAbstractItemView( QWidget *parent = nullptr );

    QAbstractItemView( const QAbstractItemView & ) = delete;
    QAbstractItemView &operator=( const QAbstractItemView & ) = delete;

    ~QAbstractItemView();

    virtual void setModel( QAbstractItemModel *model );
    QAbstractItemModel *model() const;

    virtual void setSelectionModel( QItemSelectionModel *selectionModel );
    QItemSelectionModel *selectionModel() const;

    void setItemDelegate( QAbstractItemDelegate *delegate );
    QAbstractItemDelegate *itemDelegate() const;

    void setSelectionMode( QAbstractItemView::SelectionMode mode );
    QAbstractItemView::SelectionMode selectionMode() const;

    void setSelectionBehavior( QAbstractItemView::SelectionBehavior behavior );
    QAbstractItemView::SelectionBehavior selectionBehavior() const;

    QModelIndex currentIndex() const;
    QModelIndex rootIndex() const;

    void setEditTriggers( EditTriggers triggers );
    EditTriggers editTriggers() const;

    void setVerticalScrollMode( ScrollMode mode );
    ScrollMode verticalScrollMode() const;

    void setHorizontalScrollMode( ScrollMode mode );
    ScrollMode horizontalScrollMode() const;

    void setAutoScroll( bool enable );
    bool hasAutoScroll() const;

    void setAutoScrollMargin( int margin );
    int autoScrollMargin() const;

    void setTabKeyNavigation( bool enable );
    bool tabKeyNavigation() const;

#ifndef LSCS_NO_DRAGANDDROP
    void setDropIndicatorShown( bool enable );
    bool showDropIndicator() const;

    void setDragEnabled( bool enable );
    bool dragEnabled() const;

    void setDragDropOverwriteMode( bool overwrite );
    bool dragDropOverwriteMode() const;

    void setDragDropMode( DragDropMode behavior );
    DragDropMode dragDropMode() const;

    void setDefaultDropAction( Qt::DropAction dropAction );
    Qt::DropAction defaultDropAction() const;
#endif

    void setAlternatingRowColors( bool enable );
    bool alternatingRowColors() const;

    void setIconSize( const QSize &size );
    QSize iconSize() const;

    void setTextElideMode( Qt::TextElideMode mode );
    Qt::TextElideMode textElideMode() const;

    virtual void keyboardSearch( const QString &search );

    virtual QRect visualRect( const QModelIndex &index ) const = 0;
    virtual void scrollTo( const QModelIndex &index, ScrollHint hint = EnsureVisible ) = 0;
    virtual QModelIndex indexAt( const QPoint &point ) const = 0;

    QSize sizeHintForIndex( const QModelIndex &index ) const;
    virtual int sizeHintForRow( int row ) const;
    virtual int sizeHintForColumn( int column ) const;

    void openPersistentEditor( const QModelIndex &index );
    void closePersistentEditor( const QModelIndex &index );

    void setIndexWidget( const QModelIndex &index, QWidget *widget );
    QWidget *indexWidget( const QModelIndex &index ) const;

    void setItemDelegateForRow( int row, QAbstractItemDelegate *delegate );
    QAbstractItemDelegate *itemDelegateForRow( int row ) const;

    void setItemDelegateForColumn( int column, QAbstractItemDelegate *delegate );
    QAbstractItemDelegate *itemDelegateForColumn( int column ) const;

    QAbstractItemDelegate *itemDelegate( const QModelIndex &index ) const;

    QVariant inputMethodQuery( Qt::InputMethodQuery query ) const override;

    GUI_LSCS_SLOT_1( Public, virtual void reset() )
    GUI_LSCS_SLOT_2( reset )

    GUI_LSCS_SLOT_1( Public, virtual void setRootIndex( const QModelIndex &index ) )
    GUI_LSCS_SLOT_2( setRootIndex )

    GUI_LSCS_SLOT_1( Public, virtual void doItemsLayout() )
    GUI_LSCS_SLOT_2( doItemsLayout )

    GUI_LSCS_SLOT_1( Public, virtual void selectAll() )
    GUI_LSCS_SLOT_2( selectAll )

    GUI_LSCS_SLOT_1( Public, void edit( const QModelIndex &index ) )
    GUI_LSCS_SLOT_OVERLOAD( edit, ( const QModelIndex & ) )

    GUI_LSCS_SLOT_1( Public, void clearSelection() )
    GUI_LSCS_SLOT_2( clearSelection )

    GUI_LSCS_SLOT_1( Public, void setCurrentIndex( const QModelIndex &index ) )
    GUI_LSCS_SLOT_2( setCurrentIndex )

    GUI_LSCS_SLOT_1( Public, void scrollToTop() )
    GUI_LSCS_SLOT_2( scrollToTop )

    GUI_LSCS_SLOT_1( Public, void scrollToBottom() )
    GUI_LSCS_SLOT_2( scrollToBottom )

    using QAbstractScrollArea::update;

    GUI_LSCS_SLOT_1( Public, void update( const QModelIndex &index ) )
    GUI_LSCS_SLOT_OVERLOAD( update, ( const QModelIndex & ) )

    GUI_LSCS_SIGNAL_1( Public, void pressed( const QModelIndex &index ) )
    GUI_LSCS_SIGNAL_2( pressed, index )

    GUI_LSCS_SIGNAL_1( Public, void clicked( const QModelIndex &index ) )
    GUI_LSCS_SIGNAL_2( clicked, index )

    GUI_LSCS_SIGNAL_1( Public, void doubleClicked( const QModelIndex &index ) )
    GUI_LSCS_SIGNAL_2( doubleClicked, index )

    GUI_LSCS_SIGNAL_1( Public, void activated( const QModelIndex &index ) )
    GUI_LSCS_SIGNAL_2( activated, index )

    GUI_LSCS_SIGNAL_1( Public, void entered( const QModelIndex &index ) )
    GUI_LSCS_SIGNAL_2( entered, index )

    GUI_LSCS_SIGNAL_1( Public, void viewportEntered() )
    GUI_LSCS_SIGNAL_2( viewportEntered )

    GUI_LSCS_SIGNAL_1( Public, void iconSizeChanged( const QSize &size ) )
    GUI_LSCS_SIGNAL_2( iconSizeChanged, size )

protected:
    enum CursorAction
    {
        MoveUp,
        MoveDown,
        MoveLeft,
        MoveRight,
        MoveHome,
        MoveEnd,
        MovePageUp,
        MovePageDown,
        MoveNext,
        MovePrevious
    };

    enum State
    {
        NoState,
        DraggingState,
        DragSelectingState,
        EditingState,
        ExpandingState,
        CollapsingState,
        AnimatingState
    };

#ifndef LSCS_NO_DRAGANDDROP
    enum DropIndicatorPosition
    {
        OnItem,
        AboveItem,
        BelowItem,
        OnViewport
    };
#endif

    GUI_LSCS_SLOT_1( Protected, virtual void dataChanged( const QModelIndex &topLeft, const QModelIndex &bottomRight,
                     const QVector<int> &roles = QVector<int>() ) )
    GUI_LSCS_SLOT_2( dataChanged )

    GUI_LSCS_SLOT_1( Protected, virtual void rowsInserted( const QModelIndex &parent, int start, int end ) )
    GUI_LSCS_SLOT_2( rowsInserted )

    GUI_LSCS_SLOT_1( Protected, virtual void rowsAboutToBeRemoved( const QModelIndex &parent, int start, int end ) )
    GUI_LSCS_SLOT_2( rowsAboutToBeRemoved )

    GUI_LSCS_SLOT_1( Protected, virtual void selectionChanged( const QItemSelection &selected,
                     const QItemSelection &deselected ) )
    GUI_LSCS_SLOT_2( selectionChanged )

    GUI_LSCS_SLOT_1( Protected, virtual void currentChanged( const QModelIndex &current, const QModelIndex &previous ) )
    GUI_LSCS_SLOT_2( currentChanged )

    GUI_LSCS_SLOT_1( Protected, virtual void updateEditorData() )
    GUI_LSCS_SLOT_2( updateEditorData )

    GUI_LSCS_SLOT_1( Protected, virtual void updateEditorGeometries() )
    GUI_LSCS_SLOT_2( updateEditorGeometries )

    GUI_LSCS_SLOT_1( Protected, virtual void updateGeometries() )
    GUI_LSCS_SLOT_2( updateGeometries )

    GUI_LSCS_SLOT_1( Protected, virtual void verticalScrollbarAction( int action ) )
    GUI_LSCS_SLOT_2( verticalScrollbarAction )

    GUI_LSCS_SLOT_1( Protected, virtual void horizontalScrollbarAction( int action ) )
    GUI_LSCS_SLOT_2( horizontalScrollbarAction )

    GUI_LSCS_SLOT_1( Protected, virtual void verticalScrollbarValueChanged( int value ) )
    GUI_LSCS_SLOT_2( verticalScrollbarValueChanged )

    GUI_LSCS_SLOT_1( Protected, virtual void horizontalScrollbarValueChanged( int value ) )
    GUI_LSCS_SLOT_2( horizontalScrollbarValueChanged )

    GUI_LSCS_SLOT_1( Protected, virtual void closeEditor( QWidget *editor, QAbstractItemDelegate::EndEditHint hint ) )
    GUI_LSCS_SLOT_2( closeEditor )

    GUI_LSCS_SLOT_1( Protected, virtual void commitData( QWidget *editor ) )
    GUI_LSCS_SLOT_2( commitData )

    GUI_LSCS_SLOT_1( Protected, virtual void editorDestroyed( QObject *editor ) )
    GUI_LSCS_SLOT_2( editorDestroyed )

    QAbstractItemView( QAbstractItemViewPrivate &, QWidget *parent = nullptr );

    void setHorizontalStepsPerItem( int steps );
    int horizontalStepsPerItem() const;
    void setVerticalStepsPerItem( int steps );
    int verticalStepsPerItem() const;

    virtual QModelIndex moveCursor( CursorAction cursorAction, Qt::KeyboardModifiers modifiers ) = 0;

    virtual int horizontalOffset() const = 0;
    virtual int verticalOffset() const = 0;

    virtual bool isIndexHidden( const QModelIndex &index ) const = 0;

    virtual void setSelection( const QRect &rect, QItemSelectionModel::SelectionFlags flags ) = 0;
    virtual QRegion visualRegionForSelection( const QItemSelection &selection ) const = 0;
    virtual QModelIndexList selectedIndexes() const;

    virtual bool edit( const QModelIndex &index, EditTrigger trigger, QEvent *event );

    virtual QItemSelectionModel::SelectionFlags selectionCommand( const QModelIndex &index, const QEvent *event = nullptr ) const;

    virtual QStyleOptionViewItem viewOptions() const;

    State state() const;
    void setState( State state );

    void scheduleDelayedItemsLayout();
    void executeDelayedItemsLayout();

    void setDirtyRegion( const QRegion &region );
    void scrollDirtyRegion( int dx, int dy );
    QPoint dirtyRegionOffset() const;

    void startAutoScroll();
    void stopAutoScroll();
    void doAutoScroll();

    bool focusNextPrevChild( bool next ) override;
    bool event( QEvent *event ) override;
    bool viewportEvent( QEvent *event ) override;
    void mousePressEvent( QMouseEvent *event ) override;
    void mouseMoveEvent( QMouseEvent *event ) override;
    void mouseReleaseEvent( QMouseEvent *event ) override;
    void mouseDoubleClickEvent( QMouseEvent *event ) override;

#ifndef LSCS_NO_DRAGANDDROP
    void dragEnterEvent( QDragEnterEvent *event ) override;
    void dragMoveEvent( QDragMoveEvent *event ) override;
    void dragLeaveEvent( QDragLeaveEvent *event ) override;
    void dropEvent( QDropEvent *event ) override;

    DropIndicatorPosition dropIndicatorPosition() const;

    virtual void startDrag( Qt::DropActions supportedActions );
#endif

    void focusInEvent( QFocusEvent *event ) override;
    void focusOutEvent( QFocusEvent *event ) override;
    void keyPressEvent( QKeyEvent *event ) override;
    void resizeEvent( QResizeEvent *event ) override;
    void timerEvent( QTimerEvent *event ) override;
    void inputMethodEvent( QInputMethodEvent *event ) override;

    QSize viewportSizeHint() const override;

private:
    Q_DECLARE_PRIVATE( QAbstractItemView )

    GUI_LSCS_SLOT_1( Private, void _q_columnsAboutToBeRemoved( const QModelIndex &parent, int start, int end ) )
    GUI_LSCS_SLOT_2( _q_columnsAboutToBeRemoved )

    GUI_LSCS_SLOT_1( Private, void _q_columnsRemoved( const QModelIndex &parent, int start, int end ) )
    GUI_LSCS_SLOT_2( _q_columnsRemoved )

    GUI_LSCS_SLOT_1( Private, void _q_columnsInserted( const QModelIndex &parent, int start, int end ) )
    GUI_LSCS_SLOT_2( _q_columnsInserted )

    GUI_LSCS_SLOT_1( Private, void _q_columnsMoved( const QModelIndex &source, int sourceStart, int sourceEnd,
                     const QModelIndex &destination, int destinationStart ) )
    GUI_LSCS_SLOT_2( _q_columnsMoved )

    GUI_LSCS_SLOT_1( Private, void _q_rowsInserted( const QModelIndex &parent, int start, int end ) )
    GUI_LSCS_SLOT_2( _q_rowsInserted )

    GUI_LSCS_SLOT_1( Private, void _q_rowsRemoved( const QModelIndex &parent, int start, int end ) )
    GUI_LSCS_SLOT_2( _q_rowsRemoved )

    GUI_LSCS_SLOT_1( Private, void _q_rowsMoved( const QModelIndex &source, int sourceStart, int sourceEnd,
                     const QModelIndex &destination, int destinationStart ) )
    GUI_LSCS_SLOT_2( _q_rowsMoved )

    void _q_modelDestroyed();
    void _q_layoutChanged();
    void _q_headerDataChanged();

#ifndef LSCS_NO_GESTURES
    GUI_LSCS_SLOT_1( Private, void _q_scrollerStateChanged() )
    GUI_LSCS_SLOT_2( _q_scrollerStateChanged )
#endif

    friend class QTreeView;
    friend class QTreeViewPrivate;
    friend class QListModeViewBase;
    friend class QListViewPrivate;
};

Q_DECLARE_OPERATORS_FOR_FLAGS( QAbstractItemView::EditTriggers )

#endif // LSCS_NO_ITEMVIEWS

#endif
