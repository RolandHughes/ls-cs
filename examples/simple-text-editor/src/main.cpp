//
// copyright (c) 2021 Roland Hughes d/b/a Logikal Solutions
//
// The License.txt file describes the conditions under which this software may be distributed.
//

#include <QApplication>
#include "mainwindow.h"

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );

    MainWindow *mw = new MainWindow();

    mw->show();

    return a.exec();
}
