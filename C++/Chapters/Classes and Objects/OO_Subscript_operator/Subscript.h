#ifndef SUBSCRIPT_H
#define SUBSCRIPT_H

#include <iostream>
using namespace std;

class Subscript
{
public:
    Subscript();
    ~Subscript();

    Subscript(int *);

    int operator [] (int );

private:
    int a[5];
};

#endif // SUBSCRIPT_H
