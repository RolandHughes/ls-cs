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

#ifndef QDECLARATIVETEXTINPUT_P_H
#define QDECLARATIVETEXTINPUT_P_H

#include <qdeclarativetext_p.h>
#include <qdeclarativeimplicitsizeitem_p.h>
#include <QGraphicsSceneMouseEvent>
#include <QIntValidator>

#ifndef QT_NO_LINEEDIT

QT_BEGIN_NAMESPACE

class QDeclarativeTextInputPrivate;
class QValidator;

class QDeclarativeTextInput : public QDeclarativeImplicitSizePaintedItem
{
    DECL_LSCS_OBJECT( QDeclarativeTextInput )

    LSCS_ENUM( HAlignment )
    LSCS_ENUM( EchoMode )
    LSCS_ENUM( SelectionMode )

    DECL_LSCS_PROPERTY_READ( text, text )
    DECL_LSCS_PROPERTY_WRITE( text, setText )
    DECL_LSCS_PROPERTY_NOTIFY( text, textChanged )
    DECL_LSCS_PROPERTY_READ( color, color )
    DECL_LSCS_PROPERTY_WRITE( color, setColor )
    DECL_LSCS_PROPERTY_NOTIFY( color, colorChanged )
    DECL_LSCS_PROPERTY_READ( selectionColor, selectionColor )
    DECL_LSCS_PROPERTY_WRITE( selectionColor, setSelectionColor )
    DECL_LSCS_PROPERTY_NOTIFY( selectionColor, selectionColorChanged )
    DECL_LSCS_PROPERTY_READ( selectedTextColor, selectedTextColor )
    DECL_LSCS_PROPERTY_WRITE( selectedTextColor, setSelectedTextColor )
    DECL_LSCS_PROPERTY_NOTIFY( selectedTextColor, selectedTextColorChanged )
    DECL_LSCS_PROPERTY_READ( font, font )
    DECL_LSCS_PROPERTY_WRITE( font, setFont )
    DECL_LSCS_PROPERTY_NOTIFY( font, fontChanged )
    DECL_LSCS_PROPERTY_READ( horizontalAlignment, hAlign )
    DECL_LSCS_PROPERTY_WRITE( horizontalAlignment, setHAlign )
    DECL_LSCS_PROPERTY_RESET( horizontalAlignment, resetHAlign )
    DECL_LSCS_PROPERTY_NOTIFY( horizontalAlignment, horizontalAlignmentChanged )
    DECL_LSCS_PROPERTY_READ( readOnly, isReadOnly )
    DECL_LSCS_PROPERTY_WRITE( readOnly, setReadOnly )
    DECL_LSCS_PROPERTY_NOTIFY( readOnly, readOnlyChanged )
    DECL_LSCS_PROPERTY_READ( cursorVisible, isCursorVisible )
    DECL_LSCS_PROPERTY_WRITE( cursorVisible, setCursorVisible )
    DECL_LSCS_PROPERTY_NOTIFY( cursorVisible, cursorVisibleChanged )
    DECL_LSCS_PROPERTY_READ( cursorPosition, cursorPosition )
    DECL_LSCS_PROPERTY_WRITE( cursorPosition, setCursorPosition )
    DECL_LSCS_PROPERTY_NOTIFY( cursorPosition, cursorPositionChanged )
    DECL_LSCS_PROPERTY_READ( cursorRectangle, cursorRectangle )
    DECL_LSCS_PROPERTY_NOTIFY( cursorRectangle, cursorRectangleChanged )
    DECL_LSCS_PROPERTY_READ( *cursorDelegate, cursorDelegate )
    DECL_LSCS_PROPERTY_WRITE( *cursorDelegate, setCursorDelegate )
    DECL_LSCS_PROPERTY_NOTIFY( *cursorDelegate, cursorDelegateChanged )
    DECL_LSCS_PROPERTY_READ( selectionStart, selectionStart )
    DECL_LSCS_PROPERTY_NOTIFY( selectionStart, selectionStartChanged )
    DECL_LSCS_PROPERTY_READ( selectionEnd, selectionEnd )
    DECL_LSCS_PROPERTY_NOTIFY( selectionEnd, selectionEndChanged )
    DECL_LSCS_PROPERTY_READ( selectedText, selectedText )
    DECL_LSCS_PROPERTY_NOTIFY( selectedText, selectedTextChanged )

