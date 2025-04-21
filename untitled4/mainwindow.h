#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "smt.h"
#include "smt2.h"
#include "smt3.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_first_clicked();

    void on_pushButton_second_clicked();

    void on_pushButton_third_clicked();

private:
    Ui::MainWindow *ui;

    smt *secondWindow;
    smt2 *thirdWindow;
    smt3 *fourthWindow;
};
#endif // MAINWINDOW_H
