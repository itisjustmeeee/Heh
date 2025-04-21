#include "smt3.h"
#include "ui_smt3.h"

smt3::smt3(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::smt3)
{
    ui->setupUi(this);
}

smt3::~smt3()
{
    delete ui;
}

void smt3::on_pushButton_smt3_clicked()
{
    this->close();
    emit firstWindow();
}

