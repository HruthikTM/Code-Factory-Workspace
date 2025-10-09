#include "HeroBike.h"

HeroBike::HeroBike(string model, int cc, float milage, double price, bool abs) : Bike(model, cc, milage, price), m_abs(abs)
{
    cout << "HeroBike object created" << endl;
}

HeroBike::~HeroBike()
{
    cout << "HeroBike object destroyed" << endl;
}

void HeroBike::display() const
{
    // int abs2;
    // abs2 = 10;
    //Bike::display();

    cout << "Model: " << getModel() << ", CC: " << getCC() << ", Milage: " << getMilage() << ", Price: " << getPrice() << ", ABS: " << (m_abs ? "Yes" : "No") << endl;
}
