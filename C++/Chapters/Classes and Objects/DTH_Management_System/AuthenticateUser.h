#ifndef AUTHENTICATEUSER_H
#define AUTHENTICATEUSER_H

#include <string>
#include "MainDataModel.h"
#include "Customer.h"
#include "Admin.h"

using namespace std;

class AuthenticateUser
{
public:
    AuthenticateUser();

    int login(const string& userType);
    bool registerUser(const string& userType);

    void handleCustomer(int id);
    void handleAdmin(int id);

private:
    MainDataModel* m_model;

    int getValidatedInt();
    string getValidatedName();
    string getValidatedPhone();
    string getValidatedPassword();
};

#endif
