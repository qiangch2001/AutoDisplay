#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    
    void setRgbValues(int r, int g, int b);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
