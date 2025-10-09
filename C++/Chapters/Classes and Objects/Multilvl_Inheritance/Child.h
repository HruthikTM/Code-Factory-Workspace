#ifndef CHILD_H
#define CHILD_H

#include "Parent.h"

class Child : public Parent
{
    char hobby[20];

public:
    void inputData();
    void outputData();
};

#endif // CHILD_H
