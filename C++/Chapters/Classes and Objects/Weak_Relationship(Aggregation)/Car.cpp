#include "Car.h"

Car::Car(const string &model) : m_model(model)
{
    cout << "Car Constructor" << endl;
}

Car::~Car()
{
    cout << "Car Destructor" << endl;
}

void Car :: showModel()
{
    cout << "Car model:" << m_model << endl;
}
