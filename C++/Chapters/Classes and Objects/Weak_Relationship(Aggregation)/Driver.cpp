#include "Driver.h"

Driver::Driver(const string &name) : m_name(name)
{
    cout << "Driver constructor" << endl;
}

Driver::~Driver()
{
    cout << "Driver destructor" << endl;
}

void Driver :: assignCar(Car *c)
{
    car = c;
}

void Driver :: drive()
{
    if(car)
        cout << m_name << "is driving " << endl, car->showModel();
    else
        cout << m_name << "has no car assigned" << endl;
}
