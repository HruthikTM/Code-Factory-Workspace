#include <stdio.h>

int main()
{
    int bs,da,hra;
    float gs;

    printf("Enter basic salary: ");
    scanf("%d",&bs);

    if(bs<1500){
        hra=bs*10/100;
        da=bs*90/100;
    }

    else{
        hra=500;
        da=bs*98/100;
    }

    gs=bs+da+hra;
    printf("Gross Salary: Rs. %f",gs);

    return 0;

}
