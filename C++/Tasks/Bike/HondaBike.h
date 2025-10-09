#ifndef HONDABIKE_H
#define HONDABIKE_H

#include "Bike.h"
#include <string>


class HondaBike : public Bike
{

public:
    HondaBike(string model, int cc, float milage, double price);

    ~HondaBike();

};

#endif // HONDABIKE_H
