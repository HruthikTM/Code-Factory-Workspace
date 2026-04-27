#include "mainwindow.h"

#include <QApplication>
#include "TempSensorMonitor.h"
#include "FireManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TempSensorMonitor tem;
    FireManager fi;

    QObject::connect(&tem,&TempSensorMonitor::fireOccured,&fi,&FireManager::turnOffFire);

    tem.setTemperature(35.0f);
    tem.setTemperature(51.0f);


    return a.exec();
}
