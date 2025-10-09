#include <iostream>
#include "StringConcat.h"

int main()
{
    StringConcat s1("Final");
    StringConcat s2("Boss");
    StringConcat s3(50);
    s3 = s1 + s2;
    s3.display();
    return 0;
}
