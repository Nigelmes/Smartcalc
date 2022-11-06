#include "mainwindow.h"

#include <QApplication>

#include "smartcalc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    double result = simple_math(5.5, 6.6, '+');
    printf("%lf", result);
    return a.exec();
}
