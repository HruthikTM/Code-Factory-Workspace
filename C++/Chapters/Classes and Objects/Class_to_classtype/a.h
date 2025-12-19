#ifndef A_H
#define A_H

#include "b.h"

class A
{
    int x,y;
public:
    A() : x(10),y(20){}

    operator B()
    {
        return B(x,y);
    }
};

#endif // A_H
