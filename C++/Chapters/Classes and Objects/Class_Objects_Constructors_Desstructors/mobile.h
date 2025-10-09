#ifndef MOBILE_H
#define MOBILE_H

#include <iostream>
#include <string>

using namespace std;

class Mobile
{
    string brand;
    string model;
    int price;

public:
    Mobile(string b, string m, int p)

    {
        brand = b;
        model = m;
        price = p;

        cout << "mobile created of brand: " << brand << " and" << model;
    }

    ~Mobile()
    {
        cout << "Mobile destroyed " <<endl;
    }

    void call(int num)
    {
        cout << "Calling " << num << endl;
    }

    void message(string msg)
    {
        cout << "Message sent " << msg << endl;
    }
};

#endif // MOBILE_H
