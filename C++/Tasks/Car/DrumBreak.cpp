#include "DrumBreak.h"

DrumBreak::DrumBreak()
{
    cout << "DrumBreak object created " << endl;
}

DrumBreak::~DrumBreak()
{
    cout << "DrumBreak object destroyed " << endl;
}

void DrumBreak :: setBrakePrice(float price)
{
    m_price = price;
}

float DrumBreak :: getBrakePrice()
{
    return m_price;
}

void DrumBreak :: mechanicalBrakeing()
{
    cout << "Mechanical breaking tech. is used " << endl;
}



