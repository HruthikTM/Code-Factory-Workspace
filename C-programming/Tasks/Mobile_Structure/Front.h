#ifndef FRONT_H
#define FRONT_H

#include "Dimension.h"
#include "Display.h"
#include "Camera.h"

struct MobileFront{
    struct Dimension mobileFrontDimension;
    struct Display frontDisplay;
    struct Camera frontCamrea;
};

#endif // FRONT_H
