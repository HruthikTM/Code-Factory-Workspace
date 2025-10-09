#ifndef DERIVED1_H
#define DERIVED1_H

#include "Base1.h"

class Derived1 : public Base1
{
protected:

    float x,y;

public:
    void get_xy(float a, float b);

    void put_xy();
};

#endif // DERIVED1_H