    DECL_LSCS_PROPERTY_READ( maximumLength, maxLength )
    DECL_LSCS_PROPERTY_WRITE( maximumLength, setMaxLength )
    DECL_LSCS_PROPERTY_NOTIFY( maximumLength, maximumLengthChanged )
#ifndef QT_NO_VALIDATOR
    DECL_LSCS_PROPERTY_READ( validator, validator )
    DECL_LSCS_PROPERTY_WRITE( validator, setValidator )
    DECL_LSCS_PROPERTY_NOTIFY( validator, validatorChanged )
#endif
    DECL_LSCS_PROPERTY_READ( inputMask, inputMask )
    DECL_LSCS_PROPERTY_WRITE( inputMask, setInputMask )
    DECL_LSCS_PROPERTY_NOTIFY( inputMask, inputMaskChanged )
    DECL_LSCS_PROPERTY_READ( inputMethodHints, imHints )
    DECL_LSCS_PROPERTY_WRITE( inputMethodHints, setIMHints )

    DECL_LSCS_PROPERTY_READ( acceptableInput, hasAcceptableInput )
    DECL_LSCS_PROPERTY_NOTIFY( acceptableInput, acceptableInputChanged )
    DECL_LSCS_PROPERTY_READ( echoMode, echoMode )
    DECL_LSCS_PROPERTY_WRITE( echoMode, setEchoMode )
    DECL_LSCS_PROPERTY_NOTIFY( echoMode, echoModeChanged )
    DECL_LSCS_PROPERTY_READ( activeFocusOnPress, focusOnPress )
    DECL_LSCS_PROPERTY_WRITE( activeFocusOnPress, setFocusOnPress )
    DECL_LSCS_PROPERTY_NOTIFY( activeFocusOnPress, activeFocusOnPressChanged )
    DECL_LSCS_PROPERTY_READ( passwordCharacter, passwordCharacter )
    DECL_LSCS_PROPERTY_WRITE( passwordCharacter, setPasswordCharacter )
    DECL_LSCS_PROPERTY_NOTIFY( passwordCharacter, passwordCharacterChanged )
    DECL_LSCS_PROPERTY_READ( displayText, displayText )
    DECL_LSCS_PROPERTY_NOTIFY( displayText, displayTextChanged )
    DECL_LSCS_PROPERTY_READ( autoScroll, autoScroll )
    DECL_LSCS_PROPERTY_WRITE( autoScroll, setAutoScroll )
    DECL_LSCS_PROPERTY_NOTIFY( autoScroll, autoScrollChanged )
    DECL_LSCS_PROPERTY_READ( selectByMouse, selectByMouse )
    DECL_LSCS_PROPERTY_WRITE( selectByMouse, setSelectByMouse )
    DECL_LSCS_PROPERTY_NOTIFY( selectByMouse, selectByMouseChanged )
    DECL_LSCS_PROPERTY_READ( mouseSelectionMode, mouseSelectionMode )
    DECL_LSCS_PROPERTY_WRITE( mouseSelectionMode, setMouseSelectionMode )
    DECL_LSCS_PROPERTY_NOTIFY( mouseSelectionMode, mouseSelectionModeChanged )
    DECL_LSCS_PROPERTY_REVISION( mouseSelectionMode, 1 )
    DECL_LSCS_PROPERTY_READ( canPaste, canPaste )
    DECL_LSCS_PROPERTY_NOTIFY( canPaste, canPasteChanged )
    DECL_LSCS_PROPERTY_REVISION( canPaste, 1 )
    DECL_LSCS_PROPERTY_READ( inputMethodComposing, isInputMethodComposing )
    DECL_LSCS_PROPERTY_NOTIFY( inputMethodComposing, inputMethodComposingChanged )
    DECL_LSCS_PROPERTY_REVISION( inputMethodComposing, 1 )

public:
    QDeclarativeTextInput( QDeclarativeItem *parent = 0 );
    ~QDeclarativeTextInput();

    enum EchoMode  //To match QLineEdit::EchoMode
    {
        Normal,
        NoEcho,
        Password,
        PasswordEchoOnEdit
    };

    enum HAlignment
    {
        AlignLeft = Qt::AlignLeft,
        AlignRight = Qt::AlignRight,
        AlignHCenter = Qt::AlignHCenter
    };

