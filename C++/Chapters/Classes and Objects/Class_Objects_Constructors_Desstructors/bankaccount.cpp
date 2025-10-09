#include "bankaccount.h"

BankAccount::BankAccount()
{
    cout<<"BankAccount default constructor"<<endl;
}
BankAccount::BankAccount(string name, double b, int accNo)
{
    accountHolderName = name;
    balance = b;
    accountNumber = accNo;

    cout << "Account created for client: " << accountNumber << "having name: " << accountHolderName << endl;
}

BankAccount ::~BankAccount()
{
    cout << "Account closed for: " << accountNumber << endl;
}

void BankAccount :: deposite(double amt)
{
    balance += amt;
    cout << "Deposited " << amt << endl;
}

void BankAccount :: showBalance()
{
    cout << "Balance: " << balance << endl;
}
