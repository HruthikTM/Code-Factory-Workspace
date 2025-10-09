#include "derived.h"

derived::derived(int a) : base(a)
{
    cout << "Derived constructor" << endl;
}


derived::~derived()
{
    cout << "Derived destructor" << endl;
}


void derived :: display()
{
    cout << "derived" << endl;
}
