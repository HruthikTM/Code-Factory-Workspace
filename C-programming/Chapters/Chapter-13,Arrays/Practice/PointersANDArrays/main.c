#include <stdio.h>

int main()
{
    int i=3,*x;
    float j=1.5,*y;
    char k='c',*z;


    printf("Value of i=%d\n",i);
    printf("Value of j=%f\n",j);
    printf("Value of k=%c\n",k);

    x=&i;
    y=&j;
    z=&k;

    printf("Original Address at x=%u\n",x);
    printf("Original Address at y=%u\n",y);
    printf("Original Address at z=%u\n",z);

    x++;
    y++;
    z++;

    printf("New Address at x=%u\n",x);
    printf("New Address at y=%u\n",y);
    printf("New Address at z=%u\n",z);

    return 0;
}
