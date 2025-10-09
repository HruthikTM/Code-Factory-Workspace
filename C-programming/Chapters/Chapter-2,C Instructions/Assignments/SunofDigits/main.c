#include <stdio.h>

int main()
{
    int num, digit, sum = 0;
    printf("Enter the 5 digit number: ");
    scanf("%d", &num);

    if (num < 10000 || num > 99999) {
        printf("Invalid input! Please enter a 5-digit number.\n");
        return 1;
    }

    while (num > 0) {
        for(int i=0;i<=5;i++){
        digit = num % 10;
        sum += digit;
        num /= 10;
        }
    }

    printf("Sum of digits: %d\n", sum);

    return 0;
}
