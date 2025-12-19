#include "DthServiceProvider.h"

DthServiceProvider::DthServiceProvider()
{
    cout << "\n=== WELCOME TO DTH SERVICE PROVIDER ===\n";
}

int DthServiceProvider::getValidatedInt()
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
            cout << "Invalid input, Re-enter again.\n";
        }
    }
    return value;
}

void DthServiceProvider::startService()
{
    while (true)
    {
        cout << "\n--- LOGIN PORTAL ---\n";
        cout << "1. Admin Login\n";
        cout << "2. Customer Login\n";
        cout << "3. Customer Registration\n";
        cout << "4. Exit\n";
        cout << "Choice : ";

        int choice = getValidatedInt();

        AuthenticateUser auth;

        switch (choice)
        {
        case ADMIN_LOGIN:
        {
            int id = auth.login("admin");
            if (id != -1)
                auth.handleAdmin(id);
            break;
        }

        case CUSTOMER_LOGIN:
        {
            int id = auth.login("customer");
            if (id != -1)
                auth.handleCustomer(id);
            break;
        }

        case CUSTOMER_REGISTRATION:
            auth.registerUser("customer");
            break;

        case EXIT:
            cout << "Exiting...\n";
            return;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
