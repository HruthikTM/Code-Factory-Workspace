#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item
{
public:
    Item();
    virtual ~Item();

    void setItemName(string name);
    string getItemName();
    void setItemQty(float qty);
    float getItemQty();
    void setItemPrice(float price);
    float getItemPrice();

    virtual float calculateRate() = 0;
    virtual void displayBill() = 0;

private:
    string m_name;
    float m_qty;
    float m_price;


};

#endif // ITEM_H
