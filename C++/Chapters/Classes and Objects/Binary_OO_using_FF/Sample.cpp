#include "Sample.h"

Sample::Sample()
{
    cout<<"Zero args const called"<<endl;
}

Sample::Sample(int x, int y)
{
    a=x;
    b=y;
    cout<<"Two args const called"<<endl;
}

Sample::~Sample()
{
    cout<<"Dest called"<<endl;
}

Sample operator + (Sample &s1, Sample &s2)
{
    Sample s;
    s.a = s1.a + s2.a;
    s.b = s1.b + s2.b;
    return s;
}

void Sample :: display()
{
    cout << "A=" << a << endl;
    cout << "B=" << b << endl;
}
