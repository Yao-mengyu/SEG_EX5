#include "mainwindow.h"

#include <QApplication>
//using MyersStringDiff = MyersDiff<string>;
int main(int argc, char *argv[])
{
    if(argc < 3){
        cout<<"注意调用格式为 ./UI [equal.csv] [input_dir]"<<endl;
        return 1;
    }
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(true);
    MainWindow w(nullptr, argv[1], argv[2]);
   // cout<<"after close"<<w.show_it<<endl;
    w.show();
    return a.exec();
}
