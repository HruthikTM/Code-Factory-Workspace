#include "Face.h"

Face::Face()
{
    cout << "Face Constructor" << endl;
    m_eyes = new Eyes;
    m_ears = new Ears;
    m_noes = new Noes;
    m_lips = new Lips;
    m_mouth = new Mouth;
}

Face::~Face()
{
    cout << "Face Destructor" << endl;
}
