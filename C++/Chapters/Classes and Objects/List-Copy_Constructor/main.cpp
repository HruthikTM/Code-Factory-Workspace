#include <iostream>
#include <list>
#include "Test.h"

using namespace std;

int main()
{
    Test* tst1 = new Test(10,20);
    Test* tst2 = new Test(30,40);
    // Test test2(60,40);

    Test num1(10,20);

    list<Test*> t1;
    t1.push_back(tst1);
    t1.push_back(tst2);
    t1.push_back(&num1);

    delete tst1;
    delete tst2;
    return 0;
}
