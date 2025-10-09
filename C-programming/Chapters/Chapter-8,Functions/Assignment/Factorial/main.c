#include <stdio.h>

int factorial(int);

int main()
{
    int num,f;
    printf("Enter the number: ");
    scanf("%d",&num);
    f=factorial(num);
    printf("Factorial of %d is %d\n",num,f);
    return 0;
}

int factorial(int num){
    int fact=1;
    for(int i=1;i<=num;i++)
    {
        fact=fact*i;
    }
    return fact;
}
