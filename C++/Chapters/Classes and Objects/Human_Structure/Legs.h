#ifndef LEGS_H
#define LEGS_H

#include <iostream>
using namespace std;

#include <Fingers.h>

class Legs
{
public:
    Legs();
    ~Legs();

    Fingers *m_fingers;
};

#endif // LEGS_H
