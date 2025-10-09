#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;


    fp=fopen("abc.txt","r");
    if(fp==NULL)
    {
        puts("Cant open file");
        exit(1);
    }

    while(1)
    {
        ch= fgetc(fp);
        if(ch == EOF)
            break;
        printf("%c",ch);
    }
    printf("\n");
    fclose(fp);
    return 0;
}
