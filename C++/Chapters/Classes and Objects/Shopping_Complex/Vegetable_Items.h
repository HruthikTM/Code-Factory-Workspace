#ifndef VEGETABLE_ITEMS_H
#define VEGETABLE_ITEMS_H

#include<iostream>
#include"Item.h"
using namespace std;

class Vegetable_Items : public Item
{
public:
    Vegetable_Items();
    ~Vegetable_Items();
};

struct CompareByName
{
    bool operator()(const Vegetable_Items& a, const Vegetable_Items& b)const
    {
        return a.getItemName() < b.getItemName();
    }
};

#endif // VEGETABLE_ITEMS_H
