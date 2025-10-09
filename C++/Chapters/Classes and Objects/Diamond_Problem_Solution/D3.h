#ifndef D3_H
#define D3_H

#include "D1.h"
#include "D2.h"

class D3 : public D1, public D2
{
private:
    int product;
public:
    D3();
    void setValues();
    void printProduct();
    ~D3();
};

#endif
