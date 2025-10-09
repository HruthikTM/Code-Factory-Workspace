#include <stdio.h>

int main()
{
    int cp,sp,loss,profit;
    printf("Enter Cost and Selling price: ");
    scanf("%d%d",&cp,&sp);

    if(cp>sp){
        printf("Loss\n");
        loss=cp-sp;
        printf("Loss of Rs. %d\n",loss);
    }
    else{
        printf("profit\n");
        profit=sp-cp;
        printf("Profit of Rs. %d\n",profit);
    }

    return 0;

}
