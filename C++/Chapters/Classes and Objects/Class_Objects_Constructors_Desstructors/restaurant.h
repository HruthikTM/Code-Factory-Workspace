#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>

using namespace std;


class Restaurant
{
    string name;
    int tables;

public:
    Restaurant(string n, int t)
    {
        name = n;
        tables = t;

        cout << "Restaurant created: " << name << endl;
    }
    ~Restaurant()
    {
        cout << "Restaurant destroyed: " << name << endl;
    }
    void serve()
    {
        cout << name << " is serving food " << endl;
    }
    void seats()
    {
        cout << "Tables: " << tables << endl;
    }
};

#endif // RESTAURANT_H
