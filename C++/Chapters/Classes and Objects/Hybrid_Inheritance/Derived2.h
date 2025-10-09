#ifndef DERIVED2_H
#define DERIVED2_H

#include "Derived1.h"
#include "Base2.h"

class Derived2 : public Derived1, public Base2
{
    float t;
public:
    void show();
};

#endif // DERIVED2_H
