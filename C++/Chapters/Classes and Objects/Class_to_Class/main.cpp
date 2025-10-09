#include <iostream>

using namespace std;

#include "Test1.h"
#include "Test2.h"

int main()
{
    Test1 t1;
    Test2 t2(t1);

    t2 = t1;
    t2.display();
    return 0;
}
