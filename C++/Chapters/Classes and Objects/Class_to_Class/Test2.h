#ifndef TEST2_H
#define TEST2_H

#include <iostream>

using namespace std;

#include "Test1.h"

class Test2
{
private:
    int a;
    int b;
public:
    Test2(Test1 t1);
    ~Test2();

    void display();

};

#endif // TEST2_H
