#include "AlloyWheel.h"

AlloyWheel::AlloyWheel()
{
    cout << "Alloy wheel obj is created" << endl;

    myBreak.slowDown();
    myBreak.utilizeFriction();
    myBreak.releaseBreak();
}

AlloyWheel::~AlloyWheel()
{
    cout << "Alloy wheel obj is created" << endl;
}

void AlloyWheel :: setWheelPrice(float price)
{
    m_price = price;
}

float AlloyWheel :: getWheelPrice()
{
    return m_price;
}


