#ifndef HEADAREA_H
#define HEADAREA_H

#include <iostream>
using namespace std;

#include "Hair.h"
#include "Face.h"
using namespace std;

class HeadArea
{
public:
    HeadArea();
    ~HeadArea();


    Hair *m_hair;
    Face *m_face;



};

#endif // HEADAREA_H
