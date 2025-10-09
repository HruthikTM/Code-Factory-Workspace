#include <stdio.h>

int main()
{

    int a,b,c,sum,angle=180;
    printf("Enter the angles of triangle : ");
    scanf("%d%d%d",&a,&b,&c);

    sum=a+b+c;

    if(sum==angle)
        printf("Its a triangle\n");
    else
        printf("Not a triangle\n");



}
