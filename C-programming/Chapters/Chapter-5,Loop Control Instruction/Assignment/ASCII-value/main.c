#include <stdio.h>

int main()
{
    int i = 0;
    printf("ASCII Value\tCharacter Equivalent\n");

    while (i <= 255) {
        printf("%d\t\t%c\n", i, i);
        i++;
    }
1`
    return 0;
}
