#ifndef CHESTAREA_H
#define CHESTAREA_H

#include <iostream>
#include "Chest.h"
#include "Stomach.h"

using namespace std;

class ChestArea
{
public:
    ChestArea();
    ~ChestArea();

    Chest *m_chest;
    Stomach *m_stomach;
};

#endif // CHESTAREA_H
