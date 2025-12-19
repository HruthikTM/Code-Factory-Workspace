#ifndef CUSTOMERMODEL_H
#define CUSTOMERMODEL_H

#include <string>
#include <iostream>
#include <map>

#include "Customer.h"
#include "PackageModel.h"
#include "SqlReader.h"

using namespace std;

class CustomerModel
{
public:
    CustomerModel(PackageModel* pkgModel);

    Customer* loadCustomer(int id);
    bool createCustomer(int id, const string& name, const string& pass, const string& phone);
    bool verifyUser(int id, const string& password);

    void displayAvailablePackages();
    bool selectPackage(int customerId);
    bool payment(int customerId, Package* pkg);
    void viewSubscribedPackages(int customerId);

    void viewProfile(int id);
    void editProfile(int id);

    bool addCustomer(int id, Customer* customer);
    Customer* getCustomer(int id);
    bool customerExists(int id);

private:
    SqlReader* m_reader;
    PackageModel* m_pkgModel;

    map<int, Customer*> m_customerMap;

    int getValidatedInt();
    string getValidatedName();
    string getValidatedPassword();
    string getValidatedPhone();

    string getValidatedString();
};

#endif
