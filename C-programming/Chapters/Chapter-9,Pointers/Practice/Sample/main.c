#include <stdio.h>

int main()
{
    int a=10,*p;

    *p=a;
    printf("%d",*p);


    *p=15;

    printf("%d",*p);


    return 0;
}
