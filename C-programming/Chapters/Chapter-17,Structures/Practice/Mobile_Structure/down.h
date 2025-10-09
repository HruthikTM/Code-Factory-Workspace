#ifndef DOWN_H
#define DOWN_H
#include "ports.h"
#include "speaker.h"

struct down{
    struct ports p;
    struct speaker sp;
};


struct down d = {
    .p = {
        .port = {
            "USB-C", "Audio-Jack"
        }
    },
    .sp = {
        .n = 2
    }
};
#endif // DOWN_H
