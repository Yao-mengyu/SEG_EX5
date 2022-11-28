#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent, string eq_file)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , p(Policy(eq_file))
{
    ui->setupUi(this);
   // eq_file = eq_file;
   //Policy p(eq_file);
    //p = &p_s;
    show_it = true;
   // result rw(nullptr);
    update_judge_state();
   // result rw_s = result();
    //rw = &rw_s;
   // ui->file1_name->setText("1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_judge_state(){
    pair<string, string> to_judge;
    to_judge = this->p.get_nxt_pair();
    while(true){
   //  cout<<to_judge.first.size()<<endl<<to_judge.second.size()<<endl;
    if(to_judge.first.size()==0 && to_judge.second.size()==0){
        //--------------判断完成---------------//
        
        show_it = false;
        close();
        
        rw.exec();
        exit(0);
      
        
    }else if(this-> p.need_judge(to_judge.first, to_judge.second)){
        this->file1_name = QString(to_judge.first.c_str());
        this->file2_name = QString(to_judge.second.c_str());
        ui->file1_name->setText(file1_name);
        ui->file2_name->setText(file2_name);
        break;
    }
    to_judge = this->p.get_nxt_pair();
    }
}


void MainWindow::on_pushButton_clicked()
{
    string std_name1 = this->file1_name.toStdString();
    string std_name2 = this->file2_name.toStdString();
   // cout<<"here"<<endl;
    this->p.update_result(std_name1, std_name2, true); 
    update_judge_state();
    cout<<"equal"<<endl;
}

void MainWindow::on_pushButton_2_clicked()
{
    string std_name1 = this->file1_name.toStdString();
    string std_name2 = this->file2_name.toStdString();
    this->p.update_result(std_name1, std_name2, false);
    update_judge_state();
    cout<<"inequal"<<endl;
}

void MainWindow::on_pushButton_3_clicked()
{
    string std_name1 = this->file1_name.toStdString();
    string std_name2 = this->file2_name.toStdString();
    this->p.reserve_doubt(std_name1, std_name2);
    update_judge_state();
    cout<<"doubt"<<endl;
}

