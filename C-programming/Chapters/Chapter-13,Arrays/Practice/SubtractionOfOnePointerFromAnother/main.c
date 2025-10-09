#include <stdio.h>

int main()
{
    int arr[]={10,20,30,40,50};
    int *i,*j;

    i=&arr[1];
    j=&arr[2];

    printf("%d %d\n",j-1,*j-*i);
    return 0;
}
