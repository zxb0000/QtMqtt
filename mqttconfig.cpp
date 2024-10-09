#include "mqttconfig.h"

#include <QJsonDocument>
#include <QString>

// 定义静态成员变量
QJsonObject MqttConfig::header;
QJsonObject MqttConfig::config;

void MqttConfig::printConfig()
{
    qDebug()<<"header:"<<QString(QJsonDocument(header).toJson())<<Qt::endl;
    qDebug()<<config<<Qt::endl;
}
