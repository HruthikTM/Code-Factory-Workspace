#include <iostream>
using namespace std;

template<class T1, class T2>
class Add
{
private:
    T1 a;
    T2 b;
public:
    Add(T1 x, T2 y);
    ~Add();

    auto add();
};

template<class T1, class T2>
Add<T1, T2>::Add(T1 x, T2 y) : a(x), b(y)
{
    cout << "Constructor" << endl;
}

template<class T1, class T2>
Add<T1, T2>::~Add()
{
    cout << "Destructor" << endl;
}

template<class T1, class T2>
auto Add<T1, T2>::add()
{
    return a + b;
}

int main()
{
    Add<int,double> a1(80, 7.64);
    cout << a1.add() << endl;

    Add<char,int> a2('d', 96);
    cout << a2.add() << endl;

    return 0;
}

