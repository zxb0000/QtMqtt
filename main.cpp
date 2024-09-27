#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("MyMQTT");
    w.setWindowIcon(QIcon(":/windIcon.jpg"));
    w.show();
    return a.exec();
}
