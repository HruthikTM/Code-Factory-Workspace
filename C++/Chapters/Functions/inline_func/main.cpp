#include <iostream>

using namespace std;

inline float mul(float x, float y)
{
    return(x*y);
}

inline float div(float m, float n)
{
    return(m/n);
}

int main()
{

    float a = 10, b = 2;

    cout << mul(a,b) << endl;
    cout << div(a,b) << endl;

    return 0;
}
