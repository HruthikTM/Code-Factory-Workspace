#ifndef B_H
#define B_H

#include <iostream>
using namespace std;

//#include "a.h"

class A;

class B
{
    int value2;
public:
    B();

    void inData(int n)
    {
        value2 = n;
    }

    void display()
    {
        cout << value2 << "\n";
    }

    friend void exchange(A &, B &);
};

#endif // B_H
