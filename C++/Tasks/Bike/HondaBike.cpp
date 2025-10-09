#include "HondaBike.h"

HondaBike::HondaBike(string model, int cc, float milage, double price) : Bike(model, cc, milage, price)
{
    cout << "HondaBike object created" << endl;
}

HondaBike::~HondaBike()
{
    cout << "HondaBike object destroyed" << endl;
}
