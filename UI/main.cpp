#include "mainwindow.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(true);
    MainWindow w(nullptr, "testfile");
   // cout<<"after close"<<w.show_it<<endl;
    w.show();
    return a.exec();
}
