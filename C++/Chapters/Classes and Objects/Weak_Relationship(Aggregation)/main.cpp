#include <iostream>
#include "Driver.h"

using namespace std;

int main()
{
    Car bmw("BMW X5");


    Driver* alice = new Driver("Alice");
    alice->assignCar(&bmw);
    alice->drive();


    delete alice;

    cout << "Driver object deleted, but the car still exists" << endl;
    bmw.showModel();

    return 0;
}
