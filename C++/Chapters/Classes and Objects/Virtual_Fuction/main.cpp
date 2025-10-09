#include <iostream>

using namespace std;

class Base
{
public :
    void virtual display()
    {
        cout << "I love India" << endl;
    }
};

class Derived : public Base
{
public :
    void display()
    {
        cout << "I love Mysore" << endl;
    }
};

int main()
{
    Base b;
    Derived d;

    Base *bp;

    bp = &d;
    bp->display();
    return 0;
}
