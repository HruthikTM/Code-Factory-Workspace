#include "FireManager.h"

FireManager::FireManager(QObject *parent) : QObject(parent)
{
}

void FireManager::turnOffFire(float temperature)
{
    qDebug() << " Fire detected at" << temperature ;
    qDebug() << "Activating valve shutdown";
    qDebug() << "Hi..........helll0";

    m_valveManager.turnOff();
}
