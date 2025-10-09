#include "D1.h"

D1::D1()
{
    cout << "D1 constructor is called" << endl;
}

void D1::set_y()
{
    cout << "Enter the value of y: ";
    cin >> y;
}

void D1::get_y()
{
    cout << "y = " << y << endl;
}

D1::~D1()
{
    cout << "D1 destructor is called" << endl;
}
