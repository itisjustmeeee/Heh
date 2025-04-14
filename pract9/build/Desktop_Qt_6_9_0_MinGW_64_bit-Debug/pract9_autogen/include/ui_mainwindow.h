/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton_registration;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_name_text;
    QLabel *label_FIO_text;
    QLabel *label_gender_text;
    QLabel *label_passport_text;
    QLabel *label_dateofbirth_text;
    QLabel *label_phonenumber_text;
    QLabel *label_e_mail_text;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_passport_value;
    QLineEdit *lineEdit_dateofbirth_value;
    QLineEdit *lineEdit_phonenumber_value;
    QLineEdit *lineEdit_e_mail_value;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_name_value;
    QLineEdit *lineEdit_FIO_value;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_female;
    QRadioButton *radioButton_male;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_import;
    QPushButton *pushButton_export;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(924, 589);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(430, 60, 141, 20));
        pushButton_registration = new QPushButton(centralwidget);
        pushButton_registration->setObjectName("pushButton_registration");
        pushButton_registration->setGeometry(QRect(380, 380, 211, 29));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(240, 130, 130, 241));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_name_text = new QLabel(layoutWidget);
        label_name_text->setObjectName("label_name_text");

        verticalLayout->addWidget(label_name_text);

        label_FIO_text = new QLabel(layoutWidget);
        label_FIO_text->setObjectName("label_FIO_text");

        verticalLayout->addWidget(label_FIO_text);

        label_gender_text = new QLabel(layoutWidget);
        label_gender_text->setObjectName("label_gender_text");

        verticalLayout->addWidget(label_gender_text);

        label_passport_text = new QLabel(layoutWidget);
        label_passport_text->setObjectName("label_passport_text");

        verticalLayout->addWidget(label_passport_text);

        label_dateofbirth_text = new QLabel(layoutWidget);
        label_dateofbirth_text->setObjectName("label_dateofbirth_text");

        verticalLayout->addWidget(label_dateofbirth_text);

        label_phonenumber_text = new QLabel(layoutWidget);
        label_phonenumber_text->setObjectName("label_phonenumber_text");

        verticalLayout->addWidget(label_phonenumber_text);

        label_e_mail_text = new QLabel(layoutWidget);
        label_e_mail_text->setObjectName("label_e_mail_text");

        verticalLayout->addWidget(label_e_mail_text);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(380, 230, 381, 141));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_passport_value = new QLineEdit(widget);
        lineEdit_passport_value->setObjectName("lineEdit_passport_value");

        verticalLayout_2->addWidget(lineEdit_passport_value);

        lineEdit_dateofbirth_value = new QLineEdit(widget);
        lineEdit_dateofbirth_value->setObjectName("lineEdit_dateofbirth_value");

        verticalLayout_2->addWidget(lineEdit_dateofbirth_value);

        lineEdit_phonenumber_value = new QLineEdit(widget);
        lineEdit_phonenumber_value->setObjectName("lineEdit_phonenumber_value");

        verticalLayout_2->addWidget(lineEdit_phonenumber_value);

        lineEdit_e_mail_value = new QLineEdit(widget);
        lineEdit_e_mail_value->setObjectName("lineEdit_e_mail_value");

        verticalLayout_2->addWidget(lineEdit_e_mail_value);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(380, 130, 381, 65));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_name_value = new QLineEdit(widget1);
        lineEdit_name_value->setObjectName("lineEdit_name_value");

        verticalLayout_3->addWidget(lineEdit_name_value);

        lineEdit_FIO_value = new QLineEdit(widget1);
        lineEdit_FIO_value->setObjectName("lineEdit_FIO_value");

        verticalLayout_3->addWidget(lineEdit_FIO_value);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(380, 200, 381, 28));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_female = new QRadioButton(widget2);
        radioButton_female->setObjectName("radioButton_female");

        horizontalLayout->addWidget(radioButton_female);

        radioButton_male = new QRadioButton(widget2);
        radioButton_male->setObjectName("radioButton_male");

        horizontalLayout->addWidget(radioButton_male);

        widget3 = new QWidget(centralwidget);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(240, 90, 521, 31));
        horizontalLayout_2 = new QHBoxLayout(widget3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_import = new QPushButton(widget3);
        pushButton_import->setObjectName("pushButton_import");

        horizontalLayout_2->addWidget(pushButton_import);

        pushButton_export = new QPushButton(widget3);
        pushButton_export->setObjectName("pushButton_export");

        horizontalLayout_2->addWidget(pushButton_export);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 924, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270", nullptr));
        pushButton_registration->setText(QCoreApplication::translate("MainWindow", "\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_name_text->setText(QCoreApplication::translate("MainWindow", "\320\270\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_FIO_text->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        label_gender_text->setText(QCoreApplication::translate("MainWindow", "\320\277\320\276\320\273", nullptr));
        label_passport_text->setText(QCoreApplication::translate("MainWindow", "\320\277\320\260\321\201\320\277\320\276\321\200\321\202", nullptr));
        label_dateofbirth_text->setText(QCoreApplication::translate("MainWindow", "\320\264\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        label_phonenumber_text->setText(QCoreApplication::translate("MainWindow", "\320\275\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        label_e_mail_text->setText(QCoreApplication::translate("MainWindow", "e-mail", nullptr));
        radioButton_female->setText(QCoreApplication::translate("MainWindow", "\320\226\320\265\320\275\321\201\320\272\320\270\320\271", nullptr));
        radioButton_male->setText(QCoreApplication::translate("MainWindow", "\320\234\321\203\320\266\321\201\320\272\320\276\320\271", nullptr));
        pushButton_import->setText(QCoreApplication::translate("MainWindow", "\320\270\320\274\320\276\321\200\321\202", nullptr));
        pushButton_export->setText(QCoreApplication::translate("MainWindow", "\321\215\320\272\321\201\320\277\320\276\321\200\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
