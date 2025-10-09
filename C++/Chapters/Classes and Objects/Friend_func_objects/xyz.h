#ifndef XYZ_H
#define XYZ_H

#include "abc.h"

class XYZ
{
private:
    int data;
public:

    XYZ();

    void setValue(int value)
    {
        data = value;
    }

   friend void add(XYZ, ABC);
};


#endif // XYZ_H
