#ifndef FIREMANAGER_H
#define FIREMANAGER_H

#include <QObject>
#include <QDebug>

#include "ValveManager.h"

class FireManager : public QObject
{
    Q_OBJECT

public:
    explicit FireManager(QObject *parent = nullptr);

public slots:
    void turnOffFire(float temperature);

private:
    ValveManager m_valveManager;


};

#endif // FIREMANAGER_H
