#ifndef STEELWHEEL_H
#define STEELWHEEL_H


#include "Wheel.h"
#include <iostream>
#include <string>

using namespace std;

class SteelWheel : public Wheel
{
public:
    SteelWheel();

    ~ SteelWheel();

    void setWheelPrice(float price);

    float getWheelPrice();


private:
    float m_price;
};
#endif // STEELWHEEL_H
