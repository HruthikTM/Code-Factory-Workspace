#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write();
void read();

FILE *fp;
char s[80];

int main()
{
    int choice;
    while (1) {
        printf("\n----- POEM -----\n");
        printf("1. Write POEM\n");
        printf("2. REad POEM\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            write();
            break;
        case 2:
            read();
            break;
        case 3:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("INVALID CHOICE!\n");

        }

    }

    return 0;
}


void write(){


    fp=fopen("poem.txt","w");
    if(fp == NULL)
    {
        puts("Cant open file");
        exit(1);
    }

    printf("Enter a few Lines of text:\n");
    while(strlen (gets(s)) > 0)
    {
        fputs(s,fp);
        fputs("\n",fp);
    }
    fclose(fp);
}

void read()
{
    fp=fopen("poem.txt","r");
    if(fp == NULL)
    {
        puts("Cant open file");
        exit(1);
    }

    while(fgets(s,79,fp)!=NULL)
        printf("%s",s);

    printf("\n");
    fclose(fp);
}
