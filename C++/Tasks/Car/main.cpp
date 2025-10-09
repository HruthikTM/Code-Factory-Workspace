#include <iostream>

using namespace std;

#include "Car.h"

int main()
{
    Car myCar("Benz","S-class","Petrol",1000000,7.5f);

    myCar.start();
    myCar.drive();
    myCar.stop();

    myCar.setBrand("BMW");
    myCar.setModel("M4");

    myCar.start();
    myCar.drive();
    myCar.stop();

    return 0;
}
