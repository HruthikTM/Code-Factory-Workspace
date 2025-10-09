#include <iostream>
#include "Derived.h"

using namespace std;

int main()
{
    Derived d;

    d.get_x(1.5);
    d.get_y(2.5);
    d.show();

    return 0;
}
