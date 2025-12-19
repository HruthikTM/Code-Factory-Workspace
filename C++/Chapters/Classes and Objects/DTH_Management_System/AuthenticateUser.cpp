#include "AuthenticateUser.h"
#include <iostream>
#include <limits>

using namespace std;

AuthenticateUser::AuthenticateUser()
{
    m_model = MainDataModel::getInstance();
}

int AuthenticateUser::getValidatedInt()
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
            while (getchar() != '\n');
            cout << "Invalid input.\n";
        }
    }
    return value;
}

string AuthenticateUser::getValidatedName()
{
    string input;
    cin.ignore(1000, '\n');
    while (true)
    {
        getline(cin, input);

        if (input.empty())
        {
            cout << "Name cannot be empty. Enter again: ";
            continue;
        }

        bool valid = true;
        for (char c : input)
        {
            if (!isalpha(c) && c != ' ')
            {
                valid = false;
                break;
            }
        }

        if (valid)
            return input;

        cout << "Invalid name! Enter alphabets only: ";
    }
}

string AuthenticateUser::getValidatedPhone()
{
    string input;
    while (true)
    {
        cin >> input;

        bool valid = (input.size() == 10);

        if (valid)
        {
            for (char c : input)
            {
                if (!isdigit(c))
                {
                    valid = false;
                    break;
                }
            }
        }

        if (valid)
            return input;

        cout << "Invalid phone number! Enter 10 digits only.\n";
    }
}

string AuthenticateUser::getValidatedPassword()
{
    string password;
    while (true)
    {
        cin >> password;
        if (password.size() >= 4)
            return password;

        cout << "Password must have Min.4 characters.\n";
    }
}

int AuthenticateUser::login(const string& userType)
{
    cout << "\n--- LOGIN (" << userType << ") ---\n";
    cout << "Enter ID: ";
    int id = getValidatedInt();

    cout << "Enter Password: ";
    string pass = getValidatedPassword();

    bool verified = false;

    if (userType == "customer")
    {
        CustomerModel* cm = m_model->getCustomerModel();
        verified = cm->verifyUser(id, pass);
    }
    else if (userType == "admin")
    {
        AdminModel* am = m_model->getAdminModel();
        verified = am->verifyUser(id, pass);
    }
    else
    {
        cout << "Unknown user type.\n";
        return -1;
    }

    if (!verified)
    {
        cout << "Login failed. Invalid ID or password.\n";
        return -1;
    }

    cout << "Login successful.\n";
    return id;
}

bool AuthenticateUser::registerUser(const string& userType)
{
    cout << "\n--- " << userType << " REGISTRATION ---\n";

    cout << "Enter ID: ";
    int id = getValidatedInt();

    cout << "Enter Name: ";
    string name = getValidatedName();

    cout << "Enter Password: ";
    string pass = getValidatedPassword();

    cout << "Enter Phone: ";
    string phone = getValidatedPhone();

    bool success = false;

    if (userType == "customer")
    {
        CustomerModel* cm = m_model->getCustomerModel();
        success = cm->createCustomer(id, name, pass, phone);
    }
    else if (userType == "admin")
    {
        AdminModel* am = m_model->getAdminModel();
        success = am->createAdmin(id, name, pass, phone);
    }
    else
    {
        cout << "Unknown user type.\n";
        return false;
    }

    if (!success)
        cout << "Registration failed (DB error). Map entry may still exist.\n";
    else
        cout << "Registration successful.\n";

    return success;
}

void AuthenticateUser::handleCustomer(int id)
{
    CustomerModel* cm = m_model->getCustomerModel();
    Customer* c = cm->loadCustomer(id);
    if (!c)
    {
        cout << "Unable to load customer.\n";
        return;
    }
    c->customerMenu();
}

void AuthenticateUser::handleAdmin(int id)
{
    AdminModel* am = m_model->getAdminModel();
    Admin* a = am->loadAdmin(id);
    if (!a)
    {
        cout << "Unable to load admin.\n";
        return;
    }
    a->adminMenu();
}
