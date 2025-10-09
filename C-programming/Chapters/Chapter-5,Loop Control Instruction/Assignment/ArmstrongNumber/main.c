#include <stdio.h>

int main()
{
    int num, temp, rem, res;

    printf("Armstrong Numbers from 1 to 500:\n");

    for (num = 1; num <= 500; num++) {
        temp = num;
        res = 0;

        while (temp != 0) {
            rem = temp % 10;
            res = res + rem * rem * rem;
            temp = temp / 10;
        }

        if (res == num) {
            printf("%d\n", num);
        }
    }

    return 0;
}
