#ifndef FRONT_H
#define FRONT_H
#include "screen.h"
#include "frontcamera.h"

struct front{
    struct screen sc;
    struct frontcamera fc;
};


struct front f = {
    .sc = {
        .length = 4.5,
        .breadth = 15.5
    },
    .fc = {
        .radius = 1.5,
        .pixel = 64
    }
};
#endif // FRONT_H
