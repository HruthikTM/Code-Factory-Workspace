#ifndef LEFTSIDE_H
#define LEFTSIDE_H

#include "Dimension.h"
#include "Button.h"
#include "Port.h"

struct MobileLeftSide{

    struct Dimension leftSideDimension;
    struct Button volumeButton;
    struct Port simPort;
};

#endif // LEFTSIDE_H
