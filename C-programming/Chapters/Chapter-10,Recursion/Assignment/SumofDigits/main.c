#include <stdio.h>

int sumOfDigits(int);

int main()
{

    int num;
    printf("Enter a 5-digit number: ");
    scanf("%d",&num);

    if (num < 10000 || num > 99999) {
        printf("Invalid input! Please enter a 5-digit number\n");
        return 1;
    }

    int sum=sumOfDigits(num);
    printf("Sum of given digit is:%d\n",sum);

    return 0;

}

int sumOfDigits(int n)
{
    if(n==0)
        return 0;

    return (n%10)+sumOfDigits(n/10);
}
