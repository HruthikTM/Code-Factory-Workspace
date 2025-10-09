#ifndef TOPSIDE_H
#define TOPSIDE_H


#include "Dimension.h"
#include "Port.h"
#include "MicroPhone.h"


struct MobileTopSide{
    struct Dimension topSideDimension;
    struct Port headPhonePort;
    struct MicroPhone microphone;
};

#endif // TOPSIDE_H
