#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <iostream>
#include <string>

using namespace std;

class CreditCard
{
    string number, holder;

public:

    CreditCard(string n, string h)
    {
        number = n;
        holder = h;

        cout << "Card created for " << holder << endl;
    }

    ~CreditCard()
    {
        cout << "Card destroyed: " << holder << endl;
    }

    void swipe()
    {
        cout << "Card swiped " << endl;
    }

    void details()
    {
        cout << "Holder: " << holder << endl;
    }

};

#endif // CREDITCARD_H
