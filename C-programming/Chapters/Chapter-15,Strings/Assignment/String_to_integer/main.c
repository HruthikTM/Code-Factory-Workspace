#include <stdio.h>
#include <string.h>


int stringToInteger(const char* str) {
    if (str == NULL || *str == '\0') {
        return 0;
    }

    int result = 0;
    int i = 0;


    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            int digit = str[i] - '0';
            result = result * 10 + digit;
        } else {
            printf("Warning: Non-digit character '%c' found in string. Conversion stopped.\n", str[i]);
            return 0;
        }
        i++;
    }
    return result;
}

int main(){
    const char* str1 = "abc";
    printf("\"%s\" -> %d\n", str1, stringToInteger(str1));
    return 0;
}

