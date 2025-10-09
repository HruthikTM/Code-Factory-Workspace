#include "D3.h"

D3::D3()
{
    cout << "D3 constructor is called" << endl;
}

void D3::setValues()
{
    set_x();
    set_y();
    set_z();
}

void D3::printProduct()
{
    product = x * y * z;
    cout << "Product = " << product << endl;
}

D3::~D3()
{
    cout << "D3 destructor is called" << endl;
}
