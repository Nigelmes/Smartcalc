#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

extern "C" {
   #include "s21_smartcalc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double xBegin, xEnd, h, X;
//    int N;
    QVector<double> x, y;

private slots:
    void digits_numbers();
    void AC_button();
    void func_button();
    void equals_button();
    void simp_math_button();
    void graf_button();
    void skobki();
    void x_button_push();
    void on_pushButton_clicked();
    void on_line_X_from_textChanged(); // const QString &arg1
    void on_line_X_selectionChanged();
    void on_line_X_cursorPositionChanged();
};
#endif // MAINWINDOW_H
