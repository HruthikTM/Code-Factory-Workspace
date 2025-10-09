#include <iostream>
#include "A.h"
#include "D.h"

using namespace std;

int main()
{

    // D *a1 = new D;
    // a1->B::display();

    // delete a1;


    A *a = (B *)new D;
    a->display();

    delete a;



    // B b;
    // D d;

    // B *aptr;

    // aptr = &d;

    // aptr->display();

    return 0;
}
