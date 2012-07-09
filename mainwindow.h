#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include "src/qextserialport.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_openPort_clicked();

    void on_port_currentIndexChanged(int index);

    void on_baud_currentIndexChanged(int index);

    void on_dataBits_currentIndexChanged(int index);

    void on_stopBits_currentIndexChanged(int index);

    void on_verifyBit_currentIndexChanged(int index);

    void timer_out();

    void on_sendBtn_clicked();

private:
    Ui::MainWindow *ui;
    QextSerialPort *myPort;
    QTimer *timer;

};

#endif // MAINWINDOW_H
