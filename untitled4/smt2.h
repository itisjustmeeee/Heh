#ifndef SMT2_H
#define SMT2_H

#include <QDialog>

namespace Ui {
class smt2;
}

class smt2 : public QDialog
{
    Q_OBJECT

public:
    explicit smt2(QWidget *parent = nullptr);
    ~smt2();

signals:
    void firstWindow();

private slots:
    void on_pushButton_smt2_clicked();

private:
    Ui::smt2 *ui;
};

#endif // SMT2_H
