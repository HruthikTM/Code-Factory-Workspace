#include <stdio.h>

int main()
{
    int n, num, max, min;

    printf("Enter the number of inputs: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number of inputs.\n");
        return 1;
    }

    printf("Enter number 1: ");
    scanf("%d", &num);
    min = max = num;

    for (int i = 2; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);

        if (num < min)
            min = num;
        if (num > max)
            max = num;
    }

    printf("Smaller Number: %d\n", min);
    printf("Larger Number: %d\n", max);
    printf("Range: %d\n", max - min);

    return 0;
}
