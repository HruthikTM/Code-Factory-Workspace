#ifndef BODY_H
#define BODY_H

#include "Dimension.h"
#include "Battery.h"
#include "Processor.h"

struct MobileBody
{
    char type[10];
    char color[10];

    struct Dimension mobileBodyDimension;
    struct Processor processor;
    struct Battery battery;
};

#endif // BODY_H
