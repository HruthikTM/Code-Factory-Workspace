#include <iostream>

using namespace std;
// template <class T1, class T2>
// void show(T1 a, T2 b)
template <class SUB>
void show(SUB a, int b)
{
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}

int main()
{
    // show(9.7,65);
    // show("hruthik",6854.963);
    show("ertyu",65);
    show(89.45,75);
    return 0;
}
