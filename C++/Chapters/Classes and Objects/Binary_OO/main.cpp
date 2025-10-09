#include <iostream>
using namespace std;

class Sample
{

private:
    int a,b;

public:
    Sample operator + (Sample &);
    void display()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
    Sample(int x, int y)
    {
        a = x;
        b = y;
    }
    Sample()
    {

    }

};

Sample Sample :: operator +(Sample &s)
{
    cout << "s1 = " << a << endl;
    cout << "s2 = " << s.a << endl;
    Sample k;
    k.a = a + s.a;
    k.b = b + s.b;
    return k;
}

int main()
{
    Sample s1(5, 6);
    Sample s2(6, 7);
    Sample s3;
    s3 = s1 + s2;
    s3.display();
    return 0;
}
