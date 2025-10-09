#ifndef PAYMENTGATEWAY_H
#define PAYMENTGATEWAY_H

#include <iostream>

using namespace std;

class PaymentGateway
{
public:
    PaymentGateway();
    virtual ~PaymentGateway();

    void selectPaymentMode();

    virtual void payNow(float amount) = 0;
    virtual void cancel() = 0;

};

#endif // PAYMENTGATEWAY_H
