#include "result.h"
#include "ui_result.h"

result::result(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
    m_eventLoop = new QEventLoop();
}

result::~result()
{
    delete ui;
}

void result::on_pushButton_clicked()
{

}

void result::exec(){
    setWindowModality(Qt::ApplicationModal);

    show();

    m_eventLoop->exec();
}

void result::closeEvent(QCloseEvent *event)

{

    /*

     * TODO 它可代替 TbarClose_Click 的功能

     */

    m_eventLoop->exit();

    return QMainWindow::closeEvent(event);

}

