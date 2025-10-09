#ifndef CARDPAYMENT_H
#define CARDPAYMENT_H

#include <iostream>
#include "PaymentGateway.h"
#include "GenerateBill.h"
class CardPayment : public PaymentGateway
{
public:
    CardPayment();
    ~CardPayment();

    void payNow(float amount);
    void cancel();

};

#endif // CARDPAYMENT_H