    enum SelectionMode
    {
        SelectCharacters,
        SelectWords
    };

    enum CursorPosition
    {
        CursorBetweenCharacters,
        CursorOnCharacter
    };

    //Auxilliary functions needed to control the TextInput from QML
    LSCS_INVOKABLE_METHOD_1( Public, int positionAt( int x ) const )
    LSCS_INVOKABLE_METHOD_OVERLOAD( positionAt, ( int ) )

    LSCS_INVOKABLE_METHOD_1( Public, int positionAt( int x, CursorPosition position ) const )
    LSCS_INVOKABLE_METHOD_OVERLOAD( positionAt, ( int, CursorPosition ) )
    LSCS_REVISION_OVERLOAD( positionAt, 1, ( int, CursorPosition ) )

    LSCS_INVOKABLE_METHOD_1( Public, QRectF positionToRectangle( int pos ) const )
    LSCS_INVOKABLE_METHOD_2( positionToRectangle )

    LSCS_INVOKABLE_METHOD_1( Public, void moveCursorSelection( int pos ) )
    LSCS_INVOKABLE_METHOD_OVERLOAD( moveCursorSelection, ( int ) )

    LSCS_INVOKABLE_METHOD_1( Public, void moveCursorSelection( int pos, SelectionMode mode ) )
    LSCS_INVOKABLE_METHOD_OVERLOAD( moveCursorSelection, ( int, SelectionMode ) )
    LSCS_REVISION_OVERLOAD( moveCursorSelection, 1, ( int, SelectionMode ) )

    LSCS_INVOKABLE_METHOD_1( Public, void openSoftwareInputPanel() )
    LSCS_INVOKABLE_METHOD_2( openSoftwareInputPanel )

    LSCS_INVOKABLE_METHOD_1( Public, void closeSoftwareInputPanel() )
    LSCS_INVOKABLE_METHOD_2( closeSoftwareInputPanel )

    QString text() const;
    void setText( const QString & );

    QFont font() const;
    void setFont( const QFont &font );

    QColor color() const;
    void setColor( const QColor &c );

    QColor selectionColor() const;
    void setSelectionColor( const QColor &c );

    QColor selectedTextColor() const;
    void setSelectedTextColor( const QColor &c );

    HAlignment hAlign() const;
    void setHAlign( HAlignment align );
    void resetHAlign();
    HAlignment effectiveHAlign() const;

    bool isReadOnly() const;
    void setReadOnly( bool );

    bool isCursorVisible() const;
    void setCursorVisible( bool on );

    int cursorPosition() const;
    void setCursorPosition( int cp );

    QRect cursorRectangle() const;

    int selectionStart() const;
    int selectionEnd() const;

    QString selectedText() const;

    int maxLength() const;
    void setMaxLength( int ml );

#ifndef QT_NO_VALIDATOR
    QValidator *validator() const;
    void setValidator( QValidator *v );
#endif

    QString inputMask() const;
    void setInputMask( const QString &im );

    EchoMode echoMode() const;
    void setEchoMode( EchoMode echo );

    QString passwordCharacter() const;
    void setPasswordCharacter( const QString &str );

    QString displayText() const;

    QDeclarativeComponent *cursorDelegate() const;
    void setCursorDelegate( QDeclarativeComponent * );

    bool focusOnPress() const;
    void setFocusOnPress( bool );

    bool autoScroll() const;
    void setAutoScroll( bool );

    bool selectByMouse() const;
    void setSelectByMouse( bool );

    SelectionMode mouseSelectionMode() const;
    void setMouseSelectionMode( SelectionMode mode );

    bool hasAcceptableInput() const;

    void drawContents( QPainter *p, const QRect &r );
    QVariant inputMethodQuery( Qt::InputMethodQuery property ) const;

    QRectF boundingRect() const;
    bool canPaste() const;

    bool isInputMethodComposing() const;

    Qt::InputMethodHints imHints() const;
    void setIMHints( Qt::InputMethodHints hints );

