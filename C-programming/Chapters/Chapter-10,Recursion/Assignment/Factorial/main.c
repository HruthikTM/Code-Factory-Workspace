#include <stdio.h>

int factorial(int );

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);

    int fact=factorial(num);

    printf("Factorial=%d\n",fact);

}

int factorial(int n)
{
    int f;

    if(n==1)
        return 1;
    else
        f=n*factorial(n-1);

    return f;

}
