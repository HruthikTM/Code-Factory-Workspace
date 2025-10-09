#ifndef BOTTOMSIDE_H
#define BOTTOMSIDE_H

#include "Dimension.h"
#include "Speaker.h"
#include "Port.h"

struct MobileBottomSide{
    struct Dimension bottomSideDimension;
    struct Speaker sperker;
    struct Port chargingPort;
};

#endif // BOTTOMSIDE_H
