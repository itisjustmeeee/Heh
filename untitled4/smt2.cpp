#include "smt2.h"
#include "ui_smt2.h"

smt2::smt2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::smt2)
{
    ui->setupUi(this);
}

smt2::~smt2()
{
    delete ui;
}

void smt2::on_pushButton_smt2_clicked()
{
    this->close();
    emit firstWindow();
}

