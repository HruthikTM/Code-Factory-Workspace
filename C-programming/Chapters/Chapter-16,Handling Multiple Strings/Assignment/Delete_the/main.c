#include <stdio.h>
#include <string.h>

int main() {
    char sentence[201], result[201];
    char word[10];
    int i = 0, j = 0, k = 0;

    printf("Enter a sentence (max 200 characters): ");
    scanf(" %[^\n]", sentence);
    while (sentence[i] != '\0') {

        if (sentence[i] != ' ' && sentence[i] != '\t' && sentence[i] != '\n') {
            word[k++] = sentence[i];
        } else {
            word[k] = '\0';

            if (strcmp(word, "the") != 0) {

                for (int m = 0; word[m] != '\0'; m++){
                    result[j++] = word[m];
                }
                result[j++] = sentence[i];
            } else if (sentence[i] != ' ') {
                result[j++] = sentence[i];
            }
            k = 0;
        }
        i++;
    }

    word[k] = '\0';
    if (strcmp(word, "the") != 0) {
        for (int m = 0; word[m] != '\0'; m++)
            result[j++] = word[m];
    }

    result[j] = '\0';

    printf("Sentence after deleting 'the': %s\n", result);

    return 0;
}
