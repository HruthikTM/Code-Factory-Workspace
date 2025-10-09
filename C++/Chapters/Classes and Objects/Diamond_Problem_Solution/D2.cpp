#include "D2.h"

D2::D2()
{
    cout << "D2 constructor is called" << endl;
}

void D2::set_z()
{
    cout << "Enter the value of z: ";
    cin >> z;
}

void D2::get_z()
{
    cout << "z = " << z << endl;
}

D2::~D2()
{
    cout << "D2 destructor is called" << endl;
}
