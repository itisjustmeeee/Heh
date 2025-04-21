/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
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
    QPushButton *pushButton_first;
    QLabel *label;
    QPushButton *pushButton_second;
    QPushButton *pushButton_third;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_first = new QPushButton(centralwidget);
        pushButton_first->setObjectName("pushButton_first");
        pushButton_first->setGeometry(QRect(170, 290, 75, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(360, 250, 49, 16));
        pushButton_second = new QPushButton(centralwidget);
        pushButton_second->setObjectName("pushButton_second");
        pushButton_second->setGeometry(QRect(300, 290, 75, 24));
        pushButton_third = new QPushButton(centralwidget);
        pushButton_third->setObjectName("pushButton_third");
        pushButton_third->setGeometry(QRect(420, 290, 75, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        pushButton_first->setText(QCoreApplication::translate("MainWindow", "\320\275\320\260 \320\277\320\265\321\200\320\262\320\276\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\275\320\260 \320\276\320\272\320\275\320\260", nullptr));
        pushButton_second->setText(QCoreApplication::translate("MainWindow", "\320\275\320\260 \320\262\321\202\320\276\321\200\320\276\320\265", nullptr));
        pushButton_third->setText(QCoreApplication::translate("MainWindow", "\320\275\320\260 \321\202\321\200\320\265\321\202\321\214\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
