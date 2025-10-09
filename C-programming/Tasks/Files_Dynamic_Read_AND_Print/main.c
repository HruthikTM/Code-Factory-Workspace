#include <stdio.h>
#include <stdlib.h>

FILE *fp;
char *ch;

void printContent();
void readContent();

int main()
{

    fp = fopen("para.txt","r");

    if(fp == NULL)
    {
        puts("Cant open file");
        exit(1);
    }



    return 0;
}

void printContent()
{
    while(1)
    {
        ch = fgetc(fp);
        if(ch == EOF)
            break;
        print("%c",ch);
    }

    fclose(fp);
}
