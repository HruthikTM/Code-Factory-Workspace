#ifndef ALLOYWHEEL_H
#define ALLOYWHEEL_H

#include "Wheel.h"
#include <iostream>
#include <string>

using namespace std;

class AlloyWheel : public Wheel
{
public:
    AlloyWheel();

    ~ AlloyWheel();

    void setWheelPrice(float price);
    float getWheelPrice();


private:
    float m_price;

    DiscBreak myBreak;
};

#endif // ALLOYWHEEL_H
