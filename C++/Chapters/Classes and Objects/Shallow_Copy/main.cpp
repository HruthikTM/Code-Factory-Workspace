#include <iostream>
#include "Box.h"
using namespace std;

int main()
{
    Box b1,b2;

    b1.setDimention(10,20,30);
    b1.showData();
    cout << endl;

    //Copy made through assignment operator
    b2 = b1;
    b2.showData();
    cout << endl;

    //Copy made through copy constructor
    Box b3 = b1;
    b3.showData();
    cout << endl;

    b1.deleteBreadth();
    b3.showData();

    return 0;
}
