#include "Item.h"

Item::Item() : m_qty(0), m_price(0)
{
    cout << "Item Constructor is called" << endl;
}

Item::~Item()
{
    cout << "Item Destructor is called" << endl;
}

void Item::setItemName(string name)
{
    m_name = name;
}

string Item::getItemName()
{
    return m_name;
}

void Item::setItemQty(float qty)
{
    m_qty = qty;
}

float Item::getItemQty()
{
    return m_qty;
}

void Item::setItemPrice(float price)
{
    m_price = price;
}

float Item::getItemPrice()
{
    return m_price;
}
