#include "PolicyInterface.h"

PolicyInterface::PolicyInterface()
{
    cout << "Policy Interface const is called" << endl;
}

PolicyInterface::~PolicyInterface()
{
    cout << "Policy Interface dest is called" << endl;
}

void PolicyInterface::getPolicy()
{
    HealthInsurance hi;

    EliteInsurance* ei = nullptr;
    PremiumInsurance* pi = nullptr;

    int choice, policyChoice;
    float amount;
    int age, term, number;
    string name;
    double coverage;
    bool benefits;

    cout << "Choose Insurance Type:\n" << ELITE << ". Elite Insurance\n" << PREMIUM << ". Premium Insurance\n" << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case ELITE:
        ei = new EliteInsurance;

        cout << "Enter customer name: ";
        cin >> name;
        cout << "Enter phone number: ";
        cin >> number;

        hi.setName(name);
        hi.setNumber(number);

        cout << "Customer: " << hi.getName() << " | Phone: " << hi.getNumber() << endl;

        cout << "Choose Policy Type:\n" << ELITE_BASIC << ". Amount + Age\n" << ELITE_EXTENDED << ". Amount + Age + Term + Coverage\n" << "Enter choice: ";
        cin >> policyChoice;

        cout << "Enter amount: ";
        cin >> amount;
        cout << "Enter age: ";
        cin >> age;

        switch (policyChoice)
        {
        case ELITE_BASIC:
            ei->HealthInsurance::policy(amount, age);
            break;

        case ELITE_EXTENDED:
            cout << "Enter term (years): ";
            cin >> term;
            cout << "Enter coverage: ";
            cin >> coverage;
            ei->policy(amount, age, term, coverage);
            break;

        default:
            cout << "Invalid policy choice for Elite Insurance!" << endl;
            break;
        }

        delete ei;
        break;

    case PREMIUM:
        pi = new PremiumInsurance;

        cout << "Enter customer name: ";
        cin >> name;
        cout << "Enter phone number: ";
        cin >> number;

        hi.setName(name);
        hi.setNumber(number);

        cout << "Customer: " << hi.getName() << " | Phone: " << hi.getNumber() << endl;

        cout << "Choose Policy Type:\n" << PREMIUM_BASIC << ". Amount + Age\n" << PREMIUM_EXTENDED << ". Amount + Age + Term + Coverage + Benefits\n" << "Enter choice: ";
        cin >> policyChoice;

        cout << "Enter amount: ";
        cin >> amount;
        cout << "Enter age: ";
        cin >> age;

        switch (policyChoice)
        {
        case PREMIUM_BASIC:
            pi->HealthInsurance::policy(amount, age);
            break;

        case PREMIUM_EXTENDED:
            cout << "Enter term (years): ";
            cin >> term;
            cout << "Enter coverage: ";
            cin >> coverage;
            cout << "Are benefits applied? (1 for Yes, 0 for No): ";
            cin >> benefits;
            pi->policy(amount, age, term, coverage, benefits);
            break;

        default:
            cout << "Invalid policy choice for Premium Insurance!" << endl;
            break;
        }

        delete pi;
        break;

    default:
        cout << "Invalid insurance type choice!" << endl;
        break;
    }
}
