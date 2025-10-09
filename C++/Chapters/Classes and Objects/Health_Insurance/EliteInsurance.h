#ifndef ELITEINSURANCE_H
#define ELITEINSURANCE_H

#include "HealthInsurance.h"

class EliteInsurance : public HealthInsurance
{

public:
    EliteInsurance();
    ~EliteInsurance();

    void policy(float amount, int age, int term, double coverage);

private:
    float m_amount;
    int m_age;
    int m_term;
    double m_coverage;
};

#endif // ELITEINSURANCE_H
