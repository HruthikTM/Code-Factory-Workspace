#include <iostream>

using namespace std;

class A
{
protected:
    int a = 10;
public:
    void display_A()
    {
        cout << a << endl;
    }
};

class B : public A
{
protected :
    int b = 20;
public:

    //display_A();

    void display_B()
    {
        cout << b << endl;
    }
};

class C : public A
{
protected :
    int c = 30;
public:

    //display_A();

    void display_C()
    {
        cout << c << endl;
    }
};

class D : public B, public C
{
protected :
    int d = 40;
public:

    //display_A();

    void display_D()
    {
        cout << d << endl;
    }
};

int main()
{
    D d;

    // d.a = 50;
    // d.display_A();

    //d.b = 50;
    //d.display_B();

    return 0;
}
