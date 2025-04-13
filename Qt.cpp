/*
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void validateInput();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_registration, &QPushButton::clicked, this, &MainWindow::validateInput);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::validateInput()
{
    bool Valid = true;
    QString ErrorMessage;

    QString name = ui->lineEdit_name_value->text().trimmed();
    QRegularExpression usernameRegex("^[A-Za-z0-9]{1,15}$");
    if (!usernameRegex.match(name).hasMatch()){
        ErrorMessage += "please enter correct usernsme\n ";
        Valid = false;
    }
    QString fio = ui->lineEdit_FIO_value->text().trimmed();
    QRegularExpression fioRegex("^([A-ZА-Я][a-zа-я]{0, 14})\\s([A-ZА-Я][a-zа-я]{0,14})\\s([A-ZА-Я][a-zа-я]{0, 14})$");
    if (!fioRegex.match(fio).hasMatch()){
        ErrorMessage += "please enter correct fio\n ";
        Valid = false;
    }
    QString gender;
    if (ui->radioButton_female->isChecked()){
        gender = "female ";
    }
    else if (ui->radioButton_male->isChecked()){
        gender = "male ";
    }
    else{
        ErrorMessage += "please choose your gender\n ";
        Valid = false;
    }
    QString passport = ui->lineEdit_passport_value->text().trimmed();
    QRegularExpression passportRegex("\\d{4}\\s\\d{6}$");
    if (!passportRegex.match(passport).hasMatch()){
        ErrorMessage += "please enter correct passport information\n ";
        Valid = false;
    }
    QString dateofbirth = ui->lineEdit_dateofbirth_value->text().trimmed();
    QRegularExpression dateofbirthRegex("^(0[1-9]|[12][0-9]|3[01])\\.(0[1-9]|1[0-2])\\.\\d{4}$");
    if (!dateofbirthRegex.match(dateofbirth).hasMatch()){
        ErrorMessage += "please enter correct data of birth\n ";
        Valid = false;
    }
    QString phonenumber = ui->lineEdit_phonenumber_value->text().trimmed();
    QRegularExpression phonenumberRegex("^\\+7-\\d{3}-\\d{3}-\\d{2}-\\d{2}$");
    if (!phonenumberRegex.match(phonenumber).hasMatch()){
        ErrorMessage += "please enter correct phone number\n ";
        Valid = false;
    }
    QString email = ui->lineEdit_e_mail_value->text().trimmed();
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]{1,16}@[a-zA-Z0_9.-]{1,16}\\.[a-zA-Z]{2,4}$");
    if (!emailRegex.match(email).hasMatch()){
        ErrorMessage += "please enter correct email\n ";
        Valid = false;
    }
    if (Valid){
        QMessageBox::information(this, "Congradulations, thanks for your registration", QString("your username: %1\nyour name: %2\nyour passport: %3\ndate of birth: %4\nphone number: %5\nyour E-mail: %6\n").arg(name).arg(fio).arg(passport).arg(dateofbirth).arg(phonenumber).arg(email));
        ui->lineEdit_name_value->clear();
        ui->lineEdit_FIO_value->clear();
        ui->lineEdit_passport_value->clear();
        ui->lineEdit_dateofbirth_value->clear();
        ui->lineEdit_phonenumber_value->clear();
        ui->lineEdit_e_mail_value->clear();
        ui->radioButton_female->setChecked(false);
        ui->radioButton_male->setChecked(false);
    }
    else{
        QMessageBox::warning(this, "Error", ErrorMessage);
    }
}
