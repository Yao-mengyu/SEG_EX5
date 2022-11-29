#include "result.h"
#include "ui_result.h"

result::result(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
    // p = pin;
    item_model = new QStandardItemModel();
    ui->tableView->setModel(item_model);

    QStringList column, row;
    column << "File1" << "File2";
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    item_model->setHorizontalHeaderLabels(column);                // 设置水平表头标签
    QObject::connect(ui->quit_action,SIGNAL(triggered()),this,SLOT(on_pushButton_clicked()));
    QObject::connect(ui->save_action,SIGNAL(triggered()),this,SLOT(save_eq_file()));
    m_eventLoop = new QEventLoop();
    saved = false;
}

result::~result()
{
    delete ui;
}

bool result::save_eq_file(){
    QString path = QString("");
    path = QFileDialog::getSaveFileName(this,tr("保存文件"),
                           "./equal.csv",
                           tr("csv (*.csv)"));
    if(path.isEmpty()){
        return false;
    }
    ofstream eq_stream;
    eq_stream.open(path.toStdString(), ios::app);
    eq_stream<<"file1;file2"<<endl;
    for(const auto &i: eq_pair){
        eq_stream<< i<< endl;
    }
    eq_stream.close();
    saved = true;
    return true;
}

void result::on_pushButton_clicked()
{
    if(!saved){
    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this, "保存", "是否对等价程序对文件进行保存",QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
    if(ret == QMessageBox::Save){
        //-----调用保存----//
        if(!save_eq_file()){return;}//未保存
    }
    else if(ret == QMessageBox::Cancel){return;}
    }
    m_eventLoop->exit();

    //ui->hide();
}

void result::exec(){
    setWindowModality(Qt::ApplicationModal);

    show();
    ifstream file;

    file.open(p->equal_file,ios::in);
    string strLine;
    getline(file,strLine);//把标题file读走
    while(getline(file,strLine)){
        auto semi = strLine.find(",");
        if(p->final_eq(strLine.substr(0, semi), strLine.substr(semi+1, strLine.size()))){
           // ui-> tableView->append(QString(strLine.c_str()));
            eq_pair.emplace_back(strLine);
            QList<QStandardItem *> lsi;
            lsi.append(new QStandardItem(strLine.substr(0, semi).c_str()));
            lsi.append(new QStandardItem(strLine.substr(semi+1, strLine.size()).c_str()));
            item_model->appendRow(lsi);
        }
    }
    m_eventLoop->exec();
}

void result::closeEvent(QCloseEvent *event)

{

    /*

     * TODO 它可代替 TbarClose_Click 的功能

     */
    if(!saved){//未保存时提示保存
    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this, "保存", "是否对等价程序对文件进行保存",QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
    if(ret == QMessageBox::Save){
        //-----调用保存----//
        if(!save_eq_file()){ event->ignore(); return;}//未保存
    }
    else if(ret == QMessageBox::Cancel){ event->ignore(); return;}
    }
    m_eventLoop->exit();

    return QMainWindow::closeEvent(event);

}



