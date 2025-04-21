/********************************************************************************
** Form generated from reading UI file 'smt.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMT_H
#define UI_SMT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_smt
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QPushButton *pushButton_smt1;

    void setupUi(QDialog *smt)
    {
        if (smt->objectName().isEmpty())
            smt->setObjectName("smt");
        smt->resize(700, 600);
        verticalLayout = new QVBoxLayout(smt);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(smt);
        scrollArea->setObjectName("scrollArea");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 663, 1506));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 1488));
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

        pushButton_smt1 = new QPushButton(smt);
        pushButton_smt1->setObjectName("pushButton_smt1");

        verticalLayout->addWidget(pushButton_smt1);


        retranslateUi(smt);

        QMetaObject::connectSlotsByName(smt);
    } // setupUi

    void retranslateUi(QDialog *smt)
    {
        smt->setWindowTitle(QCoreApplication::translate("smt", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("smt", "\320\271\320\276\321\203 \320\272\321\203", nullptr));
        pushButton_smt1->setText(QCoreApplication::translate("smt", "\320\275\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class smt: public Ui_smt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMT_H
