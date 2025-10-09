#include <iostream>

using namespace std;

class Sample
{
private:
    int a, b;
public:
    void operator - ();
    void display();

    Sample()
    {
        a=10;
        b=20;
    }
};

void Sample :: operator -()
{
    a=-a;
    b=-b;
}

void Sample :: display()
{
    cout << "a = " << a << "\nb = " << b << endl;
}

int main()
{
    Sample s;
    s.display();
    - s;
    s.display();
    return 0;
}
