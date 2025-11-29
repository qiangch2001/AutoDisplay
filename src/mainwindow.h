#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QFile>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_RedButton_up_clicked();

    void on_RedButton_down_clicked();

    void on_GreenButton_up_clicked();

    void on_GreenButton_down_clicked();

    void on_BlueButton_up_clicked();

    void on_BlueButton_down_clicked();


private:
    Ui::MainWindow *ui;

    QTimer * sensorTimer;
    int R = 127; // Default Red
    int G = 127; // Default Green
    int B = 127; // Default Blue
    int lastSensorValue = -1; // Sensor status indicator

    int readSensorValue();
    void handleSensorValue(int v); // UI Page manager
    void updateRedPanel(); // Update brightness value R
    void updateGreenPanel(); // Update brightness value G
    void updateBluePanel(); // Update brightness value B
};
#endif // MAINWINDOW_H
