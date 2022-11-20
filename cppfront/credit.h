#ifndef CREDIT_H
#define CREDIT_H

#include <QDialog>
#include <QValidator>

namespace Ui {
class Credit;
}

class Credit : public QDialog
{
    Q_OBJECT

public:
    explicit Credit(QWidget *parent = nullptr);
    ~Credit();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Credit *ui;
    double summa, itog, pereplata, monthly , percent;
    int srok, debt_sum;
};

#endif // CREDIT_H
