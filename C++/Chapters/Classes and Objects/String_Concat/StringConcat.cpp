#include "StringConcat.h"

StringConcat::StringConcat()
{
    cout << "StringConcat Class Const called" << endl;
}

StringConcat::~StringConcat()
{
    cout << "StringConcat Class Dest called" << endl;
    // delete original;
}

StringConcat::StringConcat(char *p)
{
    cout << "StringConcat Class Const called" << endl;
    int len = strlen(p);
    original = new char[len + 1];
    strcpy(original, p);

}

StringConcat::StringConcat (int len)
{
    cout << "StringConcat Class Const called" << endl;
    original = new char[len];
}

StringConcat StringConcat :: operator + (StringConcat &s)
{
    StringConcat k;
    k.original = new char[50];
    strcpy(k.original, original);
    strcat(k.original, " ");
    strcat(k.original, s.original);
    return k;
}

void StringConcat :: display()
{
    cout << original << endl;
    cout << "Calling Display Function" << endl;
}
