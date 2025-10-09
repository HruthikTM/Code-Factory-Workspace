#include <iostream>

#include "HeroBike.h"
#include "HondaBike.h"
#include "Bike.h"

using namespace std;

int main()
{
    HeroBike b1("Splendor", 100, 70, 70000, true);

    b1.display();

    //b1.Bike :: display();

    HondaBike b2("Unicorn", 150, 65, 100000);

    b2.display();

    return 0;
}
