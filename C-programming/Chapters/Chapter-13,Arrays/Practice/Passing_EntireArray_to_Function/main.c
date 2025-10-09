#include <stdio.h>

void display(int *,int);


int main()
{
    int num[]={24,49,83,19,11,20};
    display(&num[0],6);
    return 0;
}


void display(int *j,int n)
{
    for(int i=0;i<=n-1;i++)
    {
        printf("Element=%d\n",*j);
        j++;
    }
}
