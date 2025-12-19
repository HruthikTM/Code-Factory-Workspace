#include <iostream>
#include "a.h"
#include "b.h"

using namespace std;

int main()
{
    A a1;
    B b1;

    b1.get_b();

    b1 = a1;

    b1.get_b();
    return 0;
}
