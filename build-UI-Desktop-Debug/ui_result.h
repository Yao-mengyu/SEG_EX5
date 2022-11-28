/********************************************************************************
** Form generated from reading UI file 'result.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULT_H
#define UI_RESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_result
{
public:
    QAction *action;
    QAction *action_Ctrl_Q;
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QTableView *tableView;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *result)
    {
        if (result->objectName().isEmpty())
            result->setObjectName(QString::fromUtf8("result"));
        result->resize(841, 634);
        action = new QAction(result);
        action->setObjectName(QString::fromUtf8("action"));
        action_Ctrl_Q = new QAction(result);
        action_Ctrl_Q->setObjectName(QString::fromUtf8("action_Ctrl_Q"));
        centralwidget = new QWidget(result);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 841, 41));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 40, 841, 511));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(730, 560, 89, 25));
        result->setCentralWidget(centralwidget);
        menubar = new QMenuBar(result);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 841, 28));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        result->setMenuBar(menubar);
        statusbar = new QStatusBar(result);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        result->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_Ctrl_Q);

        retranslateUi(result);

        QMetaObject::connectSlotsByName(result);
    } // setupUi

    void retranslateUi(QMainWindow *result)
    {
        result->setWindowTitle(QApplication::translate("result", "MainWindow", nullptr));
        action->setText(QApplication::translate("result", "\344\277\235\345\255\230(Ctrl+S)", nullptr));
        action_Ctrl_Q->setText(QApplication::translate("result", "\351\200\200\345\207\272(Ctrl+Q)", nullptr));
        textBrowser->setHtml(QApplication::translate("result", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\267\262\347\273\217\345\256\214\346\210\220\345\210\244\346\226\255\357\274\214\344\273\245\344\270\213\344\270\272\347\255\211\344\273\267\347\250\213\345\272\217\346\226\207\344\273\266\345\257\271</p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("result", "\351\200\200\345\207\272", nullptr));
        menu->setTitle(QApplication::translate("result", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class result: public Ui_result {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULT_H
