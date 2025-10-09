#ifndef DRIVER_H
#define DRIVER_H

#include<iostream>
#include "Car.h"
using namespace std;


class Driver
{
private:
    string m_name;
    Car *car = nullptr;

public:
    Driver(const string &name);
    ~Driver();

    void assignCar(Car *c);
    void drive();
};

#endif // DRIVER_H
