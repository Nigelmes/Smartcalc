/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *result;
    QPushButton *push_sin;
    QPushButton *push_cos;
    QPushButton *push_asin;
    QPushButton *push_acos;
    QPushButton *push_plus;
    QPushButton *push_AC;
    QPushButton *push_leftscob;
    QPushButton *push_rightscob;
    QPushButton *push_mult;
    QPushButton *push_7;
    QPushButton *push_8;
    QPushButton *push_9;
    QPushButton *push_stepen;
    QPushButton *push_4;
    QPushButton *push_5;
    QPushButton *push_6;
    QPushButton *push_1;
    QPushButton *push_2;
    QPushButton *push_3;
    QPushButton *push_minus;
    QPushButton *push_tan;
    QPushButton *push_div;
    QPushButton *push_mod;
    QPushButton *push_dot;
    QPushButton *push_0;
    QPushButton *push_ravno;
    QPushButton *push_atan;
    QPushButton *push_sqrt;
    QPushButton *push_log;
    QPushButton *push_ln;
    QPushButton *push_X;
    QLabel *result_code;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(676, 491);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        result = new QLabel(centralwidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(0, 20, 671, 41));
        QFont font;
        font.setPointSize(20);
        result->setFont(font);
        result->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"background-color : white;"));
        result->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        push_sin = new QPushButton(centralwidget);
        push_sin->setObjectName(QString::fromUtf8("push_sin"));
        push_sin->setGeometry(QRect(10, 120, 60, 40));
        push_cos = new QPushButton(centralwidget);
        push_cos->setObjectName(QString::fromUtf8("push_cos"));
        push_cos->setGeometry(QRect(70, 120, 60, 40));
        push_asin = new QPushButton(centralwidget);
        push_asin->setObjectName(QString::fromUtf8("push_asin"));
        push_asin->setGeometry(QRect(130, 120, 60, 40));
        push_acos = new QPushButton(centralwidget);
        push_acos->setObjectName(QString::fromUtf8("push_acos"));
        push_acos->setGeometry(QRect(190, 120, 60, 40));
        push_plus = new QPushButton(centralwidget);
        push_plus->setObjectName(QString::fromUtf8("push_plus"));
        push_plus->setGeometry(QRect(190, 220, 60, 60));
        QFont font1;
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        push_plus->setFont(font1);
        push_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_AC = new QPushButton(centralwidget);
        push_AC->setObjectName(QString::fromUtf8("push_AC"));
        push_AC->setGeometry(QRect(10, 220, 60, 60));
        push_AC->setFont(font1);
        push_AC->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_AC->setCheckable(false);
        push_leftscob = new QPushButton(centralwidget);
        push_leftscob->setObjectName(QString::fromUtf8("push_leftscob"));
        push_leftscob->setGeometry(QRect(70, 220, 60, 60));
        push_leftscob->setFont(font1);
        push_leftscob->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_rightscob = new QPushButton(centralwidget);
        push_rightscob->setObjectName(QString::fromUtf8("push_rightscob"));
        push_rightscob->setGeometry(QRect(130, 220, 60, 60));
        push_rightscob->setFont(font1);
        push_rightscob->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_mult = new QPushButton(centralwidget);
        push_mult->setObjectName(QString::fromUtf8("push_mult"));
        push_mult->setGeometry(QRect(190, 280, 60, 60));
        push_mult->setFont(font1);
        push_mult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_7 = new QPushButton(centralwidget);
        push_7->setObjectName(QString::fromUtf8("push_7"));
        push_7->setGeometry(QRect(10, 280, 60, 60));
        push_8 = new QPushButton(centralwidget);
        push_8->setObjectName(QString::fromUtf8("push_8"));
        push_8->setGeometry(QRect(70, 280, 60, 60));
        push_9 = new QPushButton(centralwidget);
        push_9->setObjectName(QString::fromUtf8("push_9"));
        push_9->setGeometry(QRect(130, 280, 60, 60));
        push_stepen = new QPushButton(centralwidget);
        push_stepen->setObjectName(QString::fromUtf8("push_stepen"));
        push_stepen->setGeometry(QRect(190, 330, 60, 60));
        push_stepen->setFont(font1);
        push_stepen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_4 = new QPushButton(centralwidget);
        push_4->setObjectName(QString::fromUtf8("push_4"));
        push_4->setGeometry(QRect(10, 330, 60, 60));
        push_5 = new QPushButton(centralwidget);
        push_5->setObjectName(QString::fromUtf8("push_5"));
        push_5->setGeometry(QRect(70, 330, 60, 60));
        push_6 = new QPushButton(centralwidget);
        push_6->setObjectName(QString::fromUtf8("push_6"));
        push_6->setGeometry(QRect(130, 330, 60, 60));
        push_1 = new QPushButton(centralwidget);
        push_1->setObjectName(QString::fromUtf8("push_1"));
        push_1->setGeometry(QRect(10, 380, 60, 60));
        push_2 = new QPushButton(centralwidget);
        push_2->setObjectName(QString::fromUtf8("push_2"));
        push_2->setGeometry(QRect(70, 380, 60, 60));
        push_3 = new QPushButton(centralwidget);
        push_3->setObjectName(QString::fromUtf8("push_3"));
        push_3->setGeometry(QRect(130, 380, 60, 60));
        push_minus = new QPushButton(centralwidget);
        push_minus->setObjectName(QString::fromUtf8("push_minus"));
        push_minus->setGeometry(QRect(250, 220, 60, 60));
        push_minus->setFont(font1);
        push_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_tan = new QPushButton(centralwidget);
        push_tan->setObjectName(QString::fromUtf8("push_tan"));
        push_tan->setGeometry(QRect(250, 120, 60, 40));
        push_div = new QPushButton(centralwidget);
        push_div->setObjectName(QString::fromUtf8("push_div"));
        push_div->setGeometry(QRect(250, 280, 60, 60));
        push_div->setFont(font1);
        push_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_mod = new QPushButton(centralwidget);
        push_mod->setObjectName(QString::fromUtf8("push_mod"));
        push_mod->setGeometry(QRect(250, 330, 60, 60));
        push_mod->setFont(font1);
        push_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_dot = new QPushButton(centralwidget);
        push_dot->setObjectName(QString::fromUtf8("push_dot"));
        push_dot->setGeometry(QRect(130, 430, 60, 61));
        push_0 = new QPushButton(centralwidget);
        push_0->setObjectName(QString::fromUtf8("push_0"));
        push_0->setGeometry(QRect(10, 430, 121, 61));
        push_ravno = new QPushButton(centralwidget);
        push_ravno->setObjectName(QString::fromUtf8("push_ravno"));
        push_ravno->setGeometry(QRect(190, 380, 120, 111));
        push_ravno->setFont(font1);
        push_ravno->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_atan = new QPushButton(centralwidget);
        push_atan->setObjectName(QString::fromUtf8("push_atan"));
        push_atan->setGeometry(QRect(10, 150, 60, 40));
        push_sqrt = new QPushButton(centralwidget);
        push_sqrt->setObjectName(QString::fromUtf8("push_sqrt"));
        push_sqrt->setGeometry(QRect(190, 150, 60, 40));
        push_log = new QPushButton(centralwidget);
        push_log->setObjectName(QString::fromUtf8("push_log"));
        push_log->setGeometry(QRect(70, 150, 60, 40));
        push_ln = new QPushButton(centralwidget);
        push_ln->setObjectName(QString::fromUtf8("push_ln"));
        push_ln->setGeometry(QRect(130, 150, 60, 40));
        push_X = new QPushButton(centralwidget);
        push_X->setObjectName(QString::fromUtf8("push_X"));
        push_X->setGeometry(QRect(250, 150, 60, 40));
        result_code = new QLabel(centralwidget);
        result_code->setObjectName(QString::fromUtf8("result_code"));
        result_code->setEnabled(true);
        result_code->setGeometry(QRect(50, 70, 0, 0));
        result_code->setFont(font);
        result_code->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"background-color : white;"));
        result_code->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        result->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
#if QT_CONFIG(whatsthis)
        push_sin->setWhatsThis(QCoreApplication::translate("MainWindow", "A", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
#if QT_CONFIG(whatsthis)
        push_cos->setWhatsThis(QCoreApplication::translate("MainWindow", "@", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        push_cos->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        push_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        push_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        push_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        push_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        push_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        push_leftscob->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        push_rightscob->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        push_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        push_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        push_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        push_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        push_stepen->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        push_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        push_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        push_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        push_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        push_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        push_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        push_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        push_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        push_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        push_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        push_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        push_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        push_ravno->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        push_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        push_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        push_log->setText(QCoreApplication::translate("MainWindow", "log10", nullptr));
        push_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        push_X->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        result_code->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
