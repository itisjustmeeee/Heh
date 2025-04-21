#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    secondWindow = new smt();
    connect(secondWindow, &smt::firstWindow, this, &MainWindow::show);
    thirdWindow = new smt2();
    connect(thirdWindow, &smt2::firstWindow, this, &MainWindow::show);
    fourthWindow = new smt3();
    connect(fourthWindow, &smt3::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_first_clicked()
{
    secondWindow->show();
    this->close();
}


void MainWindow::on_pushButton_second_clicked()
{
    thirdWindow->show();
    this->close();
}


void MainWindow::on_pushButton_third_clicked()
{
    fourthWindow->show();
    this->close();
}

