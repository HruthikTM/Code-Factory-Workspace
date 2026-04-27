#include "TempSensorMonitor.h"

TempSensorMonitor::TempSensorMonitor(QObject *parent) : QObject(parent), m_temperature(0.0f)
{

}

void TempSensorMonitor::setTemperature(float temperature)
{
    m_temperature = temperature;

    if(m_temperature > 50.0f)
        emit fireOccured(m_temperature);
}
