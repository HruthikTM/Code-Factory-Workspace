#ifndef CAR_H
#define CAR_H

#include<iostream>
#include "Engine.h"
using namespace std;

class Car
{
private:
    Engine engine;
public:
    Car();
    ~Car();

    void drive();
};

#endif // CAR_H
