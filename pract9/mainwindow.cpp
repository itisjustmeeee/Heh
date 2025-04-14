#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

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
    }
    else{
        QMessageBox::warning(this, "Error", ErrorMessage);
    }
}

void MainWindow::on_pushButton_import_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "", "test (*.txt)");
    if (filename.isEmpty()){
        QMessageBox::critical(this, "Error", "you did not choose file");
        return;
    }
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this, "Error", "failed to open file");
        return;
    }
    QString username, fio, gender, passport, dateofbirth, phonenumber, email;
    QTextStream ts(&file);
    if (!ts.atEnd()) username = ts.readLine().trimmed();
    if (!ts.atEnd()) fio = ts.readLine().trimmed();
    if (!ts.atEnd()) gender = ts.readLine().trimmed();
    if (!ts.atEnd()) passport = ts.readLine().trimmed();
    if (!ts.atEnd()) dateofbirth = ts.readLine().trimmed();
    if (!ts.atEnd()) phonenumber = ts.readLine().trimmed();
    if (!ts.atEnd()) email = ts.readLine().trimmed();
    file.close();

    ui->lineEdit_name_value->setText(username);
    ui->lineEdit_FIO_value->setText(fio);
    ui->lineEdit_passport_value->setText(passport);
    ui->lineEdit_dateofbirth_value->setText(dateofbirth);
    ui->lineEdit_phonenumber_value->setText(phonenumber);
    ui->lineEdit_e_mail_value->setText(email);
    if (gender == "male"){
        ui->radioButton_male->setChecked(true);
    }
    else{
        ui->radioButton_female->setChecked(true);
    }
}


void MainWindow::on_pushButton_export_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save file", "", "text (*.txt)");
    if (filename.isEmpty()){
        QMessageBox::critical(this, "Error", "you did not choose file");
        return;
    }
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this, "Error", "failed to open file");
        return;
    }

    QTextStream ts(&file);
    ts << ui->lineEdit_name_value->text().trimmed() << "\n";
    ts << ui->lineEdit_FIO_value->text().trimmed() << "\n";
    if (ui->radioButton_male->isChecked()){
        ts << "male" << "\n";
    }
    else{
        ts << "female" << "\n";
    }
    ts << ui->lineEdit_passport_value->text().trimmed() << "\n";
    ts << ui->lineEdit_dateofbirth_value->text().trimmed() << "\n";
    ts << ui->lineEdit_phonenumber_value->text().trimmed() << "\n";
    ts << ui->lineEdit_e_mail_value->text().trimmed() << "\n";
    file.close();
}

