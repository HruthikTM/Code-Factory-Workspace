#ifndef BASE_H
#define BASE_H

#include <iostream>

using namespace std;

class Base
{
public:
    Base(int a);

    ~Base();

    void showBaseClassValue()
    {
        cout << "Base value: " << m_a << endl;
    }

private:
    int m_a;
};

#endif // BASE_H
