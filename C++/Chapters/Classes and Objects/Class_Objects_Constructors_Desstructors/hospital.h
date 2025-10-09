#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <string>

using namespace std;

class Hospital
{
    string name;
    int doctors;

public:
    Hospital(string n, int d)
    {
        name = n;
        doctors = d;

        cout << "Hospital created: " << name << endl;
    }

    ~Hospital()
    {
        cout << "Hospital destroyed: " << name << endl;
    }

    void admit()
    {
        cout << "Patient admitted." << endl;
    }

    void info()
    {
        cout << name << " has " << doctors << " doctors." << endl;
    }
};

#endif // HOSPITAL_H
