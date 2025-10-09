#include <iostream>
#include "derived.h"
#include "base.h"

using namespace std;

int main()
{

    derived d(10);
    d.display();

    //base :: display();

    //base :: d.display();

    //d.base::display();

    // base *ptr  = new derived(10);
    // ptr->display();
    return 0;
}
