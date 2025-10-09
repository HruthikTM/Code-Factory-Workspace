#include <iostream>
#include "derived.h"
using namespace std;

int main()
{
    Derived obj;
    obj.fun();
    Base base;
    base.fun();
    cout << "Hello World!" << endl;
    return 0;
}
