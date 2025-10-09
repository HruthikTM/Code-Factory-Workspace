#include "PremiumInsurance.h"

PremiumInsurance::PremiumInsurance()
{
    cout << "Premium Insurance const called" << endl;
}

PremiumInsurance::~PremiumInsurance()
{
    cout << "Premium Insurance dest called" << endl;
}

void PremiumInsurance :: policy(float amount, int age, int term, double coverage, bool benefits)
{
    m_amount=amount;
    m_age=age;
    m_term=term;
    m_coverage=coverage;
    m_benefits=benefits;

    cout << "Elite Policy -> Amount: " << m_amount << " Age: " << m_age << " Term: " << m_term << " Coverage: " << m_coverage << " Benefits: " << (m_benefits ? "Yes" : "No") << endl;
}



