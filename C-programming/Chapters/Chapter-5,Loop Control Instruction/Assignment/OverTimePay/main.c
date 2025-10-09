#include <stdio.h>

int main()
{
    int n=1,hours,ot;
    float pay;

    while(n<=10)
    {
        printf("Enter No. of hours worked by the employee: ");
        scanf("%d",&hours);

        if(hours>40){
            ot=hours-40;
            pay=ot*12;
        }
        else
        {
            ot=0;
            pay=0.0;
        }

        n++;
    }

    return 0;

}
