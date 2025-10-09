#include "HumanBody.h"

HumanBody::HumanBody()
{
    cout << "Human body Constructor" << endl;

}

HumanBody::~HumanBody()
{
    cout << "Human body Destructor" << endl;
}

void HumanBody::setGender(string gender)
{
    m_gender = gender;
}

string HumanBody::getGender()
{
    return m_gender;
}

void HumanBody::setIsAlive(bool isAlive)
{
    m_isAlive = isAlive;
}

bool HumanBody::getIsAlive()
{
    return m_isAlive;
}

