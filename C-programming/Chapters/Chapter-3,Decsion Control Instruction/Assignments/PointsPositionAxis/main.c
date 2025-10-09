#include <stdio.h>

int main()
{
    float x,y;

    printf("enter the co-ordinates: ");
    scanf("%f%f",&x,&y);

    if(x==0 && y==0)
        printf("Points lies on the origin\n");
    else if(x==0)
        printf("Points lie on the x-axis\n");
    else if(y==0)
        printf("Points lies on y-axis\n");
    else
        printf("Points neither lies on axes nor origin");

    return 0;
}
