#include <stdio.h>

int main()
{
    char name[10];
    printf("Enter your Name: ");
    gets(name);

    puts("Hello!");
    puts(name);

    return 0;
}
