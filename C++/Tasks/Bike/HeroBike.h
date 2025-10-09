#ifndef HEROBIKE_H
#define HEROBIKE_H

#include "Bike.h"
#include <string>

class HeroBike : public Bike
{

public:
    HeroBike(string model, int cc, float milage, double price, bool abs);

    ~HeroBike();

    void display() const;

private:
    bool m_abs;
};



#endif // HEROBIKE_H
