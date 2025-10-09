#ifndef LAPTOP_H
#define LAPTOP_H


#include <iostream>
#include <string>

using namespace std;
class Laptop
{
    string brand;
    int ram;

public:
    Laptop(string b, int r)
    {
        cout << "Laptop created: " << brand << endl;
    }

    ~Laptop()
    {
        cout << "Laptop destroyed: " << brand << endl;
    }

    void start()
    {
        cout << brand << "Laptop starting " << endl;
    }

    void specs()
    {
        cout << "RAM: " << ram << " GB" << endl;
    }
};

#endif // LAPTOP_H
