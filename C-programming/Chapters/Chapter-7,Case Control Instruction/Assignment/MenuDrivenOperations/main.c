#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, num, i, fact, isPrime;


    while (1) {
        printf("\nMenu:\n");
        printf("1. Factorial of a number\n");
        printf("2. Prime or not\n");
        printf("3. Odd or even\n");
        printf("4. Exit\n");

        printf("Enter the choice: ");
        scanf("%d", &choice);

        printf("Enter a Number: ");
        scanf("%d", &num);



        switch (choice) {

        case 1:
            // printf("Enter a Number: ");
            // scanf("%d", &num);
            fact = 1;
            if (num < 0) {
                printf("Factorial not defined for negative numbers.\n");
                break;
            }
            for (i = 1; i <= num; i++) {
                fact = fact * i;
            }
            printf("Factorial of number %d is %d\n", num, fact);
            break;

        case 2:
            // printf("Enter a Number: ");
            // scanf("%d", &num);
            if (num <= 1) {
                printf("%d is not a prime number\n", num);
                break;
            }
            isPrime = 1;
            for (i = 2; i <= num / 2; i++) {
                if (num % i == 0) {
                    isPrime = 0;
                    break;
                }
            }
            if (isPrime)
                printf("%d is a prime number\n", num);
            else
                printf("%d is not a prime number\n", num);
            break;

        case 3:
            //printf("Enter a Number: ");
            // scanf("%d", &num);
            if (num % 2 == 0)
                printf("Even number: %d\n", num);
            else
                printf("Odd number: %d\n", num);
            break;

        case 4:
            printf("Exiting the program.\n");
            exit(0);

        default:
            printf("INVALID CHOICE!\n");
        }
    }

    return 0;
}
