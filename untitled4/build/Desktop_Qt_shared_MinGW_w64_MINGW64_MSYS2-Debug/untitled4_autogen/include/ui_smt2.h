/********************************************************************************
** Form generated from reading UI file 'smt2.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMT2_H
#define UI_SMT2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_smt2
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_smt2;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_process;

    void setupUi(QDialog *smt2)
    {
        if (smt2->objectName().isEmpty())
            smt2->setObjectName("smt2");
        smt2->resize(700, 600);
        verticalLayout = new QVBoxLayout(smt2);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(smt2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 663, 1318));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 1300));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(widget);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);

        verticalLayout_3->addWidget(label);


        verticalLayout_2->addWidget(widget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_smt2 = new QPushButton(smt2);
        pushButton_smt2->setObjectName("pushButton_smt2");

        horizontalLayout->addWidget(pushButton_smt2);

        pushButton_clear = new QPushButton(smt2);
        pushButton_clear->setObjectName("pushButton_clear");

        horizontalLayout->addWidget(pushButton_clear);

        pushButton_process = new QPushButton(smt2);
        pushButton_process->setObjectName("pushButton_process");

        horizontalLayout->addWidget(pushButton_process);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(smt2);

        QMetaObject::connectSlotsByName(smt2);
    } // setupUi

    void retranslateUi(QDialog *smt2)
    {
        smt2->setWindowTitle(QCoreApplication::translate("smt2", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("smt2", "\320\271\320\276\321\203 \320\272\321\203", nullptr));
        pushButton_smt2->setText(QCoreApplication::translate("smt2", "\320\275\320\260\320\267\320\260\320\264", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("smt2", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButton_process->setText(QCoreApplication::translate("smt2", "\320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class smt2: public Ui_smt2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMT2_H
