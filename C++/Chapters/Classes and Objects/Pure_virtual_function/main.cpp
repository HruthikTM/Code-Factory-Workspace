#include <iostream>

using namespace std;

class A
{
public:
    void virtual display() = 0;

};

class B : public A
{
public :
    void display()
    {
        cout << "ABC" << endl;
    }
};

int main()
{
    //cout << "Hello World!" << endl;
    A *aptr;

    //A a;
    B b;

    aptr = &b;
    aptr->display();
    return 0;
}
