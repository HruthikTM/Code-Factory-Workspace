#ifndef AUTHENTICATEUSER_H
#define AUTHENTICATEUSER_H

#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include "SqlReader.h"
#include "Admin.h"
#include "Customer.h"

using namespace std;

class AuthenticateUser
{
public:
    AuthenticateUser(map<int, Admin*>& adminMap, map<int, Customer*>& customerMap);
    ~AuthenticateUser();

    string login(const string& userType);
    bool registerUser(const string& userType);

    int getValidatedInt();
    string getValidatedName();
    string getValidatedPhone();
    string getValidatedPassword();

private:
    SqlReader* m_sqlReader;
    map<int, Admin*>& m_adminMap;
    map<int, Customer*>& m_customerMap;
};

#endif // AUTHENTICATEUSER_H
