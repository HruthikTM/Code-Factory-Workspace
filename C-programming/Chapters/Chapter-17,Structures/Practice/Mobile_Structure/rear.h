#ifndef REAR_H
#define REAR_H
#include "rearcamera.h"
#include "flashlight.h"

struct rear{
    struct rearcamera;
    struct flashlight;
};

struct rear r = {
    .rc = {
        .radius = 2.5,
        .pixel = 108
    },
    .fl = {
        .radius = 1
    }
};

#endif // REAR_H
