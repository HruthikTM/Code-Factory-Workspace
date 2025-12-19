#include "Customer.h"
#include "MainDataModel.h"
#include <iostream>
using namespace std;

Customer::Customer()
{

}

int Customer::getValidatedInt()
{
    int value;
    while (true)
    {
        cin >> value;

        if (!cin.fail())
        {
            cin.ignore(1000,'\n');
            return value;
        }
        else
        {
            cin.clear();
            while(getchar() != '\n');
            cout << "Invalid input.\n";
        }
    }
    return value;
}

void Customer::customerMenu()
{
    MainDataModel* m_model = MainDataModel::getInstance();


    while (true)
    {
        cout << "\n=== CUSTOMER MENU ===\n";
        cout << "1. View Available Packages\n";
        cout << "2. Subscribe Package\n";
        cout << "3. View Profile\n";
        cout << "4. Edit Profile\n";
        cout << "5. View Subscribed Packages\n";
        cout << "6. Logout\n";
        cout << "Choice: ";

        int ch = getValidatedInt();
        if (ch == 6)
            return;

        switch (ch)
        {
        case VIEW_AVAIL_PACKAGES:
            m_model->viewAvailablePackages();
            break;

        case SUBSCRIBE_PACKAGE:
            m_model->subscribePackage(id());
            break;

        case VIEW_PROFILE:
            m_model->viewProfile(id());
            break;

        case EDIT_PROFILE:
            m_model->editProfile(id());
            break;

        case VIEW_SUBSCRIBED_PACKAGE:
            m_model->viewSubscribedPackages(id());
            break;

        case LOGOUT:
            cout << "Logging out...\n";
            return;

        default:
            cout << "Invalid option.\n";
        }
    }
}
