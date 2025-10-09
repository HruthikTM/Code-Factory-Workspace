#ifndef UPIPAYMENT_H
#define UPIPAYMENT_H

#include <iostream>
#include "PaymentGateway.h"
#include "GenerateBill.h"
using namespace std;

class UPIPayment : public PaymentGateway
{
public:
    UPIPayment();
    ~UPIPayment();

    void payNow(float amount);
    void cancel();
};

#endif // UPIPAYMENT_H
