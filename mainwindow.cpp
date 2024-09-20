#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client=new QMqttClient();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete client;
}
