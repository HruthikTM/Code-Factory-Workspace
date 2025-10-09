#include <stdio.h>

void pass(int *,int *);

int main()
{
    int a,b;
    printf("Enter value of A: ");
    scanf("%d",&a);

    printf("Enter value of B: ");
    scanf("%d",&b);

    printf("Before value of A=%d and B=%d\n",a,b);

    pass(&a,&b);

    printf("After Value of A=%d and B=%d\n",a,b);

    return 0;
}

void pass(int *x,int *y)
{

    printf("Enter the value of X: ");
    scanf("%d",*&x);

    printf("Enter the value of Y: ");
    scanf("%d",*&y);
}
