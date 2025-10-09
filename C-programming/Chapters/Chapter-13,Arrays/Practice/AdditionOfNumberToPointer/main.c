#include <stdio.h>

int main()
{
    int i=4,*j,*k;
    j=&i;
    j=j+1;
    j=j+9;
    k=j+3;

    printf("%d %d %d",i,&j,&k);
    return 0;
}
