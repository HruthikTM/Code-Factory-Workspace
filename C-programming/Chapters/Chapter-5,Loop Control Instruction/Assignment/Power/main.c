#include <stdio.h>

int main()
{
    int base,expo,result=1;

    printf("Enter the Base and Exponent: ");
    scanf("%d%d",&base,&expo);

    if(expo>=0){
        for(int i=1;i<=expo;i++){
            result=result*base;
        }
    }
    else
    {
        for(int i=1;i<=-expo;i++){
            result=result*base;
        }
    }

    result=1*result;

    printf("The result is: %d",result);
}
