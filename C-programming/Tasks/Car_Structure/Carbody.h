#ifndef BODY_H
#define BODY_H
#include <stdio.h>

#include "Dimension.h"
#include "Door.h"
#include "Window.h"

struct CarBody {
    char color[15];
    struct Dimension bodyDimension;
    struct Door doors;
    struct Window windows;
};

void a(){
    printf("hi");
}




#endif // BODY_H
