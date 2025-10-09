#include <iostream>
#include "Base.h"
#include "Derived.h"

using namespace std;

int main()
{
    Base b;
    Derived d;

    // Derived *dp;

    // dp = &d;
    // dp->display();

    Base *bp;
    bp = &d;

    Derived *dp;

    //bp->display();
    ((Derived *)bp)->display();

    return 0;

}
