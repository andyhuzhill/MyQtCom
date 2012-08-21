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
    //函数功能：点击“打开串口”按钮调用此函数，打开或关闭串口
    void on_openPort_clicked();
    //函数功能：当串口名称改变时，改变打开的串口
    void on_port_currentIndexChanged();
    //函数功能：当波特率列表框改变时，改变波特率
    void on_baud_currentIndexChanged(int index);
    //函数功能：当数据位列表框改变时，改变数据位
    void on_dataBits_currentIndexChanged(int index);
    //函数功能：当停止位列表框改变时，改变停止位
    void on_stopBits_currentIndexChanged(int index);
    //函数功能：当校验位列表框改变时，改变校验位
    void on_verifyBit_currentIndexChanged(int index);
    //函数功能：当定时器溢出时，调用此函数，查询串口内容，并打印串口内容到文本接收区
    void timer_out();
    //函数功能：点击“发送”按钮，将发送文本框内容发送到串口
    void on_sendBtn_clicked();

private:
    Ui::MainWindow *ui;
    QextSerialPort *myPort;  //声明一个串口对象
    QTimer *timer;          //声明一个定时器

};

#endif // MAINWINDOW_H
