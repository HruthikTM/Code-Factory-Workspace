#ifndef REAR_H
#define REAR_H

#include "Dimension.h"
#include "Camera.h"
#include "Flashlight.h"

struct MobileRear{
    struct Dimension mobileBackDimension;
    struct Camera rearCamrea;
    struct Flashlight flashLight;
};

#endif // REAR_H
