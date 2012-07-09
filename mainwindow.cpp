#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PortSettings settings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    myPort = new QextSerialPort(ui->port->currentText(), settings, QextSerialPort::Polling);


    ui->port->addItems(QStringList() << "/dev/ttyS0" << "/dev/ttyS1" << "/dev/ttyS2" << "/dev/ttyS3" << "/dev/ttyUSB0");
    ui->baud->addItem("115200", BAUD115200);
    ui->baud->addItem("19200", BAUD19200);
    ui->baud->addItem("9600", BAUD9600);
    ui->baud->addItem("4800", BAUD4800);
    ui->baud->addItem("2400", BAUD2400);
    ui->baud->addItem("1200", BAUD1200);
    ui->baud->addItem("600", BAUD600);
    ui->baud->addItem("300", BAUD300);
    ui->baud->setCurrentIndex(2);

    ui->dataBits->addItem("8", DATA_8);
    ui->dataBits->addItem("7", DATA_7);
    ui->dataBits->addItem("6", DATA_6);

    ui->verifyBit->addItem(tr("无校验"), PAR_NONE);
    ui->verifyBit->addItem(tr("奇校验"), PAR_ODD);
    ui->verifyBit->addItem(tr("偶校验"), PAR_EVEN);

    ui->stopBits->addItem("1", STOP_1);
    ui->stopBits->addItem("2", STOP_2);

    timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_out()));

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openPort_clicked()
{

    if(!myPort->isOpen())
    {
        if (!myPort->open(QIODevice::ReadWrite))
        {
            QMessageBox::warning(this, tr("警告"), tr("打开失败！"), QMessageBox::Ok);

        }
        myPort->setPortName(ui->port->currentText());
        timer->start();
        ui->openPort->setText(tr("关闭串口"));
    }
    else
    {
        myPort->close();
        ui->openPort->setText(tr("打开串口"));
        return ;
    }
}



void MainWindow::on_port_currentIndexChanged(int index)
{
    myPort->setPortName(ui->port->currentText());
}


void MainWindow::on_baud_currentIndexChanged(int index)
{
    myPort->setBaudRate((BaudRateType)ui->baud->itemData(index).toInt());
}


void MainWindow::on_dataBits_currentIndexChanged(int index)
{
    myPort->setDataBits((DataBitsType)ui->dataBits->itemData(index).toInt());
}



void MainWindow::on_stopBits_currentIndexChanged(int index)
{
    myPort->setStopBits((StopBitsType)ui->stopBits->itemData(index).toInt());
}

void MainWindow::on_verifyBit_currentIndexChanged(int index)
{
    myPort->setParity((ParityType)ui->verifyBit->itemData(index).toInt());
}


void MainWindow::timer_out()
{
    if (myPort->bytesAvailable())
    {
        ui->RxDisplay->insertPlainText(QString::fromLatin1(myPort->readAll()));
    }
}

void MainWindow::on_sendBtn_clicked()
{
    if (!ui->sendEdit->toPlainText().isEmpty() && myPort->isOpen())
    {
        myPort->write(ui->sendEdit->toPlainText().toLatin1());
    }
    else
    {
        QMessageBox::warning(this, tr("警告"), tr("发送文本框为空或串口未打开！"), QMessageBox::Yes);
    }
}
