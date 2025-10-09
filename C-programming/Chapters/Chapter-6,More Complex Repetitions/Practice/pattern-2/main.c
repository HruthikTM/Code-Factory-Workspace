#include <stdio.h>

int main() {
    int i, j, start;

    for (i = 7; i >= 1; i--) {

        for (j = 0; j < i; j++) {
            printf("%c ", 'A' + j);
        }


        for (j = 0; j < (7 - i) * 2-1; j++) {
            printf("  ");
        }


        if (i == 7) {
            start = i - 2;
        } else {
            start = i - 1;
        }


        for (j = start; j >= 0; j--) {
            printf("%c ", 'A' + j);
        }

        printf("\n");
    }

    return 0;
}
