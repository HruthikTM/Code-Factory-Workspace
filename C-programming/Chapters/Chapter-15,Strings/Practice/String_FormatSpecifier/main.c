#include <stdio.h>

int main()
{
    char name[5];
    printf("Enter Your Name: ");
    scanf("%s",name);

    printf("Hello %s\n",name);
    printf("Size of name array: %lu\n", sizeof(name));

    return 0;
}
