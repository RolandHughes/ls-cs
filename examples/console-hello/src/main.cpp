#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QString>
#include <QTemporaryDir>
#include <QRegularExpression>
#include <QStringList>
#include "console-hello_build_info.h"

class SomeClass
{
    LSCS_GADGET( SomeClass )
public:
    QString name() { return m_name;}

private:
    QString m_name;
};

class Task : public QObject
{
    LSCS_OBJECT( Task )
public:
    Task( QObject *parent = 0 ) : QObject( parent ) {m_ptr = new SomeClass();}

    ~Task() { delete m_ptr;}

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

    out << "Hello World!\n";
    out << "Version:    " << versionString << endl;
    out << "Build Date: " << buildDate << endl;
    out << "m_ptr->name(): " << m_ptr->name() << "\n";


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

    // More Regular Expression experiments
    //
    QRegularExpression dupExpression( "(/DUP.*:\\d+)", QPatternOption::CaseInsensitiveOption );
    QRegularExpression badDupExpression( "(/DUP.*)", QPatternOption::CaseInsensitiveOption );
    QRegularExpression queryExpression( "/Q.*", QPatternOption::CaseInsensitiveOption );
    QString str4 = "COPY =main.cpp 8:10 TO =overlord.cpp 12 /duplicate:9";
    QString str5 = "COPY . TO 9 /DUP:22";
    QString str6 = "COPY BEFORE TO 100 /DUPLICATE:100";
    QString str7 = "COPY 4 TO 120/DUP:12";
    QString str8 = "COPY 6 TO 110 /DUP:";
    QString str9 = "COPY . TO 9 /DUP:22/Q";
    QString str10 = "MOVE 20:30 TO 140 /Q";

    QRegularExpressionMatch match4 = dupExpression.match( str4 );
    QRegularExpressionMatch match5 = dupExpression.match( str5 );
    QRegularExpressionMatch match6 = dupExpression.match( str6 );
    QRegularExpressionMatch match7 = dupExpression.match( str7 );
    QRegularExpressionMatch match8 = badDupExpression.match( str8 );
    QRegularExpressionMatch match9 = queryExpression.match( str9 );
    QRegularExpressionMatch match10 = queryExpression.match( str10 );

    if ( match4.hasMatch() )
    {
        out << "match4: " << endl;
        for ( QString txt : match4.capturedTexts())
        {
            out << "    " << txt << endl;
        }
    }
    else
    {
        out << "match4 had no matches\n";
    }

    if ( match5.hasMatch() )
    {
        out << "match5: " << endl;
        for ( QString txt : match5.capturedTexts())
        {
            out << "    " << txt << endl;
        }
    }
    else
    {
        out << "match5 had no matches\n";
    }

    if ( match6.hasMatch() )
    {
        out << "match6: " << endl;
        for ( QString txt : match6.capturedTexts())
        {
            out << "    " << txt << endl;
        }
    }
    else
    {
        out << "match6 had no matches\n";
    }

    if ( match7.hasMatch() )
    {
        out << "match7: " << endl;
        for ( QString txt : match7.capturedTexts())
        {
            out << "    " << txt << endl;
        }
    }
    else
    {
        out << "match7 had no matches\n";
    }

    if ( match8.hasMatch() )
    {
        out << "match8: " << endl;
        for ( QString txt : match8.capturedTexts())
        {
            out << "    " << txt << endl;
        }
    }
    else
    {
        out << "match8 had no matches\n";
    }

    if ( match9.hasMatch() )
    {
        out << "match9: " << endl;
        for ( QString txt : match9.capturedTexts())
        {
            out << "    " << txt << endl;
        }
    }
    else
    {
        out << "match9 had no matches\n";
    }

    if ( match10.hasMatch() )
    {
        out << "match10: " << endl;
        for ( QString txt : match10.capturedTexts())
        {
            out << "    " << txt << endl;
        }
    }
    else
    {
        out << "match10 had no matches\n";
    }

    out << "    *****  \n";
    out << "    *****  \n";
    out << "    *****  \n";
    out << " Sizes on your machine: \n";
    out << "     unsigned char      " << sizeof( unsigned char ) << endl;
    out << "     short int          " << sizeof( short int ) << endl;
    out << "     int                " << sizeof( int ) << endl;
    out << "     long               " << sizeof( long ) << endl;
    out << "     long long          " << sizeof( long long ) << endl;
    out << "     float              " << sizeof( float ) << endl;
    out << "     double             " << sizeof( double ) << endl;
    

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
