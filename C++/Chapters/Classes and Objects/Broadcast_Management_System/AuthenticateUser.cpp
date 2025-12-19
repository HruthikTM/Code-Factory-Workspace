#include "AuthenticateUser.h"

AuthenticateUser::AuthenticateUser(map<int, Admin*>& adminMap, map<int, Customer*>& customerMap)
    : m_adminMap(adminMap), m_customerMap(customerMap)
{
    m_sqlReader = SqlReader::getInstance();
    m_sqlReader->createUserTables();
}

AuthenticateUser::~AuthenticateUser() {}

int AuthenticateUser :: getValidatedInt()
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
}

string AuthenticateUser :: getValidatedName()
{
    string input;
    while (true)
    {
        getline(cin, input);

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

        cout << "Invalid name! Enter alphabets only.\n";
    }
}

string AuthenticateUser :: getValidatedPhone()
{
    string input;
    while (true)
    {
        cin >> input;

        bool valid = true;
        if (input.size() != 10)
            valid = false;
        else
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

string AuthenticateUser :: getValidatedPassword()
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


bool AuthenticateUser::registerUser(const string& userType)
{
    cout << "\n===== " << (userType == "admin" ? "ADMIN" : "CUSTOMER") << " REGISTRATION =====\n";

    cout << "Enter User ID: ";
    int id = getValidatedInt();

    cout << "Enter Name: ";
    string name = getValidatedName();

    cout << "Enter Password: ";
    string password = getValidatedPassword();

    cout << "Enter Phone Number: ";
    string phone = getValidatedPhone();

    if (m_sqlReader->userExists(userType, phone))
    {
        cout << "User already exists with this phone number!\n";
        return false;
    }

    if (m_sqlReader->insertUser(userType, id, name, password, phone))
    {
        cout << "Registered successfully as " << userType << "!\n";
        return true;
    }

    cout << "Registration failed.\n";
    return false;
}

string AuthenticateUser::login(const string& userType)
{
    cout << "\n===== " << (userType == "admin" ? "ADMIN" : "CUSTOMER") << " LOGIN =====\n";

    cout << "Enter User ID: ";
    int id = getValidatedInt();

    cout << "Enter Password: ";
    string password = getValidatedPassword();

    if (!m_sqlReader->userExists(userType, id))
    {
        cout << "User not registered. Please register first.\n";
        return "";
    }

    if (m_sqlReader->verifyUser(userType, id, password))
    {
        cout << "Login successful! Welcome " << id << " (" << userType << ")\n";
        return userType;
    }

    cout << "Invalid credentials.\n";
    return "";
}

