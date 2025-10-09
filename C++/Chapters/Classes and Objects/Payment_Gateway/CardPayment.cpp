#include "CardPayment.h"

CardPayment::CardPayment()
{
    cout << "Card Payment Constructor" << endl;
}

CardPayment::~CardPayment()
{
    cout << "Card Payment Destructor" << endl;
}

void CardPayment::payNow(float amount)
{
    cout << "Processing Card payment of Rs." << amount << " ..." << endl;
    cout << "Payment Successful" << endl;

    GenerateBill *bill = new GenerateBill();
    bill->setAmount(amount);
    bill->setMode("Card");

    int choice;
    do
    {
        cout << "\nChoose an option:\n"
             << "1. Save to CSV\n"
             << "2. Save to Text\n"
             << "3. Save to SQL\n"
             << "4. Display Bill\n"
             << "5. Exit\n";
        cin >> choice;
        switch(choice)
        {
        case 1:
            bill->setFormat("CSV");
            bill->save();
            break;
        case 2:
            bill->setFormat("Text");
            bill->save();
            break;
        case 3:
            bill->setFormat("SQL");
            bill->save();
            break;
        case 4:
            if (bill->getFormat().empty())
                cout << "No format selected. Please save the bill first." << endl;
            else
                bill->display();
            break;
        case 5:
            cout << "Done with billing options" << endl;
            delete bill;
            return;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while(true);
}

void CardPayment::cancel()
{
    cout << "Card Payment Cancelled" << endl;
}
