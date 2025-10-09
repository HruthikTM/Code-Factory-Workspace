#ifndef AUTOTRANSMISSION_H
#define AUTOTRANSMISSION_H

#include <iostream>
#include <string>
#include "Gear.h"

using namespace std;

class AutoTransmission : public Gear
{
public:
    AutoTransmission();

    ~AutoTransmission();

    void controlMode();
};
#endif // AUTOTRANSMISSION_H
