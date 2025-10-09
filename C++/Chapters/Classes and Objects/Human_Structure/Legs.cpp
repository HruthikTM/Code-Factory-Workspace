#include "Legs.h"

Legs::Legs()
{
    cout << "Legs constructor" << endl;
    m_fingers = new Fingers;
}


Legs::~Legs()
{
    cout << "Legs destructor" << endl;
}
