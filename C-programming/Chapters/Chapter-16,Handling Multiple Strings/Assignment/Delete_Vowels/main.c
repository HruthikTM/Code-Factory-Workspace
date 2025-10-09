#include <stdio.h>

int isVowel(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + ('a' - 'A');
    }
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    char sentence[81], result[81];
    int  j = 0;

    printf("Enter a sentence (max 80 characters): ");
    scanf(" %[^\n]", sentence);


    for (int i = 0; sentence[i] != '\0'; i++) {
        if (!isVowel(sentence[i])) {
            result[j++] = sentence[i];
        }
    }

    result[j] = '\0';

    printf("Sentence after deleting vowels: %s\n", result);

    return 0;
}
