#include <iostream>

#include "A.h"
#include "B.h"
#include "C.h"

using namespace std;


int main()
{
    A a;
    B b;
    C c;

    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    return 0;
}
