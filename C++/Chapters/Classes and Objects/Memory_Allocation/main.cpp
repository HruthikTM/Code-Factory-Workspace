#include <iostream>
#include "NewDelete.h"

using namespace std;



int main()
{
    NewDelete *ptr1 = new NewDelete;
    // delete ptr1;

    NewDelete *ptr2 = (NewDelete *)malloc(sizeof(NewDelete));
    free(ptr2);

    return 0;


}
