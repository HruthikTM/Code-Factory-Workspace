#ifndef DERIVED_H
#define DERIVED_H

#include <iostream>

using namespace std;
#include "Base.h"

class Derived : public Base
{
public:
    Derived();

    void display();

    ~Derived();
};

#endif // DERIVED_H
