#ifndef VEGETABLE_H
#define VEGETABLE_H

#include "Item.h"

class Vegetable : public Item
{
public:
    Vegetable();
    ~Vegetable();

    float calculateRate();
    void displayBill();
};

#endif // VEGETABLE_H
