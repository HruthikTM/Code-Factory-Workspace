#include "CustomerModel.h"
#include <iostream>

CustomerModel::CustomerModel(PackageModel* pkgModel)
{
    m_reader = SqlReader::getInstance();
    m_pkgModel = pkgModel;
}

int CustomerModel::getValidatedInt()
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

string CustomerModel::getValidatedName()
{
    string input;
    cin.ignore();
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

string CustomerModel :: getValidatedPassword()
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

string CustomerModel::getValidatedPhone()
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

string CustomerModel::getValidatedString()
{
    string s;
    cin >> ws;
    getline(cin, s);
    return s;
}

void CustomerModel::displayAvailablePackages()
{
    m_pkgModel->displayPackages();
}

bool CustomerModel::selectPackage(int customerId)
{
    auto& pkgMap = m_pkgModel->getPackageMap();

    if (pkgMap.empty())
    {
        cout << "No packages available.\n";
        return false;
    }

    cout << "Enter Package ID: ";
    int pkgId = getValidatedInt();

    if (!pkgMap.count(pkgId))
    {
        cout << "Invalid package.\n";
        return false;
    }

    Package* pkg = pkgMap[pkgId];

    cout << "\nSelected Package: " << pkg->getPackageName()
         << "\nTotal Price: " << pkg->getTotalPrice() << endl;

    cout << "Proceed to payment? (y/n): ";
    char op;
    cin >> op;

    if (op == 'y' || op == 'Y')
        return payment(customerId, pkg);

    return false;
}

bool CustomerModel::payment(int customerId, Package* pkg)
{
    cout << "\n=== PAYMENT PORTAL ===\n";
    cout << "Total amount: " << pkg->getTotalPrice() << "\n";
    cout << "Payment Modes:\n1. Card\n2. UPI\n";
    cout << "Select: ";

    int method = getValidatedInt();
    string mode = (method == 1 ? "Card" : "UPI");

    cout << "Enter Transaction Reference: ";
    string txn = getValidatedString();

    cout << "Payment successful!\n";

    return m_reader->insertCustomerPackage(customerId, pkg->getPackageId(), txn, mode);
}

void CustomerModel::viewSubscribedPackages(int customerId)
{
    m_reader->getCustomerPackages(customerId);
}

void CustomerModel::viewProfile(int id)
{
    m_reader->getUser("customer", id);
}

void CustomerModel::editProfile(int id)
{
    string name, phone, pass;

    cout << "\nEnter New Name: ";

    name = getValidatedName();

    cout << "Enter New Phone: ";
    phone = getValidatedPhone();

    cout << "Enter New Password: ";
    pass = getValidatedPassword();

    m_reader->updateUser("customer", id, name, phone, pass);
}


bool CustomerModel::verifyUser(int id, const string& password)
{
    return m_reader->verifyUser("customer", id, password);
}

Customer* CustomerModel::loadCustomer(int id)
{
    if (customerExists(id))
        return getCustomer(id);

    int uid;
    string uname, upass, uphone;

    bool found = m_reader->getUser("customer", id, uid, uname, upass, uphone);
    if (!found)
        return nullptr;

    Customer* c = new Customer();
    c->setId(uid);
    c->setName(uname);
    c->setPassword(upass);
    c->setPhoneNumber(uphone);

    addCustomer(uid, c);
    return c;

}

bool CustomerModel::createCustomer(int id, const string& name, const string& pass, const string& phone)
{
    Customer* c = new Customer();
    c->setId(id);
    c->setName(name);
    c->setPassword(pass);
    c->setPhoneNumber(phone);

    addCustomer(id, c);

    bool dbSuccess = m_reader->insertUser("customer", id, name, pass, phone);

    return dbSuccess;
}

bool CustomerModel::addCustomer(int id, Customer* customer)
{
    m_customerMap[id] = customer;
    return true;
}

Customer* CustomerModel::getCustomer(int id)
{
    return m_customerMap.count(id) ? m_customerMap[id] : nullptr;
}

bool CustomerModel::customerExists(int id)
{
    return m_customerMap.count(id) > 0;
}
