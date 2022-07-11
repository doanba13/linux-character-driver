/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *input;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *from;
    QLabel *label_4;
    QComboBox *to;
    QPushButton *pushButton;
    QLabel *label_5;
    QLineEdit *ressult;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(493, 532);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 20, 371, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        input = new QLineEdit(centralwidget);
        input->setObjectName(QString::fromUtf8("input"));
        input->setGeometry(QRect(200, 120, 251, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 110, 131, 51));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 170, 131, 51));
        label_3->setFont(font1);
        from = new QComboBox(centralwidget);
        from->addItem(QString());
        from->addItem(QString());
        from->addItem(QString());
        from->setObjectName(QString::fromUtf8("from"));
        from->setGeometry(QRect(200, 180, 251, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 230, 131, 51));
        label_4->setFont(font1);
        to = new QComboBox(centralwidget);
        to->addItem(QString());
        to->addItem(QString());
        to->addItem(QString());
        to->setObjectName(QString::fromUtf8("to"));
        to->setGeometry(QRect(200, 240, 251, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 310, 251, 31));
        pushButton->setFont(font1);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 370, 131, 51));
        label_5->setFont(font1);
        ressult = new QLineEdit(centralwidget);
        ressult->setObjectName(QString::fromUtf8("ressult"));
        ressult->setGeometry(QRect(200, 380, 251, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(220, 470, 67, 17));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Umpush"));
        font2.setPointSize(9);
        font2.setItalic(true);
        label_6->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 493, 22));
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
        label->setText(QApplication::translate("MainWindow", "BASE CONVERTER", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Input number", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "From Base", nullptr));
        from->setItemText(0, QApplication::translate("MainWindow", "Binary", nullptr));
        from->setItemText(1, QApplication::translate("MainWindow", "Octal", nullptr));
        from->setItemText(2, QApplication::translate("MainWindow", "Heximal", nullptr));

        from->setCurrentText(QApplication::translate("MainWindow", "Binary", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "To Base", nullptr));
        to->setItemText(0, QApplication::translate("MainWindow", "Octal", nullptr));
        to->setItemText(1, QApplication::translate("MainWindow", "Heximal", nullptr));
        to->setItemText(2, QApplication::translate("MainWindow", "Binary", nullptr));

        to->setCurrentText(QApplication::translate("MainWindow", "Octal", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Convert", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Result", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "@group3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
