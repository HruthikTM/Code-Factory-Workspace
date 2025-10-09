#include <stdio.h>

void isLeapYear(int yy)
{
    if((yy%4==0 && yy%100!=0) || yy%400==0)
        printf("Leap Year\n");
    else
        printf("Not a Leap Year\n");
}

int main()
{
    int yy;
    printf("Enter the year: \n");
    scanf("%d",&yy);

    if(yy>0)
        isLeapYear(yy);
    else
        printf("Pls enter a valid year\n");

    return 0;
}


//Important

// int main(){
//     char c;
//     int num;
//     float f;
//     int n=printf("Enter chars: \n");
//     //printf("%d",n);

//     int s=scanf("%c%d%f",&c,&num,&f);
//     printf("%d\n",s);
//     return 0;
// }

//Important
