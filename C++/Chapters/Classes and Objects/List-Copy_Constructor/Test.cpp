#include "Test.h"

Test::Test()
{
    cout << "Test constructor" << endl;
}

Test::Test(int x, int y)
{
    cout << "Test para constructor" << endl;

    m_a = x;
    m_b = y;
}

Test::Test(const Test &obj): m_a(obj.m_a), m_b(obj.m_b)
{
    cout << "Test copy constructor" << endl;
}

Test::~Test()
{
    cout << "Test destructor" << endl;
}
