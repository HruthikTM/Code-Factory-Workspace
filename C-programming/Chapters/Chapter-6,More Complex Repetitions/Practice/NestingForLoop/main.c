#include <stdio.h>

int main()
{
    int sum;
    for(int i=1;i<=3;i++){//outer loop

        for(int j=1;j<=2;j++){//inner loop

            //sum=i+j;
            printf("i=%d j=%d sum=%d\n",i,j,i+j);

        }
    }

    return 0;
}
