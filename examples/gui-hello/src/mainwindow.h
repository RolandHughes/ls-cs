#include <QMainWindow>

class QLabel;
class QVBoxLayout;
class QPushButton;
class QPlainTextEdit;

class MainWindow : public QMainWindow
{
    LSCS_OBJECT( MainWindow )
public:
    MainWindow( QWidget *parent=0 );
    ~MainWindow();

    void printSomething();

private:

    QLabel         *m_hello;
    QVBoxLayout    *m_layout;
    QWidget        *m_widget;
    QPushButton    *m_printBtn;
    QPlainTextEdit *m_textEdit;

};
