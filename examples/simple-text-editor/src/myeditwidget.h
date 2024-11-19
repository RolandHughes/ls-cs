//
// copyright (c) 2021 Roland Hughes d/b/a Logikal Solutions
//
// The License.txt file describes the conditions under which this software may be distributed.
//

#ifndef MYEDITWIDGET_H
#define MYEDITWIDGET_H

#include <QTextEdit>
#include <QString>

class QDropEvent;
class QDragEnterEvent;

class MyEditWidget : public QTextEdit
{
    LSCS_OBJECT( MyEditWidget )
public:
    MyEditWidget( QWidget *parent = 0 );

    // This is a style thing.
    // Try to keep methods that return values near the top of the class
    // declaration, alphabetical by type. Logical groupings via function
    // simply get unmanageable in large projects or classes. You always end
    // up with a method or twelve that belong in multiple groups.
    //
    QString currentFile();

    bool    closeDoc();
    bool    isEmpty();
    bool    isDirty();


    void clearEditWidget();
    void loadFile( QString fullPathToFile );
    void newDoc();
    void openDoc();
    void save();
    void saveAs();
    void savePointReached(bool yesNo);
    void setBackgroundColor( QColor background);

    //
    //  Signals
    //
    LSCS_SIGNAL_1( Public, void newTabForFile( QString fileName ) )
    LSCS_SIGNAL_2( newTabForFile, fileName )

    LSCS_SIGNAL_1( Public, void newTabForText( QString text ) )
    LSCS_SIGNAL_2( newTabForText, text )

    LSCS_SIGNAL_1( Public, void updateTabText() )
    LSCS_SIGNAL_2( updateTabText )

    LSCS_SIGNAL_1( Public, void updateDirtyIndicator() )
    LSCS_SIGNAL_2( updateDirtyIndicator )

protected:
    void dropEvent( QDropEvent *event );
    void dragEnterEvent( QDragEnterEvent *event );

private:
    QString m_currentFile;
    bool    m_isDirty;
};

#endif  /* MYEDITWIDGET_H */
