#include <stdio.h>

void primeFactors(int,int);

int main()
{

    int num;
    printf("Enter the Number: ");
    scanf("%d",&num);


    if(num<=0)
        printf("Invalid input");

    printf("Prime factors : ");
    primeFactors(num, 2);

    return 0;

}

void primeFactors(int n,int i)
{
    if(n<=1)
        return;
    if(n%i==0){
        printf("%d ",i);
        primeFactors(n/i,i);
    }
    else{
        primeFactors(n,i+1);
    }

}
