#ifndef DISCBREAK_H
#define DISCBREAK_H

#include <iostream>
#include <string>
#include "Break.h"

using namespace std;


class DiscBreak : public Break
{
public:
    DiscBreak();

    ~DiscBreak();

    void setBrakePrice(float price);
    float getBrakePrice();

    void utilizeFriction();

private:
    float m_price;
};

#endif // DISCBREAK_H
