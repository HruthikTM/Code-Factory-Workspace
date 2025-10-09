#include <iostream>
using namespace std;

class A
{
public:
    int a;
    int b;

    void func();
};

int main()
{
    A abc;

    cout << "Address of a: " << &abc.a << endl;
    cout << "Address of b: " << &abc.b << endl;

    cout << "Address of object: " << &abc << endl;

    return 0;
}
