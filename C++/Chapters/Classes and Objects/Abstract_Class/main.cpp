#include <iostream>

using namespace std;

class Base
{
public:
    void virtual display() = 0;
};

class Derived : public Base
{
public:
    void display()
    {
        cout << "Computer" << endl;
    }
};

int main()
{
    //Base b; // can't create object for abstrsct class
    Base *bptr;
    Derived d;
    bptr = &d;
    bptr->display();
    return 0;
}
