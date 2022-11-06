#include "mainwindow.h"

#include <QApplication>

#include "s21_smartcalc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    double result = start_calc();
    printf("%lf", result);
    return a.exec();
}
