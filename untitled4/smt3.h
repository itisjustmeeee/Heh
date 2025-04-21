#ifndef SMT3_H
#define SMT3_H

#include <QDialog>

namespace Ui {
class smt3;
}

class smt3 : public QDialog
{
    Q_OBJECT

public:
    explicit smt3(QWidget *parent = nullptr);
    ~smt3();

signals:
    void firstWindow();

private slots:
    void on_pushButton_smt3_clicked();

private:
    Ui::smt3 *ui;
};

#endif // SMT3_H
