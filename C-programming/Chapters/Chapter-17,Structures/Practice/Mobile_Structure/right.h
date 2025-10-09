#ifndef RIGHT_H
#define RIGHT_H
#include "rbutton.h"

struct right{
    struct rbutton rb;
};


struct right rt={
    .rb = {
        .button = {
            "PowerButton,1", "QuickAccessButton,1"
                }
            }};
#endif // RIGHT_H
