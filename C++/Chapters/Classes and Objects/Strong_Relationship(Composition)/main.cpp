#include <iostream>
#include <Car.h>

using namespace std;

int main()
{
    Car* myCar = new Car();
    myCar->drive();


    delete myCar;
    cout << "Car object deleted\n";

    return 0;
}
