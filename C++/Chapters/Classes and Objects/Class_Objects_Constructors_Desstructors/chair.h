#ifndef CHAIR_H
#define CHAIR_H

#include <iostream>
#include <string>

using namespace std;

class Chair
{
    string material;
    int height;

public:
    Chair(string m, int h)
    {
        material = m;
        height = h;
        cout << "Chair created" << endl;
    }

    ~Chair()
    {
        cout << "Chair destroyed " << endl;
    }

    void sit()
    {
        cout << "Sitting on chair " << endl;
    }

    void info()
    {
        cout << "Material: " << material << "of height " << height << "cm." << endl;
    }
};

#endif // CHAIR_H
