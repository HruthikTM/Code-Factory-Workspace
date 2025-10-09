#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *fp;
    char another='Y';
    struct emp
    {
        char name[10];
        int age;
        float bs;
    };

    struct emp e;

    fp=fopen("EMP.txt","a");

    if(fp==NULL)
    {
        puts("Cant open file");
        exit(1);
    }

    while(another == 'Y')
    {
        printf("\nEnter name, age, basic salary:");
        scanf("%s%d%f",e.name,&e.age,&e.bs);
        fprintf(fp,"%s%d%f\n",e.name,e.age,e.bs);

        printf("Add another Employee (Y/N):");
        fflush(fp);
        another=getche();
    }
     fp=fopen("EMP.txt","r");


    while(fscanf(fp,"%s%d%f\n",e.name,&e.age,&e.bs )!=EOF)
        printf("%s%d%f\n",e.name,e.age,e.bs);
    fclose(fp);
    return 0;
}
