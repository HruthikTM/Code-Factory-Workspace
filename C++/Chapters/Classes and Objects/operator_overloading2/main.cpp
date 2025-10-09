#include <iostream>

using namespace std;

class Sample
{
private:
    int a;
    int b;
public:
    Sample operator - ();
    void display();
    Sample()
    {
        a=1;
        b=2;
    }
};

Sample Sample :: operator -()
{
    Sample s3;
    s3.a=-a;
    s3.b=-b;
    return s3;
}

void Sample :: display()
{
    cout << "a = " << a <<endl;
    cout << "b = " << b <<endl;
}

int main()
{
    Sample s1,s2;

    s1.display();
    s2.display();
    s2 = -s1;
    s1.display();
    s2.display();
    return 0;
}
