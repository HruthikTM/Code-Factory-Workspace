#include "Customer.h"

Customer::Customer( map<int, Package*>& packageMap) : m_reader(SqlReader::getInstance()),m_packageMap(packageMap)
{
}

Customer::Customer(int id, const string& name, const string& password, const string& phone, map<int, Package*>& packageMap) : m_reader(SqlReader::getInstance()),m_packageMap(packageMap)
{
    setId(id);
    setName(name);
    setPassword(password);
    setPhoneNumber(phone);
}

Customer::~Customer() {}

void Customer::customerMenu()
{
    int choice;
    while (true)
    {
        cout << "\n=========== CUSTOMER DASHBOARD ===========\n";
        cout << "1. View Available Packages\n"
                "2. Select and Pay for Package\n"
                "3. View Profile\n"
                "4. Edit Profile\n"
                "5. View Subscribed Packages\n"
                "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case DisplayAvaliablePackages:
            displayAvailablePackages();
            break;
        case Select_and_Pay:
            selectPackage();
            break;
        case ViewProfile:
            viewProfile();
            break;
        case EditProfile:
            editProfile();
            break;
        case View_Subscribed_Package:
        {
            int id;
            cout << "Enter your Customer ID: ";
            cin >> id;
            if (!m_reader->getCustomerPackages(id))
                cout << "Error retrieving your subscriptions.\n";
            break;
        }
        case Logout:
            cout << "Logging out...\n";
            return;
        default:
            cout << "Invalid choice.\n";
        }
    }
}

void Customer::displayAvailablePackages()
{
    if (m_packageMap.empty())
    {
        cout << "No packages available.\n";
        return;
    }

    cout << "\n========== AVAILABLE PACKAGES ==========\n";
    for (auto &pack : m_packageMap)
    {
        cout << "\nPackage ID: " << pack.second->getPackageId()
        << " | Name: " << pack.second->getPackageName()
        << " | Total Price: " << pack.second->getTotalPrice() << "\n";

        cout << "Channels:\n";
        for (auto& chPair : pack.second->getChannelMap())
        {
            Channels* ch = chPair.second;
            cout << "  - " << ch->getChannelId() << "." << ch->getChannelName()
                 << " (" << ch->getPrice() << ")\n";
        }

        cout << "--------------------------------------------\n";
    }
}

bool Customer::selectPackage()
{
    if (m_packageMap.empty())
    {
        cout << "No packages available.\n";
        return false;
    }

    int pkgId;
    cout << "Enter Package ID to subscribe: ";
    cin >> pkgId;

    auto it = m_packageMap.find(pkgId);
    if (it == m_packageMap.end())
    {
        cout << "Invalid Package ID.\n";
        return false;
    }

    Package *selectedPackage = it->second;
    cout << "\nYou selected package '" << selectedPackage->getPackageName() << "' costing " << selectedPackage->getTotalPrice() << endl;

    char confirm;
    cout << "Do you want to proceed with payment? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
        return payment(selectedPackage);

    cout << "Payment cancelled.\n";
    return false;
}

bool Customer::payment(Package *selectedPackage)
{
    double amount = selectedPackage->getTotalPrice();
    cout << "\n==== PAYMENT PORTAL ====\n";
    cout << "Total amount to be paid: " << amount << "\n";
    cout << "Select Payment Method:\n"
         << "1. Credit/Debit Card\n"
         << "2. UPI\n";

    int method;
    cin >> method;

    string ref;
    cout << "Enter Transaction Reference ID: ";
    cin >> ref;

    cout << "\nProcessing payment...\n";
    cout << "Payment successful! " << amount << " paid to DTH Service Provider.\n";
    cout << "You have successfully subscribed to " << selectedPackage->getPackageName() << ".\n";

    int customerId;
    cout << "Enter your Customer ID to save subscription: ";
    cin >> customerId;

    string methodStr = (method == 1) ? "Card" : "UPI";

    if (m_reader->insertCustomerPackage(customerId, selectedPackage->getPackageId(), ref, methodStr))
        cout << "Subscription saved successfully in the database.\n";
    else
        cout << "Failed to save subscription.\n";


    return true;
}

void Customer::viewProfile()
{
    int id;
    cout << "Enter your Customer ID: ";
    cin >> id;
    m_reader->getUser("customer", id);
}

void Customer::editProfile()
{
    int id;
    string name, phone, password;
    cout << "Enter your Customer ID: ";
    cin >> id;
    cout << "Enter new Name: ";
    cin >> name;
    cout << "Enter new Phone: ";
    cin >> phone;
    cout << "Enter new Password: ";
    cin >> password;

    if (m_reader->updateUser("customer", id, name, phone, password))
        cout << "Profile updated successfully!\n";
    else
        cout << "Failed to update profile.\n";
}
