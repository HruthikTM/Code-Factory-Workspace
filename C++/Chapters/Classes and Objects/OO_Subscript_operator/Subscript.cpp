#include "Subscript.h"

Subscript::Subscript()
{
    cout<<"Const is called"<<endl;
}

Subscript :: Subscript(int *s)
{
    for (int i = 0; i < 5; i++)
        a[i] = s[i];
    cout<<"Const is called"<<endl;
}

Subscript::~Subscript()
{
    cout<<"Dest is called"<<endl;
}

int Subscript ::operator [](int k)
{
    return (a[k]);
}
