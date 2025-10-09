#include "base.h"

base::base(int a)
{
    cout << "Base constructor" << endl;
}



base::~base()
{
    cout << "Base destructor" << endl;
}

void base :: display()
{
    cout << "base" << endl;
}