    DECL_LSCS_SIGNAL_1( Public, void textChanged() )
    DECL_LSCS_SIGNAL_2( textChanged )
    DECL_LSCS_SIGNAL_1( Public, void cursorPositionChanged() )
    DECL_LSCS_SIGNAL_2( cursorPositionChanged )
    DECL_LSCS_SIGNAL_1( Public, void cursorRectangleChanged() )
    DECL_LSCS_SIGNAL_2( cursorRectangleChanged )
    DECL_LSCS_SIGNAL_1( Public, void selectionStartChanged() )
    DECL_LSCS_SIGNAL_2( selectionStartChanged )
    DECL_LSCS_SIGNAL_1( Public, void selectionEndChanged() )
    DECL_LSCS_SIGNAL_2( selectionEndChanged )
    DECL_LSCS_SIGNAL_1( Public, void selectedTextChanged() )
    DECL_LSCS_SIGNAL_2( selectedTextChanged )
    DECL_LSCS_SIGNAL_1( Public, void accepted() )
    DECL_LSCS_SIGNAL_2( accepted )
    DECL_LSCS_SIGNAL_1( Public, void acceptableInputChanged() )
    DECL_LSCS_SIGNAL_2( acceptableInputChanged )
    DECL_LSCS_SIGNAL_1( Public, void colorChanged( const QColor &color ) )
    DECL_LSCS_SIGNAL_2( colorChanged, color )
    DECL_LSCS_SIGNAL_1( Public, void selectionColorChanged( const QColor &color ) )
    DECL_LSCS_SIGNAL_2( selectionColorChanged, color )
    DECL_LSCS_SIGNAL_1( Public, void selectedTextColorChanged( const QColor &color ) )
    DECL_LSCS_SIGNAL_2( selectedTextColorChanged, color )
    DECL_LSCS_SIGNAL_1( Public, void fontChanged( const QFont &font ) )
    DECL_LSCS_SIGNAL_2( fontChanged, font )
    DECL_LSCS_SIGNAL_1( Public, void horizontalAlignmentChanged( HAlignment alignment ) )
    DECL_LSCS_SIGNAL_2( horizontalAlignmentChanged, alignment )
    DECL_LSCS_SIGNAL_1( Public, void readOnlyChanged( bool isReadOnly ) )
    DECL_LSCS_SIGNAL_2( readOnlyChanged, isReadOnly )
    DECL_LSCS_SIGNAL_1( Public, void cursorVisibleChanged( bool isCursorVisible ) )
    DECL_LSCS_SIGNAL_2( cursorVisibleChanged, isCursorVisible )
    DECL_LSCS_SIGNAL_1( Public, void cursorDelegateChanged() )
    DECL_LSCS_SIGNAL_2( cursorDelegateChanged )
    DECL_LSCS_SIGNAL_1( Public, void maximumLengthChanged( int maximumLength ) )
    DECL_LSCS_SIGNAL_2( maximumLengthChanged, maximumLength )
    DECL_LSCS_SIGNAL_1( Public, void validatorChanged() )
    DECL_LSCS_SIGNAL_2( validatorChanged )
    DECL_LSCS_SIGNAL_1( Public, void inputMaskChanged( const QString &inputMask ) )
    DECL_LSCS_SIGNAL_2( inputMaskChanged, inputMask )
    DECL_LSCS_SIGNAL_1( Public, void echoModeChanged( EchoMode echoMode ) )
    DECL_LSCS_SIGNAL_2( echoModeChanged, echoMode )
    DECL_LSCS_SIGNAL_1( Public, void passwordCharacterChanged() )
    DECL_LSCS_SIGNAL_2( passwordCharacterChanged )
    DECL_LSCS_SIGNAL_1( Public, void displayTextChanged() )
    DECL_LSCS_SIGNAL_2( displayTextChanged )
    DECL_LSCS_SIGNAL_1( Public, void activeFocusOnPressChanged( bool activeFocusOnPress ) )
    DECL_LSCS_SIGNAL_2( activeFocusOnPressChanged, activeFocusOnPress )
    DECL_LSCS_SIGNAL_1( Public, void autoScrollChanged( bool autoScroll ) )
    DECL_LSCS_SIGNAL_2( autoScrollChanged, autoScroll )
    DECL_LSCS_SIGNAL_1( Public, void selectByMouseChanged( bool selectByMouse ) )
    DECL_LSCS_SIGNAL_2( selectByMouseChanged, selectByMouse )

