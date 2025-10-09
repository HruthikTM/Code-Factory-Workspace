#include <stdio.h>
#include "interest.h"

int main()
{

    float p,r,t;
    printf("Enter Principle Amount,Rate of Interest,Time: ");
    scanf("%f%f%f",&p,&r,&t);

    float si=SIMPLE_INTEREST(p,r,t);
    float amt=AMOUNT(p,r,t);

    printf("Simple Interest=%f\n",si);
    printf("Amount=%f\n",amt);

    return 0;
}
