#ifndef DRUMBREAK_H
#define DRUMBREAK_H

#include <iostream>
#include <string>
#include "Break.h"

using namespace std;


class DrumBreak : public Break
{
public:
    DrumBreak();

    ~DrumBreak();

    void setBrakePrice(float price);
    float getBrakePrice();

    void mechanicalBrakeing();

private:
    float m_price;
};
#endif // DRUMBREAK_H
