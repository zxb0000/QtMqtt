#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client=new QMqttClient();
    // 设置正则表达式验证器
    QRegularExpression regex("^[0-9]{5}$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, ui->port);
    ui->port->setValidator(validator);
    connect(client,&QMqttClient::messageReceived,this,&MainWindow::onReceiveMmessage);
    connect(client,&QMqttClient::stateChanged,this,&MainWindow::onStateChange);
    connect(client,&QMqttClient::connected,this,&MainWindow::onConnected);
    connect(client,&QMqttClient::disconnected,this,&::MainWindow::onDisconnected);
    ui->statusbar->showMessage("状态：未连接");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete client;
}

void MainWindow::onReceiveMmessage(const QByteArray &message, const QMqttTopicName &topic)
{
    QString msg=topic.name()+":\n"+message;
    ui->text1->appendPlainText(msg);
}


void MainWindow::onStateChange(QMqttClient::ClientState s)
{
    QString msg="";
    switch (s){
    case QMqttClient::ClientState::Disconnected:
        msg="已断开";
        break;
    case QMqttClient::ClientState::Connecting:
        msg="连接中";
        break;
    case QMqttClient::ClientState::Connected:
        msg="已连接";
        break;

    }
    ui->statusbar->showMessage("状态："+msg);
}

void MainWindow::onConnected()
{
    ui->text1->appendPlainText("连接成功！");
}


void MainWindow::on_pushButton_clicked()
{
    QString s=ui->lineEdit_9->text();
    client->setWillTopic(s);
    ui->text1->appendPlainText("订阅主题："+s);
}

void MainWindow::onDisconnected()
{
    ui->text1->appendPlainText("连接已断开！");
    ui->pushButton_2->setText("连接");
    ui->pushButton_2->setChecked(false);
}


void MainWindow::on_pushButton_2_clicked(bool checked)
{
    if(checked){
        client->setClientId("test0001");
        client->setAutoKeepAlive(true);
        client->setHostname(ui->host->text());
        client->setPort(ui->port->text().toUInt());
        client->setPassword(ui->password->text());
        client->setUsername(ui->username->text());
        client->setWillQoS(2);
        client->setWillTopic(ui->lineEdit_9->text());
        client->connectToHost();
        client->c
        ui->text1->appendPlainText("正在连接到："+ui->host->text());
        ui->pushButton_2->setText("断开");

    }else{
        client->setState(QMqttClient::ClientState::Disconnected);
        client->setState(QMqttClient::Disconnected);
        ui->pushButton_2->setText("连接");
    }
}

