#include "SteelWheel.h"

SteelWheel::SteelWheel()
{
    cout << "Steel wheel obj is created" << endl;
}

SteelWheel::~SteelWheel()
{
    cout << "Steel wheel obj is created" << endl;
}

void SteelWheel :: setWheelPrice(float price)
{
    m_price = price;
}

float SteelWheel :: getWheelPrice()
{
    return m_price;
}

