#include "mainwindow.h"

#include <QApplication>

#include "s21_smartcalc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    double result = calc("-3.5556*@29-5+4*6+5.51*(+6/(2+5)*(+4+(-3^6)))-4*3/2");
    printf("%lf", result);
    return a.exec();
}
