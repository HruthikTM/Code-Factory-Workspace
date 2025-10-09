#include <stdio.h>

int main()
{
    int num,positive =0 ,negative = 0,zero =0;
    char choice='y';

    while(choice=='y'||choice=='Y'){
        printf("Enter a Number: ");
        scanf("%d",&num);

        if(num>0){
            positive++;
        }
        else if(num<0){
            negative++;
        }
        else{
            zero++;
        }

        printf("Do you want another input(y/n)\n");
        scanf(" %c",&choice);
    }

    printf("Positive Count:%d\n",positive);
    printf("Negative Count:%d\n",negative);
    printf("Zero Count:%d\n",zero);

    return 0;

}
