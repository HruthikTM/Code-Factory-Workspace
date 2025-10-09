#include <iostream>

using namespace std;

class Base{
private:
    int m_x;

public:
    Base(int x);
    ~Base();
    void push();
};

class Derived : public Base
{
private :
    int y;
public:
    void pull();
};

int main()
{
    Base b;
    Derived d;

    cout << sizeof(b) << endl;
    cout << sizeof(d) << endl;
    return 0;
}
