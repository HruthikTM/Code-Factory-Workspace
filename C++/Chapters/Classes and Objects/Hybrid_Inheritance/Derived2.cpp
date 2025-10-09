#include "Derived2.h"


void Derived2 :: show()
{
    t = x + y + s;

    put_r();
    put_xy();
    put_s();

    cout << "t = " << t << endl;
}
