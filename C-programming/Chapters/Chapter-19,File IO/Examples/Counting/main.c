#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    int no_of_characters = 0, no_of_blanks = 0, no_of_lines = 0;
    int vowels = 0, consonants = 0, special_chars = 0;

    fp = fopen("para.txt", "r");

    if (fp == NULL)
    {
        puts("Can't open File");
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        no_of_characters++;

        if (ch == ' ')
            no_of_blanks++;

        if (ch == '\n')
            no_of_lines++;

        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            vowels++;
        }
        else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            consonants++;
        }

        if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == ' ' || ch == '\n' || ch == '\t'))
        {
            special_chars++;
        }
    }

    fclose(fp);

    printf("Number of characters = %d\n", no_of_characters);
    printf("Number of blanks = %d\n", no_of_blanks);
    printf("Number of lines = %d\n", no_of_lines);
    printf("Number of vowels = %d\n", vowels);
    printf("Number of consonants = %d\n", consonants);
    printf("Number of special characters = %d\n", special_chars);

    return 0;
}
