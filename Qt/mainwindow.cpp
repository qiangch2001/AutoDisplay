#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateRedPanel();
    updateGreenPanel();
    updateBluePanel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateRedPanel()
{
    // set threshold for the brightness value
    R = qBound(0, R, 255);

    // set background color
    QString style =
        QString("background-color: rgba(255, 0, 0, %1);").arg(R);
    ui->widget_r->setStyleSheet(style);
    // set brightness value
    ui->brightness_r->setText(QString::number(R));
}

void MainWindow::updateGreenPanel()
{
    G = qBound(G, 0, 255);

    QString style =
        QString("background-color: rgba(0, 255, 0, %1);").arg(G);
    ui->widget_g->setStyleSheet(style);
    ui->brightness_g->setText(QString::number(G));
}

void MainWindow::updateBluePanel()
{
    B = qBound(B, 0, 255);

    QString style =
        QString("background-color: rgba(0, 0, 255, %1);").arg(B);
    ui->widget_b->setStyleSheet(style);
    ui->brightness_b->setText(QString::number(B));
}

void MainWindow::on_RedButton_up_clicked()
{
    // brightness + 10
    R += 10;
    updateRedPanel();
}


void MainWindow::on_RedButton_down_clicked()
{
    // brightness - 10
    R -= 10;
    updateRedPanel();
}


void MainWindow::on_GreenButton_up_clicked()
{
    G += 10;
    updateGreenPanel();
}


void MainWindow::on_GreenButton_down_clicked()
{
    G -= 10;
    updateGreenPanel();
}


void MainWindow::on_BlueButton_up_clicked()
{
    B += 10;
    updateBluePanel();
}


void MainWindow::on_BlueButton_down_clicked()
{
    B -= 10;
    updateBluePanel();
}

