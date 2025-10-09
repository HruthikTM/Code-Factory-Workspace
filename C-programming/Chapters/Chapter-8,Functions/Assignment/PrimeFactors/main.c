#include <stdio.h>


    void primeFactors(int n){
        printf("Prime factors of %d are: ",n);

        while(n%2==0){
            printf("2 ");
            n=n/2;
        }

        for(int i=3;i*i<=n;i+2){
            while(n%i==0){
                printf("%d ",i);
                n=n/i;
            }
        }

        if(n>2)
            printf("%d",n);

        printf("\n");

    }

    int main()
    {
        int n;
        printf("Enter the number: ");
        scanf("%d",&n);

        if(n>1)
            primeFactors(n);
        else
            printf("Enter the number greater than 1");

    }

