#include <iostream>

using namespace std;

template <class T1, class T2>
class A
{
private:
    T1 a;
    T2 b;
public:
    A(T1 x,T2 y)
    {
        a = x;
        b = y;
    }
    void show();
};

int main()
{
    A <char,double> a1 ('a',23.98);
    a1.show();
    A <int,float> a2 (56,3.14);
    a2.show();
    return 0;
}


template<class T1, class T2>
void A<T1, T2>::show()
{
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}
