#ifndef SMT_H
#define SMT_H

#include <QDialog>

namespace Ui {
class smt;
}

class smt : public QDialog
{
    Q_OBJECT

public:
    explicit smt(QWidget *parent = nullptr);
    ~smt();

signals:
    void firstWindow();

private slots:
    void on_pushButton_smt1_clicked();

private:
    Ui::smt *ui;
};

#endif // SMT_H
