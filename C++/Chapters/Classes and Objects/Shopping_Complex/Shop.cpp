#include "Shop.h"

Shop::Shop(string shopId,string shopName) : m_shopId(shopId) , m_shopName(shopName)
{
    cout << "Shop Constructor" << endl;
}

Shop::~Shop()
{
    cout << "Shop Destructor" << endl;
}
