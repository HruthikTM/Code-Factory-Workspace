#include <iostream>

using namespace std;

class A{
public:
    void display()
    {
        cout << "i am hruthik" << endl;
    }
};

class B : public A{
public:
    void display()
    {
        A :: display();
        cout << "i am finalboss" << endl;
    }
};

int main()
{
    A a;
    B b;
    b.display();
    return 0;
}
