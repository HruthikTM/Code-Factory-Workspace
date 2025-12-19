#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "PersonDetails.h"
#include "Languages.h"
#include "Package.h"
#include "SqlReader.h"
#include <map>
#include <iostream>
#include <string>

using namespace std;

class Customer : public PersonlDetails
{
    enum customerMenu
    {
        DisplayAvaliablePackages = 1,
        Select_and_Pay,
        ViewProfile,
        EditProfile,
        View_Subscribed_Package,
        Logout
    };

public:
    Customer(map<int, Package*>& packageMap);
    Customer(int id, const string& name, const string& password, const string& phone, map<int, Package*>& packageMap);
    ~Customer();

    void customerMenu();

private:
    void displayAvailablePackages();
    bool selectPackage();
    bool payment(Package* selectedPackage);

    void viewProfile();
    void editProfile();

private:
    SqlReader* m_reader;
    map<int, Package*>& m_packageMap;
};

#endif // CUSTOMER_H
