#include <iostream>

using namespace std;

class Test
{

public:

    void add(int a, int b)
    {
        cout << "ABC" << endl;
    }

    void add(int a, float b)
    {
        cout << "XYZ" << endl;
    }

    // void add1(int a, float b)
    // {
    //     cout << "XYZ1" << endl;
    // }
};

int main()
{
    Test t;
    //t.add(10,10);
    //t.add('a',1);
    t.add(10,20.5f);

    //t.add1(10,0.1);
    return 0;
}
