#include <stdio.h>

int main()
{
    char ch;
    printf("Enter the character: ");
    scanf("%c",&ch);

    ch>='a'&&ch<='z'
        ?printf("Lower case\n")
        :printf("Invalid character\n");

    ((ch < '0') || (ch > '9' && ch < 'A') || (ch > 'Z' && ch < 'a') ||(ch > 'z'))
        ? printf("Special Symbol.\n")
        : printf("Invalid Symbol\n");

    return 0;
}
