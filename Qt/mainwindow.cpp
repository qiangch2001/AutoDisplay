#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateRedPanel();
    updateGreenPanel();
    updateBluePanel();

    // Default UI page
    ui->stackedWidget->setCurrentWidget(ui->page_config);

    // Setup a timer to periodically listen to Page Switching signal
    sensorTimer = new QTimer(this);

    // Mannually connect timercallback to the action: readSensorValue()
    connect(sensorTimer, &QTimer::timeout, this, [this]() {

        int v = readSensorValue();

        if (v != lastSensorValue) {
            lastSensorValue = v;
            handleSensorValue(v);
        }
    });


    /* Test for page switching function */
    // connect(sensorTimer, &QTimer::timeout, this, [this]() {
    //     static int fake = 0;
    //     fake = 1 - fake;
    //     handleSensorValue(fake);
    // });

    sensorTimer->start(100); //Callback every 100ms
}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::readSensorValue()
{
    // Check signal value
    QFile f("/sys/class/gpio/gpio60/value");

    if (!f.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open sensor file";
        return 0;
    }

    QByteArray data = f.readAll().trimmed();
    if (!data.isEmpty() && data[0] == '1')
        return 1;
    else
        return 0;
}


void MainWindow::handleSensorValue(int v)
{
    if (v == 1) {
        // Change to display page
        ui->stackedWidget->setCurrentWidget(ui->page_display);
    } else {
        // Change to config page
        ui->stackedWidget->setCurrentWidget(ui->page_config);
    }
}

void MainWindow::updateRedPanel()
{
    // set threshold for the brightness value
    if (R < 0)   R = 0;
    if (R > 255) R = 255;

    // set background color
    QString style =
        QString("background-color: rgba(255, 0, 0, %1);").arg(R);
    ui->widget_r->setStyleSheet(style);
    // set brightness value
    ui->brightness_r->setText(QString::number(R));
}

void MainWindow::updateGreenPanel()
{
    if (G < 0)   G = 0;
    if (G > 255) G = 255;

    QString style =
        QString("background-color: rgba(0, 255, 0, %1);").arg(G);
    ui->widget_g->setStyleSheet(style);
    ui->brightness_g->setText(QString::number(G));
}

void MainWindow::updateBluePanel()
{
    if (B < 0)   B = 0;
    if (B > 255) B = 255;

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

