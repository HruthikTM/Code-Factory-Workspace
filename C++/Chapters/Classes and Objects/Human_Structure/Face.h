#ifndef FACE_H
#define FACE_H

#include <iostream>
using namespace std;

#include "Eyes.h"
#include "Noes.h"
#include "Ears.h"
#include "Lips.h"
#include "Mouth.h"

class Face
{
public:
    Face();
    ~Face();

    Eyes *m_eyes;
    Noes *m_noes;
    Ears *m_ears;
    Lips *m_lips;
    Mouth *m_mouth;
};

#endif // FACE_H
