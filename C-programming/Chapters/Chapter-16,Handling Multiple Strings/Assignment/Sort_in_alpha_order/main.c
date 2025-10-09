#include <stdio.h>
#include <string.h>

#define SIZE 5
#define MAX_LEN 100

int main() {
    char names[SIZE][MAX_LEN];
    char temp[MAX_LEN];

    printf("Enter %d names:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%s", names[i]);
    }


    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("Sorted names:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
