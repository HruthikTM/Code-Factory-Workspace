#include "Staring.h"

Staring::Staring()
{
    cout << "Staring obj created " << endl;
}

Staring::~Staring()
{
    cout << "Staring obj deleted " << endl;
}

void Staring :: setHandleType(string handleType)
{
    m_handleType = handleType;
}

string Staring :: getHandleType()
{
    return m_handleType;
}

void Staring :: turnLeft()
{
    cout << "Truning left.." << endl;
}

void Staring :: turnRight()
{
    cout << "Truning right.." << endl;
}

void Staring :: horn()
{
    cout << "Horning.." << endl;
}
