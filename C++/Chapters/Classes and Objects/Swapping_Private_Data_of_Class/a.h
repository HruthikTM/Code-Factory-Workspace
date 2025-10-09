#ifndef A_H
#define A_H

#include <iostream>

using namespace std;

//#include "b.h"

class B;

class A
{
    int value1;
public:
    A();

    void inData(int n)
    {
        value1 = n;
    }

    void display()
    {
        cout << value1 << "\n";
    }

    friend void exchange(A &, B &);
};

#endif // A_H
