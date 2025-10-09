#include "Vegetable.h"

Vegetable::Vegetable() : Item()
{
    cout << "Vegetable Constructor is called" << endl;
}

Vegetable::~Vegetable()
{
    cout << "Vegetable Destructor is called" << endl;
}

float Vegetable::calculateRate()
{
    return (getItemQty() / 1000.0f) * getItemPrice();
}

void Vegetable::displayBill()
{
    cout << "Item Name: " << getItemName() << "\nQuantity: " << getItemQty() << " g" << "\nPrice per Kg: Rs " << getItemPrice() << "\nTotal Cost: Rs " << calculateRate() << endl;
}
