#ifndef DTHSERVICEPROVIDER_H
#define DTHSERVICEPROVIDER_H

#include <iostream>
#include "AuthenticateUser.h"

using namespace std;

class DthServiceProvider
{
    enum loginPortal
    {
        ADMIN_LOGIN = 1,
        CUSTOMER_LOGIN,
        CUSTOMER_REGISTRATION,
        EXIT
    };

public:
    DthServiceProvider();
    int getValidatedInt();
    void startService();
};

#endif
