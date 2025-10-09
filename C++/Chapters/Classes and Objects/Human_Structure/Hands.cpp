#include "Hands.h"

Hands::Hands()
{
    cout << "Hands Constructor" << endl;
    m_fingers = new Fingers;
}


Hands::~Hands()
{
    cout << "Hands Destructor" << endl;
}
