#include <iostream>

using namespace std;

class A
{
private :
    float a,b;
public:
    A()
    {
        a = 6.5;
        b = 7;
    }

    operator int ()
    {
        float x = (a + b);
        return x;
    }
};

int main()
{
    A a;
    int b = a;
    cout << "b=" << b << endl;
    return 0;
}
