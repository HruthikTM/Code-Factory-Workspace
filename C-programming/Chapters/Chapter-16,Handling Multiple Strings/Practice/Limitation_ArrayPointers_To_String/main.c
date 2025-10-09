#include <stdio.h>

int main()
{
    char *names[6];
    for(int i=0;i<=5;i++)
    {
        printf("Enter name: ");
        scanf("%s",names[i]);
    }

    return 0;
}
