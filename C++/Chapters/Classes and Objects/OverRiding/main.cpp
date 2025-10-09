#include <iostream>

using namespace std;

class B
{
public:
    void display()
    {
        cout << "fhdjhdj" << endl;
    }
};

class D : public B
{
public:
    void display()
    {
        cout << "shhhshshsh" << endl;
    }
};

int main()
{
    // D d;
    // d.display();

    // B b;
    // b.display();

    D d;
    d.B :: display();

    return 0;
}
