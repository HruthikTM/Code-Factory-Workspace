#include "Item.h"

Item::Item() : m_itemName(0), m_itemPrice(0)
{
    cout << "Item Constructor" << endl;
}

Item :: Item(string itemName,double itemQty,double itemPrice) : m_itemName(itemName), m_itemQty(itemQty), m_itemPrice(itemPrice)
{

}

Item::~Item()
{
    cout << "Item Destructor" << endl;
}

string Item::getItemName()
{
    return m_itemName;
}

double Item::getItemQty()
{
    return m_itemQty;
}

double Item::getItemPrice()
{
    return m_itemPrice;
}

void Item:: addQty(double itemQty)
{
    m_itemQty += itemQty;
}

void Item:: setItemPrice(double itemPrice)
{
    m_itemPrice = itemPrice;
}
