#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include "policy.h"
#include "result.h"
//#include "dmp_diff.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, string eq_file = "", string dir = "");
    ~MainWindow();
    bool show_it;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QString file1_name;
    QString file2_name;
    string eq_file;
    Policy p;
    void update_judge_state();
    result rw;
    string input_dir;
};
#endif // MAINWINDOW_H
