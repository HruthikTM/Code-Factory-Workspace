#include <stdio.h>
#include <string.h>
#define FOUND 1
#define NOTFOUND 0

int main()
{
    char masterlist[6][10]=
    {
        "akshay",
        "parag",
        "raman",
        "srinivas",
        "gopal",
        "rajesh"
    };






    int flag,a;
    char yourname[10];

    printf("Enetr your Name: ");
    scanf("%s",yourname);


    flag=NOTFOUND;
    for(int i=0;i<=5;i++)
    {
        a=strcmp(&masterlist[i][0],yourname);

        a=strcmp(names[i],yourname);

        if(a==0)
        {
            printf("Welcome,you entered place");
            flag=FOUND;
            break;
        }
    }

    if(flag==NOTFOUND)
    {
        printf("NOT ALLOWED");
    }

    return 0;


}
