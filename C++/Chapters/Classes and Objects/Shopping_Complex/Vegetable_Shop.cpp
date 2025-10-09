#include "Vegetable_Shop.h"

Vegetable_Shop::Vegetable_Shop(string id, string name) : Shop(shopId,shopName)
{
    cout << "Vegetable Shop Constructor" << endl;
}

Vegetable_Shop::~Vegetable_Shop()
{
    cout << "Vegetable Shop Destructor" << endl;
}

void Vegetable_Shop:: addOrUpdateVegetable(const string &name, double qty, double price)
{
    Vegetable_Items key(name,0,0);
    auto item = veges.find(key);

    if(item != veges.end())
    {
        Vegetable_Items updated = *item;
        veges.erase(item);
        updated.addQty(qty);
        updated.setItemPrice(price);
        veges.insert(updated);
        cout << "Upadted " << name << " with +" << qty << "qty and price " << price << endl;
    }
    else
    {
        veges.insert(Vegetable_Items(name,qty,price));
        cout << "Inserted new Item" << name << endl;
    }


}
