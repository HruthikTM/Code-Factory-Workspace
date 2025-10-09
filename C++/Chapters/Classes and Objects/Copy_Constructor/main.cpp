#include <iostream>

using namespace std;

class Code{
    int id;

public:
    Code()
    {

    }

    Code(int a)
    {
        id = a;
    }

    Code(Code &x)
    {
        id = x.id;
    }

    void display()
    {
        cout << id;
    }

};

int main()
{
    Code obj1(100);

    Code obj2(obj1);

    Code obj3 = obj1;

    Code obj4;
    obj4 = obj1;

    obj1.display();
    cout << "\n";
    obj2.display();
    cout << "\n";
    obj3.display();
    cout << "\n";
    obj4.display();

    return 0;
}
