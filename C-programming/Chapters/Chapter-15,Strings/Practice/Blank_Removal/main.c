#include <stdio.h>
#include <string.h>

void replaceConsecutiveBlanks(char *str) {
    if (str == NULL || *str == '\0') {
    }

    int i, j;
    i = 0;
    j = 0;
    int blank_found = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            if (!blank_found) {
                str[j++] = ' ';
                blank_found = 1;
            }
        } else {
            str[j++] = str[i];
            blank_found = 0;
        }
        i++;
    }
    str[j] = '\0';
}

int main()
{
    char str[] = "Grim   return        to   the        planet       of               apes!!";
    printf("Original string : \"%s\"\n", str);
    replaceConsecutiveBlanks(str);
    printf("Modified string : \"%s\"\n", str);



    return 0;
}
