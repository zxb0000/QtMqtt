#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtMqtt/QMqttClient>
#include<QFileDialog>
#include<QFile>
#include<QMessageBox>
#include<QJsonDocument>
#include<QJsonObject>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void onReceiveMmessage(const QByteArray &message, const QMqttTopicName &topic );
private slots:
    void onStateChange(QMqttClient::ClientState s);
    void onConnected();
    void on_pushButton_clicked();
    void onDisconnected();
    void on_pushButton_2_clicked(bool checked);

    void on_send_clicked();

    void on_action_triggered();

    void on_action_2_triggered();

private:
    Ui::MainWindow *ui;
    QMqttClient* client;

};
#endif // MAINWINDOW_H
