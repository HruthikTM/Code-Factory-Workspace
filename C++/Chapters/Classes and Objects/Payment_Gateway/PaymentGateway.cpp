#include "PaymentGateway.h"
#include "UPIPayment.h"
#include "CashPayment.h"
#include "CardPayment.h"

PaymentGateway::PaymentGateway()
{
    cout << "PaymentGateway Constructor" << endl;
}

PaymentGateway::~PaymentGateway()
{
    cout << "PaymentGateway Destructor" << endl;
}

void PaymentGateway::selectPaymentMode()
{
    while (true)
    {
        float amount;
        cout << "Enter amount: ";
        cin >> amount;

        cout << "Choose the mode of Payment\n"
             << "1. UPI\n"
             << "2. Card\n"
             << "3. Cash\n"
             << "4. Exit\n";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            PaymentGateway *ptr = new UPIPayment;
            ptr->payNow(amount);
            delete ptr;
            break;
        }
        case 2:
        {
            PaymentGateway *ptr = new CardPayment;
            ptr->payNow(amount);
            delete ptr;
            break;
        }
        case 3:
        {
            PaymentGateway *ptr = new CashPayment;
            ptr->payNow(amount);
            delete ptr;
            break;
        }
        case 4:
            cout << "Exit payment\n";
            return;
        default:
            cout << "Invalid Choice\n";
            break;
        }
    }
}
