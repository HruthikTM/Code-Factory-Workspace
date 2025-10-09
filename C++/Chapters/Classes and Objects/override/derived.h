#ifndef DERIVED_H
#define DERIVED_H

#include <iostream>
#include "base.h"
using namespace std;

class derived : public base
{
public:
    derived(int a);
    ~derived();

    void display();
};

#endif // DERIVED_H
