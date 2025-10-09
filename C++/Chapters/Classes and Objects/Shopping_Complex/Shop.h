#ifndef SHOP_H
#define SHOP_H

#include<iostream>
using namespace std;

class Shop
{
private:
    string m_shopId;
    string m_shopName;

public:
    Shop(string shopId,string shopName);
    virtual ~Shop();
};

#endif // SHOP_H
