#include <stdio.h>

int main()
{
    int c,d;

    printf("Enter the values od C and D: ");
    scanf("%d%d",&c,&d);

    c=c+d;
    d=c-d;
    c=c-d;

    printf("Value of C: %d\n",c);
    printf("Value of D: %d\n",d);
}
