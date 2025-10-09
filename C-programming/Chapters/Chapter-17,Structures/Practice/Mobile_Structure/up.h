#ifndef UP_H
#define UP_H
#include "sensor.h"

struct up{
    struct sensor s;
};


struct up u = {
    .s = {
        .n = 2
    }
};
#endif // UP_H
