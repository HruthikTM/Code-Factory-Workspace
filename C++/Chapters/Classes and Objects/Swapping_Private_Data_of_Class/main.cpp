#include <iostream>

using namespace std;

#include "a.h"
#include "b.h"

void exchange(A &x, B &y)
{
    int temp = x.value1;
    x.value1 = y.value2;
    y.value2 = temp;
}

int main()
{
    A a;
    B b;

    a.inData(10);
    b.inData(20);

    cout << "value before swapping" << "\n";
    a.display();
    b.display();

    exchange(a, b);

    cout << "value after swapping" << "\n";
    a.display();
    b.display();

    return 0;
}
