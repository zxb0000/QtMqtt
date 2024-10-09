#ifndef MQTTCONFIG_H
#define MQTTCONFIG_H
#include <QJsonObject>
#include<QList>
/**
 * @brief The MqttConfig class mqtt配置的静态类
 */
class MqttConfig
{
private:
    // 私有化构造函数，防止创建实例
    MqttConfig() {}

public:
    // 禁止拷贝和赋值
    MqttConfig(const MqttConfig&) = delete;
    MqttConfig& operator=(const MqttConfig&) = delete;
    static QJsonObject header;
    static QJsonObject config;
    static void printConfig();

};

#endif // MQTTCONFIG_H
