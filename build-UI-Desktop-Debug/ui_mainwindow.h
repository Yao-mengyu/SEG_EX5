/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *tips;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextBrowser *file1_name;
    QTextBrowser *file2_name;
    QTextBrowser *file1_text;
    QTextBrowser *file2_text;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1221, 665);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tips = new QTextBrowser(centralwidget);
        tips->setObjectName(QString::fromUtf8("tips"));
        tips->setGeometry(QRect(0, 0, 1221, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(370, 590, 89, 25));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(580, 590, 89, 25));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(770, 590, 191, 25));
        file1_name = new QTextBrowser(centralwidget);
        file1_name->setObjectName(QString::fromUtf8("file1_name"));
        file1_name->setGeometry(QRect(0, 40, 611, 41));
        file2_name = new QTextBrowser(centralwidget);
        file2_name->setObjectName(QString::fromUtf8("file2_name"));
        file2_name->setGeometry(QRect(610, 40, 611, 41));
        file1_text = new QTextBrowser(centralwidget);
        file1_text->setObjectName(QString::fromUtf8("file1_text"));
        file1_text->setGeometry(QRect(0, 80, 611, 491));
        file2_text = new QTextBrowser(centralwidget);
        file2_text->setObjectName(QString::fromUtf8("file2_text"));
        file2_text->setGeometry(QRect(610, 80, 611, 491));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1221, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        tips->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\257\267\344\273\224\347\273\206\345\257\271\344\270\213\345\210\227\347\250\213\345\272\217\346\226\207\344\273\266\346\230\257\345\220\246\347\255\211\344\273\267\350\277\233\350\241\214\345\210\244\346\226\255</p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\347\255\211\344\273\267", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\344\270\215\347\255\211\344\273\267", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\345\255\230\347\226\221\357\274\210\350\257\267\350\260\250\346\205\216\351\200\211\346\213\251\350\257\245\351\200\211\351\241\271\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
