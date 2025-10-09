#include "Base1.h"




void Base1 :: get_x(float a)
{
    x = a;
    y = get_y(8.5);
}

void Base1 :: show()
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "x + y = " << (x+y) << endl;
}
