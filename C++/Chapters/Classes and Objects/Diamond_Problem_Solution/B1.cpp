#include "B1.h"

B1::B1()
{
    cout << "B1 constructor is called" << endl;
}

void B1::set_x()
{
    cout << "Enter the value of x: ";
    cin >> x;
}

void B1::get_x()
{
    cout << "x = " << x << endl;
}

B1::~B1()
{
    cout << "B1 destructor is called" << endl;
}
