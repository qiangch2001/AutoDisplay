#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_RedButton_up_clicked()
{
    ui->brightness_r->setText("Red Up");
}


void MainWindow::on_RedButton_down_clicked()
{
    ui->brightness_r->setText("Red Down");
}


void MainWindow::on_GreenButton_up_clicked()
{
    ui->brightness_g->setText("Green Up");
}


void MainWindow::on_GreenButton_down_clicked()
{
    ui->brightness_g->setText("Green Down");
}


void MainWindow::on_BlueButton_up_clicked()
{
    ui->brightness_b->setText("Blue Up");
}


void MainWindow::on_BlueButton_down_clicked()
{
    ui->brightness_b->setText("Blue Down");
}

void MainWindow::setRgbValues(int r, int g, int b)
{
    ui->brightness_r->setText(QString::number(r));
    ui->brightness_g->setText(QString::number(g));
    ui->brightness_b->setText(QString::number(b));
}
