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
#include <QtWidgets/QGroupBox>
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
    QGroupBox *groupBox;
    QWidget *widget;
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
        Widget->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 480, 272));
        groupBox->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0);"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 481, 281));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_r = new QWidget(widget);
        widget_r->setObjectName(QString::fromUtf8("widget_r"));
        widget_r->setStyleSheet(QString::fromUtf8("background-color:rgba(255, 0, 0, 127);"));
        RedButton_up = new QPushButton(widget_r);
        RedButton_up->setObjectName(QString::fromUtf8("RedButton_up"));
        RedButton_up->setGeometry(QRect(40, 40, 71, 51));
        RedButton_up->setAutoFillBackground(false);
        RedButton_up->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
"    spread:pad,\n"
"    x1:0, y1:0,\n"
"    x2:0, y2:1,\n"
"    stop:0   rgba(255, 0,   0,   255),\n"
"    stop:0.5 rgba(0,   255, 0,   255),\n"
"    stop:1   rgba(0,   0,   255, 255)\n"
");\n"
"\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("button_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        RedButton_up->setIcon(icon);
        RedButton_down = new QPushButton(widget_r);
        RedButton_down->setObjectName(QString::fromUtf8("RedButton_down"));
        RedButton_down->setGeometry(QRect(40, 180, 71, 51));
        RedButton_down->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
"    spread:pad,\n"
"    x1:0, y1:0,\n"
"    x2:0, y2:1,\n"
"    stop:0   rgba(255, 0,   0,   255),\n"
"    stop:0.5 rgba(0,   255, 0,   255),\n"
"    stop:1   rgba(0,   0,   255, 255)\n"
");\n"
"\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("button_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        RedButton_down->setIcon(icon1);
        brightness_r = new QLabel(widget_r);
        brightness_r->setObjectName(QString::fromUtf8("brightness_r"));
        brightness_r->setGeometry(QRect(35, 120, 81, 31));
        brightness_r->setAutoFillBackground(false);
        brightness_r->setStyleSheet(QString::fromUtf8("font: 900 11pt \"Swis721 BlkCn BT\";\n"
"color: rgb(0, 255, 255);\n"
"background-color: transparent;\n"
""));
        brightness_r->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(widget_r);

        widget_g = new QWidget(widget);
        widget_g->setObjectName(QString::fromUtf8("widget_g"));
        widget_g->setStyleSheet(QString::fromUtf8("background: rgba(0, 255, 0,127)"));
        GreenButton_up = new QPushButton(widget_g);
        GreenButton_up->setObjectName(QString::fromUtf8("GreenButton_up"));
        GreenButton_up->setGeometry(QRect(40, 40, 71, 51));
        GreenButton_up->setAutoFillBackground(false);
        GreenButton_up->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
"    spread:pad,\n"
"    x1:0, y1:0,\n"
"    x2:0, y2:1,\n"
"    stop:0   rgba(255, 0,   0,   255),\n"
"    stop:0.5 rgba(0,   255, 0,   255),\n"
"    stop:1   rgba(0,   0,   255, 255)\n"
");\n"
"\n"
""));
        GreenButton_up->setIcon(icon);
        GreenButton_down = new QPushButton(widget_g);
        GreenButton_down->setObjectName(QString::fromUtf8("GreenButton_down"));
        GreenButton_down->setGeometry(QRect(40, 180, 71, 51));
        GreenButton_down->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
"    spread:pad,\n"
"    x1:0, y1:0,\n"
"    x2:0, y2:1,\n"
"    stop:0   rgba(255, 0,   0,   255),\n"
"    stop:0.5 rgba(0,   255, 0,   255),\n"
"    stop:1   rgba(0,   0,   255, 255)\n"
");\n"
""));
        GreenButton_down->setIcon(icon1);
        brightness_g = new QLabel(widget_g);
        brightness_g->setObjectName(QString::fromUtf8("brightness_g"));
        brightness_g->setGeometry(QRect(35, 120, 81, 31));
        brightness_g->setStyleSheet(QString::fromUtf8("font: 900 11pt \"Swis721 BlkCn BT\";\n"
"color:rgb(255, 0, 255);\n"
"background-color: transparent;"));
        brightness_g->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(widget_g);

        widget_b = new QWidget(widget);
        widget_b->setObjectName(QString::fromUtf8("widget_b"));
        widget_b->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 255, 127);"));
        BlueButton_up = new QPushButton(widget_b);
        BlueButton_up->setObjectName(QString::fromUtf8("BlueButton_up"));
        BlueButton_up->setGeometry(QRect(40, 40, 71, 51));
        BlueButton_up->setAutoFillBackground(false);
        BlueButton_up->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
"    spread:pad,\n"
"    x1:0, y1:0,\n"
"    x2:0, y2:1,\n"
"    stop:0   rgba(255, 0,   0,   255),\n"
"    stop:0.5 rgba(0,   255, 0,   255),\n"
"    stop:1   rgba(0,   0,   255, 255)\n"
");\n"
""));
        BlueButton_up->setIcon(icon);
        BlueButton_down = new QPushButton(widget_b);
        BlueButton_down->setObjectName(QString::fromUtf8("BlueButton_down"));
        BlueButton_down->setGeometry(QRect(40, 180, 71, 51));
        BlueButton_down->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
"    spread:pad,\n"
"    x1:0, y1:0,\n"
"    x2:0, y2:1,\n"
"    stop:0   rgba(255, 0,   0,   255),\n"
"    stop:0.5 rgba(0,   255, 0,   255),\n"
"    stop:1   rgba(0,   0,   255, 255)\n"
");\n"
""));
        BlueButton_down->setIcon(icon1);
        brightness_b = new QLabel(widget_b);
        brightness_b->setObjectName(QString::fromUtf8("brightness_b"));
        brightness_b->setGeometry(QRect(35, 120, 81, 31));
        brightness_b->setStyleSheet(QString::fromUtf8("font: 900 11pt \"Swis721 BlkCn BT\";\n"
"color: rgb(255, 255, 0);\n"
"background-color: transparent;"));
        brightness_b->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(widget_b);

        MainWindow->setCentralWidget(Widget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        RedButton_up->setText(QString());
        RedButton_down->setText(QString());
        brightness_r->setText(QCoreApplication::translate("MainWindow", "127", nullptr));
        GreenButton_up->setText(QString());
        GreenButton_down->setText(QString());
        brightness_g->setText(QCoreApplication::translate("MainWindow", "127", nullptr));
        BlueButton_up->setText(QString());
        BlueButton_down->setText(QString());
        brightness_b->setText(QCoreApplication::translate("MainWindow", "127", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
