#include <iostream>

#include "Derived2.h"

using namespace std;

int main()
{
    Derived2 d;

    d.get_r(1111);
    d.get_xy(5.5,6.6);
    d.get_s(77.9);
    d.show();

    return 0;
}
