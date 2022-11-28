#ifndef RESULT_H
#define RESULT_H

#include <QMainWindow>
#include <QEventLoop>

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

protected:
    void closeEvent(QCloseEvent *event);
    QEventLoop *m_eventLoop;

private slots:
    void on_pushButton_clicked();

private:
    Ui::result *ui;
};

#endif // RESULT_H
