#ifndef D2_H
#define D2_H

#include "B1.h"

class D2 : virtual public B1
{
protected:
    int z;
public:
    D2();
    void set_z();
    void get_z();
    ~D2();
};

#endif
