#include <stdio.h>


int fibonacci(int n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    printf("First 25 Fibonacci numbers:\n");
    for (int i = 1; i <= 25; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
