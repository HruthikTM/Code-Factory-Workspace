#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "PersonDetails.h"
// #include "MainDataModel.h"

using namespace std;

class Customer : public PersonDetails
{
    enum CustomerMenuOption
    {
        VIEW_AVAIL_PACKAGES = 1,
        SUBSCRIBE_PACKAGE,
        VIEW_PROFILE,
        EDIT_PROFILE,
        VIEW_SUBSCRIBED_PACKAGE,
        LOGOUT
    };

public:
    Customer();
    void customerMenu();

private:
    int getValidatedInt();
};

#endif
