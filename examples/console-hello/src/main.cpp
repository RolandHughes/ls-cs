#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QString>
#include <QTemporaryDir>
#include <QRegularExpression>
#include <QStringList>
#include <QLibraryInfo>
#include "console-hello_build_info.h"

class SomeClass
{
    LSCS_GADGET( SomeClass )
public:
    QString name() {
        return m_name;
    }

private:
    QString m_name;
};

class Task : public QObject
{
    LSCS_OBJECT( Task )
public:
    Task( QObject *parent = 0 ) : QObject( parent ) {
        m_ptr = new SomeClass();
    }

    ~Task() {
        delete m_ptr;
    }

    LSCS_SLOT_1( Public, void run() )
    LSCS_SLOT_2( run )

    LSCS_SIGNAL_1( Public, void finished() )
    LSCS_SIGNAL_2( finished )

private:
    SomeClass *m_ptr;

};

void Task::run()
{
    // Do processing here

    QTextStream out(stdout);

    char bold [] = { 0x1b, '[', '1', 'm', '\0'};
    char endFormat [] = { 0x1b, '[', '0', 'm', '\0'};

    out << bold << "Hello World!" << endFormat << "\n\n";
    out << "Version:    " << versionString << endl;
    out << "Build Date: " << buildDate << endl;

    out << bold << "Sizes on your machine:" << endFormat << "\n";
    out << "     unsigned char      " << sizeof( unsigned char ) << endl;
    out << "     qint8              " << sizeof( qint8 ) << endl;
    out << "     qint16             " << sizeof( qint16 ) << endl;
    out << "     qint32             " << sizeof( qint32 ) << endl;
    out << "     qint64             " << sizeof( qint64 ) << endl;
    out << "     short int          " << sizeof( short int ) << endl;
    out << "     int                " << sizeof( int ) << endl;
    out << "     long               " << sizeof( long ) << endl;
    out << "     long long          " << sizeof( long long ) << endl;
    out << "     float              " << sizeof( float ) << endl;
    out << "     double             " << sizeof( double ) << endl;
    out << "     long double        " << sizeof( long double) << endl;


    out << "\n\nNext we will do some regular expression matching.\n";
    out << "This section can be useful if you want to try out some\n";
    out << "regular expressions for your own programs.\n" << endl;  // use endl to flush
    out << "\n\n";
    out << "str1:   MOVE =fred 1234 thru 5678 TO =Ethyl 5\n";
    out << "str2:   MOVE 1:5 TO 108\n";
    out << "str3:   MOVE =JANE 543 THRU 643 TO .\n";
    out << "\n";
    // extra slashes due to string escape sequences
    out << "rangeExpression( \"(\\\\d+ THRU \\\\d+)|(\\\\d+:\\\\d+)\", QPatternOption::CaseInsensitiveOption )\n\n";


    // Some regular expression experiments.
    //
    QString str1 = "MOVE =fred 1234 thru 5678 TO =Ethyl 5";
    QString str2 = "MOVE 1:5 TO 108";
    QString str3 = "MOVE =JANE 543 THRU 643 TO .";

    QRegularExpression rangeExpression( "(\\d+ THRU \\d+)|(\\d+:\\d+)", QPatternOption::CaseInsensitiveOption );
    QRegularExpressionMatch match1 = rangeExpression.match( str1 );
    QRegularExpressionMatch match2 = rangeExpression.match( str2 );
    QRegularExpressionMatch match3 = rangeExpression.match( str3 );

    if ( match1.hasMatch() )
    {
        out << "match1: " << endl;
        for ( QString txt : match1.capturedTexts())
        {
            out << "    " << txt << endl;
        }
    }

    if ( match2.hasMatch() )
    {
        out << "match2: " << endl;
        for ( QString txt : match2.capturedTexts())
        {
            out << "    " << txt << endl;
        }
    }

    if ( match3.hasMatch() )
    {
        out << "match3: " << endl;
        for ( QString txt : match3.capturedTexts())
        {
            out << "    " << txt << endl;
        }
    }


    emit finished();
}

int main( int argc, char *argv[] )
{
    QCoreApplication a( argc, argv );

    // parent task to application so it will be cleaned up
    //
    Task *task = new Task( &a );

    // make sure we know when things are done
    //
    QObject::connect( task, SIGNAL( finished() ), &a, SLOT( quit() ) );

    // Timer won't run until event loop starts
    //
    QTimer::singleShot( 0, task, SLOT( run() ) );

    // Go for it!
    return a.exec();
}
