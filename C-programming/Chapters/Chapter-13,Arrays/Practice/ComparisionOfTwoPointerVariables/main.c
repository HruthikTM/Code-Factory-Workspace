#include <stdio.h>

int main()
{
    int arr[]={10,20,30,40,50};
    int *i,*j;

    i=&arr[3];
    j=(arr+3);

    if(i==j)
        printf("Two pointers point to same location\n");
    else
        printf("Two pointers do not point to same location\n");

    return 0;
}
