#include <QtGui/QApplication>
#include "mainwindow.h"
#include "time.h"

int main(int argc, char *argv[])
{
    srand ( time(NULL) );
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

