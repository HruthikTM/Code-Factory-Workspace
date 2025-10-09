#ifndef TYER_H
#define TYER_H

#include <iostream>
#include <string>

using namespace std;

class Tyer
{
public:
    // Tyer();

    void fillAir();

    void setTyerBrand(string tyerBrand);

    string getTyerBrand();


    void setTyerRadius(float tyerRadius);

    float getTyerRadius();

private:
    string m_tyerBrand;
    float m_tyerRadius;
};

#endif // TYER_H
