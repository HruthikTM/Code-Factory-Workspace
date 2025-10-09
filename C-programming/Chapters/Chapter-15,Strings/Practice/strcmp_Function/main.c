#include <stdio.h>
#include <string.h>

int main()
{
    char str1[]="Jerry";
    char str2[]="Ferry";

    int i=strcmp(str1,"Jerry");

    int j=strcmp(str1,str2);


    int k=strcmp(str1,"Jerry boy");

    printf("%d %d %d\n",i,j,k);

    return 0;
}
