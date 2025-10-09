#include <stdio.h>
#include <string.h>


void reverse(char *str) {
    int i, j;
    char temp;
    int len = strlen(str);

    for(i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {

    char str0[] = "To err is human...";
    char str1[] = "But to really mess things up...";
    char str2[] = "One needs to know C!!";

    char *s[] = { str0, str1, str2 };

    int n = sizeof(s) / sizeof(s[0]);


    for(int i = 0; i < n; i++) {
        reverse(s[i]);
    }


    for(int i = 0; i < n; i++) {
        printf("%s\n", s[i]);
    }

    return 0;
}
