#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *names[6];
    char n[50];
    int len;
    char *p;
    for(int i=0;i<=5;i++)
    {
        printf("Enter name: ");
        scanf("%s",n);

        len=strlen(n);
        p=(char *)malloc(len+1);
        strcpy(p,n);
        names[i]=p;
    }

    for(int i=0;i<=5;i++)
    {
        printf("%s\n",names[i]);
    }

    return 0;
}
