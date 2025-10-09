#ifndef WHEEL_H
#define WHEEL_H

#include <iostream>
#include <string>
#include "DiscBreak.h"
#include "TubeTyer.h"

using namespace std;


class Wheel
{
public:
    void setWheelRadius(float wheelRadius);
    float getWheelRadius();

    void move();

    void turn();

    void insertTyer();
    void removeTyer();


private:
    float m_wheelRadius;

    TubeTyer m_myTyer;
};

#endif // WHEEL_H
