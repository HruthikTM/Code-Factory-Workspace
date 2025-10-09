#ifndef D1_H
#define D1_H

#include "B1.h"

class D1 : virtual public B1
{
protected:
    int y;
public:
    D1();
    void set_y();
    void get_y();
    ~D1();
};

#endif
