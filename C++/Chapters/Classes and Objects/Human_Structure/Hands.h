#ifndef HANDS_H
#define HANDS_H

#include <iostream>
#include "Fingers.h"

class Hands
{
public:
    Hands();
    ~Hands();

    Fingers *m_fingers;
};

#endif // HANDS_H
