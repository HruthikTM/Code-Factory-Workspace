#include <iostream>
using namespace std;

class A {
private:
    int a;
protected:
    int b;
public:
    int c;

    A() : a(0), b(0), c(0)
    {

    }
    void showA()
    {
        cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    }
};

class B : public A
{
public:
    B()
    {
        //a = 40;
        b = 20;
        c = 30;
    }
};

class C : protected A
{
public:
    C()
    {
        //a = 40;
        b = 40;
        c = 50;
    }
};

class D : private A
{
public:
    D()
    {
        //a = 40;
        b = 60;
        c = 70;
    }
};

int main()
{
    B objB;
    C objC;
    D objD;

    cout << "Accessing B (public inheritance):" << endl;
    objB.c = 100;
    //objB.b = 700;
    // objB.a = 800;
    objB.showA();

    cout << "Accessing C (protected inheritance):" << endl;
    // objC.b = 300;
    // objC.showA();

    cout << "Accessing D (private inheritance):" << endl;


    return 0;
}
