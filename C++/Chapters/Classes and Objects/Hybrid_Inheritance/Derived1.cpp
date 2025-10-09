#include "Derived1.h"

void Derived1 :: get_xy(float a, float b)
{
    x = a;
    y = b;
}

void Derived1 :: put_xy()
{
    cout << "x= " << x << endl;
    cout << "y= " << y << endl;
}
