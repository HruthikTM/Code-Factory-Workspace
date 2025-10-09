#include <stdio.h>

int main()
{
    char names[][10]=
        {
        "akshay",
        "parag",
        "raman",
        "srinivas",
        "gopal",
        "rajesh"
        };


    char temp;

    printf("Original:%s%s\n",&names[2][0],&names[3][0]);

    for(int i=0;i<=9;i++)
    {
        temp=names[2][i];
        names[2][i]=names[3][i];
        names[3][i]=temp;
    }

    printf("New:%s%s\n",&names[2][0],&names[3][0]);

    return 0;
}
