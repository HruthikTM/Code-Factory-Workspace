#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class BankAccount
{

    string accountHolderName;
    double balance;
    int accountNumber;

public:
    BankAccount();

    BankAccount(string name, double d, int accNo);

    ~BankAccount();

    void deposite(double amt);

    void showBalance();
};

#endif // BANKACCOUNT_H
