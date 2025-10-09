#include <stdio.h>

int main()
{
    int p,n,count=1;
    float r,si;

    while(count<=3)
    {
        printf("Enter Principle Amount,No. of years and Rate of Interest: ");
        scanf("%d%d%f",&p,&n,&r);
        si=p*n*r/100;
        printf("Simple Interest: Rs.%f\n",si);

        count=count+1;
    }

    return 0;
}
