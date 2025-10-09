#ifndef POLICYINTERFACE_H
#define POLICYINTERFACE_H

#include <iostream>
#include <string>

#include "HealthInsurance.h"
#include "EliteInsurance.h"
#include "PremiumInsurance.h"

using namespace std;

class PolicyInterface
{
public:
    PolicyInterface();
    ~PolicyInterface();

    void getPolicy();

private:
    enum InsuranceType
    {
        ELITE = 1,
        PREMIUM
    };

    enum ElitePolicyType
    {
        ELITE_BASIC = 1,
        ELITE_EXTENDED
    };

    enum PremiumPolicyType
    {
        PREMIUM_BASIC = 1,
        PREMIUM_EXTENDED
    };

};


#endif // POLICYINTERFACE_H
