#include <iostream>
#include <map>
using namespace std;

template <class T1, class T2>


class Box
{
private:
    T1 value1;
    T2 value2;

    map<T1 , T2> m_map;

public:
    Box(T1 v1, T2 v2) : value1(v1), value2(v2)
    {

    }

    void show()
    {
        cout << "Value-1: " << value1 << endl;
        cout << "Value-2: " << value2 << endl;
    }
};

int main()
{
    Box<int,float> b1(10,5.5f);
    // Box<double> b2(5.5);
    // Box<string> b3("Hello");

    b1.show();
    // b2.show();
    // b3.show();
}
