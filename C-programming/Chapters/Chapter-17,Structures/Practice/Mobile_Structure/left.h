#ifndef LEFT_H
#define LEFT_H
#include "lbutton.h"

struct left{
    struct lbutton lb;
};


struct left lf={
    .lb = {
        .button = {
            "VolumeButton,1"
        }
    }};

#endif // LEFT_H
