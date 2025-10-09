#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout << "base const called" << endl;
    }

    virtual ~A()
    {
        cout << "base dest called" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "derived const called" << endl;
    }

    ~B()
    {
        cout << "derived dest called" << endl;
    }
};

int main()
{
    A *aptr;
    aptr = new B;
    delete aptr;

    return 0;
}
