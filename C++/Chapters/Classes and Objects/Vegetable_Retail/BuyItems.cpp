#include "BuyItems.h"
#include <iostream>

using namespace std;

BuyItems::BuyItems()
{
    cout << "Buy Items Constructor is called" << endl;
}

BuyItems::~BuyItems()
{
    for (Item* i : items)
        delete i;
    cout << "Buy Items Destructor is called" << endl;
}

void BuyItems::displayMenu()
{
    cout << "\nAvailable Items:\n";
    cout << "--------------------\n";
    cout << "1. Tomato (Rs 30 per kg)\n";
    cout << "2. Potato (Rs 50 per kg)\n";
    cout << "3. Carrot (Rs 40 per kg)\n";
    cout << "4. Onion (Rs 25 per kg)\n";
    cout << "5. Beans (Rs 60 per kg)\n";
    cout << "6. Exit\n";
}

void BuyItems::buyItems()
{
    while (true)
    {
        displayMenu();

        int choice;
        cout << "\nSelect a vegetable : ";
        cin >> choice;

        string name;
        float price;

        switch (choice)
        {
        case 1:
            name = "Tomato";
            price = 30.0f;
            break;
        case 2:
            name = "Potato";
            price = 50.0f;
            break;
        case 3:
            name = "Carrot";
            price = 40.0f;
            break;
        case 4:
            name = "Onion";
            price = 25.0f;
            break;
        case 5:
            name = "Beans";
            price = 60.0f;
            break;
        case 6:
            cout << "Exiting program" << endl;
            return;
        default:
            cout << "Invalid choice\n";
            continue;
        }

        Item* item = new Vegetable();
        item->setItemName(name);
        item->setItemPrice(price);

        float qty;
        cout << "Enter quantity for " << name << " (in grams): ";
        while (!(cin >> qty) || qty < 0)
        {
            cout << "Invalid quantity";
        }

        item->setItemQty(qty);
        item->calculateRate();
        item->displayBill();

        items.push_back(item);

        delete item;
    }
}
