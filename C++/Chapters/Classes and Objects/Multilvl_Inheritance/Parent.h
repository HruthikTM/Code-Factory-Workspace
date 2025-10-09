#ifndef PARENT_H
#define PARENT_H

#include "GrandParent.h"

class Parent : public GrandParent
{
    char qual[50];
    double salary;

public:
    int IQ;

    void readData();
    void printData();
};

#endif // PARENT_H
