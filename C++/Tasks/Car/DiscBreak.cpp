#include "DiscBreak.h"

DiscBreak::DiscBreak()
{
    cout << "Disc break object created " << endl;
}

DiscBreak::~DiscBreak()
{
    cout << "Disc break object destroyed " << endl;
}

void DiscBreak :: setBrakePrice(float price)
{
    m_price = price;
}

float DiscBreak :: getBrakePrice()
{
    return m_price;
}

void DiscBreak :: utilizeFriction()
{
    cout << "Disc brake utilizing friction for breaking " << endl;
}


