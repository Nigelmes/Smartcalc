#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->push_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->push_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->push_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->push_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->push_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->push_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->push_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->push_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->push_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->push_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->push_AC,SIGNAL(clicked()),this,SLOT(AC_button()));
    connect(ui->push_ravno,SIGNAL(clicked()),this,SLOT(equals_button()));
    connect(ui->push_cos,SIGNAL(clicked()),this,SLOT(func_button()));
    connect(ui->push_sin,SIGNAL(clicked()),this,SLOT(func_button()));
    connect(ui->push_tan,SIGNAL(clicked()),this,SLOT(func_button()));
    connect(ui->push_acos,SIGNAL(clicked()),this,SLOT(func_button()));
    connect(ui->push_asin,SIGNAL(clicked()),this,SLOT(func_button()));
    connect(ui->push_atan,SIGNAL(clicked()),this,SLOT(func_button()));
    connect(ui->push_plus,SIGNAL(clicked()),this,SLOT(func_button()));
    connect(ui->push_minus,SIGNAL(clicked()),this,SLOT(func_button()));
    connect(ui->push_mult,SIGNAL(clicked()),this,SLOT(func_button()));
    connect(ui->push_div,SIGNAL(clicked()),this,SLOT(func_button()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers() {
    QPushButton *button = (QPushButton *)sender();

    QString new_lable;
    if(ui->result->text() == "0") {

        ui->result->setText(button->text());

    } else {

        new_lable = ui->result->text() + button->text();

        ui->result->setText(new_lable);
    }
}

void MainWindow::AC_button() {

    QString new_lable = "0";

    ui->result->setText(new_lable);

}

void MainWindow::equals_button() {

    QByteArray ba = (ui->result->text()).toLocal8Bit();

    const char *c_str2 = ba.data();

    double res = calc(c_str2);

    QString new_lable;

    new_lable = QString::number(res, 'g', 15);

    ui->result->setText(new_lable);

}

void MainWindow::func_button() {

    QPushButton *button = (QPushButton *)sender();

    QString new_lable;
    if(ui->result->text() == "0") {

        ui->result->setText(button->text());
        ui->result_code->setText(button->whatsThis());

    } else {

        new_lable = ui->result->text() + button->text();

        ui->result->setText(new_lable);
    }

}
