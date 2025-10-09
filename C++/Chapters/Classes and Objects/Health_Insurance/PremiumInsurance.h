#ifndef PREMIUMINSURANCE_H
#define PREMIUMINSURANCE_H

#include "HealthInsurance.h"

class PremiumInsurance : public HealthInsurance
{

public:
    PremiumInsurance();
    ~PremiumInsurance();

    void policy(float amount, int age, int term, double coverage, bool benefits);

private:
    float m_amount;
    int m_age;
    int m_term;
    double m_coverage;
    bool m_benefits;
};


#endif // PREMIUMINSURANCE_H
