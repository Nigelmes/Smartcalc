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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers() {

    QPushButton *button = (QPushButton *)sender();

    double allnum;
    QString new_lable;
    allnum = (ui->result->text() + button->text()).toDouble();
    new_lable = QString::number(allnum, 'g', 15);

    ui->result->setText(new_lable);

}
