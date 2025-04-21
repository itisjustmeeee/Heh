/********************************************************************************
** Form generated from reading UI file 'smt3.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMT3_H
#define UI_SMT3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_smt3
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QLabel *label;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_smt3;
    QPushButton *pushButton_clear_2;
    QPushButton *pushButton_process_2;

    void setupUi(QDialog *smt3)
    {
        if (smt3->objectName().isEmpty())
            smt3->setObjectName("smt3");
        smt3->resize(700, 600);
        verticalLayout = new QVBoxLayout(smt3);
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(smt3);
        textEdit->setObjectName("textEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMaximumSize(QSize(16777215, 16777215));
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setTabStopDistance(80.000000000000000);

        verticalLayout->addWidget(textEdit);

        label = new QLabel(smt3);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        scrollArea_2 = new QScrollArea(smt3);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 663, 1318));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget_2 = new QWidget(scrollAreaWidgetContents_2);
        widget_2->setObjectName("widget_2");
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(0, 1300));
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(true);

        verticalLayout_5->addWidget(label_2);


        verticalLayout_2->addWidget(widget_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_smt3 = new QPushButton(smt3);
        pushButton_smt3->setObjectName("pushButton_smt3");

        horizontalLayout->addWidget(pushButton_smt3);

        pushButton_clear_2 = new QPushButton(smt3);
        pushButton_clear_2->setObjectName("pushButton_clear_2");

        horizontalLayout->addWidget(pushButton_clear_2);

        pushButton_process_2 = new QPushButton(smt3);
        pushButton_process_2->setObjectName("pushButton_process_2");

        horizontalLayout->addWidget(pushButton_process_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(smt3);

        QMetaObject::connectSlotsByName(smt3);
    } // setupUi

    void retranslateUi(QDialog *smt3)
    {
        smt3->setWindowTitle(QCoreApplication::translate("smt3", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("smt3", "\320\262\320\262\320\276\320\264\320\270\321\202\320\265 \321\202\320\265\320\272\321\201\321\202 \321\201\320\262\320\265\321\200\321\205\321\203", nullptr));
        label_2->setText(QCoreApplication::translate("smt3", "\320\271\320\276\321\203", nullptr));
        pushButton_smt3->setText(QCoreApplication::translate("smt3", "\320\275\320\260\320\267\320\260\320\264", nullptr));
        pushButton_clear_2->setText(QCoreApplication::translate("smt3", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButton_process_2->setText(QCoreApplication::translate("smt3", "\320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class smt3: public Ui_smt3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMT3_H
