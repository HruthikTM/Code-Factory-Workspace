#include <stdio.h>


int runningSum(int n) {
    if (n == 1)
        return 1;
    return n + runningSum(n - 1);
}

int main() {
    int n = 25;
    int sum = runningSum(n);
    printf("Running sum of first %d natural numbers is: %d\n", n, sum);
    return 0;
}
