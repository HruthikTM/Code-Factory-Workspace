#include "Derived.h"

Derived::Derived(int a,int b) : Base(a), m_b(b)
{
    cout << "Derived class constuctor is called" << endl;
}


Derived::~Derived()
{
    cout << "Derived class destructor is called" << endl;
}
