#include <stdio.h>

int main()
{
    int num[]={12,84,72,62,17};
    int *j=&num[0];

    for(int i=0;i<=4;i++)
    {
        printf("Address=%u\t'",j);
        printf("Element=%d\n",*j);
        j++;
    }

    return 0;
}
