#include <iostream>

using namespace std;

#include "abc.h"
#include "xyz.h"

void add(XYZ ob1, ABC ob2)
{
    std::cout << "Sum of 2 objects of 2 classes= " << ob1.data + ob2.data;
}

int main()
{
    ABC a;
    XYZ x;
    a.setValue(10);
    x.setValue(10);
    add(x,a);

    return 0;
}
