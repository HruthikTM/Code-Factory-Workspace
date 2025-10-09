#ifndef STRINGCONCAT_H
#define STRINGCONCAT_H

#include <iostream>
#include <string.h>
using namespace std;

class StringConcat
{
public:
    StringConcat();

    ~StringConcat();

    StringConcat operator + (StringConcat &);

    StringConcat(char *p);

    StringConcat (int len);

    void display();

private:
    char *original;

};

#endif // STRINGCONCAT_H
