#include "HealthInsurance.h"

HealthInsurance::HealthInsurance()
{
    cout << "Insurance const is called" << endl;
}

HealthInsurance::~HealthInsurance()
{
    cout << "Insurance dest is called" << endl;
}

void HealthInsurance :: setName(string name)
{
    m_name = name;
}

string HealthInsurance :: getName()
{
    return m_name;
}

void HealthInsurance :: setNumber(int number)
{
    m_phoneNumber = number;
}

int HealthInsurance :: getNumber()
{
    return m_phoneNumber;
}

void HealthInsurance :: policy(float amount, int age)
{
    m_amount=amount;
    m_age=age;

    cout << "General Policy -> Amount: " << m_amount << " Age: " << m_age << endl;
}


