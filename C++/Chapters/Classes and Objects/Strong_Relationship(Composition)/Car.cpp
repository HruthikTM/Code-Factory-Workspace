#include "Car.h"

Car::Car()
{
    cout << "Car Constructor" << endl;
}

Car::~Car()
{
    cout << "Car Destructor" << endl;
}

void Car :: drive()
{
    engine.start();
    cout << "Car is moving" << endl;
}
