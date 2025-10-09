#include "Test1.h"

Test1::Test1()
{
    x = 6;
    y = 7;
    cout << "constructor" <<endl;
}

Test1::~Test1()
{
    cout << "destructor" <<endl;
}

int Test1 :: get_x()
{
    return x;
}

int Test1 :: get_y()
{
    return y;
}
