#ifndef CAR_H
#define CAR_H

#include "Dimension.h"
#include "Engine.h"
#include "Carbody.h"
#include "Interior.h"
#include "Wheel.h"
#include "Light.h"

struct Car {
    char brand[20];
    char model[20];
    float price;

    Dimension carDimension;
    struct Engine carEngine;
    struct CarBody carBody;
    struct CarInterior carInterior;
    struct Wheel carWheels;
    struct CarLight carLights;
};

#endif // CAR_H
