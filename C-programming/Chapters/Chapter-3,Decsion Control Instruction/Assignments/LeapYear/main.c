#include <stdio.h>

int main()
{
    int yy;

    printf("Enter the year to check leap or not: ");
    scanf("%d",&yy);


    if( (yy%4==0 && yy%100!=0) || yy%400==0 ){
        printf("Leap Year\n");
    }
    else{
            printf("Not a Leap Year\n");
    }

    return 0;
}