    DECL_LSCS_SIGNAL_1( Public, void mouseSelectionModeChanged( SelectionMode mode ) )
    DECL_LSCS_SIGNAL_2( mouseSelectionModeChanged, mode )
    LSCS_REVISION( mouseSelectionModeChanged, 1 )

    DECL_LSCS_SIGNAL_1( Public, void canPasteChanged() )
    DECL_LSCS_SIGNAL_2( canPasteChanged )
    LSCS_REVISION( canPasteChanged, 1 )

    DECL_LSCS_SIGNAL_1( Public, void inputMethodComposingChanged() )
    DECL_LSCS_SIGNAL_2( inputMethodComposingChanged )
    LSCS_REVISION( inputMethodComposingChanged, 1 )

public :
    DECL_LSCS_SLOT_1( Public, void selectAll() )
    DECL_LSCS_SLOT_2( selectAll )

    DECL_LSCS_SLOT_1( Public, void selectWord() )
    DECL_LSCS_SLOT_2( selectWord )

    DECL_LSCS_SLOT_1( Public, void select( int start, int end ) )
    DECL_LSCS_SLOT_2( select )

    DECL_LSCS_SLOT_1( Public, void deselect() )
    DECL_LSCS_SLOT_2( deselect )
    LSCS_REVISION( deselect, 1 )

    DECL_LSCS_SLOT_1( Public, bool isRightToLeft( int start, int end ) )
    DECL_LSCS_SLOT_2( isRightToLeft )
    LSCS_REVISION( isRightToLeft, 1 )

#ifndef QT_NO_CLIPBOARD
    DECL_LSCS_SLOT_1( Public, void cut() )
    DECL_LSCS_SLOT_2( cut )
    DECL_LSCS_SLOT_1( Public, void copy() )
    DECL_LSCS_SLOT_2( copy )
    DECL_LSCS_SLOT_1( Public, void paste() )
    DECL_LSCS_SLOT_2( paste )
#endif

protected:
    virtual void geometryChanged( const QRectF &newGeometry, const QRectF &oldGeometry );

    void mousePressEvent( QGraphicsSceneMouseEvent *event );
    void mouseMoveEvent( QGraphicsSceneMouseEvent *event );
    void mouseReleaseEvent( QGraphicsSceneMouseEvent *event );
    void mouseDoubleClickEvent( QGraphicsSceneMouseEvent *event );
    bool sceneEvent( QEvent *event );
    void keyPressEvent( QKeyEvent *ev );
    void inputMethodEvent( QInputMethodEvent * );
    bool event( QEvent *e );
    void focusInEvent( QFocusEvent *event );

private :
    DECL_LSCS_SLOT_1( Private, void updateSize( bool needsRedraw = true ) )
    DECL_LSCS_SLOT_2( updateSize )
    DECL_LSCS_SLOT_1( Private, void q_textChanged() )
    DECL_LSCS_SLOT_2( q_textChanged )
    DECL_LSCS_SLOT_1( Private, void selectionChanged() )
    DECL_LSCS_SLOT_2( selectionChanged )
    DECL_LSCS_SLOT_1( Private, void createCursor() )
    DECL_LSCS_SLOT_2( createCursor )
    DECL_LSCS_SLOT_1( Private, void cursorPosChanged() )
    DECL_LSCS_SLOT_2( cursorPosChanged )
    DECL_LSCS_SLOT_1( Private, void updateCursorRectangle() )
    DECL_LSCS_SLOT_2( updateCursorRectangle )
    DECL_LSCS_SLOT_1( Private, void updateRect( const QRect &r = QRect() ) )
    DECL_LSCS_SLOT_2( updateRect )
    DECL_LSCS_SLOT_1( Private, void q_canPasteChanged() )
    DECL_LSCS_SLOT_2( q_canPasteChanged )

private:
    Q_DECLARE_PRIVATE_D( QGraphicsItem::d_ptr.data(), QDeclarativeTextInput )
};

QT_END_NAMESPACE

QML_DECLARE_TYPE( QDeclarativeTextInput )
#ifndef QT_NO_VALIDATOR
QML_DECLARE_TYPE( QValidator )
QML_DECLARE_TYPE( QIntValidator )
QML_DECLARE_TYPE( QDoubleValidator )
QML_DECLARE_TYPE( QRegExpValidator )
#endif

#endif // QT_NO_LINEEDIT

#endif // QDECLARATIVETEXTINPUT_H
