#ifndef D_H
#define D_H

#include<iostream>
#include "B.h"
#include "C.h"
#include "A.h"
using namespace std;

class D : public B, public C
{

public:
    D();
    ~D();

    // void display();
};



#endif // D_H
