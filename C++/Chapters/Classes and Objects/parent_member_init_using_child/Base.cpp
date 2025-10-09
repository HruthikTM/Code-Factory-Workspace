#include "Base.h"

Base::Base(int a) : m_a(a)
{
    cout << "Base class constuctor is called" << endl;
}

Base::~Base()
{
    cout << "Base class destructor is called" << endl;
}
