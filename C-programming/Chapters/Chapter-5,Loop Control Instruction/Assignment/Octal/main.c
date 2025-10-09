#include <stdio.h>

int main()
{
    int num,temp,octal=0,power=1;

    printf("Enter the number: ");
    scanf("%d",&num);

    temp=num;

    while(temp>0){
        int rem=temp%8;
        octal=octal+rem*power;
        power=power*10;
        temp=temp/8;

    }

    printf("Octal Equalent:%d\n",octal);

    return 0;
}
