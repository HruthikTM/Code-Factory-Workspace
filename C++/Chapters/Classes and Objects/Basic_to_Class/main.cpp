#include <iostream>

using namespace std;

class A
{
private:
    int a,b;
public:
    A()
    {

    }
    A(int x)
    {
        a = x + 5;
        b = x + 6;
    }
    void display()
    {
        cout << "a= " << a << "," << "b=" << b << endl;
    }
};


int main()
{
    A a;
    int k = 8;
    a = k;  //here k is source(basic type) and a is target(class type)
    a.display();
    return 0;
}
