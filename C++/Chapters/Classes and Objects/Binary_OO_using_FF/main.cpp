#include <iostream>
#include "Sample.h"

using namespace std;



int main()
{
    Sample s1(3,4);
    Sample s2(5,6);
    Sample s3;
    s3 = s1 + s2;
    s3.display();

    return 0;
}
