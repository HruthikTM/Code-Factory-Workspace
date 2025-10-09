#ifndef BUYITEMS_H
#define BUYITEMS_H

#include "Item.h"
#include "Vegetable.h"

class BuyItems
{
private:
    vector <Item*> items;
public:
    BuyItems();
    ~BuyItems();

    void buyItems();
    void displayMenu();
};

#endif // BUYITEMS_H
