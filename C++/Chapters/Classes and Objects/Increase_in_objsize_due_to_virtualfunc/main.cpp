#include <iostream>

using namespace std;

class A
{
public :
    void virtual display()
    {
        cout << "ABC" << endl;
    }
};

class B : public A
{
public :
    void display()
    {
        cout << "XYZ" << endl;
    }
};


int main()
{
    A a;
    B b;
    cout << sizeof(b) <<endl;
    return 0;
}
