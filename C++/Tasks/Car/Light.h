#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include <string>

using namespace std;

class Light
{
public:
    Light();

    ~Light();



    void lightON();
    void lightOFF();

private:
    string m_lightType;
};

#endif // LIGHT_H
