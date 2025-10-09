#include <iostream>
#include "PaymentGateway.h"

using namespace std;

int main()
{
    PaymentGateway *gateway;
    gateway->selectPaymentMode();
    delete gateway;

    return 0;

}
