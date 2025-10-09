#include<stdio.h>

int main()
{
    int avg,sum=0;
    int marks[30];

    for(int i=0;i<=29;i++)
    {
        printf("enter marks");
        scanf("%d",&marks[i]);
    }

    for(int i=0;i<=29;i++)
    {
        sum=sum+marks[i];

        avg=sum/30;
        printf("Average=%d\n",avg);
    }

    return 0;
}
