#ifndef AIRCONDITIONER_H
#define AIRCONDITIONER_H

#include <iostream>
#include <string>

using namespace std;

class AirConditioner
{
public:
    AirConditioner();

    ~AirConditioner();

    void cool();

    void warm();
};

#endif // AIRCONDITIONER_H
