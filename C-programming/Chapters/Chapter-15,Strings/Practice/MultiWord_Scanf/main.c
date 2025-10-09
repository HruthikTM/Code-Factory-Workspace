#include <stdio.h>

int main()
{

    char name[25];
    printf("Enter the Name: ");
    scanf("%[^\n]s",name);

    printf("%s ",name);

}
