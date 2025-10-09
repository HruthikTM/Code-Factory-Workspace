#ifndef ITEM_H
#define ITEM_H

class Item
{
private:
    string m_itemName;
    double m_itemQty;
    double m_itemPrice;
public:
    Item();
    Item(string itemName, double itemQty, double itemPrice);
    ~Item();

    string &getItemName();
    double getItemQty();
    double getItemPrice();

    void addQty(double itemQty);
    void setItemPrice(double itemPrice);

};

#endif // ITEM_H
