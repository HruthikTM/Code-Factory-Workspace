#include <stdio.h>

int main()
{
    int num[]={23,46,71,90,53};
    for(int i=0;i<=4;i++)
    {
        printf("Element No.%d\t",i);
        printf("Value=%d\t",num[i]);
        printf("Address=%u\n",&num[i]);


    }

       return 0;
}
