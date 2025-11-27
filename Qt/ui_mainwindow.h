/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *Widget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_r;
    QPushButton *RedButton_up;
    QPushButton *RedButton_down;
    QLabel *brightness_r;
    QWidget *widget_g;
    QPushButton *GreenButton_up;
    QPushButton *GreenButton_down;
    QLabel *brightness_g;
    QWidget *widget_b;
    QPushButton *BlueButton_up;
    QPushButton *BlueButton_down;
    QLabel *brightness_b;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 272);
        Widget = new QWidget(MainWindow);
        Widget->setObjectName(QString::fromUtf8("Widget"));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 481, 271));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_r = new QWidget(layoutWidget);
        widget_r->setObjectName(QString::fromUtf8("widget_r"));
        widget_r->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
"        spread:pad,\n"
"        x1:0, y1:0,\n"
"        x2:1, y2:0,\n"
"        stop:0 rgba(0, 0, 0, 0),\n"
"        stop:1 rgba(255, 0, 0, 255));\n"
"\n"
""));
        RedButton_up = new QPushButton(widget_r);
        RedButton_up->setObjectName(QString::fromUtf8("RedButton_up"));
        RedButton_up->setGeometry(QRect(40, 40, 71, 51));
        RedButton_up->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        RedButton_up->setIcon(icon);
        RedButton_down = new QPushButton(widget_r);
        RedButton_down->setObjectName(QString::fromUtf8("RedButton_down"));
        RedButton_down->setGeometry(QRect(40, 180, 71, 51));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        RedButton_down->setIcon(icon1);
        brightness_r = new QLabel(widget_r);
        brightness_r->setObjectName(QString::fromUtf8("brightness_r"));
        brightness_r->setGeometry(QRect(35, 120, 81, 31));
        brightness_r->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));

        horizontalLayout->addWidget(widget_r);

        widget_g = new QWidget(layoutWidget);
        widget_g->setObjectName(QString::fromUtf8("widget_g"));
        widget_g->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
"        spread:pad,\n"
"        x1:0, y1:0,\n"
"        x2:1, y2:0,\n"
"        stop:0 rgba(0, 0, 0, 0),\n"
"        stop:1 rgba(0, 255, 0, 255));"));
        GreenButton_up = new QPushButton(widget_g);
        GreenButton_up->setObjectName(QString::fromUtf8("GreenButton_up"));
        GreenButton_up->setGeometry(QRect(40, 40, 71, 51));
        GreenButton_up->setAutoFillBackground(false);
        GreenButton_up->setIcon(icon);
        GreenButton_down = new QPushButton(widget_g);
        GreenButton_down->setObjectName(QString::fromUtf8("GreenButton_down"));
        GreenButton_down->setGeometry(QRect(40, 180, 71, 51));
        GreenButton_down->setIcon(icon1);
        brightness_g = new QLabel(widget_g);
        brightness_g->setObjectName(QString::fromUtf8("brightness_g"));
        brightness_g->setGeometry(QRect(35, 120, 81, 31));
        brightness_g->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));

        horizontalLayout->addWidget(widget_g);

        widget_b = new QWidget(layoutWidget);
        widget_b->setObjectName(QString::fromUtf8("widget_b"));
        widget_b->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
"        spread:pad,\n"
"        x1:0, y1:0,\n"
"        x2:1, y2:0,\n"
"        stop:0 rgba(0, 0, 0, 0),\n"
"        stop:1 rgba(0, 0, 255, 255));"));
        BlueButton_up = new QPushButton(widget_b);
        BlueButton_up->setObjectName(QString::fromUtf8("BlueButton_up"));
        BlueButton_up->setGeometry(QRect(40, 40, 71, 51));
        BlueButton_up->setAutoFillBackground(false);
        BlueButton_up->setIcon(icon);
        BlueButton_down = new QPushButton(widget_b);
        BlueButton_down->setObjectName(QString::fromUtf8("BlueButton_down"));
        BlueButton_down->setGeometry(QRect(40, 180, 71, 51));
        BlueButton_down->setIcon(icon1);
        brightness_b = new QLabel(widget_b);
        brightness_b->setObjectName(QString::fromUtf8("brightness_b"));
        brightness_b->setGeometry(QRect(35, 120, 81, 31));
        brightness_b->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));

        horizontalLayout->addWidget(widget_b);

        MainWindow->setCentralWidget(Widget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        RedButton_up->setText(QString());
        RedButton_down->setText(QString());
        brightness_r->setText(QString());
        GreenButton_up->setText(QString());
        GreenButton_down->setText(QString());
        brightness_g->setText(QString());
        BlueButton_up->setText(QString());
        BlueButton_down->setText(QString());
        brightness_b->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
