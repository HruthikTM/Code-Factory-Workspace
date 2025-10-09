#include <stdio.h>
#include <string.h>

int main()
{
    char arr[]="Heloo";

    int len1,len2;

    len1=strlen(arr);
    len2=strlen("Good Morning");

    printf("String=%s length=%d\n",arr,len1);
    printf("String=%s length=%d\n","Good Morning",len2);

    return 0;
}


