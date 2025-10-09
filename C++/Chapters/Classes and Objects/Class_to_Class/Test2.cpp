#include "Test2.h"

Test2::Test2(Test1 t1)
{
    a = t1.get_x();
    b = t1.get_y();
    cout << "Contructor" << endl;
}


Test2::~Test2()
{
    cout << "Destructor" << endl;
}

void Test2 :: display()
{
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}
