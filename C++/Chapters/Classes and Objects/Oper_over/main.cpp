#include <iostream>

using namespace std;

class Test
{

private:
    int *a;

public:

    Test(int value = 0)
    {
        a = new int(value);
    }

    ~Test(){
        delete a;
    }

    // Test& operator = (const Test &other)
    // {
    //     return Test(*(this->a) = other.a);
    // }

    Test& operator = (const Test &other)
    {
        if(this == &other)
            return *this;

        delete a;

        a = new int(*other.a);

        return *this;
    }

};



int main()
{
    Test t1(10);
    Test t2;
    t2 = t1;
    return 0;
}
