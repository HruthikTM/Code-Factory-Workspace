#include "Tyer.h"

// Tyer::Tyer()
// {}

void Tyer :: fillAir()
{
    cout << "Air filled" << endl;
}

void Tyer :: setTyerBrand(string tyerBrand)
{
    m_tyerBrand = tyerBrand;
}

string Tyer :: getTyerBrand()
{
    return m_tyerBrand;
}

void Tyer :: setTyerRadius(float tyerRadius)
{
    m_tyerRadius = tyerRadius;
}

float Tyer :: getTyerRadius()
{
    return m_tyerRadius;
}
