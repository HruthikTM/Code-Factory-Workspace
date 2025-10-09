#ifndef VEGETABLE_SHOP_H
#define VEGETABLE_SHOP_H

#include<iostream>
#include<set>
#include "Shop.h"
#include "Vegetable_Items.h"
using namespace std;

class Vegetable_Shop : public Shop
{
private:
     set<Vegetable_Items, CompareByName>veges;
public:
    Vegetable_Shop(string id, string name);
    ~Vegetable_Shop();

    void addOrUpdateVegetable(const string& name,double qty,double price);

};

#endif // VEGETABLE_SHOP_H
