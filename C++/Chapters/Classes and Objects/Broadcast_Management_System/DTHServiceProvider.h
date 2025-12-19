#ifndef DTHSERVICEPROVIDER_H
#define DTHSERVICEPROVIDER_H

#include <iostream>
#include <map>
#include <string>

#include "Languages.h"
#include "Package.h"
#include "Admin.h"
#include "Customer.h"
#include "AuthenticateUser.h"
#include "SqlReader.h"

using namespace std;

class DthServiceProvider
{
    enum userTypeMenu
    {
        AdminUser = 1,
        CustomerUser ,
        ExitMenu
    };

    enum authMenu
    {
        Login = 1,
        Register,
        Back
    };

public:
    DthServiceProvider();
    ~DthServiceProvider();

    void startService();

private:
    int m_providerId;
    string m_providerName;

    map<int, Languages*> m_languageMap;
    map<int, Package*> m_packageMap;
    map<int, Admin*> m_adminMap;
    map<int, Customer*> m_customerMap;
};

#endif
