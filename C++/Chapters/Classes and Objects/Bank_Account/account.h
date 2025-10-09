#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account
{

    char name[10];
    int accNo;
    string accType;
    float balance;
public:
    Account();

    void enterDetails();
    void deposit(Account);
    void withdraw(Account);
    void showBalance(Account);
};

void Account :: enterDetails()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter Account No: ";
    cin >> accNo;
    cout << "Enter Account type: ";
    cin >> accType;
    cout << "Enter Initial Balance: ";
    cin >> balance;
}

void Account :: deposit(Account a1)
{
    float amt;

    cout << "Enter Amt to deposit: ";
    cin >> amt;

    balance = a1.balance + amt;
}

void Account :: withdraw(Account a1)
{
    float amt;

    cout << "Enter Amt to withdraw: ";
    cin >> amt;

    balance = a1.balance - amt;
}

void Account :: showBalance(Account a1)
{
    cout << "Name: " << name << "\n";
    cout << "Balance: " << balance << "\n";
}
#endif // ACCOUNT_H
