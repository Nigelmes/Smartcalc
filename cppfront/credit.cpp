#include "credit.h"
#include "ui_credit.h"

Credit::Credit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
}

Credit::~Credit()
{
    delete ui;
}

void Credit::on_pushButton_clicked() {

    double summa, itog, pereplata, monthly , percent;
    int srok ;

    summa=ui->sumcredit->text().toDouble();
    srok=ui->srokcredit->text().toInt();
    percent=ui->percentcredit->text().toDouble();


    if (ui->annuit->isChecked()) {

        percent = percent / 1200;
        monthly = summa * (percent*pow((1+percent),srok)/(pow((1+percent), srok)-1));
        itog = monthly*srok;
        pereplata = itog - summa;

        QString qsum = QString::number(itog);
        QString qmonth = QString::number(monthly);
        QString qover = QString::number(pereplata);

        ui->label_7->setText(qsum);
        ui->label_6->setText(qover);
        ui->textBrowser->setText("Ежемесячный платеж - "+qmonth +" рублей");
    } else if (ui->differen->isChecked()) {
        itog = 0;
        int debt_sum = summa / srok;
        for (int i = 1; i <= srok; i++) {
            monthly = (summa * percent / 100 * 31/365) + debt_sum;
            QString qmonth = QString::number(monthly);
            QString qi = QString::number(i);
            ui->textBrowser->setText(ui->textBrowser->toPlainText() + qi+"-й месяц: "+ qmonth + "руб." + '\n');
            summa -= debt_sum;
            itog += monthly;
        }
        pereplata = itog - debt_sum * srok;
        QString qsum = QString::number(itog, 'g', 10);
        QString qover = QString::number(pereplata, 'g', 10);
        ui->label_7->setText(qsum);
        ui->label_6->setText(qover);
    }
}
