#include "DthServiceProvider.h"

DthServiceProvider::DthServiceProvider()
{
    m_providerId = 101;
    m_providerName = "Tata Sky";

    SqlReader::getInstance()->createFile();
    SqlReader::getInstance()->readFile(m_languageMap);
    SqlReader::getInstance()->readPackages(m_packageMap, m_languageMap);
}

DthServiceProvider::~DthServiceProvider()
{
    for (auto &pair : m_languageMap)
        delete pair.second;

    m_languageMap.clear();
}

void DthServiceProvider::startService()
{
    AuthenticateUser auth(m_adminMap, m_customerMap);
    bool isAuthenticated = false;
    string userType;

    cout << "\n===== WELCOME TO DTH SERVICE PROVIDER =====\n";

    while (true)
    {
        int typeChoice;

        while (true)
        {
            cout << "\nSelect User Type:\n";
            cout << "1. Admin\n"
                    "2. Customer\n"
                    "3. Exit\n";
            cout << "Enter choice: ";

            cin >> typeChoice;

            if (!cin.fail())
            {
                cin.ignore(1000,'\n');
                break;
            }
            else
            {
                cin.clear();
                while (getchar() != '\n');
                cout << "Invalid input.\n";
            }
        }

        switch (typeChoice)
        {
        case AdminUser:
            userType = "admin";
            break;

        case CustomerUser:
            userType = "customer";
            break;

        case ExitMenu:
            cout << "Exiting DTH Service Provider...\n";
            return;

        default:
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        break;
    }

    while (!isAuthenticated)
    {
        cout << "\n===== " << (userType == "admin" ? "ADMIN" : "CUSTOMER")
        << " AUTHENTICATION =====\n";
        cout << "1. Login\n"
                "2. Register\n"
                "3. Back\n"
                "Enter choice: ";

        int choice;
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice)
        {

        case Login:
        {
            string loggedType = auth.login(userType);
            if (!loggedType.empty() && loggedType == userType)
                isAuthenticated = true;
            else if (!loggedType.empty())
                cout << "You logged in as a different user type.\n";
            break;
        }

        case Register:
            auth.registerUser(userType);
            break;

        case Back:
            cout << "Returning to main menu...\n";
            return startService();

        default:
            cout << "Invalid choice.\n";
        }
    }

    if (userType == "admin")
    {
        Admin admin(m_languageMap, m_packageMap);
        admin.adminMenu();
    }
    else if (userType == "customer")
    {
        Customer customer(m_packageMap);
        customer.customerMenu();
    }
    else
    {
        cout << "Unknown user type.\n";
    }
}



