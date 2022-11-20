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


    ui->srokcredit->setValidator(new QIntValidator);
    ui->sumcredit->setValidator(new QDoubleValidator);
    ui->percentcredit->setValidator(new QDoubleValidator);

//    QByteArray ba1 = (ui->srokcredit->text()).toLocal8Bit();
//    const char *str1 = ba1.data();

//    QByteArray ba2 = (ui->sumcredit->text()).toLocal8Bit();
//    const char *str2 = ba2.data();

//    QByteArray ba3 = (ui->srokcredit->text()).toLocal8Bit();
//    const char *str3 = ba3.data();

//        if (str1) {
//            srok=ui->srokcredit->text().toInt();
//        }

//        if (str2) {
//            summa=ui->sumcredit->text().toDouble();
//        }

//        if (str3) {
//            percent=ui->percentcredit->text().toDouble();
//        }

     srok=ui->srokcredit->text().toInt();
     summa=ui->sumcredit->text().toDouble();
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

        debt_sum = summa / srok;
        //ui->textBrowser->setText("");
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
