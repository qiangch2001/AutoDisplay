#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateRedPanel();
    updateGreenPanel();
    updateBluePanel();

    // Default UI page
    ui->stackedWidget->setCurrentWidget(ui->page_display);

    // Setup a timer to periodically listen to Page Switching signal
    sensorTimer = new QTimer(this);

    // Mannually connect timercallback to the action: readSensorValue()
    connect(sensorTimer, &QTimer::timeout, this, [this]() {

        int v = readSensorValue();

        if (v != lastSensorValue) {

            // 0 -> 1：pressed but not released
            if (lastSensorValue == 0 && v == 1) {
                pressed = true;
            }

            // 1 -> 0：released
            else if (lastSensorValue == 1 && v == 0) {

                if (pressed) {
                    togglePage();
                    pressed = false; //reset status
                }
            }

            lastSensorValue = v;
        }

        int ambientRaw = readAmbientLightValue();
        updateDisplayBrightness(ambientRaw);

    });

    sensorTimer->start(200); //Callback every 200ms
}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::readSensorValue()
{
    // Check signal value
    QFile f("/sys/class/gpio/gpio20/value");

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

// Switch page
void MainWindow::togglePage()
{
    if (ui->stackedWidget->currentWidget() == ui->page_config) {
        ui->stackedWidget->setCurrentWidget(ui->page_display);
    } else {
        ui->stackedWidget->setCurrentWidget(ui->page_config);
    }
}

// Fetch BH1750's raw data
int MainWindow::readAmbientLightValue()
{
    const char *dev = "/dev/i2c-2";

    int addr = 0x23;
    unsigned char cmd = 0x20;

    // Add "::" to avoid using Qt's open funtion, same for close()
    int fd = ::open(dev, O_RDWR);
    // Set I2C slave address
    ioctl(fd, I2C_SLAVE, addr);
    // Send measurement command （continuously H-resolution mode）
    ::write(fd, &cmd, 1);

    // Wait for measurement to complete
    usleep(150000);

    // Read 2 bytes of data
    unsigned char buf[2] = {0, 0};
    ::read(fd, buf, 2);
    ::close(fd);

    // Shift and combine bytes
    int raw = (buf[0] << 8) | buf[1];

    return raw;
}

void MainWindow::updateDisplayBrightness(int raw)
{
    // Clamp raw value to [50, 550], by testing , normal dayight is around 500
    if (raw < 50) raw = 50;
    if (raw > 550) raw = 550;
    // Map raw value [50, 550] to alpha [255, 0] and invert
    int alpha =255 - raw * 255 / 550;

    // Adjust only when on display page
    if (ui->stackedWidget->currentWidget() != ui->page_display) {
        return;
    }

    // black -> white
    QString style = QString("background-color: rgba(0, 0, 0, %1);")
                        .arg(alpha);

    ui->overlay->setStyleSheet(style);

}


void MainWindow::updateRedPanel()
{
    // set threshold for the brightness value
    if (R < 0) R = 0;
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
    if (G < 0) G = 0;
    if (G > 255) G = 255;

    QString style =
        QString("background-color: rgba(0, 255, 0, %1);").arg(G);
    ui->widget_g->setStyleSheet(style);
    ui->brightness_g->setText(QString::number(G));
}

void MainWindow::updateBluePanel()
{
    if (B < 0) B = 0;
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

