#include <iostream>
#include "Container.h"

using namespace std;

int main()
{
    Container c1, c3;
    c1.setDimention(10, 20, 30);
    c1.showData();

    Container c2 = c1; //copy constructor
    c2.showData();

    c3 = c1;          // assignment operator
    c3.showData();

    return 0;
}
