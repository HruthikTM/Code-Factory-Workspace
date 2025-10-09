#include "Wheel.h"

void Wheel :: setWheelRadius(float wheelRadius)
{
    m_wheelRadius = wheelRadius;
}

float Wheel :: getWheelRadius()
{
    return m_wheelRadius;
}

void Wheel :: move()
{
    cout << "Wheel is moving " << endl;
}

void Wheel :: turn()
{
    cout << "Wheel turning" << endl;
}

void Wheel :: insertTyer()
{
    m_myTyer.setTyerBrand("MRF");
    m_myTyer.fillAir();

    cout << "Tyer inserted" << endl;
}

void Wheel :: removeTyer()
{
    cout << "Tyer removed" << endl;
}
