#ifndef RESULT_H
#define RESULT_H

#include <QMainWindow>
#include <QEventLoop>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include "policy.h"
#include <vector>

namespace Ui {
class result;
}

class result : public QMainWindow
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = nullptr);
    ~result();
    void exec();
    Policy* p;

protected:
    void closeEvent(QCloseEvent *event);
    QEventLoop *m_eventLoop;

private slots:
    void on_pushButton_clicked();
    bool save_eq_file();
    bool save_doubt_file();


private:
    Ui::result *ui;
    QStandardItemModel* item_model;
    vector<string>eq_pair;
    bool saved;

};

#endif // RESULT_H
