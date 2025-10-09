#ifndef MOBILE_H
#define MOBILE_H

#include "Dimension.h"
#include "Front.h"
#include "Body.h"
#include "Rear.h"
#include "LeftSide.h"
#include "RightSide.h"
#include "TopSide.h"
#include "BottomSide.h"

struct Mobile{
    char brand[10];
    char model[10];
    float price;

    struct Dimension mobileDimension;
    struct MobileFront mobileFrontSide;
    struct MobileRear mobileRearSide;
    struct MobileBody mobileBody;
    struct MobileLeftSide mobileLeftSide;
    struct MobileRightSide mobileRightSide;
    struct MobileTopSide mobileTopSide;
    struct MobileBottomSide mobileBottomSide;
};

#endif // MOBILE_H
