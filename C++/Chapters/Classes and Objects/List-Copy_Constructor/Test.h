#ifndef TEST_H
#define TEST_H

#include <iostream>


using namespace std;

class Test
{
private:
    int m_a;
    int m_b;
public:
    Test();
    Test(int x, int y);
    Test (const Test& obj);
    ~Test();
};

#endif // TEST_H
