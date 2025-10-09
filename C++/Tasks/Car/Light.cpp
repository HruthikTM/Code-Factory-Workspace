#include "Light.h"

Light::Light()
{
    cout << "Light obj created " << endl;
}

Light::~Light()
{
    cout << "Light obj destroyed " << endl;
}

// void Light :: setLightType(string lightType)
// {
//     m_lightType = lightType;
// }

// string Light :: getLightType()
// {
//     return m_lightType;
// }

void Light :: lightON()
{
    cout << "Light is turned on" << endl;
}

void Light :: lightOFF()
{
    cout << "Light is turned off" << endl;
}
