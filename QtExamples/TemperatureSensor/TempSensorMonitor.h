#ifndef TEMPSENSORMONITOR_H
#define TEMPSENSORMONITOR_H

#include <QObject>

class TempSensorMonitor : public QObject
{
    Q_OBJECT

public:
    TempSensorMonitor(QObject *parent = nullptr);

    void setTemperature(float temperature);

    signals:
    void fireOccured(float temperature);

private:
    float m_temperature;
};

#endif // TEMPSENSORMONITOR_H
