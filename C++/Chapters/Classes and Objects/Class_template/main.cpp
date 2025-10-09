#include <iostream>

using namespace std;

template <class T>
class A
{
private:
    T a, b;
public:
    A(T x,T y)
    {
        a=x;
        b=y;
    }

    void show()
    {
        cout << "a=" << a << endl;
        cout << "b=" << b << endl;
    }
};

int main()
{
    A <int> a1 (1,2);
    a1.show();
    A <double> a2 (1.1, 2.2);
    a2.show();
    A <string> a3 ("hruthik","tm");
    a3.show();
    return 0;
}
