#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 6
#define MAX_LEN 100

int main() {
    char *str[] = {
        "We will teach you how to...",
        "Move a mountain",
        "Level a building",
        "Erase the past",
        "Make a million",
        "...all through C!"
    };

    char str1[MAX_LEN], str2[MAX_LEN];

    printf("Enter string to search (str1): ");
    scanf("%s", str1);

    printf("Enter replacement string (str2): ");
    scanf("%s", str2);

    for (int i = 0; i < SIZE; i++) {
        char *pos = strstr(str[i], str1);
        if (pos) {
            char newStr[MAX_LEN] = {0};
            int index = pos - str[i];

            strncpy(newStr, str[i], index);
            newStr[index] = '\0';

            strcat(newStr, str2);
            strcat(newStr, pos + strlen(str1));

            str[i] = strdup(newStr);
        }
    }

    printf("\nUpdated strings:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}
