#include <QMainWindow>

class QLabel;
class QVBoxLayout;
class QTextEdit;

class MainWindow : public QMainWindow
{
    LSCS_OBJECT( MainWindow )
public:
    MainWindow( QWidget *parent=0 );
    ~MainWindow();

private:
    void populateTextEdit();

    QLabel         *m_hello;
    QVBoxLayout    *m_layout;
    QWidget        *m_widget;
    QTextEdit *m_textEdit;

};
