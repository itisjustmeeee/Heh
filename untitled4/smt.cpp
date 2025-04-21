#include "smt.h"
#include "ui_smt.h"

smt::smt(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::smt)
{
    ui->setupUi(this);
}

smt::~smt()
{
    delete ui;
}

void smt::on_pushButton_smt1_clicked()
{
    this->close();
    emit firstWindow();
}

