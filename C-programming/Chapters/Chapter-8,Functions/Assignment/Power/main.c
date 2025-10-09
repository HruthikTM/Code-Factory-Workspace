#include <stdio.h>

//int power(int, int);

int main() {
    int base, expo, pow;

    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &expo);

    pow = power(base, expo);

    printf("Value of %d raised to %d: %d\n", base, expo, pow);

    return 0;
}

int power(int a, int b) {
    int res = 1;
    while (b != 0) {
        res = res * a;
        --b;
    }
    return res;
}
