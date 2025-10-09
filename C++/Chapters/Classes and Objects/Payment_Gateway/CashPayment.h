#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H

#include <iostream>
#include "PaymentGateway.h"
#include "GenerateBill.h"
class CashPayment : public PaymentGateway
{
public:
    CashPayment();
    ~CashPayment();

    void payNow(float amount);
    void cancel();

};

#endif // CASHPAYMENT_H
