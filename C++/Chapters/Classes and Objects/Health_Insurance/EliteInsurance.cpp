#include "EliteInsurance.h"

EliteInsurance::EliteInsurance()
{
    cout << "Elite Insurance const called" << endl;
}

EliteInsurance::~EliteInsurance()
{
    cout << "Elite Insurance dest called" << endl;
}

void EliteInsurance :: policy(float amount, int age, int term, double coverage)
{
    m_amount=amount;
    m_age=age;
    m_term=term;
    m_coverage=coverage;

    cout << "Elite Policy -> Amount: " << m_amount << " Age: " << m_age << " Term: " << m_term << " Coverage: " << m_coverage << endl;
}




