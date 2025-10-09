#ifndef WHEEL_H
#define WHEEL_H

#include "Dimension.h"

struct Wheel {
    int diameter;
    char type[10];
    struct Dimension wheelDimension;
};

#endif // WHEEL_H
