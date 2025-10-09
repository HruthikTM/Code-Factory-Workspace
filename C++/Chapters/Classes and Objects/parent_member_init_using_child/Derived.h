#ifndef DERIVED_H
#define DERIVED_H

#include "Base.h"
#include <iostream>

using namespace std;

class Derived : public Base
{
public:
    Derived(int a,int b);

    ~Derived();

    void showDerivedClassValue()
    {
        showBaseClassValue();
        cout << "Derived value: " << m_b << endl;
    }

private:
    int m_b;
};

#endif // DERIVED_H
