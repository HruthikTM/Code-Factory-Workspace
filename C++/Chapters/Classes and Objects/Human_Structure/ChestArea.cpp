#include "ChestArea.h"

ChestArea::ChestArea()
{
    cout << "Chest Area Constructor" << endl;
    m_chest = new Chest;
    m_stomach = new Stomach;
}

ChestArea::~ChestArea()
{
    cout << "Chest Area Destructor" << endl;
}
