#ifndef ADMIN_H
#define ADMIN_H

#include "PersonDetails.h"

using namespace std;

class Admin : public PersonDetails
{

    enum AdminMenuOption
    {
        CREATE_LANGUAGE = 1,
        DELETE_LANGUAGE,
        DISPLAY_LANGUAGES,
        CREATE_CHANNEL,
        EDIT_CHANNEL,
        DELETE_CHANNEL,
        CREATE_PROGRAM,
        EDIT_PROGRAM,
        DELETE_PROGRAM,
        CREATE_PACKAGE,
        EDIT_PACKAGE,
        DELETE_PACKAGE,
        DISPLAY_PACKAGES,
        LOGOUT
    };

public:
    Admin();
    void adminMenu();

private:
    int getValidatedInt();
    string getValidatedName();
    string getValidatedChannelName();
    bool isValidTime(const string &time);
    double getValidatedPrice();

};

#endif
