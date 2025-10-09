#ifndef MANUALTRANSMISSION_H
#define MANUALTRANSMISSION_H

#include <iostream>
#include <string>
#include "Gear.h"

using namespace std;

class ManualTransmission : public Gear
{
public:
    ManualTransmission();

    ~ManualTransmission();

    void controlSpeed();
};

#endif // MANUALTRANSMISSION_H
