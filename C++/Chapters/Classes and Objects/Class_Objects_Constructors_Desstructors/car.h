#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car
{
    string brand;
    string model;
    int fuelCapacity;
    int fuel;

public:
    Car(string b, string m, int capacity)
    {
        brand = b;
        model = m;
        fuelCapacity = capacity;
        fuel = 0;

        cout << brand << " " << model << " created." << endl;
    }

    ~Car()
    {
        cout << brand << " " << model << " destroyed." << endl;
    }


    void refuel(int liters)
    {
        if(fuel + liters <= fuelCapacity)
        {
            fuel += liters;
            cout << "Added " << liters << "of fuel to the car" << endl;
        }
        else
        {
            cout << "Tank is full " << endl;
        }
    }

    void drive(int distance)
    {
        float fuelNeeded = distance * 0.1;
        if(fuel >= fuelNeeded)
        {
            fuel -= fuelNeeded;
            cout << "Drove " << distance << " km. Remaining fuel: " << fuel << "L" << endl;
        }
        else
        {
            cout << "Not enough fuel to drive!" << endl;
        }

    }
};

#endif // CAR_H
