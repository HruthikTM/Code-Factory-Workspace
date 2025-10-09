#include <iostream>

using namespace std;
template <class T>
void show(T a,T b)
{
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}

int main()
{
    show(2.6,5.6);
    show(1,2);
    show(9.6,8.4);
    return 0;
}
