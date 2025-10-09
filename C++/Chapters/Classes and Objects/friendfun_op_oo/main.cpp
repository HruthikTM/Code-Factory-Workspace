#include <iostream>

using namespace std;

class Sample
{
private:
    int a;
    int b;
public:
    friend void operator - (Sample &);
    void display();

    Sample()
    {
        a=6;
        b=7;
    }
};

void operator - (Sample &x)
{
    x.a=-x.a;
    x.b=-x.b;
}

void Sample :: display()
{
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

int main()
{
    Sample s;
    s.display();
    -s;
    s.display();
    return 0;
}
